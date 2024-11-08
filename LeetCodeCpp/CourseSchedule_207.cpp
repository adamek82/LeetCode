#include "CourseSchedule_207.h"

bool CourseSchedule_207::canFinish(int numCourses, std::vector<std::vector<int>>& prerequisites) {
    std::unordered_map<int, std::vector<int>> graph;
    for (const auto& pair : prerequisites) {
        graph[pair[0]].push_back(pair[1]);
    }

    std::vector<State> states(numCourses, State::UNVISITED);

    for (int i = 0; i < numCourses; i++) {
        if (!dfs(i, graph, states)) {
            return false;
        }
    }

    return true;
}

bool CourseSchedule_207::dfs(int node, std::unordered_map<int, std::vector<int>>& graph, std::vector<State>& states) {
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