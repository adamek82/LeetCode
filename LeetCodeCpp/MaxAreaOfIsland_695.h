#pragma once
#include <algorithm>
#include <vector>

using namespace std;

class MaxAreaOfIsland_695 {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid);
private:
    int dfs(vector<vector<int>>& grid, int i, int j);
};