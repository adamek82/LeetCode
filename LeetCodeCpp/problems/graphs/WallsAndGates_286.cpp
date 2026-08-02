#include "WallsAndGates_286.h"

#include <array>
#include <limits>
#include <queue>
#include <utility>

namespace {

constexpr int EMPTY_ROOM = numeric_limits<int>::max();

constexpr array<pair<int, int>, 4> DIRECTIONS = {{
    {0, 1},
    {1, 0},
    {0, -1},
    {-1, 0},
}};

} // namespace

void WallsAndGates_286::wallsAndGates(vector<vector<int>>& rooms)
{
    if (rooms.empty() || rooms.front().empty()) {
        return;
    }

    const int rowCount = static_cast<int>(rooms.size());
    const int colCount = static_cast<int>(rooms.front().size());

    queue<pair<int, int>> cells;

    for (int row = 0; row < rowCount; ++row) {
        for (int col = 0; col < colCount; ++col) {
            if (rooms[row][col] == 0) {
                cells.emplace(row, col);
            }
        }
    }

    while (!cells.empty()) {
        const auto [row, col] = cells.front();
        cells.pop();

        for (const auto [rowOffset, colOffset] : DIRECTIONS) {
            const int nextRow = row + rowOffset;
            const int nextCol = col + colOffset;

            if (nextRow < 0 || nextRow >= rowCount ||
                nextCol < 0 || nextCol >= colCount ||
                rooms[nextRow][nextCol] != EMPTY_ROOM) {
                continue;
            }

            rooms[nextRow][nextCol] = rooms[row][col] + 1;
            cells.emplace(nextRow, nextCol);
        }
    }
}
