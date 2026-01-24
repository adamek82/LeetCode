#include "BestTimeToBuyAndSellStock_121.h"
#include <limits>

/*
 * Single-pass greedy:
 * We maintain the lowest price seen so far (minPrice). For each day’s price:
 * - If it’s a new minimum, update minPrice (candidate buy day).
 * - Otherwise, compute the profit of selling today after buying at minPrice,
 *   and update maxProfit if this profit is larger.
 *
 * This guarantees buy-before-sell because minPrice only comes from earlier days
 * (we update it and then skip profit computation on the same iteration when a
 * new minimum is found). Runs in O(n) time and O(1) extra space.
 */
int BestTimeToBuyAndSellStock_121::maxProfit(vector<int> &prices)
{
    int minPrice = numeric_limits<int>::max();
    int maxProfit = 0;
    for (int price : prices) {
        if (price < minPrice) {
            minPrice = price;
        } else if (price - minPrice > maxProfit) {
            maxProfit = price - minPrice;
        }
    }
    return maxProfit;
}
