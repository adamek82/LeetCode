#pragma once
#include <vector>
#include <stack>
#include <queue>
#include <unordered_map>
#include <unordered_set>

class FindIfPathExistsInGraph_1971 {
public:
    // Determines if there is a valid path from 'source' to 'destination' in the graph - recursive DFS version
    bool validPathRecursiveDFS(int n, std::vector<std::vector<int>>& edges, int source, int destination);

    // Same as above but using iterative DFS with a stack
    bool validPathIterativeDFS(int n, std::vector<std::vector<int>>& edges, int source, int destination);

    // Perform breadth-first search (BFS) using a classic queue-based implementation
    bool validPathBFS(int n, std::vector<std::vector<int>>& edges, int source, int destination);

    // Check graph connectivity using union-find for 'source' and 'destination'.
    bool validPathUnionFind(int n, std::vector<std::vector<int>>& edges, int source, int destination);

private:
    // Helper function for performing DFS on the graph
    bool recursive_dfs(int node, int destination, std::vector<std::vector<int>>& graph, std::vector<int>& visited);
};