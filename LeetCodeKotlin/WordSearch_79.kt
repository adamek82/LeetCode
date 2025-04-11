class WordSearch_79 {
    fun exist(board: Array<CharArray>, word: String): Boolean {
        val rows = board.size
        val cols = board[0].size

        // Pre-check: Ensure the board contains enough instances of each character needed to form the word.
        val boardCount = hashMapOf<Char, Int>()
        for (row in board) {
            for (char in row) {
                boardCount[char] = boardCount.getOrDefault(char, 0) + 1
            }
        }
        for (char in word) {
            boardCount[char] = boardCount.getOrDefault(char, 0) - 1
            if (boardCount[char]!! < 0) {
                return false
            }
        }
        
        for (i in 0 until rows) {
            for (j in 0 until cols) {
                // Start DFS if first letter matches
                if (dfs(board, word, i, j, 0)) {
                    return true
                }
            }
        }
        return false
    }
    
    private fun dfs(board: Array<CharArray>, word: String, i: Int, j: Int, index: Int): Boolean {
        // If we've matched all characters, we've found the word
        if (index == word.length) return true
        
        // Check boundaries and if the current cell matches the word character at index
        if (i < 0 || i >= board.size || j < 0 || j >= board[0].size || board[i][j] != word[index]) {
            return false
        }
        
        // Temporarily mark the current cell as visited so we don't use it twice
        val temp = board[i][j]
        board[i][j] = '#'  // '#' is used as a placeholder
        
        // Explore in all four directions
        val found = dfs(board, word, i + 1, j, index + 1) ||
                    dfs(board, word, i - 1, j, index + 1) ||
                    dfs(board, word, i, j + 1, index + 1) ||
                    dfs(board, word, i, j - 1, index + 1)
        
        // Restore the cell's original character after the exploration
        board[i][j] = temp
        
        return found
    }
}
