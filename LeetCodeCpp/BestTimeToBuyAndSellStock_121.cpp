#include "BestTimeToBuyAndSellStock_121.h"

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