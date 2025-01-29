#pragma once
#include <vector>
#include <unordered_map>
#include "GraphNode.h"

class CloneGraph_133 {
public:
    GraphNode<int>* cloneGraph(GraphNode<int>* node);
private:
    // A map from original node to its clone
    // Note: This is specialized for Node<int>
    std::unordered_map<GraphNode<int>*, GraphNode<int>*> cloned;

    // Private DFS that clones the node and its neighbors
    GraphNode<int>* dfs(GraphNode<int>* node);
};
