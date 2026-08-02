#include "FindPivotIndex_724.h"

using namespace std;

/*
 * Find Pivot Index — Prefix-Sum Scan  — Correctness Sketch
 *
 * total = Σ nums.
 * Traverse with running leftSum.
 *   At index i:
 *       rightSum = total – leftSum – nums[i]
 *       If leftSum == rightSum → i is the first (left-most) pivot, return.
 *       leftSum += nums[i]
 *
 * Complexity
 *   – Time:  O(n)   single pass
 *   – Space: O(1)   two integers
 */
int FindPivotIndex_724::pivotIndex(const vector<int>& nums)
{
    long total = 0;
    for (int v : nums) total += v;

    long left = 0;
    for (int i = 0; i < static_cast<int>(nums.size()); ++i) {
        long right = total - left - nums[i];
        if (left == right) return i;
        left += nums[i];
    }
    return -1;
}
