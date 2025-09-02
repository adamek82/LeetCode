#pragma once
#include <vector>
using namespace std;

/*
 * LeetCode 77 — Combinations
 *
 * Problem
 * -------
 * Given integers n and k, return all combinations of k numbers chosen
 * from the range [1..n]. The order of combinations is not constrained.
 *
 * Approach (backtracking with pruning)
 * -----------------------------------
 * Build combinations in increasing order. Maintain:
 *   - 'start' — the smallest candidate we may still choose,
 *   - 'cur'   — the current partial combination (size <= k).
 * On entry, if cur.size() == k, emit 'cur'.
 * Otherwise, iterate i from 'start' to the largest value that still leaves
 * enough numbers to reach size k (i.e., i <= n - (k - cur.size()) + 1):
 *   - choose i (push_back),
 *   - recurse with start = i + 1,
 *   - backtrack (pop_back).
 *
 * Complexity
 * ----------
 * Time  : O(C(n,k) * k) — we emit C(n,k) combinations, each of length k.
 * Space : O(k) auxiliary — recursion depth equals combination length.
 */
class Combinations_77 {
public:
    vector<vector<int>> combine(int n, int k);

private:
    static void dfsCombine(int n, int k, int start,
                           vector<int>& cur, vector<vector<int>>& out);
};
