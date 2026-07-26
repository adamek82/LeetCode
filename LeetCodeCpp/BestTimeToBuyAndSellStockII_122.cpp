#include "BestTimeToBuyAndSellStockII_122.h"

int BestTimeToBuyAndSellStockII_122::maxProfit_DailyDiffs(
    const vector<int>& prices)
{
    int totalProfit = 0;

    for (size_t i = 1; i < prices.size(); ++i) {
        if (prices[i] > prices[i - 1])
            totalProfit += prices[i] - prices[i - 1];
    }

    return totalProfit;
}

int BestTimeToBuyAndSellStockII_122::maxProfit_ValleyPeak(
    const vector<int>& prices)
{
    if (prices.size() < 2)
        return 0;

    int totalProfit = 0;
    size_t i = 0;

    while (i + 1 < prices.size()) {
        while (i + 1 < prices.size() && prices[i + 1] <= prices[i])
            ++i;

        const int buy = prices[i];

        while (i + 1 < prices.size() && prices[i + 1] >= prices[i])
            ++i;

        const int sell = prices[i];
        totalProfit += sell - buy;
    }

    return totalProfit;
}
