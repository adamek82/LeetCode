#include "SearchInsertPosition_35.h"

/*
 * Binary search — insertion index variant
 * ---------------------------------------
 * Returns the index at which `target` should be inserted into a sorted
 * (strictly increasing) array `nums` so that the order is preserved.
 * If `target` is already present, this returns the index of one of its
 * occurrences (the first one for strictly increasing input).
 *
 * For a detailed discussion of the *basic* binary search mechanics
 * (closed interval, invariant, termination, complexity), see the
 * documentation in BinarySearch_704.cpp. Here we focus on why the
 * final value of `left` is exactly the correct insertion position.
 *
 * High-level idea
 * ---------------
 * We run a standard binary search on a closed interval [left, right]
 * using:
 *
 *   - if nums[mid] == target: return mid;
 *   - if nums[mid] <  target: move left  to mid + 1;
 *   - if nums[mid] >  target: move right to mid - 1;
 *
 * If we never find `target`, the loop eventually terminates with
 * left == right + 1 and we return `left`. This `left` is the smallest
 * index where `target` could be placed without breaking the sort order.
 *
 * Key invariants (strengthened)
 * -----------------------------
 * At the start of each iteration we maintain:
 *
 *   1) Search interval invariant:
 *        If `target` exists in the array, then its index k lies in
 *        the closed interval [left, right].
 *
 *   2) Ordering invariant around the interval:
 *        All indices i < left  satisfy nums[i] < target.
 *        All indices i > right satisfy nums[i] > target.
 *
 * These two properties together say: everything strictly before `left`
 * is *too small*, everything strictly after `right` is *too large*, and
 * if `target` exists at all, it must be somewhere inside [left, right].
 *
 * Why the updates preserve the invariants
 * ---------------------------------------
 * Consider one loop iteration with some mid between left and right:
 *
 *   - Case A: nums[mid] == target
 *       We immediately return mid. This is a correct index where
 *       target appears, so we do not care about insertion any more.
 *
 *   - Case B: nums[mid] < target
 *       Since the array is sorted and nums[mid] < target:
 *         * For all i <= mid, nums[i] <= nums[mid] < target,
 *           so every index up to and including mid is "too small".
 *       Therefore target, if present, must lie strictly to the right
 *       of mid, in [mid + 1, right].
 *
 *       We set:
 *           left  = mid + 1;
 *           right = right;
 *
 *       This moves `left` rightwards so that:
 *         * All indices i < left are now <= mid and hence have
 *           nums[i] < target — still "too small".
 *         * We have not changed `right`, so any valid index k for
 *           target is still in [left, right].
 *
 *   - Case C: nums[mid] > target
 *       Symmetrically, by sortedness and nums[mid] > target:
 *         * For all i >= mid, nums[i] >= nums[mid] > target,
 *           so every index from mid to right is "too large".
 *
 *       We set:
 *           right = mid - 1;
 *           left  = left;
 *
 *       This moves `right` leftwards so that:
 *         * All indices i > right are now >= mid and thus have
 *           nums[i] > target — still "too large".
 *         * Any valid index k for target remains in [left, right].
 *
 * In both Case B and Case C the strengthened invariants are preserved:
 *   - Everything before `left` stays strictly < target.
 *   - Everything after `right` stays strictly > target.
 *   - If target exists, its index remains in [left, right].
 *
 * Why `left` is the insertion point when the loop ends
 * ----------------------------------------------------
 * The loop condition is `while (left <= right)`. It stops only when
 * `left` has advanced past `right`, i.e. when `left == right + 1`.
 *
 * At that moment:
 *
 *   - From the ordering invariant:
 *       * For all i < left, nums[i] < target.
 *       * For all i > right, nums[i] > target.
 *     But since left == right + 1, every index i >= left automatically
 *     satisfies i > right, so every i >= left has nums[i] > target
 *     (if such i exists at all).
 *
 *   - Thus the array is partitioned as:
 *
 *         indices:    [0, ..., left-1] | [left, left+1, ...]
 *         values:     < target         | >= target (or no elements)
 *
 *   - This means:
 *       * `left` is the smallest index at which an element >= target
 *         could appear (if any exist).
 *       * All elements strictly before `left` are < target, so inserting
 *         target at position `left` keeps the array sorted.
 *       * There is no earlier index where we could insert target without
 *         breaking sorted order, because any such index i < left would
 *         have nums[i] >= target, contradicting the invariant
 *         nums[i] < target for all i < left.
 *
 * Correctness sketch for the insertion index
 * ------------------------------------------
 *   - Soundness:
 *       Returning `left` never breaks the sort order:
 *         * Every element before `left` is < target.
 *         * Every element at or after `left` is >= target (if present).
 *       So placing target at `left` yields:
 *           nums[0] <= ... < nums[left-1] < target <= nums[left] <= ...
 *
 *   - Minimality:
 *       `left` is the *first* index where we can insert target:
 *         * If there were a smaller index j < left where inserting target
 *           preserved sorted order, we would need nums[j] >= target.
 *         * But for all i < left we maintain nums[i] < target, so such
 *           a j cannot exist. Hence `left` is minimal.
 *
 *   - Completeness:
 *       If `target` is already in the array at index k, the above logic
 *       ensures that index k is never thrown away (it stays in [left, right]
 *       until found), so we return a correct occurrence instead of an
 *       insertion position. If `target` is *not* present, the invariants
 *       and the argument above guarantee that the final `left` is the
 *       unique correct insertion index.
 *
 * Complexity:
 *   - Time:  O(log n) in the length of nums, as we halve the search
 *            region each iteration.
 *   - Space: O(1) extra space.
 */
int SearchInsertPosition_35::searchInsert(vector<int> &nums, int target)
{
    int left = 0, right = nums.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2; // Prevents overflow

        if (nums[mid] == target) {
            return mid; // Target found, return its index
        } else if (nums[mid] < target) {
            left = mid + 1; // Narrow search to the right half
        } else {
            right = mid - 1; // Narrow search to the left half
        }
    }

    // If the loop ends, `left` is the insertion point
    return left;
}
