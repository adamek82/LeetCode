#pragma once

#include <array>
#include <limits>
#include <utility>
#include <vector>

class FindSafestPathInGrid_2812 {
public:
    int maximumSafenessFactor(std::vector<std::vector<int>>& grid);

private:
    using Point = std::pair<int, int>;

    static constexpr int INF = std::numeric_limits<int>::max() / 2;

    static constexpr std::array<std::pair<int, int>, 4> directions{{
        {0, 1}, {1, 0}, {0, -1}, {-1, 0}
    }};
};
