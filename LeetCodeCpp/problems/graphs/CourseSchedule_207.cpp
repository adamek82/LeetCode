#include "CourseSchedule_207.h"

#include <queue>
#include <vector>

using namespace std;

bool CourseSchedule_207::canFinishDFS(
    int numCourses,
    const vector<vector<int>>& prerequisites)
{
    vector<vector<int>> graph(numCourses);
    for (const auto& p : prerequisites) {
        graph[p[0]].push_back(p[1]);
    }

    vector<State> states(numCourses, State::UNVISITED);

    for (int i = 0; i < numCourses; ++i) {
        if (!dfs(i, graph, states)) {
            return false;
        }
    }

    return true;
}

bool CourseSchedule_207::dfs(
    int node,
    const vector<vector<int>>& graph,
    vector<State>& states)
{
    if (states[node] == State::VISITING) {
        return false;
    }

    if (states[node] == State::VISITED) {
        return true;
    }

    states[node] = State::VISITING;

    for (int neighbor : graph[node]) {
        if (!dfs(neighbor, graph, states)) {
            return false;
        }
    }

    states[node] = State::VISITED;
    return true;
}

bool CourseSchedule_207::canFinishKahns(
    int numCourses,
    const vector<vector<int>>& prerequisites)
{
    vector<vector<int>> adj(numCourses);
    vector<int> indeg(numCourses, 0);

    for (const auto& p : prerequisites) {
        const int course = p[0];
        const int pre = p[1];

        // Kahn needs prerequisite -> course so indeg[course] counts remaining prerequisites.
        adj[pre].push_back(course);
        ++indeg[course];
    }

    queue<int> q;
    for (int i = 0; i < numCourses; ++i) {
        if (indeg[i] == 0) {
            q.push(i);
        }
    }

    int visited = 0;

    while (!q.empty()) {
        const int cur = q.front();
        q.pop();
        ++visited;

        for (int nxt : adj[cur]) {
            if (--indeg[nxt] == 0) {
                q.push(nxt);
            }
        }
    }

    return visited == numCourses;
}
