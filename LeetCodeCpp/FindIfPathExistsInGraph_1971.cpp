#include "FindIfPathExistsInGraph_1971.h"

bool FindIfPathExistsInGraph_1971::validPath(int n, std::vector<std::vector<int>>& edges, int source, int destination) {
    if (source == destination) return true;

    // Create an adjacency list using a vector of vectors
    std::vector<std::vector<int>> graph(n);
    for (const auto& edge : edges) {
        graph[edge[0]].push_back(edge[1]);
        graph[edge[1]].push_back(edge[0]);
    }

    // Use a vector to mark visited nodes
    std::vector<int> visited(n, 0);
    visited[source] = 1;

    return dfs(source, destination, graph, visited);
}

bool FindIfPathExistsInGraph_1971::dfs(int node, int destination, std::vector<std::vector<int>>& graph, std::vector<int>& visited) {
    if (node == destination) return true;

    for (int neighbor : graph[node]) {
        if (!visited[neighbor]) {
            visited[neighbor] = 1;
            if (dfs(neighbor, destination, graph, visited)) return true;
        }
    }
    return false;
}