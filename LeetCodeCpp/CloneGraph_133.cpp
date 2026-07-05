#include "CloneGraph_133.h"

using namespace std;

GraphNode<int>* CloneGraph_133::cloneGraph(GraphNode<int>* node)
{
    cloned.clear();
    return dfs(node);
}

GraphNode<int>* CloneGraph_133::dfs(GraphNode<int>* node)
{
    if (!node) {
        return nullptr;
    }

    if (cloned.count(node)) {
        return cloned[node];
    }

    GraphNode<int>* copy = new GraphNode<int>(node->val);

    // Memoize before cloning neighbors to handle cycles and self-loops.
    cloned[node] = copy;

    for (auto* neighbor : node->neighbors) {
        copy->neighbors.push_back(dfs(neighbor));
    }

    return copy;
}
