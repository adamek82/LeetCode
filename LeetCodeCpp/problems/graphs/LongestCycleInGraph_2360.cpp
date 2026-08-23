#include "LongestCycleInGraph_2360.h"

#include <algorithm>

using namespace std;

int LongestCycleInGraph_2360::longestCycle(const vector<int>& edges) const
{
    const int nodeCount = static_cast<int>(edges.size());

    int longestCycleLength = -1;
    int timestamp = 1;
    vector<int> visitTime(nodeCount);

    for (int start = 0; start < nodeCount; ++start) {
        if (visitTime[start] != 0) {
            continue;
        }

        const int traversalStartTime = timestamp;
        int node = start;

        while (node != -1 && visitTime[node] == 0) {
            visitTime[node] = timestamp++;
            node = edges[node];
        }

        if (node != -1 && visitTime[node] >= traversalStartTime) {
            const int cycleLength = timestamp - visitTime[node];
            longestCycleLength = max(longestCycleLength, cycleLength);
        }
    }

    return longestCycleLength;
}
