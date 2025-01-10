#include "MergeIntervals_56.h"

std::vector<std::vector<int>> MergeIntervals_56::merge(std::vector<std::vector<int>> &intervals)
{
    // Sort intervals based on the starting value
    std::sort(intervals.begin(), intervals.end(), [](const std::vector<int>& a, const std::vector<int>& b) {
        return a[0] < b[0];
    });

    std::vector<std::vector<int>> merged;

    for (const auto& interval : intervals) {
        // If merged is empty or the current interval does not overlap with the previous one
        if (merged.empty() || merged.back()[1] < interval[0]) {
            merged.push_back(interval);
        } else {
            // Overlapping intervals, merge them by updating the end time
            merged.back()[1] = std::max(merged.back()[1], interval[1]);
        }
    }

    return merged;
}