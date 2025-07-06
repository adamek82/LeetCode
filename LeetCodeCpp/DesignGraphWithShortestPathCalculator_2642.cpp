#include "DesignGraphWithShortestPathCalculator_2642.h"

Graph::Graph(int n, vector<vector<int>>& edges) : n(n), adj(n) {
    for (auto& e : edges)                         // e = {from, to, cost}
        adj[e[0]].push_back({e[1], e[2]});
}

void Graph::addEdge(vector<int> edge) {           // edge = {from, to, cost}
    adj[edge[0]].push_back({edge[1], edge[2]});
}

int Graph::shortestPath(int node1, int node2) {
    const long long INF = numeric_limits<long long>::max();
    vector<long long> dist(n, INF);
    priority_queue<DistPair, vector<DistPair>, greater<DistPair>> pq;

    dist[node1] = 0;
    pq.push({0, node1});

    while (!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();
        if (d != dist[u]) continue;              // stale entry
        if (u == node2) return static_cast<int>(d);

        for (auto [v, w] : adj[u]) {             // (neighbor, cost)
            long long nd = d + w;
            if (nd < dist[v]) {
                dist[v] = nd;
                pq.push({nd, v});
            }
        }
    }
    return -1;                                   // unreachable
}
