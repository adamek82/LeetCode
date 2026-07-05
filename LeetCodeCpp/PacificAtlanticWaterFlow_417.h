#pragma once

#include <queue>
#include <utility>
#include <vector>

class PacificAtlanticWaterFlow_417 {
public:
    std::vector<std::vector<int>> pacificAtlantic(std::vector<std::vector<int>>& heights);

private:
    void bfs(const std::vector<std::vector<int>>& heights,
             std::queue<std::pair<int, int>>& q,
             std::vector<std::vector<bool>>& visited);
};
