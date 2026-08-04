#pragma once

#include <string>
#include <vector>

#include "tests/framework/TestCaseTypes.h"

namespace TestCases {

// 509. Fibonacci Number
struct FibonacciNumberTestCase { int n; int expected; };

// 70. Climbing Stairs
struct ClimbingStairsTestCase { int n; int expected; };

// 746. Min Cost Climbing Stairs
struct MinCostClimbingStairsTestCase { std::vector<int> cost; int expected; };

// 198. House Robber
struct HouseRobberTestCase { std::vector<int> nums; int expected; };

// 53. Maximum Subarray
struct MaximumSubarrayTestCase { std::vector<int> nums; int expected; };

// 55. Jump Game
struct JumpGameTestCase { std::vector<int> nums; bool expected; };

// 45. Jump Game II
struct JumpGameIITestCase { std::vector<int> nums; int expected; };

// 62. Unique Paths
struct UniquePathsTestCase { int m; int n; int expected; };

// 63. Unique Paths II
struct UniquePathsIITestCase { std::vector<std::vector<int>> grid; int expected; };

// 322. Coin Change
struct CoinChangeTestCase { std::vector<int> coins; int amount; int expected; };

// 279. Perfect Squares
struct PerfectSquaresTestCase { int n; int expected; };

// 300. Longest Increasing Subsequence
struct LongestIncreasingSubsequenceTestCase { List nums; int expected; };

// 1143. Longest Common Subsequence
struct LongestCommonSubsequenceTestCase { std::string text1; std::string text2; int expected; };

// 44. Wildcard Matching
struct WildcardMatchingTestCase { std::string s; std::string p; bool expected; };

} // namespace TestCases
