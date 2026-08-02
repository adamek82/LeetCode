#include "WordSearch_79.h"

bool WordSearch_79::exist(vector<vector<char>>& board, string word)
{
    if (word.empty()) {
        return true;
    }

    if (board.empty() || board.front().empty()) {
        return false;
    }

    for (size_t row = 0; row < board.size(); ++row) {
        for (size_t col = 0; col < board[row].size(); ++col) {
            if (backtrack(board, word, row, col, 0)) {
                return true;
            }
        }
    }

    return false;
}

bool WordSearch_79::backtrack(vector<vector<char>>& board,
    const string& word,
    size_t row,
    size_t col,
    size_t index)
{
    if (board[row][col] != word[index]) {
        return false;
    }

    if (index + 1 == word.size()) {
        return true;
    }

    const char original = board[row][col];
    board[row][col] = '#';

    const size_t nextIndex = index + 1;

    const bool found =
        (row > 0 &&
         backtrack(board, word, row - 1, col, nextIndex)) ||
        (row + 1 < board.size() &&
         backtrack(board, word, row + 1, col, nextIndex)) ||
        (col > 0 &&
         backtrack(board, word, row, col - 1, nextIndex)) ||
        (col + 1 < board[row].size() &&
         backtrack(board, word, row, col + 1, nextIndex));

    board[row][col] = original;

    return found;
}
