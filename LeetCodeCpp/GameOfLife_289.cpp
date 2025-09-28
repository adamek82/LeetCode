#include "GameOfLife_289.h"
#include <algorithm>

void GameOfLife_289::gameOfLife(vector<vector<int>> &board)
{
    const int m = board.size();
    const int n = m>0 ? board[0].size() : 0;
    for (int i=0; i<m; ++i) {
        for (int j=0; j<n; ++j) {
            // count live cells in the 3x3 block
            int count = 0;
            for (int I=max(i-1, 0); I<min(i+2, m); ++I)
                for (int J=max(j-1, 0); J<min(j+2, n); ++J)
                    count += board[I][J] & 1;
            if ((count == 4 && board[i][j]) || count == 3)
                board[i][j] |= 2;   // mark as alive
        }
    }

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
                board[i][j] >>= 1;  // Update to the next state
        }
    }
}
