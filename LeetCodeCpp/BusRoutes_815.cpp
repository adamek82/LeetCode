#include "BusRoutes_815.h"
#include <unordered_map>
#include <unordered_set>
#include <queue>

int BusRoutes_815::numBusesToDestination(vector<vector<int>> &routes, int source, int target)
{
    if (source == target) return 0;

    /* 1. Build: stop → list of buses that serve it */
    unordered_map<int, vector<int>> stop2bus;
    for (int bus = 0; bus < (int)routes.size(); ++bus)
        for (int stop : routes[bus])
            stop2bus[stop].push_back(bus);
    
    /* 2. BFS on *stops*, but we only “board” each bus once.               *
     * Each BFS layer = all stops reachable with one more bus transfer.    */
    queue<int> q;                 // current frontier of stops
    unordered_set<int> seenStop;  // visited stops
    unordered_set<int> seenBus;   // buses we have already taken

    q.push(source);
    seenStop.insert(source);
    int busesTaken = 0;

    while (!q.empty()) {
        ++busesTaken;                       // we are about to board one more bus
        int sz = q.size();
        while (sz--) {
            int stop = q.front(); q.pop();

            for (int bus : stop2bus[stop]) {
                if (seenBus.count(bus)) continue; // already rode this bus
                seenBus.insert(bus);

                for (int nxtStop : routes[bus]) {
                    if (nxtStop == target) return busesTaken;
                    if (seenStop.insert(nxtStop).second)  // first-time visit
                        q.push(nxtStop);
                }
            }
        }
    }
    return -1;  // unreachable
}