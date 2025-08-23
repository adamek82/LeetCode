#pragma once
#include <string>
using namespace std;

/*
 * Merge Strings Alternately (LeetCode 1768)
 *
 * Build the result by alternating characters from word1 and word2, starting with word1.
 * When one string runs out, append the remaining suffix of the other.
 *
 * Time:  O(n + m)
 * Space: O(1) extra (result buffer of size n+m)
 */
class MergeStringsAlternately_1768 {
public:
    string mergeAlternately(const string& word1, const string& word2);
};
