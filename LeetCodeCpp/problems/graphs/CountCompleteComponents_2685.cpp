#include "CountCompleteComponents_2685.h"

#include <vector>

using namespace std;

int CountCompleteComponents_2685::countCompleteComponents(
    int n,
    const vector<vector<int>>& edges)
{
    vector<vector<int>> graph(n);

    for (const auto& edge : edges) {
        graph[edge[0]].push_back(edge[1]);
        graph[edge[1]].push_back(edge[0]);
    }

    vector<bool> visited(n);
    int completeComponents = 0;

    for (int node = 0; node < n; ++node) {
        if (visited[node]) {
            continue;
        }

        int vertices = 0;
        int degreeSum = 0;

        dfs(node, graph, visited, vertices, degreeSum);

        if (degreeSum == vertices * (vertices - 1)) {
            ++completeComponents;
        }
    }

    return completeComponents;
}

void CountCompleteComponents_2685::dfs(
    int node,
    const vector<vector<int>>& graph,
    vector<bool>& visited,
    int& vertices,
    int& degreeSum)
{
    visited[node] = true;
    ++vertices;
    degreeSum += static_cast<int>(graph[node].size());

    for (int neighbor : graph[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor, graph, visited, vertices, degreeSum);
        }
    }
}
