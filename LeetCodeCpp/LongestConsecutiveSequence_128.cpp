#include "LongestConsecutiveSequence_128.h"
#include <unordered_set>
#include <algorithm>

/*
 * Hash-set based O(n) solution.
 *
 * Idea:
 * - Insert all numbers into an unordered_set for O(1) average-time membership tests.
 * - A number `num` can only be the *start* of a consecutive sequence if `(num - 1)` is
 *   not in the set. For all other numbers (that have a predecessor), we skip work, because
 *   their sequence will be counted starting from that smaller predecessor.
 * - For each such starting number, we walk forward (`num, num+1, num+2, ...`) as long as
 *   the next value is present in the set, counting the length of this consecutive run.
 * - Track the maximum length over all runs.
 *
 * Correctness sketch (invariants):
 * - Construction invariant: after creating `st`, for every original value v in `nums`,
 *   `v` is in `st`. Duplicates in `nums` are collapsed to a single entry in `st`,
 *   which does not affect the longest consecutive *length*.
 * - Start-detection invariant: when we enter the `if (st.find(num - 1) == st.end())`
 *   branch, `num` has no predecessor in the set. Therefore any maximal consecutive
 *   sequence containing `num` must start exactly at `num`.
 * - Loop invariant: inside the `while (st.find(current + 1) != st.end())` loop:
 *   * `st` contains all integers from `num` through `current`,
 *   * `streak == current - num + 1` (streak reflects the length of the sequence seen so far),
 *   * `current + 1` is the next candidate in this sequence.
 *   When the loop terminates, `current + 1` is not in `st`, so `current` is the last
 *   element of this maximal consecutive run starting at `num`, and `streak` is its length.
 * - Uniqueness: every maximal consecutive run is counted exactly once, at its smallest
 *   element. Any other element of that run has a predecessor in `st` and fails the
 *   `st.find(num - 1) == st.end()` test, so we never double-count the same run.
 *
 * Complexity:
 * - Building the set from `nums` takes O(n) average time and O(n) extra memory.
 * - The outer loop visits each distinct value in `st` once.
 * - The inner `while` loop over `current` advances each value at most once across the
 *   entire algorithm (amortized O(n)), because we only move `current` forward, and each
 *   integer can be the “next” element in some sequence at most one time.
 * - Overall expected time complexity: O(n), where n is the size of `nums`.
 * - Space complexity: O(n) for the unordered_set.
 */
int LongestConsecutiveSequence_128::longestConsecutive(vector<int> &nums)
{
    unordered_set<int> st(nums.begin(), nums.end());
    int longest = 0;

    for (int num : st) {
        // only start counting if 'num' is the beginning of a sequence
        if (st.find(num - 1) == st.end()) {
            int current = num;
            int streak = 1;

            // walk forward until the end of this consecutive run
            while (st.find(current + 1) != st.end()) {
                current++;
                streak++;
            }

            longest = max(longest, streak);
        }
    }

    return longest;
}