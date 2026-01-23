#include "MaximumAverageSubarrayI_643.h"

/*
 * Maximum Average Subarray I (LeetCode 643) — sliding window
 *
 * Idea
 * ----
 * We need the maximum average of any contiguous subarray of length k.
 * Since k is fixed, maximizing the average is the same as maximizing the sum.
 *
 * Sliding window
 * --------------
 * Compute the sum of the first k elements. Then move the window one step at a time:
 * remove the element that leaves the window (nums[i-k]) and add the new element
 * that enters (nums[i]). This updates the window sum in O(1) per step.
 *
 * Why long long
 * -------------
 * Sums can exceed 32-bit int when k is large or values are big, so we use 64-bit
 * accumulation to avoid overflow.
 *
 * Complexity
 * ----------
 * Time:  O(n)   (each element is added/removed at most once)
 * Space: O(1)
 */
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
