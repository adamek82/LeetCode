#include "JumpGame_55.h"
#include <algorithm>

/*
 * Jump Game (LeetCode 55) — Greedy reachability
 * --------------------------------------------
 * Idea:
 *   Scan left → right and maintain `reach` = the farthest index we can reach
 *   using jumps from any position we've been able to stand on so far.
 *
 * Invariant:
 *   Before processing index i, all indices <= reach are reachable.
 *   If we ever see i > reach, then i (and everything after it) is unreachable
 *   because the best we could do from all earlier reachable positions still
 *   doesn't get us to i.
 *
 * Update step:
 *   If i is reachable, then from i we can jump up to i + nums[i].
 *   So we try to improve the farthest reachable point:
 *
 *     reach = max(reach, i + nums[i])
 *
 * Early exit:
 *   As soon as reach >= n - 1, the last index is reachable -> return true.
 *
 * Quick examples:
 *   [2,3,1,1,4]
 *     i=0 reachable, reach=max(0,0+2)=2
 *     i=1 reachable, reach=max(2,1+3)=4 -> reach >= last -> true
 *
 *   [3,2,1,0,4]
 *     i=0 reach=3, i=1 reach=3, i=2 reach=3, i=3 reach=3 (nums[3]=0 blocks)
 *     i=4 but 4 > reach(3) -> false
 *
 * Complexity:
 *   Time:  O(n)
 *   Space: O(1)
 */
bool JumpGame_55::canJump(vector<int>& nums) {
    int reach = 0;
    const int n = static_cast<int>(nums.size());
    for (int i = 0; i < n; ++i) {
        if (i > reach) return false;
        reach = max(reach, i + nums[i]);
        if (reach >= n - 1) return true;
    }
    return true; // covers n == 0 (not applicable here) or single-element arrays
}
