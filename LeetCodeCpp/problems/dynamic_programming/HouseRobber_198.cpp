#include "HouseRobber_198.h"
#include <algorithm>

/*
 * 198. House Robber — 1D DP with rolling variables
 * ------------------------------------------------
 * Let dp[i] be the maximum amount of money we can rob from the first i houses
 * (i.e., considering nums[0..i-1]) without triggering the alarm.
 *
 * Transition:
 *   - If we *skip* house i-1, we keep dp[i-1].
 *   - If we *rob* house i-1, we must skip house i-2, so we take dp[i-2] + nums[i-1].
 *
 * So for i >= 1:
 *
 *     dp[i] = max(dp[i-1], dp[i-2] + nums[i-1])
 *
 * with base:
 *
 *     dp[0] = 0        (no houses → 0 profit)
 *     dp[1] = nums[0]  (only the first house available)
 *
 * We don't need the full dp array: each step only depends on dp[i-1] and dp[i-2],
 * so we keep two rolling variables:
 *   prev1 = dp[i-1], prev2 = dp[i-2], and compute cur = dp[i] in O(1) space.
 */
int HouseRobber_198::rob(const vector<int>& nums)
{
    int prev2 = 0; // dp[i-2]
    int prev1 = 0; // dp[i-1]
    for (int x : nums) {
        int cur = max(prev1, prev2 + x); // rob current or skip
        prev2 = prev1;
        prev1 = cur;
    }
    return prev1;
}
