#include "SudokuSolver_37.h"

/*
 * Sudoku Solver (LeetCode 37)
 *
 * We are given a partially filled 9x9 Sudoku board.
 * Empty cells are represented by '.'.
 * We must fill the board so that:
 *
 *   1. Each row contains digits 1..9 exactly once.
 *   2. Each column contains digits 1..9 exactly once.
 *   3. Each 3x3 sub-box contains digits 1..9 exactly once.
 *
 * Core idea:
 *   Use classic backtracking.
 *
 *   - Scan the board to find the next empty cell.
 *   - Try digits '1'..'9'.
 *   - For each candidate, check whether placing it keeps the board valid.
 *   - If yes, place it and recurse.
 *   - If recursion later fails, undo the move and try the next digit.
 *
 * Correctness sketch:
 *   - We only place digits that do not violate Sudoku rules locally.
 *   - Recursion explores all valid continuations of the current partial board.
 *   - If a full valid completion exists, one recursive path reaches it.
 *   - If a choice leads to a dead end, backtracking restores the previous state.
 *
 * Complexity:
 *   Worst-case exponential in the number of empty cells.
 *   For fixed 9x9 Sudoku this is acceptable on LeetCode.
 */
void SudokuSolver_37::solveSudoku(vector<vector<char>>& board) {
    backtrack(board);
}

bool SudokuSolver_37::backtrack(vector<vector<char>>& board) {
    for (int r = 0; r < 9; ++r) {
        for (int c = 0; c < 9; ++c) {
            if (board[r][c] == '.') {
                for (char ch = '1'; ch <= '9'; ++ch) {
                    if (isValid(board, r, c, ch)) {
                        board[r][c] = ch;

                        if (backtrack(board)) {
                            return true;
                        }

                        board[r][c] = '.';
                    }
                }

                return false;
            }
        }
    }

    return true;
}

bool SudokuSolver_37::isValid(const vector<vector<char>>& board, int row, int col, char ch) {
    for (int i = 0; i < 9; ++i) {
        if (board[row][i] == ch) return false;
        if (board[i][col] == ch) return false;
    }

    int startRow = (row / 3) * 3;
    int startCol = (col / 3) * 3;

    for (int r = startRow; r < startRow + 3; ++r) {
        for (int c = startCol; c < startCol + 3; ++c) {
            if (board[r][c] == ch) return false;
        }
    }

    return true;
}
