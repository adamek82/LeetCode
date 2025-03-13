class MaximumAverageSubarrayI643 {
    fun findMaxAverage(nums: IntArray, k: Int): Double {
        var windowSum = 0

        // Sum of the first k elements
        for (i in 0 until k) {
            windowSum += nums[i]
        }

        var maxSum = windowSum

        // Slide the window from index k to the end
        for (i in k until nums.size) {
            // Remove the element that goes out of the window and add the new one
            windowSum = windowSum - nums[i - k] + nums[i]
            if (windowSum > maxSum) {
                maxSum = windowSum
            }
        }

        return maxSum.toDouble() / k
    }
}