#include "NumberOfIslands_200.h"

/*
 * Incremental notes vs MaxAreaOfIsland_695 (recursive flood-fill)
 * ---------------------------------------------------------------
 * Goal difference:
 *   695 returns the size of the largest island. Here (200) we return the COUNT of islands.
 *
 * Same core mechanics:
 *   - Recursive 4-direction DFS (up/down/left/right).
 *   - In-place visitation by flipping land to water (grid[i][j] = '0') to avoid revisits.
 *   - Bounds/land checks guard recursion.
 *
 * API / data differences:
 *   - Grid elements are chars '1' (land) / '0' (water), not ints.
 *   - Outer scan triggers DFS on each unvisited land cell; on trigger we increment `numIslands`.
 *
 * Correctness (why counting works):
 *   - Each DFS starting at an unvisited '1' consumes exactly one maximal 4-connected component,
 *     marking all its cells to '0'. No later start can land inside the same island.
 *   - Thus the number of DFS starts equals the number of islands.
 *
 * Complexity:
 *   - Time: O(m·n). Every cell is visited at most once; each adjacency checked O(1) times.
 *   - Space: O(m·n) worst-case recursion depth when one island spans all cells; extra locals O(1).
 */
int NumberOfIslands_200::numIslands(vector<vector<char>> &grid)
{
    if (grid.empty() || grid[0].empty()) return 0;

    const int m = static_cast<int>(grid.size());
    const int n = static_cast<int>(grid[0].size());
    int numIslands = 0;

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (grid[i][j] == '1') {
                numIslands++;
                dfs(grid, i, j);
            }
        }
    }

    return numIslands;
}

void NumberOfIslands_200::dfs(vector<vector<char>> &grid, int i, int j)
{
    /*
     * grid.size()/grid[0].size() return size_t (unsigned), but we keep m/n as int
     * because this DFS uses signed indices and signed moves (i-1, j-1) together
     * with checks like i < 0 or j < 0.
     *
     * Using size_t here would make negative checks meaningless and could cause
     * underflow. The extra (m > 0) guard makes this safe even if an empty grid
     * were passed.
     *
     * Limitation: assumes grid dimensions fit into int (<= INT_MAX). This holds
     * for typical LeetCode constraints.
     */
    const int m = static_cast<int>(grid.size());
    const int n = (m > 0) ? static_cast<int>(grid[0].size()) : 0;

    if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] != '1')
        return;

    grid[i][j] = '0';
    dfs(grid, i, j + 1);
    dfs(grid, i + 1, j);
    dfs(grid, i, j - 1);
    dfs(grid, i - 1, j);
}
