#pragma once
#include <string>
#include <array>
#include <vector>
using namespace std;

/*
 * Is Subsequence (LeetCode 392)
 *
 * One class, three query methods:
 *
 * (1) Two-pointer (single query; no preprocessing):
 *     bool isSubsequence_TwoPointer(const string& s, const string& t) const;
 *     Scan t while advancing in s on matches. Time O(|t|), Space O(1).
 *
 * (2) Position-index + upper_bound (many queries over a fixed t):
 *     Call preprocess_PosIndex(t) once. Query: O(|s| log occ), Space: O(|t|).
 *
 * (3) Next-position DP table (many queries, small alphabet):
 *     Call preprocess_NextTable(t) once. Query O(|s|), Space O(|t| * 26).
 */
class IsSubsequence_392 {
public:
    IsSubsequence_392() = default;                 // no preprocessing by default

    // Build only the position-index structure (for method 2)
    void preprocess_PosIndex(const string& t);

    // Build only the next-position DP table (for method 3)
    void preprocess_NextTable(const string& t);

    // (1) Two-pointer over provided t (no member state needed)
    bool isSubsequence_TwoPointer(const string& s, const string& t) const;

    // (2) Using position lists + upper_bound over preprocessed t_
    bool isSubsequence_PosIndex(const string& s) const;

    // (3) Using next-position DP table over preprocessed t_
    bool isSubsequence_NextTable(const string& s) const;

private:
    static inline int col(char c) { return c - 'a'; }

    string t_;                                // stored text for follow-ups
    array<vector<int>, 26> pos_;              // indices per char (method 2)
    vector<array<int, 26>> nextPos_;          // DP table (method 3)

    bool hasPosIndex_  = false;
    bool hasNextTable_ = false;
};
