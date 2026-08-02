#include "BusRoutes_815.h"

#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

int BusRoutes_815::numBusesToDestination(
    vector<vector<int>>& routes,
    int source,
    int target)
{
    if (source == target) {
        return 0;
    }

    unordered_map<int, vector<int>> stopToBuses;
    for (int bus = 0; bus < static_cast<int>(routes.size()); ++bus) {
        for (int stop : routes[bus]) {
            stopToBuses[stop].push_back(bus);
        }
    }

    // BFS over stops; each layer corresponds to taking one more bus.
    queue<int> q;
    unordered_set<int> seenStops;
    unordered_set<int> seenBuses;

    q.emplace(source);
    seenStops.insert(source);

    int busesTaken = 0;

    while (!q.empty()) {
        ++busesTaken;

        const int layerSize = static_cast<int>(q.size());
        for (int i = 0; i < layerSize; ++i) {
            const int stop = q.front();
            q.pop();

            for (int bus : stopToBuses[stop]) {
                if (seenBuses.count(bus)) {
                    continue;
                }

                seenBuses.insert(bus);

                for (int nextStop : routes[bus]) {
                    if (nextStop == target) {
                        return busesTaken;
                    }

                    if (seenStops.insert(nextStop).second) {
                        q.emplace(nextStop);
                    }
                }
            }
        }
    }

    return -1;
}
