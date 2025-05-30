#include "TwoSumII_167.h"

vector<int> TwoSumII_167::twoSum(vector<int> &numbers, int target)
{
    int l = 0, r = static_cast<int>(numbers.size()) - 1;
    while (l < r) {
        int sum = numbers[l] + numbers[r];
        if (sum == target)        // found the (unique) pair
            return {l + 1, r + 1};   // convert to 1-indexed
        if (sum < target)
            ++l;                   // need a larger sum
        else
            --r;                   // need a smaller sum
    }
    return {};  // unreachable – problem guarantees a solution
}