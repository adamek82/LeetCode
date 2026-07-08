#include "LongestCycleInGraph_2360.h"

#include <algorithm>
#include <vector>

using namespace std;

int LongestCycleInGraph_2360::longestCycle(vector<int>& edges)
{
    const int n = static_cast<int>(edges.size());

    int ans = -1;
    int time = 1;
    vector<int> timeVisited(n, 0);

    for (int i = 0; i < n; ++i) {
        if (timeVisited[i]) {
            continue;
        }

        const int startTime = time;
        int node = i;

        while (node != -1 && !timeVisited[node]) {
            timeVisited[node] = time++;
            node = edges[node];
        }

        if (node != -1 && timeVisited[node] >= startTime) {
            ans = max(ans, time - timeVisited[node]);
        }
    }

    return ans;
}
