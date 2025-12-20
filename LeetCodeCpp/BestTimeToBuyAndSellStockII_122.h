#pragma once
#include <vector>

using namespace std;

class BestTimeToBuyAndSellStockII_122 {
public:
    // Implementation 1: day-by-day accumulation of positive differences.
    int maxProfit_DailyDiffs(vector<int>& prices);

    // Implementation 2: explicit valley -> peak transactions (find buy and sell points).
    int maxProfit_ValleyPeak(vector<int>& prices);
};
