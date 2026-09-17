#include "JumpGameII_45.h"
#include <algorithm>

int JumpGameII_45::jump(vector<int>& nums)
{
    const int n = static_cast<int>(nums.size());
    if (n <= 1) return 0;

    int jumps = 0;
    int layerEnd = 0;
    int nextLayerEnd = 0;

    for (int i = 0; i < n - 1; ++i) {
        nextLayerEnd = max(nextLayerEnd, i + nums[i]);
        if (i == layerEnd) {
            ++jumps;
            layerEnd = nextLayerEnd;
        }
    }
    return jumps;
}
