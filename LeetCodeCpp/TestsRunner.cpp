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
#include "TestsBasicArraysStrings.h"
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
#include "SortCharactersByFrequency_451.h"
#include "TopKFrequentWords_692.h"
#include "TwoSum_1.h"
#include "MergeSortedArray_88.h"
#include "RemoveElement_27.h"
#include "MaximumNumberOfBalloons_1189.h"
#include "FindPivotIndex_724.h"
#include "JewelsAndStones_771.h"
#include "ContainsDuplicate_217.h"
#include "RemoveDuplicates_26.h"
#include "LongestIncreasingPathInMatrix_329.h"
#include "SplitTheArray_3046.h"
#include "RansomNote_383.h"
#include "IslandPerimeter_463.h"
#include "AppleRedistributionIntoBoxes_3074.h"
#include "UniqueNumberOfOccurrences_1207.h"
#include "DesignHashMap_706.h"
#include "PascalsTriangle_118.h"
#include "SlidingPuzzle_773.h"

using namespace std;
using namespace TestUtils;
using namespace TestCases;

class TestsRunner {
public:
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

private:
    static void appendTests(vector<TestRegistry::Entry>& dst,
                            vector<TestRegistry::Entry> src) {
        dst.insert(dst.end(), src.begin(), src.end());
    }

    static vector<TestRegistry::Entry> getTests() {
        vector<TestRegistry::Entry> tests;

        appendTests(tests, TestsBasicArraysStrings::getTests());

        const vector<TestRegistry::Entry> remainingArrayStringTests = {
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
        };

        tests.insert(tests.end(),
             remainingArrayStringTests.begin(),
             remainingArrayStringTests.end());

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
