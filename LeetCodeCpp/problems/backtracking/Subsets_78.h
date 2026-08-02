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
    /*
     * Keep the DFS helper inside the class: it's an implementation detail
     * of Subsets_78, not a free-floating utility function.
     * It could also be a non-static member (implicit `this`), but that cost
     * is negligible at this recursion depth.
     * We keep it `static` since it doesn't use object state, making the
     * intent explicit and the code cleaner.
     */
    static void subsetsDfs(const vector<int>& nums,
                           int start,
                           vector<int>& partial_sol,
                           vector<vector<int>>& out);

    static void subsetsBinaryDfs(const vector<int>& nums,
                                 int i,
                                 vector<int>& partial_sol,
                                 vector<vector<int>>& out);
public:
    /*
    * Recursive backtracking (DFS over combinations, prefix-based).
    * Emits the current partial subset on entry, then tries adding nums[i]
    * for i in [start..n-1], recursing with start = i + 1 and backtracking.
    */
    vector<vector<int>> subsets_recursive_prefix(vector<int>& nums);

    /*
    * Recursive backtracking (binary "Don't pick / Pick" by index).
    * At each index i we branch into: don't pick nums[i], then pick nums[i].
    */
    vector<vector<int>> subsets_recursive_binary(vector<int>& nums);

    /*
     * Bitmask power set: for each mask, collect elements with set bits.
     * Complexity: O(n * 2^n) time, O(n) aux (excluding output).
     */
    vector<vector<int>> subsets_bitmask(vector<int>& nums);
};
