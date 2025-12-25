#include "LongestRepeatingCharacterReplacement_424.h"
#include <vector>
#include <string>
#include <algorithm>

/*
 * Longest Repeating Character Replacement (LeetCode 424) — sliding window
 *
 * Goal
 * ----
 * Find the longest substring that can be turned into all the same letter
 * using at most k replacements.
 *
 * Key observation
 * --------------
 * For any window [left..right], the minimum number of replacements needed to make
 * the whole window one repeated character equals:
 *
 *   windowLen - (max frequency of a single letter in the window)
 *
 * because we keep the most frequent letter as-is and replace all other chars.
 *
 * Sliding window
 * --------------
 * Maintain a window [left..right] with:
 * - freq[26]  : counts of 'A'..'Z' in the current window
 * - maxFreq   : the maximum value in freq seen while expanding (monotonic non-decreasing)
 *
 * Expand by moving `right`:
 *   - include s[right] in freq
 *   - update maxFreq if this letter becomes the new maximum
 *
 * If the window would need more than k replacements:
 *
 *   (right - left + 1) - maxFreq > k
 *
 * then shrink from the left until the condition is satisfied again:
 *   - remove s[left] from freq
 *   - ++left
 *
 * Why "maxFreq never decreases" is OK
 * ----------------------------------
 * When we move `left`, the true maximum frequency inside the current window might drop,
 * but we do not recompute maxFreq downward. This means the inequality can be slightly
 * optimistic (we may treat a window as valid a bit earlier), but it never inflates the
 * final answer: maxFreq is a historical upper bound on the best in-window frequency,
 * and using it prevents over-shrinking. We still only ever increase `right`, and for
 * each `right` we keep `left` as small as allowed by the budget, so the best length
 * we record corresponds to a length achievable somewhere during the scan.
 *
 * Complexity
 * ----------
 * Time:  O(n)   (each pointer moves forward at most n times)
 * Space: O(1)   (26 counters)
 */
int LongestRepeatingCharacterReplacement_424::characterReplacement(string s, int k)
{
    vector<int> freq(26, 0);   // counts for letters in current window
    int left = 0;                   // window left bound
    int maxFreq = 0;                // highest single‑letter frequency in window
    int best = 0;                   // longest valid window seen so far

    for (int right = 0; right < static_cast<int>(s.size()); ++right) {
        int idx = s[right] - 'A';
        ++freq[idx];
        maxFreq = max(maxFreq, freq[idx]);

        // shrink window until it needs ≤ k replacements
        while ((right - left + 1) - maxFreq > k) {
            --freq[s[left] - 'A'];
            ++left;
        }
        best = max(best, right - left + 1);
    }
    return best;
}