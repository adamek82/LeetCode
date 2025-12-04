#include "FirstBadVersion_278.h"

/*
 * Binary search for the first bad version
 * ---------------------------------------
 * We search in the integer interval [1, n] where there is at least one
 * bad version and the predicate isBadVersion(version) is monotone:
 *
 *      good, good, ..., good, bad, bad, ..., bad
 *                     ^ first bad
 *
 * Idea:
 *   - Maintain a closed interval [left, right] such that:
 *       (1) There is at least one bad version in [left, right].
 *       (2) The first bad version F lies within [left, right].
 *   - At each step, probe the midpoint:
 *
 *         mid = left + (right - left) / 2
 *
 *     to avoid overflow compared to (left + right) / 2.
 *
 *   Case 1: isBadVersion(mid) == true
 *       mid is bad. Since the predicate is monotone, all versions >= mid
 *       are also bad. The first bad version F cannot be to the *right* of mid.
 *       Therefore F lies in [left, mid], and we shrink the interval:
 *
 *         right = mid;
 *
 *   Case 2: isBadVersion(mid) == false
 *       mid is good. All versions <= mid are good as well, so F cannot be
 *       in [left, mid]. The first bad version must lie in (mid, right],
 *       so we move the left boundary:
 *
 *         left = mid + 1;
 *
 * Loop invariant:
 *   At the beginning of each iteration:
 *     - There is at least one bad version in [left, right].
 *     - The first bad version F lies in [left, right].
 *
 *   The update rules above preserve this invariant:
 *     - If mid is bad, [left, mid] still contains F and at least one bad.
 *     - If mid is good, (mid, right] still contains F and at least one bad.
 *
 * Why the condition "left < right"?
 *   - We keep [left, right] as a non-empty interval that always contains F.
 *   - When left == right, there is exactly one candidate left, and by the
 *     invariant that candidate must be F. At that point we stop the loop
 *     and return left (or right; they are equal).
 *   - Using "left < right" ensures the loop terminates as we strictly
 *     shrink the length of the interval on each iteration:
 *         - right = mid  with mid < right
 *         - left = mid + 1 with left > mid
 *
 * Correctness sketch:
 *   - Soundness (no false positives):
 *       We return left only after the loop ends with left == right and the
 *       invariant guarantees that F is in [left, right]. Hence left is F.
 *
 *   - Completeness (no false negatives):
 *       Initially [left, right] = [1, n], which trivially contains F.
 *       Each iteration preserves "F ∈ [left, right]" and shrinks the
 *       interval. Eventually, the interval size becomes 1, so it must be
 *       exactly {F}, and the loop exits with left == F.
 *
 * Complexity:
 *   - Time:  O(log n) calls to isBadVersion (we halve the interval).
 *   - Space: O(1) extra space.
 */
int FirstBadVersion_278::firstBadVersion(int n)
{
    int left = 1;
    int right = n;

    while (left < right) {
        int mid = left + (right - left) / 2; // avoid potential overflow

        if (isBadVersion(mid)) {
            // mid is bad → first bad version lies in [left, mid]
            right = mid;
        } else {
            // mid is good → first bad version lies in (mid, right]
            left = mid + 1;
        }
    }

    // At this point left == right and points to the first bad version.
    return left;
}

bool FirstBadVersion_278::isBadVersion(int version) const
{
    return version >= firstBad;
}
