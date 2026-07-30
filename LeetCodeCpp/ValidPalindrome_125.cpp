#include "ValidPalindrome_125.h"

namespace {

bool isAsciiAlphanumeric(char ch)
{
    return (ch >= 'a' && ch <= 'z') ||
           (ch >= 'A' && ch <= 'Z') ||
           (ch >= '0' && ch <= '9');
}

char toAsciiLower(char ch)
{
    if (ch >= 'A' && ch <= 'Z') {
        return static_cast<char>(ch + ('a' - 'A'));
    }

    return ch;
}

} // namespace

bool ValidPalindrome_125::isPalindrome(const string& s) const
{
    size_t left = 0;
    size_t right = s.size();

    while (left < right) {
        while (left < right &&
               !isAsciiAlphanumeric(s[left])) {
            ++left;
        }

        while (left < right &&
               !isAsciiAlphanumeric(s[right - 1])) {
            --right;
        }

        if (left >= right) {
            break;
        }

        if (toAsciiLower(s[left]) !=
            toAsciiLower(s[right - 1])) {
            return false;
        }

        ++left;
        --right;
    }

    return true;
}
