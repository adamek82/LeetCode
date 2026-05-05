#include "LongestConsecutiveSequence_128.h"
#include <unordered_set>
#include <algorithm>

/*
 * Hash-set based expected O(n) solution.
 *
 * Idea:
 * - Insert all numbers into an unordered_set, so membership checks are O(1) on average.
 *   Duplicates are removed automatically, which is fine because they do not change the
 *   length of any consecutive sequence.
 * - Reserve space before inserting elements to reduce the number of rehashes while the
 *   set is being built.
 * - Iterate over the set, not over the original vector, so each distinct value is
 *   considered only once.
 * - A value `x` can only be the start of a consecutive sequence if `x - 1` is not
 *   present in the set. If `x - 1` exists, then the same sequence will be counted
 *   starting from that smaller value, so `x` should be skipped.
 * - For every detected start, walk forward through `x + 1`, `x + 2`, ... as long as
 *   the next value exists. Keep `end` as the last value of the current run; the run
 *   length is `end - x + 1`.
 * - Track the maximum run length.
 *
 * Correctness sketch:
 * - After building `st`, it contains exactly the distinct values from `nums`.
 *   Removing duplicates does not affect the answer, because consecutive sequences
 *   depend only on whether a value exists, not on how many times it appears.
 * - If `x - 1` is not in `st`, then no smaller consecutive predecessor of `x` exists,
 *   so any maximal consecutive run containing `x` must start at `x`.
 * - If `x - 1` is in `st`, then `x` is not the first element of its run, so skipping it
 *   is safe.
 * - Starting from a valid start `x`, the while loop extends the run exactly while the
 *   next consecutive value exists. When the loop stops, `end + 1` is missing, so `end`
 *   is the last value of the maximal run starting at `x`.
 * - Every maximal run is counted exactly once: at its smallest value. All other values
 *   in the same run have a predecessor in `st` and therefore fail the start test.
 *
 * Complexity:
 * - Building the set takes expected O(n) time and O(n) extra space.
 * - The outer loop iterates over at most n distinct values.
 * - Across all starts, the inner while loops advance through each distinct value at
 *   most once as part of some run, so the total work of all forward scans is O(n).
 * - Overall expected time: O(n), space: O(n).
 *
 * Note:
 * - The O(n) bound is expected, not guaranteed, because it relies on average-case
 *   unordered_set operations.
 */
int LongestConsecutiveSequence_128::longestConsecutive(vector<int>& nums)
{
    unordered_set<int> st;
    st.reserve(nums.size() * 2);

    for (int x : nums) {
        st.insert(x);
    }

    int longest = 0;

    for (int x : st) {
        // Only start counting if 'x' is the beginning of a sequence.
        if (!st.contains(x - 1)) {
            int end = x;

            // Extend the run as long as the next consecutive value exists.
            while (st.contains(end + 1)) {
                ++end;
            }

            longest = max(longest, end - x + 1);
        }
    }

    return longest;
}
