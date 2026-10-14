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
int MinimumSizeSubarraySum_209::minSubArrayLen(int target, const vector<int>& nums)
{
    size_t left = 0;
    size_t best = nums.size() + 1;
    long long sum = 0;

    for (size_t right = 0; right < nums.size(); ++right) {
        sum += nums[right];

        while (sum >= target) {
            best = min(best, right + 1 - left);
            sum -= nums[left++];
        }
    }

    return best > nums.size() ? 0 : static_cast<int>(best);
}
