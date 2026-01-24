#include "RottingOranges_994.h"
#include <array>
#include <queue>
#include <utility>

int RottingOranges_994::orangesRotting(vector<vector<int>> &grid)
{
        int m = grid.size();
        int n = grid[0].size();

        queue<pair<int, int>> rottenQueue; // To store the positions of rotten oranges
        int freshCount = 0;

        // Initialize the queue with all rotten oranges and count the fresh ones
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == static_cast<int>(CellState::ROTTEN)) {
                    rottenQueue.push({i, j});
                } else if (grid[i][j] == static_cast<int>(CellState::FRESH)) {
                    ++freshCount;
                }
            }
        }

        // If there are no fresh oranges, return 0
        if (freshCount == 0) return 0;

        int minutes = -1;
        constexpr array<pair<int, int>, 4> directions = {{{0, 1}, {1, 0}, {0, -1}, {-1, 0}}}; // 4 possible directions

        // BFS to propagate rotting effect
        while (!rottenQueue.empty()) {
            int size = rottenQueue.size();
            ++minutes;

            for (int i = 0; i < size; ++i) {
                auto [x, y] = rottenQueue.front();
                rottenQueue.pop();

                for (auto& dir : directions) {
                    int nx = x + dir.first;
                    int ny = y + dir.second;

                    // Check if the neighboring cell is a fresh orange
                    if (nx >= 0 && nx < m && ny >= 0 && ny < n && grid[nx][ny] == static_cast<int>(CellState::FRESH)) {
                        grid[nx][ny] = static_cast<int>(CellState::ROTTEN); // Rot the fresh orange
                        rottenQueue.push({nx, ny});
                        --freshCount;
                    }
                }
            }
        }

        // If there are still fresh oranges, return -1
        return freshCount == 0 ? minutes : -1;
}
