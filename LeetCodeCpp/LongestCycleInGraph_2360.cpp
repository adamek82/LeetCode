#include "LongestCycleInGraph_2360.h"

int LongestCycleInGraph_2360::longestCycle(std::vector<int> &edges)
{
    int ans = -1;
    int time = 1;                       // global clock
    std::vector<int> timeVisited(edges.size(), 0);

    for (int i = 0; i < edges.size(); ++i) {
      if (timeVisited[i]) continue;     // node already processed

      int startTime = time;             // clock value at the start of this walk
      int u = i;

      while (u != -1 && !timeVisited[u]) {
        timeVisited[u] = time++;        // stamp -- first visit ever
        u = edges[u];                   // advance along unique edge
      }

      // If we stopped because we re-entered the current walk ⇒ found a cycle
      if (u != -1 && timeVisited[u] >= startTime)
        ans = std::max(ans, time - timeVisited[u]);
    }
    return ans;
}