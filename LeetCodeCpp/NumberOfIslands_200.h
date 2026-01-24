#pragma once
#include <vector>

using namespace std;

class NumberOfIslands_200 {
public:
    int numIslands(vector<vector<char>>& grid);
private:
    void dfs(vector<vector<char>>& grid, int i, int j);
};
