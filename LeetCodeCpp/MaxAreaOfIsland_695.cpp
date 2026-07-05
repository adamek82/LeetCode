#include "MaxAreaOfIsland_695.h"

#include <algorithm>
#include <array>
#include <stack>
#include <utility>
#include <vector>

using namespace std;

// This file intentionally keeps both recursive and iterative DFS variants.
int MaxAreaOfIsland_695::maxAreaOfIslandRecursive(vector<vector<int>>& grid)
{
    if (grid.empty() || grid[0].empty()) {
        return 0;
    }

    const int m = static_cast<int>(grid.size());
    const int n = static_cast<int>(grid[0].size());
    int maxArea = 0;

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (grid[i][j] == 1) {
                maxArea = max(maxArea, dfsRecursive(grid, i, j));
            }
        }
    }

    return maxArea;
}

int MaxAreaOfIsland_695::dfsRecursive(vector<vector<int>>& grid, int i, int j)
{
    const int m = static_cast<int>(grid.size());
    const int n = static_cast<int>(grid[0].size());

    if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] != 1) {
        return 0;
    }

    grid[i][j] = 0; // Mark visited in-place.

    return 1
         + dfsRecursive(grid, i + 1, j)
         + dfsRecursive(grid, i - 1, j)
         + dfsRecursive(grid, i, j + 1)
         + dfsRecursive(grid, i, j - 1);
}

int MaxAreaOfIsland_695::maxAreaOfIslandIterative(vector<vector<int>>& grid)
{
    if (grid.empty() || grid[0].empty()) {
        return 0;
    }

    const int m = static_cast<int>(grid.size());
    const int n = static_cast<int>(grid[0].size());
    int best = 0;

    for (int r = 0; r < m; ++r) {
        for (int c = 0; c < n; ++c) {
            if (grid[r][c] == 1) {
                best = max(best, floodFillIterative(grid, m, n, r, c));
            }
        }
    }

    return best;
}

int MaxAreaOfIsland_695::floodFillIterative(vector<vector<int>>& grid, int m, int n, int r, int c)
{
    static constexpr array<pair<int, int>, 4> directions{{
        {0, 1}, {0, -1}, {1, 0}, {-1, 0}
    }};

    int area = 0;

    // Use vector-backed stack so we can reserve space upfront.
    vector<pair<int, int>> backing;
    backing.reserve(grid.size() * grid[0].size());
    stack<pair<int, int>, vector<pair<int, int>>> st(move(backing));

    st.emplace(r, c);
    grid[r][c] = 0; // Mark visited when pushing to avoid duplicate stack entries.

    while (!st.empty()) {
        auto [x, y] = st.top();
        st.pop();
        ++area;

        for (const auto& [dx, dy] : directions) {
            const int nx = x + dx;
            const int ny = y + dy;

            if (nx >= 0 && nx < m && ny >= 0 && ny < n && grid[nx][ny] == 1) {
                grid[nx][ny] = 0;
                st.emplace(nx, ny);
            }
        }
    }

    return area;
}
