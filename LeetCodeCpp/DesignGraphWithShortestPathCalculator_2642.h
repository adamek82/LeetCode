#pragma once
#include <vector>
#include <utility>

using namespace std;

/*  LeetCode 2642 – Design Graph With Shortest Path Calculator
 *  ----------------------------------------------------------
 *  • Adjacency list: vector<vector<Edge>>
 *  • Dijkstra with lazy-delete (“stale entry”) check
 */
class Graph {
    using DistPair = pair<long long,int>;   // (distance, node) – for priority-queue
    using Edge     = pair<int,int>;         // (to, cost)       – stored in the graph

    int n;
    vector<vector<Edge>> adj;               // adj[u] = {v, cost}

public:
    Graph(int n, vector<vector<int>>& edges);
    void addEdge(vector<int> edge);
    int  shortestPath(int node1, int node2);
};
