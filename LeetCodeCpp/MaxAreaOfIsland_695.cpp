#include "MaxAreaOfIsland_695.h"

int MaxAreaOfIsland_695::maxAreaOfIsland(std::vector<std::vector<int>> &grid)
{
    int m = grid.size();
    int n = grid[0].size();
    int maxArea = 0;

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (grid[i][j] == 1) {
                maxArea = std::max(maxArea, dfs(grid, i, j));
            }
        }
    }

    return maxArea;
}

int MaxAreaOfIsland_695::dfs(std::vector<std::vector<int>> &grid, int i, int j)
{
    // Directions for moving in the grid (right, left, down, up)
    static const std::vector<std::pair<int, int>> directions = {
        {0, 1}, {0, -1}, {1, 0}, {-1, 0}
    };

    if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] != 1) {
        return 0;
    }

    grid[i][j] = 0; // Mark as visited
    int area = 1;
    for (const auto& dir : directions) {
        int ni = i + dir.first;
        int nj = j + dir.second;
        area += dfs(grid, ni, nj);
    }
    return area;
}
