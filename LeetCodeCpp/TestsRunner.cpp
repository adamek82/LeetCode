#include <algorithm>
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
#include "TestsSlidingWindow.h"
#include "TestsHeaps.h"
#include "TestsBacktracking.h"
#include "TestsBitManipulation.h"
#include "TestsDesign.h"
#include "TestsOther.h"
#include "ListUtils.h"
#include "TreeUtils.h"
#include "BestTimeToBuyAndSellStock_121.h"
#include "SpiralMatrix_54.h"
#include "KthLargestElementInArray_215.h"
#include "RotateImage_48.h"
#include "MergeIntervals_56.h"
#include "ProductOfArrayExceptSelf.h"
#include "MajorityElement_169.h"
#include "ValidSudoku_36.h"
#include "ZigzagConversion_6.h"
#include "HIndex_274.h"
#include "SortColors_75.h"
#include "RemoveDuplicatesFromSortedArrayII_80.h"
#include "BestTimeToBuyAndSellStockII_122.h"
#include "ValidAnagram_242.h"
#include "AnalyzeUserWebsiteVisitPattern1152.h"
#include "GroupAnagrams_49.h"
#include "LongestConsecutiveSequence_128.h"
#include "FizzBuzz_412.h"
#include "SortCharactersByFrequency_451.h"
#include "TopKFrequentWords_692.h"
#include "TwoSum_1.h"
#include "MergeSortedArray_88.h"
#include "RemoveElement_27.h"
#include "MaximumNumberOfBalloons_1189.h"
#include "FindPivotIndex_724.h"
#include "JewelsAndStones_771.h"
#include "ContainsDuplicate_217.h"
#include "FindClosestNumberToZero_2239.h"
#include "MergeStringsAlternately_1768.h"
#include "RomanToInteger_13.h"
#include "IsSubsequence_392.h"
#include "LongestCommonPrefix_14.h"
#include "SummaryRanges_228.h"
#include "RemoveDuplicates_26.h"
#include "LongestIncreasingPathInMatrix_329.h"
#include "SplitTheArray_3046.h"
#include "RansomNote_383.h"
#include "IslandPerimeter_463.h"
#include "AppleRedistributionIntoBoxes_3074.h"
#include "UniqueNumberOfOccurrences_1207.h"
#include "NumberOfEmployeesWhoMetTarget_2798.h"
#include "DesignHashMap_706.h"
#include "PascalsTriangle_118.h"
#include "SlidingPuzzle_773.h"

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

private:
    static void appendTests(vector<TestRegistry::Entry>& dst,
                            vector<TestRegistry::Entry> src) {
        dst.insert(dst.end(), src.begin(), src.end());
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

        appendTests(tests, TestsHashmapsSets::getTests());
        appendTests(tests, TestsTwoPointers::getTests());
        appendTests(tests, TestsStacks::getTests());
        appendTests(tests, TestsLinkedLists::getTests());
        appendTests(tests, TestsBinarySearch::getTests());
        appendTests(tests, TestsSlidingWindow::getTests());
        appendTests(tests, TestsTrees::getTests());
        appendTests(tests, TestsHeaps::getTests());
        appendTests(tests, TestsBacktracking::getTests());
        appendTests(tests, TestsGraphs::getTests());
        appendTests(tests, TestsDynamicProgramming::getTests());
        appendTests(tests, TestsBitManipulation::getTests());
        appendTests(tests, TestsDesign::getTests());
        appendTests(tests, TestsOther::getTests());

        return tests;
    }

public:
    static bool runAllTests() {
        return TestRegistry::runAllTests(getTests());
    }
};

int main() {
    cout << "Running LeetCodeCpp tests:\n";
    TestsRunner::runAllTests();
    return 0;
}
