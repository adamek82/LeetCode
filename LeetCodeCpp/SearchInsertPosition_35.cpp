#include "SearchInsertPosition_35.h"

/*
 * Search Insert Position (LeetCode 35)
 * ------------------------------------
 * Given a sorted, strictly increasing array nums, returns:
 *
 *   - the index of target, if target is present;
 *   - otherwise, the index at which target should be inserted so that the
 *     array remains sorted.
 *
 * Specification:
 *   Precondition:
 *     - nums is sorted in strictly increasing order:
 *
 *           nums[0] < nums[1] < ... < nums[n - 1]
 *
 *   Postcondition:
 *     The returned value r is the correct insertion position:
 *
 *       - 0 <= r <= nums.size()
 *
 *       - every index i < r satisfies:
 *
 *             nums[i] < target
 *
 *       - if r < nums.size(), then:
 *
 *             nums[r] >= target
 *
 *     Since nums is strictly increasing, if target occurs in nums, this r is
 *     exactly the unique index where nums[r] == target. If target does not
 *     occur, r is the position where target can be inserted while preserving
 *     the sorted order.
 *
 * Candidate interval:
 *   We use a standard closed binary-search interval [left, right].
 *
 *   At any moment:
 *
 *     - indices before left have already been ruled out because their values
 *       are strictly smaller than target;
 *
 *     - indices after right have already been ruled out because their values
 *       are strictly greater than target;
 *
 *     - if target is present, its index must still be inside [left, right].
 *
 * Loop invariant:
 *   At the beginning of each iteration:
 *
 *     1. Every index before left is too small:
 *
 *          for every i such that 0 <= i < left:
 *              nums[i] < target
 *
 *     2. Every index after right is too large:
 *
 *          for every i such that right < i < nums.size():
 *              nums[i] > target
 *
 *     3. Bounds:
 *
 *          0 <= left <= nums.size()
 *         -1 <= right < nums.size()
 *          left <= right + 1
 *
 *        When left <= right, [left, right] is a valid non-empty closed
 *        candidate interval.
 *
 *        When left > right, the candidate interval is empty. Because of
 *        left <= right + 1, this means left == right + 1.
 *
 * Initialization:
 *   Initially:
 *
 *       left = 0
 *       right = nums.size() - 1
 *
 *   There are no indices before left and no indices after right, so both
 *   excluded regions are empty. Therefore the invariant holds vacuously.
 *
 * Preservation:
 *   During each iteration the loop condition gives:
 *
 *       left <= right
 *
 *   We compute:
 *
 *       mid = left + (right - left) / 2
 *
 *   Since right - left >= 0, integer division gives:
 *
 *       0 <= (right - left) / 2 <= right - left
 *
 *   After adding left:
 *
 *       left <= mid <= right
 *
 *   Thus mid is a valid index inside the current candidate interval.
 *
 *   There are three cases:
 *
 *   1. nums[mid] == target
 *
 *      We return mid immediately.
 *
 *      This is correct because mid is a valid index and nums[mid] really is
 *      equal to target.
 *
 *   2. nums[mid] < target
 *
 *      Since nums is sorted in strictly increasing order, every index i <= mid
 *      satisfies:
 *
 *          nums[i] <= nums[mid] < target
 *
 *      Therefore all indices up to and including mid are too small. Target,
 *      if present, cannot be there.
 *
 *      We set:
 *
 *          left = mid + 1
 *
 *      Now every index before the new left is known to contain a value smaller
 *      than target. The region after right is unchanged. The invariant is
 *      preserved.
 *
 *   3. nums[mid] > target
 *
 *      Since nums is sorted in strictly increasing order, every index i >= mid
 *      satisfies:
 *
 *          nums[i] >= nums[mid] > target
 *
 *      Therefore all indices from mid onward are too large. Target, if
 *      present, cannot be there.
 *
 *      We set:
 *
 *          right = mid - 1
 *
 *      Now every index after the new right is known to contain a value greater
 *      than target. The region before left is unchanged. The invariant is
 *      preserved.
 *
 * Correctness:
 *
 *   Case 1: target is found
 *   -----------------------
 *   The function returns from inside the loop only when:
 *
 *       nums[mid] == target
 *
 *   Also, mid is a valid index because left <= mid <= right and [left, right]
 *   is a valid segment of the array during the loop.
 *
 *   Therefore returning mid is correct.
 *
 *
 *   Case 2: target is not found
 *   ---------------------------
 *   If the loop terminates normally, then the loop condition is false:
 *
 *       !(left <= right)
 *
 *   so:
 *
 *       left > right
 *
 *   Together with the invariant left <= right + 1, this gives:
 *
 *       left == right + 1
 *
 *   The candidate interval [left, right] is empty.
 *
 *   From the invariant:
 *
 *     - every index i < left satisfies nums[i] < target;
 *     - every index i > right satisfies nums[i] > target.
 *
 *   Since left == right + 1, every index i >= left also satisfies i > right.
 *   Therefore every index i >= left satisfies nums[i] > target.
 *
 *   Thus the array is partitioned as:
 *
 *       indices:  [0, ..., left - 1] | [left, ..., nums.size() - 1]
 *       values:      < target        |          > target
 *
 *   Therefore left is exactly the first position where target can be inserted:
 *
 *     - inserting target before left would break the order, because all
 *       elements before left are smaller than target;
 *
 *     - inserting target at left preserves the order, because all elements
 *       from left onward are greater than target;
 *
 *     - if left == nums.size(), target is greater than every element and is
 *       inserted at the end.
 *
 * Termination:
 *   While left <= right, the candidate interval has length:
 *
 *       right - left + 1
 *
 *   This is a non-negative integer.
 *
 *   On each non-returning iteration, the interval strictly shrinks:
 *
 *     - if nums[mid] < target, left becomes mid + 1, so the lower bound moves
 *       strictly to the right;
 *
 *     - if nums[mid] > target, right becomes mid - 1, so the upper bound moves
 *       strictly to the left.
 *
 *   Therefore the non-negative integer length of the candidate interval
 *   strictly decreases on every non-returning iteration. It cannot decrease
 *   indefinitely, so the loop must terminate.
 *
 * Complexity:
 *   - Time:  O(log n), where n = nums.size(), because each iteration roughly
 *            halves the candidate interval.
 *   - Space: O(1) extra space.
 */
int SearchInsertPosition_35::searchInsert(vector<int> &nums, int target)
{
    int left = 0;

    /*
     * nums.size() returns size_t, which is unsigned.
     *
     * By casting before subtracting 1, an empty vector gives:
     *
     *     static_cast<int>(0) - 1 == -1
     *
     * Therefore:
     *
     *     left  = 0
     *     right = -1
     *
     * and the loop condition left <= right is immediately false.
     *
     * This assumes nums.size() fits into int, which is fine for typical
     * LeetCode constraints.
     */
    int right = static_cast<int>(nums.size()) - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (nums[mid] == target) {
            return mid;
        }

        if (nums[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return left;
}
