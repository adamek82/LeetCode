#include "ShortestPathInBinaryMatrix_1091.h"

int ShortestPathInBinaryMatrix_1091::shortestPathBinaryMatrix(vector<vector<int>> &grid)
{
    const int n = grid.size();
    if (n == 0 || grid[0][0] || grid[n - 1][n - 1]) return -1;

    /*  queue seeded with the start cell (0,0) in one shot             */
    queue<pair<int,int>> q{{{0, 0}}};
    grid[0][0] = 1;                    // mark distance of the start

    /*  8-directional neighborhood in a single constexpr array         */
    static constexpr array<pair<int,int>,8> kDir{{
        {-1,-1},{-1,0},{-1,1},
        { 0,-1},       { 0,1},
        { 1,-1},{ 1,0},{ 1,1}
    }};

    while (!q.empty()) {
        auto [r, c] = q.front(); q.pop();
        int dist = grid[r][c];

        if (r == n - 1 && c == n - 1) return dist;   // reached goal

        for (auto [dr, dc] : kDir) {
            int nr = r + dr, nc = c + dc;
            if (nr < 0 || nc < 0 || nr >= n || nc >= n) continue;
            if (grid[nr][nc] != 0) continue;          // blocked or visited
            grid[nr][nc] = dist + 1;
            q.emplace(nr, nc);
        }
    }
    return -1;   // no clear path
}
