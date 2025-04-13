class LetterCombinations_17 {

    fun letterCombinations(digits: String): List<String> {
        if (digits.isEmpty()) return emptyList()

        val phoneMap = mapOf(
            '2' to "abc",
            '3' to "def",
            '4' to "ghi",
            '5' to "jkl",
            '6' to "mno",
            '7' to "pqrs",
            '8' to "tuv",
            '9' to "wxyz"
        )

        val result = mutableListOf<String>()

        fun backtrack(index: Int, current: StringBuilder) {
            // If we've reached the length of digits, we've formed a valid combination
            if (index == digits.length) {
                result.add(current.toString())
                return
            }

            // Get letters mapped to the current digit
            val letters = phoneMap[digits[index]] ?: return
            for (ch in letters) {
                current.append(ch)
                backtrack(index + 1, current)
                current.deleteCharAt(current.lastIndex) // backtrack step
            }
        }

        backtrack(0, StringBuilder())
        return result
    }
}
