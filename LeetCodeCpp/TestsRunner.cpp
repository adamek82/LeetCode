#include <climits>
#include <iostream>
#include <string>
#include <vector>
#include <optional>
#include <cmath>
#include <variant>
#include <numeric>
#include "TestCases.h"
#include "TestUtils.h"
#include "TestRegistry.h"
#include "TestsGraphs.h"
#include "TestsTrees.h"
#include "TestsLinkedLists.h"
#include "TestsDynamicProgramming.h"
#include "TestsHashmapsSets.h"
#include "TestsTwoPointers.h"
#include "TestsStacks.h"
#include "TestsBinarySearch.h"
#include "ListUtils.h"
#include "TreeUtils.h"
#include "BestTimeToBuyAndSellStock_121.h"
#include "SpiralMatrix_54.h"
#include "KthLargestElementInArray_215.h"
#include "MinHeap.h"
#include "RotateImage_48.h"
#include "MergeIntervals_56.h"
#include "MergeKSortedLists_23.h"
#include "ProductOfArrayExceptSelf.h"
#include "MajorityElement_169.h"
#include "WordSearch_79.h"
#include "ValidSudoku_36.h"
#include "AllOOneDataStructure_432.h"
#include "ZigzagConversion_6.h"
#include "HIndex_274.h"
#include "SortColors_75.h"
#include "RemoveDuplicatesFromSortedArrayII_80.h"
#include "BestTimeToBuyAndSellStockII_122.h"
#include "ValidAnagram_242.h"
#include "AnalyzeUserWebsiteVisitPattern1152.h"
#include "GroupAnagrams_49.h"
#include "FindCelebrity_277.h"
#include "LongestConsecutiveSequence_128.h"
#include "FizzBuzz_412.h"
#include "LongestRepeatingCharacterReplacement_424.h"
#include "SortCharactersByFrequency_451.h"
#include "TopKFrequentWords_692.h"
#include "MaximumAverageSubarrayI_643.h"
#include "MaxConsecutiveOnesIII_1004.h"
#include "LongestSubstringWithoutRepeatingCharacters_3.h"
#include "MinimumSizeSubarraySum_209.h"
#include "PermutationInString_567.h"
#include "TwoSum_1.h"
#include "MergeSortedArray_88.h"
#include "RemoveElement_27.h"
#include "MaximumNumberOfBalloons_1189.h"
#include "AddBinary_67.h"
#include "FindPivotIndex_724.h"
#include "NumberOf1Bits_191.h"
#include "KClosestPointsToOrigin_973.h"
#include "FindSafestPathInGrid_2812.h"
#include "ValidNumber_65.h"
#include "JewelsAndStones_771.h"
#include "MissingNumber_268.h"
#include "ContainsDuplicate_217.h"
#include "LastStoneWeight_1046.h"
#include "TopKFrequentElements_347.h"
#include "FindClosestNumberToZero_2239.h"
#include "MergeStringsAlternately_1768.h"
#include "RomanToInteger_13.h"
#include "IsSubsequence_392.h"
#include "LongestCommonPrefix_14.h"
#include "SummaryRanges_228.h"
#include "RemoveDuplicates_26.h"
#include "Subsets_78.h"
#include "Permutations_46.h"
#include "Combinations_77.h"
#include "LetterCombinations_17.h"
#include "CombinationSum_39.h"
#include "GenerateParentheses_22.h"
#include "ExamRoom_855.h"
#include "LongestIncreasingPathInMatrix_329.h"
#include "SplitTheArray_3046.h"
#include "RansomNote_383.h"
#include "IslandPerimeter_463.h"
#include "AppleRedistributionIntoBoxes_3074.h"
#include "UniqueNumberOfOccurrences_1207.h"
#include "NumberOfEmployeesWhoMetTarget_2798.h"
#include "Base7_504.h"
#include "SingleNumber_136.h"
#include "DesignHashMap_706.h"
#include "ShuffleAnArray_384.h"
#include "PascalsTriangle_118.h"
#include "SlidingPuzzle_773.h"
#include "SudokuSolver_37.h"

using namespace std;
using namespace TestUtils;
using namespace TestCases;

class TestsRunner {
public:
    // ============================================================================
    // Arrays & Strings
    // ============================================================================

    /* Simple iteration, counting, and basic array/string traversal */

    static bool fizzBuzz_412_tests() {
        vector<FizzBuzzTestCase> testCases = {
            {
                3,
                {"1", "2", "Fizz"}
            },
            {
                5,
                {"1", "2", "Fizz", "4", "Buzz"}
            },
            {
                15,
                {"1", "2", "Fizz", "4", "Buzz", "Fizz", "7", "8", "Fizz", "Buzz", "11", "Fizz", "13", "14", "FizzBuzz"}
            },
            {
                16,
                {"1", "2", "Fizz", "4", "Buzz", "Fizz", "7", "8", "Fizz", "Buzz", "11", "Fizz", "13", "14", "FizzBuzz", "16"}
            },
            {
                30,
                {"1", "2", "Fizz", "4", "Buzz", "Fizz", "7", "8", "Fizz", "Buzz", "11", "Fizz", "13", "14", "FizzBuzz",
                "16", "17", "Fizz", "19", "Buzz", "Fizz", "22", "23", "Fizz", "Buzz", "26", "Fizz", "28", "29", "FizzBuzz"}
            }
        };

        FizzBuzz_412 sol;

        for (size_t i = 0; i < testCases.size(); ++i) {
            const auto& tc = testCases[i];
            auto got = sol.fizzBuzz(tc.n);

            const string label =
                "FizzBuzz 412 Test " + to_string(i + 1) + " (n=" + to_string(tc.n) + ")";
            REQUIRE_ASSERT(assertEqGeneric(label, tc.expected, got,
                                           [](vector<string> v) { return v; },
                                           PrintQuotedStrings{}));
        }

        return true;
    }

    static bool numberOfEmployeesWhoMetTarget_2798_tests() {
        using namespace TestCases;

        vector<NumberOfEmployeesWhoMetTargetTestCase> testCases = {
            // Examples from the problem statement
            {{0, 1, 2, 3, 4}, 2, 3},
            {{5, 1, 4, 2, 2}, 6, 0},

            // Additional edge / sanity tests
            {{0},             0, 1}, // target 0, everyone meets it
            {{0},             1, 0}, // nobody meets target
            {{3, 3, 3},       3, 3}, // all meet target exactly
            {{1, 2, 3, 4, 5}, 5, 1}, // exactly one employee meets target
        };

        NumberOfEmployeesWhoMetTarget_2798 sol;

        for (size_t i = 0; i < testCases.size(); ++i) {
            auto hours1 = testCases[i].hours;
            auto hours2 = testCases[i].hours;

            int gotLoop = sol.numberOfEmployeesWhoMetTarget_CountingLoop(
                hours1, testCases[i].target);
            int gotIf = sol.numberOfEmployeesWhoMetTarget_CountIf(
                hours2, testCases[i].target);

            const string base =
                "Number of Employees Who Met Target 2798 Test " + to_string(i + 1);
            REQUIRE_ASSERT(assertEqScalar(
                base + " [CountingLoop]",
                testCases[i].expected,
                gotLoop));
            REQUIRE_ASSERT(assertEqScalar(
                base + " [CountIf]",
                testCases[i].expected,
                gotIf));
        }

        return true;
    }

    static bool mergeStringsAlternately_1768_tests() {
        vector<MergeStringsAlternatelyTestCase> tests = {
            // From the statement
            {"abc",   "pqr",   "apbqcr"},
            {"ab",    "pqrs",  "apbqrs"},
            {"abcd",  "pq",    "apbqcd"},
            // Additional
            {"z",     "abcdef","zabcdef"},  // word1 shorter by far
            {"ace",   "bdf",   "abcdef"},   // equal lengths
            {"aaaaa", "b",     "abaaaa"}    // word2 very short
        };

        MergeStringsAlternately_1768 sol;

        for (size_t i = 0; i < tests.size(); ++i) {
            string got = sol.mergeAlternately(tests[i].word1, tests[i].word2);

            const string label = "Merge Strings Alternately 1768 Test " + to_string(i + 1);
            REQUIRE_ASSERT(assertEqScalar(label, tests[i].expected, got));
        }

        return true;
    }

    static bool findClosestNumber_2239_tests() {
        vector<FindClosestNumberToZeroTestCase> tests = {
            // From the statement
            {{-4,-2,1,4,8}, 1},
            {{2,-1,1},      1},

            // Additional
            {{0,5,-5},              0},   // zero present → always closest
            {{-7,-3,-2,-2},        -2},   // all negatives; tie between -2s → -2
            {{-100000,100000}, 100000},   // extremes; tie → prefer positive
            {{-1,1,2,-2},           1}    // tie at distance 1 → prefer +1
        };

        FindClosestNumberToZero_2239 sol;

        for (size_t i = 0; i < tests.size(); ++i) {
            int got = sol.findClosestNumber(tests[i].nums);

            const string label = "Find Closest Number to Zero 2239 Test " + to_string(i + 1);
            REQUIRE_ASSERT(assertEqScalar(label, tests[i].expected, got));
        }

        return true;
    }

    /* Sequence comparison, prefix checks, and simple string parsing */

    static bool isSubsequence_392_tests() {
        vector<IsSubsequence392TestCase> tests = {
            {"abc",     "ahbgdc",   true},
            {"axc",     "ahbgdc",   false},
            {"",        "ahbgdc",   true},
            {"a",       "",         false},
            {"aaaaaa",  "baaaacaa", true},
            {"abc",     "acb",      false}
        };

        // Single-query tests across all three methods
        for (size_t i = 0; i < tests.size(); ++i) {
            const string& s = tests[i].s;
            const string& t = tests[i].t;

            IsSubsequence_392 plain;
            bool a = plain.isSubsequence_TwoPointer(s, t);

            IsSubsequence_392 idxPos;
            idxPos.preprocess_PosIndex(t);
            bool b = idxPos.isSubsequence_PosIndex(s);

            IsSubsequence_392 idxNext;
            idxNext.preprocess_NextTable(t);
            bool c = idxNext.isSubsequence_NextTable(s);

            const string base = "Is Subsequence 392 Test " + to_string(i + 1);
            REQUIRE_ASSERT(assertEqScalar(base + " [two-pointer]", tests[i].expected, a));
            REQUIRE_ASSERT(assertEqScalar(base + " [pos-index]", tests[i].expected, b));
            REQUIRE_ASSERT(assertEqScalar(base + " [next-table]",  tests[i].expected, c));
            REQUIRE_ASSERT(assertEqScalar(base + " [consistency pos vs next]", b, c));
        }

        // Follow-up: many queries for the same t (reuse preprocessed data)
        vector<IsSubsequenceFollowUpTestCase> futests = {
            {"ahbgdc", { {"abc", true}, {"axc", false}, {"agc", true}, {"", true}, {"aaaa", false} }},
            {"leetcode", { {"leet", true}, {"code", true}, {"leot", false}, {"leetcode", true} }}
        };

        for (size_t b = 0; b < futests.size(); ++b) {
            const string& t = futests[b].t;

            IsSubsequence_392 idxPos, idxNext;
            idxPos.preprocess_PosIndex(t);
            idxNext.preprocess_NextTable(t);

            for (size_t qi = 0; qi < futests[b].queries.size(); ++qi) {
                const auto& [qs, expected] = futests[b].queries[qi];

                bool a = IsSubsequence_392().isSubsequence_TwoPointer(qs, t);
                bool p = idxPos.isSubsequence_PosIndex(qs);
                bool n = idxNext.isSubsequence_NextTable(qs);

                const string base =
                    "Is Subsequence 392 FU " + to_string(b + 1) +
                    " Q" + to_string(qi + 1);
                REQUIRE_ASSERT(assertEqScalar(base + " [two-pointer]", expected, a));
                REQUIRE_ASSERT(assertEqScalar(base + " [pos-index]", expected, p));
                REQUIRE_ASSERT(assertEqScalar(base + " [next-table]",  expected, n));
                REQUIRE_ASSERT(assertEqScalar(base + " [consistency pos vs next]", p, n));
            }
        }

        return true;
    }

    static bool longestCommonPrefix_14_tests() {
        vector<LongestCommonPrefixTestCase> tcs = {
            // Provided examples
            {{"flower","flow","flight"}, "fl"},
            {{"dog","racecar","car"}, ""},

            // Edge cases / extras
            {{""}, ""},
            {{"a"}, "a"},
            {{"", "b"}, ""},
            {{"interspecies","interstellar","interstate"}, "inters"},
            {{"throne","throne"}, "throne"},
            {{"throne","throne","throne"}, "throne"},
            {{"cir","car"}, "c"},
            {{"reflower","flow","flight"}, ""},
            {{"aa","a"}, "a"},
            {{"leetcode","leet","le","l"}, "l"}
        };

        LongestCommonPrefix_14 sol;

        for (size_t i = 0; i < tcs.size(); ++i) {
            string gotL = sol.longestCommonPrefix_Linear(tcs[i].strs);
            string gotS = sol.longestCommonPrefix_Sort(tcs[i].strs);
            string gotV = sol.longestCommonPrefix_Vertical(tcs[i].strs);

            if (gotL != gotS || gotL != gotV) {
                cout << "[WARN] LCP variants disagree on case " << (i + 1)
                    << "  linear=\"" << gotL << "\" sort=\"" << gotS
                    << "\" vertical=\"" << gotV << "\"\n";
            }

            const string base = "LCP14 Test " + to_string(i + 1);
            REQUIRE_ASSERT(assertEqScalar(base + " [linear]", tcs[i].expected, gotL));
            REQUIRE_ASSERT(assertEqScalar(base + " [vertical]", tcs[i].expected, gotV));
            REQUIRE_ASSERT(assertEqScalar(base + " [sort]", tcs[i].expected, gotS));
        }

        return true;
    }

    static bool summaryRanges_228_tests() {
        vector<SummaryRangesTestCase> tests = {
            {{0,1,2,4,5,7},                   {"0->2","4->5","7"}},
            {{0,2,3,4,6,8,9},                 {"0","2->4","6","8->9"}},
            {{},                              {}},
            {{5},                             {"5"}},
            {{-3,-2,-1,0,2},                  {"-3->0","2"}},
            {{INT_MAX-1, INT_MAX},            {to_string(INT_MAX-1) + "->" + to_string(INT_MAX)}},
            {{INT_MIN, INT_MIN+1, INT_MIN+3}, {to_string(INT_MIN) + "->" + to_string(INT_MIN+1), to_string(INT_MIN+3)}},
            {{1,3,5},                         {"1","3","5"}}
        };

        SummaryRanges_228 sol;

        for (size_t i = 0; i < tests.size(); ++i) {
            auto in = tests[i].nums; // method takes non-const ref
            auto got = sol.summaryRanges(in);

            const string label = "Summary Ranges 228 Test " + to_string(i + 1);
            REQUIRE_ASSERT(assertEqStrings(label, tests[i].expected, got));
        }

        return true;
    }

    static bool romanToInteger_13_tests() {
        vector<RomanToIntegerTestCase> tests = {
            // From the statement
            {"III", 3},
            {"LVIII", 58},
            {"MCMXCIV", 1994},
            // Additional
            {"IX", 9},             // simple subtractive
            {"CDXLIV", 444},       // multiple subtractive pairs (CD + XL + IV)
            {"MMMCMXCIX", 3999}    // maximum in range
        };

        RomanToInteger_13 sol;

        for (size_t i = 0; i < tests.size(); ++i) {
            int got = sol.romanToInt(tests[i].input);

            const string label =
                "Roman to Integer 13 Test " + to_string(i + 1) +
                " [\"" + tests[i].input + "\"]";
            REQUIRE_ASSERT(assertEqScalar(label, tests[i].expected, got));
        }

        return true;
    }

    /* In-place array updates and two-pointer style compaction/merge */

    static bool removeDuplicatesFromSortedArray_26_tests() {
        vector<RemoveDuplicates26TestCase> tests = {
            {{1,1,2},                             {1,2}},
            {{0,0,1,1,1,2,2,3,3,4},               {0,1,2,3,4}},
            {{42},                                {42}},
            {{7,7,7},                             {7}},
            {{-1,0,1},                            {-1,0,1}},
            {{-3,-3,-2,-2,-2,-1,-1,0,0,0,1,1,2},  {-3,-2,-1,0,1,2}}
        };

        RemoveDuplicates_26 sol;
        vector<int> a; // reuse to avoid realloc chatter

        for (size_t i = 0; i < tests.size(); ++i) {
            a = tests[i].nums; // the solver mutates in place
            int k = sol.removeDuplicates(a);

            const string label = "Remove Duplicates 26 Test " + to_string(i + 1);
            REQUIRE_ASSERT(assertEqVIntPrefix(label, tests[i].expected, a, k));
        }

        return true;
    }

    static bool removeElement_27_tests() {
        vector<RemoveElementTestCase> cases = {
            {{3,2,2,3},           3, 2, {2,2}},           // example 1
            {{0,1,2,2,3,0,4,2},   2, 5, {0,0,1,3,4}},     // example 2
            {{},                  0, 0, {}},              // empty array
            {{1,1,1},             2, 3, {1,1,1}},         // value absent
            {{4,4,4},             4, 0, {}}               // all removed
        };

        RemoveElement_27 remover;

        for (size_t i = 0; i < cases.size(); ++i) {
            auto nums = cases[i].nums;                // copy to mutate
            int  k    = remover.removeElement(nums, cases[i].val);

            // Compare length and (order-insensitive) contents of the kept prefix
            vector<int> got(nums.begin(), nums.begin() + k);
            auto        exp = cases[i].expected;
            sort(got.begin(), got.end());
            sort(exp.begin(), exp.end());

            const string base = "Remove Element 27 Test " + to_string(i + 1);
            REQUIRE_ASSERT(assertEqScalar(base + " [k]", cases[i].expectedK, k));
            REQUIRE_ASSERT(assertEqVIntExact(base + " [elems unordered]", exp, got));
        }

        return true;
    }

    static bool mergeSortedArray_88_tests() {
        vector<MergeSortedArrayTestCase> cases = {
            {{1,2,3,0,0,0}, 3, {2,5,6}, 3, {1,2,2,3,5,6}},
            {{1},           1, {},       0, {1}},
            {{0},           0, {1},      1, {1}},
            {{2,0},         1, {1},      1, {1,2}},               // reversed order input
            {{-3,-1,0,0,0}, 2, {-2,-2,4},3, {-3,-2,-2,-1,4}}      // negatives & duplicates
        };

        MergeSortedArray_88 merger;

        for (size_t i = 0; i < cases.size(); ++i) {
            auto nums1 = cases[i].nums1; // copy; merge mutates in place
            merger.merge(nums1, cases[i].m, cases[i].nums2, cases[i].n);

            const string label = "Merge Sorted Array 88 Test " + to_string(i + 1);
            REQUIRE_ASSERT(assertEqVIntExact(label, cases[i].expected, nums1));
        }

        return true;
    }

    static bool removeDuplicatesFromSortedArrayII_80_tests() {
        // Prepare test cases:
        vector<RemoveDuplicatesFromSortedArrayIITestCase> testCases = {
            // 2 examples from the problem statement:
            {{1,1,1,2,2,3}, 5, {1,1,2,2,3}},           // Example 1
            {{0,0,1,1,1,1,2,3,3}, 7, {0,0,1,1,2,3,3}}, // Example 2

            // 3 additional (one corner case):
            {{42}, 1, {42}},                       // Corner: single element
            {{2,2,2,2}, 2, {2,2}},                 // All duplicates
            {{1,1,2,2,2,3,3}, 6, {1,1,2,2,3,3}}    // Mixed duplicates
        };

        RemoveDuplicatesFromSortedArrayII_80 sol;

        for (size_t i = 0; i < testCases.size(); ++i) {
            auto nums = testCases[i].input;           // work on a copy
            int k = sol.removeDuplicates(nums);

            const string base = "Remove Duplicates II 80 Test " + to_string(i + 1);
            REQUIRE_ASSERT(assertEqScalar(base + " [k]", testCases[i].expectedK, k));
            REQUIRE_ASSERT(assertEqVIntPrefix(base + " [prefix]", testCases[i].expected, nums, k));
        }

        return true;
    }

    /* Greedy scans, prefix thinking, and simple counting ideas */

    static bool bestTimeToBuyAndSellStock_121_tests() {
        vector<BestTimeToBuyAndSellStockTestCase> testCases = {
            // Provided examples
            {{7, 1, 5, 3, 6, 4}, 5},  // Example 1
            {{7, 6, 4, 3, 1}, 0},    // Example 2

            // Additional complex test cases
            {{1, 2, 3, 4, 5, 6, 7, 8, 9}, 8},       // Buy on day 1, sell on day 9
            {{9, 8, 7, 1, 5, 3, 6, 4}, 5},          // Buy on day 4, sell on day 7

            // Edge case
            {{5}, 0}  // Single price: no transactions possible
        };

        BestTimeToBuyAndSellStock_121 solution;

        for (size_t i = 0; i < testCases.size(); ++i) {
            int result = solution.maxProfit(testCases[i].prices);

            const string label = "Best Time to Buy and Sell Stock 121 Test " + to_string(i + 1);
            REQUIRE_ASSERT(assertEqScalar(label, testCases[i].expected, result));
        }

        return true;
    }

    static bool bestTimeToBuyAndSellStockII_122_tests() {
        vector<BestTimeToBuyAndSellStockIITestCase> testCases = {
            // 3 examples from the problem statement:
            {{7,1,5,3,6,4}, 7}, // Example 1
            {{1,2,3,4,5}, 4},   // Example 2
            {{7,6,4,3,1}, 0},   // Example 3

            // Edge case: no days -> no transaction possible, profit = 0.
            {{}, 0},

            // Edge case: single day -> cannot buy and sell, profit = 0.
            {{5}, 0},

            // Edge case: flat prices -> no upward movement, profit = 0.
            {{3,3,3,3}, 0},

            // 2 additional, more complicated examples:
            // For prices = [2,4,1,10,9,11]:
            // Day-to-day profit breakdown: (4-2)=2, (10-1)=9, (11-9)=2, total profit = 2+9+2 = 13.
            {{2,4,1,10,9,11}, 13},

            // For prices = [3,3,5,0,0,3,1,4]:
            // Day-to-day profit breakdown: (5-3)=2, (3-0)=3, (4-1)=3, total profit = 2+3+3 = 8.
            {{3,3,5,0,0,3,1,4}, 8}
        };

        BestTimeToBuyAndSellStockII_122 sol;

        for (size_t i = 0; i < testCases.size(); ++i) {
            const int gotDailyDiffs = sol.maxProfit_DailyDiffs(testCases[i].prices);
            const int gotValleyPeak = sol.maxProfit_ValleyPeak(testCases[i].prices);

            const string base =
                "Best Time to Buy and Sell Stock II 122 Test " + to_string(i + 1);
            REQUIRE_ASSERT(assertEqScalar(
                base + " [DailyDiffs]",
                testCases[i].expected,
                gotDailyDiffs));
            REQUIRE_ASSERT(assertEqScalar(
                base + " [ValleyPeak]",
                testCases[i].expected,
                gotValleyPeak));
        }

        return true;
    }

    static bool findPivotIndex_724_tests() {
        vector<FindPivotIndexTestCase> cases = {
            {{1,7,3,6,5,6},  3},     // example 1
            {{1,2,3},       -1},     // example 2
            {{2,1,-1},       0},     // example 3
            {{0,0,0,0},      0},     // all zeros → first index
            {{-1,-1,0,1,1,0}, 5}     // negatives & duplicates
        };

        FindPivotIndex_724 solver;

        for (size_t i = 0; i < cases.size(); ++i) {
            int got = solver.pivotIndex(cases[i].input);

            const string label = "Find Pivot Index 724 Test " + to_string(i + 1);
            REQUIRE_ASSERT(assertEqScalar(label, cases[i].expected, got));
        }

        return true;
    }

    static bool appleRedistributionIntoBoxes_3074_tests() {
        vector<AppleRedistributionIntoBoxesTestCase> testCases = {
            // Examples from the problem statement
            {{1, 3, 2},      {4, 3, 1, 5, 2}, 2},
            {{5, 5, 5},      {2, 4, 2, 7},     4},

            // Single pack / single box
            {{1},            {1},              1},

            // Need all boxes to reach total capacity
            {{1, 2, 3},      {2, 2, 2},        3},

            // Mix of capacities where one large box + one small is enough
            {{2, 2},         {3, 1, 1},        2},
        };

        AppleRedistributionIntoBoxes_3074 solver;

        for (size_t i = 0; i < testCases.size(); ++i) {
            const auto& tc = testCases[i];

            // capacity is sorted in-place, so copy it for each run
            auto capacityCopy = tc.capacity;
            int got = solver.minimumBoxes(const_cast<vector<int>&>(tc.apple),
                                          capacityCopy);

            const string label = "Apple Redistribution Into Boxes 3074 Test " + to_string(i + 1);
            REQUIRE_ASSERT(assertEqScalar(label, tc.expected, got));
        }

        return true;
    }

    static bool splitTheArray_3046_tests() {
        vector<SplitTheArrayTestCase> testCases = {
            {{1,1,2,2,3,4}, true},   // example 1
            {{1,1,1,1},     false},  // example 2
            {{1,2},         true},   // minimal even length, trivially split [1] | [2]
            {{1,1},         true},   // [1] | [1] — each half has distinct elements
            {{2,2,3,3},     true},   // all counts <= 2
            {{5,5,5,6,7,8}, false},  // a value appears 3 times
            {{10,20,30,40}, true},   // all unique
        };

        SplitTheArray_3046 sol;

        for (size_t i = 0; i < testCases.size(); ++i) {
            auto v = testCases[i].nums;
            bool got = sol.isPossibleToSplit(v);

            const string label = "Split the Array 3046 Test " + to_string(i + 1);
            REQUIRE_ASSERT(assertEqScalar(label, testCases[i].expected, got));
        }

        return true;
    }

    /* Core array techniques: construction, partitioning, and prefix products */

    static bool pascalsTriangle_118_tests() {
        vector<PascalsTriangleTestCase> testCases = {
            // examples from the statement
            {1, {{1}}},
            {5, {{1}, {1,1}, {1,2,1}, {1,3,3,1}, {1,4,6,4,1}}},

            // additional cases
            {2, {{1}, {1,1}}},
            {3, {{1}, {1,1}, {1,2,1}}},
            {6, {{1},
                 {1,1},
                 {1,2,1},
                 {1,3,3,1},
                 {1,4,6,4,1},
                 {1,5,10,10,5,1}}},
            {7, {{1},
                 {1,1},
                 {1,2,1},
                 {1,3,3,1},
                 {1,4,6,4,1},
                 {1,5,10,10,5,1},
                 {1,6,15,20,15,6,1}}}
        };

        PascalsTriangle_118 solver;

        for (size_t i = 0; i < testCases.size(); ++i) {
            auto got = solver.generate(testCases[i].numRows);

            const string label = "Pascal's Triangle 118 Test " + to_string(i + 1);
            REQUIRE_ASSERT(assertEqVVIntExact(label, testCases[i].expected, got));
        }

        return true;
    }

    static bool sortColors_75_tests() {
        vector<SortColorsTestCase> testCases = {
            {{2, 0, 2, 1, 1, 0}, {0, 0, 1, 1, 2, 2}},
            {{2, 0, 1},          {0, 1, 2}},
            {{0},                {0}},
            {{2, 2, 2, 2},       {2, 2, 2, 2}},
            {{1, 0, 2, 2, 1, 0}, {0, 0, 1, 1, 2, 2}}
        };

        SortColors_75 sol;

        for (size_t i = 0; i < testCases.size(); ++i) {
            auto arr_threeTails = testCases[i].input;
            auto arr_counting   = testCases[i].input;

            sol.sortColors_threeTails(arr_threeTails);
            sol.sortColors_counting(arr_counting);

            const string base = "Sort Colors 75 Test " + to_string(i + 1);
            REQUIRE_ASSERT(assertEqVIntExact(base + " [threeTails]", testCases[i].expected, arr_threeTails));
            REQUIRE_ASSERT(assertEqVIntExact(base + " [counting]",   testCases[i].expected, arr_counting));
        }

        return true;
    }

    static bool productOfArrayExceptSelf_238_tests() {
        vector<ProductOfArrayExceptSelfTestCase> testCases = {
            // Example 1
            {{1, 2, 3, 4}, {24, 12, 8, 6}},
            // Example 2
            {{-1, 1, 0, -3, 3}, {0, 0, 9, 0, 0}},
            // Corner Case: All ones
            {{1, 1, 1, 1}, {1, 1, 1, 1}},
            // Complex Case 1: Mixed positive and negative numbers
            {{-2, -3, 4, 5}, {-60, -40, 30, 24}},
            // Complex Case 2: Large array
            {{10, 20, 30, 40, 50}, {1200000, 600000, 400000, 300000, 240000}}
        };

        ProductOfArrayExceptSelf solution;

        for (size_t i = 0; i < testCases.size(); ++i) {
            auto got = solution.productExceptSelf(testCases[i].input);

            const string label = "Product Except Self 238 Test " + to_string(i + 1);
            REQUIRE_ASSERT(assertEqVIntExact(label, testCases[i].expected, got));
        }

        return true;
    }

    static bool hIndex_274_tests() {
        // 5 test cases: the 2 from the LeetCode examples + 3 additional
        vector<HIndexTestCase> testCases = {
            // Example 1
            {{3, 0, 6, 1, 5}, 3},
            // Example 2
            {{1, 3, 1}, 1},

            // Additional (more complex) test cases
            {{10, 8, 5, 4, 3}, 4},  // H-index should be 4
            {{0, 0, 0, 0}, 0},      // H-index should be 0
            {{4, 4, 4, 4, 4}, 4}    // H-index should be 4
        };

        HIndex_274 sol;

        for (size_t i = 0; i < testCases.size(); ++i) {
            int got = sol.hIndex(testCases[i].input);

            const string label = "H-Index 274 Test " + to_string(i + 1);
            REQUIRE_ASSERT(assertEqScalar(label, testCases[i].expected, got));
        }

        return true;
    }

    /* More advanced transformations on intervals, strings, and matrices */

    static bool mergeIntervals_56_tests() {
        vector<MergeIntervalsTestCase> testCases = {
            // Problem statement examples
            {{{1, 3}, {2, 6}, {8, 10}, {15, 18}}, {{1, 6}, {8, 10}, {15, 18}}},
            {{{1, 4}, {4, 5}}, {{1, 5}}},

            // Additional complex test cases
            {{{1, 4}, {0, 2}, {3, 5}}, {{0, 5}}},
            {{{1, 10}, {2, 6}, {8, 9}, {15, 20}, {18, 22}}, {{1, 10}, {15, 22}}},

            // Edge case: Single interval
            {{{5, 10}}, {{5, 10}}}
        };

        MergeIntervals_56 solution;

        for (size_t i = 0; i < testCases.size(); ++i) {
            auto got = solution.merge(testCases[i].input);

            const string label = "Merge Intervals Test " + to_string(i + 1);
            REQUIRE_ASSERT(assertEqVVIntExact(label, testCases[i].expected, got));
        }

        return true;
    }

    static bool zigzagConversion_6_tests() {
        vector<ZigzagConversionTestCase> testCases = {
            {"PAYPALISHIRING", 3, "PAHNAPLSIIGYIR"},
            {"PAYPALISHIRING", 4, "PINALSIGYAHRPI"},
            {"A", 1, "A"},
            {"ABCDEFGHIJKLMNOPQRSTUVWXYZ", 5, "AIQYBHJPRXZCGKOSWDFLNTVEMU"},
            {"THISISAZIGZAGCONVERSIONTEST", 6, "TZIHGASOIIGRNSZCETIAOVETSNS"}
        };

        ZigzagConversion_6 sol;

        for (size_t i = 0; i < testCases.size(); ++i) {
            const auto& tc = testCases[i];

            string gotRow  = sol.convert_rowWise(tc.input, tc.numRows);
            string gotJump = sol.convert_jumpPattern(tc.input, tc.numRows);

            const string base =
                "Zigzag Conversion 6 Test " + to_string(i + 1) +
                " (rows=" + to_string(tc.numRows) + ")";
            REQUIRE_ASSERT(assertEqScalar(base + " [row-wise]", tc.expected, gotRow));
            REQUIRE_ASSERT(assertEqScalar(base + " [jump-pattern]", tc.expected, gotJump));
            REQUIRE_ASSERT(assertEqScalar(base + " [consistency]", gotRow, gotJump));
        }

        return true;
    }

    /* 2D matrix traversal and in-place matrix transformation */

    static bool rotateImage_48_tests() {
        vector<RotateImageTestCase> testCases = {
            // Example 1
            {{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}}, {{7, 4, 1}, {8, 5, 2}, {9, 6, 3}}},
            // Example 2
            {{{5, 1, 9, 11}, {2, 4, 8, 10}, {13, 3, 6, 7}, {15, 14, 12, 16}},
             {{15, 13, 2, 5}, {14, 3, 4, 1}, {12, 6, 8, 9}, {16, 7, 10, 11}}},
            // Additional Test Cases
            {{{1}}, {{1}}},                       // Single element
            {{{1, 2}, {3, 4}}, {{3, 1}, {4, 2}}}, // 2x2 matrix
            {
                {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}},
                {{13, 9, 5, 1}, {14, 10, 6, 2}, {15, 11, 7, 3}, {16, 12, 8, 4}}} // Larger 4x4 matrix
        };

        RotateImage_48 rotator;

        // Transpose-then-reverse variant
        for (size_t i = 0; i < testCases.size(); ++i) {
            auto m = testCases[i].input; // fresh copy
            rotator.rotateTransposeReverse(m);

            const string label =
                "Rotate Image 48 Test " + to_string(i + 1) + " [Transpose+Reverse]";
            REQUIRE_ASSERT(assertEqVVIntExact(label, testCases[i].expected, m));
        }

        // Layer-by-layer ("onion") swap variant
        for (size_t i = 0; i < testCases.size(); ++i) {
            auto m = testCases[i].input; // fresh copy
            rotator.rotateLayerSwap(m);

            const string label =
                "Rotate Image 48 Test " + to_string(i + 1) + " [LayerSwap]";
            REQUIRE_ASSERT(assertEqVVIntExact(label, testCases[i].expected, m));
        }

        return true;
    }

    static bool spiralMatrix_54_tests() {
        vector<SpiralMatrixTestCase> testCases = {
            // Provided examples
            {{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}}, {1, 2, 3, 6, 9, 8, 7, 4, 5}},
            {{{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}}, {1, 2, 3, 4, 8, 12, 11, 10, 9, 5, 6, 7}},

            // Additional test cases
            // Edge case: Single element matrix
            {{{1}}, {1}},

            // More complicated matrix: Rectangular (more rows)
            {{{1, 2}, {3, 4}, {5, 6}, {7, 8}}, {1, 2, 4, 6, 8, 7, 5, 3}},

            // More complicated matrix: Rectangular (more columns)
            {{{1, 2, 3, 4, 5}, {6, 7, 8, 9, 10}}, {1, 2, 3, 4, 5, 10, 9, 8, 7, 6}},
        };

        SpiralMatrix_54 sm54;

        for (size_t i = 0; i < testCases.size(); ++i) {
            vector<int> result = sm54.spiralOrder(testCases[i].matrix);

            const string label = "Test " + to_string(i + 1);
            REQUIRE_ASSERT(assertEqVIntExact(label, testCases[i].expected, result));
        }

        return true;
    }

    /* Preprocessing optimization for repeated subsequence queries */

    // Stress test for next-position preprocessing; also cross-checks pos-index.
    static bool isSubsequence_392_nextpos_tests() {
        string t;
        t.reserve(10000);

        for (int i = 0; i < 10000; ++i) {
            t.push_back(char('a' + (i % 26)));
        }

        IsSubsequence_392 idxNext;
        IsSubsequence_392 idxPos;

        idxNext.preprocess_NextTable(t);
        idxPos.preprocess_PosIndex(t);

        struct Query {
            string s;
            bool expected;
        };

        vector<Query> queries;

        {
            string s;
            s.reserve(26 * 100);

            for (int rep = 0; rep < 100; ++rep) {
                for (char c = 'a'; c <= 'z'; ++c) {
                    s.push_back(c);
                }
            }

            queries.push_back({move(s), true});
        }

        queries.push_back({string(384, 'z'), true});
        queries.push_back({string(385, 'z'), false});
        queries.push_back({"leetcode", true});
        queries.push_back({"zzzay", true});
        queries.push_back({"", true});

        for (size_t i = 0; i < queries.size(); ++i) {
            bool gotNext = idxNext.isSubsequence_NextTable(queries[i].s);
            bool gotPos = idxPos.isSubsequence_PosIndex(queries[i].s);

            const string base = "Is Subsequence 392 Big Test " + to_string(i + 1);
            REQUIRE_ASSERT(assertEqScalar(base + " [NextTable]", queries[i].expected, gotNext));
            REQUIRE_ASSERT(assertEqScalar(base + " [PosIndex]", queries[i].expected, gotPos));
            REQUIRE_ASSERT(assertEqScalar(base + " [Consistency]", gotNext, gotPos));
        }

        return true;
    }

    // ============================================================================
    // Sliding Window
    // ============================================================================

    /* Fixed-size windows with rolling updates */

    static bool maximumAverageSubarrayI_643_tests() {
        vector<MaximumAverageSubarrayITestCase> testCases = {
            // problem examples
            {{1, 12, -5, -6, 50, 3}, 4, 12.75},
            {{5},                    1,  5.0},

            // additional complex tests
            {{1,2,3,4,5,6,7,8,9,10},   5,  8.0},          // increasing sequence
            {{-5,-10,-3,-4,-1,-2},     3, -2.3333333333}, // all negatives
            {{0,100,0,100,0,100},      2,  50.0}          // alternating highs/lows
        };

        MaximumAverageSubarrayI_643 sol;

        for (size_t i = 0; i < testCases.size(); ++i) {
            double got = sol.findMaxAverage(testCases[i].nums, testCases[i].k);

            const string label = "Max Avg Subarray I 643 Test " + to_string(i + 1);
            REQUIRE_ASSERT(assertApprox(label, testCases[i].expected, got));
        }

        return true;
    }

    /* Expanding and shrinking windows with a running constraint */

    static bool maxConsecutiveOnesIII_1004_tests() {
        vector<MaxConsecutiveOnesIIITestCase> testCases = {
            // two examples from the problem statement:
            {{1,1,1,0,0,0,1,1,1,1,0},           2,  6},
            {{0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1}, 3, 10},

            // three more:
            {{1,0,1,0,1,0,1},                   1,  3},  // alternating
            {{1,1,0,0,1,1,1,0,1},               2,  7},  // mixed blocks
            {{0,0,0,0},                         0,  0}   // all zeros, no flips
        };

        MaxConsecutiveOnesIII_1004 sol;

        for (size_t i = 0; i < testCases.size(); ++i) {
            int got = sol.longestOnes(testCases[i].nums, testCases[i].k);

            const string label = "Max Consecutive Ones III 1004 Test " + to_string(i + 1);
            REQUIRE_ASSERT(assertEqScalar(label, testCases[i].expected, got));
        }

        return true;
    }

    static bool minimumSizeSubarraySum_209_tests() {
        vector<MinimumSizeSubarraySumTestCase> testCases = {
            // 3 examples from the problem statement
            {7,  {2, 3, 1, 2, 4, 3},             2},
            {4,  {1, 4, 4},                      1},
            {11, {1, 1, 1, 1, 1, 1, 1, 1},       0},

            // 2 additional, more demanding cases
            //  – overlapping windows, answer = 2  (10+7)
            {15, {5, 1, 3, 5, 10, 7, 4, 9, 2, 8}, 2},
            //  – strictly increasing array, answer = 3  (8+9+10)
            {25, {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, 3}
        };

        MinimumSizeSubarraySum_209 sol;

        for (size_t i = 0; i < testCases.size(); ++i) {
            int got = sol.minSubArrayLen(testCases[i].target, testCases[i].nums);

            const string label = "Minimum Size Subarray Sum 209 Test " + to_string(i + 1);
            REQUIRE_ASSERT(assertEqScalar(label, testCases[i].expected, got));
        }

        return true;
    }

    /* Variable-size windows for distinctness and replacement limits */

    static bool longestSubstringWithoutRepeatingCharacters_3_tests() {
        vector<LongestSubstringWithoutRepeatingCharactersTestCase> testCases = {
            {"abcabcbb", 3},  // example 1
            {"bbbbb",    1},  // example 2
            {"pwwkew",   3},  // example 3
            // two more complex cases:
            {"dvdf",     3},  // "vdf"
            {"anviaj",   5}   // "nviaj"
        };

        LongestSubstringWithoutRepeatingCharacters_3 sol;

        for (size_t i = 0; i < testCases.size(); ++i) {
            int got = sol.lengthOfLongestSubstring(testCases[i].input);

            const string label = "Longest Substring 3 Test " + to_string(i + 1);
            REQUIRE_ASSERT(assertEqScalar(label, testCases[i].expected, got));
        }

        return true;
    }

    static bool longestRepeatingCharacterReplacement_424_tests() {
        vector<LongestRepeatingCharacterReplacementTestCase> testCases = {
            {"ABAB",      2, 4},  // Example 1
            {"AABABBA",   1, 4},  // Example 2
            {"BABABA",    3, 6},  // Transform 3 'A's into 'B's
            {"ABCDE",     2, 3},  // Best substring length 3 by 2 changes
            {"ABBBBAA",   2, 6},  // 6-length window after 2 changes
            {"AAACCCCAC", 1, 6},  // Example of sliding window where maxFreq lags; still yields best=6
        };

        LongestRepeatingCharacterReplacement_424 sol;

        for (size_t i = 0; i < testCases.size(); ++i) {
            int got = sol.characterReplacement(testCases[i].input, testCases[i].k);

            const string label = "Character Replacement 424 Test " + to_string(i + 1);
            REQUIRE_ASSERT(assertEqScalar(label, testCases[i].expected, got));
        }

        return true;
    }

    /* Window matching with character-frequency requirements */

    static bool permutationInString_567_tests() {
        vector<PermutationInStringTestCase> testCases = {
            {"ab",   "eidbaooo",          true},
            {"ab",   "eidboaoo",          false},
            {"adc",  "dcda",              true},
            {"xyz",  "afdgzyxksldfm",     true},
            {"abcd", "abc",               false}
        };

        PermutationInString_567 sol;

        for (size_t i = 0; i < testCases.size(); ++i) {
            const bool gotFullCompare = sol.checkInclusion_fullCompare(testCases[i].s1, testCases[i].s2);
            const bool gotMatchesCounter = sol.checkInclusion_matchesCounter(testCases[i].s1, testCases[i].s2);

            const string base = "Permutation in String 567 Test " + to_string(i + 1);
            REQUIRE_ASSERT(assertEqScalar(base + " [fullCompare]", testCases[i].expected, gotFullCompare));
            REQUIRE_ASSERT(assertEqScalar(base + " [matchesCounter]", testCases[i].expected, gotMatchesCounter));
        }

        return true;
    }

    // ============================================================================
    // Heaps
    // ============================================================================

    /* Basic max-heap / min-heap simulation */

    static bool lastStoneWeight_1046_tests() {
        vector<LastStoneWeightTestCase> tests = {
            // 2 from the statement
            {{2,7,4,1,8,1}, 1},
            {{1}, 1},

            // 4 additional / edge-ish
            {{10,10}, 0},                 // equal pair cancels
            {{9,3,2,10}, 0},              // multiple reductions to zero
            {{1,1,2,3,5,8,13}, 1},        // mixed, ends with 1
            {{7,6,7,6,9}, 3}              // nontrivial leftovers
        };

        LastStoneWeight_1046 sol;
        for (size_t i = 0; i < tests.size(); ++i) {
            int got = sol.lastStoneWeight(tests[i].stones);

            const string label = "Last Stone Weight 1046 Test " + to_string(i + 1);
            REQUIRE_ASSERT(assertEqScalar(label, tests[i].expected, got));
        }

        return true;
    }

    /* Heap-based selection for k-th / top-k queries */

    static bool kthLargestElementInArray_215_tests()
    {
        vector<KthLargestElementTestCase> testCases = {
            // Problem statement examples
            {{3, 2, 1, 5, 6, 4}, 2, 5},
            {{3, 2, 3, 1, 2, 4, 5, 5, 6}, 4, 4},

            // Additional test cases
            {{1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, 1, 10}, // Largest element
            {{7, 10, 4, 3, 20, 15}, 3, 10},           // Mixed elements
            {{2, 2, 2, 2, 2}, 3, 2},                  // Repeated elements

            // Large ascending [1..10000], k=500 -> 9501 (filled below)
            {{}, 500, 9501}
        };

        // Fill the large ascending test (no extra scope)
        auto& bigCase = testCases.back();
        bigCase.nums.resize(10000);
        iota(bigCase.nums.begin(), bigCase.nums.end(), 1); // 1..10000

        KthLargestElementInArray_215 solution;

        for (size_t i = 0; i < testCases.size(); ++i)
        {
            // Use copies to be robust if implementations ever mutate input
            auto v1 = testCases[i].nums;
            auto v2 = testCases[i].nums;

            const int resMax = solution.findKthLargest_MaxHeap(v1, testCases[i].k);
            const int resMin = solution.findKthLargest_MinHeap(v2, testCases[i].k);

            const string label = "Kth Largest 215 Test " + to_string(i + 1);
            REQUIRE_ASSERT(assertEqScalar(label + " [MaxHeap]", testCases[i].expected, resMax));
            REQUIRE_ASSERT(assertEqScalar(label + " [MinHeap]", testCases[i].expected, resMin));
        }

        return true;
    }

    static bool topKFrequent_347_tests() {
        auto bag = [](initializer_list<pair<int, int>> spec) {
            size_t total = 0;

            for (const auto& [value, count] : spec) {
                total += count;
            }

            vector<int> values;
            values.reserve(total);

            for (const auto& [value, count] : spec) {
                values.insert(values.end(), count, value);
            }

            return values;
        };

        auto stress = bag({{42, 100}, {-7, 80}});
        stress.resize(stress.size() + 1000);
        iota(stress.end() - 1000, stress.end(), 10001);

        vector<TopKFrequentElementsTestCase> tests = {
            {{1,1,1,2,2,3}, 2, {1,2}},
            {{1},           1, {1}},
            {{1,1,2,2,2,3}, 1, {2}},
            {{-1,-1,-1,0,0,2,2,2,2,3,3}, 2, {2,-1}},

            // 7x7, 8x6, 9x5, 10x4, 11x3 -> k=3 => {7,8,9}
            {bag({{7,7}, {8,6}, {9,5}, {10,4}, {11,3}}), 3, {7,8,9}},

            // 42x100, -7x80, plus 1000 uniques -> k=2 => {42,-7}
            {stress, 2, {42,-7}},
        };

        TopKFrequentElements_347 sol;

        for (size_t i = 0; i < tests.size(); ++i) {
            auto got = sol.topKFrequent(tests[i].nums, tests[i].k);
            auto expected = tests[i].expected;

            sort(got.begin(), got.end());
            sort(expected.begin(), expected.end());

            const string label =
                "Top K Frequent Elements 347 Test " + to_string(i + 1) +
                " (k=" + to_string(tests[i].k) + ")";
            REQUIRE_ASSERT(assertEqVIntExact(label, expected, got));
        }

        return true;
    }

    static bool kClosestPointsToOrigin_973_tests() {
        vector<KClosestPointsToOriginTestCase> testCases = {
            // Official examples
            {{{1, 3}, {-2, 2}}, 1, {{-2, 2}}},
            {{{3, 3}, {5, -1}, {-2, 4}}, 2, {{3, 3}, {-2, 4}}},

            // Ties at the same distance; any 3 of these 4 are valid
            {{{0, 1}, {1, 0}, {-1, 0}, {0, -1}}, 3, {{0, 1}, {1, 0}, {-1, 0}}},

            // Points at extreme coordinates
            {{{10000, 10000}, {-10000, -10000}, {5000, 0}, {0, 5000}}, 2,
            {{5000, 0}, {0, 5000}}},

            // Mixed signs, k near n
            {{{2, 2}, {1, 1}, {3, 3}, {-2, -2}, {-1, -1}}, 4,
            {{-2, -2}, {-1, -1}, {1, 1}, {2, 2}}},
        };

        KClosestPointsToOrigin_973 solver;

        for (size_t i = 0; i < testCases.size(); ++i) {
            const auto& tc = testCases[i];
            const string base = "K Closest Points to Origin 973 Test " + to_string(i + 1);

            auto quickSelectInput = tc.points; // solver may mutate
            vector<vector<int>> quickSelectOutput =
                solver.kClosestQuickSelect(quickSelectInput, tc.k);

            auto heapInput = tc.points; // solver may mutate
            vector<vector<int>> heapOutput =
                solver.kClosestHeap(heapInput, tc.k);

            REQUIRE_ASSERT(assertEqScalar(
                base + " [QuickSelect valid]",
                true,
                isValidKClosestPoints(tc.points, tc.k, quickSelectOutput)));
            REQUIRE_ASSERT(assertEqScalar(
                base + " [Heap valid]",
                true,
                isValidKClosestPoints(tc.points, tc.k, heapOutput)));
        }

        return true;
    }

    /* Merging multiple sorted streams with a heap frontier */

    static bool mergeKSortedLists_23_tests() {
        using IntListNode = ListNode<int>;

        vector<MergeKListsTestCase> testCases = {
            // Example 1
            {{{1, 4, 5}, {1, 3, 4}, {2, 6}}, {1, 1, 2, 3, 4, 4, 5, 6}},
            // Example 2
            {{}, {}},
            // Example 3
            {{{}}, {}},
            // Additional Test 1: Single long list
            {{{1, 2, 3, 4, 5}}, {1, 2, 3, 4, 5}},
            // Additional Test 2: Large overlapping lists
            {{{1, 3, 5}, {2, 4, 6}, {0, 7, 8, 9}}, {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}}
        };

        MergeKSortedLists_23 solution;

        for (size_t i = 0; i < testCases.size(); ++i) {
            vector<ListUtils::UniqueList<int>> owners;
            vector<IntListNode*> lists;

            owners.reserve(testCases[i].lists.size());
            lists.reserve(testCases[i].lists.size());

            for (const auto& values : testCases[i].lists) {
                owners.push_back(ListUtils::makeUniqueList<int>(values));
                lists.push_back(owners.back().get());
            }

            IntListNode* merged = solution.mergeKLists(lists);

            for (auto& owner : owners) {
                owner.release();
            }

            ListUtils::UniqueList<int> mergedOwner(merged);

            const string label = "Merge K Sorted Lists 23 Test " + to_string(i + 1);
            REQUIRE_ASSERT(assertEqVIntExact(label, testCases[i].expected,
                                             ListUtils::toVector<int>(mergedOwner.get())));
        }

        return true;
    }

    /* Priority-queue traversal on a graph / grid state space */

    static bool findTheSafestPathInGrid_2812_tests() {
        vector<FindTheSafestPathInGridTestCase> testCases = {
            // three examples from the statement
            {{{1, 0, 0},
              {0, 0, 0},
              {0, 0, 1}},
             0},
            {{{0, 0, 1},
              {0, 0, 0},
              {0, 0, 0}},
             2},
            {{{0, 0, 0, 1},
              {0, 0, 0, 0},
              {0, 0, 0, 0},
              {1, 0, 0, 0}},
             2},

            // extra – single thief in the centre of a 5×5 grid (answer = 2)
            {{{0, 0, 0, 0, 0},
              {0, 0, 0, 0, 0},
              {0, 0, 1, 0, 0},
              {0, 0, 0, 0, 0},
              {0, 0, 0, 0, 0}},
             2},

            // extra – two thieves forcing a bottleneck of 1
            {{{0, 0, 1},
              {0, 0, 0},
              {1, 0, 0}},
             1}};

        FindSafestPathInGrid_2812 solver;

        for (size_t i = 0; i < testCases.size(); ++i) {
            const auto& tc = testCases[i];

            auto grid = tc.grid; // solver may mutate
            int got = solver.maximumSafenessFactor(grid);

            const string label = "Find Safest Path in Grid 2812 Test " + to_string(i + 1);
            REQUIRE_ASSERT(assertEqScalar(label, tc.expected, got));
        }

        return true;
    }

    // ============================================================================
    // Recursive Backtracking
    // ============================================================================

    /* Basic recursive generation of subsets, combinations, and permutations */

    static bool subsets_78_tests() {
        vector<SubsetsTestCase> tests = {
            // Example 1 (mask order for the bitmask method)
            {{1,2,3}, { {}, {1}, {2}, {1,2}, {3}, {1,3}, {2,3}, {1,2,3} }},
            // Example 2
            {{0},     { {}, {0} }},
            // Additional
            {{5,6},   { {}, {5}, {6}, {5,6} }},
            {{-1,2},  { {}, {-1}, {2}, {-1,2} }},
        };

        Subsets_78 sol;

        for (size_t i = 0; i < tests.size(); ++i) {
            const auto& tc = tests[i];
            const string base = "Subsets 78 Test " + to_string(i + 1);

            auto bitmaskInput = tc.nums;
            vector<vector<int>> bitmaskGot = sol.subsets_bitmask(bitmaskInput);
            REQUIRE_ASSERT(assertEqVVIntExact(base + " [bitmask]", tc.expected, bitmaskGot));

            auto prefixInput = tc.nums;
            vector<vector<int>> prefixGot = sol.subsets_recursive_prefix(prefixInput);
            REQUIRE_ASSERT(assertEqVVIntAnyOrder(base + " [recursive prefix]", tc.expected, prefixGot));

            auto binaryInput = tc.nums;
            vector<vector<int>> binaryGot = sol.subsets_recursive_binary(binaryInput);
            REQUIRE_ASSERT(assertEqVVIntAnyOrder(base + " [recursive binary]", tc.expected, binaryGot));
        }

        return true;
    }

    static bool combinations_77_tests() {
        vector<CombinationsTestCase> tests = {
            {4, 2, {{1,2},{1,3},{1,4},{2,3},{2,4},{3,4}}},
            {1, 1, {{1}}},
            {3, 1, {{1},{2},{3}}},
            {3, 3, {{1,2,3}}},
            {5, 3, {{1,2,3},{1,2,4},{1,2,5},{1,3,4},{1,3,5},
                    {1,4,5},{2,3,4},{2,3,5},{2,4,5},{3,4,5}}},
        };

        Combinations_77 sol;

        struct Impl {
            string name;
            function<vector<vector<int>>(const CombinationsTestCase&)> run;
        };

        const vector<Impl> impls = {
            {
                "PickNext",
                [&](const CombinationsTestCase& tc) {
                    return sol.combinePickNext(tc.n, tc.k);
                }
            },
            {
                "TakeSkip",
                [&](const CombinationsTestCase& tc) {
                    return sol.combineTakeSkip(tc.n, tc.k);
                }
            },
        };

        for (size_t i = 0; i < tests.size(); ++i) {
            const auto& tc = tests[i];
            const string base = "Combinations 77 Test " + to_string(i + 1);

            for (const auto& impl : impls) {
                vector<vector<int>> got = impl.run(tc);

                REQUIRE_ASSERT(assertEqVVIntAnyOrder(
                    base + " [" + impl.name + "]",
                    tc.expected,
                    got));
            }
        }

        return true;
    }

    static bool permutations_46_tests() {
        vector<PermutationsTestCase> tests = {
            {{1,2,3}, {{1,2,3},{1,3,2},{2,1,3},{2,3,1},{3,1,2},{3,2,1}}},
            {{0,1},   {{0,1},{1,0}}},
            {{1},     {{1}}},
            {{-1,2},  {{-1,2},{2,-1}}},
        };

        Permutations_46 sol;

        for (size_t i = 0; i < tests.size(); ++i) {
            auto in  = tests[i].nums;               // method takes non-const ref
            auto got = sol.permute(in);

            const string label = "Permutations 46 Test " + to_string(i + 1);
            REQUIRE_ASSERT(assertEqVVIntPermutations(label, tests[i].expected, got));
        }

        return true;
    }

    /* Backtracking with constraints and incremental choice building */

    static bool letterCombinations_17_tests() {
        vector<LetterCombinationsTestCase> tests = {
            {"23", {"ad","ae","af","bd","be","bf","cd","ce","cf"}},
            {"",   {}},
            {"2",  {"a","b","c"}},
            {"9",  {"w","x","y","z"}},
            {"79", {"pw","px","py","pz","qw","qx","qy","qz",
                    "rw","rx","ry","rz","sw","sx","sy","sz"}}
        };

        LetterCombinations_17 sol;

        for (size_t i = 0; i < tests.size(); ++i) {
            auto got = sol.letterCombinations(tests[i].digits);

            const string label = "Letter Combinations 17 Test " + to_string(i + 1);
            REQUIRE_ASSERT(assertEqStringsAnyOrder(label, tests[i].expected, got));
        }

        return true;
    }

    static bool generateParentheses_22_tests() {
        vector<GenerateParenthesesTestCase> tests = {
            {3, {"((()))","(()())","(())()","()(())","()()()"}},
            {1, {"()"}},
            {2, {"(())","()()"}},
            {4, {"(((())))","((()()))","((())())","((()))()",
                "(()(()))","(()()())","(()())()","(())(())","(())()()",
                "()((()))","()(()())","()(())()","()()(())","()()()()"}}
        };

        GenerateParentheses_22 sol;

        for (size_t i = 0; i < tests.size(); ++i) {
            auto got = sol.generateParenthesis(tests[i].n);

            const string label = "Generate Parentheses 22 Test " + to_string(i + 1);
            REQUIRE_ASSERT(assertEqStringsAnyOrder(label, tests[i].expected, got));
        }

        return true;
    }

    static bool combinationSum_39_tests() {
        vector<CombinationSumTestCase> tests = {
            {{2,3,6,7}, 7, {{2,2,3},{7}}},
            {{2,3,5},   8, {{2,2,2,2},{2,3,3},{3,5}}},
            {{2},       1, {}},
            {{2},       2, {{2}}},
            {{2,4,6},   6, {{2,2,2},{2,4},{6}}},
            {{8,7,4,3},11, {{3,4,4},{3,8},{7,4}}}
        };

        CombinationSum_39 sol;

        for (size_t i = 0; i < tests.size(); ++i) {
            auto cand = tests[i].candidates;       // method takes non-const ref
            auto got  = sol.combinationSum(cand, tests[i].target);

            const string label = "Combination Sum 39 Test " + to_string(i + 1);
            REQUIRE_ASSERT(assertEqVVIntAnyOrder(label, tests[i].expected, got));
        }

        return true;
    }

    /* Constraint-based board backtracking */

    static bool sudokuSolver_37_tests() {
        vector<SudokuSolverTestCase> testCases = {
            // Example 1: classic LeetCode example
            {
                {
                    {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
                    {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
                    {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
                    {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
                    {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
                    {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
                    {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
                    {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
                    {'.', '.', '.', '.', '8', '.', '.', '7', '9'}
                },
                {
                    {'5', '3', '4', '6', '7', '8', '9', '1', '2'},
                    {'6', '7', '2', '1', '9', '5', '3', '4', '8'},
                    {'1', '9', '8', '3', '4', '2', '5', '6', '7'},
                    {'8', '5', '9', '7', '6', '1', '4', '2', '3'},
                    {'4', '2', '6', '8', '5', '3', '7', '9', '1'},
                    {'7', '1', '3', '9', '2', '4', '8', '5', '6'},
                    {'9', '6', '1', '5', '3', '7', '2', '8', '4'},
                    {'2', '8', '7', '4', '1', '9', '6', '3', '5'},
                    {'3', '4', '5', '2', '8', '6', '1', '7', '9'}
                }
            },

            // Example 2: already solved board
            {
                {
                    {'5', '3', '4', '6', '7', '8', '9', '1', '2'},
                    {'6', '7', '2', '1', '9', '5', '3', '4', '8'},
                    {'1', '9', '8', '3', '4', '2', '5', '6', '7'},
                    {'8', '5', '9', '7', '6', '1', '4', '2', '3'},
                    {'4', '2', '6', '8', '5', '3', '7', '9', '1'},
                    {'7', '1', '3', '9', '2', '4', '8', '5', '6'},
                    {'9', '6', '1', '5', '3', '7', '2', '8', '4'},
                    {'2', '8', '7', '4', '1', '9', '6', '3', '5'},
                    {'3', '4', '5', '2', '8', '6', '1', '7', '9'}
                },
                {
                    {'5', '3', '4', '6', '7', '8', '9', '1', '2'},
                    {'6', '7', '2', '1', '9', '5', '3', '4', '8'},
                    {'1', '9', '8', '3', '4', '2', '5', '6', '7'},
                    {'8', '5', '9', '7', '6', '1', '4', '2', '3'},
                    {'4', '2', '6', '8', '5', '3', '7', '9', '1'},
                    {'7', '1', '3', '9', '2', '4', '8', '5', '6'},
                    {'9', '6', '1', '5', '3', '7', '2', '8', '4'},
                    {'2', '8', '7', '4', '1', '9', '6', '3', '5'},
                    {'3', '4', '5', '2', '8', '6', '1', '7', '9'}
                }
            },

            // Example 3: one missing value
            {
                {
                    {'5', '3', '4', '6', '7', '8', '9', '1', '.'},
                    {'6', '7', '2', '1', '9', '5', '3', '4', '8'},
                    {'1', '9', '8', '3', '4', '2', '5', '6', '7'},
                    {'8', '5', '9', '7', '6', '1', '4', '2', '3'},
                    {'4', '2', '6', '8', '5', '3', '7', '9', '1'},
                    {'7', '1', '3', '9', '2', '4', '8', '5', '6'},
                    {'9', '6', '1', '5', '3', '7', '2', '8', '4'},
                    {'2', '8', '7', '4', '1', '9', '6', '3', '5'},
                    {'3', '4', '5', '2', '8', '6', '1', '7', '9'}
                },
                {
                    {'5', '3', '4', '6', '7', '8', '9', '1', '2'},
                    {'6', '7', '2', '1', '9', '5', '3', '4', '8'},
                    {'1', '9', '8', '3', '4', '2', '5', '6', '7'},
                    {'8', '5', '9', '7', '6', '1', '4', '2', '3'},
                    {'4', '2', '6', '8', '5', '3', '7', '9', '1'},
                    {'7', '1', '3', '9', '2', '4', '8', '5', '6'},
                    {'9', '6', '1', '5', '3', '7', '2', '8', '4'},
                    {'2', '8', '7', '4', '1', '9', '6', '3', '5'},
                    {'3', '4', '5', '2', '8', '6', '1', '7', '9'}
                }
            },

            // Sparse board with a unique solution.
            //
            // A previous version used a 17-clue Sudoku, which is close to the hardest
            // realistic input for plain backtracking. It was correct, but too slow in
            // Debug builds. This case stays sparse enough to exercise deeper recursion,
            // while keeping the test suite reasonably fast.
            {
                {
                    {'.', '.', '.', '7', '.', '.', '.', '1', '.'},
                    {'4', '.', '7', '.', '1', '.', '9', '.', '.'},
                    {'.', '2', '.', '9', '.', '.', '.', '.', '.'},
                    {'.', '.', '.', '.', '5', '.', '4', '.', '7'},
                    {'.', '.', '8', '.', '.', '.', '3', '.', '.'},
                    {'.', '.', '1', '.', '9', '.', '.', '2', '.'},
                    {'3', '.', '.', '4', '.', '.', '2', '.', '.'},
                    {'.', '5', '.', '1', '.', '.', '.', '.', '3'},
                    {'.', '.', '.', '8', '.', '6', '.', '.', '.'}
                },
                {
                    {'6', '9', '3', '7', '8', '4', '5', '1', '2'},
                    {'4', '8', '7', '5', '1', '2', '9', '3', '6'},
                    {'1', '2', '5', '9', '6', '3', '8', '7', '4'},
                    {'9', '3', '2', '6', '5', '1', '4', '8', '7'},
                    {'5', '6', '8', '2', '4', '7', '3', '9', '1'},
                    {'7', '4', '1', '3', '9', '8', '6', '2', '5'},
                    {'3', '1', '9', '4', '7', '5', '2', '6', '8'},
                    {'8', '5', '6', '1', '2', '9', '7', '4', '3'},
                    {'2', '7', '4', '8', '3', '6', '1', '5', '9'}
                }
            }
        };

        SudokuSolver_37 solver;

        for (size_t i = 0; i < testCases.size(); ++i) {
            const auto& tc = testCases[i];
            const string base = "Sudoku Solver 37 Test " + to_string(i + 1);

            auto plainBoard = tc.input;
            solver.solveSudoku_PlainBacktracking(plainBoard);
            REQUIRE_ASSERT(assertEqScalar(
                base + " [PlainBacktracking]",
                true,
                plainBoard == tc.expected));

            auto bitMasksBoard = tc.input;
            solver.solveSudoku_BitMasks(bitMasksBoard);
            REQUIRE_ASSERT(assertEqScalar(
                base + " [BitMasks]",
                true,
                bitMasksBoard == tc.expected));
        }

        return true;
    }

    /* Backtracking over a 2D search space with visited-state control */

    static bool wordSearch_79_tests() {
        vector<WordSearchTestCase> testCases = {
            // Example 1 from problem statement
            {{{'A', 'B', 'C', 'E'},
              {'S', 'F', 'C', 'S'},
              {'A', 'D', 'E', 'E'}},
             "ABCCED",
             true},

            // Example 2 from problem statement
            {{{'A', 'B', 'C', 'E'},
              {'S', 'F', 'C', 'S'},
              {'A', 'D', 'E', 'E'}},
             "SEE",
             true},

            // Example 3 from problem statement
            {{{'A', 'B', 'C', 'E'},
              {'S', 'F', 'C', 'S'},
              {'A', 'D', 'E', 'E'}},
             "ABCB",
             false},

            // Additional complex test case 1
            {{{'A', 'B', 'C', 'E', 'F', 'G'},
              {'H', 'I', 'J', 'K', 'L', 'M'},
              {'N', 'O', 'P', 'Q', 'R', 'S'},
              {'T', 'U', 'V', 'W', 'X', 'Y'},
              {'Z', 'A', 'B', 'C', 'D', 'E'}},
             "ABCEFGMLKJIHNT",
             true},

            // Additional complex test case 2
            {{{'A', 'B', 'C', 'E', 'F', 'G'},
              {'H', 'I', 'J', 'K', 'L', 'M'},
              {'N', 'O', 'P', 'Q', 'R', 'S'},
              {'T', 'U', 'V', 'W', 'X', 'Y'},
              {'Z', 'A', 'B', 'C', 'D', 'E'}},
             "ZYXWVUTSRQPONMLK",
             false}};

        WordSearch_79 solution;

        for (size_t i = 0; i < testCases.size(); ++i) {
            bool got = solution.exist(testCases[i].board, testCases[i].word);

            const string label = "Word Search Test " + to_string(i + 1);
            REQUIRE_ASSERT(assertEqScalar(label, testCases[i].expected, got));
        }

        return true;
    }

    // ============================================================================
    // Bit Manipulation
    // ============================================================================

    /* Bitwise representation, bit counting, XOR, and binary-string arithmetic */

    static bool base7_504_tests() {
        using namespace TestCases;

        vector<Base7TestCase> testCases = {
            // Examples from the problem statement
            {100, "202"},
            {-7, "-10"},

            // Additional checks
            {0, "0"},
            {1, "1"},
            {7, "10"},
            {343, "1000"}, // 7^3
            {49, "100"},   // 7^2
            {-1, "-1"},
        };

        Base7_504 sol;

        for (size_t i = 0; i < testCases.size(); ++i) {
            const auto& tc = testCases[i];

            string got = sol.convertToBase7(tc.num);

            const string label = "Base 7 504 Test " + to_string(i + 1);
            REQUIRE_ASSERT(assertEqScalar(label, tc.expected, got));
        }

        return true;
    }

    static bool missingNumber_268_tests() {
        vector<MissingNumberTestCase> testCases = {
            // Problem statement examples
            {{3, 0, 1}, 2},
            {{0, 1}, 2},
            {{9, 6, 4, 2, 3, 5, 7, 0, 1}, 8},

            // Additional edge/complex cases
            {{1, 2, 3}, 0},    // missing 0
            {{0, 1, 2, 3}, 4}, // missing n

            // Unsorted, includes n
            {{10, 9, 8, 7, 5, 4, 3, 2, 1, 0}, 6},
        };

        MissingNumber_268 solution;

        for (size_t i = 0; i < testCases.size(); ++i) {
            const auto& tc = testCases[i];

            auto nums = tc.nums; // solver takes non-const ref
            int got = solution.missingNumber(nums);

            const string label = "Missing Number 268 Test " + to_string(i + 1);
            REQUIRE_ASSERT(assertEqScalar(label, tc.expected, got));
        }

        return true;
    }

    static bool singleNumber_136_tests() {
        using namespace TestCases;

        vector<SingleNumberTestCase> testCases = {
            // Examples from the problem statement
            {{2, 2, 1}, 1},
            {{4, 1, 2, 1, 2}, 4},
            {{1}, 1},

            // Additional checks with zeros / negatives
            {{0, 1, 0}, 1},
            {{-1, -1, -2}, -2},
            {{-3, 0, 0, -3, 7}, 7},
        };

        SingleNumber_136 sol;

        for (size_t i = 0; i < testCases.size(); ++i) {
            const auto& tc = testCases[i];

            auto nums = tc.nums; // method takes non-const ref
            int got = sol.singleNumber(nums);

            const string label = "Single Number 136 Test " + to_string(i + 1);
            REQUIRE_ASSERT(assertEqScalar(label, tc.expected, got));
        }

        return true;
    }

    static bool numberOf1Bits_191_tests() {
        vector<NumberOf1BitsTestCase> testCases = {
            {11u, 3},          // 1011
            {128u, 1},         // 10000000
            {2147483645u, 30}, // 0x7FFFFFFD
            {0u, 0},           // zero
            {0xFFFFFFFFu, 32}, // all ones
        };

        NumberOf1Bits_191 solver;

        for (size_t i = 0; i < testCases.size(); ++i) {
            const auto& tc = testCases[i];

            int gotKernighan = solver.hammingWeightKernighan(tc.n);
            int gotLookup = solver.hammingWeightLookup(tc.n);

            const string base =
                "Number of 1 Bits 191 Test " + to_string(i + 1) +
                " (n=" + to_string(tc.n) + ")";

            REQUIRE_ASSERT(assertEqScalar(base + " [Kernighan]", tc.expected, gotKernighan));
            REQUIRE_ASSERT(assertEqScalar(base + " [Lookup]", tc.expected, gotLookup));
        }

        return true;
    }

    static bool addBinary_67_tests() {
        vector<AddBinaryTestCase> testCases = {
            {"11", "1", "100"},        // example 1
            {"1010", "1011", "10101"}, // example 2
            {"0", "0", "0"},           // both zero
            {"1111", "1", "10000"},    // carry over entire length
            {"100", "110010", "110110"}, // different lengths
        };

        AddBinary_67 solver;

        for (size_t i = 0; i < testCases.size(); ++i) {
            const auto& tc = testCases[i];

            string got = solver.addBinary(tc.a, tc.b);

            const string label = "Add Binary 67 Test " + to_string(i + 1);
            REQUIRE_ASSERT(assertEqScalar(label, tc.expected, got));
        }

        return true;
    }

    // ============================================================================
    // Design
    // ============================================================================

    /* Core custom data structures and API-oriented implementations */

    static vector<int> runMinHeapScenario(const vector<MinHeapOp>& ops) {
        MinHeap heap;
        vector<int> output;

        for (const auto& op : ops) {
            switch (op.kind) {
                case MinHeapOpKind::Insert:
                    heap.insert(op.value);
                    break;

                case MinHeapOpKind::ExtractMin:
                    output.push_back(heap.extractMin());
                    break;

                case MinHeapOpKind::Update:
                    heap.update(op.value, op.newValue);
                    break;
            }
        }

        return output;
    }

    static bool minHeap_tests() {
        auto insert = [](int value) {
            return MinHeapOp{MinHeapOpKind::Insert, value};
        };

        auto extractMin = [] {
            return MinHeapOp{MinHeapOpKind::ExtractMin};
        };

        auto update = [](int index, int newValue) {
            return MinHeapOp{MinHeapOpKind::Update, index, newValue};
        };

        vector<MinHeapTestCase> testCases = {
            {
                {
                    insert(5),
                    insert(3),
                    insert(8),
                    insert(1),
                    insert(2),
                    extractMin(),
                    extractMin(),
                },
                {1, 2},
            },
            {
                {
                    insert(10),
                    insert(20),
                    insert(5),
                    update(1, 1), // index 1: 5 -> 1
                    extractMin(),
                },
                {1},
            },
            {
                {
                    insert(100),
                    insert(50),
                    insert(25),
                    extractMin(),
                    extractMin(),
                },
                {25, 50},
            },
        };

        for (size_t i = 0; i < testCases.size(); ++i) {
            const auto& tc = testCases[i];

            vector<int> got = runMinHeapScenario(tc.operations);

            const string label = "MinHeap Test " + to_string(i + 1);
            REQUIRE_ASSERT(assertEqVIntExact(label, tc.expected, got));
        }

        return true;
    }

    static bool allOOneDataStructure_432_tests() {
        auto expectMaxMin = [](const string& label,
                            AllOOneDataStructure_432& ds,
                            initializer_list<string> maxKeys,
                            initializer_list<string> minKeys) {
            return assertMaxMin(
                label,
                [&] { return ds.getMaxKey(); },
                [&] { return ds.getMinKey(); },
                maxKeys,
                minKeys);
        };

        // Basic case
        AllOOneDataStructure_432 ds1;
        ds1.inc("hello");
        ds1.inc("hello");

        REQUIRE_ASSERT(expectMaxMin(
            "AllOOne 432 Test 1 [hello twice]",
            ds1,
            {"hello"},
            {"hello"}));

        ds1.inc("leet");

        REQUIRE_ASSERT(expectMaxMin(
            "AllOOne 432 Test 1 [add leet]",
            ds1,
            {"hello"},
            {"leet"}));

        // Ties
        AllOOneDataStructure_432 ds2;
        ds2.inc("foo");
        ds2.inc("bar");
        ds2.inc("bar");

        REQUIRE_ASSERT(expectMaxMin(
            "AllOOne 432 Test 2 [bar ahead]",
            ds2,
            {"bar"},
            {"foo"}));

        ds2.inc("foo");

        REQUIRE_ASSERT(expectMaxMin(
            "AllOOne 432 Test 2 [tie at 2]",
            ds2,
            {"foo", "bar"},
            {"foo", "bar"}));

        // dec() and removal
        AllOOneDataStructure_432 ds3;
        ds3.inc("a");
        ds3.inc("a");
        ds3.inc("a");
        ds3.inc("b");
        ds3.inc("c");

        REQUIRE_ASSERT(expectMaxMin(
            "AllOOne 432 Test 3 [a=3, b=c=1]",
            ds3,
            {"a"},
            {"b", "c"}));

        ds3.dec("a");
        ds3.dec("a");
        ds3.dec("a");

        REQUIRE_ASSERT(expectMaxMin(
            "AllOOne 432 Test 3 [a removed]",
            ds3,
            {"b", "c"},
            {"b", "c"}));

        return true;
    }

    static bool examRoom_855_tests() {
        auto init = [](int n) {
            return ExamRoomTestCase{
                {"ExamRoom"},
                {{n}},
                {nullopt},
            };
        };

        auto appendSeat = [](ExamRoomTestCase& tc, int expectedSeat) {
            tc.operations.push_back("seat");
            tc.arguments.push_back({});
            tc.expected.push_back(expectedSeat);
        };

        auto appendLeave = [](ExamRoomTestCase& tc, int seatNo) {
            tc.operations.push_back("leave");
            tc.arguments.push_back({seatNo});
            tc.expected.push_back(nullopt);
        };

        vector<ExamRoomTestCase> testCases;

        {
            // Exact sequence from the statement
            auto tc = init(10);

            appendSeat(tc, 0);
            appendSeat(tc, 9);
            appendSeat(tc, 4);
            appendSeat(tc, 2);
            appendLeave(tc, 4);
            appendSeat(tc, 5);

            testCases.push_back(move(tc));
        }

        {
            // Edges cleared and re-filled; checks tie-breaking and edges
            auto tc = init(8);

            appendSeat(tc, 0);
            appendSeat(tc, 7);
            appendSeat(tc, 3);
            appendLeave(tc, 0);
            appendLeave(tc, 7);
            appendSeat(tc, 7);
            appendSeat(tc, 0);
            appendSeat(tc, 5);

            testCases.push_back(move(tc));
        }

        {
            // Interleaved interior leaves and inserts; exercises mid-splits
            auto tc = init(10);

            appendSeat(tc, 0);
            appendSeat(tc, 9);
            appendSeat(tc, 4);
            appendSeat(tc, 2);
            appendLeave(tc, 4);
            appendSeat(tc, 5);
            appendLeave(tc, 2);
            appendSeat(tc, 2);
            appendSeat(tc, 7);
            appendLeave(tc, 5);
            appendSeat(tc, 4);

            testCases.push_back(move(tc));
        }

        for (size_t caseIdx = 0; caseIdx < testCases.size(); ++caseIdx) {
            const auto& tc = testCases[caseIdx];

            REQUIRE_ASSERT(assertEqScalar(
                "Exam Room 855 Test " + to_string(caseIdx + 1) + " [ops/args size]",
                tc.operations.size(),
                tc.arguments.size()));
            REQUIRE_ASSERT(assertEqScalar(
                "Exam Room 855 Test " + to_string(caseIdx + 1) + " [ops/expected size]",
                tc.operations.size(),
                tc.expected.size()));

            optional<ExamRoom_855> room;

            for (size_t stepIdx = 0; stepIdx < tc.operations.size(); ++stepIdx) {
                const string& op = tc.operations[stepIdx];
                const auto& args = tc.arguments[stepIdx];
                const auto& expected = tc.expected[stepIdx];

                const string label =
                    makeStepLabel("Exam Room 855 Test", caseIdx, stepIdx, op, nullopt);

                if (op == "ExamRoom") {
                    REQUIRE_ASSERT(assertEqScalar(label + " [expected void]", false, expected.has_value()));
                    room.emplace(args[0]);
                } else if (op == "seat") {
                    REQUIRE_ASSERT(assertEqScalar(label + " [has expected]", true, expected.has_value()));

                    int got = room->seat();
                    REQUIRE_ASSERT(assertEqScalar(label, expected.value(), got));
                } else if (op == "leave") {
                    REQUIRE_ASSERT(assertEqScalar(label + " [expected void]", false, expected.has_value()));

                    room->leave(args[0]);
                }
            }
        }

        return true;
    }

    /* Randomized object design */

    static bool shuffleAnArray_384_tests() {
        using Vec = vector<int>;

        auto assertChiSquare = [](const string& label,
                                double value,
                                double threshold,
                                bool expectBelow) {
            const bool pass = expectBelow ? value < threshold : value >= threshold;

            cout << label << ": " << (pass ? "PASS" : "FAIL")
                << " (X=" << value << ", threshold=" << threshold << ")\n";

            return pass;
        };

        {
            Vec nums = {1, 2, 3};
            ShuffleAnArray_384_FisherYates sol(nums, /*seed=*/123456789ULL);

            Vec shuffled1 = sol.shuffle();
            Vec reset = sol.reset();
            Vec shuffled2 = sol.shuffle();

            REQUIRE_ASSERT(assertEqScalar(
                "Shuffle 384 Ops Test [shuffle #1 is permutation]",
                true,
                isPermutationVecInt(nums, shuffled1)));
            REQUIRE_ASSERT(assertEqVIntExact(
                "Shuffle 384 Ops Test [reset]",
                nums,
                reset));
            REQUIRE_ASSERT(assertEqScalar(
                "Shuffle 384 Ops Test [shuffle #2 is permutation]",
                true,
                isPermutationVecInt(nums, shuffled2)));
        }

        {
            // Permutation-level uniformity for n=3. The wrong shuffle should be visibly biased.
            Vec base = {1, 2, 3};
            const int numPermutations = 6;
            const int samples = 60000;
            const double threshold = 24.0;

            static const vector<Vec> permutations = [] {
                vector<Vec> all;
                Vec current = {1, 2, 3};

                do {
                    all.push_back(current);
                } while (next_permutation(current.begin(), current.end()));

                return all;
            }();

            auto permutationIndex = [&](const Vec& v) -> int {
                auto it = find(permutations.begin(), permutations.end(), v);
                if (it == permutations.end()) {
                    return -1;
                }

                return static_cast<int>(distance(permutations.begin(), it));
            };

            ShuffleAnArray_384_FisherYates good(base, /*seed=*/987654321ULL);
            ShuffleAnArray_384_Wrong bad(base, /*seed=*/987654321ULL);

            vector<long long> goodCounts(numPermutations, 0);
            vector<long long> badCounts(numPermutations, 0);

            for (int i = 0; i < samples; ++i) {
                good.reset();
                bad.reset();

                const int goodIndex = permutationIndex(good.shuffle());
                const int badIndex = permutationIndex(bad.shuffle());

                if (goodIndex < 0 || badIndex < 0) {
                    cout << "Shuffle 384 Chi-square Test A: FAIL"
                        << " (invalid permutation index"
                        << ", goodIndex=" << goodIndex
                        << ", badIndex=" << badIndex << ")\n";
                    return false;
                }

                ++goodCounts[goodIndex];
                ++badCounts[badIndex];
            }

            const double expected = static_cast<double>(samples) / numPermutations;
            const double goodX = chiSquare(goodCounts, expected);
            const double badX = chiSquare(badCounts, expected);

            REQUIRE_ASSERT(assertChiSquare(
                "Shuffle 384 Chi-square Test A [Fisher-Yates]",
                goodX,
                threshold,
                /*expectBelow=*/true));
            REQUIRE_ASSERT(assertChiSquare(
                "Shuffle 384 Chi-square Test A [wrong shuffle]",
                badX,
                threshold,
                /*expectBelow=*/false));
        }

        {
            // Per-position uniformity for n=5. Each value should appear uniformly across positions.
            Vec base = {0, 1, 2, 3, 4};
            const int n = static_cast<int>(base.size());
            const int samples = 30000;
            const double threshold = 22.0;

            ShuffleAnArray_384_FisherYates good(base, /*seed=*/424242ULL);
            ShuffleAnArray_384_Wrong bad(base, /*seed=*/424242ULL);

            vector<vector<long long>> goodCounts(n, vector<long long>(n, 0));
            vector<vector<long long>> badCounts(n, vector<long long>(n, 0));

            for (int i = 0; i < samples; ++i) {
                good.reset();
                bad.reset();

                Vec goodShuffle = good.shuffle();
                Vec badShuffle = bad.shuffle();

                for (int pos = 0; pos < n; ++pos) {
                    ++goodCounts[goodShuffle[pos]][pos];
                    ++badCounts[badShuffle[pos]][pos];
                }
            }

            const double expected = static_cast<double>(samples) / n;
            bool goodUniform = true;
            bool badBiased = false;

            for (int value = 0; value < n; ++value) {
                const double goodX = chiSquare(goodCounts[value], expected);
                const double badX = chiSquare(badCounts[value], expected);

                if (goodX >= threshold) {
                    goodUniform = false;
                }
                if (badX >= threshold) {
                    badBiased = true;
                }
            }

            REQUIRE_ASSERT(assertEqScalar(
                "Shuffle 384 Chi-square Test B [Fisher-Yates per-position]",
                true,
                goodUniform));
            REQUIRE_ASSERT(assertEqScalar(
                "Shuffle 384 Chi-square Test B [wrong shuffle detected]",
                true,
                badBiased));
        }

        return true;
    }

    // ============================================================================
    // Other
    // ============================================================================

    /* Problems that do not fit cleanly into the main technique-based categories */

    static bool findCelebrity_277_tests() {
        vector<FindCelebrityTestCase> testCases = {
            // 1 is the celebrity
            {{{0, 1}, {0, 0}}, 1},

            // Single person is trivially the celebrity
            {{{0}}, 0},

            // No celebrity: 0 and 1 know each other
            {{{0, 1}, {1, 0}}, -1},

            // 2 is the celebrity
            {
                {
                    {0, 1, 1},
                    {0, 0, 1},
                    {0, 0, 0},
                },
                2,
            },

            // No celebrity: candidate 2 knows 0
            {
                {
                    {0, 1, 1},
                    {0, 0, 1},
                    {1, 0, 0},
                },
                -1,
            },

            // 3 is the celebrity
            {
                {
                    {0, 1, 1, 1},
                    {0, 0, 1, 1},
                    {0, 0, 0, 1},
                    {0, 0, 0, 0},
                },
                3,
            },

            // Larger case: 6 is the celebrity
            {
                {
                    {0, 1, 1, 1, 1, 1, 1},
                    {0, 0, 1, 1, 1, 1, 1},
                    {0, 0, 0, 1, 1, 1, 1},
                    {0, 0, 0, 0, 1, 1, 1},
                    {0, 0, 0, 0, 0, 1, 1},
                    {0, 0, 0, 0, 0, 0, 1},
                    {0, 0, 0, 0, 0, 0, 0},
                },
                6,
            },
        };

        for (size_t i = 0; i < testCases.size(); ++i) {
            const auto& tc = testCases[i];

            FindCelebrity_277 sol;
            sol.knowsMatrix = tc.matrix;

            int got = sol.findCelebrity(static_cast<int>(tc.matrix.size()));

            const string label = "Find Celebrity 277 Test " + to_string(i + 1);
            REQUIRE_ASSERT(assertEqScalar(label, tc.expected, got));
        }

        return true;
    }

    static bool validNumber_65_tests() {
        vector<ValidNumberTestCase> testCases = {
            // Valid integers / decimals
            {"0", true},
            {"2", true},
            {"0089", true},
            {"-0.1", true},
            {"+3.14", true},
            {"4.", true},
            {"-.9", true},

            // Valid exponent forms
            {"2e10", true},
            {"-90E3", true},
            {"3e+7", true},
            {"+6e-1", true},
            {"53.5e93", true},
            {"-123.456e789", true},

            // Invalid forms
            {"e", false},
            {".", false},
            {"abc", false},
            {"1a", false},
            {"99e2.5", false},
            {"1e", false},
            {"e3", false},
            {"--6", false},
            {"-+3", false},
            {"95a54e53", false},
            {"+.", false},
            {".e1", false},
            {"6e6.5", false},
        };

        ValidNumber_65 solver;

        for (size_t i = 0; i < testCases.size(); ++i) {
            const auto& tc = testCases[i];

            bool got = solver.isNumber(tc.input);

            const string label =
                "Valid Number 65 Test " + to_string(i + 1) +
                " [\"" + tc.input + "\"]";
            REQUIRE_ASSERT(assertEqScalar(label, tc.expected, got));
        }

        return true;
    }

    static vector<TestRegistry::Entry> getTests() {
        vector<TestRegistry::Entry> tests = {
            // ============================================================================
            // Arrays & Strings
            // ============================================================================

            /* Simple iteration, counting, and basic array/string traversal */
            TEST(412,  "FizzBuzz",                                       fizzBuzz_412_tests),
            TEST(2798, "Number of Employees Who Met the Target",         numberOfEmployeesWhoMetTarget_2798_tests),
            TEST(1768, "Merge Strings Alternately",                      mergeStringsAlternately_1768_tests),
            TEST(2239, "Find Closest Number to Zero",                    findClosestNumber_2239_tests),

            /* Sequence comparison, prefix checks, and simple string parsing */
            TEST(392,  "Is Subsequence",                                 isSubsequence_392_tests),
            TEST(14,   "Longest Common Prefix",                          longestCommonPrefix_14_tests),
            TEST(228,  "Summary Ranges",                                 summaryRanges_228_tests),
            TEST(13,   "Roman to Integer",                               romanToInteger_13_tests),

            /* In-place array updates and two-pointer style compaction/merge */
            TEST(26,   "Remove Duplicates From Sorted Array",            removeDuplicatesFromSortedArray_26_tests),
            TEST(27,   "Remove Element",                                 removeElement_27_tests),
            TEST(88,   "Merge Sorted Array",                             mergeSortedArray_88_tests),
            TEST(80,   "Remove Duplicates from Sorted Array II",         removeDuplicatesFromSortedArrayII_80_tests),

            /* Greedy scans, prefix thinking, and simple counting ideas */
            TEST(121,  "Best Time to Buy and Sell Stock",                bestTimeToBuyAndSellStock_121_tests),
            TEST(122,  "Best Time to Buy and Sell Stock II",             bestTimeToBuyAndSellStockII_122_tests),
            TEST(724,  "Find Pivot Index",                               findPivotIndex_724_tests),
            TEST(3074, "Apple Redistribution Into Boxes",                appleRedistributionIntoBoxes_3074_tests),
            TEST(3046, "Split the Array",                                splitTheArray_3046_tests),

            /* Core array techniques: construction, partitioning, and prefix products */
            TEST(118,  "Pascal's Triangle",                              pascalsTriangle_118_tests),
            TEST(75,   "Sort Colors",                                    sortColors_75_tests),
            TEST(238,  "Product of Array Except Self",                   productOfArrayExceptSelf_238_tests),
            TEST(274,  "H-Index",                                        hIndex_274_tests),

            /* More advanced transformations on intervals, strings, and matrices */
            TEST(56,   "Merge Intervals",                                mergeIntervals_56_tests),
            TEST(6,    "Zigzag Conversion",                              zigzagConversion_6_tests),

            /* 2D matrix traversal and in-place matrix transformation */
            TEST(48,   "Rotate Image",                                   rotateImage_48_tests),
            TEST(54,   "Spiral Matrix",                                  spiralMatrix_54_tests),

            /* Preprocessing optimization for repeated subsequence queries */
            TEST(392,  "Is Subsequence (next-position table)",           isSubsequence_392_nextpos_tests),
        };

        {
            auto hashmapTests = TestsHashmapsSets::getTests();
            tests.insert(tests.end(), hashmapTests.begin(), hashmapTests.end());
        }

        {
            auto twoPointerTests = TestsTwoPointers::getTests();
            tests.insert(tests.end(), twoPointerTests.begin(), twoPointerTests.end());
        }

        {
            auto stackTests = TestsStacks::getTests();
            tests.insert(tests.end(), stackTests.begin(), stackTests.end());
        }

        {
            auto linkedListTests = TestsLinkedLists::getTests();
            tests.insert(tests.end(), linkedListTests.begin(), linkedListTests.end());
        }

        {
            auto binarySearchTests = TestsBinarySearch::getTests();
            tests.insert(tests.end(), binarySearchTests.begin(), binarySearchTests.end());
        }

        const vector<TestRegistry::Entry> afterBinarySearch = {
            // ============================================================================
            // Sliding Window
            // ============================================================================

            /* Fixed-size windows with rolling updates */
            TEST(643,  "Maximum Average Subarray I",                     maximumAverageSubarrayI_643_tests),

            /* Expanding and shrinking windows with a running constraint */
            TEST(1004, "Max Consecutive Ones III",                       maxConsecutiveOnesIII_1004_tests),
            TEST(209,  "Minimum Size Subarray Sum",                      minimumSizeSubarraySum_209_tests),

            /* Variable-size windows for distinctness and replacement limits */
            TEST(3,    "Longest Substring Without Repeating Characters", longestSubstringWithoutRepeatingCharacters_3_tests),
            TEST(424,  "Longest Repeating Character Replacement",        longestRepeatingCharacterReplacement_424_tests),

            /* Window matching with character-frequency requirements */
            TEST(567,  "Permutation in String",                          permutationInString_567_tests),
        };

        tests.insert(tests.end(), afterBinarySearch.begin(), afterBinarySearch.end());

        {
            auto treeTests = TestsTrees::getTests();
            tests.insert(tests.end(), treeTests.begin(), treeTests.end());
        }

        const vector<TestRegistry::Entry> afterTrees = {
            // ============================================================================
            // Heaps
            // ============================================================================

            /* Basic max-heap / min-heap simulation */
            TEST(1046, "Last Stone Weight",                              lastStoneWeight_1046_tests),

            /* Heap-based selection for k-th / top-k queries */
            TEST(215,  "Kth Largest Element in an Array",                kthLargestElementInArray_215_tests),
            TEST(347,  "Top K Frequent Elements",                        topKFrequent_347_tests),
            TEST(973,  "K Closest Points to Origin",                     kClosestPointsToOrigin_973_tests),

            /* Merging multiple sorted streams with a heap frontier */
            TEST(23,   "Merge K Sorted Lists",                           mergeKSortedLists_23_tests),

            /* Priority-queue traversal on a graph / grid state space */
            TEST(2812, "Find the Safest Path in a Grid",                 findTheSafestPathInGrid_2812_tests),

            // ============================================================================
            // Recursive Backtracking
            // ============================================================================

            /* Basic recursive generation of subsets, combinations, and permutations */
            TEST(78,   "Subsets",                                        subsets_78_tests),
            TEST(77,   "Combinations",                                   combinations_77_tests),
            TEST(46,   "Permutations",                                   permutations_46_tests),

            /* Backtracking with constraints and incremental choice building */
            TEST(17,   "Letter Combinations",                            letterCombinations_17_tests),
            TEST(22,   "Generate Parentheses",                           generateParentheses_22_tests),
            TEST(39,   "Combination Sum",                                combinationSum_39_tests),

            /* Constraint-based board backtracking */
            TEST(37,   "Sudoku Solver",                                  sudokuSolver_37_tests),

            /* Backtracking over a 2D search space with visited-state control */
            TEST(79,   "Word Search",                                    wordSearch_79_tests),
        };

        tests.insert(tests.end(), afterTrees.begin(), afterTrees.end());

        {
            auto graphTests = TestsGraphs::getTests();
            tests.insert(tests.end(), graphTests.begin(), graphTests.end());
        }

        {
            auto dpTests = TestsDynamicProgramming::getTests();
            tests.insert(tests.end(), dpTests.begin(), dpTests.end());
        }

        const vector<TestRegistry::Entry> afterDynamicProgramming = {
            // ============================================================================
            // Bit Manipulation
            // ============================================================================

            /* Bitwise representation, bit counting, XOR, and binary-string arithmetic */
            TEST(504,  "Base 7",                                         base7_504_tests),
            TEST(268,  "Missing Number",                                 missingNumber_268_tests),
            TEST(136,  "Single Number",                                  singleNumber_136_tests),
            TEST(191,  "Number of 1 Bits",                               numberOf1Bits_191_tests),
            TEST(67,   "Add Binary",                                     addBinary_67_tests),

            // ============================================================================
            // Design
            // ============================================================================

            /* Core custom data structures and API-oriented implementations */
            TEST(0,    "MinHeap",                                        minHeap_tests), // custom: id=0
            TEST(432,  "All O`one Data Structure",                       allOOneDataStructure_432_tests),
            TEST(855,  "Exam Room",                                      examRoom_855_tests),

            /* Randomized object design */
            TEST(384,  "Shuffle an Array",                               shuffleAnArray_384_tests),

            // ============================================================================
            // Other
            // ============================================================================

            /* Problems that do not fit cleanly into the main technique-based categories */
            TEST(277,  "Find the Celebrity",                             findCelebrity_277_tests),
            TEST(65,   "Valid Number",                                   validNumber_65_tests),
        };

        tests.insert(tests.end(),
                     afterDynamicProgramming.begin(),
                     afterDynamicProgramming.end());
        return tests;
    }

    static bool runAllTests() {
        return TestRegistry::runAllTests(getTests());
    }
};

int main() {
    cout << "Running LeetCodeCpp tests:\n";
    TestsRunner::runAllTests();
    return 0;
}
