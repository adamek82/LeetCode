#include "CourseScheduleII_210.h"

std::vector<int> CourseScheduleII_210::findOrder(int numCourses, std::vector<std::vector<int>> &prerequisites)
{
    std::vector<int> order;
    std::unordered_map<int, std::vector<int>> graph;
    
    for (const auto& prereq : prerequisites) {
        int course = prereq[0], pre = prereq[1];
        graph[course].push_back(pre);
    }

    enum State { UNVISITED, VISITING, VISITED };
    std::vector<State> states(numCourses, UNVISITED);

    std::function<bool(int)> dfs = [&](int course) {
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
