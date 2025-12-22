#include "MergeIntervals_56.h"
#include <vector>
#include <algorithm>

/*
 * Merge Intervals — sort by start, then sweep and merge overlaps
 *
 * Idea
 * ----
 * Sort intervals by their start. Then scan from left to right and maintain
 * a list `merged` that is always:
 *   1) sorted by start, and
 *   2) non-overlapping (each interval ends before the next one starts).
 *
 * During the scan:
 * - If `merged` is empty or the current interval starts after the last merged
 *   interval ends (merged.back()[1] < interval[0]), we append it as a new block.
 * - Otherwise the intervals overlap, so we extend the end of the last merged
 *   interval to cover the current one:
 *     merged.back()[1] = max(merged.back()[1], interval[1]).
 *
 * Correctness (invariant)
 * -----------------------
 * After processing the first k sorted intervals, `merged` equals the union of
 * those k intervals represented as sorted, disjoint intervals. Overlaps can
 * only occur with the last merged interval (because starts are non-decreasing),
 * so it is sufficient to compare/merge with merged.back().
 *
 * Complexity
 * ----------
 * Time:  O(n log n) for sorting + O(n) scan
 * Space: O(n) for the output (plus sorting overhead depending on implementation)
 */
vector<vector<int>> MergeIntervals_56::merge(vector<vector<int>> &intervals)
{
    if (intervals.empty()) return {};

    sort(intervals.begin(), intervals.end(),
         [](const auto& a, const auto& b) { return a[0] < b[0]; });

    vector<vector<int>> merged;
    merged.reserve(intervals.size());

    for (const auto& interval : intervals) {
        if (merged.empty() || merged.back()[1] < interval[0]) {
            merged.push_back(interval);
        } else {
            auto& last = merged.back();
            last[1] = max(last[1], interval[1]);
        }
    }
    return merged;
}
