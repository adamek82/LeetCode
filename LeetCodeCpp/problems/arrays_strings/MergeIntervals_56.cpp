#include "MergeIntervals_56.h"
#include <algorithm>

vector<vector<int>> MergeIntervals_56::merge(vector<vector<int>>& intervals)
{
    sort(intervals.begin(), intervals.end());

    vector<vector<int>> merged;
    merged.reserve(intervals.size());

    for (const auto& interval : intervals) {
        if (merged.empty() || interval[0] > merged.back()[1]) {
            merged.push_back(interval);
        } else {
            merged.back()[1] = max(merged.back()[1], interval[1]);
        }
    }

    return merged;
}
