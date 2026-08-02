#include "Permutations_46.h"
#include <utility>  // IWYU: std::swap (don't rely on MSVC transitive includes)

/*
 * LeetCode 46 — Permutations
 *
 * Problem
 * -------
 * Given an array of distinct integers `nums`, return all possible permutations.
 * The answer can be returned in any order.
 *
 * Approach (in-place backtracking with swaps)
 * ------------------------------------------
 * We generate permutations by fixing the prefix one position at a time.
 * At recursion depth `pos`, we choose which element should occupy `nums[pos]`
 * by swapping each candidate from positions `pos..n-1` into `pos`, recurse
 * to `pos+1`, and then swap back (backtrack).
 *
 * Correctness
 * -----------
 * Each recursion level places exactly one element at the next position.
 * Because all inputs are distinct and we explore every choice for each
 * position, we enumerate all n! permutations exactly once.
 *
 * Complexity
 * ----------
 * Time  : O(n · n!) — there are n! permutations; copying each length-n
 *         permutation into the output costs O(n).
 * Space : O(n) auxiliary for recursion depth; the swaps are in-place.
 */
void Permutations_46::dfsPerm(int pos, vector<int>& nums, vector<vector<int>>& out) {
    const int n = static_cast<int>(nums.size());
    if (pos == n) {
        out.push_back(nums);   // record one full permutation
        return;
    }
    for (int i = pos; i < n; ++i) {
        swap(nums[pos], nums[i]);       // choose nums[i] for position 'pos'
        dfsPerm(pos + 1, nums, out);    // recurse
        swap(nums[pos], nums[i]);       // backtrack
    }
}

vector<vector<int>> Permutations_46::permute(vector<int>& nums) {
    vector<vector<int>> out;
    dfsPerm(0, nums, out);
    return out;
}
