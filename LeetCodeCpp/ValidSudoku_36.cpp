#include "ValidSudoku_36.h"
#include <vector>
#include <unordered_set>

/*
 * Hash-set based Sudoku validation.
 *
 * We keep three arrays of hash sets: one for rows, one for columns,
 * and one for the 3x3 sub-boxes. For each non-empty cell board[i][j]:
 * - Check whether the digit is already present in the corresponding row,
 *   column, or sub-box set; if so, the board is invalid.
 * - Otherwise, insert the digit into all three sets and continue.
 *
 * The 3x3 sub-box index is computed as:
 *   boxIndex = (i / 3) * 3 + (j / 3)
 * where (i / 3) is the sub-box row (0..2) and (j / 3) is the sub-box
 * column (0..2). Multiplying the sub-box row by 3 and adding the sub-box
 * column gives a unique index in [0, 8] for each of the 9 boxes:
 *   0 1 2
 *   3 4 5
 *   6 7 8
 *
 * If we scan all 81 cells without detecting a duplicate in any row,
 * column, or sub-box, the board is valid.
 *
 * Time complexity:
 * We visit each cell once and perform O(1) expected work per cell
 * (hash-set lookup + insert), so the total time is O(81) = O(1) for
 * the fixed 9×9 Sudoku, or O(n²) for a generalized n×n board.
 * Space complexity is O(1) for standard Sudoku (a bounded number of
 * sets and digits), or O(n²) in the generalized case.
 */
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