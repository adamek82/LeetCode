#pragma once

#include <utility>
#include <vector>

class Graph {
public:
    Graph(int n, const std::vector<std::vector<int>>& edges);

    void addEdge(const std::vector<int>& edge);
    int shortestPath(int node1, int node2);

private:
    using Edge = std::pair<int, int>;
    using DistPair = std::pair<long long, int>;

    int n;
    std::vector<std::vector<Edge>> adj;
};
