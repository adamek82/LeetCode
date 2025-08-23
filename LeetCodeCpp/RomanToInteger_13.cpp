#include "RomanToInteger_13.h"

static inline int val(char c) {
    switch (c) {
        case 'I': return 1;
        case 'V': return 5;
        case 'X': return 10;
        case 'L': return 50;
        case 'C': return 100;
        case 'D': return 500;
        case 'M': return 1000;
        default:  return 0; // input is guaranteed valid per problem statement
    }
}

int RomanToInteger_13::romanToInt(const string& s)
{
    int res = 0;
    int prev = 0; // value of the previous (to the right) symbol

    for (int i = static_cast<int>(s.size()) - 1; i >= 0; --i) {
        int cur = val(s[i]);
        if (cur < prev) res -= cur;  // subtractive case
        else            res += cur;  // additive case
        prev = cur;
    }
    return res;
}
