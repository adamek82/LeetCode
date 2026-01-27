#include "LongestConsecutiveSequence_128.h"
#include <unordered_set>
#include <algorithm>

/*
 * Hash-set based expected O(n) solution.
 *
 * Idea:
 * - Insert all numbers into an unordered_set for O(1) average-time membership tests.
 * - A value `x` can only be the *start* of a consecutive sequence if `(x - 1)` is
 *   not in the set. For all other values (that have a predecessor), we skip work,
 *   because their sequence will be counted starting from that smaller predecessor.
 * - For each such starting value, walk forward (`x, x+1, x+2, ...`) as long as the
 *   next value is present in the set. Instead of maintaining a separate counter,
 *   keep `end` as the last value of the run; the run length is `end - x + 1`.
 * - Track the maximum length over all runs.
 *
 * Correctness sketch:
 * - Construction: after building `st`, for every v in `nums`, v is in `st`.
 *   Duplicates collapse in the set, which does not affect the longest consecutive length.
 * - Start detection: if `st` does not contain `x - 1`, then `x` has no predecessor in
 *   the set, so any maximal consecutive sequence containing `x` must start at `x`.
 * - Forward scan: while `st` contains `end + 1`, we can extend the run by one.
 *   When the loop stops, `end + 1` is missing, so `end` is the last element of the
 *   maximal run starting at `x`, and its length is `end - x + 1`.
 * - Uniqueness: each maximal run is counted exactly once at its smallest element.
 *   Any other element y in that run has y - 1 in `st`, so it fails the start test.
 *
 * Complexity:
 * - Building the set takes expected O(n) time and O(n) extra space.
 * - The outer loop iterates over `nums`; only starts trigger the inner scan.
 * - Across the whole algorithm, the inner while loops advance `end` a total of O(n)
 *   times (amortized), because each distinct value can be the "next" element in a run
 *   at most once.
 * - Overall expected time: O(n), space: O(n).
 */
int LongestConsecutiveSequence_128::longestConsecutive(vector<int>& nums)
{
    unordered_set<int> st(nums.begin(), nums.end());
    int longest = 0;

    for (int x : nums) {
        // Only start counting if 'x' is the beginning of a sequence.
        if (!st.contains(x - 1)) {
            int end = x;

            // Extend the run as long as the next consecutive value exists.
            while (st.contains(end + 1)) ++end;

            longest = max(longest, end - x + 1);
        }
    }
    return longest;
}
