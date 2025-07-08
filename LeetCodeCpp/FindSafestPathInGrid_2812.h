#pragma once
#include <array>
#include <limits>
#include <vector>

using namespace std;

class FindSafestPathInGrid_2812 {
    using pii = pair<int,int>;
    static constexpr int INF = std::numeric_limits<int>::max();

    // 4 possible directions
    static constexpr array<pair<int,int>,4> directions =
        {{{0, 1}, {1, 0}, {0, -1}, {-1, 0}}};

public:
    int maximumSafenessFactor(vector<vector<int>>& grid);
};