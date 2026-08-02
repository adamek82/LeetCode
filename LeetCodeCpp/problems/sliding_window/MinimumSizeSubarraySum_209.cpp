#include "MinimumSizeSubarraySum_209.h"
#include <limits>       // for numeric_limits
#include <algorithm>    // for min

/*
 * Minimum Size Subarray Sum (LeetCode 209) — sliding window (positive numbers)
 *
 * Goal
 * ----
 * Find the minimal length of a contiguous subarray whose sum is at least `target`.
 * If no such subarray exists, return 0.
 *
 * Key property used
 * -----------------
 * All numbers are positive. This gives monotonic behavior:
 * - Expanding the window (moving r right) can only increase `sum`.
 * - Shrinking the window (moving l right) can only decrease `sum`.
 * Because of that, we can use two pointers without backtracking.
 *
 * Sliding window
 * --------------
 * Maintain a window [l..r] and its running sum.
 * 1) Extend the window by including nums[r] (sum += nums[r]).
 * 2) While the window already satisfies sum >= target, try to shrink it from
 *    the left to make it as small as possible, updating the best length:
 *       best = min(best, r - l + 1)
 *       sum -= nums[l]; ++l
 *
 * Correctness intuition
 * ---------------------
 * For each right endpoint r, the inner while-loop moves l as far right as it can
 * while keeping sum >= target. That means we discover the shortest valid window
 * ending at r. Taking the minimum across all r yields the globally shortest
 * valid subarray.
 *
 * Implementation notes
 * --------------------
 * - Use `long long` for `sum` to avoid overflow when values or n are large.
 * - `best` starts as INF; if it never changes, no valid subarray exists -> return 0.
 *
 * Complexity
 * ----------
 * Time:  O(n)   (each index moves forward at most once)
 * Space: O(1)
 */
int MinimumSizeSubarraySum_209::minSubArrayLen(int target, vector<int> &nums)
{
    /*
     * nums.size() is size_t; keep n as int because indices
     * (l/r) are int and we compute (r - l + 1).
     */
    int n = static_cast<int>(nums.size());
    int l = 0;                            // left boundary
    long long sum = 0;                    // running window sum
    int best = numeric_limits<int>::max();   // minimal length so far

    for (int r = 0; r < n; ++r) {
        sum += nums[r];                   // expand window

        // shrink from the left while we still meet / exceed target
        while (sum >= target) {
            best = min(best, r - l + 1);
            sum -= nums[l++];
        }
    }
    return best == numeric_limits<int>::max() ? 0 : best;
}
