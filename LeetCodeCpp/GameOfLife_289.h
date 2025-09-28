#pragma once
#include <vector>
using namespace std;

class GameOfLife_289 {
public:
    /**
     * Applies one step of Conway's Game of Life in-place.
     * Modifies 'board' directly (packs current & next state into cell bits).
     * Complexity: O(m·n) time, O(1) extra space.
     */
    void gameOfLife(vector<vector<int>>& board);
};
