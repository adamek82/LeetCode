#include "FindIfPathExistsInGraph_1971.h"
#include "UnionFind.h"

bool FindIfPathExistsInGraph_1971::validPathRecursiveDFS(int n, std::vector<std::vector<int>>& edges, int source, int destination) {
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

    return recursive_dfs(source, destination, graph, visited);
}

bool FindIfPathExistsInGraph_1971::validPathIterativeDFS(int n, std::vector<std::vector<int>> &edges, int source, int destination)
{
    if (source == destination) return true;

    // This time we're going to use a hashmap for graph representation
    std::unordered_map<int, std::vector<int>> graph;
        for (const auto& edge : edges) {
        graph[edge[0]].push_back(edge[1]);
        graph[edge[1]].push_back(edge[0]);
    }

    // This time use a hashset to represent visited nodes
    std::unordered_set<int> visited;
    std::stack<int> stack;

    stack.push(source);
    visited.insert(source);

    while (!stack.empty()) {
        int node = stack.top();
        stack.pop();
        if (node == destination) return true;

        for(int nei : graph[node]) {
            if (visited.find(nei) == visited.end()) {
                visited.insert(nei);
                stack.push(nei);
            }
        }
    }

    return false;
}

bool FindIfPathExistsInGraph_1971::validPathBFS(int n, std::vector<std::vector<int>> &edges, int source, int destination)
{
    if (source == destination) return true;

    // This time we're going to use a hashmap for graph representation
    std::unordered_map<int, std::vector<int>> graph;
        for (const auto& edge : edges) {
        graph[edge[0]].push_back(edge[1]);
        graph[edge[1]].push_back(edge[0]);
    }

    // This time use a hashset to represent visited nodes
    std::unordered_set<int> visited;
    std::queue<int> queue;

    queue.push(source);
    visited.insert(source);

    while (!queue.empty()) {
        int node = queue.front();
        queue.pop();
        if (node == destination) return true;

        for(int nei : graph[node]) {
            if (visited.find(nei) == visited.end()) {
                visited.insert(nei);
                queue.push(nei);
            }
        }
    }

    return false;
}

bool FindIfPathExistsInGraph_1971::validPathUnionFind(int n, std::vector<std::vector<int>> &edges, int source, int destination)
{
    UnionFind uf(n);

    // Union all edges
    for (const auto& edge : edges) {
        uf.unionSets(edge[0], edge[1]);
    }

    // Check if source and destination are in the same set
    return uf.find(source) == uf.find(destination);
}

bool FindIfPathExistsInGraph_1971::recursive_dfs(int node, int destination, std::vector<std::vector<int>>& graph, std::vector<int>& visited) {
    if (node == destination) return true;

    for (int neighbor : graph[node]) {
        if (!visited[neighbor]) {
            visited[neighbor] = 1;
            if (recursive_dfs(neighbor, destination, graph, visited)) return true;
        }
    }
    return false;
}