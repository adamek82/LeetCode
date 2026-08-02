#include "CourseScheduleII_210.h"

#include <functional>
#include <queue>
#include <vector>

using namespace std;

vector<int> CourseScheduleII_210::findOrderByDFSTraversal(
    int numCourses,
    vector<vector<int>>& prerequisites)
{
    vector<vector<int>> graph(numCourses);
    for (const auto& p : prerequisites) {
        const int course = p[0];
        const int pre = p[1];

        graph[course].push_back(pre);
    }

    enum State { UNVISITED, VISITING, VISITED };
    vector<State> states(numCourses, UNVISITED);
    vector<int> order;

    // Recursive lambda kept here to keep the DFS local to this variant.
    function<bool(int)> dfs = [&](int course) {
        if (states[course] == VISITING) {
            return false;
        }

        if (states[course] == VISITED) {
            return true;
        }

        states[course] = VISITING;

        for (int pre : graph[course]) {
            if (!dfs(pre)) {
                return false;
            }
        }

        states[course] = VISITED;

        // With course -> prerequisite edges, DFS postorder already gives prerequisite-first order.
        order.push_back(course);

        return true;
    };

    for (int i = 0; i < numCourses; ++i) {
        if (!dfs(i)) {
            return {};
        }
    }

    return order;
}

vector<int> CourseScheduleII_210::findOrderByKahnsAlgorithm(
    int numCourses,
    vector<vector<int>>& prerequisites)
{
    vector<vector<int>> graph(numCourses);
    vector<int> inDegree(numCourses, 0);

    for (const auto& p : prerequisites) {
        const int course = p[0];
        const int pre = p[1];

        // Kahn needs prerequisite -> course so inDegree[course] counts remaining prerequisites.
        graph[pre].push_back(course);
        ++inDegree[course];
    }

    queue<int> q;
    for (int i = 0; i < numCourses; ++i) {
        if (inDegree[i] == 0) {
            q.push(i);
        }
    }

    vector<int> order;

    while (!q.empty()) {
        const int course = q.front();
        q.pop();

        order.push_back(course);

        for (int next : graph[course]) {
            if (--inDegree[next] == 0) {
                q.push(next);
            }
        }
    }

    return static_cast<int>(order.size()) == numCourses ? order : vector<int>();
}
