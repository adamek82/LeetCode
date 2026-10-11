#include "LongestRepeatingCharacterReplacement_424.h"
#include <algorithm>
#include <array>
#include <cstddef>

using namespace std;

int LongestRepeatingCharacterReplacement_424::characterReplacement(const string& s, int k)
{
    array<size_t, 26> freq{};
    const size_t replacementLimit = static_cast<size_t>(k);
    size_t left = 0;
    size_t maxFreq = 0;

    for (size_t right = 0; right < s.size(); ++right) {
        maxFreq = max(maxFreq, ++freq[s[right] - 'A']);

        if (right + 1 - left > maxFreq + replacementLimit) {
            --freq[s[left] - 'A'];
            ++left;
        }
    }

    return static_cast<int>(s.size() - left);
}
