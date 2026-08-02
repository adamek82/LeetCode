#include "ValidNumber_65.h"

bool ValidNumber_65::isNumber(const string& s) const
{
    bool seenDigit = false;
    bool seenDot = false;
    bool seenExponent = false;

    for (size_t index = 0; index < s.size(); ++index) {
        const char ch = s[index];

        if (ch >= '0' && ch <= '9') {
            seenDigit = true;
            continue;
        }

        if (ch == '+' || ch == '-') {
            if (index != 0 &&
                s[index - 1] != 'e' &&
                s[index - 1] != 'E') {
                return false;
            }

            continue;
        }

        if (ch == '.') {
            if (seenDot || seenExponent) {
                return false;
            }

            seenDot = true;
            continue;
        }

        if (ch == 'e' || ch == 'E') {
            if (seenExponent || !seenDigit) {
                return false;
            }

            seenExponent = true;
            seenDigit = false;
            continue;
        }

        return false;
    }

    return seenDigit;
}
