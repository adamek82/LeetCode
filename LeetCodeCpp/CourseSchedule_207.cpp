#include "CourseSchedule_207.h"

/*
 * Algorithm: DFS with three-state coloring to detect cycles in a directed graph
 * ----------------------------------------------------------------------------
 * Problem restatement:
 *   Each pair [a, b] means: course a depends on course b (edge a -> b). We can finish
 *   all courses iff the prerequisite graph is a DAG (i.e., has no directed cycle).
 *
 * Graph model:
 *   - Build adjacency list 'graph' where graph[u] lists all v such that u -> v (u depends on v).
 *   - Using unordered_map<int, vector<int>> allows sparse storage; reading graph[x] is safe
 *     even if x has no outgoing edges (it yields an empty vector by default).
 *
 * State machine (coloring):
 *   - UNVISITED: node not seen yet.
 *   - VISITING: node is on the current DFS recursion stack (gray).
 *   - VISITED: node and its entire prerequisite subtree were fully explored (black), and no
 *     cycle was found in that subtree.
 *
 * Core procedure (dfs(node)):
 *   1) If states[node] == VISITING, we discovered a back-edge to an ancestor in the current
 *      recursion stack ⇒ a directed cycle exists ⇒ return false.
 *   2) If states[node] == VISITED, this subtree was already proven acyclic ⇒ return true.
 *   3) Mark node as VISITING, then recursively dfs() all neighbors (its prerequisites).
 *      If any recursive call returns false, propagate false (cycle detected).
 *   4) After exploring all neighbors successfully, mark node as VISITED and return true.
 *
 * Why this is correct (proof sketch):
 *   - Soundness (no false positives): The only way we return false is when we see a node
 *     in VISITING state. VISITING means the node is on the current recursion stack, so
 *     encountering it again implies a directed path from that node back to itself
 *     (a back-edge). This is exactly the definition of a cycle in a DFS traversal.
 *   - Completeness (no missed cycles): Suppose a directed cycle exists. Start DFS from any
 *     vertex that can reach the cycle (or from a cycle vertex itself). DFS will eventually
 *     enter the cycle and, while unwinding, revisit a node that is still VISITING
 *     (on the stack), triggering the detection above. Thus every cycle is detected.
 *   - DAG acceptance: If dfs(node) returns true for all nodes, then no call ever observed
 *     states[·] == VISITING, so no back-edge exists; DFS back-edges characterize cycles
 *     in directed graphs. Therefore the graph is acyclic (a DAG), meaning a valid
 *     topological order exists and all courses can be finished.
 *
 * Why we start DFS from every node:
 *   The graph may be disconnected or consist of multiple weakly connected components.
 *   Looping i = 0..numCourses-1 ensures every vertex is either visited directly or via
 *   reachability from another starting point, so cycles anywhere are found.
 *
 * Complexity:
 *   Let n = numCourses and m = prerequisites.size().
 *   - Time: O(n + m) expected. Each vertex is colored UNVISITED→VISITING→VISITED once,
 *     and each directed edge is examined at most once. (Hash map lookups/insertions are
 *     expected O(1); pathological hash collisions could degrade, but average-case is O(1).)
 *   - Space: O(n + m).
 *       • Adjacency storage: O(m).
 *       • State array: O(n).
 *       • Recursion stack: O(h) where h ≤ n (worst case a chain). So total auxiliary space
 *         is O(n) in the worst case in addition to the graph.
 *
 * Implementation notes:
 *   - The three-state scheme prevents re-exploration of finished subtrees (VISITED) and
 *     detects cycles precisely via VISITING encounters (recursion stack membership).
 *   - Accessing graph[node] without an existence check is safe because unordered_map
 *     default-initializes an empty vector on first access (via operator[]).
 *   - For very deep graphs, consider an explicit stack to avoid potential recursion limits.
 *
 * Additional conclusions / clarifications (why no resetting of `states` is needed):
 *   - The `states` vector is a global memo of progress across all DFS roots: after one DFS
 *     completes, all nodes it touched are permanently VISITED (proved acyclic) and never
 *     need re-exploration. Resetting would discard this information and harm complexity.
 *   - Any existing cycle will be detected from *any* vertex that reaches it: as DFS enters
 *     the cycle, it must eventually revisit a node still marked VISITING, immediately
 *     flagging the cycle—independently of which vertex we started from.
 *   - Upon successful return from a DFS call (no cycle found), the in-DFS invariant is that
 *     no node remains VISITING; outside the call, the outer loop only ever sees nodes as
 *     UNVISITED or VISITED. Hence there is nothing to “clean up” between iterations.
 *   - Consequently, each node transitions UNVISITED→VISITING→VISITED at most once and each
 *     edge is examined at most once, preserving the O(n + m) time bound and correctness.
 */
bool CourseSchedule_207::canFinishDFS(int numCourses, const vector<vector<int>>& prerequisites) {
    unordered_map<int, vector<int>> graph;
    for (const auto& pair : prerequisites) {
        graph[pair[0]].push_back(pair[1]);
    }

    vector<State> states(numCourses, State::UNVISITED);

    for (int i = 0; i < numCourses; i++) {
        if (!dfs(i, graph, states)) {
            return false;
        }
    }

    return true;
}

bool CourseSchedule_207::dfs(int node, unordered_map<int, vector<int>>& graph, vector<State>& states) {
    if (states[node] == State::VISITING) return false; // Cycle detected
    if (states[node] == State::VISITED) return true;   // Already visited

    states[node] = State::VISITING;

    // No need to check if the node exists, graph[node] is always safe to access
    for (int neighbor : graph[node]) {
        if (!dfs(neighbor, graph, states)) {
            return false;
        }
    }

    states[node] = State::VISITED;
    return true;
}

// ---------- Kahn’s BFS / topological-sort variant -----------------------
bool CourseSchedule_207::canFinishKahns(int numCourses,
                                        const vector<vector<int>>& prerequisites) {
    // Build adjacency list and in-degree array
    vector<vector<int>> adj(numCourses);
    vector<int> indeg(numCourses, 0);
    for (const auto& p : prerequisites) {
        int course = p[0], pre = p[1];
        adj[pre].push_back(course);            // edge pre → course
        ++indeg[course];
    }

    // Start with all courses that have no prerequisites
    queue<int> q;
    for (int i = 0; i < numCourses; ++i)
        if (indeg[i] == 0) q.push(i);

    int visited = 0;
    while (!q.empty()) {
        int cur = q.front(); q.pop();
        ++visited;
        for (int nxt : adj[cur])               // “take” current course
            if (--indeg[nxt] == 0) q.push(nxt);
    }
    return visited == numCourses;              // true ⇔ no cycle
}
