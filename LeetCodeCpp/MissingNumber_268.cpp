#include <numeric>
#include "MissingNumber_268.h"

int MissingNumber_268::missingNumber(vector<int> &nums)
{
    long long n = nums.size();                           // make sure the formula runs in 64-bit
    long long expectedSum = n * (n + 1) / 2;             // sum of 0..n computed in 64-bit to avoid overflow
    long long actualSum = accumulate(nums.begin(), nums.end(), 0LL); // 0LL -> accumulate in 64-bit
    return static_cast<int>(expectedSum - actualSum);    // the difference fits in int by problem constraints
}