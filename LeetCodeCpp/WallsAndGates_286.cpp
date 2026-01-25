#include "WallsAndGates_286.h"
#include <queue>


void WallsAndGates_286::wallsAndGates(vector<vector<int>> &rooms)
{
    if (rooms.empty() || rooms[0].empty()) return;

    const int m = static_cast<int>(rooms.size());
    const int n = static_cast<int>(rooms[0].size());
    queue<pair<int,int>> q;

    // 1️⃣ Load all gates into the queue (multi-source BFS start points)
    for (int r = 0; r < m; ++r) {
        for (int c = 0; c < n; ++c) {
            if (rooms[r][c] == 0) {
                q.emplace(r, c);
            }
        }
    }

    // 2️⃣ BFS expansion: first time we reach a room, we've found its
    //    shortest distance to any gate.
    while (!q.empty()) {
        auto [r, c] = q.front();
        q.pop();

        for (auto [dr, dc] : directions) {
            int nr = r + dr;
            int nc = c + dc;

            // Skip out-of-bounds, walls, and already-visited cells
            if (nr < 0 || nr >= m || nc < 0 || nc >= n ||
                rooms[nr][nc] != INF)
                continue;

            rooms[nr][nc] = rooms[r][c] + 1;  // relax distance
            q.emplace(nr, nc);
        }
    }
}
