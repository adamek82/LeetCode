#include "RottingOranges_994.h"

#include <array>
#include <queue>
#include <utility>
#include <vector>

using namespace std;

int RottingOranges_994::orangesRotting(vector<vector<int>>& grid)
{
    if (grid.empty() || grid[0].empty()) {
        return 0;
    }

    const int m = static_cast<int>(grid.size());
    const int n = static_cast<int>(grid[0].size());

    queue<pair<int, int>> rottenQueue;
    int freshCount = 0;

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (grid[i][j] == static_cast<int>(CellState::ROTTEN)) {
                rottenQueue.emplace(i, j);
            } else if (grid[i][j] == static_cast<int>(CellState::FRESH)) {
                ++freshCount;
            }
        }
    }

    if (freshCount == 0) {
        return 0;
    }

    int minutes = -1;

    static constexpr array<pair<int, int>, 4> directions{{
        {0, 1}, {1, 0}, {0, -1}, {-1, 0}
    }};

    while (!rottenQueue.empty()) {
        const int size = static_cast<int>(rottenQueue.size());
        ++minutes;

        for (int i = 0; i < size; ++i) {
            auto [x, y] = rottenQueue.front();
            rottenQueue.pop();

            for (const auto& [dx, dy] : directions) {
                const int nx = x + dx;
                const int ny = y + dy;

                if (nx >= 0 && nx < m
                    && ny >= 0 && ny < n
                    && grid[nx][ny] == static_cast<int>(CellState::FRESH)) {
                    grid[nx][ny] = static_cast<int>(CellState::ROTTEN);
                    rottenQueue.emplace(nx, ny);
                    --freshCount;
                }
            }
        }
    }

    return freshCount == 0 ? minutes : -1;
}
