#include "CourseScheduleII_210.h"

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
