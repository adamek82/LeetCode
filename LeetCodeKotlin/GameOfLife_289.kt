class GameOfLife_289 {
    /**
     * Applies one step of Conway's Game of Life in-place.
     * Modifies [board] directly by packing current and next state into two bits.
     *
     * Complexity:
     * - Time: O(m * n)
     * - Space: O(1) extra
     */
    fun gameOfLife(board: Array<IntArray>) {
        val m = board.size
        val n = if (m > 0) board[0].size else 0

        for (i in 0 until m) {
            for (j in 0 until n) {
                var count = 0

                for (ii in maxOf(i - 1, 0) until minOf(i + 2, m)) {
                    for (jj in maxOf(j - 1, 0) until minOf(j + 2, n)) {
                        count += board[ii][jj] and 1
                    }
                }

                if ((count == 4 && board[i][j] == 1) || count == 3) {
                    board[i][j] = board[i][j] or 2
                }
            }
        }

        for (i in 0 until m) {
            for (j in 0 until n) {
                board[i][j] = board[i][j] shr 1
            }
        }
    }
}
