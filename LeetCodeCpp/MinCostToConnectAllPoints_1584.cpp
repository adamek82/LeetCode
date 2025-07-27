#include "MinCostToConnectAllPoints_1584.h"

/*
 * This is Prim’s algorithm implemented with a min-heap (lazy updates).
 *
 * Educationally it’s fine, but for THIS problem the underlying graph is complete:
 * every pair of points forms an edge, so |E| ~= n*(n-1)/2 = Θ(n^2).
 *
 * Using a binary heap yields time Θ(E log V) = Θ(n^2 log n)
 * because we push Θ(n) candidates at each of n steps (Θ(n^2) total pushes),
 * and each push/pop costs O(log V) ~ O(log n). With the lazy pattern
 * (std::priority_queue has no decrease-key) many stale entries are popped and skipped,
 * but the asymptotics stay Θ(n^2 log n) and memory can hold Θ(n^2) queued pairs.
 *
 * A simple array-based Prim that scans all vertices to find the next minimum
 * runs in Θ(n^2) time and O(n) extra space, which is asymptotically and
 * practically better here (n ≤ 1000).
 *
 * Notes:
 * - Result can approach ~4e9 in worst cases, so summing in 64-bit (long long) is safer.
 * - Keep this heap version if you want to mirror the typical sparse-graph implementation;
 *   for dense graphs prefer the O(n^2) array variant.
 */
int MinCostToConnectAllPoints_1584::minCostConnectPoints(vector<vector<int>> &points)
{
    int n = points.size();
    vector<bool> inMST(n, false); // Tracks if a point is already in the MST
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> minHeap;
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
int MinCostToConnectAllPoints_1584::manhattanDist(const vector<int> &p1, const vector<int> &p2)
{
    return abs(p1[0] - p2[0]) + abs(p1[1] - p2[1]);
}
