#include "MinCostToConnectAllPoints_1584.h"
#include <queue>
#include <algorithm>
#include <limits>

/*
 * This is Prim’s algorithm implemented with a min-heap (lazy updates).
 *
 * Educationally it’s fine, but for THIS problem the underlying graph is complete:
 * every pair of points forms an edge, so |E| ~= n*(n-1)/2 = Θ(n^2).
 *
 * Using a binary heap yields time Θ(E log V) = Θ(n^2 log n)
 * because we push Θ(n) candidates at each of n steps (Θ(n^2) total pushes),
 * and each push/pop costs O(log V) ~ O(log n). With the lazy pattern
 * (priority_queue has no decrease-key) many stale entries are popped and skipped,
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
int MinCostToConnectAllPoints_1584::minCostConnectPointsHeap(vector<vector<int>> &points)
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

/*
 * Prim’s MST — array-based O(n^2) variant.
 *
 * Idea:
 * - Maintain S = set of vertices already in the tree.
 * - minDist[u] stores the cheapest edge from any v ∈ S to u.
 * - Each iteration:
 *     1) pick the unused vertex v with the smallest minDist[v] (safe by the cut property),
 *     2) add its cost to the answer and mark v as used,
 *     3) relax: for every unused u, set minDist[u] = min(minDist[u], w(v,u)).
 *
 * This chooses, in every step, the lightest edge crossing the cut (S, V \ S),
 * which belongs to some MST (cut property). After n iterations we obtain an MST.
 *
 * Complexity: O(n^2) time, O(n) extra space — better than heap O(n^2 log n) on a
 * complete graph.
 */
int MinCostToConnectAllPoints_1584::minCostConnectPointsArray(vector<vector<int>> &points) {
    int n = static_cast<int>(points.size());
    // For every vertex not yet in the tree: best known cost to connect it to the tree S
    vector<int> minDist(n, std::numeric_limits<int>::max());

    // Marks vertices already added to the MST (set S)
    vector<char> used(n, 0);

    // Accumulates MST cost; 64-bit to avoid overflow
    long long total = 0;

    // Start Prim from node 0: cost to add the first node is 0
    minDist[0] = 0;

    // Repeat n times: each iteration adds exactly one new vertex to the MST.
    for (int it = 0; it < n; ++it) {
        // 1) Pick the unused vertex v with the smallest connection cost minDist[v].
        //    This is the "safe edge" per the cut property.
        int v = -1;
        for (int i = 0; i < n; ++i)
            if (!used[i] && (v == -1 || minDist[i] < minDist[v]))
                v = i;

        // 2) Add v to the MST and pay its connection cost.
        used[v] = 1;
        total += minDist[v];

        // 3) Relax edges from v to every still-unpicked vertex u:
        //    if connecting u via v is cheaper, update minDist[u].
        for (int u = 0; u < n; ++u) {
            if (!used[u]) {
                int w = manhattanDist(points[v], points[u]);
                if (w < minDist[u]) minDist[u] = w;
            }
        }
    }

    // The sum of chosen minimal crossing edges is the MST weight.
    return static_cast<int>(total);
}

// Helper function to calculate Manhattan distance between two points
int MinCostToConnectAllPoints_1584::manhattanDist(const vector<int> &p1, const vector<int> &p2)
{
    return abs(p1[0] - p2[0]) + abs(p1[1] - p2[1]);
}
