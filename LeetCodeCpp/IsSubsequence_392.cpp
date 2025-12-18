#include "IsSubsequence_392.h"
#include <algorithm>
#include <cassert>

/*
 * Build only the position-index once (for method 2)
 * -------------------------------------------------
 * Store t_ and build, for each letter 'a'..'z', a sorted vector of all indices
 * where that letter appears in t_. We fill these vectors by a single left-to-right
 * scan of t_, pushing indices in increasing order (so they end up sorted naturally).
 *
 * This preprocessing enables fast subsequence queries via binary search
 * (upper_bound) on these per-character index lists.
 */
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

/*
 * (2) Position-index + upper_bound (many queries over a fixed t)
 * --------------------------------------------------------------
 * Idea:
 *   Preprocess t into pos_[ch] = sorted list of indices where character ch occurs.
 *   Then each query string s is checked by greedily matching its characters from
 *   left to right, always choosing the earliest occurrence in t that is strictly
 *   to the right of the previously matched position.
 *
 * How it works:
 *   last = index of the most recently matched character in t (starts at -1).
 *   For each c in s:
 *     - Look up vec = pos_[c].
 *     - Find the first position in vec that is > last (upper_bound).
 *       If none exists, s cannot be a subsequence of t.
 *     - Update last to that position and continue.
 *
 * Why upper_bound:
 *   We need the next occurrence strictly after 'last' to preserve order.
 *
 * Complexity:
 *   Preprocess: O(|t|) time, O(|t|) memory.
 *
 *   Query (more precise):
 *     Sum over characters of s:
 *       Σ O(log occ(s[k]))
 *     where occ(x) is the number of occurrences of character x in t
 *     (i.e., size of pos_[x]).
 *
 *   Query (convenient upper bound):
 *     Let occ_max = max_c occ(c). Then every lookup costs at most O(log occ_max),
 *     so the whole query is O(|s| log occ_max). This avoids writing the sum,
 *     and since occ_max ≤ |t|, the worst-case bound is O(|s| log |t|).
 */
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
