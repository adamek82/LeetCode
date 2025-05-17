#include "MaximumAverageSubarrayI_643.h"

double MaximumAverageSubarrayI_643::findMaxAverage(vector<int> &nums, int k)
{
    long long windowSum = 0;
    // Sum up the first k elements
    for (int i = 0; i < k; ++i) {
        windowSum += nums[i];
    }

    long long maxSum = windowSum;
    // Slide the window: subtract the element leaving, add the new one
    for (int i = k; i < nums.size(); ++i) {
        windowSum += nums[i] - nums[i - k];
        if (windowSum > maxSum) {
            maxSum = windowSum;
        }
    }

    // Return the maximum average
    return static_cast<double>(maxSum) / k;
}