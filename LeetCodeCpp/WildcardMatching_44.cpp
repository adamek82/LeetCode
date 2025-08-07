#include "WildcardMatching_44.h"

/**
 * LeetCode #44 – Wildcard Matching
 *
 * Greedy O(m + n) algorithm explained step-by-step:
 *
 *  i  –  current position in s
 *  j  –  current position in p
 *  starIdx   –  position of the most recent '*' in p  (-1 if none seen so far)
 *  matchIdx  –  position in s that the above '*' is currently “covering”
 *
 * 1. Walk through s and p simultaneously.
 * 2. Case-by-case:
 *      a) Characters match exactly OR pattern has '?'  ->  consume both.
 *      b) Pattern shows '*'                            ->  remember where it is,
 *                                                          pretend it matches empty for now,
 *                                                          and move j past '*'.
 *      c) Mismatch but we HAVE seen a previous '*'     ->  back-track:
 *                                                          • reset j to char AFTER that '*'
 *                                                          • extend the span matched by '*'
 *                                                            by one more char of s
 *                                                          • continue scanning
 *      d) Mismatch and NO previous '*'                 ->  impossible => return false.
 * 3. When s is exhausted, the remainder of p must be only '*' characters.
 *    If so, every char of p can match an empty suffix and we succeed.
 *
 * This visits each index of s and p at most once (apart from
 * the controlled rewinds in step 2c), yielding O(m + n) time
 * and O(1) extra memory.
 */
bool WildcardMatching_44::isMatch(string s, string p)
{
    int m = s.size(), n = p.size();
    int i = 0, j = 0;        // cursors in s and p
    int starIdx = -1;        // last position of '*' in p
    int matchIdx = -1;       // position in s that the last '*' covers

    while (i < m) {
        // Case 2a: exact match or '?'
        if (j < n && (p[j] == '?' || p[j] == s[i])) {
            ++i;
            ++j;
        }
        // Case 2b: new '*'
        else if (j < n && p[j] == '*') {
            starIdx = j;     // remember where '*'
            matchIdx = i;    // '*' currently matches empty string
            ++j;             // move past '*'
        }
        // Case 2c: mismatch – backtrack to last '*'
        else if (starIdx != -1) {
            j = starIdx + 1; // reset pattern to char after '*'
            ++matchIdx;      // let '*' absorb one more char
            i = matchIdx;    // retry matching from here
        }
        // Case 2d: mismatch with no '*'
        else {
            return false;
        }
    }

    // Step 3: the rest of p must be all '*'
    while (j < n && p[j] == '*') ++j;
    return j == n;
}