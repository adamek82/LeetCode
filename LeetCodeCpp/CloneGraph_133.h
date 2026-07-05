#pragma once

#include "GraphNode.h"

#include <unordered_map>

class CloneGraph_133 {
public:
    GraphNode<int>* cloneGraph(GraphNode<int>* node);

private:
    std::unordered_map<GraphNode<int>*, GraphNode<int>*> cloned;

    GraphNode<int>* dfs(GraphNode<int>* node);
};
