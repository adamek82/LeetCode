#include "MinCostToConnectAllPoints_1584.h"

int MinCostToConnectAllPoints_1584::minCostConnectPoints(std::vector<std::vector<int>> &points)
{
    int n = points.size();
    std::vector<bool> inMST(n, false); // Tracks if a point is already in the MST
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<>> minHeap;
    // Min-heap to store (cost, point_index)

    int result = 0; // Total cost of the MST
    int edgesUsed = 0; // Number of edges included in the MST

    // Start with point 0
    minHeap.push({0, 0}); // (cost, point_index)

    while (edgesUsed < n) {
        auto [currCost, currPoint] = minHeap.top();
        minHeap.pop();

        // Skip if this point is already in MST
        if (inMST[currPoint]) {
            continue;
        }

        // Add this point to the MST
        result += currCost;
        inMST[currPoint] = true;
        edgesUsed++;

        // Update the min-heap with the cost of connecting this point to others
        for (int nextPoint = 0; nextPoint < n; ++nextPoint) {
            if (!inMST[nextPoint]) {
                int dist = manhattanDist(points[currPoint], points[nextPoint]);
                minHeap.push({dist, nextPoint});
            }
        }
    }

    return result;
}

// Helper function to calculate Manhattan distance between two points
int MinCostToConnectAllPoints_1584::manhattanDist(const std::vector<int> &p1, const std::vector<int> &p2)
{
    return abs(p1[0] - p2[0]) + abs(p1[1] - p2[1]);
}
