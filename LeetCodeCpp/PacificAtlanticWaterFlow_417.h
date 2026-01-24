#pragma once
#include <vector>
#include <queue>
#include <utility>

using namespace std;

class PacificAtlanticWaterFlow_417 {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights);
private:
    void bfs(const vector<vector<int>>& heights, queue<pair<int, int>>& q, vector<vector<bool>>& visited);
};
