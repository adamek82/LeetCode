#include "PermutationInString_567.h"

bool PermutationInString_567::checkInclusion(string s1, string s2)
{
    const int m = s1.size(), n = s2.size();
    if (m > n) return false;

    array<int, 26> need{};      // counts of chars in s1
    array<int, 26> window{};    // counts inside current window

    for (char c : s1)  need[c - 'a']++;
    for (int i = 0; i < m; ++i)  window[s2[i] - 'a']++;

    if (need == window) return true;     // first window

    for (int right = m; right < n; ++right) {
        int left = right - m;            // index that slides out

        --window[s2[left] - 'a'];        // remove leftmost char
        ++window[s2[right] - 'a'];       // add new char

        if (need == window) return true; // check current window
    }
    return false;
}