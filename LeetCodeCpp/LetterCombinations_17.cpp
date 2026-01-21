#include "LetterCombinations_17.h"
#include <vector>
#include <string>
#include <string_view>

/*
 * LeetCode 17 — Letter Combinations of a Phone Number
 *
 * Problem
 * -------
 * Given digits in the range ['2'..'9'], return all possible letter combinations
 * based on the classic phone keypad mapping. Return the answer in any order.
 *
 * Approach (backtracking over digit→letters)
 * -----------------------------------------
 * - Map each digit to its letters (2→"abc", 3→"def", ..., 9→"wxyz").
 * - DFS by position: at index i, append each letter mapped from digits[i]
 *   to the current `path`, recurse to i+1, and backtrack.
 * - Base case: when i == digits.size(), emit `path`.
 *
 * Edge case:
 * - Empty input string → return empty vector.
 *
 * Complexity
 * ----------
 * Let L be the number of combinations (≤ 4^n where n = digits.length).
 * - Time  : O(L · n)      (build/copy length-n strings L times)
 * - Space : O(n) auxiliary (recursion depth + current path)
 */
void LetterCombinations_17::dfs(const string& digits, int idx,
                                string& path, vector<string>& out) {
    if (idx == static_cast<int>(digits.size())) {
        out.push_back(path);
        return;
    }

    const string_view letters = KEYS[digits[idx] - '0'];

    for (char ch : letters) {
        path.push_back(ch);
        dfs(digits, idx + 1, path, out);
        path.pop_back();
    }
}

vector<string> LetterCombinations_17::letterCombinations(string digits) {
    if (digits.empty()) return {};

    vector<string> out;
    string path;
    path.reserve(digits.size());
    dfs(digits, 0, path, out);

    return out;
}
