#include "LongestCommonSubsequence_1143.h"
#include <algorithm>
#include <utility>
#include <vector>

using namespace std;

int LongestCommonSubsequence_1143::longestCommonSubsequence(const string& text1, const string& text2)
{
    int m = static_cast<int>(text1.size());
    int n = static_cast<int>(text2.size());

    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (text1[i - 1] == text2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    return dp[m][n];
}

int LongestCommonSubsequence_1143::longestCommonSubsequenceTwoRows(
    const string& text1, const string& text2)
{
    const string* a = &text1;
    const string* b = &text2;
    if (b->size() > a->size()) {
        swap(a, b);
    }

    int m = static_cast<int>(a->size());
    int n = static_cast<int>(b->size());

    vector<int> prev(n + 1, 0);
    vector<int> cur(n + 1, 0);

    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if ((*a)[i - 1] == (*b)[j - 1]) {
                cur[j] = prev[j - 1] + 1;
            } else {
                cur[j] = max(prev[j], cur[j - 1]);
            }
        }
        swap(prev, cur);
    }

    return prev[n];
}

string LongestCommonSubsequence_1143::longestCommonSubsequenceString(
    const string& text1, const string& text2)
{
    int m = static_cast<int>(text1.size());
    int n = static_cast<int>(text2.size());

    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (text1[i - 1] == text2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    string lcs;
    lcs.reserve(dp[m][n]);

    int i = m, j = n;
    while (i > 0 && j > 0) {
        if (text1[i - 1] == text2[j - 1]) {
            lcs.push_back(text1[i - 1]);
            --i; --j;
        } else if (dp[i - 1][j] >= dp[i][j - 1]) {
            --i;
        } else {
            --j;
        }
    }

    reverse(lcs.begin(), lcs.end());
    return lcs;
}
