#include "SquaresOfSortedArray_977.h"
#include <vector>

/*
 * Squares of a Sorted Array (LeetCode 977)
 *
 * Given a non-decreasing array of integers (may contain negatives),
 * returns a new array of their squares, also sorted in non-decreasing order.
 *
 * Idea:
 *   - The largest squares must come from elements with the largest absolute
 *     values, which are always located at the ends of the sorted array.
 *   - Use two pointers: one at the left end (l) and one at the right end (r).
 *   - At each step, compare abs(nums[l]) and abs(nums[r]) to find which side
 *     produces the larger square.
 *
 * Steps:
 *   - Initialize l = 0 and r = n - 1.
 *   - Iterate pos from n - 1 down to 0 (filling the result array from back):
 *       - If abs(nums[l]) > abs(nums[r]):
 *             res[pos] = nums[l] * nums[l]; ++l;
 *         else:
 *             res[pos] = nums[r] * nums[r]; --r;
 *   - Return res; it is sorted because we always place the currently largest
 *     remaining square at the next free position from the end.
 *
 * Complexity:
 *   - Time:  O(n) — each element is inspected and written exactly once.
 *   - Space: O(n) — for the output array (excluding input).
 */

vector<int> SquaresOfSortedArray_977::sortedSquares(const vector<int> &nums)
{
    int n = static_cast<int>(nums.size());
    vector<int> res(n);            // result, to be filled from back → front
    int l = 0, r = n - 1;          // two pointers

    for (int pos = n - 1; pos >= 0; --pos) {
        int leftVal  = nums[l];
        int rightVal = nums[r];

        if (abs(leftVal) > abs(rightVal)) {     // left dominates
            res[pos] = leftVal * leftVal;
            ++l;
        } else {                                // right dominates (or ties)
            res[pos] = rightVal * rightVal;
            --r;
        }
    }
    return res;
}