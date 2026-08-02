#include "ShortestPathInBinaryMatrix_1091.h"

#include <array>
#include <queue>
#include <utility>
#include <vector>

using namespace std;

int ShortestPathInBinaryMatrix_1091::shortestPathBinaryMatrix(vector<vector<int>>& grid)
{
    if (grid.empty() || grid[0].empty()) {
        return -1;
    }

    const int n = static_cast<int>(grid.size());

    if (grid[0][0] || grid[n - 1][n - 1]) {
        return -1;
    }

    static constexpr array<pair<int, int>, 8> directions{{
        {-1, -1}, {-1, 0}, {-1, 1},
        { 0, -1},          { 0, 1},
        { 1, -1}, { 1, 0}, { 1, 1}
    }};

    queue<pair<int, int>> q;
    q.emplace(0, 0);

    grid[0][0] = 1; // Store distance in-place.

    while (!q.empty()) {
        auto [r, c] = q.front();
        q.pop();

        const int dist = grid[r][c];

        if (r == n - 1 && c == n - 1) {
            return dist;
        }

        for (const auto& [dr, dc] : directions) {
            const int nr = r + dr;
            const int nc = c + dc;

            if (nr < 0 || nr >= n || nc < 0 || nc >= n) {
                continue;
            }

            if (grid[nr][nc] != 0) {
                continue;
            }

            grid[nr][nc] = dist + 1;
            q.emplace(nr, nc);
        }
    }

    return -1;
}
