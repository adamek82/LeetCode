#include "FindClosestNumberToZero_2239.h"
#include <cstdlib>   // llabs
#include <climits>

int FindClosestNumberToZero_2239::findClosestNumber(const vector<int>& nums)
{
    int best = nums[0];
    long long bestd = llabs(static_cast<long long>(best));

    for (size_t i = 1; i < nums.size(); ++i) {
        int x = nums[i];
        long long d = llabs(static_cast<long long>(x));
        if (d < bestd || (d == bestd && x > best)) {
            bestd = d;
            best  = x;
        }
    }
    return best;
}
