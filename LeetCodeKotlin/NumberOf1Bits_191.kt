class NumberOf1Bits_191 {
    fun hammingWeight(n: Int): Int {
        var bits = n
        var count = 0
        while (bits != 0) {
            bits = bits and (bits - 1)
            count++
        }
        return count
    }
}