#include "Subsets_78.h"

/*
 * Bitmask power set: for each mask, collect elements with set bits.
 * Complexity: O(n * 2^n) time, O(n) aux (excluding output).
 */
vector<vector<int>> Subsets_78::subsets_bitmask(vector<int>& nums) {
    const int n = static_cast<int>(nums.size());
    const int total = 1 << n;

    vector<vector<int>> out;
    out.reserve(total);

    for (int mask = 0; mask < total; ++mask) {
        vector<int> cur;
        cur.reserve(n);
        for (int i = 0; i < n; ++i) {
            if (mask & (1 << i)) cur.push_back(nums[i]);
        }
        out.push_back(move(cur));
    }
    return out;
}

/*
 * Recursive backtracking (DFS include/exclude via forward 'start' index).
 * Emits the current partial subset on entry, then tries adding each nums[i]
 * for i in [start..n-1], recursing with start = i + 1 and backtracking.
 */
static void subsetsDfs(const vector<int>& nums,
                       int start,
                       vector<int>& partial_sol,
                       vector<vector<int>>& out)
{
    out.push_back(partial_sol);         // record the current subset

    for (int i = start; i < static_cast<int>(nums.size()); ++i) {
        partial_sol.push_back(nums[i]); // choose
        subsetsDfs(nums, i + 1, partial_sol, out);
        partial_sol.pop_back();         // backtrack
    }
}

vector<vector<int>> Subsets_78::subsets_recursive(vector<int>& nums) {
    vector<vector<int>> out;
    vector<int> partial_sol;
    partial_sol.reserve(nums.size());
    subsetsDfs(nums, 0, partial_sol, out);
    return out;
}
