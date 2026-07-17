#include "DesignGraphWithShortestPathCalculator_2642.h"

#include <functional>
#include <limits>
#include <queue>
#include <utility>
#include <vector>

using namespace std;

Graph::Graph(int n, const vector<vector<int>>& edges)
    : n(n), adj(n)
{
    for (const auto& edge : edges) {
        addEdge(edge);
    }
}

void Graph::addEdge(const vector<int>& edge) {
    int from = edge[0];
    int to = edge[1];
    int cost = edge[2];

    adj[from].push_back({to, cost});
}

int Graph::shortestPath(int node1, int node2)
{
    const long long INF = numeric_limits<long long>::max();

    vector<long long> dist(n, INF);
    priority_queue<DistPair, vector<DistPair>, greater<>> pq;

    dist[node1] = 0;
    pq.emplace(0, node1);

    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();

        if (d != dist[u]) {
            continue; // Stale heap entry.
        }

        if (u == node2) {
            return static_cast<int>(d);
        }

        for (auto [v, w] : adj[u]) {
            const long long nd = d + w;

            if (nd < dist[v]) {
                dist[v] = nd;
                pq.emplace(nd, v);
            }
        }
    }

    return -1;
}
