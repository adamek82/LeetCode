#pragma once
#include <vector>

class NumberOfIslands_200 {
public:
    int numIslands(std::vector<std::vector<char>>& grid);
private:
    void dfs(std::vector<std::vector<char>>& grid, int i, int j);
};