#include "NetworkDelayTime_743.h"

int NetworkDelayTime_743::networkDelayTime(vector<vector<int>> &times, int n, int k)
{
    // Build the graph as an adjacency list
    unordered_map<int, vector<pair<int, int>>> graph;
    for (const auto& time : times) {
        int u = time[0], v = time[1], w = time[2];
        graph[u].emplace_back(v, w);
    }

    // Min-heap to keep track of the minimum time to reach each node
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> min_heap;
    min_heap.emplace(0, k); // (time from source to node, node)

    unordered_map<int, int> min_times;

    while (!min_heap.empty()) {
        auto [time_k_to_i, i] = min_heap.top();
        min_heap.pop();

        if (min_times.count(i)) continue; // Skip if the node is already visited

        min_times[i] = time_k_to_i;

        for (const auto& [nei, nei_time] : graph[i]) {
            if (!min_times.count(nei)) {
                min_heap.emplace(time_k_to_i + nei_time, nei);
            }
        }
    }

    return min_times.size() == n
               ? max_element(min_times.begin(), min_times.end(),
                                  [](const auto &a, const auto &b)
                                  { return a.second < b.second; })
                     ->second
               : -1;
}