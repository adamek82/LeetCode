#include "TwoSumLessThanK_1099.h"
#include <algorithm>

// Returns the maximum nums[i] + nums[j] < k for i < j, or -1 if no such pair exists.
int TwoSumLessThanK_1099::twoSumLessThanK(std::vector<int>& nums, int k) {
    if (nums.size() < 2) return -1;

    std::sort(nums.begin(), nums.end());

    int left = 0;
    int right = static_cast<int>(nums.size()) - 1;
    int best = -1;

    while (left < right) {
        const int sum = nums[left] + nums[right];

        if (sum < k) {
            if (sum > best) best = sum;
            ++left;   // try to increase sum (since it's valid)
        } else {
            --right;  // sum too big, decrease it
        }
    }

    return best;
}
