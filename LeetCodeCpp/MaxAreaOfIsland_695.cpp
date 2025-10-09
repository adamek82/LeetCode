#include "MaxAreaOfIsland_695.h"
#include <algorithm>
#include <vector>
#include <stack>

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
 *   - Space: O(m·n) in the worst case due to recursion stack depth (e.g., a snake-shaped island).
 *            Extra auxiliary space beyond recursion is O(1) (the fixed directions array).
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
    int m = grid.size();
    int n = grid[0].size();
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

// Iterative DFS, public entry point
int MaxAreaOfIsland_695::maxAreaOfIslandIterative(vector<vector<int>>& grid)
{
    int m = grid.size();
    int n = grid[0].size();
    int best = 0;

    // Directions for moving in the grid (right, left, down, up)
    static const vector<pair<int, int>> directions = {
        {0, 1}, {0, -1}, {1, 0}, {-1, 0}
    };

    for (int r = 0; r < m; ++r)
        for (int c = 0; c < n; ++c)
            if (grid[r][c] == 1)                       // unvisited land
                best = max(best, floodFillIterative(grid, r, c));

    return best;
}

// Helper performing the stack-based flood-fill and returning island area
int MaxAreaOfIsland_695::floodFillIterative(vector<vector<int>>& grid, int r, int c)
{
    int m = grid.size();
    int n = grid[0].size();
    int area = 0;

    // Directions for moving in the grid (right, left, down, up)
    static const vector<pair<int, int>> directions = {
        {0, 1}, {0, -1}, {1, 0}, {-1, 0}
    };

    stack<pair<int,int>> st;
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