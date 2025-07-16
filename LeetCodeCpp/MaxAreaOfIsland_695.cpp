#include "MaxAreaOfIsland_695.h"

int MaxAreaOfIsland_695::maxAreaOfIslandRecursive(vector<vector<int>> &grid)
{
    int m = grid.size();
    int n = grid[0].size();
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

int MaxAreaOfIsland_695::dfsRecursive(vector<vector<int>> &grid, int i, int j)
{
    // Directions for moving in the grid (right, left, down, up)
    static const vector<pair<int, int>> directions = {
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
        area += dfsRecursive(grid, ni, nj);
    }
    return area;
}

// Iterative DFS, public entry point
int MaxAreaOfIsland_695::maxAreaOfIslandIterative(vector<vector<int>>& grid)
{
    int m = grid.size();
    int n = grid[0].size();
    int best = 0;

    // Directions for moving in the grid (right, left, down, up)
    static const vector<pair<int, int>> directions = {
        {0, 1}, {0, -1}, {1, 0}, {-1, 0}
    };

    for (int r = 0; r < m; ++r)
        for (int c = 0; c < n; ++c)
            if (grid[r][c] == 1)                       // unvisited land
                best = max(best, floodFillIterative(grid, r, c));

    return best;
}

// Helper performing the stack-based flood-fill and returning island area
int MaxAreaOfIsland_695::floodFillIterative(vector<vector<int>>& grid, int r, int c)
{
    int m = grid.size();
    int n = grid[0].size();
    int area = 0;

    // Directions for moving in the grid (right, left, down, up)
    static const vector<pair<int, int>> directions = {
        {0, 1}, {0, -1}, {1, 0}, {-1, 0}
    };

    stack<pair<int,int>> st;
    st.emplace(r, c);
    grid[r][c] = 0;                 // mark visited

    while (!st.empty()) {           // DFS flood-fill
        auto [x, y] = st.top();
        st.pop();
        ++area;

        for (const auto& d : directions) {
            int nx = x + d.first;
            int ny = y + d.second;
            if (nx >= 0 && nx < m && ny >= 0 && ny < n
                && grid[nx][ny] == 1) {
                grid[nx][ny] = 0;   // mark & push
                st.emplace(nx, ny);
            }
        }
    }

    return area;
}