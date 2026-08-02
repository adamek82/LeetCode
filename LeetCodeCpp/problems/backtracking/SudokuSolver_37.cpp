#include "SudokuSolver_37.h"
#include <bit>

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
 * This file contains two implementations:
 *
 *   1. Plain backtracking:
 *      - scan the board for the next empty cell
 *      - try digits '1'..'9'
 *      - validate each candidate by scanning row / column / box
 *
 *   2. Bit-mask backtracking:
 *      - maintain used digits for rows / columns / boxes as 9-bit masks
 *      - compute candidate digits with bit operations
 *      - pick the next empty cell with the fewest available candidates
 *
 * Both methods solve the same problem and mutate the board in place.
 */

// ============================================================================
// Implementation 1: plain backtracking
// ============================================================================

void SudokuSolver_37::solveSudoku_PlainBacktracking(vector<vector<char>>& board) {
    backtrackPlain(board);
}

bool SudokuSolver_37::backtrackPlain(vector<vector<char>>& board) {
    for (int r = 0; r < 9; ++r) {
        for (int c = 0; c < 9; ++c) {
            if (board[r][c] == '.') {
                for (char ch = '1'; ch <= '9'; ++ch) {
                    if (isValidPlain(board, r, c, ch)) {
                        board[r][c] = ch;

                        if (backtrackPlain(board)) {
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

bool SudokuSolver_37::isValidPlain(const vector<vector<char>>& board, int row, int col, char ch) {
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

// ============================================================================
// Implementation 2: bit masks + backtracking
// ============================================================================

void SudokuSolver_37::solveSudoku_BitMasks(vector<vector<char>>& board) {
    int rowMask[9] = {};
    int colMask[9] = {};
    int boxMask[9] = {};
    vector<pair<int, int>> empty;

    for (int r = 0; r < 9; ++r) {
        for (int c = 0; c < 9; ++c) {
            if (board[r][c] == '.') {
                empty.push_back({r, c});
            } else {
                int digit = board[r][c] - '1';
                int bit = 1 << digit;
                int b = boxIndex(r, c);

                rowMask[r] |= bit;
                colMask[c] |= bit;
                boxMask[b] |= bit;
            }
        }
    }

    backtrackBitMasks(board, empty, 0, rowMask, colMask, boxMask);
}

bool SudokuSolver_37::backtrackBitMasks(vector<vector<char>>& board,
                                        vector<pair<int, int>>& empty,
                                        int pos,
                                        int rowMask[9],
                                        int colMask[9],
                                        int boxMask[9]) {
    if (pos == static_cast<int>(empty.size())) {
        return true;
    }

    // Choose the empty cell with the fewest available candidates.
    int best = pos;
    int bestCandidateCount = 10;

    for (int i = pos; i < static_cast<int>(empty.size()); ++i) {
        int r = empty[i].first;
        int c = empty[i].second;
        int b = boxIndex(r, c);

        int used = rowMask[r] | colMask[c] | boxMask[b];
        int available = (~used) & 0x1FF;  // only 9 lowest bits matter

        int candidateCount = popcount(static_cast<unsigned int>(available));
        if (candidateCount < bestCandidateCount) {
            bestCandidateCount = candidateCount;
            best = i;

            if (candidateCount == 1) {
                break;
            }
        }
    }

    swap(empty[pos], empty[best]);

    int r = empty[pos].first;
    int c = empty[pos].second;
    int b = boxIndex(r, c);

    int used = rowMask[r] | colMask[c] | boxMask[b];
    int available = (~used) & 0x1FF;

    while (available) {
        int bit = available & -available;  // isolate the lowest set bit
        available -= bit;

        int digit = countr_zero(static_cast<unsigned int>(bit));    // index of the set bit: 0..8
        board[r][c] = static_cast<char>('1' + digit);

        rowMask[r] |= bit;
        colMask[c] |= bit;
        boxMask[b] |= bit;

        if (backtrackBitMasks(board, empty, pos + 1, rowMask, colMask, boxMask)) {
            return true;
        }

        rowMask[r] ^= bit;
        colMask[c] ^= bit;
        boxMask[b] ^= bit;
        board[r][c] = '.';
    }

    swap(empty[pos], empty[best]);
    return false;
}

int SudokuSolver_37::boxIndex(int row, int col) {
    return (row / 3) * 3 + (col / 3);
}
