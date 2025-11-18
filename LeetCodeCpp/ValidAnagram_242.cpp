#include "ValidAnagram_242.h"
#include <string>
#include <vector>

/*
 * Valid Anagram (LeetCode 242)
 *
 * Checks if two strings are anagrams by counting character frequencies.
 *
 * Steps:
 *   - If s and t have different lengths, they cannot be anagrams.
 *   - Use a fixed-size array count[26] initialized to 0, assuming only
 *     lowercase English letters 'a'–'z'.
 *   - For each character in s, increment count[c - 'a'].
 *   - For each character in t, decrement count[c - 'a'].
 *   - If s and t contain exactly the same multiset of letters, every entry
 *     in count will return to 0. If any entry is non-zero, the strings differ.
 *
 * Time complexity:
 *   - O(n), where n is the length of the strings (single pass over s and t,
 *     plus a constant 26-step check of the count array).
 *
 * Space complexity:
 *   - O(1) extra space: the count vector has fixed size 26, independent of n.
 */

bool ValidAnagram_242::isAnagram(string s, string t)
{
    if (s.length() != t.length()) return false;

    vector<int> count(26, 0);
    for (char c : s) count[c - 'a']++;
    for (char c : t) count[c - 'a']--;

    for (int freq : count) {
        if (freq != 0) return false;
    }
    return true;
}