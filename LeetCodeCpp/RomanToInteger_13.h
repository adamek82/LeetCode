#pragma once
#include <string>
using namespace std;

/*
 * Roman to Integer (LeetCode 13)
 *
 * Algorithm:
 * - Scan from right to left using the standard subtractive rule.
 * - Let val(c) map each Roman char to its integer value.
 * - Keep `prev = 0`. For each char c from the end:
 *     cur = val(c);
 *     if (cur < prev) res -= cur; else res += cur;
 *     prev = cur;
 *   This handles pairs like IV, IX, XL, XC, CD, CM naturally.
 *
 * Complexity:
 * - Time:  O(n)
 * - Space: O(1)
 */
class RomanToInteger_13 {
public:
    int romanToInt(const string& s);
};
