#include "FindSafestPathInGrid_2812.h"

#include <algorithm>
#include <functional>
#include <queue>
#include <tuple>
#include <vector>

using namespace std;

int FindSafestPathInGrid_2812::maximumSafenessFactor(vector<vector<int>>& grid)
{
    const int n = static_cast<int>(grid.size());

    vector<vector<int>> dist(n, vector<int>(n, INF));
    queue<Point> q;

    // Multi-source BFS: distance from each cell to the nearest thief.
    for (int r = 0; r < n; ++r) {
        for (int c = 0; c < n; ++c) {
            if (grid[r][c] == 1) {
                dist[r][c] = 0;
                q.emplace(r, c);
            }
        }
    }

    while (!q.empty()) {
        auto [r, c] = q.front();
        q.pop();

        for (const auto& [dr, dc] : directions) {
            const int nr = r + dr;
            const int nc = c + dc;

            if (nr < 0 || nr >= n || nc < 0 || nc >= n) {
                continue;
            }

            if (dist[nr][nc] > dist[r][c] + 1) {
                dist[nr][nc] = dist[r][c] + 1;
                q.emplace(nr, nc);
            }
        }
    }

    using State = tuple<int, int, int>; // {safeness, row, col}

    vector<vector<int>> best(n, vector<int>(n, -1));
    priority_queue<State> pq;

    best[0][0] = dist[0][0];
    pq.emplace(best[0][0], 0, 0);

    // Widest-path search: maximize the minimum safeness value along the path.
    while (!pq.empty()) {
        auto [safe, r, c] = pq.top();
        pq.pop();

        if (safe < best[r][c]) {
            continue;
        }

        if (r == n - 1 && c == n - 1) {
            return safe;
        }

        for (const auto& [dr, dc] : directions) {
            const int nr = r + dr;
            const int nc = c + dc;

            if (nr < 0 || nr >= n || nc < 0 || nc >= n) {
                continue;
            }

            const int nextSafe = min(safe, dist[nr][nc]);

            if (nextSafe > best[nr][nc]) {
                best[nr][nc] = nextSafe;
                pq.emplace(nextSafe, nr, nc);
            }
        }
    }

    return 0;
}
