#include "WildcardMatching_44.h"
#include <vector>

using namespace std;

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

bool WildcardMatching_44::isMatch_DP2D(const string& text, const string& pattern)
{
    const size_t m = text.size();
    const size_t n = pattern.size();

    vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));

    dp[0][0] = true;

    for (size_t j = 1; j <= n; ++j) {
        if (pattern[j - 1] == '*') {
            dp[0][j] = dp[0][j - 1];
        }
    }

    for (size_t i = 1; i <= m; ++i) {
        for (size_t j = 1; j <= n; ++j) {
            if (pattern[j - 1] == '*') {
                dp[i][j] = dp[i][j - 1] || dp[i - 1][j];
            } else if (pattern[j - 1] == '?' ||
                       pattern[j - 1] == text[i - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
            }
        }
    }

    return dp[m][n];
}
