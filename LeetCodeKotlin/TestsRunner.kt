object TestsRunner {
    @JvmStatic
    fun main(args: Array<String>) {
        println("Running BestTimeToBuyAndSellStock_121 tests:")
        testBestTimeToBuyAndSellStock_121()
    }

    data class MaxProfitTestCase(
        val prices: IntArray,
        val expectedResult: Int
    )

    private fun testBestTimeToBuyAndSellStock_121() {
        // The same test cases we used in C++
        //  - Provided examples
        //  - Additional complex test cases
        //  - Edge case
        val testCases = listOf(
            MaxProfitTestCase(intArrayOf(7, 1, 5, 3, 6, 4), 5),  // Example 1
            MaxProfitTestCase(intArrayOf(7, 6, 4, 3, 1), 0),     // Example 2
            MaxProfitTestCase(intArrayOf(1, 2, 3, 4, 5, 6, 7, 8, 9), 8), // Additional
            MaxProfitTestCase(intArrayOf(9, 8, 7, 1, 5, 3, 6, 4), 5),   // Additional
            MaxProfitTestCase(intArrayOf(5), 0)                         // Edge
        )

        val solution = BestTimeToBuyAndSellStock_121()

        for ((index, testCase) in testCases.withIndex()) {
            val result = solution.maxProfit(testCase.prices)
            val pass = (result == testCase.expectedResult)

            println(
                "Test ${index + 1}: res = " + 
                if (pass) {
                    "PASS"
                } else {
                    "FAIL"
                } + 
                " (Expected: ${testCase.expectedResult}, Got: $result)"
            )
        }
    }
}