#pragma once
#include <queue>
#include <vector>
#include <algorithm>

class MinCostToConnectAllPoints_1584 {
public:
    int minCostConnectPoints(std::vector<std::vector<int>>& points);
private:
    int manhattanDist(const std::vector<int>& p1, const std::vector<int>& p2);
};