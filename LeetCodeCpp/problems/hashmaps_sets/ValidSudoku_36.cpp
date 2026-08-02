#include "ValidSudoku_36.h"

#include <array>

bool ValidSudoku_36::isValidSudoku(const vector<vector<char>>& board) const
{
    constexpr size_t BOARD_SIZE = 9;
    constexpr size_t BOX_SIZE = 3;

    array<array<bool, BOARD_SIZE>, BOARD_SIZE> rows{};
    array<array<bool, BOARD_SIZE>, BOARD_SIZE> cols{};
    array<array<bool, BOARD_SIZE>, BOARD_SIZE> boxes{};

    for (size_t row = 0; row < BOARD_SIZE; ++row) {
        for (size_t col = 0; col < BOARD_SIZE; ++col) {
            const char cell = board[row][col];

            if (cell == '.') {
                continue;
            }

            const size_t digit = static_cast<size_t>(cell - '1');
            const size_t box =
                (row / BOX_SIZE) * BOX_SIZE + col / BOX_SIZE;

            if (rows[row][digit] ||
                cols[col][digit] ||
                boxes[box][digit]) {
                return false;
            }

            rows[row][digit] = true;
            cols[col][digit] = true;
            boxes[box][digit] = true;
        }
    }

    return true;
}
