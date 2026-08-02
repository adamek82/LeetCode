#pragma once
#include <string>
#include <array>
#include <vector>
using namespace std;

class IsSubsequence_392 {
public:
    IsSubsequence_392() = default;

    void preprocess_PosIndex(const string& t);
    void preprocess_NextTable(const string& t);

    bool isSubsequence_TwoPointer(const string& s, const string& t) const;
    bool isSubsequence_PosIndex(const string& s) const;
    bool isSubsequence_NextTable(const string& s) const;

private:
    static inline int col(char c) { return c - 'a'; }

    string t_;
    array<vector<size_t>, 26> pos_;
    vector<array<size_t, 26>> nextPos_;

    bool hasPosIndex_  = false;
    bool hasNextTable_ = false;
};
