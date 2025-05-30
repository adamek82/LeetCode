#include "NumberOfIslands_200.h"

int NumberOfIslands_200::numIslands(vector<vector<char>> &grid)
{
    int m = grid.size();
    int n = grid[0].size();
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
    int m = grid.size();
    int n = grid[0].size();
    if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] != '1')
        return;
    grid[i][j] = '0';
    dfs(grid, i, j + 1);
    dfs(grid, i + 1, j);
    dfs(grid, i, j - 1);
    dfs(grid, i - 1, j);
}
