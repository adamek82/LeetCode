#include "ShortestCycleInGraph_2608.h"

int ShortestCycleInGraph_2608::findShortestCycle(int n, std::vector<std::vector<int>> &edges)
{
    std::vector<std::vector<int>> g(n);
    for (auto& e : edges) {
        int u = e[0], v = e[1];
        g[u].push_back(v);
        g[v].push_back(u);
    }

    const int INF = 1e9;
    int best = INF;
    std::vector<int> dist(n);

    for (int s = 0; s < n; ++s) {
        std::fill(dist.begin(), dist.end(), INF);
        std::queue<int> q;
        dist[s] = 0;
        q.push(s);

        while (!q.empty()) {
            int u = q.front(); q.pop();

            if (2 * dist[u] + 1 >= best)       // cannot beat current best
                continue;

            for (int v : g[u]) {
                if (dist[v] == INF) {          // tree edge
                    dist[v] = dist[u] + 1;
                    q.push(v);
                } else if (dist[v] + 1 != dist[u]) {
                    /*  v is NOT the parent of u in the BFS tree.
                        In an undirected BFS tree the parent of u
                        is the only neighbour whose distance is
                        exactly dist[u]-1, so the inequality
                        identifies a cross/side edge that closes a cycle. */
                    best = std::min(best, dist[u] + dist[v] + 1);
                }
            }
        }
    }
    return best == INF ? -1 : best;
}