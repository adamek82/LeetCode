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
    for (int i = 0; i < static_cast<int>(t_.size()); ++i) {
        pos_[t_[i] - 'a'].push_back(i);
    }
    hasPosIndex_ = true;
}

/*
 * Build only the next-position DP table (for method 3)
 * ----------------------------------------------------
 * Store t_ and build a (n+1) x 26 table nextPos_, where:
 *   nextPos_[i][c] = the earliest index j >= i with t_[j] == c, or -1 if none.
 *
 * Construction goes right-to-left:
 *   - nextPos_[n] is a sentinel row filled with -1 ("past the end of t").
 *   - For each i from n-1 down to 0:
 *       copy nextPos_[i+1] (knowledge about the suffix),
 *       then set the entry for t_[i] to i.
 *
 * This preprocessing enables O(|s|) subsequence queries with constant-time
 * transitions per character. Refer to the method (3) comment below
 * isSubsequence_NextTable(...) for the full intuition, examples, and complexity.
 */
void IsSubsequence_392::preprocess_NextTable(const string& t) {
    t_ = t;
    const int n = static_cast<int>(t_.size());
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
    while (i < static_cast<int>(s.size()) && j < static_cast<int>(t.size())) {
        if (s[i] == t[j]) ++i;
        ++j;
    }
    return i == static_cast<int>(s.size());
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

/*
 * (3) Next-position DP table (many queries, small alphabet)
 * ---------------------------------------------------------
 * Goal:
 *   Answer many "is s a subsequence of fixed t?" queries fast.
 *
 * Data structure:
 *   nextPos_[i][c] tells you the earliest index j >= i such that t_[j] == c,
 *   or -1 if character c does not appear at/after position i.
 *
 *   - Rows: i = 0..n, where n = |t|.
 *   - Cols: c = 0..25 for 'a'..'z' (via col(c) = c - 'a').
 *
 * Why n+1 rows:
 *   Row n is a sentinel state meaning "we are past the end of t".
 *   From there, no character can be matched, so nextPos_[n][*] = -1.
 *   This avoids boundary checks both during preprocessing and querying.
 *
 * Preprocessing (build nextPos_):
 *   nextPos_.assign(n + 1, {}) creates a vector of (n+1) rows, each row being
 *   an array<int,26> value-initialized (i.e., filled with zeros).
 *   Then we explicitly set the sentinel row to -1:
 *       nextPos_[n].fill(-1);
 *
 *   We fill rows from right to left:
 *       for i = n-1 down to 0:
 *           nextPos_[i] = nextPos_[i+1];          // copy "future" knowledge
 *           nextPos_[i][col(t_[i])] = i;          // current char is available at i
 *
 *   Intuition for building from the end:
 *     Row i answers "what is the next occurrence at/after i?", which depends on
 *     the suffix t[i..]. The suffix information is already known at row i+1
 *     (for t[i+1..]), so we can reuse it by copying the row and then patching
 *     one entry for t[i]. If we built left-to-right, we'd need information from
 *     the future (unknown yet) to fill nextPos_[i][*], so we'd either need extra
 *     passes or more complex bookkeeping.
 *
 * Example:
 *   t = "abac" (n=4)
 *   Indices: 0 1 2 3
 *            a b a c
 *
 *   Sentinel row i=4: next(a)=next(b)=next(c)=-1
 *
 *   i=3 ('c'): copy row 4, set c->3  => a:-1 b:-1 c:3
 *   i=2 ('a'): copy row 3, set a->2  => a:2  b:-1 c:3
 *   i=1 ('b'): copy row 2, set b->1  => a:2  b:1  c:3
 *   i=0 ('a'): copy row 1, set a->0  => a:0  b:1  c:3
 *
 * Querying with nextPos_:
 *   Maintain a pointer i = "the earliest position in t_ we are allowed to use next".
 *   Start i = 0. For each character c in s:
 *     nxt = nextPos_[i][col(c)]
 *     if nxt == -1 -> cannot match c after position i, return false
 *     else set i = nxt + 1 and continue (must match subsequent chars strictly after nxt)
 *
 *   Example query:
 *     t = "abac"
 *     s = "bac"
 *       i=0: 'b' -> nextPos_[0]['b']=1, i=2
 *       i=2: 'a' -> nextPos_[2]['a']=2, i=3
 *       i=3: 'c' -> nextPos_[3]['c']=3, i=4
 *       all matched -> true
 *
 * Complexity:
 *   Preprocess time:
 *     O(n * 26) because each row copy touches 26 ints (constant alphabet size).
 *   Preprocess space:
 *     O((n + 1) * 26) ints for the table.
 *   Query time:
 *     O(|s|) (each character is one table lookup + constant work).
 *
 * Notes:
 *   - This method is ideal when t is fixed and you have many queries,
 *     and the alphabet is small (here: lowercase English letters).
 *   - The sentinel row makes both preprocessing and querying cleaner:
 *     i can become n, and nextPos_[n][*] is still a valid lookup returning -1.
 */
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
