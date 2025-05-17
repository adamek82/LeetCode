#include "PacificAtlanticWaterFlow_417.h"

vector<vector<int>> PacificAtlanticWaterFlow_417::pacificAtlantic(vector<vector<int>> &heights)
{
    int rows = heights.size();
    int cols = heights[0].size();

    vector<vector<bool>> pacific(rows, vector<bool>(cols, false));
    vector<vector<bool>> atlantic(rows, vector<bool>(cols, false));

    queue<pair<int, int>> pacificQueue;
    queue<pair<int, int>> atlanticQueue;

    // Initialize queues with border cells
    for (int i = 0; i < rows; ++i) {
        pacificQueue.push({i, 0});
        atlanticQueue.push({i, cols - 1});
        pacific[i][0] = true;
        atlantic[i][cols - 1] = true;
    }
    for (int j = 0; j < cols; ++j) {
        pacificQueue.push({0, j});
        atlanticQueue.push({rows - 1, j});
        pacific[0][j] = true;
        atlantic[rows - 1][j] = true;
    }

    // Perform BFS for each ocean
    bfs(heights, pacificQueue, pacific);
    bfs(heights, atlanticQueue, atlantic);

    // Find cells that can flow to both oceans
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

void PacificAtlanticWaterFlow_417::bfs(const vector<vector<int>> &heights, queue<pair<int, int>> &q,
    vector<vector<bool>> &visited)
{
    int rows = heights.size();
    int cols = heights[0].size();
    vector<int> directions = {-1, 0, 1, 0, -1}; // Used to calculate neighbors

    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();

        for (int d = 0; d < 4; ++d) {
            int nx = x + directions[d];
            int ny = y + directions[d + 1];

            if (nx >= 0 && nx < rows && ny >= 0 && ny < cols && !visited[nx][ny] && heights[nx][ny] >= heights[x][y]) {
                visited[nx][ny] = true;
                q.push({nx, ny});
            }
        }
    }
}
