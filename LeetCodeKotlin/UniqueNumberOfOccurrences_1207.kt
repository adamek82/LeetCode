class UniqueNumberOfOccurrences_1207 {
    fun uniqueOccurrences(arr: IntArray): Boolean {
        val freq = mutableMapOf<Int, Int>()
        for (num in arr) {
            freq[num] = freq.getOrDefault(num, 0) + 1
        }

        val occurrences = mutableSetOf<Int>()
        for (count in freq.values) {
            if (!occurrences.add(count)) {
                return false
            }
        }

        return true
    }
}