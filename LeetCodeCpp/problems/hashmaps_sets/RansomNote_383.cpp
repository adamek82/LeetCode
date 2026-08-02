#include "RansomNote_383.h"
#include <vector>

/*
 * Ransom Note (LeetCode 383)
 *
 * Checks whether ransomNote can be constructed using characters from magazine,
 * where each character in magazine may be used at most once.
 *
 * Steps:
 *   - If ransomNote is longer than magazine, construction is impossible.
 *   - Use a fixed-size array count[26] initialized to 0, assuming only
 *     lowercase English letters 'a'–'z'.
 *   - For each character c in magazine, increment count[c - 'a'] to record
 *     how many copies of that letter we have available.
 *   - For each character c in ransomNote, decrement count[c - 'a']; if any
 *     entry becomes negative, magazine does not have enough of that letter,
 *     so we return false.
 *   - If we finish processing ransomNote without going negative, return true.
 *
 * Time complexity:
 *   - O(m + n), where m = magazine.length() and n = ransomNote.length().
 *
 * Space complexity:
 *   - O(1) extra space: the frequency array has fixed size 26, independent
 *     of the input lengths.
 */

bool RansomNote_383::canConstruct(string ransomNote, string magazine)
{
    if (ransomNote.size() > magazine.size()) return false;

    vector<int> count(26, 0);

    for (char c : magazine) {
        count[c - 'a']++;
    }

    for (char c : ransomNote) {
        int idx = c - 'a';
        count[idx]--;
        if (count[idx] < 0) return false; // not enough of this character
    }

    return true;
}
