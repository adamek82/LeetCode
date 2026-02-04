#pragma once
#include <vector>

using namespace std;

class LongestIncreasingSubsequence_300 {
public:
    // O(N log N) "tails" method (binary search)
    int lengthOfLIS_tails(vector<int>& nums);

    // O(N^2) dynamic programming
    int lengthOfLIS_dp(const vector<int>& nums);

    // O(N log N) tails + parent pointers (reconstruct one actual LIS)
    vector<int> getLIS_tails(const vector<int>& nums);
};
