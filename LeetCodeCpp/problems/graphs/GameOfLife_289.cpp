#include "GameOfLife_289.h"

#include <algorithm>
#include <vector>

using namespace std;

void GameOfLife_289::gameOfLife(vector<vector<int>>& board)
{
    const int m = static_cast<int>(board.size());
    const int n = (m > 0) ? static_cast<int>(board[0].size()) : 0;

    // Bit 0 stores the old state; bit 1 stages the next state.
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            int count = 0;

            for (int row = max(i - 1, 0); row < min(i + 2, m); ++row) {
                for (int col = max(j - 1, 0); col < min(j + 2, n); ++col) {
                    count += board[row][col] & 1;
                }
            }

            if ((count == 4 && (board[i][j] & 1)) || count == 3) {
                board[i][j] |= 2;
            }
        }
    }

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            board[i][j] >>= 1;
        }
    }
}
