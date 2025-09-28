#include "GraphUtils.h"

namespace {

/*
 * DFS helper for isomorphism; maps nodes from original -> cloned.
 * Neighbor order is compared index-by-index (stable adjacency).
 */
static bool dfsIso(GraphNode<int>* n1,
                   GraphNode<int>* n2,
                   unordered_map<GraphNode<int>*, GraphNode<int>*>& visited)
{
    if (!n1 || !n2) return n1 == n2;
    if (n1->val != n2->val) return false;

    auto it = visited.find(n1);
    if (it != visited.end()) return it->second == n2;

    visited[n1] = n2;

    if (n1->neighbors.size() != n2->neighbors.size()) return false;
    for (size_t i = 0; i < n1->neighbors.size(); ++i) {
        if (!dfsIso(n1->neighbors[i], n2->neighbors[i], visited)) return false;
    }
    return true;
}

} // anonymous namespace

namespace GraphUtils {

GraphNode<int>* buildGraph(const vector<vector<int>>& adjList) {
    if (adjList.empty()) return nullptr;

    unordered_map<int, GraphNode<int>*> nodeMap;
    const int n = static_cast<int>(adjList.size());

    // Create all nodes [1..n] first (stable addresses, stable order)
    for (int i = 1; i <= n; ++i) nodeMap[i] = new GraphNode<int>(i);

    // Wire neighbors according to the adjacency list
    for (int i = 0; i < n; ++i) {
        auto* u = nodeMap[i + 1];
        for (int v : adjList[i]) {
            // Lazily allow references beyond [1..n] if present in adjList
            if (!nodeMap.count(v)) nodeMap[v] = new GraphNode<int>(v);
            u->neighbors.push_back(nodeMap[v]);
        }
    }

    return nodeMap[1]; // entry point
}

bool areGraphsIsomorphic(GraphNode<int>* original, GraphNode<int>* cloned) {
    if (!original && !cloned) return true;
    if (!original || !cloned) return false;
    if (original->val != cloned->val) return false;

    unordered_map<GraphNode<int>*, GraphNode<int>*> visited;
    return dfsIso(original, cloned, visited);
}

void freeGraph(GraphNode<int>* start) {
    if (!start) return;
    unordered_set<GraphNode<int>*> seen;
    vector<GraphNode<int>*> stack;
    stack.push_back(start);

    // Collect all reachable nodes (guard against cycles)
    while (!stack.empty()) {
        GraphNode<int>* u = stack.back(); stack.pop_back();
        if (!u || seen.count(u)) continue;
        seen.insert(u);
        for (auto* v : u->neighbors) {
            if (v && !seen.count(v)) stack.push_back(v);
        }
    }

    // Free once each
    for (auto* node : seen) delete node;
}

} // namespace GraphUtils
