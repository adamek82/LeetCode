#include "MaxConsecutiveOnesIII_1004.h"

int MaxConsecutiveOnesIII_1004::longestOnes(vector<int> &nums, int k)
{
    int left = 0;            // Left end of the window
    int maxLen = 0;          // Result: maximum window size
    int zerosCount = 0;      // Number of zeros in the current window

    // Expand the window with right
    for (int right = 0; right < (int)nums.size(); ++right) {
        if (nums[right] == 0) {
            ++zerosCount;
        }

        // If too many zeros, contract from the left
        while (zerosCount > k) {
            if (nums[left] == 0) {
                --zerosCount;
            }
            ++left;
        }

        // Window [left..right] is valid: update maximum length
        maxLen = max(maxLen, right - left + 1);
    }

    return maxLen;
}
