#include "ShortestCycleInGraph_2608.h"
#include <queue>
#include <algorithm>

int ShortestCycleInGraph_2608::findShortestCycle(int n, vector<vector<int>> &edges)
{
    vector<vector<int>> g(n);
    for (auto& e : edges) {
        int u = e[0], v = e[1];
        g[u].push_back(v);
        g[v].push_back(u);
    }

    /*
     * We use a large finite INF sentinel (1e9) instead of std::numeric_limits<int>::max().
     * Reason: it is safely above any real BFS distance here (dist <= n-1), while keeping
     * arithmetic like (2*dist[u] + 1) and (dist[u] + dist[v] + 1) comfortably away from
     * integer overflow concerns and avoiding extra casts/guards.
     *
     * Alternative: constexpr int INF = std::numeric_limits<int>::max() / 4;
     * This also works (keeps "infinite" far away and still leaves headroom), but for this
     * problem a simple 1'000'000'000 sentinel is clear, sufficient, and not worth extra fuss.
     */
    constexpr int INF = 1'000'000'000;
    int best = INF;
    vector<int> dist(n);

    for (int s = 0; s < n; ++s) {
        fill(dist.begin(), dist.end(), INF);
        queue<int> q;
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
                    /*
                     *  v is NOT the parent of u in the BFS tree.
                     *  In an undirected BFS tree the parent of u
                     *  is the only neighbour whose distance is
                     *  exactly dist[u]-1, so the inequality
                     *  identifies a cross/side edge that closes a cycle.
                     */
                    best = min(best, dist[u] + dist[v] + 1);
                }
            }
        }
    }
    return best == INF ? -1 : best;
}