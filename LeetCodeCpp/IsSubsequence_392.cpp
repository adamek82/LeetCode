#include "IsSubsequence_392.h"
#include <algorithm>
#include <cassert>

/* ---------- Build only the position-index once (for method 2) ---------- */
void IsSubsequence_392::preprocess_PosIndex(const string& t) {
    t_ = t;
    for (auto& v : pos_) v.clear();
    for (int i = 0; i < (int)t_.size(); ++i) {
        pos_[t_[i] - 'a'].push_back(i);
    }
    hasPosIndex_ = true;
}

/* ---------- Build only the next-position DP table (for method 3) ---------- */
void IsSubsequence_392::preprocess_NextTable(const string& t) {
    t_ = t;
    const int n = (int)t_.size();
    nextPos_.assign(n + 1, {});      // zero-initialize each row (array<int,26>)
    nextPos_[n].fill(-1);            // sentinel row
    for (int i = n - 1; i >= 0; --i) {
        nextPos_[i] = nextPos_[i + 1];      // copy next row
        nextPos_[i][col(t_[i])] = i;        // set current char position
    }
    hasNextTable_ = true;
}

/* ---------- (1) Two-pointer over provided t (no preprocessing) ---------- */
bool IsSubsequence_392::isSubsequence_TwoPointer(const string& s, const string& t) const {
    int i = 0, j = 0;
    while (i < (int)s.size() && j < (int)t.size()) {
        if (s[i] == t[j]) ++i;
        ++j;
    }
    return i == (int)s.size();
}

/* ---------- (2) Position-index + upper_bound (needs preprocessed pos_) ---------- */
bool IsSubsequence_392::isSubsequence_PosIndex(const string& s) const {
    assert(hasPosIndex_ && "Call preprocess_PosIndex(t) before using this method.");
    int last = -1;
    for (char c : s) {
        const auto& vec = pos_[c - 'a'];
        auto it = upper_bound(vec.begin(), vec.end(), last);
        if (it == vec.end()) return false;
        last = *it;
    }
    return true;
}

/* ---------- (3) Next-position DP table (needs preprocessed nextPos_) ---------- */
bool IsSubsequence_392::isSubsequence_NextTable(const string& s) const {
    assert(hasNextTable_ && "Call preprocess_NextTable(t) before using this method.");
    int i = 0;                              // search start in t_
    for (char c : s) {
        int nxt = nextPos_[i][col(c)];      // row 'n' exists and is all -1
        if (nxt == -1) return false;
        i = nxt + 1;
    }
    return true;
}
