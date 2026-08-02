#pragma once
#include <vector>
using namespace std;

class SudokuSolver_37 {
public:
    // Implementation 1: plain backtracking with row/column/box scanning.
    void solveSudoku_PlainBacktracking(vector<vector<char>>& board);

    // Implementation 2: backtracking with bit masks and MRV-style choice.
    void solveSudoku_BitMasks(vector<vector<char>>& board);

private:
    // Plain backtracking helpers
    bool backtrackPlain(vector<vector<char>>& board);
    bool isValidPlain(const vector<vector<char>>& board, int row, int col, char ch);

    // Bit-mask backtracking helpers
    bool backtrackBitMasks(vector<vector<char>>& board,
                           vector<pair<int, int>>& empty,
                           int pos,
                           int rowMask[9],
                           int colMask[9],
                           int boxMask[9]);

    int boxIndex(int row, int col);
};
