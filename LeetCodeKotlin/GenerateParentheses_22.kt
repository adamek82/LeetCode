class GenerateParentheses_22 {
    fun generateParenthesis(n: Int): List<String> {
        val result = mutableListOf<String>()
        
        fun backtrack(current: String, open: Int, close: Int) {
            // If the current string is a valid combination, add it to the result list
            if (current.length == n * 2) {
                result.add(current)
                return
            }
            
            // If we can add an opening parenthesis, do so and recurse
            if (open < n) {
                backtrack(current + "(", open + 1, close)
            }
            
            // If we can add a closing parenthesis (only if there is a corresponding unmatched opening), do so and recurse
            if (close < open) {
                backtrack(current + ")", open, close + 1)
            }
        }
        
        // Start the recursion with an empty string
        backtrack("", 0, 0)
        return result
    }
}
