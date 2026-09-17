#include "CoinChange_322.h"
#include <algorithm>

using namespace std;

int CoinChange_322::coinChange(vector<int>& coins, int amount)
{
    sort(coins.begin(), coins.end());

    const int INF = amount + 1;
    vector<int> dp(amount + 1, INF);
    dp[0] = 0;

    for (int i = 1; i <= amount; ++i) {
        for (int c : coins) {
            if (c > i) break;
            dp[i] = min(dp[i], dp[i - c] + 1);
        }
    }

    return dp[amount] == INF ? -1 : dp[amount];
}
