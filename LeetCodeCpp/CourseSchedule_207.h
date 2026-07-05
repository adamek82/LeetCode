#pragma once

#include <vector>

class CourseSchedule_207 {
public:
    bool canFinishDFS(int numCourses, const std::vector<std::vector<int>>& prerequisites);
    bool canFinishKahns(int numCourses, const std::vector<std::vector<int>>& prerequisites);

private:
    enum class State { UNVISITED, VISITING, VISITED };

    bool dfs(int node,
             const std::vector<std::vector<int>>& graph,
             std::vector<State>& states);
};
