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
 * Optional alternative; useful for A/B checks in tests.
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
