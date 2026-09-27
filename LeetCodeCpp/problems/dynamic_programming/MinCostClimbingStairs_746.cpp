#include "MinCostClimbingStairs_746.h"
#include <algorithm>

using namespace std;

int MinCostClimbingStairs_746::minCostClimbingStairs(const vector<int>& cost)
{
    const size_t n = cost.size();
    int dp_im2 = 0;
    int dp_im1 = 0;
    for (size_t i = 2; i <= n; ++i) {
        const int cur = min(dp_im1 + cost[i - 1], dp_im2 + cost[i - 2]);
        dp_im2 = dp_im1;
        dp_im1 = cur;
    }
    return dp_im1;
}
