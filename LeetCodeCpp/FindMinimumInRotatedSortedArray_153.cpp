#include "FindMinimumInRotatedSortedArray_153.h"

/*
 * 153. Find Minimum in Rotated Sorted Array — binary search on structure
 * ----------------------------------------------------------------------
 * We are given a strictly increasing array that has been rotated at some
 * pivot k (0 <= k < n). Formally, `nums` looks like:
 *
 *     nums = [a_k, a_{k+1}, ..., a_{n-1}, a_0, a_1, ..., a_{k-1}]
 *
 * where the original `a_0 < a_1 < ... < a_{n-1}`. All elements are distinct.
 * The task is to find the minimum element in O(log n) time.
 *
 * High-level idea:
 *   - The minimum is exactly the "rotation point" where the sorted order
 *     wraps around.
 *   - Consider the last element nums[right]. Relative to this pivot, the
 *     array is split into two monotone regions:
 *
 *       [left ... right]:
 *         - "Right" (tail) part: elements >= nums[0] and <= nums[right]
 *           (fully sorted, contains the minimum if array is not rotated).
 *         - "Left" (head) part: elements >= nums[0] but > nums[right]
 *           (these belong to the rotated front and lie strictly before
 *           the minimum in a rotated configuration).
 *
 *   - We use nums[mid] vs nums[right] to decide which side contains the
 *     minimum, similarly to how "first bad version" uses a monotone predicate.
 *
 * Binary search invariant:
 *   - We maintain a closed interval [left, right] such that the minimum
 *     element always lies within this interval.
 *
 * Update rules:
 *   1) If nums[mid] > nums[right]:
 *        - This means mid is in the "left" (rotated) part, where elements
 *          are strictly greater than the tail's last element.
 *        - Therefore, the minimum cannot be at mid or to its left; it must
 *          lie strictly to the right of mid.
 *
 *          left = mid + 1;
 *
 *   2) Else (nums[mid] <= nums[right]):
 *        - This means mid is in the "right" (sorted) part that *does* contain
 *          the minimum (either at mid or somewhere to its left).
 *        - We shrink the search interval to [left, mid] without losing the
 *          minimum.
 *
 *          right = mid;
 *
 * Loop condition and termination:
 *   - We use "while (left < right)" and always shrink the interval:
 *       - In case (1), left increases (left = mid + 1), so the interval
 *         length strictly decreases.
 *       - In case (2), right decreases (right = mid), also shrinking the
 *         interval.
 *   - When the loop ends, left == right and the invariant guarantees that
 *     this single index contains the minimum element. We can safely return
 *     nums[left].
 *
 * Complexity:
 *   - Time:  O(log n) — each step halves the search interval.
 *   - Space: O(1) extra space.
 */
int FindMinimumInRotatedSortedArray_153::findMin(vector<int> &nums)
{
    int left = 0, right = nums.size() - 1;

    // Binary search loop
    while (left < right) {
        int mid = left + (right - left) / 2;

        // If the mid element is greater than the rightmost element,
        // then the minimum is in the right half
        if (nums[mid] > nums[right]) {
            left = mid + 1;
        }
        // Else the minimum is in the left half (including mid)
        else {
            right = mid;
        }
    }

    // When the loop ends, left == right, pointing to the smallest element
    return nums[left];
}