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
#include "CourseSchedule_207.h"
#include "FindIfPathExistsInGraph_1971.h"
#include "NumberOfIslands_200.h"
#include "MaxAreaOfIsland_695.h"
#include "CourseScheduleII_210.h"
#include "NetworkDelayTime_743.h"
#include "RottingOranges_994.h"
#include "PacificAtlanticWaterFlow_417.h"
#include "MinCostToConnectAllPoints_1584.h"
#include "LongestCommonSubsequence_1143.h"
#include "LongestIncreasingSubsequence_300.h"
#include "ListUtils.h"
#include "TreeUtils.h"
#include "GraphUtils.h"
#include "RemoveDuplicatesFromSortedList_83.h"
#include "ReverseLinkedList_206.h"
#include "MergeTwoSortedLists_21.h"
#include "LinkedListCycle_141.h"
#include "MiddleOfLinkedList_876.h"
#include "RemoveNthNodeFromEndOfList_19.h"
#include "BestTimeToBuyAndSellStock_121.h"
#include "SpiralMatrix_54.h"
#include "ValidateBinarySearchTree_98.h"
#include "LowestCommonAncestorOfBST_235.h"
#include "CopyListWithRandomPointer_138.h"
#include "KthSmallestElementInBST_230.h"
#include "Trie.h"
#include "KthLargestElementInArray_215.h"
#include "MinHeap.h"
#include "RotateImage_48.h"
#include "MergeIntervals_56.h"
#include "MergeKSortedLists_23.h"
#include "ProductOfArrayExceptSelf.h"
#include "MajorityElement_169.h"
#include "EvaluateReversePolishNotation_150.h"
#include "LargestRectangleInHistogram_84.h"
#include "WordSearch_79.h"
#include "ValidParentheses_20.h"
#include "ValidSudoku_36.h"
#include "BinarySearch_704.h"
#include "SearchInsertPosition_35.h"
#include "Search2DMatrix_74.h"
#include "AllOOneDataStructure_432.h"
#include "FindMinimumInRotatedSortedArray_153.h"
#include "GraphNode.h"
#include "CloneGraph_133.h"
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
#include "LRUCache_146.h"
#include "SortCharactersByFrequency_451.h"
#include "CoinChange_322.h"
#include "TopKFrequentWords_692.h"
#include "LongestCycleInGraph_2360.h"
#include "ShortestCycleInGraph_2608.h"
#include "UniquePathsII_63.h"
#include "MaximumAverageSubarrayI_643.h"
#include "MaxConsecutiveOnesIII_1004.h"
#include "LongestSubstringWithoutRepeatingCharacters_3.h"
#include "MinimumSizeSubarraySum_209.h"
#include "PermutationInString_567.h"
#include "SquaresOfSortedArray_977.h"
#include "ReverseString_344.h"
#include "TwoSumII_167.h"
#include "ValidPalindrome_125.h"
#include "ThreeSum_15.h"
#include "ContainerWithMostWater_11.h"
#include "TrappingRainWater_42.h"
#include "MaximalRectangle_85.h"
#include "MaximumSubarray_53.h"
#include "TwoSum_1.h"
#include "MergeSortedArray_88.h"
#include "RemoveElement_27.h"
#include "MaximumNumberOfBalloons_1189.h"
#include "AddBinary_67.h"
#include "FindPivotIndex_724.h"
#include "NumberOf1Bits_191.h"
#include "DecodeString_GoogleOnsite.h"
#include "WildcardMatching_44.h"
#include "KClosestPointsToOrigin_973.h"
#include "UniquePaths_62.h"
#include "BusRoutes_815.h"
#include "ShortestPathInBinaryMatrix_1091.h"
#include "DesignGraphWithShortestPathCalculator_2642.h"
#include "FindSafestPathInGrid_2812.h"
#include "MaximumDepthOfBinaryTree_104.h"
#include "WallsAndGates_286.h"
#include "ValidNumber_65.h"
#include "JewelsAndStones_771.h"
#include "ValidPerfectSquare_367.h"
#include "PerfectSquares_279.h"
#include "SameTree_100.h"
#include "MissingNumber_268.h"
#include "DailyTemperatures_739.h"
#include "ContainsDuplicate_217.h"
#include "FibonacciNumber_509.h"
#include "ClimbingStairs_70.h"
#include "MinCostClimbingStairs_746.h"
#include "HouseRobber_198.h"
#include "LastStoneWeight_1046.h"
#include "TopKFrequentElements_347.h"
#include "FindClosestNumberToZero_2239.h"
#include "MergeStringsAlternately_1768.h"
#include "RomanToInteger_13.h"
#include "IsSubsequence_392.h"
#include "LongestCommonPrefix_14.h"
#include "SummaryRanges_228.h"
#include "RemoveDuplicates_26.h"
#include "JumpGameII_45.h"
#include "JumpGame_55.h"
#include "Subsets_78.h"
#include "Permutations_46.h"
#include "Combinations_77.h"
#include "LetterCombinations_17.h"
#include "CombinationSum_39.h"
#include "GenerateParentheses_22.h"
#include "ExamRoom_855.h"
#include "GameOfLife_289.h"
#include "LongestIncreasingPathInMatrix_329.h"
#include "MinStack_155.h"
#include "BaseballGame_682.h"

using namespace std;
using namespace TestUtils;
using namespace TestCases;

// --- Unified test registry ---------------------------------------------------
// Each entry binds: LeetCode id (0 if custom), human title, and the static test fn.
struct TestEntry {
    int id;                    // 0 for custom/non-LeetCode
    const char* title;         // human-readable
    void (*fn)();              // pointer to static test function
};

// Helper to keep the table compact.
#define TEST(ID, TITLE, FN) TestEntry{ (ID), (TITLE), &FN }

class TestsRunner {
public:
    static void courseSchedule_207_tests() {
        vector<ScheduleTestCase> testCases = {
            {2, {{1, 0}}, true},
            {2, {{1, 0}, {0, 1}}, false},
            {5, {{0, 1}, {2, 3}, {3, 4}, {2, 1}}, true},
            {5, {{0, 1}, {2, 3}, {3, 4}, {2, 1}, {4, 2}}, false},
        };

        CourseSchedule_207 cs207;

        const vector<pair<string, function<bool(const ScheduleTestCase&)>>> impls = {
            {"DFS",  [&](const ScheduleTestCase& tc){ return cs207.canFinishDFS(tc.numCourses, tc.prerequisites); }},
            {"Kahn", [&](const ScheduleTestCase& tc){ return cs207.canFinishKahns(tc.numCourses, tc.prerequisites); }},
        };

        for (size_t i = 0; i < testCases.size(); ++i) {
            const auto& tc = testCases[i];
            for (const auto& [name, run] : impls) {
                assertEqScalar("Course Schedule 207 [" + name + "] " + to_string(i + 1), tc.expected, run(tc));
            }
        }
    }

    static void findIfPathExistsInGraph_1971_tests() {
        vector<PathTestCase> testCases = {
            {3, {{0, 1}, {1, 2}, {2, 0}}, 0, 2, true},
            {6, {{0, 1}, {0, 2}, {3, 5}, {5, 4}, {4, 3}}, 0, 5, false},
            {4, {{0, 1}, {1, 2}, {2, 3}}, 0, 3, true},
            {5, {{0, 4}, {4, 3}, {3, 2}, {2, 1}}, 0, 1, true},
            {4, {{0, 1}, {1, 2}}, 0, 3, false},
        };

        FindIfPathExistsInGraph_1971 fp1971;

        const vector<pair<string, function<bool(const PathTestCase&)>>> impls = {
            {"DFS-rec", [&](const PathTestCase& tc){
                return fp1971.validPathRecursiveDFS(tc.n, tc.edges, tc.source, tc.destination);
            }},
            {"DFS-iter", [&](const PathTestCase& tc){
                return fp1971.validPathIterativeDFS(tc.n, tc.edges, tc.source, tc.destination);
            }},
            {"BFS", [&](const PathTestCase& tc){
                return fp1971.validPathBFS(tc.n, tc.edges, tc.source, tc.destination);
            }},
            {"UnionFind", [&](const PathTestCase& tc){
                return fp1971.validPathUnionFind(tc.n, tc.edges, tc.source, tc.destination);
            }},
        };

        for (size_t i = 0; i < testCases.size(); ++i) {
            const auto& tc = testCases[i];
            for (const auto& [name, run] : impls) {
                assertEqScalar("Find Path 1971 [" + name + "] " + to_string(i + 1),
                            tc.expected, run(tc));
            }
        }
    }

    static void numIslands_200_tests()
    {
        // Define test cases
        vector<NumIslandsTestCase> testCases = {
            {{{'1', '1', '1', '1', '0'},
              {'1', '1', '0', '1', '0'},
              {'1', '1', '0', '0', '0'},
              {'0', '0', '0', '0', '0'}},
             1},

            {{{'1', '1', '0', '0', '0'},
              {'1', '1', '0', '0', '0'},
              {'0', '0', '1', '0', '0'},
              {'0', '0', '0', '1', '1'}},
             3},

            // Additional test case 1
            {{{'1', '0', '0', '0', '1'},
              {'0', '1', '1', '1', '0'},
              {'0', '1', '0', '1', '0'},
              {'1', '0', '0', '0', '1'}},
             5}, // Expected output: 5 (each isolated "1" or group of "1"s is an island)

            // Additional test case 2
            {{{'1', '1', '1'},
              {'0', '1', '0'},
              {'1', '1', '1'}},
             1} // Expected output: 1 (entire grid is a single connected island)
        };

        NumberOfIslands_200 noi200;

        // Run test cases
        for (size_t i = 0; i < testCases.size(); i++)
        {
            int result = noi200.numIslands(testCases[i].grid);
            assertEqScalar("Test " + to_string(i + 1), testCases[i].expected, result);
        }
    }

    static void maxAreaOfIsland_695_tests() {
        vector<MaxAreaTestCase> testCases = {
            {{{0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
              {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
              {0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
              {0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 0, 0},
              {0, 1, 0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 0},
              {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
              {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
              {0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0}},
             6},

            {{{0, 0, 0, 0, 0, 0, 0, 0}}, 0}, // Expected output: 0 (no land)

            // Additional test case 1
            {{{1, 1, 0, 0, 1, 1},
              {1, 0, 0, 0, 1, 1},
              {0, 0, 1, 1, 1, 0},
              {0, 0, 1, 0, 1, 1}},
             10}, // Expected output: 10

            // Additional test case 2
            {{{0, 1, 1, 1},
              {1, 1, 0, 0},
              {1, 0, 0, 1},
              {1, 1, 1, 0}},
             9} // Expected output: 9
        };

        MaxAreaOfIsland_695 mai695;

        for (size_t i = 0; i < testCases.size(); i++) {
            // make independent copies because each routine mutates the grid
            auto gridRec  = testCases[i].grid;
            auto gridIter = testCases[i].grid;

            int resRec  = mai695.maxAreaOfIslandRecursive(gridRec);
            int resIter = mai695.maxAreaOfIslandIterative(gridIter);

            assertEqScalar("Max Area Test" + to_string(i + 1) + " (recursive)", testCases[i].expected, resRec);
            assertEqScalar("Max Area Test" + to_string(i + 1) + " (iterative)", testCases[i].expected, resIter);
        }
    }

    static void courseScheduleII_210_tests() {
        vector<CourseScheduleIITestCase> testCases = {
            // Example 1
            {2, {{1, 0}}, {0, 1}},
            // Example 2
            {4, {{1, 0}, {2, 0}, {3, 1}, {3, 2}}, {0, 1, 2, 3}},
            // Example 3
            {1, {}, {0}},
            // Additional Complex Test 1: A graph with two independent subgraphs
            {6, {{1, 0}, {2, 0}, {3, 4}, {5, 4}}, {0, 4, 1, 2, 3, 5}},
            // Additional Complex Test 2: A cycle detection case
            {5, {{0, 1}, {1, 2}, {2, 3}, {3, 4}, {4, 0}}, {}}
        };

        auto validTopo = [](int n, const vector<vector<int>>& pre, const vector<int>& order) {
            if (order.empty()) return pre.empty() ? n == 0 : false;        // empty only for cycle (or trivial n==0)
            if ((int)order.size() != n) return false;
            unordered_map<int,int> pos; pos.reserve(order.size());
            for (int i = 0; i < (int)order.size(); ++i) pos[order[i]] = i;
            for (const auto& e : pre) if (pos[e[1]] > pos[e[0]]) return false;
            return true;
        };

        CourseScheduleII_210 sol;
        for (size_t i = 0; i < testCases.size(); ++i) {
            const auto& tc = testCases[i];

            // DFS version (make a mutable copy for the non-const ref parameter)
            auto pre1 = tc.prerequisites;
            auto a    = sol.findOrderByDFSTraversal(tc.numCourses, pre1);
            bool okA  = tc.expectedOrder.empty() ? a.empty()
                                                : validTopo(tc.numCourses, tc.prerequisites, a);
            assertEqScalar("Course Schedule II 210 [DFS] Test " + to_string(i + 1), true, okA);

            // Kahn version (another mutable copy)
            auto pre2 = tc.prerequisites;
            auto b    = sol.findOrderByKahnsAlgorithm(tc.numCourses, pre2);
            bool okB  = tc.expectedOrder.empty() ? b.empty()
                                                : validTopo(tc.numCourses, tc.prerequisites, b);
            assertEqScalar("Course Schedule II 210 [Kahn] Test " + to_string(i + 1), true, okB);
        }
    }

    static void networkDelayTime_743_tests() {
        vector<NetworkDelayTimeTestCase> testCases = {
            // Provided Examples
            {{ {2, 1, 1}, {2, 3, 1}, {3, 4, 1} }, 4, 2, 2},
            {{ {1, 2, 1} }, 2, 1, 1},
            {{ {1, 2, 1} }, 2, 2, -1},

            // Additional Complex Example 1: 6 nodes, complex network
            {{ {1, 2, 2}, {1, 3, 4}, {2, 4, 7}, {3, 4, 1}, {2, 5, 5}, {5, 6, 3}, {4, 6, 2} }, 6, 1, 7},

            // Additional Complex Example 2: 8 nodes, complex network
            {{ {1, 2, 2}, {1, 3, 1}, {3, 4, 4}, {2, 5, 7}, {5, 6, 1}, {6, 7, 5}, {7, 8, 2}, {4, 8, 3} }, 8, 1, 15},
        };

        NetworkDelayTime_743 ndt743;

        for (size_t i = 0; i < testCases.size(); ++i) {
            int result = ndt743.networkDelayTime(testCases[i].times, testCases[i].n, testCases[i].k);
            assertEqScalar("Test " + to_string(i + 1), testCases[i].expected, result);
        }
    }

    static void rottingOranges_994_tests()
    {
        vector<RottingOrangesTestCase> testCases = {
            {{{2, 1, 1}, {1, 1, 0}, {0, 1, 1}}, 4},  // Example 1
            {{{2, 1, 1}, {0, 1, 1}, {1, 0, 1}}, -1}, // Example 2
            {{{0, 2}}, 0},                           // Example 3
            // Additional Test Case 1
            {{{2, 1, 1, 0, 0, 1, 2},
              {1, 0, 0, 0, 1, 1, 0},
              {0, 1, 2, 1, 0, 1, 0},
              {0, 1, 0, 2, 2, 1, 0}},
             3},
            // Additional Test Case 2
            {{{2, 2, 1, 1, 1, 0, 0},
              {0, 1, 1, 2, 1, 1, 0},
              {1, 1, 0, 1, 1, 2, 1},
              {2, 0, 0, 1, 1, 1, 1},
              {0, 0, 1, 1, 0, 0, 0}},
             4}};

        RottingOranges_994 solution;

        for (size_t i = 0; i < testCases.size(); ++i)
        {
            int result = solution.orangesRotting(testCases[i].grid);
            assertEqScalar("Test " + to_string(i + 1), testCases[i].expected, result);
        }
    }

    static void pacificAtlantic_417_tests()
    {
        vector<PacificAtlanticTestCase> testCases = {
            // Example 1
            {{{1, 2, 2, 3, 5},
              {3, 2, 3, 4, 4},
              {2, 4, 5, 3, 1},
              {6, 7, 1, 4, 5},
              {5, 1, 1, 2, 4}},
             {{0, 4}, {1, 3}, {1, 4}, {2, 2}, {3, 0}, {3, 1}, {4, 0}}},

            // Example 2
            {{{1}}, {{0, 0}}},

            // Additional Test Case 1
            {{{10, 10, 10},
              {10, 1, 10},
              {10, 10, 10}},
             {{0, 0}, {0, 1}, {0, 2}, {1, 0}, {1, 2}, {2, 0}, {2, 1}, {2, 2}}},

            // Additional Test Case 2
            {{{1, 2, 2, 3, 5},
              {3, 2, 3, 4, 4},
              {2, 4, 5, 6, 7},
              {6, 7, 8, 9, 10}},
             {{0, 4}, {1, 3}, {1, 4}, {2, 3}, {2, 4}, {3, 0}, {3, 1}, {3, 2}, {3, 3}, {3, 4}}},

            // Additional Test Case 3
            {{{5, 5, 5, 5, 5},
              {5, 1, 1, 1, 5},
              {5, 1, 1, 1, 5},
              {5, 1, 1, 1, 5},
              {5, 5, 5, 5, 5}},
             {{0, 0}, {0, 1}, {0, 2}, {0, 3}, {0, 4}, {1, 0}, {1, 4}, {2, 0}, {2, 4}, {3, 0}, {3, 4}, {4, 0}, {4, 1}, {4, 2}, {4, 3}, {4, 4}}}};

        PacificAtlanticWaterFlow_417 pacificAtlanticSolution;

        for (size_t i = 0; i < testCases.size(); ++i)
        {
            auto result = pacificAtlanticSolution.pacificAtlantic(testCases[i].heights);
            assertEqVVIntExact("Test " + to_string(i + 1), testCases[i].expected, result);
        }
    }

    static void minCostToConnectAllPoints_1584_tests() {
        vector<MinCostToConnectAllPointsTestCase> testCases = {
            // Provided examples
            {{{0, 0}, {2, 2}, {3, 10}, {5, 2}, {7, 0}}, 20},
            {{{3, 12}, {-2, 5}, {-4, 1}}, 18},

            // Additional complex examples
            {{{1, 1}, {3, 3}, {7, 7}, {10, 10}, {15, 15}}, 28}, // Sequential points
            {{{0, 0}, {1, 1}, {1, 0}, {0, 1}, {2, 2}}, 5}, // Compact grid
            {{{-100, -100}, {100, 100}, {-100, 100}, {100, -100}}, 600}, // Distant points
        };

        MinCostToConnectAllPoints_1584 solution;

        for (size_t i = 0; i < testCases.size(); ++i) {
            auto ptsHeap  = testCases[i].points;
            auto ptsArray = testCases[i].points;

            int resHeap  = solution.minCostConnectPointsHeap(testCases[i].points);
            int resArray = solution.minCostConnectPointsArray(testCases[i].points);

            assertEqScalar("Min Cost Test" + to_string(i + 1) + " (heap)", testCases[i].expected, resHeap);
            assertEqScalar("Min Cost Test" + to_string(i + 1) + " (array)", testCases[i].expected, resArray);
        }
    }

    static void longestCommonSubsequence_1143_tests() {
        vector<LongestCommonSubsequenceTestCase> testCases = {
            // Provided examples
            {"abcde", "ace", 3}, // Example 1
            {"abc", "abc", 3},   // Example 2
            {"abc", "def", 0},   // Example 3

            // Additional complex examples
            {"abcdefghijabcdefghij", "acegikacegik", 10}, // Alternating match
            {"abcdefghijklmnopqrst", "zyxwvutsrqponmlkjih", 1} // No common subsequence
        };

        LongestCommonSubsequence_1143 solution;

        LongestCommonSubsequence_1143 sol;
        for (size_t i = 0; i < testCases.size(); ++i) {
            int got = sol.longestCommonSubsequence(testCases[i].text1, testCases[i].text2);
            assertEqScalar("LCS 1143 Test " + to_string(i + 1), testCases[i].expected, got);
        }
    }

    static void longestIncreasingSubsequence_300_tests() {
        vector<LongestIncreasingSubsequenceTestCase> testCases = {
            // Provided examples
            {{10, 9, 2, 5, 3, 7, 101, 18}, 4}, // Example 1
            {{0, 1, 0, 3, 2, 3}, 4},           // Example 2
            {{7, 7, 7, 7, 7, 7, 7}, 1},        // Example 3

            // Additional complex examples
            {{3, 10, 2, 1, 20, 4, 6, 21, 22, 23}, 6}, // Example 4
            {{9, 2, 5, 3, 7, 101, 18, 9, 4, 5, 6, 7, 8}, 7} // Example 5
        };

        LongestIncreasingSubsequence_300 solution;

        for (size_t i = 0; i < testCases.size(); ++i) {
            // Run both implementations and check against expected, then cross-check equality.
            auto nums1 = testCases[i].nums;              // tails version takes non-const ref
            int got_tails = solution.lengthOfLIS_tails(nums1);
            int got_dp    = solution.lengthOfLIS_dp(testCases[i].nums);

            assertEqScalar("LIS 300 [tails]  Test " + to_string(i + 1), testCases[i].expected, got_tails);
            assertEqScalar("LIS 300 [dp]     Test " + to_string(i + 1), testCases[i].expected, got_dp);
            assertEqScalar("LIS 300 [agree]  Test " + to_string(i + 1), got_tails, got_dp);
        }
    }

    static void removeDuplicatesFromSortedList_83_tests() {
        using IntListNode = ListNode<int>;

        // Define test cases
        vector<RemoveDuplicatesTestCase> testCases = {
            // Provided examples
            {{1, 1, 2}, {1, 2}},
            {{1, 1, 2, 3, 3}, {1, 2, 3}},

            // Additional complex test cases
            {{1, 1, 1, 1, 1}, {1}},                         // Single value repeated many times
            {{1, 2, 2, 3, 3, 4, 4, 5, 5, 6}, {1, 2, 3, 4, 5, 6}}, // Alternating duplicates
            {{-10, -10, -5, 0, 0, 1, 1, 2, 2, 2, 100}, {-10, -5, 0, 1, 2, 100}}, // Mixed negative and positive numbers
        };

        RemoveDuplicatesFromSortedList_83 solution;

        for (size_t i = 0; i < testCases.size(); ++i) {
            IntListNode* input = ListUtils::createLinkedList<int>(testCases[i].input);
            IntListNode* result = solution.deleteDuplicates(input);
            vector<int> resultVector = ListUtils::toVector<int>(result);

            assertEqVIntExact("Test " + to_string(i + 1), testCases[i].expected, ListUtils::toVector<int>(result));

            ListUtils::freeList<int>(result);
        }
    }

    static void reverseLinkedList_206_tests() {
        using IntListNode = ListNode<int>;

        // Define test cases
        vector<ReverseListTestCase> testCases = {
            // Provided examples
            {{1, 2, 3, 4, 5}, {5, 4, 3, 2, 1}},
            {{1, 2}, {2, 1}},
            {{}, {}},

            // Additional complex test cases
            {{-5, -4, -3, -2, -1}, {-1, -2, -3, -4, -5}}, // Negative values
            {{10, 20, 30, 40, 50, 60}, {60, 50, 40, 30, 20, 10}} // Longer list
        };

        ReverseLinkedList_206 solution;

        for (size_t i = 0; i < testCases.size(); ++i) {
            IntListNode* input = ListUtils::createLinkedList<int>(testCases[i].input);
            IntListNode* result = solution.reverseList(input);
            vector<int> resultVector = ListUtils::toVector<int>(result);

            assertEqVIntExact("Test " + to_string(i + 1), testCases[i].expected, ListUtils::toVector<int>(result));

            ListUtils::freeList<int>(result);
        }
    }

    static void mergeTwoSortedLists_21_tests() {
        using IntListNode = ListNode<int>;

        // Define test cases
        vector<MergeTwoListsTestCase> testCases = {
            // Provided examples
            {{1, 2, 4}, {1, 3, 4}, {1, 1, 2, 3, 4, 4}},
            {{}, {}, {}},
            {{}, {0}, {0}},

            // Additional complex test cases
            {{-10, -5, 0, 3}, {-8, -6, 2, 4}, {-10, -8, -6, -5, 0, 2, 3, 4}},
            {{1, 3, 5, 7}, {2, 4, 6, 8, 10}, {1, 2, 3, 4, 5, 6, 7, 8, 10}}
        };

        MergeTwoSortedLists_21 solution;

        for (size_t i = 0; i < testCases.size(); ++i) {
            IntListNode* list1 = ListUtils::createLinkedList<int>(testCases[i].list1);
            IntListNode* list2 = ListUtils::createLinkedList<int>(testCases[i].list2);

            IntListNode* result = solution.mergeTwoLists(list1, list2);
            vector<int> resultVector = ListUtils::toVector<int>(result);

            assertEqVIntExact("Test " + to_string(i + 1), testCases[i].expected, ListUtils::toVector<int>(result));

            ListUtils::freeList<int>(result);
        }
    }

    static void hasCycle_141_tests() {
        vector<LinkedListCycleTestCase> testCases = {
            // Provided examples
            {{3, 2, 0, -4}, 1, true},
            {{1, 2}, 0, true},
            {{1}, -1, false},

            // Additional examples
            {{1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, 4, true},
            {{10, 20, 30, 40, 50, 60, 70, 80}, 2, true}
        };

        LinkedListCycle_141 solution;

        for (size_t i = 0; i < testCases.size(); ++i) {
            ListNode<int>* head = ListUtils::createLinkedListWithCycle<int>(testCases[i].input, testCases[i].pos);
            bool result = solution.hasCycle(head);

            assertEqScalar("Test " + to_string(i + 1), testCases[i].expected, result);

            ListUtils::freeList<int>(head);
        }
    }

    static void middleOfTheLinkedList_876_tests() {
        using IntListNode = ListNode<int>;

        vector<MiddleOfLinkedListTestCase> testCases = {
            // Provided examples
            {{1, 2, 3, 4, 5}, {3, 4, 5}},
            {{1, 2, 3, 4, 5, 6}, {4, 5, 6}},

            // Additional test cases
            {{}, {}},                         // Edge case: empty list
            {{1}, {1}},                       // Edge case: single element
            {{1, 2, 3, 4, 5, 6, 7}, {4, 5, 6, 7}} // Odd-length list
        };

        MiddleOfLinkedList_876 solution;

        for (size_t i = 0; i < testCases.size(); ++i) {
            IntListNode* input = ListUtils::createLinkedList<int>(testCases[i].input);
            IntListNode* result = solution.middleNode(input);
            vector<int> resultVector = ListUtils::toVector<int>(result);

            assertEqVIntExact("Test " + to_string(i + 1), testCases[i].expected, ListUtils::toVector<int>(result));

            ListUtils::freeList<int>(input);
        }
    }

    static void removeNthNodeFromEndOfList_19_tests() {
        using IntListNode = ListNode<int>;

        vector<RemoveNthNodeTestCase> testCases = {
            // Provided examples
            {{1, 2, 3, 4, 5}, 2, {1, 2, 3, 5}},
            {{1}, 1, {}},
            {{1, 2}, 1, {1}},

            // Additional test cases
            {{10, 20, 30, 40, 50, 60, 70}, 3, {10, 20, 30, 40, 60, 70}}, // Bigger list
            {{5, 10, 15, 20}, 4, {10, 15, 20}} // Removing the head
        };

        RemoveNthNodeFromEndOfList_19 solution;

        for (size_t i = 0; i < testCases.size(); ++i) {
            IntListNode* input = ListUtils::createLinkedList<int>(testCases[i].input);
            IntListNode* result = solution.removeNthFromEnd(input, testCases[i].n);
            vector<int> resultVector = ListUtils::toVector<int>(result);

            assertEqVIntExact("Test " + to_string(i + 1), testCases[i].expected, ListUtils::toVector<int>(result));

            ListUtils::freeList<int>(result);
        }
    }

    static void bestTimeToBuyAndSellStock_121_tests() {
        vector<MaxProfitTestCase> testCases = {
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
            assertEqScalar("Test " + to_string(i + 1), testCases[i].expected, result);
        }
    }

    static void spiralMatrix_54_tests() {
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
            assertEqVIntExact("Test " + to_string(i + 1), testCases[i].expected, result);
        }
    }

    static void validateBinarySearchTree_98_tests() {
        vector<ValidateBinarySearchTreeTestCase> testCases = {
            // Provided examples
            {{2, 1, 3}, true},
            {{5, 1, 4, nullopt, nullopt, 3, 6}, false},

            // Additional complex test cases
            {{10, 5, 15, nullopt, nullopt, 6, 20}, false}, // Violates BST in right subtree
            {{3, 1, 5, 0, 2, 4, 6}, true},                          // Valid BST
            {{1, nullopt, 2, nullopt, 3, nullopt, 4}, true} // Skewed right
        };

        ValidateBinarySearchTree_98 validator;

        for (size_t i = 0; i < testCases.size(); ++i) {
            TreeNode<int>* root = TreeUtils::vectorToTree<int>(testCases[i].tree);
            bool result = validator.isValidBST(root);

            if (!assertEqScalar("Validate BST Test " + to_string(i + 1), testCases[i].expected, result)) {
                cout << "  Input tree:\n";
                TreeUtils::printTree(root);
            }

            TreeUtils::freeTree(root);
        }
    }

    static void lowestCommonAncestor_235_tests() {
        vector<LowestCommonAncestorTestCase> testCases = {
            // Example 1
            {{6, 2, 8, 0, 4, 7, 9, nullopt, nullopt, 3, 5}, 2, 8, 6},
            // Example 2
            {{6, 2, 8, 0, 4, 7, 9, nullopt, nullopt, 3, 5}, 2, 4, 2},
            // Example 3
            {{2, 1}, 2, 1, 2},
            // Additional Complex Test 1
            {{10, 5, 15, 3, 8, 12, 20, 1, 4, 7, 9, nullopt, nullopt, 18, 25}, 4, 9, 5},
            // Additional Complex Test 2
            {{30, 10, 50, 5, 20, 40, 60, nullopt, 8, 15, 25, 35, 45, nullopt, 70}, 15, 45, 30},
        };

        LowestCommonAncestorOfBST_235 lcaSolver;

        for (size_t i = 0; i < testCases.size(); ++i) {
            TreeNode<int>* root = TreeUtils::vectorToTree(testCases[i].tree);
            TreeNode<int>* p = TreeUtils::findNode(root, testCases[i].p);
            TreeNode<int>* q = TreeUtils::findNode(root, testCases[i].q);

            TreeNode<int>* lca = lcaSolver.lowestCommonAncestor(root, p, q);
            int got = lca ? lca->val : numeric_limits<int>::min();

            if (!assertEqScalar("LCA Test " + to_string(i + 1), testCases[i].expected, got)) {
                cout << "  Input tree:\n";
                TreeUtils::printTree(root);
                cout << "  p=" << testCases[i].p << ", q=" << testCases[i].q << "\n";
            }

            TreeUtils::freeTree(root);
        }
    }

    static void copyRandomList_138_tests() {
        using IntListNode = ListNode<int>;

        vector<CopyRandomListTestCase> testCases = {
            // Provided test cases
            {{{7, nullopt}, {13, 0}, {11, 4}, {10, 2}, {1, 0}},
             {{7, nullopt}, {13, 0}, {11, 4}, {10, 2}, {1, 0}}},
            {{{1, 1}, {2, 1}}, {{1, 1}, {2, 1}}},
            {{{3, nullopt}, {3, 0}, {3, nullopt}},
             {{3, nullopt}, {3, 0}, {3, nullopt}}},

            // Additional complex test cases
            {{{1, nullopt}, {2, 0}, {3, 1}, {4, 3}, {5, 2}},
             {{1, nullopt}, {2, 0}, {3, 1}, {4, 3}, {5, 2}}},
            {{{10, 4}, {20, 3}, {30, 2}, {40, 1}, {50, nullopt}},
             {{10, 4}, {20, 3}, {30, 2}, {40, 1}, {50, nullopt}}}
        };

        CopyListWithRandomPointer_138 solution;

        for (size_t i = 0; i < testCases.size(); ++i) {
            IntListNode* input = ListUtils::createLinkedListWithRandom<int>(testCases[i].input);
            IntListNode* expected = ListUtils::createLinkedListWithRandom<int>(testCases[i].expected);

            IntListNode* result = solution.copyRandomList(input);
            bool isCorrect = ListUtils::compareListsWithRandom<int>(result, expected);

            assertEqScalar("Copy Random List Test " + to_string(i + 1), true, isCorrect);

            ListUtils::freeList(input);
            ListUtils::freeList(result);
            ListUtils::freeList(expected);
        }
    }

    static void kthSmallestElementInBST_230_tests() {
        vector<KthSmallestTestCase> testCases = {
            // Example 1
            {{3, 1, 4, nullopt, 2}, 1, 1},
            // Example 2
            {{5, 3, 6, 2, 4, nullopt, nullopt, 1}, 3, 3},
            // Additional Test 1: Larger balanced tree
            {{15, 10, 20, 5, 13, 17, 25, 3, 8, nullopt, 14, 16, 18}, 6, 14},
            // Additional Test 2: Single node tree
            {{42}, 1, 42},
            // Additional Test 3: Skewed tree
            {{1, nullopt, 2, nullopt, 3, nullopt, 4}, 4, 4}
        };

        KthSmallestElementInBST_230 solution;

        for (size_t i = 0; i < testCases.size(); ++i) {
            TreeNode<int>* root = TreeUtils::vectorToTree<int>(testCases[i].tree);
            int got = solution.kthSmallest(root, testCases[i].k);

            if (!assertEqScalar("Kth Smallest Element Test " + to_string(i + 1), testCases[i].expected, got)) {
                cout << "  Input tree:\n";
                TreeUtils::printTree(root);
                cout << "  k=" << testCases[i].k << "\n";
            }

            TreeUtils::freeTree(root);
        }
    }

    static void implementTrie_208_tests() {
        vector<TrieTestCase> testCases = {
            // Example 1
            {
                {"Trie", "insert", "search", "search", "startsWith", "insert", "search"},
                {nullopt, "apple", "apple", "app", "app", "app", "app"},
                {nullopt, nullopt, true, false, true, nullopt, true}
            },
            // Example 2: Overlapping words
            {
                {"Trie", "insert", "insert", "search", "search", "startsWith"},
                {nullopt, "apple", "applause", "apple", "applause", "app"},
                {nullopt, nullopt, nullopt, true, true, true}
            },
            // Example 3: Single-character operations
            {
                {"Trie", "insert", "search", "startsWith", "search"},
                {nullopt, "a", "a", "a", "b"},
                {nullopt, nullopt, true, true, false}
            },
            // Example 4: No matching prefix
            {
                {"Trie", "insert", "insert", "startsWith", "startsWith", "search"},
                {nullopt, "car", "cart", "ca", "cat", "carrot"},
                {nullopt, nullopt, nullopt, true, false, false}
            },
            // Example 5: Large input set
            {
                {"Trie", "insert", "insert", "insert", "search", "search", "startsWith"},
                {nullopt, "dictionary", "dictionaries", "dictator", "dictionary", "dictionaries", "dict"},
                {nullopt, nullopt, nullopt, nullopt, true, true, true}
            }
        };

        for (size_t i = 0; i < testCases.size(); ++i) {
            cout << "Running Trie Test Case " << i + 1 << ":\n";
            Trie* trie = nullptr;

            for (size_t j = 0; j < testCases[i].operations.size(); ++j) {
                const auto& op  = testCases[i].operations[j];
                const auto& arg = testCases[i].arguments[j];
                const auto& exp = testCases[i].expected[j];

                if (op == "Trie") { trie = new Trie(); continue; }
                if (op == "insert") { trie->insert(arg.value()); continue; }

                if (op == "search" || op == "startsWith") {
                    bool got = (op == "search")
                            ? trie->search(arg.value())
                            : trie->startsWith(arg.value());

                    bool expected = exp.value();
                    const string label = makeStepLabel("Trie Case", i, j, op, arg);

                    if (!assertEqScalar(label, expected, got)) {
                        cout << "  (debug) op=" << op << " arg=\"" << arg.value() << "\"\n";
                    }
                }
            }

            delete trie;
            cout << "\n";
        }
    }

    static void kthLargestElementInArray_215_tests()
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

            // Assertions instead of manual cout formatting
            assertEqScalar("Kth Largest 215 Test " + to_string(i + 1) + " [MaxHeap]", testCases[i].expected, resMax);
            assertEqScalar("Kth Largest 215 Test " + to_string(i + 1) + " [MinHeap]", testCases[i].expected, resMin);
        }
    }

    static vector<int> runMinHeapScenario(const vector<pair<string,int>>& ops) {
        MinHeap heap;
        vector<int> out;
        for (const auto& [op, x] : ops) {
            if (op == "insert") {
                heap.insert(x);
            } else if (op == "extractMin") {
                out.push_back(heap.extractMin());
            } else if (op == "update") {
                heap.update(x, x);
            }
        }
        return out;
    }

    static void minHeap_tests() {
        vector<MinHeapTestCase> testCases = {
            {
                {{"insert",5},{"insert",3},{"insert",8},{"insert",1},{"insert",2},{"extractMin",0},{"extractMin",0}},
                {1,2}       // Expected results of the extractMin calls
            },
            {
                {{"insert",10},{"insert",20},{"insert",5},{"update",1},{"extractMin",0}},
                {1}         // Updated root is extracted
            },
            {
                {{"insert",100},{"insert",50},{"insert",25},{"extractMin",0},{"extractMin",0}},
                {25,50}     // Both extractions
            }
        };

        for (size_t i = 0; i < testCases.size(); ++i) {
            const auto got = runMinHeapScenario(testCases[i].operations);
            assertEqVIntExact("MinHeap Test " + to_string(i + 1), testCases[i].expected, got);
        }
    }

    static void rotateImage_48_tests() {
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

        // -------- Transpose-then-Reverse variant --------------------------------
        for (size_t i = 0; i < testCases.size(); ++i) {
            auto m = testCases[i].input; // fresh copy
            rotator.rotateTransposeReverse(m);
            assertEqVVIntExact("[Transpose+Reverse] Test " + to_string(i + 1), testCases[i].expected, m);
        }

        // -------- Layer-by-Layer (“onion”) swap variant -------------------------
        for (size_t i = 0; i < testCases.size(); ++i) {
            auto m = testCases[i].input; // fresh copy
            rotator.rotateLayerSwap(m);
            assertEqVVIntExact("[LayerSwap]        Test " + to_string(i + 1), testCases[i].expected, m);
        }
    }

    static void mergeIntervals_56_tests() {
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
            assertEqVVIntExact("Merge Intervals Test " + to_string(i + 1), testCases[i].expected, got);
        }
    }

    static void mergeKLists_tests() {
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
            vector<IntListNode*> lists;
            lists.reserve(testCases[i].input.size());
            for (const auto& v : testCases[i].input) {
                lists.push_back(ListUtils::createLinkedList<int>(v));
            }

            IntListNode* merged = solution.mergeKLists(lists);

            assertEqVIntExact("Merge K Lists Test " + to_string(i + 1), testCases[i].expected,
                            ListUtils::toVector<int>(merged));

            ListUtils::freeList<int>(merged);
        }
    }

    static void productOfArrayExceptSelf_238_tests() {
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
            assertEqVIntExact("Product Except Self Test " + to_string(i + 1), testCases[i].expected, got);
        }
    }

    static void majorityElement_169_tests() {
        // Define test cases
        vector<MajorityElementTestCase> testCases = {
            // Example 1
            {{3, 2, 3}, 3},
            // Example 2
            {{2, 2, 1, 1, 1, 2, 2}, 2},
            // Edge Case: Single element
            {{1}, 1},
            // Complex Case 1: Large input with clear majority
            {{1, 1, 1, 1, 2, 2, 2, 2, 1, 1}, 1},
            // Complex Case 2: Alternating majority
            {{5, 1, 5, 1, 5, 5, 5, 2, 5, 3, 5, 5}, 5},
            // Complex Case 3: Majority in large data
            {{10, 9, 9, 10, 10, 10, 9, 10, 9, 10, 10}, 10}
        };

        // Boyer–Moore Majority Vote
        for (size_t i = 0; i < testCases.size(); ++i) {
            MajorityElement_169 sol;
            int got = sol.majorityElement(testCases[i].input);
            assertEqScalar("MajorityElement_169 Boyer–Moore Test " + to_string(i + 1), testCases[i].expected, got);
        }

        // Frequency Counting (hashmap)
        for (size_t i = 0; i < testCases.size(); ++i) {
            MajorityElement_169 sol;
            int got = sol.majorityElementWithHashmap(testCases[i].input);
            assertEqScalar("MajorityElement_169 Hashmap Test " + to_string(i + 1), testCases[i].expected, got);
        }
    }

    static void evaluateReversePolishNotation_150_tests() {
        vector<EvaluateRPNTestCase> testCases = {
            {{"2", "1", "+", "3", "*"}, 9},  // Example 1
            {{"4", "13", "5", "/", "+"}, 6}, // Example 2
            {{"10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"}, 22}, // Example 3
            // Additional test cases
            {{"3", "4", "+", "2", "*", "7", "/"}, 2}, // Complex case: (((3+4)*2)/7)
            {{"5", "-2", "4", "+", "*", "3", "+"}, 13} // Complex case: ((5*(-2+4))+3)
        };

        EvaluateReversePolishNotation_150 evaluator;

        for (size_t i = 0; i < testCases.size(); ++i) {
            int got = evaluator.evalRPN(testCases[i].input);
            assertEqScalar("Evaluate RPN Test " + to_string(i + 1), testCases[i].expected, got);
        }
    }

    static void largestRectangleInHistogram_84_tests() {
        vector<LargestRectangleTestCase> testCases = {
            // Example 1
            {{2, 1, 5, 6, 2, 3}, 10},
            // Example 2
            {{2, 4}, 4},
            // Additional Test 1: All bars of the same height
            {{1, 1, 1, 1, 1}, 5},
            // Additional Test 2: Decreasing heights
            {{5, 4, 3, 2, 1}, 9},
            // Additional Test 3: Complex case
            {{2, 1, 4, 5, 1, 3, 3}, 8},
            // Additional Test 4: Plateau with equal heights (ties).
            {{1, 2, 3, 3, 3, 1}, 9}
        };

        LargestRectangleInHistogram_84 solution;
        for (size_t i = 0; i < testCases.size(); ++i) {
            int got = solution.largestRectangleArea(testCases[i].input);
            assertEqScalar("Largest Rectangle Test " + to_string(i + 1), testCases[i].expected, got);
        }
    }

    static void wordSearch_79_tests() {
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
            assertEqScalar("Word Search Test " + to_string(i + 1), testCases[i].expected, got);
        }
    }

    static void validParentheses_20_tests() {
        vector<ValidParenthesesTestCase> testCases = {
            {"()", true},
            {"()[]{}", true},
            {"(]", false},
            {"([])", true},
            {"({[(){}[]]})", true} // Additional complex test case
        };

        ValidParentheses_20 solution;
        for (size_t i = 0; i < testCases.size(); ++i) {
            bool got = solution.isValid(testCases[i].input);
            assertEqScalar("Valid Parentheses Test " + to_string(i + 1), testCases[i].expected, got);
        }
    }

    static void validSudoku_36_tests() {
        vector<ValidSudokuTestCase> testCases = {
            // Example 1: Valid Sudoku
            {{
                {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
                {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
                {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
                {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
                {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
                {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
                {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
                {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
                {'.', '.', '.', '.', '8', '.', '.', '7', '9'}
            }, true},

            // Example 2: Invalid Sudoku (Duplicate in Sub-box)
            {{
                {'8', '3', '.', '.', '7', '.', '.', '.', '.'},
                {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
                {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
                {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
                {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
                {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
                {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
                {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
                {'.', '.', '.', '.', '8', '.', '.', '7', '9'}
            }, false},

            // Example 3: Valid Complex Sudoku
            {{
                {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
                {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
                {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
                {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
                {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
                {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
                {'1', '6', '.', '.', '.', '.', '2', '8', '.'},
                {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
                {'2', '.', '.', '.', '8', '.', '.', '7', '9'}
            }, true},

            // Example 4: Invalid Sudoku (Duplicate in Row)
            {{
                {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
                {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
                {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
                {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
                {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
                {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
                {'1', '6', '.', '.', '.', '.', '2', '8', '.'},
                {'.', '.', '.', '4', '1', '9', '.', '1', '5'},
                {'2', '.', '.', '.', '8', '.', '.', '7', '9'}
            }, false},

            // Example 5: Invalid Sudoku (Duplicate in Column)
            {{
                {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
                {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
                {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
                {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
                {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
                {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
                {'1', '6', '.', '.', '.', '.', '2', '8', '.'},
                {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
                {'2', '.', '.', '.', '8', '.', '.', '7', '5'}
            }, false},
        };

        ValidSudoku_36 solver;
        for (size_t i = 0; i < testCases.size(); ++i) {
            bool got = solver.isValidSudoku(testCases[i].board);
            assertEqScalar("Valid Sudoku Test " + to_string(i + 1), testCases[i].expected, got);
        }
    }

    static void binarySearch_704_tests() {
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
            int got = solution.search(testCases[i].input, testCases[i].target);
            assertEqScalar("Binary Search Test " + to_string(i + 1), testCases[i].expected, got);
        }
    }

    static void searchInsertPosition_35_tests() {
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
            int got = solution.searchInsert(testCases[i].input, testCases[i].target);
            assertEqScalar("Search Insert Position Test " + to_string(i + 1), testCases[i].expected, got);
        }
    }

    static void search2DMatrix_74_tests() {
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
            assertEqScalar("Search 2D Matrix Test " + to_string(i + 1), testCases[i].expected, got);
        }
    }

    static void allOOneDataStructure_432_tests() {
        // Test 1: basic
        AllOOneDataStructure_432 ds1;
        ds1.inc("hello"); ds1.inc("hello");
        assertMaxMin("AllOOne T1/A",
                    [&]{ return ds1.getMaxKey(); }, [&]{ return ds1.getMinKey(); },
                    {"hello"}, {"hello"});

        ds1.inc("leet");
        assertMaxMin("AllOOne T1/B",
                    [&]{ return ds1.getMaxKey(); }, [&]{ return ds1.getMinKey(); },
                    {"hello"}, {"leet"});

        // Test 2: ties
        AllOOneDataStructure_432 ds2;
        ds2.inc("foo");
        ds2.inc("bar"); ds2.inc("bar");
        assertMaxMin("AllOOne T2/A",
                    [&]{ return ds2.getMaxKey(); }, [&]{ return ds2.getMinKey(); },
                    {"bar"}, {"foo"});

        ds2.inc("foo"); // both = 2
        assertMaxMin("AllOOne T2/B",
                    [&]{ return ds2.getMaxKey(); }, [&]{ return ds2.getMinKey(); },
                    {"foo","bar"}, {"foo","bar"});

        // Test 3: dec() & removal
        AllOOneDataStructure_432 ds3;
        ds3.inc("a"); ds3.inc("a"); ds3.inc("a"); // a=3
        ds3.inc("b"); ds3.inc("c");               // b=1, c=1
        assertMaxMin("AllOOne T3/A",
                    [&]{ return ds3.getMaxKey(); }, [&]{ return ds3.getMinKey(); },
                    {"a"}, {"b","c"});

        ds3.dec("a"); ds3.dec("a"); ds3.dec("a"); // a removed
        assertMaxMin("AllOOne T3/B",
                    [&]{ return ds3.getMaxKey(); }, [&]{ return ds3.getMinKey(); },
                    {"b","c"}, {"b","c"});
    }

    static void findMinimumInRotatedSortedArray_153_tests() {
        vector<FindMinTestCase> testCases = {
            {{3, 4, 5, 1, 2}, 1},                     // Example 1
            {{4, 5, 6, 7, 0, 1, 2}, 0},               // Example 2
            {{11, 13, 15, 17}, 11},                   // Example 3
            {{5, 6, 7, 8, 9, 1, 2, 3, 4}, 1},         // Additional Test 1
            {{30, 40, 50, 5, 10, 20}, 5}              // Additional Test 2
        };

        FindMinimumInRotatedSortedArray_153 solution;
        for (size_t i = 0; i < testCases.size(); ++i) {
            int got = solution.findMin(testCases[i].input);
            assertEqScalar("Find Min Rotated Array 153 Test " + to_string(i + 1), testCases[i].expected, got);
        }
    }

    static void cloneGraph_133_tests() {
        vector<vector<vector<int>>> testCases = {
            {{2, 4}, {1, 3}, {2, 4}, {1, 3}},  // Example 1
            {{}},  // Example 2 (Single node, no neighbors)
            {},    // Example 3 (Empty graph)
            {{2}, {1, 3}, {2, 4}, {3}}, // Additional case: Line-shaped graph
            {{2, 3, 4, 5}, {1, 3, 5}, {1, 2, 4}, {1, 3, 5}, {1, 2, 4}} // Additional case: Fully connected small graph
        };

        CloneGraph_133 solver;
        for (size_t i = 0; i < testCases.size(); ++i) {
            GraphNode<int>* original = GraphUtils::buildGraph(testCases[i]);
            GraphNode<int>* cloned   = solver.cloneGraph(original);

            bool iso = GraphUtils::areGraphsIsomorphic(original, cloned);
            assertEqScalar("Clone Graph 133 Test " + to_string(i + 1), true, iso);

            GraphUtils::freeGraph(original);
            GraphUtils::freeGraph(cloned);
        }
    }

    static void zigzagConversion_6_tests() {
        vector<ZigzagTestCase> testCases = {
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

            const string base = "Zigzag Conversion 6 Test " + to_string(i + 1)
                              + " (rows=" + to_string(tc.numRows) + ")";

            assertEqScalar(base + " [row-wise]",    tc.expected, gotRow);
            assertEqScalar(base + " [jump-pattern]",tc.expected, gotJump);
            assertEqScalar(base + " [consistency]", gotRow,      gotJump);
        }
    }

    static void hIndex_274_tests() {
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
            assertEqScalar("H-Index 274 Test " + to_string(i + 1), testCases[i].expected, got);
        }
    }

    static void sortColors_75_tests() {
        // Create test cases (two from the problem statement + three more)
        vector<SortColorsTestCase> testCases = {
            // Example 1
            {{2, 0, 2, 1, 1, 0}, {0, 0, 1, 1, 2, 2}},
            // Example 2
            {{2, 0, 1}, {0, 1, 2}},
            // Additional Test 1: Single element
            {{0}, {0}},
            // Additional Test 2: All the same element
            {{2, 2, 2, 2}, {2, 2, 2, 2}},
            // Additional Test 3: Mixed with more 1s
            {{1, 0, 2, 2, 1, 0}, {0, 0, 1, 1, 2, 2}}
        };

        SortColors_75 sol;
        for (size_t i = 0; i < testCases.size(); ++i) {
            auto arr = testCases[i].input;   // work on a copy
            sol.sortColors(arr);
            assertEqVIntExact("Sort Colors 75 Test " + to_string(i + 1), testCases[i].expected, arr);
        }
    }

    static void removeDuplicatesFromSortedArrayII_80_tests() {
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
            assertEqScalar(base + " [k]", testCases[i].expectedK, k);
            assertEqVIntPrefix(base + " [prefix]", testCases[i].expected, nums, k);
        }
    }

    static void bestTimeToBuyAndSellStockII_122_tests() {
        vector<BestTimeToBuyAndSellStockII_122_TestCase> testCases = {
            // 3 examples from the problem statement:
            {{7,1,5,3,6,4}, 7}, // Example 1
            {{1,2,3,4,5}, 4},   // Example 2
            {{7,6,4,3,1}, 0},   // Example 3

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
            int got = sol.maxProfit(testCases[i].prices);
            assertEqScalar("Best Time to Buy and Sell Stock II 122 Test " + to_string(i + 1),
                        testCases[i].expected, got);
        }
    }

    static void validAnagram_242_tests() {
        vector<ValidAnagramTestCase> testCases = {
            // Examples from the problem statement
            {"anagram", "nagaram", true},
            {"rat", "car", false},

            // Additional complex test cases
            {"abcdefg", "gfedcba", true}, // Reverse order, still an anagram
            {"aabbcc", "abcabc", true},   // Same frequency, different order
            {string(50000, 'a') + "b", string(50000, 'a') + "c", false} // Edge case with large input, one character differs
        };

        ValidAnagram_242 sol;
        for (size_t i = 0; i < testCases.size(); ++i) {
            bool got = sol.isAnagram(testCases[i].s, testCases[i].t);
            assertEqScalar("Valid Anagram 242 Test " + to_string(i + 1), testCases[i].expected, got);
        }
    }

    static void analyzeUserWebsiteVisitPattern_1152_tests() {
        vector<AnalyzeUserWebsiteVisitPatternTestCase> testCases = {
            // Example 1 (From Problem Statement)
            {
                {"joe", "joe", "joe", "james", "james", "james", "james", "mary", "mary", "mary"},
                {1, 2, 3, 4, 5, 6, 7, 8, 9, 10},
                {"home", "about", "career", "home", "cart", "maps", "home", "home", "about", "career"},
                {"home", "about", "career"}
            },
            // Example 2 (From Problem Statement)
            {
                {"ua", "ua", "ua", "ub", "ub", "ub"},
                {1, 2, 3, 4, 5, 6},
                {"a", "b", "a", "a", "b", "c"},
                {"a", "b", "a"}
            },
            // Corner Case: Only one user with exactly three visits
            {
                {"alice", "alice", "alice"},
                {1, 2, 3},
                {"x", "y", "z"},
                {"x", "y", "z"}
            },
            // Large Complex Case: Multiple users with different patterns
            {
                {"u1", "u1", "u1", "u1", "u2", "u2", "u2", "u3", "u3", "u3", "u3", "u3"},
                {1, 2, 3, 4, 5, 6, 7, 1, 2, 3, 4, 5},
                {"alpha", "beta", "gamma", "delta", "alpha", "beta", "gamma", "beta", "gamma", "alpha", "delta", "beta"},
                {"alpha", "beta", "gamma"}
            },
            // Another more complex test
            {
                {"u1", "u1", "u1", "u2", "u2", "u2", "u3", "u3", "u3", "u4", "u4", "u4"},
                {1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3},
                {"home", "about", "career", "home", "about", "career", "home", "career", "about", "career", "about", "home"},
                {"home", "about", "career"}
            },
            // Complex case with a tie, forcing lexicographical sorting
            {
                {"u1", "u1", "u1", "u2", "u2", "u2", "u3", "u3", "u3", "u4", "u4", "u4", "u5", "u5", "u5", "u6", "u6", "u6"},
                {1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3},
                {"alpha", "beta", "gamma", "alpha", "beta", "gamma", "beta", "gamma", "delta",
                 "beta", "gamma", "delta", "alpha", "beta", "gamma", "alpha", "beta", "gamma"},
                {"alpha", "beta", "gamma"}  // Lexicographically smaller, tie-breaking case
            }
        };

        AnalyzeUserWebsiteVisitPattern1152 sol;
        for (size_t i = 0; i < testCases.size(); ++i) {
            auto m = sol.mostVisitedPattern_usingMap(
                testCases[i].username, testCases[i].timestamp, testCases[i].website);
            auto h = sol.mostVisitedPattern_usingHashmap(
                testCases[i].username, testCases[i].timestamp, testCases[i].website);

            const string base = "Analyze User Website Visit Pattern 1152 Test " + to_string(i + 1);
            assertEqStrings(base + " [map]",     testCases[i].expected, m);
            assertEqStrings(base + " [hashmap]", testCases[i].expected, h);
            assertEqStrings(base + " [consistency]", m, h);
        }
    }

    static void groupAnagrams_49_tests() {
        vector<GroupAnagramsTestCase> testCases = {
            // Example 1
            {{"eat", "tea", "tan", "ate", "nat", "bat"},
             {{"bat"}, {"tan", "nat"}, {"eat", "tea", "ate"}}},

            // Example 2
            {{""}, { {""} }},

            // Example 3
            {{"a"}, { {"a"} }},

            // Large test case: Multiple anagram groups with long words
            {{"abcdefg", "gfedcba", "xyz", "zxy", "yxz", "longword", "wordlong"},
             {{"abcdefg", "gfedcba"}, {"xyz", "zxy", "yxz"}, {"longword", "wordlong"}}},

            // Large test case: Many unique words (no anagrams)
            {{"abcd", "efgh", "ijkl", "mnop", "qrst", "uvwx", "yz"},
             {{"abcd"}, {"efgh"}, {"ijkl"}, {"mnop"}, {"qrst"}, {"uvwx"}, {"yz"}}}
        };

        GroupAnagrams_49 solution;
        for (size_t i = 0; i < testCases.size(); ++i) {
            auto got_sorting  = solution.groupAnagrams_sorting (testCases[i].input);
            auto got_counting = solution.groupAnagrams_counting(testCases[i].input);

            const string base = "Group Anagrams 49 Test " + to_string(i + 1);

            assertEqVVStrAnyOrder(base + " [sorting]",     testCases[i].expected, got_sorting);
            assertEqVVStrAnyOrder(base + " [counting]",    testCases[i].expected, got_counting);
            assertEqVVStrAnyOrder(base + " [consistency]", got_sorting,           got_counting);
        }
    }

    static void findCelebrity_277_tests() {
        vector<FindCelebrityTestCase> testCases = {
            // Easy: A knows B, B knows no one → B is celebrity
            {{{0, 1}, {0, 0}}, 1},

            // Edge: 1 person only
            {{{0}}, 0},

            // Edge: 3 people, 2 is celeb
            {{
                {0, 1, 1},
                {0, 0, 1},
                {0, 0, 0}
            }, 2},

            // 4x4 complex
            {{
                {0, 1, 1, 1},
                {0, 0, 1, 1},
                {0, 0, 0, 1},
                {0, 0, 0, 0}
            }, 3},

            // 7x7 larger case, celebrity at 6
            {{
                {0,1,1,1,1,1,1},
                {0,0,1,1,1,1,1},
                {0,0,0,1,1,1,1},
                {0,0,0,0,1,1,1},
                {0,0,0,0,0,1,1},
                {0,0,0,0,0,0,1},
                {0,0,0,0,0,0,0}
            }, 6}
        };

        for (size_t i = 0; i < testCases.size(); ++i) {
            FindCelebrity_277 sol;
            sol.knowsMatrix = testCases[i].matrix;
            int got = sol.findCelebrity(static_cast<int>(testCases[i].matrix.size()));
            assertEqScalar("Find Celebrity 277 Test " + to_string(i + 1),
                        testCases[i].expected, got);
        }
    }

    static void longestConsecutiveSequence_128_tests() {
        vector<LongestConsecutiveSequenceTestCase> testCases = {
            // Examples from problem statement
            {{100,4,200,1,3,2},         4},
            {{0,3,7,2,5,8,4,6,0,1},     9},
            {{1,0,1,2},                 3},
            // Additional complex cases
            {{-1,-2,-3,7,6,5,4,3,2,1},   7},          // 1,2,3,4,5,6,7
            {{10,5,12,3,55,30,4,11,11,5,13,14,6}, 5}  // 10–14
        };

        LongestConsecutiveSequence_128 sol;
        for (size_t i = 0; i < testCases.size(); ++i) {
            int got = sol.longestConsecutive(testCases[i].input);
            assertEqScalar("Longest Consecutive Sequence 128 Test " + to_string(i + 1),
                        testCases[i].expected, got);
        }
    }

    static void fizzBuzz_412_tests() {
        vector<int> ns = {3, 5, 15, 16, 30};
        vector<vector<string>> expected = {
            {"1","2","Fizz"},
            {"1","2","Fizz","4","Buzz"},
            {"1","2","Fizz","4","Buzz","Fizz","7","8","Fizz","Buzz","11","Fizz","13","14","FizzBuzz"},
            {"1","2","Fizz","4","Buzz","Fizz","7","8","Fizz","Buzz","11","Fizz","13","14","FizzBuzz","16"},
            {"1","2","Fizz","4","Buzz","Fizz","7","8","Fizz","Buzz","11","Fizz","13","14","FizzBuzz","16","17","Fizz","19","Buzz","Fizz","22","23","Fizz","Buzz","26","Fizz","28","29","FizzBuzz"}
        };

        FizzBuzz_412 sol;
        for (size_t i = 0; i < ns.size(); ++i) {
            auto got = sol.fizzBuzz(ns[i]);
            const string label = "FizzBuzz 412 Test " + to_string(i + 1) + " (n=" + to_string(ns[i]) + ")";
            // exact order comparison
            assertEqGeneric(label, expected[i], got,
                            [](vector<string> v){ return v; },  // identity normalize
                            PrintQuotedStrings{});
        }
    }

    // Tests for LeetCode #424 Longest Repeating Character Replacement
    static void longestRepeatingCharacterReplacement_424_tests() {
        vector<LongestRepeatingCharReplacementTestCase> testCases = {
            {"ABAB",      2, 4},  // Example 1
            {"AABABBA",   1, 4},  // Example 2
            {"BABABA",    3, 6},  // Transform 3 'A's into 'B's
            {"ABCDE",     2, 3},  // Best substring length 3 by 2 changes
            {"ABBBBAA",   2, 6}   // 6-length window after 2 changes
        };

        LongestRepeatingCharacterReplacement_424 sol;
        for (size_t i = 0; i < testCases.size(); ++i) {
            int got = sol.characterReplacement(testCases[i].input, testCases[i].k);
            assertEqScalar("Longest Repeating Character Replacement 424 Test " + to_string(i + 1),
                        testCases[i].expected, got);
        }
    }

    static void lruCache_146_tests() {
        vector<LRUCacheTestCase> testCases = {
            // From problem statement
            {
                {"LRUCache","put","put","get","put","get","put","get","get","get"},
                {{2},      {1,1}, {2,2}, {1},  {3,3}, {2},  {4,4}, {1},  {3},   {4}},
                { nullopt, nullopt, nullopt, 1,
                  nullopt, -1,         nullopt, -1,
                   3,            4 }
            },
            // Additional: overwrite existing key and capacity=1 edge
            {
                {"LRUCache","put","put","get","put","get","get"},
                {{1},      {1,10},{1,20},{1},  {2,30},{1},  {2}},
                { nullopt, nullopt, nullopt, 20,
                  nullopt,  -1,           30 }
            },
            // Additional: complex sequence with capacity = 3 and multiple evictions
            {
                {"LRUCache","put","put","put","get","put","get","get","put","get","get"},
                {{3},      {1,1}, {2,2}, {3,3}, {1},  {4,4}, {2},  {3},  {5,5}, {1},  {4}},
                { nullopt, nullopt, nullopt, nullopt, 1,
                  nullopt, -1,          3,          nullopt, -1,        4}
            },
        };

        for (size_t t = 0; t < testCases.size(); ++t) {
            unique_ptr<LRUCache> cache;
            const auto& C = testCases[t];

            for (size_t i = 0; i < C.operations.size(); ++i) {
                const string& op = C.operations[i];

                if (op == "LRUCache") {
                    cache = make_unique<LRUCache>(C.arguments[i][0]);
                } else if (op == "put") {
                    cache->put(C.arguments[i][0], C.arguments[i][1]);
                } else if (op == "get") {
                    int key = C.arguments[i][0];
                    int got = cache->get(key);
                    const string label = makeStepLabel("LRUCache_146", t, i, "get", to_string(key));
                    assertEqScalar(label, C.expected[i].value(), got);
                }
            }
        }
    }

    static void sortCharactersByFrequency_451_tests() {
        vector<string> inputs = {
            "tree",      // 'e'x2, 'r','t'
            "cccaaa",    // 'c'x3, 'a'x3
            "Aabb",      // 'b'x2, 'A','a'
            "dccbbbaaaa",// a4,b3,c2,d1
            "srrqqqpppp" // p4,q3,r2,s1
        };

        SortCharactersByFrequency_451 sol;
        for (size_t i = 0; i < inputs.size(); ++i) {
            string got = sol.frequencySort(inputs[i]);
            const string label = "Sort Characters by Frequency 451 Test " + to_string(i + 1);
            assertEqScalar(label, true, isValidFrequencySort(inputs[i], got));
        }
    }

    static void coinChange_322_tests() {
        vector<CoinChangeTestCase> testCases = {
            // 3 examples from the problem statement
            { {1,2,5},       11,  3  },
            { {2},           3,  -1  },
            { {1},           0,   0  },

            // 2 complex examples:
            // • 8 denominations, amount ≥ 30
            { {1,3,4,5,10,20,50,100}, 99,  5  },
            // • 8 prime‐value coins, larger amount
            { {2,3,5,7,11,13,17,19}, 100,  6  }
        };

        CoinChange_322 sol;
        for (size_t i = 0; i < testCases.size(); ++i) {
            int got = sol.coinChange(testCases[i].coins, testCases[i].amount);
            const string label = "Coin Change 322 Test " + to_string(i + 1) +
                                " (amount=" + to_string(testCases[i].amount) + ")";
            assertEqScalar(label, testCases[i].expected, got);
        }
    }

    static void topKFrequentWords_692_tests() {
        vector<TopKFrequentWordsTestCase> testCases = {
            // Examples from problem statement
            {{"i","love","leetcode","i","love","coding"}, 2, {"i","love"}},
            {{"the","day","is","sunny","the","the","the","sunny","is","is"}, 4, {"the","is","sunny","day"}},
            // Additional complex tests
            {{"a","b","c","a","b","c"},                    2, {"a","b"}},                    // all tie, pick lexicographically smallest
            {{"apple","app","apple","banana","banana","app","banana","car"}, 3, {"banana","app","apple"}}, // freq tie + lex order
            {{"z","y","z","x","y"},                       3, {"y","z","x"}}                // z,y freq tie, x last
        };

        TopKFrequentWords_692 sol;
        for (size_t i = 0; i < testCases.size(); ++i) {
            auto got = sol.topKFrequent(testCases[i].input, testCases[i].k);
            const string label = "Top K Frequent Words 692 Test " + to_string(i + 1) +
                                " (k=" + to_string(testCases[i].k) + ")";
            assertEqStrings(label, testCases[i].expected, got);  // exact order matters
        }
    }

    static void longestCycleInGraph_2360_tests() {
        vector<LongestCycleTestCase> testCases = {
            // 2 examples from the LeetCode problem statement
            {{3, 3, 4, 2, 3}, 3},   // Example 1
            {{2, -1, 3, 1}, -1},    // Example 2

            // 3 additional, more complex cases
            {{1, 2, 3, 4, 0}, 5},         // single 5-node cycle
            {{1, 0, 4, 2, 3}, 3},         // two cycles, longest = 3
            {{1, 2, 3, 4, 5, 6, 0}, 7}    // single 7-node cycle
        };

        LongestCycleInGraph_2360 sol;
        for (size_t i = 0; i < testCases.size(); ++i) {
            int got = sol.longestCycle(testCases[i].edges);
            const string label = "Longest Cycle in Graph 2360 Test " + to_string(i + 1);
            assertEqScalar(label, testCases[i].expected, got);
        }
    }

    static void shortestCycleInGraph_2608_tests() {
        vector<ShortestCycleTestCase> cases = {
            // ── 2 examples from the problem statement ───────────────────────────
            {
                7,
                {{0,1},{1,2},{2,0},{3,4},{4,5},{5,6},{6,3}},
                3
            },
            {
                4,
                {{0,1},{0,2}},
                -1
            },

            // ── extra #1 : tiny corner-case – only one edge, no cycle ───────────
            {
                2,
                {{0,1}},
                -1
            },

            /* ── extra #2 : larger, multiple cycles, shortest = 3 ───────────────
                   triangle 0-1-2-0  (len 3)
                   square   3-4-5-6-3 (len 4)
                   edges 2-3 and 4-7-5 add inter-connections                  */
            {
                8,
                {{0,1},{1,2},{2,0},
                 {3,4},{4,5},{5,6},{6,3},
                 {2,3},
                 {4,7},{7,5}},
                3
            },

            /* ── extra #3 : “outer-loop needed” case (path + remote triangle) ───
               0-1-2-3-4-5-6   long arm
                         ╲
                          7
                         ╱ ╲
                        8 - 6          shortest = 3 (6-7-8-6)
               With BFS from 0 the first detected cycle would be very long,
               so we need one BFS per start vertex to get the true minimum.      */
            {
                9,
                {{0,1},{1,2},{2,3},{3,4},{4,5},{5,6},   // path
                 {6,7},{7,8},{8,6}},                    // triangle at the end
                3
            }
        };

        ShortestCycleInGraph_2608 sol;
        for (size_t i = 0; i < cases.size(); ++i) {
            int got = sol.findShortestCycle(cases[i].n, cases[i].edges);
            assertEqScalar("Shortest Cycle in Graph 2608 Test " + to_string(i + 1), cases[i].expected, got);
        }
    }

    static void uniquePathsII_63_tests() {
        vector<UniquePathsIITestCase> testCases = {
            // From the problem statement
            {{{0,0,0},{0,1,0},{0,0,0}}, 2},
            {{{0,1},{0,0}}, 1},

            // Additional complex cases
            // 1) Single‐row with an obstacle blocking all paths past it
            {{{0,1,0,0,0}}, 0},

            // 2) 3×3 with no obstacles: C(4,2)=6
            {{{0,0,0},{0,0,0},{0,0,0}}, 6},

            // 3) Larger 10×10 grid with no obstacles:
            //    number of paths = C(18,9) = 48620
            {
                vector<vector<int>>(10, vector<int>(10, 0)),
                48620
            }
        };

        UniquePathsII_63 sol;
        for (size_t i = 0; i < testCases.size(); ++i) {
            int got = sol.uniquePathsWithObstacles(testCases[i].input);
            assertEqScalar("Unique Paths II 63 Test " + to_string(i + 1), testCases[i].expected, got);
        }
    }

    static void maximumAverageSubarrayI_643_tests() {
        vector<MaxAvgTestCase> testCases = {
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
            double got = sol.findMaxAverage(testCases[i].input, testCases[i].k);
            const string label = "Max Avg Subarray I 643 Test " + to_string(i + 1);
            // keep tolerance via approxEqual, assert on the boolean
            assertEqScalar(label, true, approxEqual(got, testCases[i].expected));
        }
    }

    static void maxConsecutiveOnesIII_1004_tests() {
        vector<MaxConsecutiveOnesTestCase> testCases = {
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
            int got = sol.longestOnes(testCases[i].input, testCases[i].k);
            assertEqScalar("Max Consecutive Ones III 1004 Test " + to_string(i + 1), testCases[i].expected, got);
        }
    }

    static void longestSubstringWithoutRepeatingCharacters_3_tests() {
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
            assertEqScalar("Longest Substring Without Repeating Characters 3 Test " + to_string(i + 1),
                        testCases[i].expected, got);
        }
    }

    static void minimumSizeSubarraySum_209_tests() {
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
            int got = sol.minSubArrayLen(testCases[i].target, testCases[i].input);
            assertEqScalar("Minimum Size Subarray Sum 209 Test " + to_string(i + 1), testCases[i].expected, got);
        }
    }

    static void permutationInString_567_tests() {
        vector<PermutationInStringTestCase> testCases = {
            // Two examples from the problem statement
            {"ab", "eidbaooo", true},
            {"ab", "eidboaoo", false},
            // Three extra, increasingly tricky, cases
            {"adc",  "dcda",              true},   // permutation “cda” present
            {"xyz",  "afdgzyxksldfm",     true},   // reversed substring “zyx”
            {"abcd", "abc",               false}   // corner-case: |s1| > |s2|
        };

        PermutationInString_567 sol;
        for (size_t i = 0; i < testCases.size(); ++i) {
            bool got = sol.checkInclusion(testCases[i].s1, testCases[i].s2);
            assertEqScalar("Permutation in String 567 Test " + to_string(i + 1), testCases[i].expected, got);
        }
    }

    static void squaresOfSortedArray_977_tests() {
        vector<SquaresOfSortedArrayTestCase> testCases = {
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
            auto got = sol.sortedSquares(testCases[i].input);
            assertEqVIntExact("Squares of Sorted Array 977 Test " + to_string(i + 1),
                            testCases[i].expected, got);
        }
    }

    static void reverseString_344_tests() {
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
            auto s = testCases[i].input;          // work on a copy
            solver.reverseString(s);

            const string label = "Reverse String 344 Test " + to_string(i + 1);
            const string got(s.begin(), s.end());
            const string exp(testCases[i].expected.begin(), testCases[i].expected.end());
            assertEqScalar(label, exp, got);
        }
    }

    static void twoSumII_167_tests() {
        // long stress-case prepared first so it can go in the init-list
        vector<int> longNums;
        for (int v = -1000; v <= 1000; ++v) longNums.push_back(v);  // 2001 elements
        vector<int> longAns = {1, static_cast<int>(longNums.size())};  // -1000 + 1000 = 0

        vector<TwoSumIITestCase> testCases = {
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
            auto nums = testCases[i].input; // solve on a copy
            auto got  = solver.twoSum(nums, testCases[i].target);
            assertEqVIntExact("Two Sum II 167 Test " + to_string(i + 1), testCases[i].expected, got);
        }
    }

    static void validPalindrome_125_tests() {
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
            assertEqScalar("Valid Palindrome 125 Test " + to_string(i + 1), testCases[i].expected, got);
        }
    }

    static void threeSum_15_tests() {
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
            auto got = solver.threeSum(testCases[i].input);
            assertEqVVIntAnyOrder("Three Sum 15 Test " + to_string(i + 1), testCases[i].expected, got);
        }
    }

    static void containerWithMostWater_11_tests() {
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
            int got = solver.maxArea(testCases[i].input);
            assertEqScalar("Container With Most Water 11 Test " + to_string(i + 1), testCases[i].expected, got);
        }
    }

    static void trappingRainWater_42_tests() {
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
            int got = solver.trap(testCases[i].input);
            assertEqScalar("Trapping Rain Water 42 Test " + to_string(i + 1), testCases[i].expected, got);
        }
    }

    static void maximalRectangle_85_tests() {
        vector<MaximalRectangleTestCase> testCases = {
            // ── three examples from the problem statement ──
            {{{'1','0','1','0','0'},
              {'1','0','1','1','1'},
              {'1','1','1','1','1'},
              {'1','0','0','1','0'}}, 6},
            {{{'0'}}, 0},
            {{{'1'}}, 1},

            // ── additional, larger & denser cases ──
            // 1) 8×8 block of 1 s → area 64
            {vector<vector<char>>(8, vector<char>(8, '1')), 64},

            // 2) 4×10 mixed grid (largest 5×4 block) → area 20
            {{{'1','1','1','1','1','0','0','0','1','1'},
              {'1','1','1','1','1','1','1','1','1','0'},
              {'1','1','1','1','1','1','1','1','0','0'},
              {'1','1','1','1','1','0','0','0','0','0'}}, 20}
        };

        MaximalRectangle_85 solver;
        for (size_t i = 0; i < testCases.size(); ++i) {
            int got = solver.maximalRectangle(testCases[i].matrix);
            assertEqScalar("Maximal Rectangle 85 Test " + to_string(i + 1), testCases[i].expected, got);
        }
    }

    static void maximumSubarray_53_tests() {
        vector<MaximumSubarrayTestCase> tc = {
            // 3 canonical LeetCode examples
            {{-2,1,-3,4,-1,2,1,-5,4}, 6},
            {{1}, 1},
            {{5,4,-1,7,8}, 23},

            // all-negative array → pick single largest element
            {{-8,-3,-6,-2,-5,-4}, -2},

            // larger mixed array (answer = 25, subarray [10, -2, 3, 14])
            {{-1,10,-2,3,14,-5,2}, 25}
        };

        MaximumSubarray_53 solver;
        for (size_t i = 0; i < tc.size(); ++i) {
            int got = solver.maxSubArray(tc[i].input);
            assertEqScalar("Maximum Subarray 53 Test " + to_string(i + 1), tc[i].expected, got);
        }
    }

    static void twoSum_1_tests() {
        vector<TwoSumCase> cases = {
            {{2, 7, 11, 15},               9,  {0, 1}},
            {{3, 2, 4},                    6,  {1, 2}},
            {{3, 3},                       6,  {0, 1}},
            // Added tougher / edge scenarios
            {{-10, -1, 0, 1, 2, 8},       -9,  {0, 3}},           // negative + positive mix
            {{1000000000, -1000000000, 3, 4, 8}, 12,  {3, 4}}     // 4 + 8
        };

        TwoSum_1 solver;
        for (size_t i = 0; i < cases.size(); ++i) {
            auto got = solver.twoSum(cases[i].input, cases[i].target);

            // Order-independent compare of index pairs
            auto expected = cases[i].expected;
            sort(got.begin(), got.end());
            sort(expected.begin(), expected.end());

            assertEqVIntExact("Two Sum 1 Test " + to_string(i + 1), expected, got);
        }
    }

    static void mergeSortedArray_88_tests() {
        vector<MergeCase> cases = {
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
            assertEqVIntExact(label, cases[i].expected, nums1);
        }
    }

    static void removeElement_27_tests() {
        vector<RemCase> cases = {
            {{3,2,2,3},           3, 2, {2,2}},           // example 1
            {{0,1,2,2,3,0,4,2},   2, 5, {0,0,1,3,4}},     // example 2
            {{},                  0, 0, {}},              // empty array
            {{1,1,1},             2, 3, {1,1,1}},         // value absent
            {{4,4,4},             4, 0, {}}               // all removed
        };

        RemoveElement_27 remover;
        for (size_t i = 0; i < cases.size(); ++i) {
            auto nums = cases[i].input;                // copy to mutate
            int  k    = remover.removeElement(nums, cases[i].val);

            // Compare length and (order-insensitive) contents of the kept prefix
            vector<int> got(nums.begin(), nums.begin() + k);
            auto        exp = cases[i].expected;
            sort(got.begin(), got.end());
            sort(exp.begin(), exp.end());

            const string base = "Remove Element 27 Test " + to_string(i + 1);
            assertEqScalar(base + " [k]", cases[i].expectedK, k);
            assertEqVIntExact(base + " [elems unordered]", exp, got);
        }
    }

    static void maximumNumberOfBalloons_1189_tests()
    {
        vector<BalloonCase> cases = {
            {"nlaebolko",            1},   // example 1
            {"loonbalxballpoon",     2},   // example 2
            {"leetcode",             0},   // example 3
            {"balloonballoon",       2},   // two exact words
            {"balon",                0}    // missing letters
        };

        MaximumNumberOfBalloons_1189 solver;
        for (size_t i = 0; i < cases.size(); ++i) {
            int got = solver.maxNumberOfBalloons(cases[i].input);
            assertEqScalar("Maximum Number of Balloons 1189 Test " + to_string(i + 1), cases[i].expected, got);
        }
    }

    static void addBinary_67_tests()
    {
        vector<ABCase> cases = {
            {"11",      "1",       "100"},      // example 1
            {"1010",    "1011",    "10101"},    // example 2
            {"0",       "0",       "0"},        // both zero
            {"1111",    "1",       "10000"},    // carry over entire length
            {"100",     "110010",  "110110"}    // different lengths
        };

        AddBinary_67 solver;
        for (size_t i = 0; i < cases.size(); ++i) {
            string got = solver.addBinary(cases[i].a, cases[i].b);
            assertEqScalar("Add Binary 67 Test " + to_string(i + 1), cases[i].expected, got);
        }
    }

    static void findPivotIndex_724_tests() {
        vector<PivotCase> cases = {
            {{1,7,3,6,5,6},  3},     // example 1
            {{1,2,3},       -1},     // example 2
            {{2,1,-1},       0},     // example 3
            {{0,0,0,0},      0},     // all zeros → first index
            {{-1,-1,0,1,1,0}, 5}     // negatives & duplicates
        };

        FindPivotIndex_724 solver;
        for (size_t i = 0; i < cases.size(); ++i) {
            int got = solver.pivotIndex(cases[i].input);
            assertEqScalar("Find Pivot Index 724 Test " + to_string(i + 1), cases[i].expected, got);
        }
    }

    static void numberOf1Bits_191_tests()
    {
        vector<HWCase> cases = {
            {11u,          3},          // 1011
            {128u,         1},          // 10000000
            {2147483645u, 30},          // 0x7FFFFFFD
            {0u,           0},          // edge: zero
            {0xFFFFFFFFu, 32}           // all ones
        };

        NumberOf1Bits_191 solver;
        for (size_t i = 0; i < cases.size(); ++i) {
            int got = solver.hammingWeight(cases[i].n);
            assertEqScalar("Number of 1 Bits 191 Test " + to_string(i + 1) +
                           " (n=" + to_string(cases[i].n) + ")", cases[i].expected, got);
        }
    }

    static void decodeString_GoogleOnsite_tests() {
        vector<DecodeStringTestCase> testCases = {
            {"ab[cd]{2}",                   "abcdcd"},
            {"def[ab[cd]{2}]{3}ghi",        "defabcdcdabcdcdabcdcdghi"},
            {"x[y[z]{2}w]{3}",              "xyzzwyzzwyzzw"},
            {"[ab]{2}[cd]{2}",              "ababcdcd"},
            {"plain",                       "plain"},
            {"[a]{5}",                      "aaaaa"}
        };

        DecodeString_GoogleOnsite solver;
        for (size_t i = 0; i < testCases.size(); ++i) {
            string got = solver.decode(testCases[i].input);
            assertEqScalar("Decode String (Google Onsite) Test " + to_string(i + 1), testCases[i].expected, got);
        }
    }

    static void wildcardMatching_44_tests() {
        vector<WildcardMatchingTestCase> tc = {
            /* three examples from the statement */
            {"aa", "a",       false},
            {"aa", "*",       true },
            {"cb", "?a",      false},
            /* three extra / harder cases */
            {"adceb",         "*a*b",        true },
            {"acdcb",         "a*c?b",       false},
            {"abcabczzzde",   "*abc???de*",  true },
            {"baaaacxyz",     "*a*?xyz",     true },
            {"abcded",        "a*d",         true },
            {"abcdbcde",      "a*de",        true },
        };

        WildcardMatching_44 solver;
        for (size_t i = 0; i < tc.size(); ++i) {
            bool got = solver.isMatch(tc[i].s, tc[i].p);
            assertEqScalar("Wildcard Matching 44 Test " + to_string(i + 1), tc[i].expected, got);
        }
    }

    static void kClosestPointsToOrigin_973_tests() {
        vector<KClosestTestCase> cases = {
            // Two official examples
            {{{1,3}, {-2,2}}, 1, {{-2,2}}},
            {{{3,3}, {5,-1}, {-2,4}}, 2, {{3,3}, {-2,4}}},

            // Three extra, trickier cases
            // 1) Many symmetrically placed points, ask for almost all
            {{{0,1}, {1,0}, {-1,0}, {0,-1}}, 3,
                            {{0,1}, {1,0}, {-1,0}}},
            // 2) Points at extreme coordinates
            {{{10000,10000}, {-10000,-10000}, {5000,0}, {0,5000}}, 2,
                            {{5000,0}, {0,5000}}},
            // 3) Mixed positives and negatives, k near n
            {{{2,2}, {1,1}, {3,3}, {-2,-2}, {-1,-1}}, 4,
                            {{-2,-2}, {-1,-1}, {1,1}, {2,2}}}
        };

        KClosestPointsToOrigin_973 solver;
        for (size_t i = 0; i < cases.size(); ++i) {
            // QuickSelect
            auto in1  = cases[i].points;                 // solver may mutate
            auto out1 = solver.kClosestQuickSelect(in1, cases[i].k);
            assertEqScalar("K Closest 973 Test " + to_string(i + 1) + " [QuickSelect]", true,
                isValidKClosestPoints(cases[i].points, cases[i].k, out1));

            // Heap
            auto in2  = cases[i].points;
            auto out2 = solver.kClosestHeap(in2, cases[i].k);
            assertEqScalar("K Closest 973 Test " + to_string(i + 1) + " [Heap]", true,
                isValidKClosestPoints(cases[i].points, cases[i].k, out2));
        }
    }

    static void uniquePaths_62_tests() {
        vector<UniquePaths62TestCase> cases = {
            /* three official cases from the problem statement */
            {3, 7, 28},
            {3, 2, 3},
            {1, 1, 1},
            /* two more demanding cases – still ≤ 2 000 000 000 */
            {12, 23, 193536720},
            {8, 69, 1984829850}
        };

        UniquePaths_62 solver;
        for (size_t i = 0; i < cases.size(); ++i) {
            int got = solver.uniquePaths(cases[i].m, cases[i].n);
            assertEqScalar(
                "Unique Paths 62 Test " + to_string(i + 1) +
                " (m=" + to_string(cases[i].m) + ", n=" + to_string(cases[i].n) + ")",
                cases[i].expected, got
            );
        }
    }

    static void busRoutes_815_tests() {
        vector<BusRoutesTestCase> cases = {
            // Official examples
            {{{1,2,7},{3,6,7}}, 1, 6, 2},
            {{{7,12},{4,5,15},{6},{15,19},{9,12,13}}, 15, 12, -1},
            // Additional tougher cases
            {{{1,2,3,4,5},{5,6,7,8},{8,9,10,11},{11,12,13,1}}, 1, 13, 1},
            {{{1,2,3},{4,5,6}}, 5, 5, 0},
            {{{1,2,3},{3,4,5},{5,6,7},{7,8,9}}, 2, 8, 4}
        };

        BusRoutes_815 solver;
        for (size_t i = 0; i < cases.size(); ++i) {
            auto routes = cases[i].routes; // solver may mutate
            int got = solver.numBusesToDestination(routes, cases[i].source, cases[i].target);
            assertEqScalar("Bus Routes 815 Test " + to_string(i + 1), cases[i].expected, got);
        }
    }

    static void shortestPathBinaryMatrix_1091_tests() {
        vector<ShortestPathTestCase> testCases = {
            /* 3 examples from the problem statement */
            {
             {{0, 1},
              {1, 0}},
             2},
            {
             {{0, 0, 0},
              {1, 1, 0},
              {1, 1, 0}},
             4},
            {
             {{1, 0, 0},
              {1, 1, 0},
              {1, 1, 0}},
             -1},
            /* 2 extra, larger cases */
            {
              {{0, 0, 0, 0, 0},
              {1, 1, 1, 1, 0},
              {0, 0, 0, 1, 0},
              {0, 1, 0, 1, 0},
              {0, 1, 0, 0, 0}},
             8}, // reachable
            {
             {{0, 1, 1, 1, 1},
              {1, 1, 1, 1, 1},
              {1, 1, 1, 1, 1},
              {1, 1, 1, 1, 1},
              {1, 1, 1, 1, 0}},
             -1} // unreachable
        };

        ShortestPathInBinaryMatrix_1091 solver;
        for (size_t i = 0; i < testCases.size(); ++i) {
            auto grid = testCases[i].grid;  // solver mutates the grid
            int got = solver.shortestPathBinaryMatrix(grid);
            assertEqScalar("Shortest Path Binary Matrix 1091 Test " + to_string(i + 1), testCases[i].expected, got);
        }
    }

    static void designGraphWithShortestPathCalculator_2642_tests() {
        using EdgeList = vector<vector<int>>;

        vector<GraphTC> testCases = {
            // Case 1 – official example
            {
                {"Graph","shortestPath","shortestPath","addEdge","shortestPath"},
                {
                    pair<int,EdgeList>{4, {{0,2,5},{0,1,2},{1,2,1},{3,0,3}}},
                    pair<int,int>{3,2},
                    pair<int,int>{0,3},
                    vector<int>{1,3,4},
                    pair<int,int>{0,3}
                },
                {nullopt, 6, -1, nullopt, 6}
            },
            // Case 2 – empty graph, then one edge
            {
                {"Graph","shortestPath","addEdge","shortestPath"},
                {
                    pair<int,EdgeList>{2, {}},
                    pair<int,int>{0,1},
                    vector<int>{0,1,10},
                    pair<int,int>{0,1}
                },
                {nullopt, -1, nullopt, 10}
            },
            // Case 3 – cheaper path appears after addEdge
            {
                {"Graph","shortestPath","addEdge","shortestPath"},
                {
                    pair<int,EdgeList>{5, {{0,1,3},{1,2,4},{2,3,5},{3,4,6},{0,4,20}}},
                    pair<int,int>{0,4},
                    vector<int>{1,4,1},
                    pair<int,int>{0,4}
                },
                {nullopt, 18, nullopt, 4}
            }
        };

        for (size_t t = 0; t < testCases.size(); ++t) {
            unique_ptr<Graph> g;
            const auto& tc = testCases[t];

            for (size_t i = 0; i < tc.operations.size(); ++i) {
                const string& op = tc.operations[i];

                if (op == "Graph") {
                    auto [n, edges] = get<pair<int,EdgeList>>(tc.arguments[i]);
                    g = make_unique<Graph>(n, edges);
                } else if (op == "addEdge") {
                    g->addEdge(get<vector<int>>(tc.arguments[i]));
                } else if (op == "shortestPath") {
                    auto [u, v] = get<pair<int,int>>(tc.arguments[i]);
                    int got = g->shortestPath(u, v);
                    const string label = makeStepLabel("Graph_2642", t, i, "shortestPath",
                        to_string(u) + "," + to_string(v));
                    assertEqScalar(label, tc.expected[i].value(), got);
                }
            }
        }
    }

    static void findTheSafestPathInGrid_2812_tests() {
        vector<SafestPathTestCase> testCases = {
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
            int got = solver.maximumSafenessFactor(testCases[i].grid);
            assertEqScalar("Safest Path 2812 Test " + to_string(i + 1), testCases[i].expected, got);
        }
    }

    static void maximumDepthOfBinaryTree_104_tests() {
        vector<MaxDepthTestCase> testCases = {
            // two examples from the problem statement
            {{3, 9, 20, nullopt, nullopt, 15, 7}, 3},
            {{1, nullopt, 2},                     2},

            // three extra, increasingly tricky, cases
            // (a) irregular but shallow left/right mix – depth 4
            {{1, 2, 3, 4, nullopt, nullopt, 5, nullopt, 6}, 4},
            // (b) strongly left-skewed – depth 5
            {{1, 2, nullopt, 3, nullopt, 4, nullopt, 5}, 5},
            // (c) empty tree – depth 0
            {{}, 0}
        };

        MaximumDepthOfBinaryTree_104 solver;
        for (size_t i = 0; i < testCases.size(); ++i) {
            TreeNode<int>* root = TreeUtils::vectorToTree<int>(testCases[i].tree);

            int dRec = solver.maxDepthRecursive(root);
            int dStk = solver.maxDepthDFSStack(root);
            int dBfs = solver.maxDepthBFSQueue(root);

            const string base = "Max Depth 104 Test " + to_string(i + 1);
            assertEqScalar(base + " [recursive]", testCases[i].expected, dRec);
            assertEqScalar(base + " [DFS stack]", testCases[i].expected, dStk);
            assertEqScalar(base + " [BFS queue]", testCases[i].expected, dBfs);

            TreeUtils::freeTree(root);
        }
    }

    static void wallsAndGates_286_tests() {
        const int INF = 2147483647;          // 2^31-1

        vector<WallsAndGatesTestCase> testCases = {
            // Example 1
            {
                {{INF, -1, 0,   INF},
                {INF, INF, INF, -1},
                {INF, -1,  INF, -1},
                {0,   -1,  INF, INF}},
                {{3, -1, 0, 1},
                {2, 2, 1, -1},
                {1, -1, 2, -1},
                {0, -1, 3, 4}}
            },
            // Example 2
            {
                {{0, INF}},
                {{0, 1}}
            },
            // Example 3
            {
                {{INF}},
                {{INF}}
            },
            // Complex 1: 4×4 grid, two gates
            {
                {{0,   INF, INF, INF},
                {INF, -1,  INF, INF},
                {INF, INF, INF, 0  },
                {INF, -1,  INF, INF}},
                {{0, 1, 2, 2},
                {1, -1, 2, 1},
                {2, 2, 1, 0},
                {3, -1, 2, 1}}
            },
            // Complex 2: unreachable rooms stay INF
            {
                {{INF, -1, 0,   INF, INF},
                {-1,  INF, -1, INF, -1 },
                {INF, -1,  INF, -1, INF}},
                {{INF, -1, 0, 1, 2},
                {-1,  INF, -1, 2, -1},
                {INF, -1,  INF, -1, INF}}
            }
        };

        WallsAndGates_286 solver;
        for (size_t i = 0; i < testCases.size(); ++i) {
            auto rooms = testCases[i].rooms;    // copy so we can mutate
            solver.wallsAndGates(rooms);
            assertEqVVIntExact("Walls & Gates 286 Test " + to_string(i + 1), testCases[i].expected, rooms);
        }
    }

    static void validNumber_65_tests() {
        vector<ValidNumberTestCase> testCases = {
            {"0",              true},   // example 1
            {"e",              false},  // example 2
            {".",              false},  // example 3
            {"2",              true},
            {"0089",           true},
            {"-0.1",           true},
            {"+3.14",          true},
            {"4.",             true},
            {"-.9",            true},
            {"2e10",           true},
            {"-90E3",          true},
            {"3e+7",           true},
            {"+6e-1",          true},
            {"53.5e93",        true},
            {"-123.456e789",   true},
            {"abc",            false},
            {"1a",             false},
            {"99e2.5",         false}
        };

        ValidNumber_65 solver;
        for (size_t i = 0; i < testCases.size(); ++i) {
            bool got = solver.isNumber(testCases[i].input);
            assertEqScalar("Valid Number 65 Test " + to_string(i + 1) + " [\"" + testCases[i].input + "\"]",
                testCases[i].expected, got);
        }
    }

    static void numJewelsAndStones_771_tests() {
        vector<JewelsAndStonesTestCase> testCases = {
            // Problem-statement examples
            {"aA", "aAAbbbb", 3},
            {"z",  "ZZ",      0},

            // Extra, more demanding cases
            {"abc", "aabbccABCabc",                    9},
            {"abcdefghijklmnopqrstuvwxyz",
             "abcdefghijklmnopqrstuvwxyzABCDEFGHIJ",  26},
            {"Aa",  "aaaaaaaaAAAAAAAaA",              17}
        };

        JewelsAndStones_771 solver;
        for (size_t i = 0; i < testCases.size(); ++i) {
            int got = solver.numJewelsInStones(testCases[i].jewels, testCases[i].stones);
            assertEqScalar("Jewels & Stones 771 Test " + to_string(i + 1), testCases[i].expected, got);
        }
    }

    static void validPerfectSquare_367_tests() {
        vector<PerfectSquareTestCase> cases = {
            {16,          true},    // example 1
            {14,          false},   // example 2
            {2147395600,  true},    // 46340² – largest 32-bit square
            {2147483647,  false},   // INT_MAX – not a square
            {808201,      true}     // 899² – non-trivial perfect square
        };

        ValidPerfectSquare_367 solver;
        for (size_t i = 0; i < cases.size(); ++i) {
            bool got = solver.isPerfectSquare(cases[i].input);
            assertEqScalar("Valid Perfect Square 367 Test " + to_string(i + 1), cases[i].expected, got);
        }
    }

    static void perfectSquares_279_tests() {
        // 2 from the problem + 3 more complex (incl. edge n = 10^4)
        vector<PerfectSquares279TestCase> testCases = {
            {12,    3},  // Example 1: 12 = 4 + 4 + 4
            {13,    2},  // Example 2: 13 = 9 + 4
            {3000,  3},  // 3 squares (e.g., 3000 = 1600 + 900 + 500)
            {9991,  4},  // Legendre form (4^a(8b+7)) ⇒ needs 4 squares
            {10000, 1}   // Edge case (max n): 10000 = 100^2
        };

        PerfectSquares_279 solver;
        for (size_t i = 0; i < testCases.size(); ++i) {
            int got = solver.numSquares(testCases[i].input);
            assertEqScalar("Perfect Squares 279 Test " + to_string(i + 1), testCases[i].expected, got);
        }
    }

    static void sameTree_100_tests()
    {
        vector<SameTreeTestCase> cases = {
            // Examples
            { {1, 2, 3},                  {1, 2, 3},                  true  }, // Example 1
            { {1, 2},                     {1, nullopt, 2},            false }, // Example 2
            { {1, 2, 1},                  {1, 1, 2},                  false }, // Example 3

            // A few extra sanity checks
            { {},                         {},                         true  },
            { {1, nullopt, 2, 3},         {1, nullopt, 2, 3},         true  },
            {
                {10, nullopt, 20, 15, nullopt, nullopt, 25, nullopt, nullopt, 22, nullopt},
                {10, nullopt, 20, 15, nullopt, nullopt, 25, nullopt, nullopt, 22, nullopt},
                true
            },
        };

        SameTree_100 sol;
        for (size_t i = 0; i < cases.size(); ++i) {
            auto* p = TreeUtils::vectorToTree<int>(cases[i].p);
            auto* q = TreeUtils::vectorToTree<int>(cases[i].q);

            const string base = "SameTree_100 Test " + to_string(i + 1);

            bool g1 = sol.isSameTreeRecursive(p, q);
            bool g2 = sol.isSameTreeIterativeDFS(p, q);
            bool g3 = sol.isSameTreeBFSQueue(p, q);

            assertEqScalar(base + " [recursive]",     cases[i].expected, g1);
            assertEqScalar(base + " [iterative DFS]", cases[i].expected, g2);
            assertEqScalar(base + " [BFS queue]",     cases[i].expected, g3);

            TreeUtils::freeTree(p);
            TreeUtils::freeTree(q);
        }
    }

    static void missingNumber_268_tests() {
        vector<MissingNumberTestCase> testCases = {
            // Problem statement examples
            {{3, 0, 1}, 2},
            {{0, 1}, 2},
            {{9, 6, 4, 2, 3, 5, 7, 0, 1}, 8},

            // Additional edge/complex cases
            {{1, 2, 3}, 0},                 // missing 0
            {{0, 1, 2, 3}, 4},              // missing n
            {{10, 9, 8, 7, 5, 4, 3, 2, 1, 0}, 6} // unsorted, includes n
        };

        MissingNumber_268 solution;
        for (size_t i = 0; i < testCases.size(); ++i) {
            int got = solution.missingNumber(testCases[i].input);
            assertEqScalar("Missing Number 268 Test " + to_string(i + 1), testCases[i].expected, got);
        }
    }

    static void dailyTemperatures_739_tests() {
        vector<DailyTemperatures739TestCase> tests = {
            // Three examples from the problem statement
            {{73,74,75,71,69,72,76,73}, {1,1,4,2,1,1,0,0}},
            {{30,40,50,60},             {1,1,1,0}},
            {{30,60,90},                 {1,1,0}},

            // Three additional, more complex cases
            {{100,99,98,97},             {0,0,0,0}},            // strictly decreasing: no warmer future day
            {{70,70,71},                 {2,1,0}},              // plateau followed by a warmer day
            {{75,71,69,72,76,73,73,74,75},{4,2,1,1,0,2,1,1,0}}  // mixed drops, duplicates, multiple pops
        };

        DailyTemperatures_739 solver;
        for (size_t i = 0; i < tests.size(); ++i) {
            auto got = solver.dailyTemperatures(tests[i].input);
            assertEqVIntExact("Daily Temperatures 739 Test " + to_string(i + 1), tests[i].expected, got);
        }
    }

    static void containsDuplicate_217_tests() {
        vector<ContainsDuplicate217TestCase> tests = {
            // 3 from the statement
            {{1, 2, 3, 1}, true},
            {{1, 2, 3, 4}, false},
            {{1, 1, 1, 3, 3, 4, 3, 2, 4, 2}, true},

            // 3 “complex”/edge-ish
            // extremes + duplicate far apart
            {{1000000000, -1000000000, 999999999, -999999999, 123456789, 987654321, 123456789}, true},
            // negative/zero/positive with early & late dup
            {{-7, 0, 5, 42, -7}, true},
            // large unique set
            {{}, false} // placeholder, will be replaced by bigUnique below
        };

        // Build a large unique vector [-5000..4999]
        vector<int> bigUnique(10000);
        iota(bigUnique.begin(), bigUnique.end(), -5000);
        tests.push_back({ move(bigUnique), false });

        ContainsDuplicate_217 sol;

        for (size_t i = 0; i < tests.size(); ++i) {
            bool got = sol.containsDuplicate(tests[i].input);
            assertEqScalar("ContainsDuplicate 217 Test " + to_string(i + 1), tests[i].expected, got);
        }

        // Stress: large array + one duplicate appended
        vector<int> bigWithDup(10000);
        iota(bigWithDup.begin(), bigWithDup.end(), -5000);
        bigWithDup.push_back(123); // duplicate
        bool got = sol.containsDuplicate(bigWithDup);
        assertEqScalar("ContainsDuplicate 217 Stress", true, got);
    }

    static void fibonacci_509_tests() {
        vector<Fibonacci509TestCase> tests = {
            // 3 from the statement
            {2, 1},
            {3, 2},
            {4, 3},
            // 3 additional / edge-ish
            {0, 0},
            {1, 1},
            {30, 832040}
        };

        FibonacciNumber_509 sol;
        for (size_t i = 0; i < tests.size(); ++i) {
            int got = sol.fib(tests[i].n);
            assertEqScalar("Fibonacci 509 Test " + to_string(i + 1) + " (n=" + to_string(tests[i].n) + ")",
                tests[i].expected, got);
        }
    }

    static void climbingStairs_70_tests() {
        vector<ClimbingStairs70TestCase> tests = {
            // 2 from the statement
            {2, 2},
            {3, 3},

            // 4 additional / edge-ish
            {1, 1},
            {4, 5},
            {10, 89},
            {45, 1836311903}
        };

        ClimbingStairs_70 sol;
        for (size_t i = 0; i < tests.size(); ++i) {
            int got = sol.climbStairs(tests[i].n);
            assertEqScalar("Climbing Stairs 70 Test " + to_string(i + 1) + " (n=" + to_string(tests[i].n) + ")",
                tests[i].expected, got);
        }
    }

    static void minCostClimbingStairs_746_tests() {
        vector<MinCostClimbingStairs746TestCase> tests = {
            // 2 from the statement
            {{10,15,20}, 15},
            {{1,100,1,1,1,100,1,1,100,1}, 6},

            // 4 additional / edge-ish
            {{5, 6}, 5},                         // n=2, pick cheaper start
            {{0,0,0,0}, 0},                      // all zeros
            {{2,2,2,2,2}, 4},                    // uniform costs
            {{999,1,999,1,999,1,999,1}, 4}       // pick all the 1's
        };

        MinCostClimbingStairs_746 sol;
        for (size_t i = 0; i < tests.size(); ++i) {
            int got = sol.minCostClimbingStairs(tests[i].cost);
            assertEqScalar("Min Cost Climbing Stairs 746 Test " + to_string(i + 1), tests[i].expected, got);
        }
    }

    static void houseRobber_198_tests() {
        vector<HouseRobber198TestCase> tests = {
            // 2 from the statement
            {{1,2,3,1}, 4},
            {{2,7,9,3,1}, 12},

            // 4 additional / edge-ish
            {{2,1,1,2}, 4},                 // choose 2 + 2
            {{0,0,0,0,0}, 0},               // all zeros
            {{6,6,4,8,4,3,3,10}, 27},       // mixed values
            {{100}, 100}                    // single element
        };

        HouseRobber_198 sol;
        for (size_t i = 0; i < tests.size(); ++i) {
            int got = sol.rob(tests[i].input);
            assertEqScalar("House Robber 198 Test " + to_string(i + 1), tests[i].expected, got);
        }
    }

    static void lastStoneWeight_1046_tests() {
        vector<LastStoneWeight1046TestCase> tests = {
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
            int got = sol.lastStoneWeight(tests[i].input);
            assertEqScalar("Last Stone Weight 1046 Test " + to_string(i + 1), tests[i].expected, got);
        }
    }

    static void topKFrequent_347_tests() {
        // helper: build a multiset vector from (value,count) pairs
        auto bag = [](initializer_list<pair<int,int>> spec) {
            vector<int> v; size_t tot = 0;
            for (auto [val,c]: spec) tot += c;
            v.reserve(tot);
            for (auto [val,c]: spec) v.insert(v.end(), c, val);
            return v;
        };

        vector<TopKFrequent347TestCase> tests = {
            {{1,1,1,2,2,3}, 2, {1,2}},
            {{1},           1, {1}},
            {{1,1,2,2,2,3}, 1, {2}},
            {{-1,-1,-1,0,0,2,2,2,2,3,3}, 2, {2,-1}},
            // 7×7, 6×8, 5×9, 4×10, 3×11  -> k=3 => {7,8,9}
            { bag({{7,7},{8,6},{9,5},{10,4},{11,3}}), 3, {7,8,9} },
            // 42×100, -7×80, plus 1000 uniques -> k=2 => {42,-7}
            { [&]{
                auto v = bag({{42,100},{-7,80}});
                v.resize(v.size()+1000);
                iota(v.end()-1000, v.end(), 10001);
                return v;
            }(), 2, {42,-7} }
        };

        TopKFrequentElements_347 sol;
        for (size_t i = 0; i < tests.size(); ++i) {
            auto got = sol.topKFrequent(tests[i].input, tests[i].k);
            auto e   = tests[i].expected;
            sort(got.begin(), got.end());
            sort(e.begin(),   e.end());
            assertEqVIntExact("Top K Frequent 347 Test " + to_string(i+1) + " (k=" + to_string(tests[i].k) + ")", e, got);
        }
    }

    static void findClosestNumber_2239_tests() {
        vector<FindClosest2239TestCase> tests = {
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
            int got = sol.findClosestNumber(tests[i].input);
            const string label = "Find Closest Number to Zero 2239 Test " + to_string(i + 1);
            assertEqScalar(label, tests[i].expected, got);
        }
    }

    static void mergeStringsAlternately_1768_tests() {
        vector<MergeStringsAlternately1768TestCase> tests = {
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
            string got = sol.mergeAlternately(tests[i].a, tests[i].b);
            const string label = "Merge Strings Alternately 1768 Test " + to_string(i + 1);
            assertEqScalar(label, tests[i].expected, got);
        }
    }

    static void romanToInteger_13_tests() {
        vector<RomanToInteger13TestCase> tests = {
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
            const string label = "Roman to Integer 13 Test " + to_string(i + 1) + " [\"" + tests[i].input + "\"]";
            assertEqScalar(label, tests[i].expected, got);
        }
    }

    static void isSubsequence_392_tests() {
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
            assertEqScalar(base + " [two-pointer]", tests[i].expected, a);
            assertEqScalar(base + " [pos-index]",   tests[i].expected, b);
            assertEqScalar(base + " [next-table]",  tests[i].expected, c);
            assertEqScalar(base + " [consistency pos vs next]", b, c);
        }

        // Follow-up: many queries for the same t (reuse preprocessed data)
        vector<IsSubsequence392FollowUpCase> futests = {
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

                const string base = "Is Subsequence 392 FU " + to_string(b + 1) + " Q" + to_string(qi + 1);
                assertEqScalar(base + " [two-pointer]", expected, a);
                assertEqScalar(base + " [pos-index]",   expected, p);
                assertEqScalar(base + " [next-table]",  expected, n);
                assertEqScalar(base + " [consistency pos vs next]", p, n);
            }
        }
    }

    // Big test focusing on next-position DP (also cross-check pos-index)
    static void isSubsequence_392_nextpos_tests() {
        string t;
        t.reserve(10000);
        for (int i = 0; i < 10000; ++i) t.push_back(char('a' + (i % 26)));

        IsSubsequence_392 idxNext, idxPos;
        idxNext.preprocess_NextTable(t);
        idxPos.preprocess_PosIndex(t);

        struct Q { string s; bool expected; };
        vector<Q> qs;
        {
            string s;
            s.reserve(26 * 100);
            for (int rep = 0; rep < 100; ++rep)
                for (char c = 'a'; c <= 'z'; ++c) s.push_back(c);
            qs.push_back({move(s), true});
        }
        qs.push_back({string(384, 'z'), true});
        qs.push_back({string(385, 'z'), false});
        qs.push_back({"leetcode", true});
        qs.push_back({"zzzay", true});
        qs.push_back({"", true});

        for (size_t i = 0; i < qs.size(); ++i) {
            bool gotN = idxNext.isSubsequence_NextTable(qs[i].s);
            bool gotP = idxPos .isSubsequence_PosIndex(qs[i].s);

            const string base = "Is Subsequence 392 Big Test " + to_string(i + 1);

            assertEqScalar(base + " [NextTable]", qs[i].expected, gotN);
            assertEqScalar(base + " [PosIndex]",  qs[i].expected, gotP);
            assertEqScalar(base + " [Consistency]", gotN, gotP);
        }
    }

    static void longestCommonPrefix_14_tests() {
        vector<LongestCommonPrefix14TestCase> tcs = {
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
            string got  = sol.longestCommonPrefix_Linear(tcs[i].strs);
            string got2 = sol.longestCommonPrefix_Sort(tcs[i].strs); // cross-check

            if (got != got2) {
                cout << "[WARN] LCP variants disagree on case " << (i + 1)
                    << "  primary=\"" << got << "\" sort=\"" << got2 << "\"\n";
            }

            assertEqScalar("LCP14 Test " + to_string(i + 1), tcs[i].expected, got);
        }
    }

    static void summaryRanges_228_tests() {
        vector<SummaryRanges228TestCase> tests = {
            {{0,1,2,4,5,7},                  {"0->2","4->5","7"}},
            {{0,2,3,4,6,8,9},                {"0","2->4","6","8->9"}},
            {{},                              {}},
            {{5},                             {"5"}},
            {{-3,-2,-1,0,2},                 {"-3->0","2"}},
            {{INT_MAX-1, INT_MAX},           {to_string(INT_MAX-1) + "->" + to_string(INT_MAX)}},
            {{INT_MIN, INT_MIN+1, INT_MIN+3},{to_string(INT_MIN) + "->" + to_string(INT_MIN+1), to_string(INT_MIN+3)}},
            {{1,3,5},                         {"1","3","5"}}
        };

        SummaryRanges_228 sol;
        for (size_t i = 0; i < tests.size(); ++i) {
            auto in  = tests[i].nums;              // method takes non-const ref
            auto got = sol.summaryRanges(in);
            assertEqStrings("Summary Ranges 228 Test " + to_string(i + 1), tests[i].expected, got);
        }
    }

    static void removeDuplicates_26_tests() {
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
            a = tests[i].nums;                      // the solver mutates in place
            int k = sol.removeDuplicates(a);
            assertEqVIntPrefix("Remove Duplicates 26 Test " + to_string(i + 1), tests[i].expected, a, k);
        }
    }

    static void jumpGameII_45_tests() {
        vector<JumpGameII45TestCase> tests = {
            {{2,3,1,1,4}, 2},            // example 1
            {{2,3,0,1,4}, 2},            // example 2
            {{0}, 0},                    // single element
            {{1}, 0},                    // single element
            {{1,1,1,1}, 3},              // need to hop each step
            {{5,0,0,0,0}, 1},            // one jump covers all
            {{1,4,1,1,1,1}, 2},          // to index 1, then to end
            {{3,2,1}, 1},                // first jump reaches the end
            {{9,8,7,6,5,4,3,2,1,0}, 1}   // giant first jump
        };

        JumpGameII_45 sol;
        for (size_t i = 0; i < tests.size(); ++i) {
            auto arr = tests[i].nums;           // method takes non-const ref
            int got = sol.jump(arr);
            assertEqScalar("Jump Game II 45 Test " + to_string(i + 1), tests[i].expected, got);
        }
    }

    static void jumpGame_55_tests() {
        vector<JumpGame55TestCase> tests = {
            {{2,3,1,1,4}, true},     // example 1
            {{3,2,1,0,4}, false},    // example 2
            {{0}, true},             // single element is trivially reachable
            {{1}, true},
            {{1,0,1}, false},        // stuck at index 1
            {{2,0}, true},           // one jump to end
            {{2,0,0}, true},         // reach=2 at i=0 covers the end
            {{1,1,0,1}, false},      // stuck at index 2
            {{5,0,0,0,0}, true},     // first jump covers all
            {{2,5,0,0}, true},       // reach grows via index 1
            {{2,0,2,0,1}, true},     // detours but reachable
            {{2,0,1,0,0}, false}     // reach stalls before the end
        };

        JumpGame_55 sol;
        for (size_t i = 0; i < tests.size(); ++i) {
            auto arr = tests[i].nums;                  // method takes non-const ref
            bool got = sol.canJump(arr);
            const string label = "Jump Game 55 Test " + to_string(i + 1);
            assertEqScalar(label, tests[i].expected, got);
        }
    }

    static void subsets_78_tests() {
        vector<Subsets78TestCase> tests = {
            // Example 1 (mask order for the bitmask method)
            {{1,2,3}, { {}, {1}, {2}, {1,2}, {3}, {1,3}, {2,3}, {1,2,3} }},
            // Example 2
            {{0},     { {}, {0} }},
            // Additional
            {{5,6},   { {}, {5}, {6}, {5,6} }},
            {{-1,2},  { {}, {-1}, {2}, {-1,2} }},
        };

        Subsets_78 sol;

        // Reuse these to avoid extra scopes.
        vector<int> in;
        vector<vector<int>> got;

        for (size_t i = 0; i < tests.size(); ++i) {
            // Bitmask variant: exact order comparison (matches mask enumeration order).
            in  = tests[i].nums;               // solver takes non-const ref by project style
            got = sol.subsets_bitmask(in);
            assertEqVVIntExact("Subsets 78 (bitmask) Test " + to_string(i + 1), tests[i].expected, got);

            // Recursive/backtracking variant: order-insensitive comparison.
            in  = tests[i].nums;
            got = sol.subsets_recursive(in);
            assertEqVVIntAnyOrder("Subsets 78 (recursive) Test " + to_string(i + 1), tests[i].expected, got);
        }
    }

    static void permutations_46_tests() {
        vector<Permutations46TestCase> tests = {
            {{1,2,3}, {{1,2,3},{1,3,2},{2,1,3},{2,3,1},{3,1,2},{3,2,1}}},
            {{0,1},   {{0,1},{1,0}}},
            {{1},     {{1}}},
            {{-1,2},  {{-1,2},{2,-1}}},
        };

        Permutations_46 sol;
        for (size_t i = 0; i < tests.size(); ++i) {
            auto in  = tests[i].nums;               // method takes non-const ref
            auto got = sol.permute(in);
            assertEqVVIntPermutations("Permutations 46 Test " + to_string(i + 1), tests[i].expected, got);
        }
    }

    static void combinations_77_tests() {
        vector<Combinations77TestCase> tests = {
            {4, 2, {{1,2},{1,3},{1,4},{2,3},{2,4},{3,4}}},
            {1, 1, {{1}}},
            {3, 1, {{1},{2},{3}}},
            {3, 3, {{1,2,3}}},
            {5, 3, {{1,2,3},{1,2,4},{1,2,5},{1,3,4},{1,3,5},
                    {1,4,5},{2,3,4},{2,3,5},{2,4,5},{3,4,5}}},
        };

        Combinations_77 sol;
        for (size_t i = 0; i < tests.size(); ++i) {
            auto got = sol.combine(tests[i].n, tests[i].k);
            assertEqVVIntAnyOrder("Combinations 77 Test " + to_string(i + 1), tests[i].expected, got);
        }
    }

    static void letterCombinations_17_tests() {
        vector<LetterCombinations17TestCase> tests = {
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
            assertEqStringsAnyOrder("Letter Combinations 17 Test " + to_string(i + 1), tests[i].expected, got);
        }
    }

    static void combinationSum_39_tests() {
        vector<CombinationSum39TestCase> tests = {
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
            assertEqVVIntAnyOrder("Combination Sum 39 Test " + to_string(i + 1), tests[i].expected, got);
        }
    }

    static void generateParentheses_22_tests() {
        vector<GenerateParentheses22TestCase> tests = {
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
            assertEqStringsAnyOrder("Generate Parentheses 22 Test " + to_string(i + 1), tests[i].expected, got);
        }
    }

    static void examRoom_855_tests() {
        // Case 1: EXACT sequence from the statement.
        ExamRoomTestCase c1{
            /* ops */ {"ExamRoom", "seat", "seat", "seat", "seat", "leave", "seat"},
            /* args*/ {{10},        {},      {},      {},      {},      {4},    {}},
            /* exp */ {nullopt,      0,       9,       4,       2,      nullopt, 5}
        };

        // Case 2: Edges cleared then re-filled; checks tie-breaking and edges.
        // n = 8
        // seat -> 0; seat -> 7; seat -> 3; leave(0); leave(7); seat -> 7; seat -> 0; seat -> 5
        ExamRoomTestCase c2{
            /* ops */ {"ExamRoom", "seat", "seat", "seat", "leave", "leave", "seat", "seat", "seat"},
            /* args*/ {{8},         {},     {},     {},     {0},     {7},     {},     {},     {}},
            /* exp */ {nullopt,      0,      7,      3,     nullopt, nullopt,  7,      0,      5}
        };

        // Case 3: Interleaved interior leaves and inserts; exercises mid-splits.
        // n = 10
        ExamRoomTestCase c3{
            /* ops */ {"ExamRoom", "seat","seat","seat","seat","leave","seat","leave","seat","seat","leave","seat"},
            /* args*/ {{10},        {},    {},    {},    {},    {4},    {},    {2},    {},    {},    {5},    {}},
            /* exp */ {nullopt,      0,     9,     4,     2,    nullopt, 5,    nullopt, 2,     7,    nullopt, 4}
        };

        vector<ExamRoomTestCase> cases = {c1, c2, c3};

        for (size_t t = 0; t < cases.size(); ++t) {
            optional<ExamRoom_855> er;
            const auto& C = cases[t];

            for (size_t i = 0; i < C.operations.size(); ++i) {
                const string& op = C.operations[i];
                const auto&    a = C.arguments[i];
                const auto&   ex = C.expected[i];

                if (op == "ExamRoom") {
                    er.emplace(a[0]);
                }
                else if (op == "leave") {
                    er->leave(a[0]);
                }
                else if (op == "seat") {
                    int got = er->seat();
                    const string label = makeStepLabel("ExamRoom_855", t, i, op, nullopt);
                    assertEqScalar(label, ex.value(), got);
                }
            }
        }
    }

    static void gameOfLife_289_tests() {
        vector<GameOfLifeTestCase> testCases = {
            // Example 1
            {
                {{0,1,0},{0,0,1},{1,1,1},{0,0,0}},
                {{0,0,0},{1,0,1},{0,1,1},{0,1,0}}
            },
            // Example 2
            {
                {{1,1},{1,0}},
                {{1,1},{1,1}}
            },
            // Complex 1: Blinker (oscillator) — horizontal -> vertical
            {
                {{0,0,0},
                {1,1,1},
                {0,0,0}},
                {{0,1,0},
                {0,1,0},
                {0,1,0}}
            },
            // Complex 2: Stable block (still life) — unchanged
            {
                {{0,0,0,0},
                {0,1,1,0},
                {0,1,1,0},
                {0,0,0,0}},
                {{0,0,0,0},
                {0,1,1,0},
                {0,1,1,0},
                {0,0,0,0}}
            },
            // Complex 3: Glider — first step
            {
                {{0,1,0,0,0},
                {0,0,1,0,0},
                {1,1,1,0,0},
                {0,0,0,0,0},
                {0,0,0,0,0}},
                {{0,0,0,0,0},
                {1,0,1,0,0},
                {0,1,1,0,0},
                {0,1,0,0,0},
                {0,0,0,0,0}}
            }
        };

        GameOfLife_289 solver;

        for (size_t i = 0; i < testCases.size(); ++i) {
            auto board = testCases[i].input;  // in-place update required
            solver.gameOfLife(board);
            assertEqVVIntExact("Game of Life Test " + to_string(i + 1), testCases[i].expected, board);
        }
    }

    static void longestIncreasingPathInMatrix_329_tests() {
        using TestCases::LongestIncreasingPathInMatrixTestCase;

        vector<LongestIncreasingPathInMatrixTestCase> testCases = {
            // Example 1
            {{{9,9,4},
            {6,6,8},
            {2,1,1}}, 4},

            // Example 2
            {{{3,4,5},
            {3,2,6},
            {2,2,1}}, 4},

            // Example 3
            {{{1}}, 1},

            // Complex 1: snake-like 3x3 increasing path of length 9
            {{{1,2,3},
            {6,5,4},
            {7,8,9}}, 9},

            // Complex 2: rectangular with plateaus, optimal path length 6
            {{{1,2,3,4},
            {2,2,3,5},
            {2,2,4,6}}, 6},
        };

        LongestIncreasingPathInMatrix_329 lip329;
        for (size_t i = 0; i < testCases.size(); ++i) {
            int got = lip329.longestIncreasingPath(testCases[i].matrix);
            assertEqScalar("Longest Increasing Path in Matrix 329 Test " + to_string(i + 1),
                        testCases[i].expected, got);
        }
    }

    static void minStack_155_tests() {
        auto run = [](const vector<pair<string,int>>& ops) {
            MinStack_155 ms;
            vector<int> out;
            for (const auto& [op, val] : ops) {
                if (op == "push") {
                    ms.push(val);
                } else if (op == "pop") {
                    ms.pop();
                } else if (op == "top") {
                    out.push_back(ms.top());
                } else if (op == "getMin") {
                    out.push_back(ms.getMin());
                }
            }
            return out;
        };

        vector<MinStackTestCase> tests = {
            // Example from the prompt
            {
                {{"push",-2},{"push",0},{"push",-3},{"getMin",0},{"pop",0},{"top",0},{"getMin",0}},
                {-3, 0, -2}
            },
            // Monotonic decreasing pushes, verify min changes on pops
            {
                {{"push",5},{"push",3},{"push",1},{"getMin",0},{"pop",0},{"getMin",0},{"pop",0},{"getMin",0},{"top",0}},
                {1, 3, 5, 5}
            },
            // Duplicated minima; ensure min persists through equal values
            {
                {{"push",5},{"push",5},{"push",-1},{"push",-1},{"push",7},
                {"getMin",0},{"pop",0},{"getMin",0},{"pop",0},{"getMin",0},{"pop",0},{"getMin",0},{"top",0}},
                {-1, -1, -1, 5, 5}
            },
            // Interleaved stress: push/pop/top/getMin in mixed order
            {
                {{"push",2},{"push",0},{"push",3},{"push",0},{"getMin",0}, // min=0
                {"pop",0},{"getMin",0},                                   // min=0
                {"pop",0},{"getMin",0},                                   // min=0
                {"pop",0},{"getMin",0}},                                  // min=2
                {0, 0, 0, 2}
            },
            // Single element edge pattern
            {
                {{"push",42},{"getMin",0},{"top",0},{"pop",0}},
                {42, 42}
            }
        };

        for (size_t i = 0; i < tests.size(); ++i) {
            auto got = run(tests[i].ops);
            assertEqVIntExact("Min Stack 155 Test " + to_string(i + 1), tests[i].expected, got);
        }
    }

    static void baseballGame_682_tests() {
        using namespace TestCases;
        vector<BaseballGameTestCase> testCases = {
            {{"5","2","C","D","+"}, 30},                      // Example 1
            {{"5","-2","4","C","D","9","+","+"}, 27},         // Example 2
            {{"1","C"}, 0},                                   // Example 3
            {{"10"}, 10},                                     // Simple single score
            {{"5","-2","C","C","10"}, 10},                    // Consecutive cancellations then a value
            {{"3","4","+","+"}, 25},                          // Multiple '+' in a row
            {{"-5","D","+"}, -30},                            // Negatives with D and +
            {{"1","C","2","C"}, 0},                           // Ends empty again
            {{"1","2","3","D","+","C","D","+"}, 42},          // Rich sequence with interleaved ops
            {{"-1","-2","+","D","C","C"}, -3},                // Many ops with cancels near the end
            {{"30000","30000","+","D","C"}, 120000},          // Large values near bounds to verify 32-bit-safe math
            {{"1","D","D","C","+"}, 6},                       // Alternating D and C
        };

        BaseballGame_682 sol;
        for (size_t i = 0; i < testCases.size(); ++i) {
            auto ops = testCases[i].ops; // calPoints takes non-const ref
            int got = sol.calPoints(ops);
            assertEqScalar("Baseball Game 682 Test " + to_string(i + 1),
                           testCases[i].expected, got);
        }
    }

    inline static const TestEntry kTests[] = {
        TEST(207,  "Course Schedule",                                courseSchedule_207_tests),
        TEST(1971, "Find if Path Exists in Graph",                   findIfPathExistsInGraph_1971_tests),
        TEST(200,  "Number of Islands",                              numIslands_200_tests),
        TEST(695,  "Max Area of Island",                             maxAreaOfIsland_695_tests),
        TEST(210,  "Course Schedule II",                             courseScheduleII_210_tests),
        TEST(743,  "Network Delay Time",                             networkDelayTime_743_tests),
        TEST(994,  "Rotting Oranges",                                rottingOranges_994_tests),
        TEST(417,  "Pacific Atlantic Water Flow",                    pacificAtlantic_417_tests),
        TEST(1584, "Min Cost to Connect All Points",                 minCostToConnectAllPoints_1584_tests),
        TEST(1143, "Longest Common Subsequence",                     longestCommonSubsequence_1143_tests),
        TEST(300,  "Longest Increasing Subsequence",                 longestIncreasingSubsequence_300_tests),
        TEST(83,   "Remove Duplicates from Sorted List",             removeDuplicatesFromSortedList_83_tests),
        TEST(206,  "Reverse Linked List",                            reverseLinkedList_206_tests),
        TEST(21,   "Merge Two Sorted Lists",                         mergeTwoSortedLists_21_tests),
        TEST(141,  "Linked List Cycle",                              hasCycle_141_tests),
        TEST(876,  "Middle of the Linked List",                      middleOfTheLinkedList_876_tests),
        TEST(19,   "Remove Nth Node From End of List",               removeNthNodeFromEndOfList_19_tests),
        TEST(121,  "Best Time to Buy and Sell Stock",                bestTimeToBuyAndSellStock_121_tests),
        TEST(54,   "Spiral Matrix",                                  spiralMatrix_54_tests),
        TEST(98,   "Validate Binary Search Tree",                    validateBinarySearchTree_98_tests),
        TEST(235,  "Lowest Common Ancestor",                         lowestCommonAncestor_235_tests),
        TEST(138,  "Copy List With Random Pointer",                  copyRandomList_138_tests),
        TEST(230,  "Kth Smallest Element in a BST",                  kthSmallestElementInBST_230_tests),
        TEST(208,  "Implement Trie",                                 implementTrie_208_tests),
        TEST(215,  "Kth Largest Element in an Array",                kthLargestElementInArray_215_tests),
        TEST(0,    "MinHeap",                                        minHeap_tests), // custom: id=0
        TEST(48,   "Rotate Image",                                   rotateImage_48_tests),
        TEST(56,   "Merge Intervals",                                mergeIntervals_56_tests),
        TEST(23,   "Merge K Sorted Lists",                           mergeKLists_tests),
        TEST(238,  "Product of Array Except Self",                   productOfArrayExceptSelf_238_tests),
        TEST(169,  "Majority Element",                               majorityElement_169_tests),
        TEST(150,  "Evaluate Reverse Polish Notation",               evaluateReversePolishNotation_150_tests),
        TEST(84,   "Largest Rectangle in Histogram",                 largestRectangleInHistogram_84_tests),
        TEST(79,   "Word Search",                                    wordSearch_79_tests),
        TEST(20,   "Valid Parentheses",                              validParentheses_20_tests),
        TEST(36,   "Valid Sudoku",                                   validSudoku_36_tests),
        TEST(704,  "Binary Search",                                  binarySearch_704_tests),
        TEST(35,   "Search Insert Position",                         searchInsertPosition_35_tests),
        TEST(74,   "Search a 2D Matrix",                             search2DMatrix_74_tests),
        TEST(432,  "All O`one Data Structure",                       allOOneDataStructure_432_tests),
        TEST(153,  "Find Minimum in Rotated Sorted Array",           findMinimumInRotatedSortedArray_153_tests),
        TEST(133,  "Clone Graph",                                    cloneGraph_133_tests),
        TEST(6,    "Zigzag Conversion",                              zigzagConversion_6_tests),
        TEST(274,  "H-Index",                                        hIndex_274_tests),
        TEST(75,   "Sort Colors",                                    sortColors_75_tests),
        TEST(80,   "Remove Duplicates from Sorted Array II",         removeDuplicatesFromSortedArrayII_80_tests),
        TEST(122,  "Best Time to Buy and Sell Stock II",             bestTimeToBuyAndSellStockII_122_tests),
        TEST(242,  "Valid Anagram",                                  validAnagram_242_tests),
        TEST(1152, "Analyze User Website Visit Pattern",             analyzeUserWebsiteVisitPattern_1152_tests),
        TEST(49,   "Group Anagrams",                                 groupAnagrams_49_tests),
        TEST(277,  "Find the Celebrity",                             findCelebrity_277_tests),
        TEST(128,  "Longest Consecutive Sequence",                   longestConsecutiveSequence_128_tests),
        TEST(412,  "FizzBuzz",                                       fizzBuzz_412_tests),
        TEST(424,  "Longest Repeating Character Replacement",        longestRepeatingCharacterReplacement_424_tests),
        TEST(146,  "LRU Cache",                                      lruCache_146_tests),
        TEST(451,  "Sort Characters by Frequency",                   sortCharactersByFrequency_451_tests),
        TEST(322,  "Coin Change",                                    coinChange_322_tests),
        TEST(692,  "Top K Frequent Words",                           topKFrequentWords_692_tests),
        TEST(2360, "Longest Cycle in a Graph",                       longestCycleInGraph_2360_tests),
        TEST(2608, "Shortest Cycle in a Graph",                      shortestCycleInGraph_2608_tests),
        TEST(63,   "Unique Paths II",                                uniquePathsII_63_tests),
        TEST(643,  "Maximum Average Subarray I",                     maximumAverageSubarrayI_643_tests),
        TEST(1004, "Max Consecutive Ones III",                       maxConsecutiveOnesIII_1004_tests),
        TEST(3,    "Longest Substring Without Repeating Characters", longestSubstringWithoutRepeatingCharacters_3_tests),
        TEST(209,  "Minimum Size Subarray Sum",                      minimumSizeSubarraySum_209_tests),
        TEST(567,  "Permutation in String",                          permutationInString_567_tests),
        TEST(977,  "Squares of a Sorted Array",                      squaresOfSortedArray_977_tests),
        TEST(344,  "Reverse String",                                 reverseString_344_tests),
        TEST(167,  "Two Sum II",                                     twoSumII_167_tests),
        TEST(125,  "Valid Palindrome",                               validPalindrome_125_tests),
        TEST(15,   "3Sum",                                           threeSum_15_tests),
        TEST(11,   "Container With Most Water",                      containerWithMostWater_11_tests),
        TEST(42,   "Trapping Rain Water",                            trappingRainWater_42_tests),
        TEST(85,   "Maximal Rectangle",                              maximalRectangle_85_tests),
        TEST(53,   "Maximum Subarray",                               maximumSubarray_53_tests),
        TEST(1,    "Two Sum",                                        twoSum_1_tests),
        TEST(88,   "Merge Sorted Array",                             mergeSortedArray_88_tests),
        TEST(27,   "Remove Element",                                 removeElement_27_tests),
        TEST(1189, "Maximum Number of Balloons",                     maximumNumberOfBalloons_1189_tests),
        TEST(67,   "Add Binary",                                     addBinary_67_tests),
        TEST(724,  "Find Pivot Index",                               findPivotIndex_724_tests),
        TEST(191,  "Number of 1 Bits",                               numberOf1Bits_191_tests),
        TEST(0,    "Decode String (Google Onsite)",                  decodeString_GoogleOnsite_tests), // custom
        TEST(44,   "Wildcard Matching",                              wildcardMatching_44_tests),
        TEST(973,  "K Closest Points to Origin",                     kClosestPointsToOrigin_973_tests),
        TEST(62,   "Unique Paths",                                   uniquePaths_62_tests),
        TEST(815,  "Bus Routes",                                     busRoutes_815_tests),
        TEST(1091, "Shortest Path Binary Matrix",                    shortestPathBinaryMatrix_1091_tests),
        TEST(2642, "Design Graph With Shortest Path Calculator",     designGraphWithShortestPathCalculator_2642_tests),
        TEST(2812, "Find the Safest Path in a Grid",                 findTheSafestPathInGrid_2812_tests),
        TEST(104,  "Maximum Depth of Binary Tree",                   maximumDepthOfBinaryTree_104_tests),
        TEST(286,  "Walls and Gates",                                wallsAndGates_286_tests),
        TEST(65,   "Valid Number",                                   validNumber_65_tests),
        TEST(771,  "Jewels and Stones",                              numJewelsAndStones_771_tests),
        TEST(367,  "Valid Perfect Square",                           validPerfectSquare_367_tests),
        TEST(279,  "Perfect Squares",                                perfectSquares_279_tests),
        TEST(100,  "Same Tree",                                      sameTree_100_tests),
        TEST(268,  "Missing Number",                                 missingNumber_268_tests),
        TEST(739,  "Daily Temperatures",                             dailyTemperatures_739_tests),
        TEST(217,  "Contains Duplicate",                             containsDuplicate_217_tests),
        TEST(509,  "Fibonacci Number",                               fibonacci_509_tests),
        TEST(70,   "Climbing Stairs",                                climbingStairs_70_tests),
        TEST(746,  "Min Cost Climbing Stairs",                       minCostClimbingStairs_746_tests),
        TEST(198,  "House Robber",                                   houseRobber_198_tests),
        TEST(1046, "Last Stone Weight",                              lastStoneWeight_1046_tests),
        TEST(347,  "Top K Frequent Elements",                        topKFrequent_347_tests),
        TEST(2239, "Find Closest Number to Zero",                    findClosestNumber_2239_tests),
        TEST(1768, "Merge Strings Alternately",                      mergeStringsAlternately_1768_tests),
        TEST(13,   "Roman to Integer",                               romanToInteger_13_tests),
        TEST(392,  "Is Subsequence",                                 isSubsequence_392_tests),
        TEST(392,  "Is Subsequence (next-position table)",           isSubsequence_392_nextpos_tests),
        TEST(14,   "Longest Common Prefix",                          longestCommonPrefix_14_tests),
        TEST(228,  "Summary Ranges",                                 summaryRanges_228_tests),
        TEST(26,   "Remove Duplicates",                              removeDuplicates_26_tests),
        TEST(45,   "Jump Game II",                                   jumpGameII_45_tests),
        TEST(55,   "Jump Game",                                      jumpGame_55_tests),
        TEST(78,   "Subsets",                                        subsets_78_tests),
        TEST(46,   "Permutations",                                   permutations_46_tests),
        TEST(77,   "Combinations",                                   combinations_77_tests),
        TEST(17,   "Letter Combinations",                            letterCombinations_17_tests),
        TEST(39,   "Combination Sum",                                combinationSum_39_tests),
        TEST(22,   "Generate Parentheses",                           generateParentheses_22_tests),
        TEST(855,  "Exam Room",                                      examRoom_855_tests),
        TEST(289,  "Game of Life",                                   gameOfLife_289_tests),
        TEST(329,  "Longest Increasing Path in a Matrix",            longestIncreasingPathInMatrix_329_tests),
        TEST(155,  "Min Stack",                                      minStack_155_tests),
        TEST(682,  "Baseball Game",                                  baseballGame_682_tests),
    };

    static void runAllTests() {
        for (const auto& t : kTests) {
            // Unified banner: "Running <title> (#id) tests:"
            cout << "Running " << t.title;
            if (t.id > 0) cout << " (#" << t.id << ")";
            cout << " tests:\n";
            t.fn();
        }
    }
};

int main() {
    cout << "Running LeetCodeCpp tests:\n";
    TestsRunner::runAllTests();
    return 0;
}
