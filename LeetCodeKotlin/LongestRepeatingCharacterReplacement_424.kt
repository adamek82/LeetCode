class LongestRepeatingCharacterReplacement_424 {
    fun characterReplacement(s: String, k: Int): Int {
        val freq = IntArray(26) // To count occurrences of each letter
        var left = 0
        var maxFreq = 0
        var maxLength = 0

        for (right in s.indices) {
            // Update the frequency of the current character
            freq[s[right] - 'A']++

            // Update the maximum frequency in the current window
            maxFreq = maxOf(maxFreq, freq[s[right] - 'A'])

            // If more than k replacements are needed, shrink from left
            while ((right - left + 1) - maxFreq > k) {
                freq[s[left] - 'A']--
                left++
            }

            // Update the maximum window size
            maxLength = maxOf(maxLength, right - left + 1)
        }

        return maxLength
    }
}