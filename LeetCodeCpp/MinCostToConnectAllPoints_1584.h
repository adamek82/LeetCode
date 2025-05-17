#pragma once
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

class MinCostToConnectAllPoints_1584 {
public:
    int minCostConnectPoints(vector<vector<int>>& points);
private:
    int manhattanDist(const vector<int>& p1, const vector<int>& p2);
};