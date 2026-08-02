#include "NetworkDelayTime_743.h"

#include <algorithm>
#include <functional>
#include <limits>
#include <queue>
#include <utility>
#include <vector>

using namespace std;

int NetworkDelayTime_743::networkDelayTime(vector<vector<int>>& times, int n, int k)
{
    const int INF = numeric_limits<int>::max() / 2;

    vector<vector<pair<int, int>>> graph(n + 1);
    for (const auto& t : times) {
        graph[t[0]].emplace_back(t[1], t[2]);
    }

    vector<int> dist(n + 1, INF);
    dist[k] = 0;

    using State = pair<int, int>; // {distance, node}

    priority_queue<State, vector<State>, greater<>> pq;
    pq.emplace(0, k);

    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();

        if (d > dist[u]) {
            continue; // Stale heap entry from before a shorter path to u was found.
        }

        for (auto [v, w] : graph[u]) {
            if (d + w < dist[v]) {
                dist[v] = d + w;
                pq.emplace(dist[v], v);
            }
        }
    }

    const int ans = *max_element(dist.begin() + 1, dist.end());
    return ans == INF ? -1 : ans;
}
