#pragma once
#include <queue>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class MinCostToConnectAllPoints_1584 {
public:
    int minCostConnectPointsHeap(vector<vector<int>>& points);
    int minCostConnectPointsArray(vector<vector<int>>& points);
private:
    int manhattanDist(const vector<int>& p1, const vector<int>& p2);
};