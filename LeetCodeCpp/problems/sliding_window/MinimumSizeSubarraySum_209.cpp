#include "MinimumSizeSubarraySum_209.h"
#include <limits>
#include <algorithm>

using namespace std;

int MinimumSizeSubarraySum_209::minSubArrayLen(int target, const vector<int>& nums)
{
    size_t left = 0;
    size_t best = nums.size() + 1;
    long long sum = 0;

    for (size_t right = 0; right < nums.size(); ++right) {
        sum += nums[right];

        while (sum >= target) {
            best = min(best, right + 1 - left);
            sum -= nums[left++];
        }
    }

    return best > nums.size() ? 0 : static_cast<int>(best);
}
