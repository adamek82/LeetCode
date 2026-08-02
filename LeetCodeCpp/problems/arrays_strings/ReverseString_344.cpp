#include "ReverseString_344.h"
#include <utility>  // for std::swap

/*
 * Reverse String (LeetCode 344)
 *
 * Reverses the input character array in-place.
 *
 * Idea:
 *   - Use two pointers: one at the beginning (l) and one at the end (r).
 *   - Swap the characters at l and r, then move l forward and r backward.
 *   - Stop when the pointers meet or cross (l >= r).
 *
 * Steps:
 *   - Initialize l = 0, r = static_cast<int>(s.size()) - 1.
 *   - While l < r:
 *       - swap(s[l], s[r]);
 *       - ++l, --r;
 *
 * Note on static_cast<int>:
 *   - s.size() returns size_t (an unsigned type). Converting it to int
 *     avoids mixing signed/unsigned types in comparisons and arithmetic
 *     (like r-- or l < r), and prevents potential underflow issues.
 *
 * Complexity:
 *   - Time:  O(n) — each character is visited at most once.
 *   - Space: O(1) — in-place, uses only a few extra variables.
 */
void ReverseString_344::reverseString(vector<char> &s)
{
    int l = 0, r = static_cast<int>(s.size()) - 1;
    while (l < r) {
        swap(s[l++], s[r--]);
    }
}
