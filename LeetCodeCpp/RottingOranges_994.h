#pragma once
#include <vector>

using namespace std;

class RottingOranges_994 {
public:
    enum class CellState { EMPTY, FRESH, ROTTEN };
    int orangesRotting(vector<vector<int>>& grid);
};
