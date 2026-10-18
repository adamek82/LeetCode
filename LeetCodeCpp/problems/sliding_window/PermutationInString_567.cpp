#include "PermutationInString_567.h"
#include <cstddef>

using namespace std;

bool PermutationInString_567::checkInclusion_fullCompare(
    const string& s1, const string& s2)
{
    const size_t m = s1.size();
    const size_t n = s2.size();

    if (m > n)
        return false;

    FrequencyArray need{};
    FrequencyArray window{};

    for (char c : s1) {
        ++need[c - 'a'];
    }

    for (size_t i = 0; i < m; ++i) {
        ++window[s2[i] - 'a'];
    }

    if (need == window)
        return true;

    for (size_t right = m; right < n; ++right) {
        const size_t left = right - m;

        --window[s2[left] - 'a'];
        ++window[s2[right] - 'a'];

        if (need == window)
            return true;
    }

    return false;
}

void PermutationInString_567::applyDelta(FrequencyArray& window,
                                         const FrequencyArray& need,
                                         size_t idx,
                                         int delta,
                                         size_t& matches)
{
    if (need[idx] == window[idx])
        --matches;

    window[idx] += delta;

    if (need[idx] == window[idx])
        ++matches;
}

bool PermutationInString_567::checkInclusion_matchesCounter(
    const string& s1, const string& s2)
{
    const size_t m = s1.size();
    const size_t n = s2.size();

    if (m > n)
        return false;

    FrequencyArray need{};
    FrequencyArray window{};

    for (char c : s1) {
        ++need[c - 'a'];
    }

    for (size_t i = 0; i < m; ++i) {
        ++window[s2[i] - 'a'];
    }

    size_t matches = 0;

    for (size_t i = 0; i < AlphabetSize; ++i) {
        if (need[i] == window[i])
            ++matches;
    }

    if (matches == AlphabetSize)
        return true;

    for (size_t right = m; right < n; ++right) {
        const size_t outIdx = s2[right - m] - 'a';
        const size_t inIdx = s2[right] - 'a';

        applyDelta(window, need, outIdx, -1, matches);
        applyDelta(window, need, inIdx, 1, matches);

        if (matches == AlphabetSize)
            return true;
    }

    return false;
}
