#include "CourseScheduleII_210.h"
#include <unordered_map>
#include <functional>
#include <queue>

/*
 * Incremental notes vs CourseSchedule_207 (DFS cycle check)
 * ---------------------------------------------------------
 * Goal difference:
 *   207 asked “can we finish?” (cycle detection). Here (210) we also return a valid course order.
 *
 * Same core mechanics:
 *   - Three-state DFS (UNVISITED / VISITING / VISITED) with cycle detection identical to 207.
 *   - We use a lambda `dfs` instead of a free/member helper, but behavior is the same.
 *
 * Edge orientation & why we don’t reverse:
 *   - We build edges as course -> prerequisite (graph[course].push_back(pre)).
 *   - We push a node into `order` *after* exploring all its neighbors (postorder).
 *   - For each edge (course -> pre), postorder ensures `pre` is pushed before `course`,
 *     so `order` already satisfies “all prerequisites come earlier”. No final reverse is needed.
 *   - (Contrast: if edges were pre -> course, we would typically reverse the postorder.)
 *
 * Correctness (topological order construction):
 *   - If a cycle exists, we detect VISITING and abort with {} (no order).
 *   - If no cycle exists (DAG), DFS postorder on edges course->pre yields a linear extension:
 *       for every dependency course->pre, `dfs(course)` explores `pre` first,
 *       so `pre` is pushed earlier; thus `order` respects all prerequisites.
 *
 * Complexity:
 *   - Time: O(n + m), where n = numCourses, m = prerequisites.size().
 *   - Space: O(n + m) for the graph, O(n) for states + order, and O(n) worst-case recursion stack.
 *
 * Implementation notes:
 *   - Accessing graph[u] is safe even if u has no outgoing edges (unordered_map::operator[] creates an empty vector).
 *   - Returning {} on cycle matches the problem’s requirement to return an empty ordering when impossible.
 */
vector<int> CourseScheduleII_210::findOrderByDFSTraversal(int numCourses, vector<vector<int>> &prerequisites)
{
    vector<int> order;
    unordered_map<int, vector<int>> graph;

    for (const auto& prereq : prerequisites) {
        int course = prereq[0], pre = prereq[1];
        graph[course].push_back(pre);
    }

    enum State { UNVISITED, VISITING, VISITED };
    vector<State> states(numCourses, UNVISITED);

    function<bool(int)> dfs = [&](int course) {
        if (states[course] == VISITING) return false;
        if (states[course] == VISITED) return true;

        states[course] = VISITING;
        for (int neighbor : graph[course]) {
            if (!dfs(neighbor)) return false;
        }

        states[course] = VISITED;
        order.push_back(course);
        return true;
    };

    for (int i = 0; i < numCourses; ++i) {
        if (!dfs(i)) return {}; // Return empty array if a cycle is detected
    }

    return order;
}

/*
 * Incremental notes vs CourseSchedule_207 (Kahn’s algorithm)
 * ----------------------------------------------------------
 * Goal difference:
 *   207 asked only “can we finish?”. Here (210) we must also return a valid topological order.
 *
 * Orientation and data:
 *   - Edges are prerequisite → course (pre -> course), so inDegree[v] counts remaining prerequisites.
 *   - Queue initially holds all courses with inDegree == 0 (ready to take).
 *
 * Procedure (Kahn):
 *   1) Build adj lists with pre -> course and compute inDegree.
 *   2) Push every inDegree==0 node to the queue.
 *   3) While queue not empty:
 *        - Pop u, append u to `order` (it is next in topo order).
 *        - For each v in adj[u], decrement inDegree[v]; if it hits 0, push v.
 *   4) If we appended all n nodes, return `order`; else return {} (cycle present).
 *
 * Why this yields a correct order:
 *   - A node enters the queue only when all its prerequisites were already appended to `order`,
 *     so appending maintains the prerequisite-before-dependent constraint.
 *   - If a cycle exists, nodes on the cycle never reach inDegree 0, queue stalls early,
 *     and order.size() < n detects impossibility.
 *
 * Complexity:
 *   - Time: O(n + m), with n = numCourses, m = prerequisites.size().
 *   - Space: O(n + m) for graph + inDegree + queue.
 */
vector<int> CourseScheduleII_210::findOrderByKahnsAlgorithm(int numCourses, vector<vector<int>> &prerequisites)
{
    vector<int> order;
    vector<int> inDegree(numCourses, 0);
    vector<vector<int>> graph(numCourses); // Graph with numCourses empty vectors

    // Build the graph and calculate in-degrees
    for (const auto& pre : prerequisites) {
        graph[pre[1]].push_back(pre[0]);
        inDegree[pre[0]]++;
    }

    // Queue to process courses with no prerequisites
    queue<int> queue;
    for (int i = 0; i < numCourses; ++i) {
        if (inDegree[i] == 0) {
            queue.push(i); // Add courses with no prerequisites
        }
    }

    // Process courses in topological order
    while (!queue.empty()) {
        int node = queue.front();
        queue.pop();
        order.push_back(node);

        for (int target : graph[node]) {
            inDegree[target]--;
            if (inDegree[target] == 0) {
                queue.push(target);
            }
        }
    }

    // Check if all courses are processed
    return order.size() == numCourses ? order : vector<int>();
}
