#include "PermutationInString_567.h"
#include <string>
#include <array>

/*
 * Permutation in String (LeetCode 567) — sliding window (full compare)
 *
 * Idea
 * ----
 * Keep a window of length m = |s1| over s2 and compare 26-letter histograms.
 * If counts match for any window, that window is a permutation of s1.
 *
 * Complexity
 * ----------
 * Time:  O(n * 26) ~ O(n) (fixed alphabet)
 * Space: O(1)      (26 buckets)
 */
bool PermutationInString_567::checkInclusion_fullCompare(string s1, string s2)
{
    const int m = (int)s1.size();
    const int n = (int)s2.size();
    if (m > n) return false;

    array<int, 26> need{};
    array<int, 26> window{};

    for (char c : s1) ++need[c - 'a'];
    for (int i = 0; i < m; ++i) ++window[s2[i] - 'a'];

    if (need == window) return true;

    for (int right = m; right < n; ++right) {
        const int left = right - m;
        --window[s2[left] - 'a'];
        ++window[s2[right] - 'a'];

        if (need == window) return true;
    }

    return false;
}

void PermutationInString_567::applyDelta(array<int, 26>& window,
                                         const array<int, 26>& need,
                                         int idx,
                                         int delta,
                                         int& matches)
{
    if (need[idx] == window[idx]) --matches;   // leaving "matched" state
    window[idx] += delta;
    if (need[idx] == window[idx]) ++matches;   // entering "matched" state
}

/*
 * Permutation in String (LeetCode 567) — sliding window (matches counter)
 *
 * Idea
 * ----
 * Same fixed-size window, but instead of comparing all 26 buckets every time,
 * track `matches` = number of letters for which need[i] == window[i].
 *
 * When sliding the window, only two letters change (one goes out, one comes in),
 * so we can update `matches` in O(1) using applyDelta().
 *
 * Complexity
 * ----------
 * Time:  O(n)  (O(1) updates per step, plus initial 26 scan)
 * Space: O(1)  (26 buckets)
 */
bool PermutationInString_567::checkInclusion_matchesCounter(string s1, string s2)
{
    const int m = (int)s1.size();
    const int n = (int)s2.size();
    if (m > n) return false;

    array<int, 26> need{};
    array<int, 26> window{};

    for (char c : s1) ++need[c - 'a'];
    for (int i = 0; i < m; ++i) ++window[s2[i] - 'a'];

    int matches = 0;
    for (int i = 0; i < 26; ++i) {
        if (need[i] == window[i]) ++matches;
    }
    if (matches == 26) return true;

    for (int right = m; right < n; ++right) {
        const int outIdx = s2[right - m] - 'a';
        const int inIdx  = s2[right] - 'a';

        applyDelta(window, need, outIdx, -1, matches);
        applyDelta(window, need, inIdx,  +1, matches);

        if (matches == 26) return true;
    }

    return false;
}
