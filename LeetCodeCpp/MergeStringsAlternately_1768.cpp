#include "MergeStringsAlternately_1768.h"

/*
 * Merge Strings Alternately (LeetCode 1768) — Two Pointers + Append
 * ---------------------------------------------------------------
 * Method:
 *   Walk through both strings with two indices (i for word1, j for word2).
 *   In each loop iteration, try to take one character from word1 first,
 *   then one character from word2. If one string is already exhausted,
 *   we simply keep taking characters from the other.
 *
 * Efficiency notes:
 *   - out.reserve(n + m) pre-allocates enough space for the final result,
 *     avoiding repeated reallocations as we push characters.
 *   - The loop condition (i < n || j < m) naturally handles different lengths
 *     without extra post-processing.
 */

string MergeStringsAlternately_1768::mergeAlternately(const string& word1, const string& word2)
{
    const int n = static_cast<int>(word1.size());
    const int m = static_cast<int>(word2.size());
    string out;
    out.reserve(n + m);

    int i = 0, j = 0;
    while (i < n || j < m) {
        if (i < n) out.push_back(word1[i++]); // take from word1 first
        if (j < m) out.push_back(word2[j++]); // then from word2
    }
    return out;
}
