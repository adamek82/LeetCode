class MinimumSizeSubarraySum_209 {
    fun minSubArrayLen(target: Int, nums: IntArray): Int {
        var left = 0
        var sum = 0
        var minLength = Int.MAX_VALUE

        for (right in nums.indices) {
            sum += nums[right]

            // Shrink the window while the sum is >= target
            while (sum >= target) {
                minLength = minOf(minLength, right - left + 1)
                sum -= nums[left]
                left++
            }
        }

        return if (minLength == Int.MAX_VALUE) 0 else minLength
    }
}