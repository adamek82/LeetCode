#pragma once
#include <vector>
using namespace std;

/*
 * LeetCode 78 — Subsets (Power Set)
 *
 * Problem
 * -------
 * Given an array of unique integers `nums`, return all possible subsets.
 * The order of subsets is not constrained by the judge.
 *
 * Approach (bitmask enumeration)
 * ------------------------------
 * For n elements there are 2^n subsets. Iterate mask from 0..(1<<n)-1 and
 * include nums[i] iff the i-th bit of mask is set. This naturally preserves
 * the original element order inside each subset and yields a deterministic
 * subset order overall (by mask).
 *
 * Complexity
 * ----------
 * Time  : O(n * 2^n)
 * Space : O(n) for a single subset being built (O(2^n) in the output)
 */
class Subsets_78 {
public:
    // Returns all subsets of `nums` in any order.
    vector<vector<int>> subsets(vector<int>& nums);
};
