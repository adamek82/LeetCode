#include "ValidSudoku_36.h"

bool ValidSudoku_36::isValidSudoku(vector<vector<char>> &board)
{
    // Define hash sets for rows, columns, and 3x3 sub-boxes
    vector<unordered_set<char>> rows(9);
    vector<unordered_set<char>> cols(9);
    vector<unordered_set<char>> boxes(9);

    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            char c = board[i][j];

            if (c == '.') continue; // Skip empty cells

            // Check the row
            if (rows[i].count(c)) return false;
            rows[i].insert(c);

            // Check the column
            if (cols[j].count(c)) return false;
            cols[j].insert(c);

            // Check the 3x3 sub-box
            int boxIndex = (i / 3) * 3 + (j / 3);
            if (boxes[boxIndex].count(c)) return false;
            boxes[boxIndex].insert(c);
        }
    }

    return true; // If no conflicts, the board is valid
}