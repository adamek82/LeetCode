#include "MinCostClimbingStairs_746.h"
#include <algorithm>

/*
 * 746. Min Cost Climbing Stairs — bottom-up DP in O(1) space
 * ---------------------------------------------------------
 * Let dp[i] be the minimum cost to reach step i (where i ranges from 0 to n),
 * i.e., the position *before* stepping on i (the "top" is step n).
 *
 * Recurrence (bottom-up):
 *   - Base:   dp[0] = 0, dp[1] = 0
 *   - Step:   for i >= 2:
 *
 *       dp[i] = min(dp[i - 1] + cost[i - 1],
 *                   dp[i - 2] + cost[i - 2])
 *
 * We only ever use dp[i - 1] and dp[i - 2] to compute dp[i], so we don't need
 * the whole dp array. Keeping just two rolling variables (dp_im1, dp_im2) is
 * enough to implement this recurrence in O(1) extra space.
 */
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
