#include "WildcardMatching_44.h"

bool WildcardMatching_44::isMatch(const string& text, const string& pattern)
{
    size_t textIndex = 0;
    size_t patternIndex = 0;

    size_t starIndex = string::npos;
    size_t starTextEnd = 0;

    while (textIndex < text.size()) {
        if (patternIndex < pattern.size() &&
            (pattern[patternIndex] == '?' ||
             pattern[patternIndex] == text[textIndex])) {
            ++textIndex;
            ++patternIndex;
            continue;
        }

        if (patternIndex < pattern.size() &&
            pattern[patternIndex] == '*') {
            starIndex = patternIndex;
            starTextEnd = textIndex;
            ++patternIndex;
            continue;
        }

        if (starIndex != string::npos) {
            patternIndex = starIndex + 1;
            textIndex = ++starTextEnd;
            continue;
        }

        return false;
    }

    while (patternIndex < pattern.size() &&
           pattern[patternIndex] == '*') {
        ++patternIndex;
    }

    return patternIndex == pattern.size();
}
