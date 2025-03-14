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
        println("Running SquaresOfSortedArray_977 tests:")
        testSquaresOfSortedArray_977()
        println("Running MinSubArrayLen_209 tests:")
        testMinSubArrayLen_209()
        println("Running PermutationInString_567 tests:")
        testPermutationInString_567()
        println("Running LongestRepeatingCharacterReplacement_424 tests:")
        testLongestRepeatingCharacterReplacement_424()
        println("Running LongestConsecutiveSequence_128 tests:")
        testLongestConsecutiveSequence_128()
        println("Running MaxConsecutiveOnesIII_1004 tests:")
        testMaxConsecutiveOnesIII_1004()
        println("Running IslandPerimeter_463 tests:")
        testIslandPerimeter_463()
        println("Running MaximumAverageSubarrayI_643 tests:")
        testMaximumAverageSubarrayI_643()
        println("Running InvertBinaryTree_226 tests:")
        testInvertBinaryTree_226()
        println("Running MaximumDepthOfBinaryTree_194 tests:")
        testMaximumDepthOfBinaryTree_104()
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

    data class SquaresTestCase(
        val input: IntArray,
        val expected: IntArray
    )

    data class MinSubArrayLenTestCase(
        val target: Int,
        val nums: IntArray,
        val expectedResult: Int
    )

    data class PermutationInStringTestCase(
        val s1: String,
        val s2: String,
        val expectedResult: Boolean
    )

    data class LongestRepeatingCharReplacementTestCase(
        val s: String,
        val k: Int,
        val expected: Int
    )

    data class LongestConsecutiveSequenceTestCase(
        val nums: IntArray,
        val expected: Int
    )

    data class MaxConsecutiveOnesIIITestCase(
        val nums: IntArray,
        val k: Int,
        val expected: Int
    )

    data class IslandPerimeterTestCase(
        val grid: Array<IntArray>,
        val expected: Int
    )

    data class MaximumAverageSubarrayITestCase(
        val nums: IntArray,
        val k: Int,
        val expected: Double
    )

    data class InvertBinaryTreeTestCase(
        val inputValues: List<Int?>,
        val expectedValues: List<Int?>
    )

    data class MaximumDepthOfBinaryTreeCase(
        val inputValues: List<Int?>,
        val expectedValue: Int
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

    private fun testSquaresOfSortedArray_977() {
        val testCases = listOf(
            SquaresTestCase(intArrayOf(-4, -1, 0, 3, 10), intArrayOf(0, 1, 9, 16, 100)),
            SquaresTestCase(intArrayOf(-7, -3, 2, 3, 11), intArrayOf(4, 9, 9, 49, 121)),
            SquaresTestCase(intArrayOf(-10, -5, -2, 0, 1, 4, 8), intArrayOf(0, 1, 4, 16, 25, 64, 100)),
            SquaresTestCase(intArrayOf(-8, -7, -6, -5, -4, -3, -2, -1), intArrayOf(1, 4, 9, 16, 25, 36, 49, 64)),
            SquaresTestCase(intArrayOf(0, 1, 2, 3, 4, 5, 6, 7, 8, 9), intArrayOf(0, 1, 4, 9, 16, 25, 36, 49, 64, 81))
        )

        val solution = SquaresOfSortedArray_977()

        for ((index, testCase) in testCases.withIndex()) {
            val result = solution.sortedSquares(testCase.input)
            val pass = (result.contentEquals(testCase.expected))

            println(
                "SquaresOfSortedArray Test ${index + 1}: " +
                if (pass) "PASS" else "FAIL" +
                " (Expected: ${testCase.expected.joinToString()}, Got: ${result.joinToString()})"
            )
        }
    }

    private fun testMinSubArrayLen_209() {
        val testCases = listOf(
            // 3 examples from the problem statement:
            MinSubArrayLenTestCase(7, intArrayOf(2, 3, 1, 2, 4, 3), 2),
            MinSubArrayLenTestCase(4, intArrayOf(1, 4, 4), 1),
            MinSubArrayLenTestCase(11, intArrayOf(1, 1, 1, 1, 1, 1, 1, 1), 0),

            // 2 additional, more complex tests:
            MinSubArrayLenTestCase(100, intArrayOf(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 50), 9),
            MinSubArrayLenTestCase(15, intArrayOf(5, 1, 3, 5, 10, 7, 4, 9, 2, 8), 2)
        )

        val solution = MinimumSizeSubarraySum_209()

        for ((index, testCase) in testCases.withIndex()) {
            val result = solution.minSubArrayLen(testCase.target, testCase.nums)
            val pass = (result == testCase.expectedResult)
            println(
                "MinSubArrayLen Test ${index + 1}: " +
                    if (pass) "PASS" else "FAIL" +
                    " (Expected: ${testCase.expectedResult}, Got: $result)"
            )
        }
    }

    private fun testPermutationInString_567() {
        val testCases = listOf(
            // Example cases
            PermutationInStringTestCase("ab", "eidbaooo", true),
            PermutationInStringTestCase("ab", "eidboaoo", false),

            // Additional complex cases
            PermutationInStringTestCase("abc", "cbabcacab", true),  // Contains permutation at index 2
            PermutationInStringTestCase("xyz", "yxzxyzxyz", true),  // Multiple valid permutations
            PermutationInStringTestCase("aabb", "eidbaabooo", true) // Contains permutation "baab"
        )

        val solution = PermutationInString_567()

        for ((index, testCase) in testCases.withIndex()) {
            val result = solution.checkInclusion(testCase.s1, testCase.s2)
            val pass = (result == testCase.expectedResult)

            println(
                "PermutationInString Test ${index + 1}: " +
                if (pass) "PASS" else "FAIL" +
                " (Expected: ${testCase.expectedResult}, Got: $result)"
            )
        }
    }

    private fun testLongestRepeatingCharacterReplacement_424() {
        // 2 examples from the problem statement + 3 more complex ones
        val testCases = listOf(
            LongestRepeatingCharReplacementTestCase("ABAB", 2, 4),       // Example 1
            LongestRepeatingCharReplacementTestCase("AABABBA", 1, 4),    // Example 2
            LongestRepeatingCharReplacementTestCase("BABABA", 3, 6),     // Turn all 'A' to 'B'
            LongestRepeatingCharReplacementTestCase("ABCDE", 2, 3),      // Best is a substring of length 3 by transforming 2 chars
            LongestRepeatingCharReplacementTestCase("ABBBBAA", 2, 6)     // Transform 2 'A's in a 6-length substring
        )

        val solution = LongestRepeatingCharacterReplacement_424()

        for ((index, testCase) in testCases.withIndex()) {
            val result = solution.characterReplacement(testCase.s, testCase.k)
            val pass = (result == testCase.expected)
            println(
                "LongestRepeatingCharacterReplacement Test ${index + 1}: " +
                        if (pass) "PASS" else "FAIL" +
                        " (Expected: ${testCase.expected}, Got: $result)"
            )
        }
    }

    private fun testLongestConsecutiveSequence_128() {
        val testCases = listOf(
            // 3 examples from the problem statement:
            LongestConsecutiveSequenceTestCase(intArrayOf(100, 4, 200, 1, 3, 2), 4),
            LongestConsecutiveSequenceTestCase(intArrayOf(0, 3, 7, 2, 5, 8, 4, 6, 0, 1), 9),
            LongestConsecutiveSequenceTestCase(intArrayOf(1, 0, 1, 2), 3),

            // 2 additional, more complex tests:
            LongestConsecutiveSequenceTestCase(intArrayOf(-1, 0, 1, 2, 3, 7, 8, 10, 11, 12), 5),
            LongestConsecutiveSequenceTestCase(intArrayOf(-10, -9, -8, -100, 200, 205, 203, 202, 204, 201), 6)
        )

        val solution = LongestConsecutiveSequence_128()

        for ((index, testCase) in testCases.withIndex()) {
            val result = solution.longestConsecutive(testCase.nums)
            val pass = (result == testCase.expected)

            println(
                "LongestConsecutiveSequence Test ${index + 1}: " +
                if (pass) "PASS" else "FAIL" +
                " (Expected: ${testCase.expected}, Got: $result)"
            )
        }
    }

    private fun testMaxConsecutiveOnesIII_1004() {
        val testCases = listOf(
            // 2 examples from the problem statement:
            MaxConsecutiveOnesIIITestCase(intArrayOf(1,1,1,0,0,0,1,1,1,1,0), 2, 6),
            MaxConsecutiveOnesIIITestCase(intArrayOf(0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1), 3, 10),

            // 3 additional, more complex tests:
            MaxConsecutiveOnesIIITestCase(intArrayOf(1,0,1,1,0,1), 1, 4),
            MaxConsecutiveOnesIIITestCase(intArrayOf(0,0,0,1,1,1,0,1,1,1), 2, 8),
            MaxConsecutiveOnesIIITestCase(intArrayOf(1,1,0,1,0,0,1,1), 3, 8)
        )

        val solution = MaxConsecutiveOnesIII_1004()

        for ((index, testCase) in testCases.withIndex()) {
            val result = solution.longestOnes(testCase.nums, testCase.k)
            val pass = (result == testCase.expected)
            println(
                "MaxConsecutiveOnesIII Test ${index + 1}: " +
                if (pass) "PASS" else "FAIL" +
                " (Expected: ${testCase.expected}, Got: $result)"
            )
        }
    }

    private fun testIslandPerimeter_463() {
        val testCases = listOf(
            // Example 1
            IslandPerimeterTestCase(
                arrayOf(
                    intArrayOf(0, 1, 0, 0),
                    intArrayOf(1, 1, 1, 0),
                    intArrayOf(0, 1, 0, 0),
                    intArrayOf(1, 1, 0, 0)
                ),
                16
            ),
            // Example 2
            IslandPerimeterTestCase(
                arrayOf(intArrayOf(1)),
                4
            ),
            // Example 3
            IslandPerimeterTestCase(
                arrayOf(intArrayOf(1, 0)),
                4
            ),
            // Additional complex example 1
            IslandPerimeterTestCase(
                arrayOf(
                    intArrayOf(1, 1, 1, 0),
                    intArrayOf(1, 1, 0, 0),
                    intArrayOf(1, 0, 0, 0)
                ),
                12
            ),
            // Additional complex example 2
            IslandPerimeterTestCase(
                arrayOf(
                    intArrayOf(0, 0, 0, 0, 0),
                    intArrayOf(0, 1, 1, 1, 0),
                    intArrayOf(0, 1, 1, 1, 0),
                    intArrayOf(0, 0, 1, 0, 0),
                    intArrayOf(0, 0, 0, 0, 0)
                ),
                12
            )
        )

        val solution = IslandPerimeter_463()
        for ((index, testCase) in testCases.withIndex()) {
            val result = solution.islandPerimeter(testCase.grid)
            val pass = (result == testCase.expected)
            println(
                "IslandPerimeter Test ${index + 1}: " +
                if (pass) "PASS" else "FAIL" +
                " (Expected: ${testCase.expected}, Got: $result)"
            )
        }
    }

    private fun testMaximumAverageSubarrayI_643() {
        val testCases = listOf(
            // Example 1 (from the problem statement)
            MaximumAverageSubarrayITestCase(intArrayOf(1,12,-5,-6,50,3), 4, 12.75),
            // Example 2 (from the problem statement)
            MaximumAverageSubarrayITestCase(intArrayOf(5), 1, 5.0),

            // Three additional complex tests
            MaximumAverageSubarrayITestCase(intArrayOf(0, 0, 0, 0), 4, 0.0),
            MaximumAverageSubarrayITestCase(intArrayOf(-1, -2, -3, -4, -5, 5, 5, 5, 5, 5), 5, 5.0),
            MaximumAverageSubarrayITestCase(intArrayOf(1,2,3,4,5,6,7,8), 3, 7.0)
        )

        val solution = MaximumAverageSubarrayI643()

        for ((index, testCase) in testCases.withIndex()) {
            val result = solution.findMaxAverage(testCase.nums, testCase.k)
            val pass = kotlin.math.abs(result - testCase.expected) < 1e-5
            println(
                "MaximumAverageSubarrayI Test ${index + 1}: " +
                if (pass) "PASS" else "FAIL" +
                " (Expected: ${testCase.expected}, Got: $result)"
            )
        }
    }

    private fun testInvertBinaryTree_226() {
        val solution = InvertBinaryTree_226()
    
        // 1) Define your test cases in level-order form
        val testCases = listOf(
            // Example 1 (from the problem statement)
            InvertBinaryTreeTestCase(
                inputValues = listOf(4, 2, 7, 1, 3, 6, 9),
                expectedValues = listOf(4, 7, 2, 9, 6, 3, 1)
            ),
            // Example 2 (from the problem statement)
            InvertBinaryTreeTestCase(
                inputValues = listOf(2, 1, 3),
                expectedValues = listOf(2, 3, 1)
            ),
            // Example 3 (Empty tree)
            InvertBinaryTreeTestCase(
                inputValues = emptyList(),
                expectedValues = emptyList()
            ),
            // Additional test case 1 (Single node)
            InvertBinaryTreeTestCase(
                inputValues = listOf(1),
                expectedValues = listOf(1)
            ),
            // Additional test case 2 (More complex tree)
            //
            // Original tree:
            //        8
            //       / \
            //      3  10
            //     / \   \
            //    1   6   14
            //       / \
            //      4   7
            //     /
            //    13
            //
            // Level-order (inputValues):
            // [8, 3, 10, 1, 6, null, 14, null, null, 4, 7, 13]
            //
            // Inverted tree:
            //        8
            //       / \
            //     10   3
            //     /    / \
            //   14    6   1
            //    \   / \
            //    13 7  4
            //
            // Level-order (expectedValues):
            // [8, 10, 3, 14, null, 6, 1, null, 13, 7, 4]
            InvertBinaryTreeTestCase(
                inputValues = listOf(8, 3, 10, 1, 6, null, 14, null, null, 4, 7, 13),
                expectedValues = listOf(8, 10, 3, 14, null, 6, 1, null, 13, 7, 4)
            )
        )
    
        // 2) For each test case, convert the lists into trees, invert, and check
        for ((index, testCase) in testCases.withIndex()) {
            val inputTree = TreeUtils.vectorToTree(testCase.inputValues)
            val expectedTree = TreeUtils.vectorToTree(testCase.expectedValues)
    
            val result = solution.invertTree(inputTree)
            val pass = TreeUtils.isSameTree(result, expectedTree)
    
            println("InvertBinaryTree Test ${index + 1}: ${if (pass) "PASS" else "FAIL"}")
        }
    }

    private fun testMaximumDepthOfBinaryTree_104() {
        val solution = MaximumDepthOfBinaryTree_104()

        val testCases = listOf(
            // Example 1 (from the problem statement)
            MaximumDepthOfBinaryTreeCase(
                inputValues = listOf(3, 9, 20, null, null, 15, 7),
                expectedValue = 3
            ),
            // Example 2 (from the problem statement)
            MaximumDepthOfBinaryTreeCase(
                inputValues = listOf(1, null, 2),
                expectedValue = 2
            ),
            // Additional Test Case 1: Empty tree
            MaximumDepthOfBinaryTreeCase(
                inputValues = listOf(), // No nodes
                expectedValue = 0
            ),
             // Additional Test Case 2: Single node tree
            MaximumDepthOfBinaryTreeCase(
                inputValues = listOf(1), // Only root node
                expectedValue = 1
            ),
            // Additional Test Case 3: Unbalanced left-skewed tree
            MaximumDepthOfBinaryTreeCase(
                inputValues = listOf(1, 2, null, 3, null, 4, null),
                expectedValue = 4
            )
        )
        for ((index, testCase) in testCases.withIndex()) {
            val inputTree = TreeUtils.vectorToTree(testCase.inputValues)
            val result = solution.maxDepth(inputTree)
            val pass = (result == testCase.expectedValue)
            println(
                "MaximumDepthOfBinaryTree Test ${index + 1}: " +
                if (pass) "PASS" else "FAIL" +
                " (Expected: ${testCase.expectedValue}, Got: $result)"
            )
        }
    }
}