#pragma once
#include <vector>
#include <queue>
#include <array>

using namespace std;

class RottingOranges_994 {
public:
    enum class CellState { EMPTY, FRESH, ROTTEN };
    int orangesRotting(vector<vector<int>>& grid);
};