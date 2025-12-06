#include "SearchInRotatedSortedArray_33.h"

/*
 * 33. Search in Rotated Sorted Array — binary search on the sorted half
 * ---------------------------------------------------------------------
 * We are given a strictly increasing array that has been rotated at some
 * pivot k. Formally, `nums` is:
 *
 *     [a_k, a_{k+1}, ..., a_{n-1}, a_0, a_1, ..., a_{k-1}]
 *
 * where a_0 < a_1 < ... < a_{n-1}, and all values are distinct. We must find
 * the index of `target` in O(log n) time, or return -1 if it does not exist.
 *
 * Key structural property:
 *   For any index mid, at least one of the two halves
 *       [left .. mid] or [mid .. right]
 *   is a *normal* (non-rotated) sorted subarray:
 *
 *   - If nums[left] <= nums[mid], then [left .. mid] is strictly increasing.
 *   - Otherwise, [mid .. right] is strictly increasing.
 *
 * High-level idea:
 *   We run a standard binary search on the index range [left, right]. At each
 *   step, we:
 *
 *     1) Check if nums[mid] == target.
 *     2) Decide which half is sorted.
 *     3) Decide whether `target` can lie in that sorted half (via simple
 *        range check). If yes, we restrict to that half; otherwise, we
 *        discard it and search the other half.
 *
 *   Because at every step we remove a half that is guaranteed *not* to
 *   contain the target, the search remains O(log n).
 *
 * Invariant:
 *   - At the start of each iteration, if `target` exists in the array,
 *     then it lies in the current closed interval [left, right].
 *
 * Update rules (with distinct elements):
 *   Let mid = floor((left + right) / 2):
 *
 *   1) If nums[mid] == target:
 *        return mid.
 *
 *   2) If nums[left] <= nums[mid], the left half [left .. mid] is sorted.
 *        - If nums[left] <= target < nums[mid], then `target` must be
 *          somewhere inside [left .. mid-1], so:
 *
 *              right = mid - 1;
 *
 *        - Otherwise, `target` cannot be in that sorted half, so it must be
 *          in the other half (if it exists at all):
 *
 *              left = mid + 1;
 *
 *   3) Else (nums[left] > nums[mid]), the right half [mid .. right] is sorted.
 *        - If nums[mid] < target <= nums[right], then `target` must be
 *          inside [mid+1 .. right], so:
 *
 *              left = mid + 1;
 *
 *        - Otherwise, `target` cannot be in that sorted half, so it must be
 *          in the other half:
 *
 *              right = mid - 1;
 *
 * Termination:
 *   - On each iteration we strictly shrink the interval [left, right].
 *   - Either we find nums[mid] == target and return mid, or the interval
 *     eventually becomes empty (left > right), in which case the invariant
 *     implies that `target` is not present and we return -1.
 *
 * Complexity:
 *   - Time:  O(log n), we discard about half of the remaining interval on
 *            each step.
 *   - Space: O(1) extra space.
 */

int SearchInRotatedSortedArray_33::search(vector<int>& nums, int target)
{
    int left  = 0;
    int right = static_cast<int>(nums.size()) - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (nums[mid] == target) {
            return mid;
        }

        // Determine which half is sorted.
        if (nums[left] <= nums[mid]) {
            // Left half [left .. mid] is sorted.
            if (nums[left] <= target && target < nums[mid]) {
                // Target lies in the left sorted half.
                right = mid - 1;
            } else {
                // Target lies in the right half.
                left = mid + 1;
            }
        } else {
            // Right half [mid .. right] is sorted.
            if (nums[mid] < target && target <= nums[right]) {
                // Target lies in the right sorted half.
                left = mid + 1;
            } else {
                // Target lies in the left half.
                right = mid - 1;
            }
        }
    }

    return -1;
}
