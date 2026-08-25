#include "ShortestPathVisitingAllNodes_847.h"

#include <queue>

using namespace std;

namespace {

struct State {
    int node;
    int visitedMask;
};

} // namespace

int ShortestPathVisitingAllNodes_847::shortestPathLength(
    const vector<vector<int>>& graph) const
{
    const int nodeCount = static_cast<int>(graph.size());
    const int maskCount = 1 << nodeCount;
    const int allVisitedMask = maskCount - 1;

    queue<State> states;
    vector<vector<char>> visited(nodeCount, vector<char>(maskCount));

    for (int node = 0; node < nodeCount; ++node) {
        const int visitedMask = 1 << node;
        states.push({node, visitedMask});
        visited[node][visitedMask] = 1;
    }

    int pathLength = 0;

    while (!states.empty()) {
        const int levelSize = static_cast<int>(states.size());

        for (int i = 0; i < levelSize; ++i) {
            const State current = states.front();
            states.pop();

            if (current.visitedMask == allVisitedMask) {
                return pathLength;
            }

            for (const int neighbor : graph[current.node]) {
                const int nextMask = current.visitedMask | (1 << neighbor);

                if (visited[neighbor][nextMask] != 0) {
                    continue;
                }

                visited[neighbor][nextMask] = 1;
                states.push({neighbor, nextMask});
            }
        }

        ++pathLength;
    }

    return -1;
}
