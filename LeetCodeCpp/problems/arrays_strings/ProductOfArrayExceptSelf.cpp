#include "ProductOfArrayExceptSelf.h"

vector<int> ProductOfArrayExceptSelf::productExceptSelf(const vector<int>& nums)
{
    vector<int> result(nums.size(), 1);

    int prefix = 1;

    for (size_t i = 0; i < nums.size(); ++i) {
        result[i] = prefix;
        prefix *= nums[i];
    }

    int suffix = 1;

    for (size_t i = nums.size(); i-- > 0;) {
        result[i] *= suffix;
        suffix *= nums[i];
    }

    return result;
}
