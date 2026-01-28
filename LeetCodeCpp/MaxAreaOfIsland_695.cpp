#include "MaxAreaOfIsland_695.h"
#include <algorithm>
#include <array>
#include <stack>
#include <utility>

/*
 * Algorithm: Flood-fill via DFS to compute the largest 4-connected component (island) of 1s
 * -----------------------------------------------------------------------------------------
 * Problem restatement:
 *   Given a binary grid (0 = water, 1 = land), an "island" is a maximal set of land cells
 *   connected orthogonally (up/down/left/right). Return the maximum island area (cell count).
 *
 * Approach:
 *   - Scan all cells. When a land cell (1) is found, start a DFS that:
 *       • counts this cell (area += 1),
 *       • marks it visited by flipping grid[i][j] = 0 (in-place),
 *       • recursively explores its four orthogonal neighbors,
 *       • returns the total size of this connected component.
 *   - Track the maximum among all DFS-returned areas.
 *
 * Visited marking (why mutation is safe and sufficient):
 *   - The DFS sets each visited land cell to 0 exactly once. This prevents:
 *       • revisiting the same cell within the current DFS (avoids infinite loops),
 *       • recounting the same island from later outer-loop positions.
 *   - Thus every land cell is processed at most once overall.
 *   - If grid preservation is required, use a separate visited[m][n] array instead of mutation.
 *
 * Correctness (proof sketch):
 *   - Soundness: The DFS only moves to orthogonal neighbors that are inside bounds and equal to 1.
 *     Because we mark a cell 0 immediately upon visiting, any cell contributes exactly 1 to the
 *     area of the unique DFS that first touches it; no cell is counted twice.
 *   - Completeness: Starting a DFS from every unvisited land cell ensures we initiate exactly one
 *     DFS per island (by maximality). The recursive expansion explores the entire 4-connected
 *     component before returning, so the computed area equals the island’s size.
 *   - Max selection: Taking the max over all DFS areas yields the maximum island area by definition.
 *
 * Complexity:
 *   Let m = grid height, n = grid width.
 *   - Time: O(m·n). Each cell is visited at most once; each edge (adjacency) is examined O(1) times.
 *   - Space: O(m·n) in the worst case due to recursion stack depth — e.g., when the entire grid is
 *            land (a single island of size m·n).
 *            Extra auxiliary space beyond the recursion stack is O(1) — only a few locals.
 *            An iterative DFS/BFS with an explicit stack/queue achieves the same O(m·n) time and
 *            O(m·n) worst-case space but avoids call-stack overflows on large grids.
 *
 * Grid connectivity:
 *   - Uses 4-neighborhood (up, down, left, right). To adopt 8-connectivity, include diagonals
 *     in the directions array.
 *
 * Edge cases:
 *   - All water → returns 0 (no DFS is triggered).
 *   - Single cell grid → returns either 0 or 1.
 *   - Assumes grid is non-empty with consistent row lengths (grid.size() > 0, grid[0].size() > 0).
 */
int MaxAreaOfIsland_695::maxAreaOfIslandRecursive(vector<vector<int>> &grid)
{
    if (grid.empty() || grid[0].empty()) return 0;

    const int m = static_cast<int>(grid.size());
    const int n = static_cast<int>(grid[0].size());
    int maxArea = 0;

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (grid[i][j] == 1) {
                maxArea = max(maxArea, dfsRecursive(grid, i, j));
            }
        }
    }

    return maxArea;
}

int MaxAreaOfIsland_695::dfsRecursive(vector<vector<int>> &grid, int i, int j) {
    int m = grid.size(), n = grid[0].size();
    if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] != 1) return 0;

    grid[i][j] = 0;
    return 1
         + dfsRecursive(grid, i+1, j)       // down
         + dfsRecursive(grid, i-1, j)       // up
         + dfsRecursive(grid, i, j+1)       // right
         + dfsRecursive(grid, i, j-1);      // left
}

/*
 * Algorithm: Iterative DFS (explicit stack) flood-fill for maximum island area
 * ---------------------------------------------------------------------------
 * Problem restatement:
 *   Given a binary grid (0 = water, 1 = land), an island is a maximal 4-connected
 *   component of 1s (up/down/left/right). Return the size of the largest island.
 *
 * Approach:
 *   - Scan all cells; upon encountering an unvisited land cell (1), run an iterative
 *     DFS using an explicit stack to flood-fill that island and compute its area.
 *   - Mark cells as visited by flipping grid[x][y] = 0 (in-place) to prevent revisits.
 *   - Track the maximum area over all flood-fills.
 *
 * Stack-based flood-fill (floodFillIterative):
 *   - Initialize a stack with the seed cell (r,c) and immediately mark it 0.
 *   - While the stack is not empty:
 *       • Pop a cell, increment area.
 *       • For each of its four neighbors, if in bounds and equal to 1, mark it 0 and push.
 *   - Returning area yields the size of this island’s 4-connected component.
 *
 * Why mark before push:
 *   - Marking a neighbor as visited (set to 0) at the time of pushing guarantees that no cell
 *     enters the stack more than once, preventing duplicates and ensuring linear complexity.
 *
 * Correctness (proof sketch):
 *   - Soundness: We only count cells that were 1 and each is marked 0 exactly once, so no cell
 *     is double-counted. Pushing occurs only for valid, in-bounds land neighbors.
 *   - Completeness: Starting from every yet-unvisited land cell triggers exactly one flood-fill
 *     per island; the stack expansion explores the entire 4-connected component before finishing.
 *   - Max selection: Taking the maximum of all returned areas yields the largest island by definition.
 *
 * Relation to recursive DFS:
 *   - This is behaviorally equivalent to the recursive version but uses an explicit stack instead
 *     of the call stack, avoiding recursion-depth limits on large or snaking islands.
 *
 * Complexity:
 *   Let m = grid height, n = grid width.
 *   - Time: O(m·n). Each cell is pushed/popped at most once; each adjacency is checked O(1).
 *   - Space: O(m·n) in the worst case for the explicit stack when one island spans all cells.
 *            Extra auxiliary space beyond the stack is O(1) (fixed directions array and a few locals).
 *
 * Edge cases:
 *   - All water → result 0.
 *   - Single cell grid → 0 or 1 accordingly.
 *   - Assumes non-empty grid with consistent row lengths.
 */
int MaxAreaOfIsland_695::maxAreaOfIslandIterative(vector<vector<int>>& grid)
{
    if (grid.empty() || grid[0].empty()) return 0;

    const int m = static_cast<int>(grid.size());
    const int n = static_cast<int>(grid[0].size());
    int best = 0;

    for (int r = 0; r < m; ++r)
        for (int c = 0; c < n; ++c)
            if (grid[r][c] == 1)                       // unvisited land
                best = max(best, floodFillIterative(grid, m, n, r, c));

    return best;
}

// Helper performing the stack-based flood-fill and returning island area
int MaxAreaOfIsland_695::floodFillIterative(vector<vector<int>>& grid, int m, int n, int r, int c)
{
    int area = 0;

    // Directions for moving in the grid (right, left, down, up)
    static constexpr array<pair<int,int>, 4> directions{{
        {0, 1}, {0, -1}, {1, 0}, {-1, 0}
    }};

    /*
     * Use std::stack with std::vector as the underlying container (instead of the default std::deque).
     *
     * Why:
     * - std::vector is contiguous and often has lower overhead than std::deque for stack-like push/pop.
     * - We can reserve upfront to reduce (or eliminate) reallocations while the DFS grows the stack.
     *
     * Note:
     * - The stack may temporarily hold many cells; an upper bound is m*n.
     * - We build the backing vector separately to call reserve(), then move it into std::stack.
     */
    vector<pair<int,int>> backing;
    backing.reserve(static_cast<size_t>(m) * static_cast<size_t>(n));
    stack<pair<int,int>, vector<pair<int,int>>> st(std::move(backing));

    st.emplace(r, c);
    grid[r][c] = 0;                 // mark visited

    while (!st.empty()) {           // DFS flood-fill
        auto [x, y] = st.top();
        st.pop();
        ++area;

        for (const auto& d : directions) {
            int nx = x + d.first;
            int ny = y + d.second;
            if (nx >= 0 && nx < m && ny >= 0 && ny < n
                && grid[nx][ny] == 1) {
                grid[nx][ny] = 0;   // mark & push
                st.emplace(nx, ny);
            }
        }
    }

    return area;
}
