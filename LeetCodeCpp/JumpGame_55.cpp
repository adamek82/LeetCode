#include "JumpGame_55.h"
#include <algorithm>

/*
 * Greedy: track the farthest reachable index (`reach`). If we encounter
 * an index beyond `reach`, it's unreachable -> return false.
 */
bool JumpGame_55::canJump(vector<int>& nums) {
    int reach = 0;
    const int n = (int)nums.size();
    for (int i = 0; i < n; ++i) {
        if (i > reach) return false;
        reach = max(reach, i + nums[i]);
        if (reach >= n - 1) return true;
    }
    return true; // covers n == 0 (not applicable here) or single-element arrays
}
