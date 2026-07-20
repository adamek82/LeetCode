#include "TestsArrayGreedyTransform.h"

#include <algorithm>
#include <string>
#include <vector>

#include "TestCases.h"
#include "TestUtils.h"

#include "BestTimeToBuyAndSellStock_121.h"
#include "BestTimeToBuyAndSellStockII_122.h"
#include "FindPivotIndex_724.h"
#include "AppleRedistributionIntoBoxes_3074.h"
#include "SplitTheArray_3046.h"

#include "MergeIntervals_56.h"
#include "ZigzagConversion_6.h"

using namespace std;
using namespace TestCases;
using namespace TestUtils;

namespace {

/* Greedy scans, prefix thinking, and simple counting ideas */

bool bestTimeToBuyAndSellStock_121_tests() {
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

bool bestTimeToBuyAndSellStockII_122_tests() {
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

bool findPivotIndex_724_tests() {
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

bool appleRedistributionIntoBoxes_3074_tests() {
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

bool splitTheArray_3046_tests() {
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

/* More advanced transformations on intervals, strings, and matrices */

bool mergeIntervals_56_tests() {
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

bool zigzagConversion_6_tests() {
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

} // namespace

namespace TestsArrayGreedyTransform {

std::vector<TestRegistry::Entry> getTests() {
    return {
        // Greedy scans, prefix thinking, and simple counting ideas
        TEST(121,  "Best Time to Buy and Sell Stock",     bestTimeToBuyAndSellStock_121_tests),
        TEST(122,  "Best Time to Buy and Sell Stock II",  bestTimeToBuyAndSellStockII_122_tests),
        TEST(724,  "Find Pivot Index",                    findPivotIndex_724_tests),
        TEST(3074, "Apple Redistribution Into Boxes",     appleRedistributionIntoBoxes_3074_tests),
        TEST(3046, "Split the Array",                     splitTheArray_3046_tests),

        // More advanced transformations on intervals, strings, and matrices
        TEST(56,   "Merge Intervals",                     mergeIntervals_56_tests),
        TEST(6,    "Zigzag Conversion",                   zigzagConversion_6_tests),
    };
}

} // namespace TestsArrayGreedyTransform
