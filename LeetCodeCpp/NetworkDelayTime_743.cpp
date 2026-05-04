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
 *
 *  - A heap entry (d, u) is "stale" if d > dist[u]. It corresponds to an older
 *    path to u that has already been improved.
 *
 *  - A heap entry (d, u) is "current" if d == dist[u], meaning that its key
 *    matches the best distance to u currently stored in dist[u].
 *
 *  - A vertex becomes "settled" when its current heap entry is popped from pq.
 *    At that moment, dist[u] is already the final shortest-path distance to u.
 *    Immediately after that, the algorithm processes u's outgoing edges.
 *
 *    Important: in the induction step below, we reason about the state just
 *    before (d, u) is popped from pq. At that point u is not settled yet. The
 *    proof shows that after popping this current entry, it is safe to mark u as
 *    settled.
 *
 * Loop invariants, maintained at the top of each while-iteration, before the
 * next heap entry is popped:
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
 *  path from k to itself. No vertex has been settled yet, and all other vertices
 *  have distance INF.
 *
 * Induction step:
 *  Consider the beginning of some while-iteration. Let (d, u) be the next pair
 *  that pq will return as the minimum.
 *
 *  If d > dist[u], then this entry is stale. A strictly better path to u has
 *  already been found, so processing outgoing edges using the worse distance d
 *  cannot improve anything that would not also be reachable from the better
 *  distance dist[u]. Therefore it is safe to skip this entry.
 *
 *  Otherwise d == dist[u]. This entry is current. We claim that d is the true
 *  shortest-path distance to u, i.e. d == δ(u).
 *
 *  Consider the state just before (d, u) is popped from pq. At that point u is
 *  not settled yet. Suppose, for contradiction, that there exists a strictly
 *  shorter path P from k to u with length δ(u) < d.
 *
 *  Walk along this path P from k toward u. Since k is settled first, and u is
 *  not settled yet just before being popped, there must be a first vertex on P
 *  that is not yet settled. Call it y.
 *
 *  Let x be the predecessor of y on P:
 *
 *      k -> ... -> x -> y -> ... -> u
 *
 *  Since y is the first unsettled vertex on this path, x is already settled.
 *
 *  When x was settled, the algorithm processed all outgoing edges of x,
 *  including edge (x, y). Since x is settled, dist[x] is already equal to δ(x).
 *  Therefore relaxing edge (x, y) must have considered the distance:
 *
 *      δ(x) + w(x, y)
 *
 *  Because edge x -> y lies on the shortest path P to u, this value is exactly
 *  the true shortest-path distance to y:
 *
 *      δ(x) + w(x, y) = δ(y)
 *
 *  Therefore the algorithm must have pushed a candidate for y with distance
 *  δ(y), unless an even better distance to y was already known. In either case,
 *  pq should contain a current candidate for y with key at most δ(y).
 *
 *  Since all edge weights are non-negative and y appears before u on path P,
 *  reaching y cannot be more expensive than reaching u along the same path:
 *
 *      δ(y) <= δ(u)
 *
 *  By the contradiction assumption:
 *
 *      δ(u) < d
 *
 *  Hence:
 *
 *      δ(y) <= δ(u) < d
 *
 *  So pq should contain a current candidate for y with key smaller than d.
 *
 *  But (d, u) was supposed to be the minimum entry returned by the min-heap.
 *  This is impossible: the heap would have popped that cheaper candidate for y
 *  before popping (d, u).
 *
 *  Contradiction.
 *
 *  Therefore no shorter path to u exists, so:
 *
 *      d == δ(u)
 *
 *  and it is safe to settle u.
 *
 *  The algorithm then processes u's outgoing edges and performs the usual
 *  relaxations:
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
 *  Dijkstra's algorithm behaves like a wave expanding from the source.
 *
 *  Settled vertices form a region for which the final shortest distances are
 *  already known. The heap stores candidates for the next vertices on the
 *  boundary of that region.
 *
 *  When a current entry (d, u) is popped from the heap, u is the cheapest known
 *  candidate for expanding the settled region.
 *
 *  If there were a shorter path to u, that path would have to cross from the
 *  settled region into the unsettled region through some edge:
 *
 *      settled region              unsettled region
 *
 *      k -> ... -> x ------------> y -> ... -> u
 *                 last settled     first unsettled
 *
 *  Since x was already settled, edge x -> y was already processed. And if the
 *  entire path to u were cheaper than d, then the prefix of that path reaching y
 *  would also be cheaper than d, because y appears earlier on the path and edge
 *  weights are non-negative.
 *
 *  Therefore the heap would have to contain a candidate cheaper than (d, u).
 *  But the heap has just returned (d, u) as the minimum. Contradiction.
 *
 *  This is why, after popping a current entry (d, u), dist[u] is final.
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
 *  We must not skip d == dist[u]. A current extraction of u has exactly
 *  d == dist[u], and this is the moment when u becomes settled and its outgoing
 *  edges must be relaxed.
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
 *  - Initializing dist and scanning it at the end take Θ(V).
 *  - Each successful relaxation pushes one heap entry.
 *  - There are O(E) pushed entries and therefore O(E) pops.
 *  - Each heap operation costs O(log H), where H is the current heap size.
 *    In this no-decrease-key variant, H can be O(E), so the heap work is
 *    directly bounded by O(E log E).
 *
 *    For a simple graph, E <= V^2, hence log E <= 2 log V. Therefore the heap
 *    work is usually written as O(E log V).
 *
 *  Overall: O(V + E log V).
 *
 *  This is often also written as O((V + E) log V), which is a looser but common
 *  upper bound for Dijkstra with a binary heap.
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
