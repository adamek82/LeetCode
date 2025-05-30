// LeetCodeCpp/ContainerWithMostWater_11.cpp
#include "ContainerWithMostWater_11.h"

/*
 * Approach — two-pointer (shrinking window)
 * ----------------------------------------
 * 1. Start with the widest possible container: l = 0, r = n-1.
 * 2. Current area = min(height[l], height[r]) * (r - l).
 * 3. The *shorter* side limits the area.
 *    – Moving the taller side inward always makes the width smaller while
 *      its height cannot increase, so the area cannot improve.
 *    – Therefore advance the shorter side, hoping to meet a taller bar
 *      that compensates for the lost width.
 * 4. Repeat until the pointers meet, tracking the maximum area seen.
 *
 * Correctness
 * -----------
 * Any optimal pair (i, j) with i < j is examined exactly once:
 * • either when l = i, r = j,  
 * • or it is dominated by a pair that used an equal-or-taller bar on the
 *   same side with a wider interval (already considered earlier).
 * Thus the optimum is never skipped.
 *
 * Complexity
 * ----------
 * Time  : O(n) — each pointer moves at most n-1 steps.  
 * Space : O(1) — only a few integers stored.
 */
int ContainerWithMostWater_11::maxArea(vector<int>& height)
{
    int l = 0, r = static_cast<int>(height.size()) - 1;
    long long best = 0;
    while (l < r) {
        long long h = min(height[l], height[r]);
        best = max(best, h * (r - l));
        if (height[l] < height[r])
            ++l;
        else
            --r;
    }
    return static_cast<int>(best);
}
