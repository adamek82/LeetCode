#include "TrappingRainWater_42.h"
#include <algorithm>

/*
 * Approach — two-pointer with running maxima
 * -----------------------------------------
 * Idea: at any index i the water level equals
 *   min(maxLeft(i), maxRight(i)) − height[i]
 * where maxLeft/maxRight are the tallest bars to the left / right.
 *
 * Classic pre-compute arrays require O(n) space.  We can do better:
 *
 * • Place two pointers at the ends:  l = 0, r = n-1.
 * • Maintain current maxima seen so far while shrinking the window:
 *     leftMax  = max(height[0..l])
 *     rightMax = max(height[r..n-1])
 * • The lower side is the bottleneck that determines the water level.
 *   – If leftMax ≤ rightMax, the trapped water above height[l] is
 *       leftMax − height[l]  (never negative)
 *     then advance l and update leftMax.
 *   – Otherwise use the symmetrical logic for the right side.
 * • Each index is processed exactly once ⇒ total O(n) time, O(1) space.
 *
 * Correctness sketch
 * ------------------
 * When leftMax ≤ rightMax, every bar between l and r is bounded on the
 * left by leftMax and on the right by **at least** rightMax ≥ leftMax.
 * Therefore the water level at l depends solely on leftMax; moving r
 * cannot raise it.  Analogous reasoning holds when right side is lower.
 *
 * Complexity
 * ----------
 * Time  : O(n) — linear single pass.
 * Space : O(1) — only a few scalar variables.
 */
int TrappingRainWater_42::trap(vector<int>& height)
{
    int n = static_cast<int>(height.size());
    if (n < 3) return 0;

    int l = 0, r = n - 1;
    int leftMax = 0, rightMax = 0;
    long long water = 0;

    while (l < r) {
        if (height[l] <= height[r]) {
            leftMax = max(leftMax, height[l]);
            water  += leftMax - height[l];
            ++l;
        } else {
            rightMax = max(rightMax, height[r]);
            water   += rightMax - height[r];
            --r;
        }
    }
    return static_cast<int>(water);
}
