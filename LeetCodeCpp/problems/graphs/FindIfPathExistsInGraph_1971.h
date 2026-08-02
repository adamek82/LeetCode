#pragma once

#include <vector>

class FindIfPathExistsInGraph_1971 {
public:
    bool validPathRecursiveDFS(int n,
                               const std::vector<std::vector<int>>& edges,
                               int source,
                               int destination);

    bool validPathIterativeDFS(int n,
                               const std::vector<std::vector<int>>& edges,
                               int source,
                               int destination);

    bool validPathBFS(int n,
                      const std::vector<std::vector<int>>& edges,
                      int source,
                      int destination);

    bool validPathUnionFind(int n,
                            const std::vector<std::vector<int>>& edges,
                            int source,
                            int destination);

private:
    bool recursive_dfs(int node,
                       int destination,
                       const std::vector<std::vector<int>>& graph,
                       std::vector<int>& visited);
};
