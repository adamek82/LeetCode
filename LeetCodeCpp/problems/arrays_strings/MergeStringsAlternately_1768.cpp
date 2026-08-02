#include "MergeStringsAlternately_1768.h"

string MergeStringsAlternately_1768::mergeAlternately(const string& word1, const string& word2)
{
    string out;
    out.reserve(word1.size() + word2.size());

    size_t i = 0;
    size_t j = 0;

    while (i < word1.size() || j < word2.size()) {
        if (i < word1.size())
            out.push_back(word1[i++]);

        if (j < word2.size())
            out.push_back(word2[j++]);
    }

    return out;
}
