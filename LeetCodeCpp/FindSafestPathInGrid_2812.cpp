#include "FindSafestPathInGrid_2812.h"
#include <queue>

int FindSafestPathInGrid_2812::maximumSafenessFactor(vector<vector<int>>& grid) {
    int n = grid.size();
    vector<vector<int>> dist(n, vector<int>(n, INF));
    queue<pii> q;

    /* ---------- Step 1: multi-source BFS ---------- */
    for (int r = 0; r < n; ++r)
        for (int c = 0; c < n; ++c)
            if (grid[r][c] == 1) {          // thief
                dist[r][c] = 0;
                q.emplace(r,c);
            }

    while (!q.empty()) {
        auto [r,c] = q.front(); q.pop();
        for (auto [dr, dc] : directions) {
            int nr = r + dr, nc = c + dc;
            if (nr<0 || nr>=n || nc<0 || nc>=n) continue;
            if (dist[nr][nc] > dist[r][c] + 1) {
                dist[nr][nc] = dist[r][c] + 1;
                q.emplace(nr,nc);
            }
        }
    }

    /* ---------- Step 2: widest-path search ---------- */
    vector<vector<int>> best(n, vector<int>(n, -1));
    using State = tuple<int,int,int>;                 // (bottleneck, r, c)
    int initial = dist[0][0];
    best[0][0] = initial;
    priority_queue<State> pq{ less<State>(), { {initial, 0, 0} } };     // in-place initialization

    while (!pq.empty()) {
        auto [safe, r, c] = pq.top(); pq.pop();
        if (r == n-1 && c == n-1) return safe;        // optimal reached
        if (safe < best[r][c]) continue;              // outdated entry
        for (auto [dr, dc] : directions) {
            int nr = r + dr, nc = c + dc;
            if (nr<0 || nr>=n || nc<0 || nc>=n) continue;
            int nsafe = min(safe, dist[nr][nc]);
            if (nsafe > best[nr][nc]) {
                best[nr][nc] = nsafe;
                pq.emplace(nsafe, nr, nc);
            }
        }
    }
    return 0;                                         // grid always has a thief, so unreachable only logically
}
