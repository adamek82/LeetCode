#include "JumpGameII_45.h"
#include <algorithm>

int JumpGameII_45::jump(vector<int>& nums) {
    const int n = (int)nums.size();
    if (n <= 1) return 0;

    int jumps = 0;
    int curEnd = 0;    // farthest index reachable with exactly `jumps` jumps
    int farthest = 0;  // farthest index reachable with `jumps + 1` jumps

    for (int i = 0; i < n - 1; ++i) {
        farthest = max(farthest, i + nums[i]);
        if (i == curEnd) {      // end of current layer -> must "take" a jump
            ++jumps;
            curEnd = farthest;
        }
    }
    return jumps;
}
