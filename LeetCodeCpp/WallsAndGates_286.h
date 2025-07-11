#pragma once
#include <vector>
#include <queue>
#include <array>
#include <utility>

using namespace std;

class WallsAndGates_286 {
public:
    void wallsAndGates(vector<vector<int>>& rooms);

private:
    static constexpr int INF = 2147483647;  // 2^31 - 1
    static constexpr array<pair<int,int>,4> directions =            // 4-directional moves
        {{{0, 1}, {1, 0}, {0, -1}, {-1, 0}}};
};