class SqrtX_69 {
    fun mySqrt(x: Int): Int {
        // Handle edge cases directly
        if (x < 2) return x

        var left = 1
        var right = x / 2  // For x>=2, the square root is always <= x/2

        // Binary search for the integer square root
        while (left <= right) {
            val mid = left + (right - left) / 2
            // Instead of mid*mid, use mid <= x/mid to avoid overflow.
            if (mid <= x / mid) {
                left = mid + 1
            } else {
                right = mid - 1
            }
        }

        return right
    }
}