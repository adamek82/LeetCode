#pragma once
#include <vector>
using namespace std;

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
class Permutations_46 {
public:
    vector<vector<int>> permute(vector<int>& nums);

private:
    // Backtracking driver: fixes prefix [0..pos-1], permutes suffix [pos..n-1].
    static void dfsPerm(int pos, vector<int>& nums, vector<vector<int>>& out);
};
