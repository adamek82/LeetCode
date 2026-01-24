#include "RemoveDuplicatesFromSortedArrayII_80.h"

/*
 * Remove Duplicates from Sorted Array II (LeetCode 80)
 *
 * Goal
 * ----
 * Modify the sorted array in-place so that each distinct value appears
 * at most twice. Return k = new length. The first k elements of `nums`
 * form the valid result (the rest can be ignored).
 *
 * Key property used
 * -----------------
 * `nums` is sorted, so duplicates of the same value always appear as one
 * contiguous block. This makes it enough to only compare against the last
 * written occurrences.
 *
 * Two-pointer idea (reader + writer)
 * ----------------------------------
 * - `i` scans the original array from left to right (reader).
 * - `k` points to where the next accepted element should be written (writer).
 *
 * Invariant (what is always true)
 * -------------------------------
 * After processing elements nums[0..i-1], the prefix nums[0..k-1] contains
 * exactly the kept elements in sorted order, and no value occurs there more
 * than two times.
 *
 * Acceptance rule
 * ---------------
 * We always accept the first two elements of the output (k < 2), because
 * nothing can exceed the "twice" limit yet.
 *
 * For k >= 2, we decide whether nums[i] can be appended:
 * - If nums[i] == nums[k-2], then adding nums[i] would create three equal
 *   values among the last two already kept and this one (because sorted order
 *   guarantees they'd be consecutive). We must skip it.
 * - If nums[i] != nums[k-2], then either it's a new value, or it's the second
 *   occurrence of the current value. In both cases, appending it still keeps
 *   "at most twice", so we write nums[k] = nums[i] and increment k.
 *
 * Complexity
 * ----------
 * Time:  O(n)  (single pass)
 * Space: O(1)  (in-place, constant extra memory)
 */
int RemoveDuplicatesFromSortedArrayII_80::removeDuplicates(vector<int> &nums)
{
    int k = 0; // writer index for the next accepted element

    for (int i = 0; i < static_cast<int>(nums.size()); i++) {
        if (k < 2 || nums[i] != nums[k - 2]) {
            nums[k++] = nums[i];
        }
    }

    return k;
}
