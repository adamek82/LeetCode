#pragma once
#include <vector>
#include <unordered_map>

using namespace std;

class CourseSchedule_207 {
public:
    // Enum to track the state of the course in the graph
    enum class State { UNVISITED, VISITING, VISITED };

    // DFS-based three-state algorithm (formerly canFinish)
    bool canFinishDFS(int numCourses, const vector<vector<int>>& prerequisites);

    // Kahn’s BFS / topological-sort algorithm
    bool canFinishKahns(int numCourses, const vector<vector<int>>& prerequisites);

private:
    // Helper for the DFS variant
    bool dfs(int node, unordered_map<int, vector<int>>& graph, vector<State>& states);
};
