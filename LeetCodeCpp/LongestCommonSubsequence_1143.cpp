#include "LongestCommonSubsequence_1143.h"

int LongestCommonSubsequence_1143::longestCommonSubsequence(string text1, string text2)
{
    int m = text1.size();
    int n = text2.size();

    // DP table where dp[i][j] is the LCS of text1[0..i-1] and text2[0..j-1]
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    // Bottom-up DP
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (text1[i - 1] == text2[j - 1]) {
                // Characters match, extend the LCS
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                // Characters don't match, take the maximum LCS excluding one character
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    return dp[m][n];
}