#include "LongestSubstringWithoutRepeatingCharacters_3.h"
#include <vector>
#include <algorithm>

/*
 * Longest Substring Without Repeating Characters (LeetCode 3)
 *
 * Idea
 * ----
 * Use a sliding window [i..j] that always contains no duplicate characters.
 * As we extend the window with `j`, we track the last index where each character
 * was seen. If the new character `s[j]` was already seen inside the current
 * window, we "jump" the left pointer `i` just past that previous occurrence.
 *
 * Key detail
 * ----------
 * `last[c]` stores the most recent index of character c.
 * When processing position j:
 *   - if last[c] >= i, then c repeats within the current window [i..j-1],
 *     so we set i = last[c] + 1 to restore uniqueness.
 *   - update last[c] = j and compute window length (j - i + 1).
 *
 * Why it works
 * ------------
 * `i` never moves left, only right. Each position is processed once by `j`,
 * and `i` advances at most n times overall. The jump (i = last[c] + 1) avoids
 * shrinking one step at a time, so the total work is linear.
 *
 * Practical notes
 * ---------------
 * - Use `unsigned char` for indexing: plain `char` may be signed, and values
 *   with the high bit set could become negative, causing out-of-bounds access.
 * - The 256-sized table assumes an 8-bit character domain (ASCII/extended byte).
 *   If the input is full Unicode, this table is not sufficient; you'd track last
 *   occurrences in a hash map keyed by code point (still O(n) expected time, but
 *   no longer strictly O(1) extra space).
 *
 * Complexity
 * ----------
 * Time:  O(n)
 * Space: O(1) for fixed 256 alphabet; otherwise O(min(n, alphabet)).
 */
int LongestSubstringWithoutRepeatingCharacters_3::lengthOfLongestSubstring(const string &s)
{
    int n = static_cast<int>(s.size());
    // last occurrence of each ASCII char; initialized to -1
    vector<int> last(256, -1);
    int best = 0;
    // window is s[i..j-1]
    for (int i = 0, j = 0; j < n; ++j) {
        unsigned char c = s[j];
        // if we've seen c inside the current window [i..j-1], move i
        if (last[c] >= i) {
            i = last[c] + 1;
        }
        // record/update last position of c
        last[c] = j;
        // update best length
        best = max(best, j - i + 1);
    }
    return best;
}
