#include "CriticalConnectionsInNetwork_1192.h"

#include <algorithm>
#include <vector>

using namespace std;

vector<vector<int>> CriticalConnectionsInNetwork_1192::criticalConnections(
    int n,
    const vector<vector<int>>& connections)
{
    graph.assign(n, {});
    tin.assign(n, -1);
    low.assign(n, -1);
    timer = 0;

    for (const auto& connection : connections) {
        const int u = connection[0];
        const int v = connection[1];

        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    vector<vector<int>> bridges;
    dfs(0, -1, bridges);

    return bridges;
}

void CriticalConnectionsInNetwork_1192::dfs(
    int node,
    int parent,
    vector<vector<int>>& bridges)
{
    tin[node] = low[node] = timer++;

    for (int neighbor : graph[node]) {
        if (neighbor == parent) {
            continue;
        }

        if (tin[neighbor] != -1) {
            low[node] = min(low[node], tin[neighbor]);
            continue;
        }

        dfs(neighbor, node, bridges);
        low[node] = min(low[node], low[neighbor]);

        if (low[neighbor] > tin[node]) {
            bridges.push_back({node, neighbor});
        }
    }
}
