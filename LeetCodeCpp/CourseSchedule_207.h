#pragma once
#include <vector>
#include <unordered_map>

using namespace std;

class CourseSchedule_207 {
public:
    // Enum to track the state of the course in the graph
    enum class State { UNVISITED, VISITING, VISITED };

    // Function to determine if it's possible to finish all courses
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites);

private:
    // Helper function for DFS
    bool dfs(int node, unordered_map<int, vector<int>>& graph, vector<State>& states);
};
