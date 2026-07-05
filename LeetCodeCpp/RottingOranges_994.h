#pragma once

#include <vector>

class RottingOranges_994 {
public:
    int orangesRotting(std::vector<std::vector<int>>& grid);

private:
    enum class CellState { EMPTY, FRESH, ROTTEN };
};
