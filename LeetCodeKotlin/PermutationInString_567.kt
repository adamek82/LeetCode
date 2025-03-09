class PermutationInString_567 {
    fun checkInclusion(s1: String, s2: String): Boolean {
        if (s1.length > s2.length) return false

        val ALPHABET_SIZE = 'z' - 'a' + 1
        val s1Freq = IntArray(ALPHABET_SIZE)
        val s2Freq = IntArray(ALPHABET_SIZE)

        // Count frequencies for s1 and the first window in s2
        for (i in s1.indices) {
            s1Freq[s1[i] - 'a']++
            s2Freq[s2[i] - 'a']++
        }

        var matches = s1Freq.contentEquals(s2Freq)

        // Sliding window
        for (i in s1.length until s2.length) {
            if (matches) return true

            // Add new character to the window
            s2Freq[s2[i] - 'a']++
            // Remove the leftmost character of the previous window
            s2Freq[s2[i - s1.length] - 'a']--

            matches = s1Freq.contentEquals(s2Freq)
        }

        return matches
    }
}