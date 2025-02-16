#include "BestTimeToBuyAndSellStockII_122.h"

/*
 * In this solution, we calculate the maximum profit by summing every "positive difference"
 * between consecutive days. Specifically, for each day i > 0, if prices[i] > prices[i - 1],
 * we pretend we buy on day (i - 1) and sell on day i. This sum of all small increases
 * is equivalent to "buying low and selling high" repeatedly, which effectively captures
 * the entire upward movement.
 */
int BestTimeToBuyAndSellStockII_122::maxProfit(std::vector<int> &prices)
{
    // Accumulates the total profit after evaluating all daily price differences
    int totalProfit = 0;

    // Iterate through prices starting from the second day (i = 1)
    for (int i = 1; i < (int)prices.size(); ++i) {

        // If today's price is higher than yesterday's price,
        // we add the difference to our total profit
        if (prices[i] > prices[i - 1]) {
            totalProfit += (prices[i] - prices[i - 1]);
        }
    }

    // Return the accumulated profit after processing all days
    return totalProfit;
}