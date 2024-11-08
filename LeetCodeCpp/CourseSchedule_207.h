#pragma once
#include <vector>
#include <unordered_map>

class CourseSchedule_207 {
public:
    // Enum to track the state of the course in the graph
    enum class State { UNVISITED, VISITING, VISITED };

    // Function to determine if it's possible to finish all courses
    bool canFinish(int numCourses, std::vector<std::vector<int>>& prerequisites);

private:
    // Helper function for DFS
    bool dfs(int node, std::unordered_map<int, std::vector<int>>& graph, std::vector<State>& states);
};
