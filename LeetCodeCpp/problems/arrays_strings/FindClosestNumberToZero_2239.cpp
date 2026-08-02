#include "FindClosestNumberToZero_2239.h"
#include <cstdlib>

int FindClosestNumberToZero_2239::findClosestNumber(const vector<int>& nums)
{
    int best = nums[0];

    for (int x : nums) {
        if (abs(x) < abs(best) || (abs(x) == abs(best) && x > best))
            best = x;
    }

    return best;
}
