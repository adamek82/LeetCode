#include "HouseRobber_198.h"
#include <algorithm>

int HouseRobber_198::rob(const vector<int>& nums)
{
    int prev2 = 0;
    int prev1 = 0;
    for (int x : nums) {
        int cur = max(prev1, prev2 + x);
        prev2 = prev1;
        prev1 = cur;
    }
    return prev1;
}
