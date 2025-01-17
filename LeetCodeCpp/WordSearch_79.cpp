#include "WordSearch_79.h"

bool WordSearch_79::exist(std::vector<std::vector<char>> &board, std::string word)
{
    int rows = board.size();
    int cols = board[0].size();

    // Iterate through each cell in the board
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (backtrack(board, word, i, j, 0)) {
                return true;
            }
        }
    }
    return false;
}

bool WordSearch_79::backtrack(std::vector<std::vector<char>> &board, const std::string &word, int row, int col, int index)
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
