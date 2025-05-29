#include "ReverseString_344.h"

void ReverseString_344::reverseString(vector<char> &s)
{
    int l = 0, r = static_cast<int>(s.size()) - 1;
    while (l < r) {
        swap(s[l++], s[r--]);
    }
}