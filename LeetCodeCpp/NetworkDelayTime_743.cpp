#include "NetworkDelayTime_743.h"
#include <iostream>
#include <queue>

/*
 * Correctness sketch (Dijkstra with a binary min-heap, no decrease-key)
 * --------------------------------------------------------------------
 * Assumptions:
 *  - The graph is directed.
 *  - All edge weights are non-negative: w(u, v) >= 0.
 *  - Vertices are numbered from 1 to n.
 *
 * Data:
 *  - dist[u] is the best distance from the source k to u found so far.
 *  - dist[u] == INF means that u has not been discovered yet.
 *  - pq contains pairs (d, u). Each such pair represents a discovered path
 *    from k to u with length d.
 *
 * Important note:
 *  This implementation does not perform a decrease-key operation in the heap.
 *  When a better distance to u is found, we update dist[u] and push a new pair
 *  (dist[u], u). Older, worse pairs for the same vertex may remain in pq and are
 *  later ignored by the stale-entry check:
 *
 *      if (d > dist[u]) continue;
 *
 * Terminology:
 *  - A vertex is "discovered" if dist[u] < INF.
 *  - A vertex is "settled" when it is popped from pq with d == dist[u] and its
 *    outgoing edges are processed.
 *  - A heap entry (d, u) is "stale" if d > dist[u]. It corresponds to an older
 *    path to u that has already been improved.
 *
 * Loop invariants (at the top of each while-iteration):
 *
 *  1) For every settled vertex x, dist[x] is the true shortest-path distance
 *     from k to x, usually denoted δ(x).
 *
 *  2) Every heap entry (d, y) represents some actually discovered path from k
 *     to y with length d. Therefore d >= δ(y), because δ(y) is the shortest
 *     possible distance to y.
 *
 *  3) For every discovered but not yet settled vertex y, dist[y] is the best
 *     distance to y found so far. When dist[y] was last improved, the algorithm
 *     pushed an entry (dist[y], y) into pq. The heap may also contain older,
 *     worse entries for y, but those will be skipped as stale.
 *
 *  4) Undiscovered vertices have dist[y] == INF and do not need to appear in pq.
 *
 * Basis:
 *  Initially, dist[k] = 0 and pq contains only (0, k). This represents the empty
 *  path from k to itself. No vertex has been settled yet, and all undiscovered
 *  vertices have distance INF.
 *
 * Induction step:
 *  Let (d, u) be the next pair popped from pq.
 *
 *  If d > dist[u], then this entry is stale. A strictly better path to u has
 *  already been found, so processing outgoing edges using the worse distance d
 *  cannot improve anything that would not also be reachable from dist[u].
 *  Therefore it is safe to skip this entry.
 *
 *  Otherwise d == dist[u]. We claim that d is the true shortest-path distance
 *  δ(u).
 *
 *  Suppose, for contradiction, that there exists a strictly shorter path P from
 *  k to u with length δ(u) < d. Consider the first vertex y on P that is not
 *  settled at the moment u is popped. Let x be the predecessor of y on P.
 *  Then x is settled by the choice of y.
 *
 *  When x was settled, the algorithm relaxed edge (x, y). Since dist[x] was
 *  already equal to δ(x), this relaxation must have discovered a candidate for y
 *  with distance:
 *
 *      δ(x) + w(x, y) = δ(y)
 *
 *  and pushed an entry with key δ(y) into pq, unless an even better distance to y
 *  was already known.
 *
 *  Because all edge weights are non-negative and y lies on a shortest path to u,
 *  we have:
 *
 *      δ(y) <= δ(u) < d
 *
 *  Therefore, at the time u is popped, pq should contain a non-stale entry for
 *  some vertex on P with key less than d. That contradicts the fact that (d, u)
 *  was the minimum key popped from the min-heap.
 *
 *  Hence no shorter path to u exists, so d == δ(u). Processing u's outgoing edges
 *  then performs the usual relaxations:
 *
 *      if (d + w < dist[v]) {
 *          dist[v] = d + w;
 *          pq.emplace(dist[v], v);
 *      }
 *
 *  This preserves the invariants: newly improved distances are recorded in dist
 *  and represented by new heap entries, while older entries remain harmless
 *  because the stale-entry check will discard them later.
 *
 * Intuition behind the proof:
 * ---------------------------
 *  Dijkstra's algorithm grows a region of settled vertices around the source.
 *  At each step, the min-heap chooses the discovered vertex with the smallest
 *  currently known distance.
 *
 *  Once a vertex u is popped with d == dist[u], there is no way for some later
 *  path to reach u more cheaply.
 *
 *  Why? Any alternative path to u would have to leave the already-settled region
 *  through some not-yet-settled vertex y. But the prefix of that path from the
 *  source to y would already have distance less than the full path to u.
 *
 *  If that full path were shorter than d, then y would have a candidate distance
 *  smaller than d in the heap. The heap would then pop y before u. Since u was
 *  popped first, such a shorter path cannot exist.
 *
 *  The non-negative edge weight assumption is essential here. Once we extend a
 *  path by another edge, its length cannot decrease. Therefore a path that first
 *  reaches some not-yet-settled vertex with distance at least d cannot later turn
 *  into a path to u with total distance smaller than d.
 *
 * Why the stale-entry guard works:
 * --------------------------------
 *  The line
 *
 *      if (d > dist[u]) continue;
 *
 *  skips heap entries whose key d is strictly worse than the current best known
 *  distance dist[u].
 *
 *  Such entries appear because this implementation never decreases a key already
 *  stored in pq. Instead, when a better path to u is found, a new pair (d', u) is
 *  pushed with d' < d, and the old pair remains in pq.
 *
 *  When the old pair is eventually popped, dist[u] already stores a better
 *  distance. Relaxing outgoing edges from the old distance d would only produce
 *  candidates d + w that are no better than the candidates produced from the
 *  smaller distance dist[u], because all weights w are non-negative.
 *
 *  Therefore stale entries can be ignored safely.
 *
 *  The check must be strict:
 *
 *      if (d > dist[u]) continue;
 *
 *  We must not skip d == dist[u]. The first non-stale extraction of u has exactly
 *  d == dist[u] and is the moment when u becomes settled and its outgoing edges
 *  must be relaxed.
 *
 * Termination and result:
 * -----------------------
 *  Each successful relaxation strictly decreases some dist[v] and pushes one
 *  heap entry. There are at most O(E) successful relaxations, so only O(E) heap
 *  entries are pushed. The loop terminates after all entries have been popped
 *  either for processing or as stale entries.
 *
 *  After the loop, dist[u] is the shortest distance from k to u for every
 *  reachable vertex u. If some vertex remains INF, it is unreachable and the
 *  answer is -1. Otherwise, the network delay time is the maximum shortest
 *  distance among vertices 1..n.
 *
 * Time complexity:
 * ----------------
 *  Let V be the number of vertices and E the number of edges.
 *
 *  - Building the adjacency list takes Θ(V + E).
 *  - Each successful relaxation pushes one heap entry.
 *  - There are O(E) pushed entries and therefore O(E) pops.
 *  - Each heap operation costs O(log H), where H is the current heap size.
 *    In this no-decrease-key variant, H can be O(E), so this is O(log E).
 *    For a simple graph, E <= V^2, hence log E <= 2 log V, and Big-O ignores
 *    constant factors. Therefore O(log E) is usually written as O(log V),
 *    giving the standard O((V + E) log V) bound.
 *
 *  Overall: O((V + E) log V).
 *
 * Space complexity:
 * -----------------
 *  - The adjacency list uses Θ(V + E) space.
 *  - The dist array uses Θ(V) space.
 *  - The heap may contain O(E) entries in the no-decrease-key variant.
 *
 *  Overall: O(V + E) space.
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
