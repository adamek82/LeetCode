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
 */

class Subsets_78 {
public:
    /*
     * Recursive backtracking — include/exclude with forward start
     * -----------------------------------------------------------
     * Idea:
     *   Build subsets by exploring choices left-to-right. At each call we have:
     *     - 'start' index from which we may add more elements,
     *     - a 'partial_sol' vector with the elements chosen so far.
     *   We first push the current 'partial_sol' into the output (pre-order), then
     *   iterate i = start..n-1:
     *     - choose nums[i] (push_back),
     *     - recurse with start = i + 1,
     *     - backtrack (pop_back).
     *
     * Why this works:
     *   The 'start' pointer prevents duplicates (we never revisit indices < start).
     *   Each recursion frame contributes exactly one subset (the current prefix),
     *   so we emit 2^n subsets overall.
     *
     * Complexity:
     *   Time  : O(n * 2^n)        — each element participates in half of subsets
     *   Space : O(n) auxiliary     — recursion depth + the current partial subset
     */
    vector<vector<int>> subsets_recursive(vector<int>& nums);

    /*
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
    vector<vector<int>> subsets_bitmask(vector<int>& nums);
};
