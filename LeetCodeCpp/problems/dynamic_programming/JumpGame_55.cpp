#include "JumpGame_55.h"
#include <algorithm>

using namespace std;

bool JumpGame_55::canJump(vector<int>& nums) {
    int reach = 0;
    const int n = static_cast<int>(nums.size());

    for (int i = 0; i < n; ++i) {
        if (i > reach) return false;
        reach = max(reach, i + nums[i]);
        if (reach >= n - 1) return true;
    }
    return true;
}
