#pragma once
#include <algorithm>
#include <vector>

class MaxAreaOfIsland_695 {
public:
    int maxAreaOfIsland(std::vector<std::vector<int>>& grid);
private:
    int dfs(std::vector<std::vector<int>>& grid, int i, int j);
};