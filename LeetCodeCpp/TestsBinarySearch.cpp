#include "TestsBinarySearch.h"

#include <string>
#include <vector>

#include "TestCases.h"
#include "TestUtils.h"

#include "BinarySearch_704.h"
#include "SearchInsertPosition_35.h"
#include "FirstBadVersion_278.h"

#include "SqrtX_69.h"
#include "ValidPerfectSquare_367.h"
#include "KokoEatingBananas_875.h"

#include "Search2DMatrix_74.h"
#include "FindMinimumInRotatedSortedArray_153.h"
#include "SearchInRotatedSortedArray_33.h"

using namespace std;
using namespace TestCases;
using namespace TestUtils;

namespace {

/* Basic binary search on sorted arrays and monotonic positions */

bool binarySearch_704_tests() {
    vector<BinarySearchTestCase> testCases = {
        // Example 1
        {{-1, 0, 3, 5, 9, 12}, 9, 4},
        // Example 2
        {{-1, 0, 3, 5, 9, 12}, 2, -1},
        // Complex Case 1: Large range with the target in the middle
        {{-10000, -5000, 0, 5000, 10000}, 0, 2},
        // Complex Case 2: Target near boundaries
        {{1, 3, 5, 7, 9, 11}, 11, 5}, // Target is the last element
        // Corner Case: Single element, no match
        {{1}, 0, -1}
    };

    BinarySearch_704 solution;

    for (size_t i = 0; i < testCases.size(); ++i) {
        int got = solution.search(testCases[i].nums, testCases[i].target);

        const string label = "Binary Search Test " + to_string(i + 1);
        REQUIRE_ASSERT(assertEqScalar(label, testCases[i].expected, got));
    }

    return true;
}

bool searchInsertPosition_35_tests() {
    vector<BinarySearchTestCase> testCases = {
        // Example 1: Target is found
        {{1, 3, 5, 6}, 5, 2},
        // Example 2: Target is not found, insert at index 1
        {{1, 3, 5, 6}, 2, 1},
        // Example 3: Target is not found, insert at the end
        {{1, 3, 5, 6}, 7, 4},
        // Complex Case 1: Large range with insertion at the beginning
        {{10, 20, 30, 40, 50}, 5, 0},
        // Complex Case 2: Large range with insertion in the middle
        {{10, 20, 30, 40, 50, 60, 70, 80, 90, 100}, 55, 5}
    };

    SearchInsertPosition_35 solution;

    for (size_t i = 0; i < testCases.size(); ++i) {
        int got = solution.searchInsert(testCases[i].nums, testCases[i].target);

        const string label = "Search Insert Position Test " + to_string(i + 1);
        REQUIRE_ASSERT(assertEqScalar(label, testCases[i].expected, got));
    }

    return true;
}

bool firstBadVersion_278_tests() {
    vector<FirstBadVersionTestCase> testCases = {
        // Example: first bad in the middle
        {5, 4, 4},
        // Edge: only one version, and it's bad
        {1, 1, 1},
        // Edge: first version is bad
        {10, 1, 1},
        // Edge: last version is first bad
        {10, 10, 10},
        // Larger range: first bad somewhere in the interior
        {1000, 537, 537}
    };

    for (size_t i = 0; i < testCases.size(); ++i) {
        const auto& tc = testCases[i];

        FirstBadVersion_278 sol;

        sol.firstBad = tc.firstBad;
        int got = sol.firstBadVersion(tc.n);

        const string label = "First Bad Version 278 Test " + to_string(i + 1);
        REQUIRE_ASSERT(assertEqScalar(label, tc.expected, got));
    }

    return true;
}

/* Binary search over a numeric answer space */

bool sqrtX_69_tests() {
    vector<SqrtXTestCase> testCases = {
        // Examples from the problem statement
        {4, 2},
        {8, 2},

        // Additional edge / boundary tests
        {0, 0},
        {1, 1},
        {2, 1},
        {2147395600, 46340}, // 46340^2, largest square within int range
        {2147483647, 46340}  // INT_MAX, not a perfect square
    };

    SqrtX_69 solution;

    for (size_t i = 0; i < testCases.size(); ++i) {
        int got = solution.mySqrt(testCases[i].x);

        const string label = "Sqrt(x) 69 Test " + to_string(i + 1);
        REQUIRE_ASSERT(assertEqScalar(label, testCases[i].expected, got));
    }

    return true;
}

bool validPerfectSquare_367_tests() {
    vector<ValidPerfectSquareTestCase> cases = {
        {16,          true},    // example 1
        {14,          false},   // example 2
        {2147395600,  true},    // 46340² – largest 32-bit square
        {2147483647,  false},   // INT_MAX – not a square
        {808201,      true}     // 899² – non-trivial perfect square
    };

    ValidPerfectSquare_367 solver;

    for (size_t i = 0; i < cases.size(); ++i) {
        bool got = solver.isPerfectSquare(cases[i].num);

        const string label = "Valid Perfect Square 367 Test " + to_string(i + 1);
        REQUIRE_ASSERT(assertEqScalar(label, cases[i].expected, got));
    }

    return true;
}

bool kokoEatingBananas_875_tests() {
    vector<KokoEatingBananasTestCase> testCases = {
        // LeetCode examples
        {{3, 6, 7, 11}, 8, 4},              // Example 1
        {{30, 11, 23, 4, 20}, 5, 30},       // Example 2
        {{30, 11, 23, 4, 20}, 6, 23},       // Example 3

        // Single pile, enough hours to go slow
        {{5}, 10, 1},                        // can eat 1 banana/hour

        // Single pile, tighter time
        {{5}, 5, 1},                         // exactly 1 banana/hour
        {{5}, 4, 2},                         // needs speed 2

        // Multiple small piles
        {{1, 1, 1, 1}, 4, 1},                // min k = 1, since 4 piles of 1 banana each take 4 hours
    };

    KokoEatingBananas_875 solution;

    for (size_t i = 0; i < testCases.size(); ++i) {
        int got = solution.minEatingSpeed(testCases[i].piles, testCases[i].h);

        const string label = "Koko Eating Bananas 875 Test " + to_string(i + 1);
        REQUIRE_ASSERT(assertEqScalar(label, testCases[i].expected, got));
    }

    return true;
}

/* Binary search on matrix and rotated-array structure */

bool search2DMatrix_74_tests() {
    vector<Search2DMatrixTestCase> testCases = {
        // Provided examples
        {{{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}}, 3, true},
        {{{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}}, 13, false},

        // Additional complex test cases
        {{{1, 5, 9}, {14, 20, 23}, {30, 34, 50}}, 20, true},
        {{{1, 3, 6, 10}, {15, 20, 25, 30}, {35, 40, 45, 50}}, 7, false},
        {{{5, 7, 9, 11}, {13, 15, 17, 19}, {21, 23, 25, 27}}, 27, true},
    };

    Search2DMatrix_74 solution;

    for (size_t i = 0; i < testCases.size(); ++i) {
        bool got = solution.searchMatrix(testCases[i].matrix, testCases[i].target);

        const string label = "Search 2D Matrix Test " + to_string(i + 1);
        REQUIRE_ASSERT(assertEqScalar(label, testCases[i].expected, got));
    }

    return true;
}

bool findMinimumInRotatedSortedArray_153_tests() {
    vector<FindMinimumInRotatedSortedArrayTestCase> testCases = {
        {{3, 4, 5, 1, 2}, 1},                     // Example 1
        {{4, 5, 6, 7, 0, 1, 2}, 0},               // Example 2
        {{11, 13, 15, 17}, 11},                   // Example 3
        {{5, 6, 7, 8, 9, 1, 2, 3, 4}, 1},         // Additional Test 1
        {{30, 40, 50, 5, 10, 20}, 5}              // Additional Test 2
    };

    FindMinimumInRotatedSortedArray_153 solution;

    for (size_t i = 0; i < testCases.size(); ++i) {
        int got = solution.findMin(testCases[i].nums);

        const string label = "Find Min Rotated Array 153 Test " + to_string(i + 1);
        REQUIRE_ASSERT(assertEqScalar(label, testCases[i].expected, got));
    }

    return true;
}

bool searchInRotatedSortedArray_33_tests() {
    vector<BinarySearchTestCase> testCases = {
        // Problem statement examples
        {{4, 5, 6, 7, 0, 1, 2}, 0, 4},   // Example 1
        {{4, 5, 6, 7, 0, 1, 2}, 3, -1},  // Example 2
        {{1},                     0, -1}, // Example 3

        // Additional: no rotation, target present
        {{1, 2, 3, 4, 5, 6, 7}, 4, 3},

        // Additional: no rotation, target absent
        {{1, 2, 3, 4, 5, 6, 7}, 8, -1},

        // Additional: rotation in the middle, target in left sorted half
        {{6, 7, 0, 1, 2, 3, 4, 5}, 7, 1},

        // Additional: rotation in the middle, target in right sorted half
        {{6, 7, 0, 1, 2, 3, 4, 5}, 3, 5},

        // Additional: two-element arrays
        {{2, 1}, 1, 1},
        {{2, 1}, 2, 0},
        {{2, 1}, 3, -1}
    };

    SearchInRotatedSortedArray_33 solution;

    for (size_t i = 0; i < testCases.size(); ++i) {
        int got = solution.search(testCases[i].nums, testCases[i].target);

        const string label = "Search Rotated Sorted Array 33 Test " + to_string(i + 1);
        REQUIRE_ASSERT(assertEqScalar(label, testCases[i].expected, got));
    }

    return true;
}

} // namespace

namespace TestsBinarySearch {

std::vector<TestRegistry::Entry> getTests() {
    return {
        // Basic binary search on sorted arrays and monotonic positions
        TEST(704, "Binary Search",                        binarySearch_704_tests),
        TEST(35,  "Search Insert Position",               searchInsertPosition_35_tests),
        TEST(278, "First Bad Version",                    firstBadVersion_278_tests),

        // Binary search over a numeric answer space
        TEST(69,  "Sqrt(x)",                              sqrtX_69_tests),
        TEST(367, "Valid Perfect Square",                 validPerfectSquare_367_tests),
        TEST(875, "Koko Eating Bananas",                  kokoEatingBananas_875_tests),

        // Binary search on matrix and rotated-array structure
        TEST(74,  "Search a 2D Matrix",                   search2DMatrix_74_tests),
        TEST(153, "Find Minimum in Rotated Sorted Array", findMinimumInRotatedSortedArray_153_tests),
        TEST(33,  "Search in Rotated Sorted Array",       searchInRotatedSortedArray_33_tests),
    };
}

} // namespace TestsBinarySearch
