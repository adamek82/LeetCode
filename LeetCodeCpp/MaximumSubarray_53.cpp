#include "MaximumSubarray_53.h"

int MaximumSubarray_53::maxSubArray(const vector<int> &nums)
{
    int cur  = nums[0];
    int best = nums[0];
    for (size_t i = 1; i < nums.size(); ++i) {
        cur  = std::max(nums[i], cur + nums[i]);
        best = std::max(best, cur);
    }
    return best;
}