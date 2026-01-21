#include "GenerateParentheses_22.h"

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
void GenerateParentheses_22::dfs(int openLeft, int closeLeft,
                                 string& cur, vector<string>& out) {
    if (openLeft == 0 && closeLeft == 0) {
        out.push_back(cur);
        return;
    }
    if (openLeft > 0) {
        cur.push_back('(');
        dfs(openLeft - 1, closeLeft, cur, out);
        cur.pop_back();
    }
    if (closeLeft > openLeft) { // only close if we have more ')' remaining than '('
        cur.push_back(')');
        dfs(openLeft, closeLeft - 1, cur, out);
        cur.pop_back();
    }
}

vector<string> GenerateParentheses_22::generateParenthesis(int n) {
    vector<string> out;
    string cur;
    cur.reserve(n * 2);
    dfs(n, n, cur, out);
    return out;
}
