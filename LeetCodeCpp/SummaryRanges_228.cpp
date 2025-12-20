#include "SummaryRanges_228.h"

/*
 * Summary Ranges (LeetCode 228) — Scan and Compress Consecutive Runs
 * -----------------------------------------------------------------
 * Method:
 *   Walk through the sorted array and group maximal consecutive segments.
 *   For each segment starting at i:
 *     - start = nums[i], end = start
 *     - advance j while nums[j] continues the run (nums[j] == end + 1)
 *   Emit either "start" (single number) or "start->end" (range),
 *   then continue from i = j.
 *
 * Overflow note (why long long):
 *   The consecutive check compares nums[j] with (end + 1).
 *   If end is near INT_MAX, doing (end + 1) in 32-bit could overflow.
 *   Casting to long long ensures end + 1 is computed safely.
 */

vector<string> SummaryRanges_228::summaryRanges(vector<int>& nums) {
    vector<string> out;
    const int n = (int)nums.size();
    int i = 0;

    while (i < n) {
        long long start = nums[i];
        long long end   = start;
        int j = i + 1;

        // use 64-bit math to avoid overflow on (prev + 1) near INT_MAX
        while (j < n && (long long)nums[j] == end + 1) {
            end = nums[j];
            ++j;
        }

        if (start == end) {
            out.push_back(to_string(start));
        } else {
            out.push_back(to_string(start) + "->" + to_string(end));
        }
        i = j;
    }
    return out;
}
