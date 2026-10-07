#include "LongestSubstringWithoutRepeatingCharacters_3.h"
#include <algorithm>
#include <array>
#include <cstddef>

using namespace std;

int LongestSubstringWithoutRepeatingCharacters_3::lengthOfLongestSubstring(const string& s)
{
    array<size_t, 256> nextPosition{};
    size_t best = 0;

    for (size_t left = 0, right = 0; right < s.size(); ++right) {
        const unsigned char c = s[right];
        left = max(left, nextPosition[c]);
        nextPosition[c] = right + 1;
        best = max(best, right - left + 1);
    }

    return static_cast<int>(best);
}
