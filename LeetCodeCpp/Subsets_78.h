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
private:
    static void subsetsDfs(const vector<int>& nums,
                           int start,
                           vector<int>& partial_sol,
                           vector<vector<int>>& out);
public:
    /*
     * Recursive backtracking (DFS include/exclude via forward 'start' index).
     * Emits the current partial subset on entry, then tries adding each nums[i]
     * for i in [start..n-1], recursing with start = i + 1 and backtracking.
     */
    vector<vector<int>> subsets_recursive(vector<int> &nums);

    /*
     * Bitmask power set: for each mask, collect elements with set bits.
     * Complexity: O(n * 2^n) time, O(n) aux (excluding output).
     */
    vector<vector<int>> subsets_bitmask(vector<int>& nums);
};
