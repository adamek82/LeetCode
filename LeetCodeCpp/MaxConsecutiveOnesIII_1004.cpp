#include "MaxConsecutiveOnesIII_1004.h"
#include <vector>
#include <algorithm>

/*
 * Max Consecutive Ones III (LeetCode 1004) — sliding window / two pointers
 *
 * Goal
 * ----
 * Find the longest contiguous subarray that can be turned into all 1s by flipping
 * at most k zeros.
 *
 * Idea (window with a "flip budget")
 * ---------------------------------
 * Maintain a window [left..right] that is always "valid", meaning it contains at
 * most k zeros (i.e., needs <= k flips). We expand the window by moving `right`.
 * When we include a 0, we spend one unit of budget: --k.
 *
 * If k drops below 0, the window now has too many zeros, so we shrink it from
 * the left until it becomes valid again. When a 0 leaves the window, we refund
 * the budget: ++k.
 *
 * Why two pointers are enough (no brute force)
 * --------------------------------------------
 * Brute force would try all O(n^2) subarrays and count zeros.
 * With two pointers, we exploit monotonicity:
 * - Increasing `right` can only keep or worsen validity (adds elements, may add zeros).
 * - To restore validity, moving `left` rightwards can only help (removes elements, may remove zeros).
 *
 * Because `left` only moves forward and never needs to move back, every element
 * enters the window once (via `right`) and leaves at most once (via `left`),
 * giving a linear-time scan that still finds the optimum: for each `right`,
 * after shrinking, [left..right] is the longest valid window ending at `right`.
 * Taking the maximum over all `right` yields the global best.
 *
 * Complexity
 * ----------
 * Time:  O(n)
 * Space: O(1)
 */
int MaxConsecutiveOnesIII_1004::longestOnes(vector<int> &nums, int k)
{
    int left = 0;
    int best = 0;

    for (int right = 0; right < (int)nums.size(); ++right) {
        if (nums[right] == 0) --k;

        while (k < 0) {
            if (nums[left] == 0) ++k;
            ++left;
        }
        best = max(best, right - left + 1);
    }
    return best;
}
