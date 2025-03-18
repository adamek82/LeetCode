class LongestConsecutiveSequence_128 {
    fun longestConsecutive(nums: IntArray): Int {
        if (nums.isEmpty()) return 0

        // Use a set for O(1) lookups
        val numSet = nums.toHashSet()
        var longestStreak = 0

        for (num in numSet) {
            // Only start counting if `num-1` is not in the set (i.e., `num` begins a sequence)
            if (!numSet.contains(num - 1)) {
                var currentNum = num
                var currentStreak = 1

                // Count how many consecutive numbers follow
                while (numSet.contains(currentNum + 1)) {
                    currentNum++
                    currentStreak++
                }
                longestStreak = maxOf(longestStreak, currentStreak)
            }
        }
        return longestStreak
    }
}