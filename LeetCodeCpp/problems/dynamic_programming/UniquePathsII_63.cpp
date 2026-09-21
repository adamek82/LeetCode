#include "UniquePathsII_63.h"
#include <cstddef>
#include <vector>

using namespace std;

int UniquePathsII_63::uniquePathsWithObstacles(vector<vector<int>> &grid)
{
    if (grid.empty() || grid[0].empty()) {
        return 0;
    }

    vector<int> dp(grid[0].size(), 0);
    dp[0] = 1;

    for (const auto& row : grid) {
        for (size_t j = 0; j < row.size(); ++j) {
            if (row[j] == 1) {
                dp[j] = 0;
            } else if (j > 0) {
                dp[j] += dp[j - 1];
            }
        }
    }

    return dp.back();
}
