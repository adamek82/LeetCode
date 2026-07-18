#include "TestsDynamicProgramming.h"

#include <string>
#include <vector>

#include "TestCases.h"
#include "TestUtils.h"

#include "FibonacciNumber_509.h"
#include "ClimbingStairs_70.h"
#include "MinCostClimbingStairs_746.h"
#include "HouseRobber_198.h"
#include "CoinChange_322.h"
#include "PerfectSquares_279.h"
#include "UniquePaths_62.h"
#include "UniquePathsII_63.h"
#include "WildcardMatching_44.h"
#include "LongestCommonSubsequence_1143.h"
#include "LongestIncreasingSubsequence_300.h"
#include "MaximumSubarray_53.h"
#include "JumpGame_55.h"
#include "JumpGameII_45.h"

using namespace std;
using namespace TestCases;
using namespace TestUtils;

namespace {

/* Introductory 1D DP with direct state transitions */

static bool fibonacci_509_tests() {
    vector<FibonacciNumberTestCase> tests = {
        // 3 from the statement
        {2, 1},
        {3, 2},
        {4, 3},

        // Edge cases and a larger value
        {0, 0},
        {1, 1},
        {30, 832040},
    };

    FibonacciNumber_509 sol;

    for (size_t i = 0; i < tests.size(); ++i) {
        const auto& tc = tests[i];

        int got = sol.fib(tc.n);

        const string label =
            "Fibonacci 509 Test " + to_string(i + 1) +
            " (n=" + to_string(tc.n) + ")";
        REQUIRE_ASSERT(assertEqScalar(label, tc.expected, got));
    }

    return true;
}

static bool climbingStairs_70_tests() {
    vector<ClimbingStairsTestCase> tests = {
        // 2 from the statement
        {2, 2},
        {3, 3},

        // Edge cases and larger values
        {1, 1},
        {4, 5},
        {10, 89},
        {45, 1836311903},
    };

    ClimbingStairs_70 sol;

    for (size_t i = 0; i < tests.size(); ++i) {
        const auto& tc = tests[i];

        int got = sol.climbStairs(tc.n);

        const string label =
            "Climbing Stairs 70 Test " + to_string(i + 1) +
            " (n=" + to_string(tc.n) + ")";
        REQUIRE_ASSERT(assertEqScalar(label, tc.expected, got));
    }

    return true;
}

static bool minCostClimbingStairs_746_tests() {
    vector<MinCostClimbingStairsTestCase> tests = {
        // 2 from the statement
        {{10, 15, 20}, 15},
        {{1, 100, 1, 1, 1, 100, 1, 1, 100, 1}, 6},

        // Edge cases and patterned inputs
        {{5, 6}, 5},                          // n=2, pick cheaper start
        {{0, 0, 0, 0}, 0},                    // all zeros
        {{2, 2, 2, 2, 2}, 4},                 // uniform costs
        {{999, 1, 999, 1, 999, 1, 999, 1}, 4}, // pick all the 1s
    };

    MinCostClimbingStairs_746 sol;

    for (size_t i = 0; i < tests.size(); ++i) {
        const auto& tc = tests[i];

        int got = sol.minCostClimbingStairs(tc.cost);

        const string label = "Min Cost Climbing Stairs 746 Test " + to_string(i + 1);
        REQUIRE_ASSERT(assertEqScalar(label, tc.expected, got));
    }

    return true;
}

/* Linear DP on arrays with local recurrence choices */

static bool houseRobber_198_tests() {
    vector<HouseRobberTestCase> tests = {
        // 2 from the statement
        {{1, 2, 3, 1}, 4},
        {{2, 7, 9, 3, 1}, 12},

        // Edge cases and patterned inputs
        {{2, 1, 1, 2}, 4},           // choose 2 + 2
        {{0, 0, 0, 0, 0}, 0},        // all zeros
        {{6, 6, 4, 8, 4, 3, 3, 10}, 27},
        {{100}, 100},                // single element
    };

    HouseRobber_198 sol;

    for (size_t i = 0; i < tests.size(); ++i) {
        const auto& tc = tests[i];

        int got = sol.rob(tc.nums);

        const string label = "House Robber 198 Test " + to_string(i + 1);
        REQUIRE_ASSERT(assertEqScalar(label, tc.expected, got));
    }

    return true;
}

static bool maximumSubarray_53_tests() {
    vector<MaximumSubarrayTestCase> tests = {
        // 3 canonical LeetCode examples
        {{-2, 1, -3, 4, -1, 2, 1, -5, 4}, 6},
        {{1}, 1},
        {{5, 4, -1, 7, 8}, 23},

        // All-negative array -> pick the single largest element
        {{-8, -3, -6, -2, -5, -4}, -2},

        // Larger mixed array: answer is 25 from [10, -2, 3, 14]
        {{-1, 10, -2, 3, 14, -5, 2}, 25},
    };

    MaximumSubarray_53 solver;

    for (size_t i = 0; i < tests.size(); ++i) {
        const auto& tc = tests[i];

        int got = solver.maxSubArray(tc.nums);

        const string label = "Maximum Subarray 53 Test " + to_string(i + 1);
        REQUIRE_ASSERT(assertEqScalar(label, tc.expected, got));
    }

    return true;
}

/* Reachability and minimum-jump style DP / greedy-DP crossover */

static bool jumpGame_55_tests() {
    vector<JumpGameTestCase> tests = {
        {{2, 3, 1, 1, 4}, true},   // example 1
        {{3, 2, 1, 0, 4}, false},  // example 2
        {{0}, true},               // single element is trivially reachable
        {{1}, true},
        {{1, 0, 1}, false},        // stuck at index 1
        {{2, 0}, true},            // one jump to end
        {{2, 0, 0}, true},         // reach=2 at i=0 covers the end
        {{1, 1, 0, 1}, false},     // stuck at index 2
        {{5, 0, 0, 0, 0}, true},   // first jump covers all
        {{2, 5, 0, 0}, true},      // reach grows via index 1
        {{2, 0, 2, 0, 1}, true},   // detours but reachable
        {{2, 0, 1, 0, 0}, false},  // reach stalls before the end
    };

    JumpGame_55 sol;

    for (size_t i = 0; i < tests.size(); ++i) {
        const auto& tc = tests[i];

        auto nums = tc.nums; // solver takes non-const ref
        bool got = sol.canJump(nums);

        const string label = "Jump Game 55 Test " + to_string(i + 1);
        REQUIRE_ASSERT(assertEqScalar(label, tc.expected, got));
    }

    return true;
}

static bool jumpGameII_45_tests() {
    vector<JumpGameIITestCase> tests = {
        {{2, 3, 1, 1, 4}, 2},                // example 1
        {{2, 3, 0, 1, 4}, 2},                // example 2
        {{0}, 0},                            // single element
        {{1}, 0},                            // single element
        {{1, 1, 1, 1}, 3},                   // need to hop each step
        {{5, 0, 0, 0, 0}, 1},                // one jump covers all
        {{1, 4, 1, 1, 1, 1}, 2},             // to index 1, then to end
        {{3, 2, 1}, 1},                      // first jump reaches the end
        {{9, 8, 7, 6, 5, 4, 3, 2, 1, 0}, 1}, // giant first jump
    };

    JumpGameII_45 sol;

    for (size_t i = 0; i < tests.size(); ++i) {
        const auto& tc = tests[i];

        auto nums = tc.nums; // solver takes non-const ref
        int got = sol.jump(nums);

        const string label = "Jump Game II 45 Test " + to_string(i + 1);
        REQUIRE_ASSERT(assertEqScalar(label, tc.expected, got));
    }

    return true;
}

/* Grid DP with path counting and blocked cells */

static bool uniquePaths_62_tests() {
    vector<UniquePathsTestCase> cases = {
        // Official cases from the problem statement
        {3, 7, 28},
        {3, 2, 3},
        {1, 1, 1},

        // Larger cases, still <= 2,000,000,000
        {12, 23, 193536720},
        {8, 69, 1984829850},
    };

    UniquePaths_62 solver;

    for (size_t i = 0; i < cases.size(); ++i) {
        const auto& tc = cases[i];

        const string base =
            "Unique Paths 62 Test " + to_string(i + 1) +
            " (m=" + to_string(tc.m) + ", n=" + to_string(tc.n) + ")";

        int gotComb = solver.uniquePaths_Comb(tc.m, tc.n);
        int gotDP2D = solver.uniquePaths_DP2D(tc.m, tc.n);
        int gotDP2Rows = solver.uniquePaths_DP2Rows(tc.m, tc.n);

        REQUIRE_ASSERT(assertEqScalar(base + " [comb]", tc.expected, gotComb));
        REQUIRE_ASSERT(assertEqScalar(base + " [dp-2D]", tc.expected, gotDP2D));
        REQUIRE_ASSERT(assertEqScalar(base + " [dp-2rows]", tc.expected, gotDP2Rows));
    }

    return true;
}

static bool uniquePathsII_63_tests() {
    vector<UniquePathsIITestCase> testCases = {
        // From the problem statement
        {{{0, 0, 0}, {0, 1, 0}, {0, 0, 0}}, 2},
        {{{0, 1}, {0, 0}}, 1},

        // Single row with an obstacle blocking all paths past it
        {{{0, 1, 0, 0, 0}}, 0},

        // 3x3 with no obstacles: C(4,2)=6
        {{{0, 0, 0}, {0, 0, 0}, {0, 0, 0}}, 6},

        // 10x10 with no obstacles: C(18,9)=48620
        {
            vector<vector<int>>(10, vector<int>(10, 0)),
            48620,
        },
    };

    UniquePathsII_63 sol;

    for (size_t i = 0; i < testCases.size(); ++i) {
        const auto& tc = testCases[i];

        auto grid = tc.grid; // solver may mutate
        int got = sol.uniquePathsWithObstacles(grid);

        const string label = "Unique Paths II 63 Test " + to_string(i + 1);
        REQUIRE_ASSERT(assertEqScalar(label, tc.expected, got));
    }

    return true;
}

/* Unbounded-choice and counting / minimization DP */

static bool coinChange_322_tests() {
    vector<CoinChangeTestCase> testCases = {
        // 3 examples from the problem statement
        {{1, 2, 5}, 11, 3},
        {{2}, 3, -1},
        {{1}, 0, 0},

        // 8 denominations, amount >= 30
        {{1, 3, 4, 5, 10, 20, 50, 100}, 99, 5},

        // 8 prime-value coins, larger amount
        {{2, 3, 5, 7, 11, 13, 17, 19}, 100, 6},
    };

    CoinChange_322 sol;

    for (size_t i = 0; i < testCases.size(); ++i) {
        const auto& tc = testCases[i];

        auto coins = tc.coins; // solver may mutate
        int got = sol.coinChange(coins, tc.amount);

        const string label =
            "Coin Change 322 Test " + to_string(i + 1) +
            " (amount=" + to_string(tc.amount) + ")";
        REQUIRE_ASSERT(assertEqScalar(label, tc.expected, got));
    }

    return true;
}

static bool perfectSquares_279_tests() {
    vector<PerfectSquaresTestCase> testCases = {
        // 2 examples from the problem statement
        {12, 3}, // 12 = 4 + 4 + 4
        {13, 2}, // 13 = 9 + 4

        // Larger and edge cases
        {3000, 3},
        {9991, 4},  // Legendre form 4^a(8b+7), so 4 squares are needed
        {10000, 1}, // 10000 = 100^2
    };

    PerfectSquares_279 solver;

    for (size_t i = 0; i < testCases.size(); ++i) {
        const auto& tc = testCases[i];

        int got = solver.numSquares(tc.n);

        const string label =
            "Perfect Squares 279 Test " + to_string(i + 1) +
            " (n=" + to_string(tc.n) + ")";
        REQUIRE_ASSERT(assertEqScalar(label, tc.expected, got));
    }

    return true;
}

/* Sequence DP on increasing structure and string matching */

static bool longestIncreasingSubsequence_300_tests() {
    vector<LongestIncreasingSubsequenceTestCase> testCases = {
        // Provided examples
        {{10, 9, 2, 5, 3, 7, 101, 18}, 4},
        {{0, 1, 0, 3, 2, 3}, 4},
        {{7, 7, 7, 7, 7, 7, 7}, 1},

        // Larger mixed cases
        {{3, 10, 2, 1, 20, 4, 6, 21, 22, 23}, 6},
        {{9, 2, 5, 3, 7, 101, 18, 9, 4, 5, 6, 7, 8}, 7},
    };

    LongestIncreasingSubsequence_300 solver;

    for (size_t i = 0; i < testCases.size(); ++i) {
        const auto& tc = testCases[i];
        const string base = "LIS 300 Test " + to_string(i + 1);

        auto tailsInput = tc.nums; // tails version takes non-const ref
        int tailsLen = solver.lengthOfLIS_tails(tailsInput);
        int dpLen = solver.lengthOfLIS_dp(tc.nums);

        REQUIRE_ASSERT(assertEqScalar(base + " [tails length]", tc.expected, tailsLen));
        REQUIRE_ASSERT(assertEqScalar(base + " [dp length]", tc.expected, dpLen));
        REQUIRE_ASSERT(assertEqScalar(base + " [length consistency]", tailsLen, dpLen));

        vector<int> tailsSeq = solver.getLIS_tails(tc.nums);
        vector<int> dpSeq = solver.getLIS_dp(tc.nums);

        REQUIRE_ASSERT(assertEqScalar(
            base + " [tails seq size]",
            tc.expected,
            static_cast<int>(tailsSeq.size())));
        REQUIRE_ASSERT(assertEqScalar(
            base + " [dp seq size]",
            tc.expected,
            static_cast<int>(dpSeq.size())));

        REQUIRE_ASSERT(assertEqScalar(
            base + " [tails seq increasing]",
            true,
            isStrictlyIncreasing(tailsSeq)));
        REQUIRE_ASSERT(assertEqScalar(
            base + " [dp seq increasing]",
            true,
            isStrictlyIncreasing(dpSeq)));

        REQUIRE_ASSERT(assertEqScalar(
            base + " [tails seq subsequence]",
            true,
            isSubsequence(tailsSeq, tc.nums)));
        REQUIRE_ASSERT(assertEqScalar(
            base + " [dp seq subsequence]",
            true,
            isSubsequence(dpSeq, tc.nums)));

        REQUIRE_ASSERT(assertEqScalar(
            base + " [tails seq matches tails length]",
            tailsLen,
            static_cast<int>(tailsSeq.size())));
        REQUIRE_ASSERT(assertEqScalar(
            base + " [dp seq matches dp length]",
            dpLen,
            static_cast<int>(dpSeq.size())));

        REQUIRE_ASSERT(assertEqScalar(
            base + " [seq length consistency]",
            tailsSeq.size(),
            dpSeq.size()));
    }

    return true;
}

static bool longestCommonSubsequence_1143_tests() {
    vector<LongestCommonSubsequenceTestCase> testCases = {
        // Provided examples
        {"abcde", "ace", 3},
        {"abc", "abc", 3},
        {"abc", "def", 0},

        // Larger cases
        {"abcdefghijabcdefghij", "acegikacegik", 10},
        {"abcdefghijklmnopqrst", "zyxwvutsrqponmlkjih", 1},
    };

    LongestCommonSubsequence_1143 sol;

    for (size_t i = 0; i < testCases.size(); ++i) {
        const auto& tc = testCases[i];
        const string base = "LCS 1143 Test " + to_string(i + 1);

        int fullDP = sol.longestCommonSubsequence(tc.text1, tc.text2);
        int twoRows = sol.longestCommonSubsequenceTwoRows(tc.text1, tc.text2);

        REQUIRE_ASSERT(assertEqScalar(base + " [full DP]", tc.expected, fullDP));
        REQUIRE_ASSERT(assertEqScalar(base + " [2 rows]", tc.expected, twoRows));
        REQUIRE_ASSERT(assertEqScalar(base + " [length consistency]", fullDP, twoRows));

        string lcs = sol.longestCommonSubsequenceString(tc.text1, tc.text2);

        REQUIRE_ASSERT(assertEqScalar(
            base + " [string length]",
            tc.expected,
            static_cast<int>(lcs.size())));
        REQUIRE_ASSERT(assertEqScalar(
            base + " [string subseq text1]",
            true,
            isSubsequenceStr(lcs, tc.text1)));
        REQUIRE_ASSERT(assertEqScalar(
            base + " [string subseq text2]",
            true,
            isSubsequenceStr(lcs, tc.text2)));
    }

    return true;
}

static bool wildcardMatching_44_tests() {
    vector<WildcardMatchingTestCase> tests = {
        // Three examples from the statement
        {"aa", "a", false},
        {"aa", "*", true},
        {"cb", "?a", false},

        // Extra harder cases
        {"adceb", "*a*b", true},
        {"acdcb", "a*c?b", false},
        {"abcabczzzde", "*abc???de*", true},
        {"baaaacxyz", "*a*?xyz", true},
        {"abcded", "a*d", true},
        {"abcdbcde", "a*de", true},
    };

    WildcardMatching_44 solver;

    for (size_t i = 0; i < tests.size(); ++i) {
        const auto& tc = tests[i];

        bool got = solver.isMatch(tc.s, tc.p);

        const string label =
            "Wildcard Matching 44 Test " + to_string(i + 1) +
            " (pattern=\"" + tc.p + "\")";
        REQUIRE_ASSERT(assertEqScalar(label, tc.expected, got));
    }

    return true;
}

} // namespace

namespace TestsDynamicProgramming {

std::vector<TestRegistry::Entry> getTests() {
    return {
        // Introductory 1D DP with direct state transitions
        TEST(509,  "Fibonacci Number",                         fibonacci_509_tests),
        TEST(70,   "Climbing Stairs",                          climbingStairs_70_tests),
        TEST(746,  "Min Cost Climbing Stairs",                 minCostClimbingStairs_746_tests),
        TEST(198,  "House Robber",                             houseRobber_198_tests),

        // Unbounded-choice DP / coin-style recurrence problems
        TEST(322,  "Coin Change",                              coinChange_322_tests),
        TEST(279,  "Perfect Squares",                          perfectSquares_279_tests),

        // Grid DP with path-counting recurrences
        TEST(62,   "Unique Paths",                             uniquePaths_62_tests),
        TEST(63,   "Unique Paths II",                          uniquePathsII_63_tests),

        // String / sequence DP
        TEST(44,   "Wildcard Matching",                        wildcardMatching_44_tests),
        TEST(1143, "Longest Common Subsequence",               longestCommonSubsequence_1143_tests),
        TEST(300,  "Longest Increasing Subsequence",           longestIncreasingSubsequence_300_tests),

        // Optimization-style DP / greedy-DP boundary cases
        TEST(53,   "Maximum Subarray",                         maximumSubarray_53_tests),
        TEST(55,   "Jump Game",                                jumpGame_55_tests),
        TEST(45,   "Jump Game II",                             jumpGameII_45_tests),
    };
}

} // namespace TestsDynamicProgramming
