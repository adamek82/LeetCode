#include "ProductOfArrayExceptSelf.h"

std::vector<int> ProductOfArrayExceptSelf::productExceptSelf(std::vector<int> &nums)
{
    int n = nums.size();
    std::vector<int> result(n, 1);

    // Calculate prefix products
    int prefix = 1;
    for (int i = 0; i < n; ++i) {
        result[i] = prefix;
        prefix *= nums[i];
    }

    // Calculate suffix products and multiply with prefix products
    int suffix = 1;
    for (int i = n - 1; i >= 0; --i) {
        result[i] *= suffix;
        suffix *= nums[i];
    }

    return result;
}