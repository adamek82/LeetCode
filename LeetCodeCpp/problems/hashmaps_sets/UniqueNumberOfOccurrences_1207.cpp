#include "UniqueNumberOfOccurrences_1207.h"
#include <unordered_map>
#include <unordered_set>

/*
 * 1207. Unique Number of Occurrences
 * ----------------------------------
 * Algorithm:
 *   1) Use an unordered_map<int,int> to count how many times each value
 *      appears in arr.
 *   2) Iterate over the map and insert each frequency into an
 *      unordered_set<int>.
 *   3) If a frequency is already present in the set, we have found two
 *      different values with the same number of occurrences -> return false.
 *   4) If we finish without conflicts, all frequencies are unique -> return true.
 *
 * Complexity:
 *   - Time:  O(n), where n = arr.size(), for counting + set insertion.
 *   - Space: O(n) in the worst case (all values distinct).
 */
bool UniqueNumberOfOccurrences_1207::uniqueOccurrences(vector<int>& arr)
{
    unordered_map<int, int> freq;
    for (int x : arr) {
        ++freq[x];
    }

    unordered_set<int> seen;
    for (const auto& [value, count] : freq) {
        /*
        * unordered_set::insert(value) returns {iterator, inserted}.
        * `inserted` (pair.second) is true only if `count` was NOT in the set yet.
        * So `!seen.insert(count).second` means: this `count` already existed -> duplicate frequency.
        */
        if (!seen.insert(count).second) {
            return false;
        }
    }

    return true;
}
