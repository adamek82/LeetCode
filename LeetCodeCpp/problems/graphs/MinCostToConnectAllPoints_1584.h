#pragma once

#include <vector>

class MinCostToConnectAllPoints_1584 {
public:
    int minCostConnectPointsHeap(std::vector<std::vector<int>>& points);
    int minCostConnectPointsArray(std::vector<std::vector<int>>& points);

private:
    int manhattanDist(const std::vector<int>& p1, const std::vector<int>& p2);
};
