#pragma once
#include <vector>
using namespace std;

/*
 * Contains Duplicate (LeetCode 217)
 * Approach: scan once, keep a hash-set of seen values. If insert fails -> duplicate found.
 * Time: O(n), Space: O(n). Works for full [-1e9, 1e9] range.
 */
class ContainsDuplicate_217 {
public:
    bool containsDuplicate(const vector<int>& nums);
};
