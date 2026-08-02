#pragma once
#include <vector>

using namespace std;

/*
 * 706. Design HashMap (LeetCode)
 *
 * Constraints make a direct-address table practical:
 *   - keys are in [0, 1_000_000]
 *   - at most 10^4 operations total
 *
 * We store a vector<int> of size 1_000_001, initialized to -1.
 * Values are in [0, 1_000_000], so -1 is a safe sentinel for "missing".
 *
 * Complexity:
 *   - put/get/remove: O(1)
 *   - space: O(1_000_001) integers (~4 MB)
 */
class MyHashMap {
public:
    MyHashMap();

    void put(int key, int value);
    int  get(int key);
    void remove(int key);

private:
    static constexpr int kMaxKey = 1'000'000;
    static constexpr int kMissing = -1;

    vector<int> values_; // direct-address table
};
