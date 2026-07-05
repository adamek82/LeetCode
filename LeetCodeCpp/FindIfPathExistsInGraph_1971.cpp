#include "FindIfPathExistsInGraph_1971.h"

#include "UnionFind.h"

#include <queue>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

// This file intentionally keeps several solution variants for the same problem:
// recursive DFS, iterative DFS, BFS, and Union-Find.
bool FindIfPathExistsInGraph_1971::validPathRecursiveDFS(
    int n,
    const vector<vector<int>>& edges,
    int source,
    int destination)
{
    if (source == destination) {
        return true;
    }

    vector<vector<int>> graph(n);
    for (const auto& edge : edges) {
        graph[edge[0]].push_back(edge[1]);
        graph[edge[1]].push_back(edge[0]);
    }

    vector<int> visited(n, 0);
    visited[source] = 1;

    return recursive_dfs(source, destination, graph, visited);
}

bool FindIfPathExistsInGraph_1971::validPathIterativeDFS(
    [[maybe_unused]] int n,
    const vector<vector<int>>& edges,
    int source,
    int destination)
{
    if (source == destination) {
        return true;
    }

    unordered_map<int, vector<int>> graph;
    for (const auto& edge : edges) {
        graph[edge[0]].push_back(edge[1]);
        graph[edge[1]].push_back(edge[0]);
    }

    unordered_set<int> visited;
    stack<int> st;

    st.push(source);
    visited.insert(source);

    while (!st.empty()) {
        int node = st.top();
        st.pop();

        if (node == destination) {
            return true;
        }

        for (int neighbor : graph[node]) {
            if (!visited.count(neighbor)) {
                visited.insert(neighbor);
                st.push(neighbor);
            }
        }
    }

    return false;
}

bool FindIfPathExistsInGraph_1971::validPathBFS(
    [[maybe_unused]] int n,
    const vector<vector<int>>& edges,
    int source,
    int destination)
{
    if (source == destination) {
        return true;
    }

    unordered_map<int, vector<int>> graph;
    for (const auto& edge : edges) {
        graph[edge[0]].push_back(edge[1]);
        graph[edge[1]].push_back(edge[0]);
    }

    unordered_set<int> visited;
    queue<int> q;

    q.push(source);
    visited.insert(source);

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        if (node == destination) {
            return true;
        }

        for (int neighbor : graph[node]) {
            if (!visited.count(neighbor)) {
                visited.insert(neighbor);
                q.push(neighbor);
            }
        }
    }

    return false;
}

bool FindIfPathExistsInGraph_1971::validPathUnionFind(
    int n,
    const vector<vector<int>>& edges,
    int source,
    int destination)
{
    UnionFind uf(n);

    for (const auto& edge : edges) {
        uf.unionSets(edge[0], edge[1]);
    }

    return uf.find(source) == uf.find(destination);
}

bool FindIfPathExistsInGraph_1971::recursive_dfs(
    int node,
    int destination,
    const vector<vector<int>>& graph,
    vector<int>& visited)
{
    if (node == destination) {
        return true;
    }

    for (int neighbor : graph[node]) {
        if (!visited[neighbor]) {
            visited[neighbor] = 1;

            if (recursive_dfs(neighbor, destination, graph, visited)) {
                return true;
            }
        }
    }

    return false;
}
