#pragma once

#include <vector>

class CountCompleteComponents_2685 {
public:
    int countCompleteComponents(
        int n,
        const std::vector<std::vector<int>>& edges);

private:
    static void dfs(
        int node,
        const std::vector<std::vector<int>>& graph,
        std::vector<bool>& visited,
        int& vertices,
        int& degreeSum);
};
