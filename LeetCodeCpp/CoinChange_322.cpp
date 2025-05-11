#include "CoinChange_322.h"

int CoinChange_322::coinChange(std::vector<int> &coins, int amount)
{
    std::sort(coins.begin(), coins.end());
    const int INF = amount + 1;
    std::vector<int> dp(amount + 1, INF);
    dp[0] = 0;

    for (int i = 1; i <= amount; ++i) {
        for (int c : coins) {
            if (c > i) break;
            // no need to check dp[i-c] != INF
            dp[i] = std::min(dp[i], dp[i - c] + 1);
        }
    }
    return dp[amount] == INF ? -1 : dp[amount];
}