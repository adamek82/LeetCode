#include "LongestRepeatingCharacterReplacement_424.h"

int LongestRepeatingCharacterReplacement_424::characterReplacement(std::string s, int k)
{
    std::vector<int> freq(26, 0);   // counts for letters in current window
    int left = 0;                   // window left bound
    int maxFreq = 0;                // highest single‑letter frequency in window
    int best = 0;                   // longest valid window seen so far

    for (int right = 0; right < static_cast<int>(s.size()); ++right) {
        int idx = s[right] - 'A';
        ++freq[idx];
        maxFreq = std::max(maxFreq, freq[idx]);

        // shrink window until it needs ≤ k replacements
        while ((right - left + 1) - maxFreq > k) {
            --freq[s[left] - 'A'];
            ++left;
        }
        best = std::max(best, right - left + 1);
    }
    return best;
}