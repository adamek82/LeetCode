#pragma once
#include <vector>
using namespace std;

/*
 * House Robber (LeetCode 198)
 *
 * DP with rolling variables:
 * Let dp[i] = max money from subarray nums[0..i].
 * Recurrence: dp[i] = max(dp[i-1], dp[i-2] + nums[i]).
 * We keep only (prev2=dp[i-2], prev1=dp[i-1]) → O(1) space.
 * Time: O(n), Space: O(1).
 */
class HouseRobber_198 {
public:
    int rob(const vector<int>& nums);
};
