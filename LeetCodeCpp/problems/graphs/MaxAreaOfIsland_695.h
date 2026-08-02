#pragma once

#include <vector>

class MaxAreaOfIsland_695 {
public:
    int maxAreaOfIslandRecursive(std::vector<std::vector<int>>& grid);
    int maxAreaOfIslandIterative(std::vector<std::vector<int>>& grid);

private:
    int dfsRecursive(std::vector<std::vector<int>>& grid, int i, int j);
    int floodFillIterative(std::vector<std::vector<int>>& grid, int m, int n, int r, int c);
};
