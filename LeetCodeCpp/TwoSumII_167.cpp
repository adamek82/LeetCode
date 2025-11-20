#include "TwoSumII_167.h"
#include <vector>

/*
 * Two Sum II – Input Array Is Sorted (LeetCode 167)
 *
 * Given a non-decreasing array of integers and a target value,
 * finds the indices of the two numbers such that they add up to target.
 * The solution is guaranteed to exist and must be returned as 1-based indices.
 *
 * Idea:
 *   - The array is sorted, so we can use a two-pointer approach.
 *   - Start with one pointer at the beginning (l) and one at the end (r).
 *   - Compute sum = numbers[l] + numbers[r]:
 *       - If sum == target, we found the (unique) pair.
 *       - If sum < target, we need a larger sum → move l right.
 *       - If sum > target, we need a smaller sum → move r left.
 *
 * Why two pointers are enough:
 *   - For any fixed l, increasing r can only increase the sum; decreasing r
 *     can only decrease it, because the array is sorted.
 *   - If sum < target at (l, r), then any pair (l, r') with r' < r will give
 *     an even smaller sum, so the correct pair (if it uses l) must have a
 *     larger index on the left side → we safely increment l.
 *   - If sum > target at (l, r), then any pair (l', r) with l' > l will give
 *     an even larger sum, so the correct pair (if it uses r) must have a
 *     smaller index on the right side → we safely decrement r.
 *   - This monotonicity ensures we never skip the valid pair: each move
 *     discards only index combinations that cannot possibly be a solution.
 *
 * Complexity:
 *   - Time:  O(n) — each pointer moves at most n steps in total.
 *   - Space: O(1) — uses only a few extra variables.
 */
vector<int> TwoSumII_167::twoSum(vector<int> &numbers, int target)
{
    int l = 0, r = static_cast<int>(numbers.size()) - 1;
    while (l < r) {
        int sum = numbers[l] + numbers[r];
        if (sum == target)        // found the (unique) pair
            return {l + 1, r + 1};   // convert to 1-indexed
        if (sum < target)
            ++l;                   // need a larger sum
        else
            --r;                   // need a smaller sum
    }
    return {};  // unreachable – problem guarantees a solution
}