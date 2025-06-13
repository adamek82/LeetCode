#include "MaximumNumberOfBalloons_1189.h"
#include <array>
#include <limits>

int MaximumNumberOfBalloons_1189::maxNumberOfBalloons(string &text)
{
    array<int, 26> freq{};                // zero-initialised
    for (char c : text) freq[c - 'a']++;

    const array<int, 26> need = []{
        array<int, 26> a{};               // requirement vector
        a['b' - 'a'] = 1;
        a['a' - 'a'] = 1;
        a['l' - 'a'] = 2;
        a['o' - 'a'] = 2;
        a['n' - 'a'] = 1;
        return a;
    }();

    int ans = numeric_limits<int>::max();
    for (int i = 0; i < 26; ++i)
        if (need[i])
            ans = min(ans, freq[i] / need[i]);

    return ans == numeric_limits<int>::max() ? 0 : ans;
}