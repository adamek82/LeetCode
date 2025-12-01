#include "BinarySearch_704.h"

/*
 * Binary search (LeetCode 704)
 * ----------------------------
 * Searches for target in a sorted (non-decreasing) array nums and returns its
 * index, or -1 if target is not present.
 *
 * Invariant (closed interval):
 *   - At the start of each iteration, if target exists in nums, then it lies
 *     within the inclusive index range [left, right].
 *   - The range [left, right] is always a valid segment of the array
 *     (0 <= left && right < nums.size() when left <= right).
 *
 * Loop steps:
 *   - We compute:
 *         mid = left + (right - left) / 2
 *     instead of (left + right) / 2 to avoid potential overflow when left
 *     and right are large.
 *
 *   - If nums[mid] == target:
 *       We have found target, and mid is a valid answer.
 *
 *   - If nums[mid] < target:
 *       All indices i <= mid have nums[i] <= nums[mid] < target (array is
 *       sorted), so target cannot be in [left, mid]. We therefore move the
 *       left boundary to mid + 1, keeping the invariant that, if target
 *       exists, it is in [left, right].
 *
 *   - If nums[mid] > target:
 *       All indices i >= mid have nums[i] >= nums[mid] > target, so target
 *       cannot be in [mid, right]. We move the right boundary to mid - 1 and
 *       again preserve the invariant.
 *
 * Why "left <= right" (and not "left < right")?
 *   - We treat [left, right] as a *closed* interval of candidates.
 *   - When left == right, there is still exactly one index that might hold
 *     target, so we must enter the loop and check that element.
 *   - Once left becomes right + 1, the interval is empty; there are no
 *     remaining candidates, so the loop terminates.
 *   - If we used left < right instead, the case left == right would not be
 *     processed, and a valid single-element interval could be skipped.
 *
 *   Example where "left < right" loses a valid answer:
 *     - Let nums = [1, 3, 5, 7, 9] and target = 9.
 *     - Initial state: left = 0, right = 4.
 *         mid = 0 + (4 - 0) / 2 = 2  → nums[2] = 5 < 9
 *         ⇒ move left to mid + 1 = 3, so [left, right] = [3, 4].
 *     - Next iteration (still with left < right):
 *         mid = 3 + (4 - 3) / 2 = 3  → nums[3] = 7 < 9
 *         ⇒ move left to mid + 1 = 4, so [left, right] = [4, 4].
 *     - Now the only valid answer is at index 4 (nums[4] == 9), but:
 *         * with condition (left < right), we have left == right,
 *           so the loop stops *before* checking nums[4];
 *         * the algorithm incorrectly returns -1 even though target is present.
 *     - With (left <= right), we would enter the loop once more with
 *       left == right == 4, compute mid = 4, and correctly return index 4.
 *
 * Correctness sketch:
 *   Soundness (no false positives):
 *     - The only way we return an index is inside the loop when
 *         nums[mid] == target.
 *     - mid is always between left and right, and while left <= right we
 *       have 0 <= left <= mid <= right < nums.size().
 *     - Therefore any returned index mid is in range and satisfies
 *       nums[mid] == target.
 *
 *   Completeness (no false negatives):
 *     - We argue by induction on the loop iterations using the invariant:
 *         P(t): at the beginning of iteration t (before computing mid),
 *               if target is present at some index k, then k ∈ [left, right].
 *
 *     - Base case (t = 0):
 *         At the very start, left = 0 and right = nums.size() - 1,
 *         so any valid index k with nums[k] == target satisfies
 *         k ∈ [0, nums.size() - 1] = [left, right]. Thus P(0) holds.
 *
 *     - Inductive step:
 *         Assume P(t) holds at the start of some iteration t, i.e., if
 *         target exists at index k, then k ∈ [left, right].
 *         In this iteration we compute mid and compare nums[mid] with target:
 *
 *           * If nums[mid] < target:
 *               Because the array is sorted and nums[mid] < target,
 *               every index i <= mid has nums[i] <= nums[mid] < target.
 *               So k cannot be <= mid; if target exists, it must lie in
 *               [mid + 1, right]. We set left = mid + 1 and keep right
 *               unchanged, so k remains in the new [left, right].
 *
 *           * If nums[mid] > target:
 *               By sortedness and nums[mid] > target, every index i >= mid
 *               has nums[i] >= nums[mid] > target. So k cannot be >= mid;
 *               if target exists, it must lie in [left, mid - 1]. We set
 *               right = mid - 1 and keep left unchanged, so k remains in
 *               the new [left, right].
 *
 *           * If nums[mid] == target:
 *               We return mid immediately, so we never break the invariant
 *               and we have found a correct index.
 *
 *         Therefore, whenever we do not return, the update of [left, right]
 *         preserves the invariant: if target exists, its index k is still
 *         inside the new interval at the beginning of the next iteration.
 *
 *     - By induction, P(t) holds at the beginning of every iteration as long
 *       as target exists in the array. The interval [left, right] strictly
 *       shrinks whenever we do not find target, so it eventually reduces to
 *       a single index k, at which point mid == k and nums[mid] == target,
 *       and the algorithm returns that index instead of -1.
 *
 * Termination:
 *   - On each iteration, we either return (when nums[mid] == target), or we
 *     strictly shrink the interval:
 *         - right -> mid - 1  (upper bound moves left), or
 *         - left  -> mid + 1  (lower bound moves right).
 *   - The length of [left, right] is a non-negative integer, so it can only
 *     shrink a finite number of times before becoming empty (left > right),
 *     at which point the loop ends and we return -1.
 *
 * Complexity:
 *   - Time:  O(log n), where n = nums.size(), because we roughly halve the
 *            search interval each iteration.
 *   - Space: O(1) extra space.
 */
int BinarySearch_704::search(vector<int> &nums, int target)
{
    int left = 0, right = nums.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2; // Prevents overflow

        if (nums[mid] == target) {
            return mid; // Target found, return its index
        } else if (nums[mid] < target) {
            left = mid + 1; // Search in the right half
        } else {
            right = mid - 1; // Search in the left half
        }
    }

    return -1; // Target not found
}