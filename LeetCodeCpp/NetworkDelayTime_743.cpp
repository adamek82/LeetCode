#include "NetworkDelayTime_743.h"
#include <iostream>

int NetworkDelayTime_743::networkDelayTime(vector<vector<int>> &times, int n, int k)
{
    const int INF = numeric_limits<int>::max();

    // Build the graph as an adjacency list
    vector<vector<pair<int,int>>> g(n + 1);
    for (auto& t : times)
        g[t[0]].push_back({t[1], t[2]});

    // Dijkstra
    vector<int> dist(n + 1, INF);
    dist[k] = 0;

    using State = pair<int,int>;                                // {dist, node}
    // Min-heap to keep track of the minimum time to reach each node
    priority_queue<State, vector<State>, greater<State>> pq;
    pq.emplace(0, k);

    while (!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();
        if (d > dist[u]) continue;                  // stale entry

        for (auto [v, w] : g[u]) {
            if (d + w < dist[v]) {                  // relaxation
                dist[v] = d + w;
                pq.emplace(dist[v], v);
            }
        }
    }

    int ans = *max_element(dist.begin() + 1, dist.end());
    return ans == INF ? -1 : ans;
}