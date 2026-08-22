#include "ShortestCycleInGraph_2608.h"

#include <algorithm>
#include <queue>

using namespace std;

int ShortestCycleInGraph_2608::findShortestCycle(
    int vertexCount,
    const vector<vector<int>>& edges) const
{
    vector<vector<int>> adjacencyList(vertexCount);

    for (const auto& edge : edges) {
        const int firstVertex = edge[0];
        const int secondVertex = edge[1];

        adjacencyList[firstVertex].push_back(secondVertex);
        adjacencyList[secondVertex].push_back(firstVertex);
    }

    constexpr int UNVISITED = -1;
    const int noCycle = vertexCount + 1;

    int shortestCycle = noCycle;
    vector<int> distances(vertexCount);

    for (int start = 0; start < vertexCount; ++start) {
        fill(distances.begin(), distances.end(), UNVISITED);

        queue<int> vertices;
        distances[start] = 0;
        vertices.push(start);

        while (!vertices.empty()) {
            const int current = vertices.front();
            vertices.pop();

            if (2 * distances[current] + 1 >= shortestCycle)
                continue;

            for (const int neighbor : adjacencyList[current]) {
                if (distances[neighbor] == UNVISITED) {
                    distances[neighbor] = distances[current] + 1;
                    vertices.push(neighbor);
                } else if (distances[neighbor] + 1 != distances[current]) {
                    shortestCycle = min(
                        shortestCycle,
                        distances[current] + distances[neighbor] + 1);

                    if (shortestCycle == 3)
                        return 3;
                }
            }
        }
    }

    return shortestCycle == noCycle ? -1 : shortestCycle;
}
