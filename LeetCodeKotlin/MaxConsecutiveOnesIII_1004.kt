class MaxConsecutiveOnesIII_1004 {
    fun longestOnes(nums: IntArray, k: Int): Int {
        var left = 0
        var zeroCount = 0
        var maxLength = 0

        for (right in nums.indices) {
            if (nums[right] == 0) {
                zeroCount++
            }

            // If we exceed k zeros, move the left pointer until zeroCount <= k
            while (zeroCount > k) {
                if (nums[left] == 0) {
                    zeroCount--
                }
                left++
            }

            // Update the maximum window size that has at most k zeros
            maxLength = maxOf(maxLength, right - left + 1)
        }

        return maxLength
    }
}
