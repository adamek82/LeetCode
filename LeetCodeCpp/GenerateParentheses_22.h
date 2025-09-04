#pragma once
#include <vector>
#include <string>
using namespace std;

/*
 * LeetCode 22 — Generate Parentheses
 *
 * Problem
 * -------
 * Given n pairs of parentheses, generate all combinations that form
 * valid parentheses strings. Return the combinations in any order.
 *
 * Approach (backtracking with remaining counts)
 * --------------------------------------------
 * Maintain:
 *   - openLeft  : how many '(' we may still place,
 *   - closeLeft : how many ')' we may still place.
 * Invariant: we can only place ')' if closeLeft > openLeft — otherwise
 * we'd close more than we've opened, producing an invalid prefix.
 *
 * Recurrence:
 *   - If openLeft > 0: place '(', recurse with openLeft - 1.
 *   - If closeLeft > openLeft: place ')', recurse with closeLeft - 1.
 * Base case: when openLeft == 0 and closeLeft == 0, emit the built string.
 *
 * Complexity
 * ----------
 * Let C_n be the nth Catalan number (number of valid strings).
 * - Time  : O(C_n * n) to construct/copy each length-n*2 string once.
 * - Space : O(n) auxiliary for recursion depth and current string.
 */
class GenerateParentheses_22 {
public:
    vector<string> generateParenthesis(int n);

private:
    static void dfs(int openLeft, int closeLeft,
                    string& cur, vector<string>& out);
};
