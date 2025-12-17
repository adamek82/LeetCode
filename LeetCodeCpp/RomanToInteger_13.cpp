#include "RomanToInteger_13.h"

// Map a single Roman numeral symbol to its integer value (valid input per problem).
static inline int val(char c) {
    switch (c) {
        case 'I': return 1;
        case 'V': return 5;
        case 'X': return 10;
        case 'L': return 50;
        case 'C': return 100;
        case 'D': return 500;
        case 'M': return 1000;
        default:  return 0; // input is guaranteed valid per problem statement
    }
}

/*
 * Roman to Integer (LeetCode 13) — Right-to-Left Scan (Add/Subtract)
 * -----------------------------------------------------------------
 * Key idea:
 *   Roman numerals are mostly additive (X + V + I), except for the
 *   subtractive pairs where a smaller symbol placed before a larger one
 *   means subtraction (IV = 5 - 1, IX = 10 - 1, etc.).
 *
 * Method:
 *   Traverse the string from right to left while remembering the value of the
 *   symbol we saw just to the right (prev).
 *
 *   For each symbol with value cur:
 *     - If cur < prev, this cur is part of a subtractive pattern, so subtract it.
 *     - Otherwise it contributes normally, so add it.
 *   Then set prev = cur and continue leftward.
 *
 * Why this is “smart”:
 *   Scanning from the right turns the “is this subtractive?” question into a
 *   simple local comparison (cur vs prev), avoiding special-case handling of
 *   specific pairs like "IV", "IX", "XL", "CM", etc.
 *
 * Helper val(c):
 *   Maps each Roman symbol to its numeric value via a switch.
 *   The default case returns 0, but per the typical problem statement the input
 *   is guaranteed to be a valid Roman numeral, so it should never be used.
 */
int RomanToInteger_13::romanToInt(const string& s)
{
    int res = 0;
    int prev = 0; // value of the previous (to the right) symbol

    for (int i = static_cast<int>(s.size()) - 1; i >= 0; --i) {
        int cur = val(s[i]);
        if (cur < prev) res -= cur;  // subtractive case
        else            res += cur;  // additive case
        prev = cur;
    }
    return res;
}
