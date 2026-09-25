#pragma once
#include <vector>

class LongestIncreasingSubsequence_300 {
public:
    int lengthOfLIS_tails(std::vector<int>& nums);

    int lengthOfLIS_dp(const std::vector<int>& nums);

    std::vector<int> getLIS_tails(const std::vector<int>& nums);

    std::vector<int> getLIS_dp(const std::vector<int>& nums);
};
