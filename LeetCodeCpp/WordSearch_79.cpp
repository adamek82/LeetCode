#include "WordSearch_79.h"

/*
 * LeetCode 79 — Word Search
 *
 * Problem
 * -------
 * Given an m×n board of characters and a string `word`, determine if `word`
 * exists in the grid. The word can be constructed from sequentially adjacent
 * cells (horizontally or vertically). The same cell may not be used more than
 * once in a path.
 *
 * Approach (DFS backtracking with in-place visited marking)
 * --------------------------------------------------------
 * - Try every cell as a potential start position.
 * - Backtrack(board, row, col, index) attempts to match `word[index...]`
 *   starting from (row, col).
 *   * If index == word.size(): all characters matched → true.
 *   * If out of bounds or board[row][col] != word[index] → false.
 *   * Otherwise, mark the cell as visited (temporarily set to '#'),
 *     recurse in 4 directions with index+1, then restore the original char.
 *
 * Correctness
 * -----------
 * - Soundness: we only advance `index` when the current cell matches the
 *   required character; the visited mark prevents reusing the same cell in
 *   the current path, so any successful return corresponds to a valid path
 *   forming `word`.
 * - Completeness: we explore all cells as start points, and from each cell we
 *   explore all 4 adjacent moves consistent with the next character. Thus, if
 *   a valid path exists anywhere, the search will find it.
 *
 * Complexity
 * ----------
 * Let R = rows, C = cols, and L = word.length().
 * - Time  : O(R*C*4^L) in the worst case (each step branches up to 4 ways).
 *           (Tighter: O(R*C*3^(L-1)) after the first step, since we can't go
 *           back to the immediately previous cell, but 4^L is a safe bound.)
 * - Space : O(L) auxiliary for recursion depth (in-place marking uses O(1)
 *           extra grid memory).
 */
bool WordSearch_79::exist(vector<vector<char>> &board, string word)
{
    int rows = board.size();
    int cols = board[0].size();

    // Iterate through each cell in the board
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (board[i][j] == word[0] && backtrack(board, word, i, j, 0)) {
                return true;
            }
        }
    }
    return false;
}

bool WordSearch_79::backtrack(vector<vector<char>> &board, const string &word, int row, int col, int index)
{
    // Base case: all characters in the word are matched
    if (index == word.size()) {
        return true;
    }

    // Check boundaries and ensure the cell matches the current character of the word
    if (row < 0 || row >= board.size() || col < 0 || col >= board[0].size() || board[row][col] != word[index]) {
        return false;
    }

    // Mark the cell as visited by altering its value temporarily
    char temp = board[row][col];
    board[row][col] = '#'; // Any non-alphabet character to denote visited

    // Explore all 4 possible directions
    bool found = backtrack(board, word, row + 1, col, index + 1) ||
                    backtrack(board, word, row - 1, col, index + 1) ||
                    backtrack(board, word, row, col + 1, index + 1) ||
                    backtrack(board, word, row, col - 1, index + 1);

    // Restore the cell value after exploring
    board[row][col] = temp;

    return found;
}
