#include "MaxConsecutiveOnesIII_1004.h"
#include <algorithm>
#include <cstddef>

using namespace std;

int MaxConsecutiveOnesIII_1004::longestOnes(const vector<int>& nums, int k)
{
    size_t left = 0;
    int remainingFlips = k;

    for (size_t right = 0; right < nums.size(); ++right) {
        if (nums[right] == 0) {
            --remainingFlips;
        }

        if (remainingFlips < 0 && nums[left++] == 0) {
            ++remainingFlips;
        }
    }

    return static_cast<int>(nums.size() - left);
}
