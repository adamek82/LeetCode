#include "MinCostToConnectAllPoints_1584.h"

#include <algorithm>
#include <cstdlib>
#include <functional>
#include <limits>
#include <queue>
#include <utility>
#include <vector>

using namespace std;

int MinCostToConnectAllPoints_1584::minCostConnectPointsHeap(vector<vector<int>>& points)
{
    const int n = static_cast<int>(points.size());
    if (n == 0) {
        return 0;
    }

    // Educational sparse-graph-style Prim; for this complete graph prefer the O(n^2) array variant.
    vector<bool> inMST(n, false);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> minHeap;

    long long total = 0;
    int pointsUsed = 0;

    minHeap.emplace(0, 0);

    while (pointsUsed < n) {
        auto [currCost, currPoint] = minHeap.top();
        minHeap.pop();

        if (inMST[currPoint]) {
            continue;
        }

        total += currCost;
        inMST[currPoint] = true;
        ++pointsUsed;

        for (int nextPoint = 0; nextPoint < n; ++nextPoint) {
            if (!inMST[nextPoint]) {
                const int dist = manhattanDist(points[currPoint], points[nextPoint]);
                minHeap.emplace(dist, nextPoint);
            }
        }
    }

    return static_cast<int>(total);
}

int MinCostToConnectAllPoints_1584::minCostConnectPointsArray(vector<vector<int>>& points)
{
    const int n = static_cast<int>(points.size());
    if (n == 0) {
        return 0;
    }

    vector<int> minDist(n, numeric_limits<int>::max());
    vector<bool> used(n, false);

    long long total = 0;
    minDist[0] = 0;

    for (int it = 0; it < n; ++it) {
        int v = -1;

        for (int i = 0; i < n; ++i) {
            if (!used[i] && (v == -1 || minDist[i] < minDist[v])) {
                v = i;
            }
        }

        used[v] = true;
        total += minDist[v];

        for (int u = 0; u < n; ++u) {
            if (!used[u]) {
                const int w = manhattanDist(points[v], points[u]);
                minDist[u] = min(minDist[u], w);
            }
        }
    }

    return static_cast<int>(total);
}

int MinCostToConnectAllPoints_1584::manhattanDist(
    const vector<int>& p1,
    const vector<int>& p2)
{
    return abs(p1[0] - p2[0]) + abs(p1[1] - p2[1]);
}
