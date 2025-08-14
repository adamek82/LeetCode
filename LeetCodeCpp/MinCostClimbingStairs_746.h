#pragma once
#include <vector>
using namespace std;

/*
 * Min Cost Climbing Stairs (LeetCode 746)
 *
 * Let dp[i] be the minimal cost to stand on step i (virtual top is step n).
 * Transitions for i >= 2:
 *   dp[i] = min(dp[i-1] + cost[i-1], dp[i-2] + cost[i-2])
 * Base: dp[0] = dp[1] = 0 (you can start from step 0 or step 1 for free).
 * Answer: dp[n].
 * Time: O(n), Space: O(1).
 */
class MinCostClimbingStairs_746 {
public:
    int minCostClimbingStairs(const vector<int>& cost);
};
