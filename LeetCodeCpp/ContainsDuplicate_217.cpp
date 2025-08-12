#include "ContainsDuplicate_217.h"
#include <unordered_set>

bool ContainsDuplicate_217::containsDuplicate(const vector<int>& nums)
{
    unordered_set<int> seen;
    seen.reserve(nums.size() * 2); // small perf tweak to reduce rehashing
    for (int x : nums) {
        if (!seen.insert(x).second) return true; // already present
    }
    return false;
}
