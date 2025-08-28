#include "SummaryRanges_228.h"

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
