#include "UniquePaths_62.h"
#include <vector>

using namespace std;

int UniquePaths_62::uniquePaths_Comb(int m, int n)
{
    long long N = m + n - 2;
    long long k = min(m - 1, n - 1);

    long long res = 1;
    for (long long i = 1; i <= k; ++i) {
        res = res * (N - k + i) / i;
    }
    return static_cast<int>(res);
}

int UniquePaths_62::uniquePaths_DP2D(int m, int n)
{
    vector<vector<int>> dp(m, vector<int>(n, 1));

    for (int i = 1; i < m; ++i) {
        for (int j = 1; j < n; ++j) {
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        }
    }
    return dp[m - 1][n - 1];
}

int UniquePaths_62::uniquePaths_DP2Rows(int m, int n)
{
    vector<int> prev(n, 1);
    vector<int> curr(n, 1);

    for (int i = 1; i < m; ++i) {
        for (int j = 1; j < n; ++j) {
            curr[j] = curr[j - 1] + prev[j];
        }
        prev.swap(curr);
    }
    return prev[n - 1];
}
