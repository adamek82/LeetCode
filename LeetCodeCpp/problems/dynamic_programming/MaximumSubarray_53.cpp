#include "MaximumSubarray_53.h"

/*
 * Maximum Subarray (LeetCode 53) — Kadane’s algorithm
 * ---------------------------------------------------
 * Goal:
 *   Find the contiguous subarray with the largest possible sum.
 *
 * Key idea (the “keep collecting until it stops helping” intuition):
 *   While scanning left → right, keep only one piece of state:
 *
 *     cur  = best sum of a subarray that MUST end at i
 *     best = best sum of ANY subarray seen so far
 *
 *   At position i, there are exactly two sensible choices for a best subarray
 *   that ends at i:
 *     1) Start fresh at i:            nums[i]
 *     2) Extend the previous one:     cur + nums[i]
 *
 *   So:
 *     cur = max(nums[i], cur + nums[i])
 *
 * DP perspective (why this belongs to Dynamic Programming):
 *   Define dp[i] as the maximum subarray sum that ends exactly at index i.
 *
 *     dp[i] = max(nums[i], dp[i-1] + nums[i])
 *
 *   This is a classic DP recurrence: the optimal answer for i depends only on i-1.
 *   Kadane is simply the space-optimized form:
 *
 *     cur  == dp[i]    (we keep only the previous state instead of a whole dp[] table)
 *     best == max over all dp[i]
 *
 *   So it’s DP without tabulation: same recurrence, just O(1) memory.
 *
 * Why this is correct (the “dropping bad baggage” rule):
 *   If cur is negative before adding nums[i], then (cur + nums[i]) < nums[i].
 *   That means carrying the previous sum only makes the result WORSE.
 *   A negative prefix is dead weight — any future subarray is better without it.
 *
 *   If cur is positive, adding it increases future sums, so we keep it.
 *
 * Mental model:
 *   Think of cur as the “momentum” of your current streak.
 *   - Positive momentum helps the next step → keep it.
 *   - Negative momentum hurts the next step → reset.
 *
 * Two quick examples to burn it in:
 *
 *   Example A: [-2, 1, -3, 4, -1, 2, 1, -5, 4]
 *     i=0: cur=-2, best=-2
 *     i=1 (1):  cur=max(1, -2+1=-1)=1      best=1     (drop -2, start at 1)
 *     i=3 (4):  cur=max(4, -2+4=2)=4       best=4     (drop the bad prefix, start at 4)
 *     then: -1 → cur=3, +2 → cur=5, +1 → cur=6, best=6
 *     Best subarray is [4,-1,2,1] sum=6.
 *
 *   Example B: [5, -7, 3, 5]
 *     i=0: cur=5, best=5
 *     i=1 (-7): cur=max(-7, 5-7=-2)=-2    best=5     (streak became negative)
 *     i=2 (3):  cur=max(3, -2+3=1)=3      best=5     (reset: don’t drag -2)
 *     i=3 (5):  cur=max(5, 3+5=8)=8       best=8     (extend positive streak)
 *
 * Complexity:
 *   Time:  O(n) — single pass
 *   Space: O(1) — only cur and best
 */
int MaximumSubarray_53::maxSubArray(const vector<int> &nums)
{
    int cur  = nums[0];
    int best = nums[0];
    for (size_t i = 1; i < nums.size(); ++i) {
        cur  = max(nums[i], cur + nums[i]);
        best = max(best, cur);
    }
    return best;
}