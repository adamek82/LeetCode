#include "PerfectSquares_279.h"
#include <vector>
#include <algorithm>

using namespace std;

int PerfectSquares_279::numSquares(int n)
{
    vector<int> dp(n + 1, n + 1);
    dp[0] = 0;

    vector<int> squares;
    for (int j = 1; j * j <= n; ++j)
        squares.push_back(j * j);

    for (int k = 1; k <= n; ++k) {
        for (int s : squares) {
            if (s > k) break;
            dp[k] = min(dp[k], dp[k - s] + 1);
        }
    }
    return dp[n];
}
