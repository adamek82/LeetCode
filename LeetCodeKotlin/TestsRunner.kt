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
        println("Running BalancedBinaryTree_110 tests:")
        testBalancedBinaryTree_110()
        println("Running BinaryTreeLevelOrderTraversal_102 tests:")
        testBinaryTreeLevelOrderTraversal_102()
        println("Running DiameterOfBinaryTree_543 tests:")
        testDiameterOfBinaryTree_543()
        println("Running SameTree_100 tests:")
        testSameTree_100()
        println("Running SymmetricTree_101 tests:")
        testSymmetricTree_101()
        println("Running PathSum_112 tests:")
        testPathSum_112()
        println("Running SubtreeOfAnotherTree_572 tests:")
        testSubtreeOfAnotherTree_572()
        println("Running AverageOfLevelsInBinaryTree_637 tests:")
        testAverageOfLevelsInBinaryTree_637()
        println("Running KthSmallestBST_230 tests:")
        testKthSmallestBST_230()
        println("Running MinimumAbsoluteDifferenceInBST_530 tests:")
        testMinimumAbsoluteDifferenceInBST_530()
        println("Running ValidateBinarySearchTree_98 tests:")
        testValidateBinarySearchTree_98()
        println("Running LowestCommonAncestorOfBinarySearchTree_235 tests:")
        testLowestCommonAncestorOfBinarySearchTree_235()
        println("Running ImplementTrie_208 tests:")
        testImplementTrie_208()
        println("Running SqrtX_69 tests:")
        testSqrtX_69()
    }

    /** Helper to compare double arrays within 1e-5 */
    private fun checkDoubleArraysApproximately(a: DoubleArray, b: DoubleArray, eps: Double = 1e-5): Boolean {
        if (a.size != b.size) return false
        for (i in a.indices) {
            if (kotlin.math.abs(a[i] - b[i]) > eps) return false
        }
        return true
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

    data class BalancedBinaryTreeTestCase(
        val inputValues: List<Int?>,
        val expected: Boolean
    )

    data class BinaryTreeLevelOrderTraversalTestCase(
        val inputValues: List<Int?>,
        val expected: List<List<Int>>
    )

    data class DiameterOfBinaryTreeTestCase(
        val inputValues: List<Int?>,
        val expected: Int
    )

    data class SameTreeTestCase(
        val p: List<Int?>,
        val q: List<Int?>,
        val expected: Boolean
    )

    data class SymmetricTreeTestCase(
        val inputValues: List<Int?>,
        val expected: Boolean
    )

    data class PathSumTestCase(
        val rootValues: List<Int?>,
        val targetSum: Int,
        val expected: Boolean
    )

    data class SubtreeTestCase(
        val rootValues: List<Int?>,
        val subRootValues: List<Int?>,
        val expected: Boolean
    )

    data class AverageOfLevelsInBinaryTreeTestCase(
        val inputValues: List<Int?>,
        val expected: DoubleArray
    )

    data class KthSmallestBSTTestCase(
        val inputValues: List<Int?>,
        val k: Int,
        val expected: Int
    )

    data class MinimumAbsoluteDifferenceInBSTTestCase(
        val inputValues: List<Int?>,
        val expected: Int
    )

    data class ValidateBinarySearchTreeTestCase(
        val inputValues: List<Int?>,
        val expected: Boolean
    )

    data class LowestCommonAncestorOfBSTTestCase(
        val inputValues: List<Int?>,
        val pVal: Int,
        val qVal: Int,
        val expected: Int
    )

    data class TrieTestCase(
        val operations: List<String>,
        val arguments: List<String?>,
        val expectedResults: List<Boolean?>  // null if no boolean result is expected from the operation
    )

    data class SqrtTestCase(
        val x: Int,
        val expected: Int
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

    private fun testBalancedBinaryTree_110() {
        val testCases = listOf(
            // Example 1: [3,9,20,null,null,15,7] -> true
            BalancedBinaryTreeTestCase(listOf(3, 9, 20, null, null, 15, 7), true),

            // Example 2: [1,2,2,3,3,null,null,4,4] -> false
            BalancedBinaryTreeTestCase(listOf(1, 2, 2, 3, 3, null, null, 4, 4), false),

            // Example 3: [] -> true
            BalancedBinaryTreeTestCase(emptyList(), true),

            // Additional Example 4: [2,1,3] -> true
            BalancedBinaryTreeTestCase(listOf(2, 1, 3), true),

            // Additional Example 5 (unbalanced):
            // [1,2,2,3,null,null,3,4,null,null,null] -> false
            BalancedBinaryTreeTestCase(listOf(1, 2, 2, 3, null, null, 3, 4, null, null, null), false)
        )

        val solution = BalancedBinaryTree_110()
        for ((index, testCase) in testCases.withIndex()) {
            val root = TreeUtils.vectorToTree(testCase.inputValues)
            val result = solution.isBalanced(root)
            val pass = (result == testCase.expected)
            println(
                "BalancedBinaryTree Test ${index + 1}: " +
                if (pass) "PASS" else "FAIL" +
                " (Expected: ${testCase.expected}, Got: $result)"
            )
        }
    }

    private fun testBinaryTreeLevelOrderTraversal_102() {
        val solution = BinaryTreeLevelOrderTraversal_102()
        val testCases = listOf(
            // Given Example 1
            BinaryTreeLevelOrderTraversalTestCase(
                inputValues = listOf(3, 9, 20, null, null, 15, 7),
                expected = listOf(
                    listOf(3),
                    listOf(9, 20),
                    listOf(15, 7)
                )
            ),
            // Given Example 2
            BinaryTreeLevelOrderTraversalTestCase(
                inputValues = listOf(1),
                expected = listOf(
                    listOf(1)
                )
            ),
            // Given Example 3 (empty tree)
            BinaryTreeLevelOrderTraversalTestCase(
                inputValues = emptyList(),
                expected = emptyList()
            ),
            // Additional Test 4 (perfect binary tree)
            // Tree shape:
            //         1
            //        / \
            //       2   3
            //      / \ / \
            //     4  5 6  7
            // BFS => [[1],[2,3],[4,5,6,7]]
            BinaryTreeLevelOrderTraversalTestCase(
                inputValues = listOf(1, 2, 3, 4, 5, 6, 7),
                expected = listOf(
                    listOf(1),
                    listOf(2, 3),
                    listOf(4, 5, 6, 7)
                )
            ),
            // Additional Test 5 (mixed nulls)
            // Level-order array => [1,2,3,4,null,null,7]
            // BFS => [[1],[2,3],[4,7]]
            BinaryTreeLevelOrderTraversalTestCase(
                inputValues = listOf(1, 2, 3, 4, null, null, 7),
                expected = listOf(
                    listOf(1),
                    listOf(2, 3),
                    listOf(4, 7)
                )
            )
        )

        for ((index, testCase) in testCases.withIndex()) {
            // Convert level-order list to a TreeNode? (similar to how other tree tests are done)
            val root = TreeUtils.vectorToTree(testCase.inputValues)

            val result = solution.levelOrder(root)
            val pass = (result == testCase.expected)

            println(
                "BinaryTreeLevelOrderTraversal_102 Test ${index + 1}: " +
                if (pass) "PASS" else "FAIL" +
                " (Expected: ${testCase.expected}, Got: $result)"
            )
        }
    }

    private fun testDiameterOfBinaryTree_543() {
        val testCases = listOf(
            // Example 1: Balanced tree with diameter = 3
            //      1
            //     / \
            //    2   3
            //   / \
            //  4   5
            DiameterOfBinaryTreeTestCase(listOf(1, 2, 3, 4, 5), 3),

            // Example 2: Small tree with diameter = 1
            //    1
            //   /
            //  2
            DiameterOfBinaryTreeTestCase(listOf(1, 2), 1),

            // Additional Test 1: Unbalanced left-skewed tree with diameter = 4
            //    1
            //   /
            //  2
            //   \
            //    3
            //     \
            //      4
            //       \
            //        5
            DiameterOfBinaryTreeTestCase(listOf(1, 2, null, 3, null, 4, null, 5), 4),

            // Additional Test 2: Full binary tree with diameter = 4
            //        1
            //       / \
            //      2   3
            //     / \ / \
            //    4  5 6  7
            DiameterOfBinaryTreeTestCase(listOf(1, 2, 3, 4, 5, 6, 7), 4),

            // Additional Test 3: Large right-skewed tree with diameter = 9
            //  1
            //   \
            //    2
            //     \
            //      3
            //       \
            //        4
            //         \
            //          5
            //           \
            //            6
            //             \
            //              7
            //               \
            //                8
            //                 \
            //                  9
            //                   \
            //                   10
            DiameterOfBinaryTreeTestCase(listOf(1, null, 2, null, 3, null, 4, null, 5, null, 6, null, 7, null, 8, null, 9, null, 10), 9)
        )

        val solution = DiameterOfBinaryTree_543()

        for ((index, testCase) in testCases.withIndex()) {
            val root = TreeUtils.vectorToTree(testCase.inputValues)
            val result = solution.diameterOfBinaryTree(root)
            val pass = result == testCase.expected
            println(
                "DiameterOfBinaryTree Test ${index + 1}: " +
                        if (pass) "PASS" else "FAIL" +
                        " (Expected: ${testCase.expected}, Got: $result)"
            )
        }
    }

    private fun testSameTree_100() {
        val testCases = listOf(
            // Example 1: Trees are identical
            SameTreeTestCase(listOf(1, 2, 3), listOf(1, 2, 3), true),

            // Example 2: Different structures
            SameTreeTestCase(listOf(1, 2), listOf(1, null, 2), false),

            // Example 3: Different node values
            SameTreeTestCase(listOf(1, 2, 1), listOf(1, 1, 2), false),

            // Additional Test 1: Identical complex tree
            //       5              5
            //      / \            / \
            //     3   7          3   7
            //    / \   \        / \   \
            //   2   4   8      2   4   8
            SameTreeTestCase(
                listOf(5, 3, 7, 2, 4, null, 8),
                listOf(5, 3, 7, 2, 4, null, 8),
                true
            ),

            // Additional Test 2: Large tree with one differing node
            //       10               10
            //      /  \             /  \
            //     5    15          5    20  <- Different value
            //    / \   / \        / \   / \
            //   3   7 12 17      3   7 12 17
            SameTreeTestCase(
                listOf(10, 5, 15, 3, 7, 12, 17),
                listOf(10, 5, 20, 3, 7, 12, 17),
                false
            )
        )

        val solution = SameTree_100()

        for ((index, testCase) in testCases.withIndex()) {
            val pTree = TreeUtils.vectorToTree(testCase.p)
            val qTree = TreeUtils.vectorToTree(testCase.q)

            val result = solution.isSameTree(pTree, qTree)
            val pass = (result == testCase.expected)

            println(
                "SameTree_100 Test ${index + 1}: " +
                        if (pass) "PASS" else "FAIL" +
                        " (Expected: ${testCase.expected}, Got: $result)"
            )
        }
    }

    private fun testSymmetricTree_101() {
        val testCases = listOf(
            // Example 1: Symmetric tree
            SymmetricTreeTestCase(
                inputValues = listOf(1, 2, 2, 3, 4, 4, 3),
                expected = true
            ),

            // Example 2: Non-symmetric tree
            SymmetricTreeTestCase(
                inputValues = listOf(1, 2, 2, null, 3, null, 3),
                expected = false
            ),

            // Additional complex test 1: Larger symmetric tree
            //         1
            //       /   \
            //      2     2
            //     / \   / \
            //    3   4 4   3
            //   /           \
            //  5             5
            SymmetricTreeTestCase(
                inputValues = listOf(1, 2, 2, 3, 4, 4, 3, 5, null, null, null, null, null, null, 5),
                expected = true
            ),

            // Additional complex test 2: Tree structurally symmetric but with one mismatched value
            //        1
            //       / \
            //      2   2
            //     /     \
            //    3       4  <-- Mismatched values (should be 3 to match)
            SymmetricTreeTestCase(
                inputValues = listOf(1, 2, 2, 3, null, null, 4),
                expected = false
            ),

            // Additional complex test 3: Asymmetric tree with uneven depths
            //        1
            //       / \
            //      2   2
            //       \   \
            //        3   3
            //       /     \
            //      4       4
            SymmetricTreeTestCase(
                inputValues = listOf(1, 2, 2, null, 3, null, 3, 4, null, null, 4),
                expected = false
            )
        )

        val solution = SymmetricTree_101()

        for ((index, testCase) in testCases.withIndex()) {
            val root = TreeUtils.vectorToTree(testCase.inputValues)
            val result = solution.isSymmetric(root)
            val pass = (result == testCase.expected)

            println(
                "SymmetricTree_101 Test ${index + 1}: " +
                        if (pass) "PASS" else "FAIL" +
                        " (Expected: ${testCase.expected}, Got: $result)"
            )
        }
    }

    private fun testPathSum_112() {
        val testCases = listOf(
            PathSumTestCase(listOf(5,4,8,11,null,13,4,7,2,null,null,null,1), 22, true), // Example 1
            PathSumTestCase(listOf(1,2,3), 5, false),                               // Example 2
            PathSumTestCase(emptyList(), 0, false),                                 // Example 3
            // Additional complex case 1
            PathSumTestCase(listOf(1,-2,-3,1,3,-2,null,-1), -1, true),
            // Additional complex case 2
            PathSumTestCase(listOf(10,5,12,4,7,null,null,null,null,1), 18, false)
        )

        val solution = PathSum_112()

        for ((index, testCase) in testCases.withIndex()) {
            val tree = TreeUtils.vectorToTree(testCase.rootValues)
            val result = solution.hasPathSum(tree, testCase.targetSum)
            val pass = (result == testCase.expected)
            println(
                "PathSum_112 Test ${index + 1}: " +
                        if (pass) "PASS" else "FAIL" +
                        " (Expected: ${testCase.expected}, Got: $result)"
            )
        }
    }

    private fun testSubtreeOfAnotherTree_572() {
        val testCases = listOf(
            // Example 1
            SubtreeTestCase(
                rootValues = listOf(3, 4, 5, 1, 2),
                subRootValues = listOf(4, 1, 2),
                expected = true
            ),
            // Example 2
            SubtreeTestCase(
                rootValues = listOf(3, 4, 5, 1, 2, null, null, null, null, 0),
                subRootValues = listOf(4, 1, 2),
                expected = false
            ),
            // Additional complex case 1
            SubtreeTestCase(
                rootValues = listOf(1, 2, 3, 4, 5, 6, 7),
                subRootValues = listOf(2, 4, 5),
                expected = true
            ),
            // Additional complex case 2
            SubtreeTestCase(
                rootValues = listOf(10, 5, 15, 3, 7, null, 18),
                subRootValues = listOf(5, 3, 7),
                expected = true
            ),
            // Additional complex case 3: A subtree appearing deep within the tree
            SubtreeTestCase(
                rootValues = listOf(1, 2, 3, 4, 5, null, null, 6, 7, null, null, null, null, 8, 9),
                subRootValues = listOf(4, 6, 7, null, null, 8, 9),
                expected = true
            )
        )

        val solution = SubtreeOfAnotherTree_572()

        for ((index, testCase) in testCases.withIndex()) {
            val rootTree = TreeUtils.vectorToTree(testCase.rootValues)
            val subRootTree = TreeUtils.vectorToTree(testCase.subRootValues)

            val result = solution.isSubtree(rootTree, subRootTree)
            val pass = (result == testCase.expected)

            println(
                "SubtreeOfAnotherTree Test ${index + 1}: " +
                if (pass) "PASS" else "FAIL" +
                " (Expected: ${testCase.expected}, Got: $result)"
            )
        }
    }

    private fun testAverageOfLevelsInBinaryTree_637() {
        val testCases = listOf(
            // From the problem statement Example 1
            AverageOfLevelsInBinaryTreeTestCase(
                listOf(3, 9, 20, null, null, 15, 7),
                doubleArrayOf(3.0, 14.5, 11.0)
            ),
            // From the problem statement Example 2
            AverageOfLevelsInBinaryTreeTestCase(
                listOf(3, 9, 20, 15, 7),
                doubleArrayOf(3.0, 14.5, 11.0)
            ),
            // From the problem statement Example 3 (empty tree)
            AverageOfLevelsInBinaryTreeTestCase(
                emptyList(),
                doubleArrayOf()
            ),
            // Additional complex example (perfect binary tree)
            // Level by level averages: 1, (2+3)/2=2.5, (4+5+6+7)/4=5.5
            AverageOfLevelsInBinaryTreeTestCase(
                listOf(1, 2, 3, 4, 5, 6, 7),
                doubleArrayOf(1.0, 2.5, 5.5)
            ),
            // Additional complex example (unbalanced)
            // Averages: [1.0, 2.5, 4.5, 6.0, 7.0]
            AverageOfLevelsInBinaryTreeTestCase(
                listOf(1, 2, 3, 4, null, null, 5, 6, null, null, null, null, 7, null, null),
                doubleArrayOf(1.0, 2.5, 4.5, 6.0, 7.0)
            )
        )

        val solution = AverageOfLevelsInBinaryTree_637()

        for ((index, testCase) in testCases.withIndex()) {
            val root = TreeUtils.vectorToTree(testCase.inputValues)
            val result = solution.averageOfLevels(root)
            val pass = checkDoubleArraysApproximately(result, testCase.expected)

            println(
                "AverageOfLevelsInBinaryTree_637 Test ${index + 1}: " +
                if (pass) "PASS" else "FAIL" +
                " (Expected: ${testCase.expected.joinToString()}, Got: ${result.joinToString()})"
            )
        }
    }

    private fun testKthSmallestBST_230() {
        val testCases = listOf(
            // Example 1 (from the problem statement)
            KthSmallestBSTTestCase(
                listOf(3, 1, 4, null, 2),
                k = 1,
                expected = 1
            ),
            // Example 2 (from the problem statement)
            KthSmallestBSTTestCase(
                listOf(5, 3, 6, 2, 4, null, null, 1),
                k = 3,
                expected = 3
            ),
            // Additional Test 3: A more complex BST
            // BFS => [8,3,10,1,6,null,14,null,null,4,7]
            // Inorder => [1,3,4,6,7,8,10,14], so 5th smallest is 7.
            KthSmallestBSTTestCase(
                listOf(8, 3, 10, 1, 6, null, 14, null, null, 4, 7),
                k = 5,
                expected = 7
            ),
            // Additional Test 4: BST with duplicates
            // BFS => [5,3,7,3,4,6,8]
            // Inorder => [3,3,4,5,6,7,8], so 2nd smallest is also 3.
            KthSmallestBSTTestCase(
                listOf(5, 3, 7, 3, 4, 6, 8),
                k = 2,
                expected = 3
            ),
            // Additional Test 5: Right-skewed chain [1, null, 2, null, 3]
            // Inorder => [1,2,3], so 3rd smallest is 3.
            KthSmallestBSTTestCase(
                listOf(1, null, 2, null, 3),
                k = 3,
                expected = 3
            )
        )

        val solution = KthSmallestElementInBST_230()  // Replace with your actual class name if different
        for ((index, testCase) in testCases.withIndex()) {
            val root = TreeUtils.vectorToTree(testCase.inputValues)
            val result = solution.kthSmallest(root, testCase.k)
            val pass = (result == testCase.expected)

            println(
                "KthSmallestBST_230 Test ${index + 1}: " +
                if (pass) "PASS" else "FAIL" +
                " (Expected: ${testCase.expected}, Got: $result)"
            )
        }
    }

    private fun testMinimumAbsoluteDifferenceInBST_530() {
        val testCases = listOf(
            // Example 1 (from the problem statement)
            MinimumAbsoluteDifferenceInBSTTestCase(
                listOf(4, 2, 6, 1, 3),
                expected = 1
            ),
            // Example 2 (from the problem statement)
            MinimumAbsoluteDifferenceInBSTTestCase(
                listOf(1, 0, 48, null, null, 12, 49),
                expected = 1
            ),
            // Additional Test 3: Perfect BST
            // Level-order => [4,2,6,1,3,5,7]
            // Sorted => [1,2,3,4,5,6,7], min gap is 1
            MinimumAbsoluteDifferenceInBSTTestCase(
                listOf(4, 2, 6, 1, 3, 5, 7),
                expected = 1
            ),
            // Additional Test 4: Skewed BST (all right children)
            // Input => [1, null, 2, null, 3, null, 4]
            // Sorted => [1,2,3,4], min gap = 1
            MinimumAbsoluteDifferenceInBSTTestCase(
                listOf(1, null, 2, null, 3, null, 4),
                expected = 1
            ),
            // Additional Test 5: BST with bigger gaps
            // Input => [10,5,15,3,7,12,20,2,null,null,9,null,null,null,25]
            // Sorted => [2,3,5,7,9,10,12,15,20,25], min gap = 1 (between 2 & 3, or 9 & 10)
            MinimumAbsoluteDifferenceInBSTTestCase(
                listOf(10,5,15,3,7,12,20,2,null,null,9,null,null,null,25),
                expected = 1
            )
        )

        val solution = MinimumAbsoluteDifferenceInBST_530()
        for ((index, testCase) in testCases.withIndex()) {
            val root = TreeUtils.vectorToTree(testCase.inputValues)
            val result = solution.getMinimumDifference(root)
            val pass = (result == testCase.expected)

            println(
                "MinimumAbsoluteDifferenceInBST_530 Test ${index + 1}: " +
                if (pass) "PASS" else "FAIL" +
                " (Expected: ${testCase.expected}, Got: $result)"
            )
        }
    }

    private fun testValidateBinarySearchTree_98() {
        println("Running ValidateBinarySearchTree_98 tests:")

        val testCases = listOf(
            // Example 1 from the problem statement
            ValidateBinarySearchTreeTestCase(
                listOf(2, 1, 3),
                expected = true
            ),
            // Example 2 from the problem statement
            ValidateBinarySearchTreeTestCase(
                listOf(5, 1, 4, null, null, 3, 6),
                expected = false
            ),
            // Additional Test 3: Right-skewed tree [1,null,2,null,3,null,4]
            ValidateBinarySearchTreeTestCase(
                listOf(1, null, 2, null, 3, null, 4),
                expected = true
            ),
            // Additional Test 4: All duplicates [2,2,2] => invalid BST
            ValidateBinarySearchTreeTestCase(
                listOf(2, 2, 2),
                expected = false
            ),
            // Additional Test 5: Larger valid BST
            // Level-order => [10,5,15,2,7,12,20]
            ValidateBinarySearchTreeTestCase(
                listOf(10, 5, 15, 2, 7, 12, 20),
                expected = true
            )
        )

        val solution = ValidateBinarySearchTree_98()

        for ((index, testCase) in testCases.withIndex()) {
            val root = TreeUtils.vectorToTree(testCase.inputValues)
            val result = solution.isValidBST(root)
            val pass = (result == testCase.expected)

            println(
                "ValidateBinarySearchTree_98 Test ${index + 1}: " +
                if (pass) "PASS" else "FAIL" +
                " (Expected: ${testCase.expected}, Got: $result)"
            )
        }
    }

    private fun testLowestCommonAncestorOfBinarySearchTree_235() {
        println("Running LowestCommonAncestorOfBinarySearchTree_235 tests:")

        val testCases = listOf(
            // Example 1 from the problem statement
            LowestCommonAncestorOfBSTTestCase(
                listOf(6, 2, 8, 0, 4, 7, 9, null, null, 3, 5),
                pVal = 2,
                qVal = 8,
                expected = 6
            ),
            // Example 2 from the problem statement
            LowestCommonAncestorOfBSTTestCase(
                listOf(6, 2, 8, 0, 4, 7, 9, null, null, 3, 5),
                pVal = 2,
                qVal = 4,
                expected = 2
            ),
            // Example 3 from the problem statement
            LowestCommonAncestorOfBSTTestCase(
                listOf(2, 1),
                pVal = 2,
                qVal = 1,
                expected = 2
            ),
            // Additional Test 4: LCA is the root
            // BFS => [5,3,8,2,4,7,9]
            // pVal=2, qVal=9 => LCA is 5
            LowestCommonAncestorOfBSTTestCase(
                listOf(5, 3, 8, 2, 4, 7, 9),
                pVal = 2,
                qVal = 9,
                expected = 5
            ),
            // Additional Test 5: Deeper nodes
            // BFS => [10, 5, 15, null, null, 12, 20]
            // pVal=12, qVal=20 => LCA is 15
            LowestCommonAncestorOfBSTTestCase(
                listOf(10, 5, 15, null, null, 12, 20),
                pVal = 12,
                qVal = 20,
                expected = 15
            )
        )

        val solution = LowestCommonAncestorOfBinarySearchTree_235()

        for ((index, testCase) in testCases.withIndex()) {
            val root = TreeUtils.vectorToTree(testCase.inputValues)

            // Helper function to find a node by its value
            fun findNodeByValue(node: TreeNode?, value: Int): TreeNode? {
                if (node == null) return null
                if (node.value == value) return node
                return if (value < node.value) {
                    findNodeByValue(node.left, value)
                } else {
                    findNodeByValue(node.right, value)
                }
            }

            val pNode = findNodeByValue(root, testCase.pVal)
            val qNode = findNodeByValue(root, testCase.qVal)
            val lca = solution.lowestCommonAncestor(root, pNode, qNode)
            val pass = (lca?.value == testCase.expected)

            println(
                "LowestCommonAncestorOfBinarySearchTree_235 Test ${index + 1}: " +
                if (pass) "PASS" else "FAIL" +
                " (Expected: ${testCase.expected}, Got: ${lca?.value})"
            )
        }
    }

    private fun testImplementTrie_208() {
        val testCases = listOf(
            // Example 1
            TrieTestCase(
                operations = listOf("Trie", "insert", "search", "search", "startsWith", "insert", "search"),
                arguments = listOf(null, "apple", "apple", "app", "app", "app", "app"),
                expectedResults = listOf(null, null, true, false, true, null, true)
            ),
            // Example 2: Overlapping words
            TrieTestCase(
                operations = listOf("Trie", "insert", "insert", "search", "search", "startsWith"),
                arguments = listOf(null, "apple", "applause", "apple", "applause", "app"),
                expectedResults = listOf(null, null, null, true, true, true)
            ),
            // Example 3: Single-character operations
            TrieTestCase(
                operations = listOf("Trie", "insert", "search", "startsWith", "search"),
                arguments = listOf(null, "a", "a", "a", "b"),
                expectedResults = listOf(null, null, true, true, false)
            ),
            // Example 4: No matching prefix
            TrieTestCase(
                operations = listOf("Trie", "insert", "insert", "startsWith", "startsWith", "search"),
                arguments = listOf(null, "car", "cart", "ca", "cat", "carrot"),
                expectedResults = listOf(null, null, null, true, false, false)
            ),
            // Example 5: Large input set
            TrieTestCase(
                operations = listOf("Trie", "insert", "insert", "insert", "search", "search", "startsWith"),
                arguments = listOf(null, "dictionary", "dictionaries", "dictator", "dictionary", "dictionaries", "dict"),
                expectedResults = listOf(null, null, null, null, true, true, true)
            )
        )

        for ((index, testCase) in testCases.withIndex()) {
            var trie: Trie? = null

            for (opIndex in testCase.operations.indices) {
                val op = testCase.operations[opIndex]
                val arg = testCase.arguments[opIndex]
                val expected = testCase.expectedResults[opIndex]

                when (op) {
                    "Trie" -> {
                        trie = Trie()
                        println("Operation: Trie() -> null")
                    }
                    "insert" -> {
                        trie!!.insert(arg!!)
                        println("Operation: insert(\"$arg\") -> null")
                    }
                    "search" -> {
                        val result = trie!!.search(arg!!)
                        print("Operation: search(\"$arg\") -> $result")
                        if (expected != null && result == expected) {
                            println(" [PASS]")
                        } else {
                            println(" [FAIL]")
                        }
                    }
                    "startsWith" -> {
                        val result = trie!!.startsWith(arg!!)
                        print("Operation: startsWith(\"$arg\") -> $result")
                        if (expected != null && result == expected) {
                            println(" [PASS]")
                        } else {
                            println(" [FAIL]")
                        }
                    }
                }
            }
            println()
        }
    }

    private fun testSqrtX_69() {
        val testCases = listOf(
            SqrtTestCase(4, 2),           // Example 1
            SqrtTestCase(8, 2),           // Example 2
            SqrtTestCase(0, 0),           // Edge case: x = 0
            SqrtTestCase(50, 7),          // Additional test case: typical number (sqrt(50) ≈ 7.07)
            SqrtTestCase(2147483647, 46340) // Overflow-avoidance test with max Int
        )

        val solution = SqrtX_69()
        for ((index, testCase) in testCases.withIndex()) {
            val result = solution.mySqrt(testCase.x)
            val pass = (result == testCase.expected)
            println(
                "SqrtX_69 Test ${index + 1}: " +
                (if (pass) "PASS" else "FAIL") +
                " (Input: ${testCase.x}, Expected: ${testCase.expected}, Got: $result)"
            )
        }
    }
}