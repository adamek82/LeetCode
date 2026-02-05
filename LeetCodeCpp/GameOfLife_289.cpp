#include "GameOfLife_289.h"
#include <algorithm>

/*
 * How this in-place trick works (two bits per cell):
 *
 * Encoding:
 *   - We use the least significant bit (bit 0) for the current state:
 *       0 = dead now, 1 = alive now
 *   - We temporarily use the next bit (bit 1) to stage the next state:
 *       If a cell will be alive in the next generation → set bit 1: x |= 2
 *       After the pass, shift right once: x >>= 1
 *         → staged next state (bit 1) becomes the new current state (bit 0)
 *
 * Counting neighbors while mutating in place:
 *   - When summing neighbors, we use:
 *       count += board[I][J] & 1;
 *     This masks off all but the least significant bit so we only consider
 *     the *original* state of each cell, ignoring any staged writes to bit 1.
 *   - Loop ranges are clamped with max/min to avoid out-of-bounds access.
 *
 * Single compact if for all rules:
 *   - Recall: count includes the cell itself.
 *   - Alive cell survives if it has 2 or 3 neighbors:
 *       → corresponds to count == 3 or count == 4 when board[i][j] is alive
 *   - Dead cell becomes alive if it has exactly 3 neighbors:
 *       → corresponds to count == 3 when board[i][j] is dead
 *   - This can be merged into:
 *       if ((count == 4 && board[i][j]) || count == 3)
 *   - Notice: using board[i][j] (truthy if alive now) works here without &1,
 *     because the check happens before we set bit 1 for that cell.
 *
 * State promotion:
 *   - After staging next states in bit 1, we run:
 *       board[i][j] >>= 1;
 *     This discards the old state (bit 0) and promotes next state (bit 1 → bit 0).
 *
 * Invariants:
 *   - Initially each cell is 0 or 1.
 *   - After the first pass, values are {0,1,2,3}:
 *       0 (dead→dead), 1 (alive→dead), 2 (dead→alive), 3 (alive→alive).
 *   - Masking with &1 guarantees correct neighbor counts.
 *
 * Complexity:
 *   - Time: O(m·n) since for each of m·n cells we scan up to 9 neighbors.
 *   - Space: O(1) extra; both states are packed into two bits per cell.
 */
void GameOfLife_289::gameOfLife(vector<vector<int>> &board)
{
    /*
    * board.size()/board[0].size() return size_t (unsigned), but we keep m/n as int
    * because the neighbor iteration uses signed arithmetic (i-1 / j-1) and bounds
    * like max(i-1, 0) and min(i+2, m). Using size_t would make negative indices
    * underflow and would require lots of casts.
    *
    * Limitation: assumes dimensions fit into int (<= INT_MAX). For LeetCode boards
    * this is safe in practice.
    */
    const int m = static_cast<int>(board.size());
    const int n = (m > 0) ? static_cast<int>(board[0].size()) : 0;
    for (int i=0; i<m; ++i) {
        for (int j=0; j<n; ++j) {
            // count live cells in the 3x3 block
            int count = 0;
            for (int I=max(i-1, 0); I<min(i+2, m); ++I)
                for (int J=max(j-1, 0); J<min(j+2, n); ++J)
                    count += board[I][J] & 1;
            if ((count == 4 && board[i][j]) || count == 3)
                board[i][j] |= 2;   // Mark as alive
        }
    }

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
                board[i][j] >>= 1;  // Update to the next state
        }
    }
}
