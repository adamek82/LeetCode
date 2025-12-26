#include "BestTimeToBuyAndSellStockII_122.h"

/*
 * In this solution, we calculate the maximum profit by summing every "positive difference"
 * between consecutive days. Specifically, for each day i > 0, if prices[i] > prices[i - 1],
 * we pretend we buy on day (i - 1) and sell on day i. This sum of all small increases
 * is equivalent to "buying low and selling high" repeatedly, which effectively captures
 * the entire upward movement.
 */
int BestTimeToBuyAndSellStockII_122::maxProfit_DailyDiffs(vector<int> &prices)
{
    // Accumulates the total profit after evaluating all daily price differences
    int totalProfit = 0;

    // Iterate through prices starting from the second day (i = 1)
    for (int i = 1; i < static_cast<int>(prices.size()); ++i) {

        // If today's price is higher than yesterday's price,
        // we add the difference to our total profit
        if (prices[i] > prices[i - 1]) {
            totalProfit += (prices[i] - prices[i - 1]);
        }
    }

    // Return the accumulated profit after processing all days
    return totalProfit;
}

/*
 * Valley/Peak scan (explicit transactions)
 *
 * Idea
 * ----
 * We repeatedly:
 *   1) scan forward to find a local minimum (valley)   -> that's our "buy" day
 *   2) then scan forward to find a local maximum (peak) -> that's our "sell" day
 * and add (sell - buy) to the answer.
 *
 * This produces the same total profit as summing all positive day-to-day differences,
 * but makes the transaction boundaries explicit.
 */
int BestTimeToBuyAndSellStockII_122::maxProfit_ValleyPeak(vector<int>& prices)
{
    const int n = static_cast<int>(prices.size());
    if (n < 2) {
        return 0;
    }

    int totalProfit = 0;
    int i = 0;

    while (i < n - 1) {

        // Look where to buy: move forward while the price is not increasing.
        // After this loop, i points to a local minimum (or we reached the end).
        while (i < n - 1 && prices[i + 1] <= prices[i]) {
            ++i;
        }
        const int buy = prices[i];

        // Look where to sell: move forward while the price keeps increasing.
        // After this loop, i points to a local maximum.
        while (i < n - 1 && prices[i + 1] >= prices[i]) {
            ++i;
        }
        const int sell = prices[i];

        totalProfit += (sell - buy);
    }

    return totalProfit;
}
