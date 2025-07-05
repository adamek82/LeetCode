#pragma once
#include <vector>

using namespace std;

class BusRoutes_815 {
public:
    /*
     * Returns the least number of buses you must take to travel from
     * `source` to `target` given the circular `routes`.
     *
     * If it is impossible to reach `target`, returns -1.
     */
    int numBusesToDestination(vector<vector<int>>& routes,
                               int source,
                               int target);
};
