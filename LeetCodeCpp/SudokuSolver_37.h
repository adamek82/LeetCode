#pragma once
#include <vector>
using namespace std;

class SudokuSolver_37 {
public:
    void solveSudoku(vector<vector<char>>& board);

private:
    bool backtrack(vector<vector<char>>& board);
    bool isValid(const vector<vector<char>>& board, int row, int col, char ch);
};
