#include "CourseSchedule_207.h"

// ---------- DFS three-state variant (renamed) ---------------------------
bool CourseSchedule_207::canFinishDFS(int numCourses, vector<vector<int>>& prerequisites) {
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
                                        std::vector<std::vector<int>>& prerequisites) {
    // Build adjacency list and in-degree array
    std::vector<std::vector<int>> adj(numCourses);
    std::vector<int> indeg(numCourses, 0);
    for (const auto& p : prerequisites) {
        int course = p[0], pre = p[1];
        adj[pre].push_back(course);            // edge pre → course
        ++indeg[course];
    }

    // Start with all courses that have no prerequisites
    std::queue<int> q;
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
