#include "BinarySearch_704.h"

/*
 * Binary search (LeetCode 704)
 * ----------------------------
 * Searches for target in a sorted (non-decreasing) array nums and returns its
 * index, or -1 if target is not present.
 *
 * Specification:
 *   Precondition:
 *     - nums is sorted in non-decreasing order:
 *         nums[0] <= nums[1] <= ... <= nums[n - 1]
 *
 *   Postcondition:
 *     - If the function returns index r >= 0, then:
 *         0 <= r < nums.size() and nums[r] == target.
 *     - If the function returns -1, then:
 *         target does not occur in nums.
 *
 * Candidate interval:
 *   We maintain a closed interval [left, right] containing all indices that
 *   have not yet been ruled out.
 *
 *   Indices strictly before left have already been ruled out.
 *   Indices strictly after right have already been ruled out.
 *
 * Loop invariant:
 *   At the beginning of each iteration:
 *
 *     1. Every index before left has been ruled out:
 *
 *          for every i such that 0 <= i < left:
 *              nums[i] != target
 *
 *     2. Every index after right has been ruled out:
 *
 *          for every i such that right < i < nums.size():
 *              nums[i] != target
 *
 *     3. Therefore, if target is present in nums, it can only be inside the
 *        current candidate interval [left, right].
 *
 *     4. Bounds:
 *
 *          0 <= left <= nums.size()
 *         -1 <= right < nums.size()
 *
 *        When left <= right, [left, right] is a valid non-empty closed
 *        interval of array indices.
 *
 *        When left > right, the candidate interval is empty.
 *
 * Initialization:
 *   Initially:
 *
 *       left = 0
 *       right = nums.size() - 1
 *
 *   Therefore, no index before left exists, and no index after right exists.
 *   Both ruled-out regions are empty, so the invariant is true.
 *
 * Loop condition:
 *   The loop runs while:
 *
 *       left <= right
 *
 *   This means that the closed candidate interval [left, right] is non-empty.
 *
 * Why "left <= right" and not "left < right"?
 *   - We use a closed interval [left, right].
 *   - When left == right, there is exactly one remaining candidate index.
 *     This index still has to be checked.
 *   - Once left becomes right + 1, the interval is empty and there are no
 *     candidates left.
 *
 *   Example where "left < right" loses a valid answer:
 *
 *       nums   = [1, 3, 5, 7, 9]
 *       target = 9
 *
 *       left = 0, right = 4
 *       mid = 0 + (4 - 0) / 2 = 2
 *       nums[2] = 5 < 9
 *       so left = mid + 1 = 3
 *
 *       Now [left, right] = [3, 4].
 *
 *       mid = 3 + (4 - 3) / 2 = 3
 *       nums[3] = 7 < 9
 *       so left = mid + 1 = 4
 *
 *       Now [left, right] = [4, 4].
 *
 *   If the loop condition were left < right, the loop would stop here before
 *   checking nums[4], even though nums[4] == 9.
 *
 *   With left <= right, we enter the loop once more, compute mid = 4, and
 *   correctly return 4.
 *
 * Preservation of the invariant:
 *   On each iteration we compute:
 *
 *       mid = left + (right - left) / 2
 *
 *   instead of:
 *
 *       mid = (left + right) / 2
 *
 *   to avoid potential overflow when left and right are large.
 *
 *   Since the loop condition gives left <= right, we have:
 *
 *       left <= mid <= right
 *
 *   Therefore mid is a valid index in the current candidate interval.
 *
 *   There are three cases:
 *
 *   1. nums[mid] == target
 *
 *      We return mid immediately. This is correct because mid is in range and
 *      nums[mid] is equal to target.
 *
 *   2. nums[mid] < target
 *
 *      Since nums is sorted in non-decreasing order, every index i <= mid
 *      satisfies:
 *
 *          nums[i] <= nums[mid] < target
 *
 *      Therefore target cannot occur at any index i <= mid.
 *
 *      So we can safely rule out the whole range [left, mid] by setting:
 *
 *          left = mid + 1
 *
 *      All indices before the new left have now been ruled out, and the
 *      already ruled-out region after right is unchanged. Thus the invariant
 *      is preserved.
 *
 *   3. nums[mid] > target
 *
 *      Since nums is sorted in non-decreasing order, every index i >= mid
 *      satisfies:
 *
 *          nums[i] >= nums[mid] > target
 *
 *      Therefore target cannot occur at any index i >= mid.
 *
 *      So we can safely rule out the whole range [mid, right] by setting:
 *
 *          right = mid - 1
 *
 *      All indices after the new right have now been ruled out, and the
 *      already ruled-out region before left is unchanged. Thus the invariant
 *      is preserved.
 *
 * Correctness:
 *
 *   Soundness: no false positives
 *   -----------------------------
 *   The function returns an index only in this case:
 *
 *       nums[mid] == target
 *
 *   During the loop, mid is always a valid index because:
 *
 *       left <= mid <= right
 *
 *   and when left <= right, the invariant gives that [left, right] is a valid
 *   segment of the array.
 *
 *   Therefore every returned index is valid and really contains target.
 *
 *
 *   Completeness: no false negatives
 *   --------------------------------
 *   The invariant says that all indices outside [left, right] have already
 *   been ruled out.
 *
 *   Each non-returning iteration preserves this invariant:
 *
 *     - If nums[mid] < target, sortedness rules out every index <= mid, so
 *       moving left to mid + 1 removes only impossible positions.
 *
 *     - If nums[mid] > target, sortedness rules out every index >= mid, so
 *       moving right to mid - 1 removes only impossible positions.
 *
 *   When the loop terminates, the loop condition is false:
 *
 *       !(left <= right)
 *
 *   so:
 *
 *       left > right
 *
 *   The candidate interval [left, right] is empty.
 *
 *   By the invariant:
 *
 *     - every index before left has been ruled out;
 *     - every index after right has been ruled out.
 *
 *   Since left > right, every valid array index is either before left or after
 *   right. Therefore every valid array index has been ruled out, so target
 *   does not occur in nums.
 *
 *   Returning -1 is therefore correct.
 *
 * Termination:
 *   While left <= right, the candidate interval has length:
 *
 *       right - left + 1
 *
 *   This length is a non-negative integer.
 *
 *   On each iteration, either we return immediately, or we strictly shrink
 *   the candidate interval:
 *
 *     - If nums[mid] < target, then left becomes mid + 1.
 *       Since mid >= left, the new left is strictly greater than the old left.
 *
 *     - If nums[mid] > target, then right becomes mid - 1.
 *       Since mid <= right, the new right is strictly smaller than the old
 *       right.
 *
 *   Therefore the non-negative integer length of the candidate interval
 *   strictly decreases on every non-returning iteration.
 *
 *   It cannot decrease indefinitely. Eventually either target is found and
 *   returned, or the interval becomes empty, i.e. left > right, and the loop
 *   terminates.
 *
 * Complexity:
 *   - Time:  O(log n), where n = nums.size(), because each iteration roughly
 *            halves the candidate interval.
 *   - Space: O(1) extra space.
 */
int BinarySearch_704::search(vector<int> &nums, int target)
{
    int left = 0;

    /*
     * nums.size() returns size_t, which is unsigned.
     *
     * If we wrote:
     *
     *     nums.size() - 1
     *
     * and nums were empty, the subtraction would happen in unsigned arithmetic:
     *
     *     0u - 1u
     *
     * which underflows to a huge value, SIZE_MAX.
     *
     * By casting first:
     *
     *     static_cast<int>(nums.size()) - 1
     *
     * an empty vector gives:
     *
     *     static_cast<int>(0) - 1 == -1
     *
     * Therefore for an empty vector we get:
     *
     *     left  = 0
     *     right = -1
     *
     * and the loop condition:
     *
     *     left <= right
     *
     * is immediately false.
     *
     * Limitation:
     *   This assumes nums.size() fits into int. For typical LeetCode
     *   constraints this is fine. In production code, for very large
     *   containers, prefer a signed size type such as std::ptrdiff_t or
     *   std::ssize(nums) in C++20.
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

    return -1;
}
