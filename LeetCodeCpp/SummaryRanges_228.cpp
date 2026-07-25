#include "SummaryRanges_228.h"

vector<string> SummaryRanges_228::summaryRanges(const vector<int>& nums)
{
    vector<string> ranges;
    ranges.reserve(nums.size());

    size_t i = 0;

    while (i < nums.size()) {
        const int start = nums[i];
        size_t j = i + 1;

        while (j < nums.size() && nums[j] == nums[j - 1] + 1)
            ++j;

        const int end = nums[j - 1];

        if (start == end)
            ranges.push_back(to_string(start));
        else
            ranges.push_back(to_string(start) + "->" + to_string(end));

        i = j;
    }

    return ranges;
}
