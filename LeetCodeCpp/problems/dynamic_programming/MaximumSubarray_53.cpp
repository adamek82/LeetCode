#include "MaximumSubarray_53.h"

int MaximumSubarray_53::maxSubArray(const vector<int> &nums)
{
    int cur  = nums[0];
    int best = nums[0];
    for (size_t i = 1; i < nums.size(); ++i) {
        cur  = max(nums[i], cur + nums[i]);
        best = max(best, cur);
    }
    return best;
}