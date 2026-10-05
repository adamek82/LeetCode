#include "MaximumAverageSubarrayI_643.h"
#include <algorithm>
#include <cstddef>

using namespace std;

double MaximumAverageSubarrayI_643::findMaxAverage(const vector<int>& nums, int k)
{
    const size_t windowSize = static_cast<size_t>(k);
    long long windowSum = 0;
    for (size_t i = 0; i < windowSize; ++i) {
        windowSum += nums[i];
    }

    long long maxSum = windowSum;
    for (size_t i = windowSize; i < nums.size(); ++i) {
        windowSum -= nums[i - windowSize];
        windowSum += nums[i];
        maxSum = max(maxSum, windowSum);
    }

    return static_cast<double>(maxSum) / k;
}
