#include "NetworkDelayTime_743.h"
#include <iostream>
#include <queue>
#include <vector>

/*
 * Correctness sketch (Dijkstra with a binary min-heap)
 * ----------------------------------------------------
 * Assumptions: directed graph, non-negative edge weights w(u,v) ≥ 0.
 * Data: `dist[u]` = best distance to u currently known; priority queue pq contains
 *      pairs (d,u) meaning “there is a path A→u of length d discovered so far”.
 *
 * Loop invariant (maintained at the top of each while-iteration):
 *  1) For every vertex x that has already been removed from pq without being skipped
 *     by the “stale entry” test, dist[x] equals the true shortest-path distance δ(x).
 *  2) For every vertex y not yet settled, there exists at least one heap entry (d,y)
 *     with d ≥ δ(y). (In particular, when a better path to y is found we push a new
 *     entry with the improved key.)
 *
 * Basis: Initially dist[A]=0 and pq = {(0,A)}. δ(A)=0, so (1) will hold after we
 * remove A; (2) holds trivially because every discovered candidate is pushed.
 *
 * Induction step: Let (d,u) be the next heap minimum that is NOT skipped. By heap
 * property d is minimal among all keys currently in pq. Suppose, for the sake of
 * contradiction, that d > δ(u). Consider a shortest path P to u and let x be the
 * predecessor of u on P. x must already be settled when we pop (d,u); otherwise
 * there would still be some heap entry for x with key ≤ δ(x) < δ(u) < d, contradicting
 * the minimality of d. When x was settled we relaxed edge (x,u) and pushed a heap
 * entry (δ(x)+w(x,u),u) = (δ(u),u), so pq must contain a key strictly smaller than d
 * —again a contradiction. Therefore d = δ(u), and marking u as visited preserves (1).
 * Relaxing all edges (u,v) then pushes candidates of the form (δ(u)+w(u,v), v),
 * thus maintaining (2). By induction, every vertex we really process is settled with
 * its true shortest distance.
 *
 * Termination and result: The loop terminates because each relaxation only pushes,
 * and the heap becomes empty once all candidates have been popped or discarded as
 * stale. The answer is max_u dist[u] if all vertices are reachable; otherwise some
 * dist[u] stays INF and we return −1.
 *
 * Why the “stale entry” guard works
 * ---------------------------------
 * The line
 *     if (d > dist[u]) continue;
 * drops entries whose key d is strictly worse than the current best dist[u].
 * This situation occurs because we never decrease keys in the heap; instead, when
 * we find a better path to u we push a new pair (d',u) with d'<d and leave the old
 * one in pq. When the old (larger) one eventually pops, it is stale and can be
 * ignored safely since dist[u] already records a ≤-better distance that will (or
 * already did) propagate relaxations.
 *
 * Stale-entry guard
 * -----------------
 * We never perform decrease-key; instead we push a new (d',u) only when we
 * discover a strictly better distance: if (d_new < dist[u]). Therefore any
 * old heap entries for u have d_old > dist[u] and are safe to skip:
 *
 *     if (d > dist[u]) continue;   // skip strictly-worse entries
 *
 * Do NOT skip d == dist[u]: the first optimal extraction of u has exactly
 * this equality and must perform relaxations. Because relax() uses strict
 * '<', we never insert an equal-key duplicate for the same vertex, so the
 * d == dist[u] case is the fresh, correct one to process.
 *
 * Time complexity
 * ---------------
 * Let V = number of vertices, E = number of edges.
 *  - Building the adjacency list:  Θ(V + E).
 *  - Each pop from pq costs O(log V). We pop at most once per pushed entry.
 *    We push at most one entry per successful relaxation, i.e. O(E) entries.
 *    Hence the heap work is O((V + E) log V) (V for the source and any vertices
 *    that might be inserted once; E for all relaxations).
 * Overall: O((V + E) log V).  (With a Fibonacci heap: O(E + V log V).)
 *
 * Space complexity
 * ----------------
 *  - Graph adjacency lists: Θ(V + E).
 *  - dist array: Θ(V).
 *  - Heap: up to O(E) entries in the decrease-key-by-insertion style.
 * Overall: O(V + E) space.
 */
int NetworkDelayTime_743::networkDelayTime(vector<vector<int>> &times, int n, int k)
{
    const int INF = numeric_limits<int>::max();

    // Build the graph as an adjacency list
    vector<vector<pair<int, int>>> g(n + 1);
    for (auto& t : times)
        g[t[0]].emplace_back(t[1], t[2]);

    // Dijkstra
    vector<int> dist(n + 1, INF);
    dist[k] = 0;

    using State = pair<int,int>;                    // {dist, node}

    // Min-heap to keep track of the minimum time to reach each node
    priority_queue<State, vector<State>, greater<>> pq;
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