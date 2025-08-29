#pragma once
#include <vector>
using namespace std;

/*
 * LeetCode 55 — Jump Game
 *
 * Problem
 * -------
 * Given nums[i] as the maximum forward jump length from index i, decide
 * whether we can reach the last index starting from 0.
 *
 * Greedy Invariant
 * ----------------
 * Maintain the farthest index `reach` we can get to so far. When scanning
 * left-to-right:
 *   - If at position i we have i > reach, then i is unreachable -> return false.
 *   - Otherwise, extend reach = max(reach, i + nums[i]).
 * If we finish the scan (or reach >= n - 1 at any time), return true.
 *
 * Correctness intuition
 * ---------------------
 * Among all ways to reach each index <= reach, choosing the maximum extension
 * i + nums[i] dominates any shorter extension, so we only need the scalar
 * summary "current farthest reach" instead of enumerating paths (no DP needed).
 *
 * Complexity
 * ----------
 * Time  : O(n)
 * Space : O(1)
 */
class JumpGame_55 {
public:
    // Returns true iff the last index is reachable from index 0.
    bool canJump(vector<int>& nums);
};
