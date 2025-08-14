#pragma once

/*
 * Climbing Stairs (LeetCode 70)
 * Ways(n) = Ways(n-1) + Ways(n-2), with Ways(1)=1, Ways(2)=2.
 * Iterative DP, O(n) time, O(1) space. Fits in 32-bit int for n ≤ 45.
 */
class ClimbingStairs_70 {
public:
    int climbStairs(int n);
};
