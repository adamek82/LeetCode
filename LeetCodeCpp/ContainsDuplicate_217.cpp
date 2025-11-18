#include "ContainsDuplicate_217.h"
#include <unordered_set>

/*
 * Contains Duplicate (LeetCode 217)
 *
 * Uses an unordered_set to track which numbers have been seen so far.
 *
 * For each x in nums:
 *   - seen.insert(x) returns a pair { iterator, bool_inserted }.
 *   - The .second field is true if x was not in the set before (inserted now),
 *     and false if x was already present.
 *   - If .second is false, we have found a duplicate and can return true early.
 *
 * The call to seen.reserve(nums.size() * 2) preallocates space for roughly
 * twice as many elements as we expect. This lowers the load factor and helps
 * the hash table avoid frequent rehashing as we insert elements, which gives
 * a small performance boost in the average case.
 *
 * Time complexity:
 *   - Average:  O(n), because each unordered_set insertion/lookup is O(1) on
 *               average and we may insert up to n elements.
 *   - Worst:    O(n^2) in pathological cases with many hash collisions.
 *
 * Space complexity:
 *   - O(n) for storing up to n distinct elements in the unordered_set.
 */
bool ContainsDuplicate_217::containsDuplicate(const vector<int>& nums)
{
    unordered_set<int> seen;
    seen.reserve(nums.size() * 2); // small perf tweak to reduce rehashing
    for (int x : nums) {
        if (!seen.insert(x).second) return true; // already present
    }
    return false;
}
