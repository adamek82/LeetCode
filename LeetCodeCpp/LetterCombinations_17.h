#pragma once
#include <vector>
#include <string>
#include <array>
#include <string_view>
using namespace std;

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
class LetterCombinations_17 {
public:
    vector<string> letterCombinations(string digits);

private:
    // Keypad mapping indexed by digit - '0' (0/1 map to empty).
    // `inline` + `constexpr` keeps this a single definition across TUs (C++17+).
    inline static constexpr array<string_view, 10> KEYS{
        "", "", "abc", "def", "ghi",
        "jkl", "mno", "pqrs", "tuv", "wxyz"
    };

    static void dfs(const string& digits, int idx,
                    string& path, vector<string>& out);
};
