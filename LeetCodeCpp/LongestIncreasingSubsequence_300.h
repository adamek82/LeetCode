#pragma once
#include <vector>

using namespace std;

class LongestIncreasingSubsequence_300 {
public:
    // O(N log N) "tails" method (binary search)
    int lengthOfLIS_tails(vector<int>& nums);

    // O(N^2) dynamic programming
    int lengthOfLIS_dp(const vector<int>& nums);
};
