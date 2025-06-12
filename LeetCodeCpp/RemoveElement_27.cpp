#include "RemoveElement_27.h"

/*
 * Remove Element — Forward Write Pointer  — Correctness Sketch
 *
 * Let i be the position we next write a “kept” value, and j iterate over
 * every original element.
 *
 * Invariant
 *   • All indices < i hold elements ≠ val (final positions).
 *   • Indices ≥ j have not been examined yet.
 *
 * Step
 *   if nums[j] ≠ val → copy to nums[i++].
 *   else             → skip.
 *
 * After one pass i == k, the count of kept elements, and the first k slots
 * contain exactly those elements (order preserved but not required).
 *
 * Complexity
 *   – Time:  O(n)  (single scan)
 *   – Space: O(1)  (constant counters)
 */
int RemoveElement_27::removeElement(vector<int>& nums, int val)
{
    int i = 0;

    for (int j = 0; j < static_cast<int>(nums.size()); ++j)
        if (nums[j] != val)
            nums[i++] = nums[j];

    return i;
}