#include "LongestCommonPrefix_14.h"
#include <algorithm>

/*
 * Longest Common Prefix — linear LCP shrink
 *
 * Idea
 * ----
 * Maintain the current candidate prefix length L for all strings seen so far.
 * Initialize L = |strs[0]|. For each next string s:
 *   - Let lim = min(L, |s|).
 *   - Scan base[0..lim) and s[0..lim) once, left-to-right, to find the first
 *     mismatch position j (or j = lim if none).
 *   - Set L = j. If L becomes 0, return "" early.
 * Finally, return base.substr(0, L).
 *
 * Invariant / Correctness
 * -----------------------
 * After processing i strings, L equals the length of the longest common prefix
 * of strs[0], …, strs[i]. The update L := j computes exactly the LCP(base, s)
 * truncated to the previous L, thus preserving the invariant. When the loop
 * ends, L is the LCP length across all strings, so base.substr(0, L) is the
 * answer.
 *
 * Complexity
 * ----------
 * Each string contributes at most lim + 1 character comparisons (lim ≤ m),
 * and L never increases. Summing over all strings yields ≤ n·m comparisons,
 * where n = number of strings and m = min_i |strs[i]|.
 * Time:  O(n · m)
 * Space: O(1) extra
 *
 * Note
 * ----
 * For slightly better constants you may choose the shortest string as `base`,
 * but it’s not required for the O(n·m) bound.
 */
string LongestCommonPrefix_14::longestCommonPrefix_Linear(const vector<string> &strs) const
{
    if (strs.empty())
        return "";
    const string &base = strs[0];
    size_t L = base.size();
    for (size_t i = 1; i < strs.size(); ++i)
    {
        const string &s = strs[i];
        size_t j = 0;
        size_t lim = min(L, s.size());
        while (j < lim && base[j] == s[j])
            ++j;    // single-pass scan
        L = j;
        if (L == 0)
            return "";
    }
    return base.substr(0, L);
}

/*
 * Longest Common Prefix — sort + compare extremes
 *
 * Idea
 * ----
 * Copy the input, sort it lexicographically, then compute the common prefix
 * only between the first string `a = v.front()` and the last string
 * `b = v.back()`. Return that prefix.
 *
 * Why "first and last" are enough
 * ------------------------------
 * After sorting, all strings that share a given prefix P form one contiguous
 * block in the sorted order (because lexicographic order groups equal-prefix
 * strings together).
 *
 * Let P be the longest common prefix of *all* strings in v.
 * - Then in particular, both the smallest string `a` and the largest string `b`
 *   (lexicographically) must start with P, so LCP(a, b) has length >= |P|.
 * - Conversely, suppose `a` and `b` first differ at position k. Then there exist
 *   strings in the set that are <= b and >= a, but any string that would share
 *   a longer prefix than k with both a and b would have to lie "between" them
 *   and still start with that longer prefix. Since a and b already disagree at k,
 *   no string can force the global common prefix to extend beyond k.
 *   Therefore the common prefix of all strings cannot be longer than LCP(a, b).
 *
 * Combining both directions gives:
 *   LCP(all strings) == LCP(v.front(), v.back()).
 *
 * Complexity
 * ----------
 * Sorting dominates. With n strings and average length ~m:
 * - sort: O(n log n) comparisons, each comparison can cost up to O(m)
 *   (lexicographic compare may scan characters until mismatch)
 * - final prefix scan: O(m)
 * Total time:  O(n log n · m)   (worst-case)
 * Extra space: O(n) for the copied vector (plus sort overhead), and O(1) extra
 * beyond that.
 *
 * Note
 * ----
 * This is typically less optimal than the linear "shrink L" approach
 * (O(n · m) time, O(1) extra), so treat it as an optional alternative
 * (e.g., for A/B checks in tests) rather than the primary implementation.
 */
string LongestCommonPrefix_14::longestCommonPrefix_Sort(const vector<string> &strs) const
{
    if (strs.empty())
        return "";
    vector<string> v = strs;
    sort(v.begin(), v.end());
    const string &a = v.front();
    const string &b = v.back();
    size_t i = 0, lim = min(a.size(), b.size());
    while (i < lim && a[i] == b[i])
        ++i;
    return a.substr(0, i);
}
