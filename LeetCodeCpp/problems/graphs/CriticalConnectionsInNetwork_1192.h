#pragma once

#include <vector>

class CriticalConnectionsInNetwork_1192 {
public:
    std::vector<std::vector<int>> criticalConnections(
        int n,
        const std::vector<std::vector<int>>& connections);

private:
    std::vector<std::vector<int>> graph;
    std::vector<int> tin;
    std::vector<int> low;
    int timer = 0;

    void dfs(
        int node,
        int parent,
        std::vector<std::vector<int>>& bridges);
};
