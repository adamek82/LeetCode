#include "IslandPerimeter_463.h"

#include <cstddef>

using namespace std;

int IslandPerimeter_463::islandPerimeter(
    const vector<vector<int>>& grid) const
{
    if (grid.empty() || grid.front().empty()) {
        return 0;
    }

    const size_t rowCount = grid.size();
    const size_t columnCount = grid.front().size();

    int perimeter = 0;

    for (size_t row = 0; row < rowCount; ++row) {
        for (size_t column = 0; column < columnCount; ++column) {
            if (grid[row][column] == 0) {
                continue;
            }

            perimeter += 4;

            if (row > 0 && grid[row - 1][column] == 1) {
                perimeter -= 2;
            }

            if (column > 0 && grid[row][column - 1] == 1) {
                perimeter -= 2;
            }
        }
    }

    return perimeter;
}
