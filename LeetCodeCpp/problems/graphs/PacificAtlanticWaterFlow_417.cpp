#include "PacificAtlanticWaterFlow_417.h"

#include <array>
#include <queue>
#include <utility>
#include <vector>

using namespace std;

vector<vector<int>> PacificAtlanticWaterFlow_417::pacificAtlantic(vector<vector<int>>& heights)
{
    if (heights.empty() || heights[0].empty()) {
        return {};
    }

    const int rows = static_cast<int>(heights.size());
    const int cols = static_cast<int>(heights[0].size());

    vector<vector<bool>> pacific(rows, vector<bool>(cols, false));
    vector<vector<bool>> atlantic(rows, vector<bool>(cols, false));

    queue<pair<int, int>> pacificQueue;
    queue<pair<int, int>> atlanticQueue;

    for (int i = 0; i < rows; ++i) {
        pacificQueue.emplace(i, 0);
        atlanticQueue.emplace(i, cols - 1);

        pacific[i][0] = true;
        atlantic[i][cols - 1] = true;
    }

    for (int j = 0; j < cols; ++j) {
        pacificQueue.emplace(0, j);
        atlanticQueue.emplace(rows - 1, j);

        pacific[0][j] = true;
        atlantic[rows - 1][j] = true;
    }

    // Reverse-flow BFS: from ocean borders to cells that can flow into that ocean.
    bfs(heights, pacificQueue, pacific);
    bfs(heights, atlanticQueue, atlantic);

    vector<vector<int>> result;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (pacific[i][j] && atlantic[i][j]) {
                result.push_back({i, j});
            }
        }
    }

    return result;
}

void PacificAtlanticWaterFlow_417::bfs(
    const vector<vector<int>>& heights,
    queue<pair<int, int>>& q,
    vector<vector<bool>>& visited)
{
    static constexpr array<pair<int, int>, 4> directions{{
        {-1, 0}, {1, 0}, {0, -1}, {0, 1}
    }};

    const int rows = static_cast<int>(heights.size());
    const int cols = static_cast<int>(heights[0].size());

    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();

        for (const auto& [dx, dy] : directions) {
            const int nx = x + dx;
            const int ny = y + dy;

            if (nx >= 0 && nx < rows
                && ny >= 0 && ny < cols
                && !visited[nx][ny]
                && heights[nx][ny] >= heights[x][y]) {
                visited[nx][ny] = true;
                q.emplace(nx, ny);
            }
        }
    }
}
