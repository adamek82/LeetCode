#include "ValidPalindrome_125.h"

bool ValidPalindrome_125::isPalindrome(string s)
{
    int l = 0, r = static_cast<int>(s.size()) - 1;
    while (l < r) {
        while (l < r && !isalnum(static_cast<unsigned char>(s[l]))) ++l;
        while (l < r && !isalnum(static_cast<unsigned char>(s[r]))) --r;
        if (l < r &&
            tolower(static_cast<unsigned char>(s[l])) !=
            tolower(static_cast<unsigned char>(s[r])))
            return false;
        ++l; --r;
    }
    return true;
}