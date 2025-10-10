#include "CloneGraph_133.h"
#include "GraphNode.h"

/*
 * Algorithm: DFS + memoization to deep-clone an undirected graph (handles cycles)
 * -------------------------------------------------------------------------------
 * Problem restatement (LC 133):
 *   Given a reference to a node in a graph, return a deep copy of the connected component
 *   reachable from that node. Multiple edges and cycles may exist.
 *
 * Approach:
 *   - Perform DFS from the input node. Maintain a hash map `cloned` from original-node*
 *     to clone-node* (memo).
 *   - On first visit of an original node `u`, allocate its clone `u'` (copying `val` only),
 *     insert {u → u'} into `cloned`, then recursively clone each neighbor v and append the
 *     returned clone v' to `u'->neighbors`.
 *   - If a node `u` is encountered again (cycle / shared neighbor), return `cloned[u]`
 *     immediately without re-cloning.
 *
 * Key details (why this handles cycles and shared structure):
 *   - Insert {u → u'} into `cloned` *before* recursing to neighbors. This guarantees that
 *     encountering `u` again during the same DFS (e.g., cycles, self-loops) returns the
 *     already-created clone and prevents infinite recursion and duplicate nodes.
 *   - Each original node is cloned exactly once; all references in the clone graph point
 *     to the unique clones recorded in `cloned`, preserving adjacency structure.
 *
 * Correctness (sketch):
 *   - Soundness: For every original edge (u, v), the algorithm appends the clone v' to u'’s
 *     neighbor list (and vice versa for undirected input when traversed), so edges are preserved.
 *     Because `cloned` returns the same v' for all appearances of v, shared neighbors remain shared.
 *   - Termination: Since we memoize on first visit and never revisit for cloning, the recursion
 *     over a finite graph finishes even in the presence of cycles or self-loops.
 *   - Completeness: Starting from the given node, DFS reaches every vertex in its connected component;
 *     thus every reachable vertex gets exactly one clone and all incident edges are reconstructed.
 *
 * Complexity:
 *   Let V be the number of nodes reachable from `node`, E the number of edges among them.
 *   - Time: O(V + E). Each node is cloned once; each adjacency is traversed once.
 *   - Space: O(V) for the `cloned` map and O(V) worst-case recursion stack depth.
 *
 * Notes:
 *   - `cloned.clear()` makes the per-instance memo fresh for each top-level call.
 *   - Returns nullptr if input `node` is nullptr (empty graph).
 *   - For very deep graphs, an explicit stack (iterative DFS/BFS) avoids call-stack limits.
 */
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