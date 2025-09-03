#pragma once
#include <vector>
using namespace std;

/*
 * LeetCode 39 — Combination Sum
 *
 * Problem
 * -------
 * Given distinct integers `candidates` and an integer `target`, return all
 * unique combinations where chosen numbers sum to `target`. You may reuse
 * each candidate unlimited times. Order of combinations is not constrained.
 *
 * Approach (backtracking with sorting + pruning)
 * ----------------------------------------------
 * - Sort `candidates` ascending to enable pruning and to build combinations
 *   in non-decreasing order (which avoids permutation duplicates like [2,3]
 *   vs [3,2]).
 * - DFS state: (start, remain, cur).
 *   * Iterate i from `start` .. end while candidates[i] <= remain.
 *   * Choose candidates[i], recurse with same i (unlimited reuse), and
 *     `remain - candidates[i]`. Backtrack afterward.
 *   * If remain becomes 0, emit current combination.
 * - Prune early: since sorted, if candidates[i] > remain, break the loop.
 *
 * Correctness
 * -----------
 * - No duplicates: combinations are generated in non-decreasing order and
 *   we never revisit earlier indices (< start), so permutations are not
 *   produced.
 * - Completeness: for each prefix we try every feasible candidate at/after
 *   `start` and continue while sum ≤ target; all solutions are explored.
 *
 * Complexity
 * ----------
 * Let S be the number of returned combinations (< 150 per constraints).
 * - Time  : O(S * k) to copy k-length combinations, plus backtracking overhead.
 * - Space : O(k) auxiliary for recursion stack and current path.
 */
class CombinationSum_39 {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target);

private:
    static void dfs(int start, int remain, const vector<int>& cand,
                    vector<int>& cur, vector<vector<int>>& out);
};
