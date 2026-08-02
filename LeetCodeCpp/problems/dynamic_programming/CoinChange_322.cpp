#include "CoinChange_322.h"
#include <algorithm>

/*
 * Coin Change (LeetCode 322) — Bottom-up DP (unbounded knapsack)
 * -------------------------------------------------------------
 * Goal:
 *   Given coin denominations, find the minimum number of coins needed
 *   to make exactly `amount`. If impossible, return -1.
 *
 * Core intuition (build answers from smaller amounts):
 *   Any optimal way to make amount i must end with “one last coin” c.
 *   If the last coin is c, then before taking it we must have made (i - c).
 *
 *   So the problem for i reduces to a smaller subproblem:
 *
 *     best(i) = min over all coins c<=i of ( best(i - c) + 1 )
 *
 * DP meaning:
 *   dp[i] = minimum coins needed to make sum i.
 *
 * Base case:
 *   dp[0] = 0  (zero coins to make zero)
 *
 * Unreachable sentinel:
 *   Initialize dp[] with INF (here INF = amount + 1 is a convenient value)
 *   to represent “not possible yet”.
 *
 * Transition:
 *   For each target i from 1..amount:
 *     try every coin c that fits (c <= i):
 *       dp[i] = min(dp[i], dp[i - c] + 1)
 *
 * Why “no need to check dp[i - c] != INF”:
 *   If dp[i - c] is INF, then dp[i - c] + 1 becomes INF + 1.
 *   Since dp[i] starts at INF, min(INF, INF+1) stays INF, so nothing breaks.
 *
 * Why not Greedy?
 *   A greedy strategy (“always take the largest coin you can”) is tempting,
 *   but it is NOT guaranteed to minimize the number of coins unless the coin
 *   system has special properties.
 *
 *   Example: coins = [1, 6, 7, 9, 11], amount = 13
 *     Greedy picks 11 (largest <= 13), remaining = 2
 *       -> must use 1 + 1, so total = 11 + 1 + 1 (3 coins)
 *     But the optimal solution is:
 *       -> 6 + 7 (2 coins)
 *
 *   Greedy fails because a locally-best choice (taking 11) can force an
 *   inefficient remainder, while a different combination of smaller coins
 *   uses fewer coins overall.
 *
 * Why sorting helps:
 *   Sorting coins lets us break early when c > i, saving iterations.
 *
 * Mental model:
 *   Imagine dp as a row of “best known costs” to reach each amount.
 *   For i, you look left by each coin value c and ask:
 *     “If I already know the cheapest way to reach (i-c),
 *      then adding one coin c gives me a candidate for i.”
 *
 * Three examples to lock it in:
 *
 *   Example A (typical DP win): coins = [1, 3, 4], amount = 6
 *     dp[0]=0
 *     i=1: dp[1]=dp[0]+1=1
 *     i=3: dp[3]=min(dp[2]+1, dp[0]+1)=1   (use coin 3)
 *     i=4: dp[4]=min(dp[3]+1=2, dp[1]+1=2, dp[0]+1=1)=1 (use coin 4)
 *     i=6: dp[6]=min(dp[5]+1, dp[3]+1, dp[2]+1)
 *                = min(?, 1+1=2, ?) = 2    (3+3 beats 4+1+1)
 *
 *   Example B (unreachable): coins = [2], amount = 3
 *     dp[0]=0
 *     i=1: no coin fits -> dp[1]=INF
 *     i=2: dp[2]=dp[0]+1=1
 *     i=3: only coin 2 fits -> dp[3]=dp[1]+1=INF -> unreachable -> return -1
 *
 *   Example C (greedy trap): coins = [1, 6, 7, 9, 11], amount = 13
 *     Greedy would do: 11 + 1 + 1 (3 coins)
 *     DP finds:        6 + 7      (2 coins)
 *
 * Complexity:
 *   Time:  O(amount * number_of_coins)   (break helps in practice)
 *   Space: O(amount)
 */
int CoinChange_322::coinChange(vector<int> &coins, int amount)
{
    sort(coins.begin(), coins.end());
    const int INF = amount + 1;
    vector<int> dp(amount + 1, INF);
    dp[0] = 0;

    for (int i = 1; i <= amount; ++i) {
        for (int c : coins) {
            if (c > i) break;
            // no need to check dp[i-c] != INF
            dp[i] = min(dp[i], dp[i - c] + 1);
        }
    }
    return dp[amount] == INF ? -1 : dp[amount];
}
