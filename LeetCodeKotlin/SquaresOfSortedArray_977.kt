class SquaresOfSortedArray_977 {
    fun sortedSquares(nums: IntArray): IntArray {
        val n = nums.size
        val result = IntArray(n)
        var left = 0
        var right = n - 1
        var index = n - 1

        while (left <= right) {
            val leftSquare = nums[left] * nums[left]
            val rightSquare = nums[right] * nums[right]

            if (leftSquare > rightSquare) {
                result[index] = leftSquare
                left++
            } else {
                result[index] = rightSquare
                right--
            }
            index--
        }

        return result
    }
}