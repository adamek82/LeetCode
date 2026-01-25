#include "TwoSum_1.h"
#include <unordered_map>

/*
 * Two-Sum — One-Pass Hash Map  — Correctness Sketch
 *
 * Invariant (complement tracking):
 *   • After scanning the first i elements, `seen` maps each value v ∈ nums[0..i-1]
 *     to its index.  For the current value x = nums[i] we look for y = target-x.
 *
 * Why it works
 *   – If y is already in `seen`, (seen[y], i) is the unique solution guaranteed
 *     by the problem; we can return immediately.
 *   – Otherwise we store x → i and continue.  Duplicates are handled because we
 *     always *query* before *inserting*.
 *
 * Complexity
 *   – Time:  O(n)    — one hash lookup per element.
 *   – Space: O(n)    — up to n-1 stored complements.
 */
vector<int> TwoSum_1::twoSum(const vector<int>& nums, int target)
{
    unordered_map<int,int> seen;          // value → index
    for (int i = 0; i < static_cast<int>(nums.size()); ++i) {
        int need = target - nums[i];
        auto it = seen.find(need);
        if (it != seen.end())
            return {it->second, i};
        seen[nums[i]] = i;
    }
    return {}; // should never hit — problem guarantees one answer
}
