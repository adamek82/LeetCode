#pragma once
#include "GraphNode.h"
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

namespace GraphUtils {

    /*
     * Builds a directed/undirected graph from 1-based adjacency list.
     * For i in [1..adjList.size()], edges (i -> adjList[i-1][*]) are created.
     * Returns the node with value = 1 (entry point), or nullptr if adjList empty.
     */
     GraphNode<int>* buildGraph(const vector<vector<int>>& adjList);

    /*
     * Checks graph isomorphism by walking two graphs in lockstep starting
     * at the given entry nodes. Assumes neighbor order matters (like your tests).
     * Returns true iff structure and node values match under a consistent mapping.
     */
    bool areGraphsIsomorphic(GraphNode<int>* original, GraphNode<int>* cloned);

    /*
     * Frees all nodes reachable from `start` (guards against cycles).
     */
    void freeGraph(GraphNode<int>* start);
}
