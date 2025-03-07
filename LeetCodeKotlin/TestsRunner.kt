object TestsRunner {
    @JvmStatic
    fun main(args: Array<String>) {
        println("Running BestTimeToBuyAndSellStock_121 tests:")
        testBestTimeToBuyAndSellStock_121()
        println("Running FindIfPathExistsInGraph_1971 tests:")
        testFindIfPathExistsInGraph_1971()
        println("Running GroupAnagrams_49 tests:")
        testGroupAnagrams_49()
        println("Running AddBinary_67 tests:")
        testAddBinary_67()
        println("Running HammingWeight_191 tests:")
        testHammingWeight_191()
        println("Running UniqueNumberOfOccurrences_1207 tests:")
        testUniqueNumberOfOccurrences_1207()
    }

    data class MaxProfitTestCase(
        val prices: IntArray,
        val expectedResult: Int
    )

    data class PathTestCase(
        val n: Int,
        val edges: Array<IntArray>,
        val source: Int,
        val destination: Int,
        val expectedResult: Boolean
    )

    data class GroupAnagramsTestCase(
        val input: Array<String>,
        val expected: List<List<String>>
    )

    data class AddBinaryTestCase(
        val a: String,
        val b: String,
        val expected: String
    )

    data class HammingWeightTestCase(
        val n: Int,
        val expected: Int
    )

    data class UniqueOccurrencesTestCase(
        val arr: IntArray,
        val expectedResult: Boolean
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

    private fun testFindIfPathExistsInGraph_1971() {
        val testCases = listOf(
            PathTestCase(3, arrayOf(intArrayOf(0, 1), intArrayOf(1, 2), intArrayOf(2, 0)), 0, 2, true),
            PathTestCase(6, arrayOf(intArrayOf(0, 1), intArrayOf(0, 2), intArrayOf(3, 5), intArrayOf(5, 4), intArrayOf(4, 3)), 0, 5, false),
            PathTestCase(4, arrayOf(intArrayOf(0, 1), intArrayOf(1, 2), intArrayOf(2, 3)), 0, 3, true),
            PathTestCase(5, arrayOf(intArrayOf(0, 4), intArrayOf(4, 3), intArrayOf(3, 2), intArrayOf(2, 1)), 0, 1, true),
            PathTestCase(4, arrayOf(intArrayOf(0, 1), intArrayOf(1, 2)), 0, 3, false)
        )

        val solution = FindIfPathExistsInGraph_1971()

        for ((index, testCase) in testCases.withIndex()) {
            val result = solution.validPath(testCase.n, testCase.edges, testCase.source, testCase.destination)
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

    private fun testGroupAnagrams_49() {
        val testCases = listOf(
            // Example 1
            GroupAnagramsTestCase(
                arrayOf("eat", "tea", "tan", "ate", "nat", "bat"),
                listOf(listOf("bat"), listOf("tan", "nat"), listOf("eat", "tea", "ate"))
            ),
            // Example 2
            GroupAnagramsTestCase(
                arrayOf(""),
                listOf(listOf(""))
            ),
            // Example 3
            GroupAnagramsTestCase(
                arrayOf("a"),
                listOf(listOf("a"))
            ),
            // Large test case: Multiple anagram groups with long words
            GroupAnagramsTestCase(
                arrayOf("abcdefg", "gfedcba", "xyz", "zxy", "yxz", "longword", "wordlong"),
                listOf(listOf("abcdefg", "gfedcba"), listOf("xyz", "zxy", "yxz"), listOf("longword", "wordlong"))
            ),
            // Large test case: Many unique words (no anagrams)
            GroupAnagramsTestCase(
                arrayOf("abcd", "efgh", "ijkl", "mnop", "qrst", "uvwx", "yz"),
                listOf(listOf("abcd"), listOf("efgh"), listOf("ijkl"), listOf("mnop"), listOf("qrst"), listOf("uvwx"), listOf("yz"))
            )
        )

        val solution = GroupAnagrams_49()

        for ((index, testCase) in testCases.withIndex()) {
            val resultSorting = solution.groupAnagrams_sorting(testCase.input)
            val resultCounting = solution.groupAnagrams_counting(testCase.input)

            // Sort groups for deterministic comparison
            val normalize = { res: List<List<String>> ->
                res.map { it.sorted() }
                    .sortedWith { a, b ->
                        // Compare a[i] vs b[i] for each index until they differ.
                        val minSize = minOf(a.size, b.size)
                        for (i in 0 until minSize) {
                            val cmp = a[i].compareTo(b[i])
                            if (cmp != 0) return@sortedWith cmp
                        }
                        // If all overlapping elements are equal, compare by length (shorter = less)
                        a.size.compareTo(b.size)
                    }
            }

            val sortedResultSorting = normalize(resultSorting)
            val sortedResultCounting = normalize(resultCounting)
            val sortedExpected = normalize(testCase.expected)

            val passSorting = sortedResultSorting == sortedExpected
            val passCounting = sortedResultCounting == sortedExpected
            val identicalOutputs = sortedResultSorting == sortedResultCounting

            println(
                "Group Anagrams Test ${index + 1}: " +
                (if (passSorting) "PASS" else "FAIL") + " (Sorting) | " +
                (if (passCounting) "PASS" else "FAIL") + " (Counting) | " +
                (if (identicalOutputs) "MATCH" else "DIFFERENT") + " (Comparison)"
            )
        }
    }

    private fun testAddBinary_67() {
        val testCases = listOf(
            // From the LeetCode examples
            AddBinaryTestCase("11", "1", "100"),
            AddBinaryTestCase("1010", "1011", "10101"),
            // Three additional, more complex tests
            AddBinaryTestCase("0", "0", "0"),
            AddBinaryTestCase("1111", "1111", "11110"),
            AddBinaryTestCase("100000", "1", "100001")
        )

        val solution = AddBinary_67()

        for ((index, testCase) in testCases.withIndex()) {
            val result = solution.addBinary(testCase.a, testCase.b)
            val pass = (result == testCase.expected)

            println(
                "AddBinary Test ${index + 1}: " +
                if (pass) "PASS" else "FAIL" +
                " (Expected: ${testCase.expected}, Got: $result)"
            )
        }
    }

    private fun testHammingWeight_191() {
        val testCases = listOf(
            // Provided examples
            HammingWeightTestCase(0xB, 3),             // was 11
            HammingWeightTestCase(0x80, 1),            // was 128
            HammingWeightTestCase(0x7FFFFFFD, 30),     // was 2147483645
            // Two additional complicated ones
            HammingWeightTestCase(0x7FFFFFFF, 31),     // was 2147483647
            HammingWeightTestCase(0x55555555, 16)      // was 1431655765
        )

        val solution = NumberOf1Bits_191()

        for ((index, testCase) in testCases.withIndex()) {
            val result = solution.hammingWeight(testCase.n)
            val pass = (result == testCase.expected)
            println(
                "HammingWeight Test ${index + 1}: " +
                if (pass) "PASS" else "FAIL" +
                " (Expected: ${testCase.expected}, Got: $result)"
            )
        }
    }

    private fun testUniqueNumberOfOccurrences_1207() {
        val testCases = listOf(
            UniqueOccurrencesTestCase(intArrayOf(1, 2, 2, 1, 1, 3), true),
            UniqueOccurrencesTestCase(intArrayOf(1, 2), false),
            UniqueOccurrencesTestCase(intArrayOf(-3, 0, 1, -3, 1, 1, 1, -3, 10, 0), true),
            UniqueOccurrencesTestCase(intArrayOf(4, 4, 4, 4, 3, 3, 3, 3, 2, 2, 2, 1, 1, 1, 1, 5), false),
            UniqueOccurrencesTestCase(intArrayOf(-1000, 1000, -500, 500, 0, 0, 0, -500, 500), false)
        )

        val solution = UniqueNumberOfOccurrences_1207()

        for ((index, testCase) in testCases.withIndex()) {
            val result = solution.uniqueOccurrences(testCase.arr)
            val pass = (result == testCase.expectedResult)

            println(
                "Test ${index + 1}: res = " +
                if (pass) "PASS" else "FAIL" +
                " (Expected: ${testCase.expectedResult}, Got: $result)"
            )
        }
    }
}