#include "RomanToInteger_13.h"

namespace {

int value(char c)
{
    switch (c) {
        case 'I': return 1;
        case 'V': return 5;
        case 'X': return 10;
        case 'L': return 50;
        case 'C': return 100;
        case 'D': return 500;
        case 'M': return 1000;
        default: return 0;
    }
}

}

int RomanToInteger_13::romanToInt(const string& s)
{
    int result = 0;
    int previous = 0;

    for (auto it = s.rbegin(); it != s.rend(); ++it) {
        const int current = value(*it);

        if (current < previous)
            result -= current;
        else
            result += current;

        previous = current;
    }

    return result;
}
