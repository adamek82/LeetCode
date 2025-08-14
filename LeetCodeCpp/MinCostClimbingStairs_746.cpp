#include "MinCostClimbingStairs_746.h"
#include <algorithm>

int MinCostClimbingStairs_746::minCostClimbingStairs(const vector<int>& cost)
{
    const int n = static_cast<int>(cost.size());
    int dp_im2 = 0; // dp[0]
    int dp_im1 = 0; // dp[1]
    for (int i = 2; i <= n; ++i) {
        int cur = min(dp_im1 + cost[i - 1], dp_im2 + cost[i - 2]);
        dp_im2 = dp_im1;
        dp_im1 = cur;
    }
    return dp_im1; // dp[n]
}
