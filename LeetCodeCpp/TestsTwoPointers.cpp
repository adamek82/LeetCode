#include "TestsTwoPointers.h"

#include <algorithm>
#include <string>
#include <vector>

#include "TestCases.h"
#include "TestUtils.h"

#include "ReverseString_344.h"
#include "ValidPalindrome_125.h"

#include "SquaresOfSortedArray_977.h"
#include "TwoSumII_167.h"
#include "TwoSumLessThanK_1099.h"

#include "ThreeSum_15.h"
#include "ThreeSumClosest_16.h"
#include "FourSum_18.h"

#include "ContainerWithMostWater_11.h"
#include "TrappingRainWater_42.h"

using namespace std;
using namespace TestCases;
using namespace TestUtils;

namespace {

/* Opposite-end pointers for simple in-place processing */

static bool reverseString_344_tests() {
    // build a large case up-front so it can be placed inside the uniform-init list
    vector<char> longIn;
    for (int i = 0; i < 10000; ++i) longIn.push_back('a' + (i % 26));
    vector<char> longOut(longIn.rbegin(), longIn.rend());

    vector<ReverseStringTestCase> testCases = {
        // two examples from the problem statement
        {{'h','e','l','l','o'},            {'o','l','l','e','h'}},
        {{'H','a','n','n','a','h'},        {'h','a','n','n','a','H'}},

        // three additional cases
        {{'a'},                            {'a'}},                       // length-1
        {{'a','b','c','c','b','a'},        {'a','b','c','c','b','a'}},   // palindrome
        {move(longIn),                     move(longOut)}                // 10 000 chars
    };

    ReverseString_344 solver;

    for (size_t i = 0; i < testCases.size(); ++i) {
        auto s = testCases[i].input; // work on a copy
        solver.reverseString(s);

        const string got(s.begin(), s.end());
        const string expected(testCases[i].expected.begin(), testCases[i].expected.end());

        const string label = "Reverse String 344 Test " + to_string(i + 1);
        REQUIRE_ASSERT(assertEqScalar(label, expected, got));
    }

    return true;
}

static bool validPalindrome_125_tests() {
    // Build a long palindrome of 10,000 'a' with commas between (punctuation ignored by checker)
    constexpr int N = 10000;
    string longStr(2 * N, ',');
    for (int i = 0; i < 2 * N; i += 2) longStr[i] = 'a';

    vector<ValidPalindromeTestCase> testCases = {
        // two examples from the problem statement
        {"A man, a plan, a canal: Panama", true},
        {"race a car",                     false},

        // third example from the statement
        {" ",                              true},

        // two additional cases
        {"0P",                             false}, // mixed digit/letter
        {move(longStr),                    true}   // long palindrome
    };

    ValidPalindrome_125 solver;

    for (size_t i = 0; i < testCases.size(); ++i) {
        bool got = solver.isPalindrome(testCases[i].input);

        const string label = "Valid Palindrome 125 Test " + to_string(i + 1);
        REQUIRE_ASSERT(assertEqScalar(label, testCases[i].expected, got));
    }

    return true;
}

/* Two-pointer scans on sorted arrays */

static bool squaresOfSortedArray_977_tests() {
    vector<SquaresOfASortedArrayTestCase> testCases = {
        // 2 examples from the problem statement
        {{-4, -1, 0, 3, 10},      {0, 1, 9, 16, 100}},
        {{-7, -3, 2, 3, 11},      {4, 9, 9, 49, 121}},
        // 3 additional (one is a corner case)
        {{-10, -5, -2, -1},       {1, 4, 25, 100}},               // all negatives
        {{0},                     {0}},                           // corner: single element
        {{-10000, -3, -3, 0, 2, 10000},
                                {0, 4, 9, 9, 100000000, 100000000}} // extremes & duplicates
    };

    SquaresOfSortedArray_977 sol;

    for (size_t i = 0; i < testCases.size(); ++i) {
        auto got = sol.sortedSquares(testCases[i].nums);

        const string label = "Squares of Sorted Array 977 Test " + to_string(i + 1);
        REQUIRE_ASSERT(assertEqVIntExact(label, testCases[i].expected, got));
    }

    return true;
}

static bool twoSumII_167_tests() {
    // long stress-case prepared first so it can go in the init-list
    vector<int> longNums;
    for (int v = -1000; v <= 1000; ++v) longNums.push_back(v);  // 2001 elements
    vector<int> longAns = {1, static_cast<int>(longNums.size())};  // -1000 + 1000 = 0

    vector<TwoSumIIInputArrayIsSortedTestCase> testCases = {
        // three examples from the statement
        {{2,7,11,15},                  9,  {1,2}},
        {{2,3,4},                      6,  {1,3}},
        {{-1,0},                      -1,  {1,2}},

        // two additional cases
        {{1,3,4,7,11,15},             15,  {3,5}},          // mid-array pair
        {move(longNums),               0,  move(longAns)}   // 2001-element stress
    };

    TwoSumII_167 solver;

    for (size_t i = 0; i < testCases.size(); ++i) {
        auto nums = testCases[i].numbers; // solve on a copy
        auto got  = solver.twoSum(nums, testCases[i].target);

        const string label = "Two Sum II 167 Test " + to_string(i + 1);
        REQUIRE_ASSERT(assertEqVIntExact(label, testCases[i].expected, got));
    }

    return true;
}

static bool twoSumLessThanK_1099_tests() {
    vector<TwoSumLessThanKTestCase> testCases = {
        // statement example
        {{34, 23, 1, 24, 75, 33, 54, 8}, 60, 58},   // 24 + 34

        // no valid pair
        {{10, 20, 30}, 15, -1},

        // duplicates
        {{1, 1, 1}, 3, 2},

        // negatives + positives
        {{-5, -2, 0, 1, 3}, 2, 1},                 // 0 + 1 or -2 + 3
    };

    TwoSumLessThanK_1099 solver;

    for (size_t i = 0; i < testCases.size(); ++i) {
        auto nums = testCases[i].nums;  // solver sorts in-place
        int got = solver.twoSumLessThanK(nums, testCases[i].k);

        const string label = "Two Sum Less Than K 1099 Test " + to_string(i + 1);
        REQUIRE_ASSERT(assertEqScalar(label, testCases[i].expected, got));
    }

    return true;
}

/* Two-pointer optimization after sorting */

static bool threeSum_15_tests() {
    vector<ThreeSumTestCase> testCases = {
        // two examples from the problem statement
        {{-1,0,1,2,-1,-4},            {{-1,-1,2},{-1,0,1}}},
        {{0,1,1},                     {}},

        // third statement example
        {{0,0,0},                     {{0,0,0}}},

        // two additional cases
        {{-2,0,1,1,2},                {{-2,0,2},{-2,1,1}}},
        {{-2,-2,1,3,1,2,0,0},         {{-2,0,2},{-2,1,1}}}
    };

    ThreeSum_15 solver;

    for (size_t i = 0; i < testCases.size(); ++i) {
        auto got = solver.threeSum(testCases[i].nums);

        const string label = "Three Sum 15 Test " + to_string(i + 1);
        REQUIRE_ASSERT(assertEqVVIntAnyOrder(label, testCases[i].expected, got));
    }

    return true;
}

static bool threeSumClosest_16_tests() {
    vector<ThreeSumClosestTestCase> testCases = {
        // two examples from the problem statement
        {{-1, 2, 1, -4}, 1, 2},
        {{0, 0, 0},      1, 0},

        // additional cases
        // all positive, target smaller than all sums
        {{1, 1, 1, 0},  -100, 2},

        // exact match exists
        {{1, 2, 3, 4},   6, 6},    // 1 + 2 + 3

        // mixed positives/negatives, more spread out
        {{1, 2, 5, 10, 11}, 12, 13}, // closest is 1 + 2 + 10 = 13

        // duplicate values, multiple triplets with same distance
        {{-1, -1, 1, 1, 3}, 0, -1}    // sums closest to 0 are -1 and 1 (distance 1)
    };

    ThreeSumClosest_16 solver;

    for (size_t i = 0; i < testCases.size(); ++i) {
        auto nums = testCases[i].nums;  // solve on a copy (project style)
        int got   = solver.threeSumClosest(nums, testCases[i].target);

        const string label = "Three Sum Closest 16 Test " + to_string(i + 1);
        REQUIRE_ASSERT(assertEqScalar(label, testCases[i].expected, got));
    }

    return true;
}

static bool fourSum_18_tests() {
    vector<FourSumTestCase> testCases = {
        // two examples from the problem statement
        {{1, 0, -1, 0, -2, 2}, 0,
            {
                {-2, -1, 1, 2},
                {-2,  0, 0, 2},
                {-1,  0, 0, 1},
            }},
        {{2, 2, 2, 2, 2}, 8,
            {
                {2, 2, 2, 2},
            }},

        // no solution
        {{1, 2, 3, 4}, 100, {}},

        // mixed positives/negatives, single solution
        {{-3, -1, 0, 2, 4, 5}, 2,
            {
                {-3, -1, 2, 4},
            }},

        // duplicates and multiple distinct quadruplets
        {{-3, -1, -1, 0, 2, 2, 2, 4}, 0,
            {
                {-3, -1, 0, 4},
                {-3, -1, 2, 2},
                {-1, -1, 0, 2},
            }},
    };

    FourSum_18 solver;

    for (size_t i = 0; i < testCases.size(); ++i) {
        auto nums = testCases[i].nums;  // work on a copy
        auto got  = solver.fourSum(nums, testCases[i].target);

        const string label = "Four Sum 18 Test " + to_string(i + 1);
        REQUIRE_ASSERT(assertEqVVIntAnyOrder(label, testCases[i].expected, got));
    }

    return true;
}

/* Shrinking-window reasoning with left/right boundaries */

static bool containerWithMostWater_11_tests() {
    vector<ContainerWithMostWaterTestCase> testCases = {
        // two examples from the statement
        {{1,8,6,2,5,4,8,3,7}, 49},
        {{1,1},                1},

        // three additional cases
        {{4,3,2,1,4},          16}, // equal ends
        {{1,2,1},              2},  // small valley
        {{2,3,10,5,7,8,9},     36}  // tall inner peak
    };

    ContainerWithMostWater_11 solver;

    for (size_t i = 0; i < testCases.size(); ++i) {
        int got = solver.maxArea(testCases[i].height);

        const string label = "Container With Most Water 11 Test " + to_string(i + 1);
        REQUIRE_ASSERT(assertEqScalar(label, testCases[i].expected, got));
    }

    return true;
}

static bool trappingRainWater_42_tests() {
    vector<TrappingRainWaterTestCase> testCases = {
        // two examples from the statement
        {{0,1,0,2,1,0,1,3,2,1,2,1}, 6},
        {{4,2,0,3,2,5},             9},

        // three additional cases
        {{0,0,0},                   0},  // flat
        {{1,2,3,4,5},               0},  // monotonic
        {{5,4,1,2},                 1},  // small basin
        {{4,0,0,0,4},               12}
    };

    TrappingRainWater_42 solver;

    for (size_t i = 0; i < testCases.size(); ++i) {
        int got = solver.trap(testCases[i].height);

        const string label = "Trapping Rain Water 42 Test " + to_string(i + 1);
        REQUIRE_ASSERT(assertEqScalar(label, testCases[i].expected, got));
    }

    return true;
}

} // namespace

namespace TestsTwoPointers {

std::vector<TestRegistry::Entry> getTests() {
    return {
        // Opposite-end pointers for simple in-place processing
        TEST(344,  "Reverse String",              reverseString_344_tests),
        TEST(125,  "Valid Palindrome",            validPalindrome_125_tests),

        // Two-pointer scans on sorted arrays
        TEST(977,  "Squares of a Sorted Array",   squaresOfSortedArray_977_tests),
        TEST(167,  "Two Sum II",                  twoSumII_167_tests),
        TEST(1099, "Two Sum Less Than K",         twoSumLessThanK_1099_tests),

        // Two-pointer optimization after sorting
        TEST(15,   "3Sum",                        threeSum_15_tests),
        TEST(16,   "3Sum Closest",                threeSumClosest_16_tests),
        TEST(18,   "4Sum",                        fourSum_18_tests),

        // Shrinking-window reasoning with left/right boundaries
        TEST(11,   "Container With Most Water",   containerWithMostWater_11_tests),
        TEST(42,   "Trapping Rain Water",         trappingRainWater_42_tests),
    };
}

} // namespace TestsTwoPointers
