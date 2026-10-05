#include "MaxConsecutiveOnesIII_1004.h"
#include <algorithm>
#include <cstddef>

using namespace std;

int MaxConsecutiveOnesIII_1004::longestOnes(const vector<int>& nums, int k)
{
    size_t left = 0;
    size_t best = 0;

    for (size_t right = 0; right < nums.size(); ++right) {
        if (nums[right] == 0) --k;

        while (k < 0) {
            if (nums[left] == 0) ++k;
            ++left;
        }

        best = max(best, right + 1 - left);
    }

    return static_cast<int>(best);
}
