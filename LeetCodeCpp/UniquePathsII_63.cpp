#include "UniquePathsII_63.h"

int UniquePathsII_63::uniquePathsWithObstacles(vector<vector<int>> &grid)
{
    int m = grid.size(), n = grid[0].size();

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i == 0 && j == 0) {
                // start cell → if obstacle=1 becomes 0, else 1
                grid[i][j] = !grid[i][j];
            }
            else if (grid[i][j] == 1) {
                // obstacle: zero out
                grid[i][j] = 0;
            }
            else if (i > 0 && j > 0) {
                // regular cell: sum from top + left
                grid[i][j] = grid[i-1][j] + grid[i][j-1];
            }
            else if (i > 0) {
                // first column (j==0): only from above
                grid[i][j] = grid[i-1][j];
            }
            else {
                // first row (i==0, j>0): only from left
                grid[i][j] = grid[i][j-1];
            }
        }
    }

    return grid[m-1][n-1];
}
