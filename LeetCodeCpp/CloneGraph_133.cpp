#include "CloneGraph_133.h"

GraphNode<int> *CloneGraph_133::cloneGraph(GraphNode<int> *node)
{
    cloned.clear();
    return dfs(node);
}

GraphNode<int> *CloneGraph_133::dfs(GraphNode<int> *node)
{
    if (!node) {
        return nullptr;
    }
    if (cloned.count(node)) {
        return cloned[node];
    }
    // Create new clone using the node's value
    GraphNode<int>* copy = new GraphNode<int>(node->val);
    cloned[node] = copy;

    // Recursively clone neighbors
    for (auto* neighbor : node->neighbors) {
        copy->neighbors.push_back(dfs(neighbor));
    }
    return copy;
}