class JumpGameII_45 {
    fun jump(nums: IntArray): Int {
        if (nums.size == 1) return 0

        var jumps = 0         // Count of jumps made.
        var currentEnd = 0    // Current window end.
        var farthest = 0      // Farthest reachable index so far.

        // Iterate over indices from 0 to the second-to-last element.
        for (i in 0 until nums.lastIndex) {
            // Update the farthest index we can reach.
            farthest = maxOf(farthest, i + nums[i])

            // When we've reached the end of the current window,
            // we make a jump and set the window's end to the farthest index reached.
            if (i == currentEnd) {
                jumps++
                currentEnd = farthest
            }
        }
        return jumps
    }
}