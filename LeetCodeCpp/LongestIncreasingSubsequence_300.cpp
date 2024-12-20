#include "LongestIncreasingSubsequence_300.h"

int LongestIncreasingSubsequence_300::lengthOfLIS(std::vector<int> &nums)
{
    std::vector<int> sub;
    for (int num : nums) {
        // Find the first element in 'sub' that is >= num
        auto it = std::lower_bound(sub.begin(), sub.end(), num);
        if (it == sub.end()) {
            // If num is greater than all elements, append it
            sub.push_back(num);
        } else {
            // Otherwise, replace the first element >= num
            *it = num;
        }
    }
    return sub.size();
}
