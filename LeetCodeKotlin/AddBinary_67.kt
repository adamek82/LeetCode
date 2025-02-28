class AddBinary_67 {
    fun addBinary(a: String, b: String): String {
        var i = a.lastIndex
        var j = b.lastIndex
        var carry = 0
        val result = StringBuilder()

        while (i >= 0 || j >= 0 || carry != 0) {
            var sum = carry
            sum += if (i >= 0) a[i--] - '0' else 0
            sum += if (j >= 0) b[j--] - '0' else 0
            // Append the current bit (0 or 1)
            result.append(sum % 2)
            // Update the carry
            carry = sum / 2
        }

        // Reverse the string builder to get the final result
        return result.reverse().toString()
    }
}