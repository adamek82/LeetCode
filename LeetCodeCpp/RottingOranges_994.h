#pragma once
#include <vector>
#include <queue>
#include <array>

class RottingOranges_994 {
public:
    enum class CellState { EMPTY, FRESH, ROTTEN };
    int orangesRotting(std::vector<std::vector<int>>& grid);
};