#include "MergeStringsAlternately_1768.h"

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
