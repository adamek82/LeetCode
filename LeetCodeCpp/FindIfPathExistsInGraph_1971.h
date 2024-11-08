#pragma once
#include <vector>

class FindIfPathExistsInGraph_1971 {
public:
    // Determines if there is a valid path from 'source' to 'destination' in the graph
    bool validPath(int n, std::vector<std::vector<int>>& edges, int source, int destination);

private:
    // Helper function for performing DFS on the graph
    bool dfs(int node, int destination, std::vector<std::vector<int>>& graph, std::vector<int>& visited);
};