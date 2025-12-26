#include "RemoveDuplicates_26.h"

/*
 * Remove Duplicates from Sorted Array (LeetCode 26) — Two Pointers (in-place)
 * --------------------------------------------------------------------------
 * Idea:
 *   Since nums is sorted, duplicates are adjacent. We keep a "unique prefix"
 *   at the beginning of the array and extend it whenever we find a new value.
 *
 * Pointers:
 *   - i scans the array from left to right.
 *   - k is the length of the unique prefix so far, and also the next write index.
 *     Invariant: nums[0..k-1] contains the first k unique values in sorted order.
 *
 * Update:
 *   When nums[i] differs from the last unique value nums[k-1], we write it to
 *   nums[k] and increment k.
 *
 * Result:
 *   Return k = number of unique elements (the new logical length). Elements
 *   beyond index k-1 are irrelevant for the problem.
 *
 * Complexity:
 *   Time O(n), Space O(1).
 */
int RemoveDuplicates_26::removeDuplicates(vector<int>& nums) {
    const int n = static_cast<int>(nums.size());
    if (n == 0) return 0;

    int k = 1; // write index for next unique
    for (int i = 1; i < n; ++i) {
        if (nums[i] != nums[k - 1]) {
            nums[k++] = nums[i];
        }
    }
    return k;
}
