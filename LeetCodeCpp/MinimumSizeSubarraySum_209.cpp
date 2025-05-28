#include "MinimumSizeSubarraySum_209.h"

int MinimumSizeSubarraySum_209::minSubArrayLen(int target, vector<int> &nums)
{
    int n = nums.size();
    int l = 0;                            // left boundary
    long long sum = 0;                    // running window sum
    int best = numeric_limits<int>::max();   // minimal length so far

    for (int r = 0; r < n; ++r) {
        sum += nums[r];                   // expand window

        // shrink from the left while we still meet / exceed target
        while (sum >= target) {
            best = min(best, r - l + 1);
            sum -= nums[l++];
        }
    }
    return best == numeric_limits<int>::max() ? 0 : best;
}