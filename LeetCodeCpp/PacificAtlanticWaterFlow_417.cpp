#include "PacificAtlanticWaterFlow_417.h"

vector<vector<int>> PacificAtlanticWaterFlow_417::pacificAtlantic(vector<vector<int>> &heights)
{
    if (heights.empty() || heights[0].empty()) return {};

    /*
     * heights.size() is size_t; keep rows/cols as int because
     * we use signed indices and (rows-1)/(cols-1).
     */
    const int rows = static_cast<int>(heights.size());
    const int cols = static_cast<int>(heights[0].size());

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
    /*
     * Defensive guard: bfs() assumes a non-empty grid because it reads heights[0].size().
     * The caller (pacificAtlantic) already checks for an empty input, but keeping this
     * guard makes bfs() safe as a standalone helper and prevents accidental UB if it
     * ever gets reused elsewhere.
     *
     * rows/cols are stored as int even though size() returns size_t, because this BFS
     * uses signed coordinates and signed deltas (nx = x +/- 1, ny = y +/- 1) together
     * with checks like nx >= 0. Using size_t here would complicate the logic and can
     * lead to unsigned underflow bugs.
     *
     * Limitation: assumes grid dimensions fit into int (<= INT_MAX), which holds for
     * typical LeetCode constraints.
     */
    if (heights.empty() || heights[0].empty()) return;

    const int rows = static_cast<int>(heights.size());
    const int cols = static_cast<int>(heights[0].size());
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
