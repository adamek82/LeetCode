#include <climits>
#include <iostream>
#include <string>
#include <vector>
#include <optional>
#include <cmath>
#include <variant>
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

        cout << "-> DFS (three-state) version:\n";
        for (size_t i = 0; i < testCases.size(); ++i) {
            bool result = cs207.canFinishDFS(testCases[i].numCourses, testCases[i].prerequisites);
            assertEqScalar("Test " + to_string(i + 1), testCases[i].expected, result);
        }

        cout << "-> Kahn's algorithm version:\n";
        for (size_t i = 0; i < testCases.size(); ++i) {
            bool result = cs207.canFinishKahns(testCases[i].numCourses, testCases[i].prerequisites);
            assertEqScalar("Test " + to_string(i + 1), testCases[i].expected, result);
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

        cout << "-> Recursive DFS version:\n";
        for (size_t i = 0; i < testCases.size(); ++i) {
            bool result = fp1971.validPathRecursiveDFS(testCases[i].n, testCases[i].edges, testCases[i].source, testCases[i].destination);
            assertEqScalar("Test " + to_string(i + 1), testCases[i].expected, result);
        }

        cout << "-> Iterative DFS version with a stack:\n";
        for (size_t i = 0; i < testCases.size(); ++i) {
            bool result = fp1971.validPathIterativeDFS(testCases[i].n, testCases[i].edges, testCases[i].source, testCases[i].destination);
            assertEqScalar("Test " + to_string(i + 1), testCases[i].expected, result);
        }

        cout << "-> BFS version with a queue:\n";
        for (size_t i = 0; i < testCases.size(); ++i) {
            bool result = fp1971.validPathBFS(testCases[i].n, testCases[i].edges, testCases[i].source, testCases[i].destination);
            assertEqScalar("Test " + to_string(i + 1), testCases[i].expected, result);
        }

        cout << "-> Union-find version:\n";
        for (size_t i = 0; i < testCases.size(); ++i) {
            bool result = fp1971.validPathUnionFind(testCases[i].n, testCases[i].edges, testCases[i].source, testCases[i].destination);
            assertEqScalar("Test " + to_string(i + 1), testCases[i].expected, result);
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

        CourseScheduleII_210 cs210;

        // Define the isValidOrder function inside the test function
        function<bool(const vector<int>&, int, const vector<vector<int>>&, const vector<int>&)>
        isValidOrder = [](const vector<int>& order, int numCourses,
                          const vector<vector<int>>& prerequisites,
                          const vector<int>& expectedOrder) {
            // If expectedOrder is empty, we expect an empty result (cycle case)
            if (expectedOrder.empty()) return order.empty();

            // Create a position map to check the order of prerequisites
            unordered_map<int, int> position;
            for (int i = 0; i < order.size(); ++i) {
                position[order[i]] = i;
            }

            // Verify each prerequisite pair to ensure order is correct
            for (const auto& prereq : prerequisites) {
                int course = prereq[0], prerequisite = prereq[1];
                if (position[prerequisite] > position[course]) {
                    return false; // If prerequisite appears after the course, order is invalid
                }
            }

            return true; // All prerequisites are satisfied in the given order
        };

        cout << "-> DFS-based topological sort version:\n";
        for (size_t i = 0; i < testCases.size(); ++i) {
            vector<int> result = cs210.findOrderByDFSTraversal(testCases[i].numCourses, testCases[i].prerequisites);

            bool pass = isValidOrder(result, testCases[i].numCourses, testCases[i].prerequisites, testCases[i].expectedOrder);
            cout << "Test " << (i + 1) << ": res = " << (pass ? "PASS" : "FAIL") << endl;
        }

        cout << "-> Kahn's algorithm version:\n";
        for (size_t i = 0; i < testCases.size(); ++i) {
            vector<int> result = cs210.findOrderByKahnsAlgorithm(testCases[i].numCourses, testCases[i].prerequisites);

            bool pass = isValidOrder(result, testCases[i].numCourses, testCases[i].prerequisites, testCases[i].expectedOrder);
            cout << "Test " << (i + 1) << ": res = " << (pass ? "PASS" : "FAIL") << endl;
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

        for (size_t i = 0; i < testCases.size(); ++i) {
            int result = solution.longestCommonSubsequence(testCases[i].text1, testCases[i].text2);
            cout << "LCS Test " << i + 1 << ": res = "
                    << (result == testCases[i].expected ? "PASS" : "FAIL")
                    << " (Expected: " << testCases[i].expected
                    << ", Got: " << result << ")" << endl;
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

        LongestIncreasingSubsequence_300 solution; // Assuming your LIS solution is implemented in this class

        for (size_t i = 0; i < testCases.size(); ++i) {
            int result = solution.lengthOfLIS(testCases[i].nums);
            assertEqScalar("Test " + to_string(i + 1), testCases[i].expected, result);
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

            if (!TestUtils::assertEqScalar("Validate BST Test " + to_string(i + 1), testCases[i].expected, result)) {
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

            TreeNode<int>* result = lcaSolver.lowestCommonAncestor(root, p, q);

            cout << "LCA Test " << (i + 1) << ": res = "
                    << ((result && result->val == testCases[i].expected) ? "PASS" : "FAIL")
                    << " (Expected: " << testCases[i].expected << ", Got: " << (result ? result->val : -1) << ")" << endl;

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

            cout << "Test " << (i + 1) << ": " << (isCorrect ? "PASS" : "FAIL") << endl;

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
            TreeNode<int>* root = TreeUtils::vectorToTree(testCases[i].tree);

            int result = solution.kthSmallest(root, testCases[i].k);
            cout << "Kth Smallest Element Test " << (i + 1) << ": res = "
                    << (result == testCases[i].expected ? "PASS" : "FAIL")
                    << " (Expected: " << testCases[i].expected << ", Got: " << result << ")" << endl;

            TreeUtils::freeTree(root); // Free tree memory
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
                const auto& op = testCases[i].operations[j];
                const auto& arg = testCases[i].arguments[j];
                const auto& expected = testCases[i].expected[j];

                if (op == "Trie") {
                    trie = new Trie();
                    cout << "Operation: Trie() -> null\n";
                } else if (op == "insert") {
                    trie->insert(arg.value());
                    cout << "Operation: insert(\"" << arg.value() << "\") -> null\n";
                } else if (op == "search") {
                    bool result = trie->search(arg.value());
                    cout << "Operation: search(\"" << arg.value() << "\") -> " << (result ? "true" : "false");
                    if (expected.has_value() && result == expected.value()) {
                        cout << " [PASS]\n";
                    } else {
                        cout << " [FAIL]\n";
                    }
                } else if (op == "startsWith") {
                    bool result = trie->startsWith(arg.value());
                    cout << "Operation: startsWith(\"" << arg.value() << "\") -> " << (result ? "true" : "false");
                    if (expected.has_value() && result == expected.value()) {
                        cout << " [PASS]\n";
                    } else {
                        cout << " [FAIL]\n";
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

            // Large ascending [1..10000], k=500 -> 9501 (placeholder, filled below)
            {{}, 500, 9501}
        };

        // Fill the large ascending test
        {
            vector<int> big;
            big.reserve(10000);
            for (int i = 1; i <= 10000; ++i) big.push_back(i);
            testCases.back() = {move(big), 500, 9501};
        }

        KthLargestElementInArray_215 solution;

        for (size_t i = 0; i < testCases.size(); ++i)
        {
            // Use copies to be robust if implementations ever mutate input
            auto v1 = testCases[i].nums;
            auto v2 = testCases[i].nums;

            int resMax = solution.findKthLargest_MaxHeap(v1, testCases[i].k);
            int resMin = solution.findKthLargest_MinHeap(v2, testCases[i].k);

            bool passMax = (resMax == testCases[i].expected);
            bool passMin = (resMin == testCases[i].expected);
            bool agree   = (resMax == resMin);

            cout << "Kth Largest Element 215 Test " << (i + 1) << " [MaxHeap]: "
                << (passMax ? "PASS" : "FAIL")
                << " (k=" << testCases[i].k
                << ", Expected: " << testCases[i].expected
                << ", Got: " << resMax << ")\n";

            cout << "Kth Largest Element 215 Test " << (i + 1) << " [MinHeap]: "
                << (passMin ? "PASS" : "FAIL")
                << " (k=" << testCases[i].k
                << ", Expected: " << testCases[i].expected
                << ", Got: " << resMin << ")"
                << (agree ? "" : "  <-- mismatch between implementations!") << "\n";
        }
    }

    static void minHeap_tests() {
        vector<MinHeapTestCase> testCases = {
            {
                {{"insert", 5}, {"insert", 3}, {"insert", 8}, {"insert", 1}, {"insert", 2}, {"extractMin", 0}, {"extractMin", 0}},
                {1, 2} // Expected results of the extractMin calls
            },
            {
                {{"insert", 10}, {"insert", 20}, {"insert", 5}, {"update", 1}, {"extractMin", 0}},
                {1} // Updated root is extracted
            },
            {
                {{"insert", 100}, {"insert", 50}, {"insert", 25}, {"extractMin", 0}, {"extractMin", 0}},
                {25, 50} // Both extractions
            }
        };

        for (size_t i = 0; i < testCases.size(); ++i) {
            MinHeap heap;
            vector<int> results;

            for (const auto& op : testCases[i].operations) {
                if (op.first == "insert") {
                    heap.insert(op.second);
                } else if (op.first == "extractMin") {
                    results.push_back(heap.extractMin());
                } else if (op.first == "update") {
                    heap.update(op.second, op.second); // Use parameters as necessary
                }
            }

            // Compare results
            bool pass = results == testCases[i].expected;
            cout << "MinHeap Test " << (i + 1) << ": " << (pass ? "PASS" : "FAIL") << "\n";
            if (!pass) {
                cout << "Expected: ";
                for (int r : testCases[i].expected) cout << r << " ";
                cout << "\nGot: ";
                for (int r : results) cout << r << " ";
                cout << "\n";
            }
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
            auto input = testCases[i].input;      // fresh copy
            rotator.rotateTransposeReverse(input);

            cout << "[Transpose+Reverse] Test " << (i + 1) << ": res = "
                    << (input == testCases[i].expected ? "PASS" : "FAIL") << '\n';
            cout << "Expected:\n";
            printMatrix(testCases[i].expected);
            cout << "Got:\n";
            printMatrix(input);
        }

        // -------- Layer-by-Layer (“onion”) swap variant -------------------------
        for (size_t i = 0; i < testCases.size(); ++i) {
            auto input = testCases[i].input;      // fresh copy
            rotator.rotateLayerSwap(input);

            cout << "[LayerSwap]        Test " << (i + 1) << ": res = "
                    << (input == testCases[i].expected ? "PASS" : "FAIL") << '\n';
            cout << "Expected:\n";
            printMatrix(testCases[i].expected);
            cout << "Got:\n";
            printMatrix(input);
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
            auto result = solution.merge(testCases[i].input);

            cout << "Merge Intervals Test " << (i + 1) << ": res = "
                    << (result == testCases[i].expected ? "PASS" : "FAIL")
                    << "\nExpected: ";
            for (const auto& interval : testCases[i].expected) {
                cout << "[" << interval[0] << "," << interval[1] << "] ";
            }
            cout << "\nGot: ";
            for (const auto& interval : result) {
                cout << "[" << interval[0] << "," << interval[1] << "] ";
            }
            cout << "\n\n";
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
            // Create input linked lists
            vector<IntListNode*> inputLists;
            for (const auto& list : testCases[i].input) {
                inputLists.push_back(ListUtils::createLinkedList<int>(list));
            }

            // Run the solution
            IntListNode* result = solution.mergeKLists(inputLists);

            // Convert result to vector
            vector<int> resultVector = ListUtils::toVector<int>(result);

            // Print test results
            cout << "Merge K Lists Test " << i + 1 << ": res = "
                    << (resultVector == testCases[i].expected ? "PASS" : "FAIL")
                    << " (Expected: " << ListUtils::toString<int>(ListUtils::createLinkedList<int>(testCases[i].expected))
                    << ", Got: " << ListUtils::toString<int>(result) << ")" << endl;

            // Free allocated memory
            ListUtils::freeList<int>(result);
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
            auto result = solution.productExceptSelf(testCases[i].input);
            cout << "Product of Array Except Self Test " << (i + 1) << ": res = "
                    << (result == testCases[i].expected ? "PASS" : "FAIL")
                    << " (Expected: ";
            for (int val : testCases[i].expected) cout << val << " ";
            cout << ", Got: ";
            for (int val : result) cout << val << " ";
            cout << ")\n";
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

        cout << "-> Boyer–Moore Majority Vote Algorithm:\n";
        for (size_t i = 0; i < testCases.size(); ++i) {
            MajorityElement_169 solution;
            int result = solution.majorityElement(testCases[i].input);
            cout << "Test " << (i + 1) << ": ";
            if (result == testCases[i].expected) {
                cout << "PASS\n";
            } else {
                cout << "FAIL (Expected: " << testCases[i].expected
                        << ", Got: " << result << ")\n";
            }
        }

        cout << "-> Frequency Counting with a Hashmap Algorithm:\n";
        for (size_t i = 0; i < testCases.size(); ++i) {
            MajorityElement_169 solution;
            int result = solution.majorityElementWithHashmap(testCases[i].input);
            cout << "Test " << (i + 1) << ": ";
            if (result == testCases[i].expected) {
                cout << "PASS\n";
            } else {
                cout << "FAIL (Expected: " << testCases[i].expected
                        << ", Got: " << result << ")\n";
            }
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
            int result = evaluator.evalRPN(testCases[i].input);
            cout << "Evaluate RPN Test " << (i + 1) << ": res = "
                      << (result == testCases[i].expected ? "PASS" : "FAIL")
                      << " (Expected: " << testCases[i].expected << ", Got: " << result << ")\n";
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
            {{2, 1, 4, 5, 1, 3, 3}, 8}
        };

        LargestRectangleInHistogram_84 solution;

        for (size_t i = 0; i < testCases.size(); ++i) {
            int result = solution.largestRectangleArea(testCases[i].input);
            cout << "Test " << (i + 1) << ": res = "
                      << (result == testCases[i].expected ? "PASS" : "FAIL")
                      << " (Expected: " << testCases[i].expected
                      << ", Got: " << result << ")" << endl;
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
            bool result = solution.exist(testCases[i].board, testCases[i].word);
            cout << "Test " << (i + 1) << ": res = "
                    << (result == testCases[i].expected ? "PASS" : "FAIL")
                    << " (Expected: " << (testCases[i].expected ? "true" : "false")
                    << ", Got: " << (result ? "true" : "false") << ")" << endl;
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
            bool result = solution.isValid(testCases[i].input);
            cout << "Test " << (i + 1) << ": res = "
                    << (result == testCases[i].expected ? "PASS" : "FAIL")
                    << " (Expected: " << (testCases[i].expected ? "true" : "false")
                    << ", Got: " << (result ? "true" : "false") << ")" << endl;
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
            bool result = solver.isValidSudoku(testCases[i].board);
            cout << "Valid Sudoku Test " << (i + 1) << ": res = "
                    << (result == testCases[i].expected ? "PASS" : "FAIL")
                    << " (Expected: " << (testCases[i].expected ? "true" : "false")
                    << ", Got: " << (result ? "true" : "false") << ")" << endl;
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
            int result = solution.search(testCases[i].input, testCases[i].target);
            cout << "Binary Search Test " << (i + 1) << ": res = "
                    << (result == testCases[i].expected ? "PASS" : "FAIL")
                    << " (Expected: " << testCases[i].expected
                    << ", Got: " << result << ")" << endl;
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
            int result = solution.searchInsert(testCases[i].input, testCases[i].target);
            cout << "Search Insert Position Test " << (i + 1) << ": res = "
                    << (result == testCases[i].expected ? "PASS" : "FAIL")
                    << " (Expected: " << testCases[i].expected
                    << ", Got: " << result << ")" << endl;
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
            bool result = solution.searchMatrix(testCases[i].matrix, testCases[i].target);
            cout << "Test " << (i + 1) << ": res = "
                    << (result == testCases[i].expected ? "PASS" : "FAIL")
                    << " (Expected: " << (testCases[i].expected ? "true" : "false")
                    << ", Got: " << (result ? "true" : "false") << ")\n";
        }
    }

    static bool inSet(const string& s, initializer_list<string> candidates) {
        // Helper to handle the fact that getMaxKey / getMinKey can return any
        // of the keys sharing min/max count
        for (auto& c : candidates) {
            if (s == c) return true;
        }
        return false;
    }

    static void allOOneDataStructure_432_tests() {
        // Test 1: Basic example from problem statement
        {
            AllOOneDataStructure_432 allOne;
            allOne.inc("hello");
            allOne.inc("hello");
            // "hello" now has count 2
            string mx = allOne.getMaxKey();  // expect "hello"
            string mn = allOne.getMinKey();  // expect "hello"
            bool t1a = (mx == "hello") && (mn == "hello");

            allOne.inc("leet");
            // "hello"=2, "leet"=1
            mx = allOne.getMaxKey(); // still "hello"
            mn = allOne.getMinKey(); // now "leet"
            bool t1b = (mx == "hello") && (mn == "leet");

            bool pass = t1a && t1b;
            cout << "Test 1: " << (pass ? "PASS" : "FAIL") << endl;
        }

        // Test 2: Multiple keys with same counts
        {
            AllOOneDataStructure_432 allOne;
            allOne.inc("foo"); // foo=1
            allOne.inc("bar"); // bar=1
            allOne.inc("bar"); // bar=2
            // So bar=2, foo=1
            bool t2a = inSet(allOne.getMaxKey(), {"bar"}); // Only "bar" has count=2
            bool t2b = inSet(allOne.getMinKey(), {"foo"}); // Only "foo" has count=1

            // Now bring foo up to 2
            allOne.inc("foo"); // foo=2, bar=2
            // Both foo & bar have count=2, so min & max can be either
            bool t2c = inSet(allOne.getMaxKey(), {"foo", "bar"});
            bool t2d = inSet(allOne.getMinKey(), {"foo", "bar"});

            bool pass = (t2a && t2b && t2c && t2d);
            cout << "Test 2: " << (pass ? "PASS" : "FAIL") << endl;
        }

        // Test 3: Testing dec() and removal
        {
            AllOOneDataStructure_432 allOne;
            // a=3, b=1, c=1
            allOne.inc("a");  allOne.inc("a");  allOne.inc("a");
            allOne.inc("b");
            allOne.inc("c");

            // Check max/min
            bool t3a = inSet(allOne.getMaxKey(), {"a"});          // a=3 is max
            bool t3b = inSet(allOne.getMinKey(), {"b", "c"});     // b=1, c=1

            // Decrement "a" 3 times => "a" removed from structure
            allOne.dec("a"); // now a=2
            allOne.dec("a"); // now a=1
            allOne.dec("a"); // now removed
            // left with b=1, c=1

            bool t3c = inSet(allOne.getMaxKey(), {"b", "c"});  // both b,c => count=1
            bool t3d = inSet(allOne.getMinKey(), {"b", "c"});

            bool pass = (t3a && t3b && t3c && t3d);
            cout << "Test 3: " << (pass ? "PASS" : "FAIL") << endl;
        }
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
            int result = solution.findMin(testCases[i].input);
            cout << "Test " << (i + 1) << ": res = "
                    << (result == testCases[i].expected ? "PASS" : "FAIL")
                    << " (Expected: " << testCases[i].expected << ", Got: " << result << ")" << endl;
        }
    }

    // Helper function to check if two graphs are isomorphic
    static bool areGraphsIsomorphic(GraphNode<int>* original, GraphNode<int>* cloned) {
        if (!original && !cloned) return true;
        if (!original || !cloned) return false;
        if (original->val != cloned->val) return false;

        unordered_map<GraphNode<int>*, GraphNode<int>*> visited;
        function<bool(GraphNode<int>*, GraphNode<int>*)> dfs = [&](GraphNode<int>* n1, GraphNode<int>* n2) -> bool {
            if (!n1 || !n2) return n1 == n2;
            if (n1->val != n2->val) return false;
            if (visited.count(n1)) return visited[n1] == n2;

            visited[n1] = n2;
            if (n1->neighbors.size() != n2->neighbors.size()) return false;

            for (size_t i = 0; i < n1->neighbors.size(); ++i) {
                if (!dfs(n1->neighbors[i], n2->neighbors[i])) return false;
            }
            return true;
        };

        return dfs(original, cloned);
    }

    // Utility function to build a graph from adjacency list
    static GraphNode<int>* buildGraph(const vector<vector<int>>& adjList) {
        if (adjList.empty()) return nullptr;

        unordered_map<int, GraphNode<int>*> nodeMap;
        for (int i = 0; i < adjList.size(); ++i) {
            if (!nodeMap.count(i + 1)) nodeMap[i + 1] = new GraphNode<int>(i + 1);
            for (int neighbor : adjList[i]) {
                if (!nodeMap.count(neighbor)) nodeMap[neighbor] = new GraphNode<int>(neighbor);
                nodeMap[i + 1]->neighbors.push_back(nodeMap[neighbor]);
            }
        }
        return nodeMap[1]; // The first node (value = 1) is always the entry point.
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
            GraphNode<int>* originalGraph = buildGraph(testCases[i]);
            GraphNode<int>* clonedGraph = solver.cloneGraph(originalGraph);

            bool result = areGraphsIsomorphic(originalGraph, clonedGraph);
            cout << "Clone Graph Test " << (i + 1) << ": " << (result ? "PASS" : "FAIL") << endl;
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

        ZigzagConversion_6 solution;
        for (size_t i = 0; i < testCases.size(); ++i) {
            string result_rowWise = solution.convert_rowWise(testCases[i].input, testCases[i].numRows);
            string result_jumpPattern = solution.convert_jumpPattern(testCases[i].input, testCases[i].numRows);

            cout << "Test " << (i + 1) << " (Row-Wise): "
                      << (result_rowWise == testCases[i].expected ? "PASS" : "FAIL")
                      << " (Expected: " << testCases[i].expected
                      << ", Got: " << result_rowWise << ")" << endl;

            cout << "Test " << (i + 1) << " (Jump-Pattern): "
                      << (result_jumpPattern == testCases[i].expected ? "PASS" : "FAIL")
                      << " (Expected: " << testCases[i].expected
                      << ", Got: " << result_jumpPattern << ")" << endl;
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

        HIndex_274 solution;

        for (size_t i = 0; i < testCases.size(); ++i) {
            int result = solution.hIndex(testCases[i].input);
            cout << "HIndex_274 Test " << (i + 1) << ": res = "
                      << ((result == testCases[i].expected) ? "PASS" : "FAIL")
                      << " (Expected: " << testCases[i].expected
                      << ", Got: " << result << ")" << endl;
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

        SortColors_75 solution;

        for (size_t i = 0; i < testCases.size(); ++i) {
            vector<int> arr = testCases[i].input;
            solution.sortColors(arr);

            bool pass = (arr == testCases[i].expected);
            cout << "SortColors Test " << (i + 1) << ": "
                    << (pass ? "PASS" : "FAIL")
                    << " (Expected: [";
            for (size_t j = 0; j < testCases[i].expected.size(); ++j) {
                cout << testCases[i].expected[j]
                        << (j + 1 < testCases[i].expected.size() ? ", " : "");
            }
            cout << "], Got: [";
            for (size_t j = 0; j < arr.size(); ++j) {
                cout << arr[j] << (j + 1 < arr.size() ? ", " : "");
            }
            cout << "])" << endl;
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

        // Instantiate your solution class
        RemoveDuplicatesFromSortedArrayII_80 solution;

        // Run each test
        for (size_t i = 0; i < testCases.size(); ++i) {
            auto nums = testCases[i].input;  // Make a local copy we can modify
            int k = solution.removeDuplicates(nums);

            // Check if k matches expectedK, and also if the first k elements match expectedResult
            bool pass = (k == testCases[i].expectedK);
            if (pass) {
                for (int idx = 0; idx < k; ++idx) {
                    if (nums[idx] != testCases[i].expected[idx]) {
                        pass = false;
                        break;
                    }
                }
            }

            cout << "RemoveDuplicatesFromSortedArrayII_80 Test " << (i + 1) << ": "
                    << (pass ? "PASS" : "FAIL")
                    << " (Expected k=" << testCases[i].expectedK
                    << ", got k=" << k << ")" << endl;
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

        // Instantiate the solution class
        BestTimeToBuyAndSellStockII_122 solution;

        // Test each case
        for (size_t i = 0; i < testCases.size(); ++i) {
            int result = solution.maxProfit(testCases[i].prices);

            bool pass = (result == testCases[i].expected);
            cout << "BestTimeToBuyAndSellStockII_122 Test " << (i + 1) << ": "
                    << (pass ? "PASS" : "FAIL")
                    << " (Expected " << testCases[i].expected
                    << ", got " << result << ")" << endl;
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

        ValidAnagram_242 solution;

        for (size_t i = 0; i < testCases.size(); ++i) {
            bool result = solution.isAnagram(testCases[i].s, testCases[i].t);
            cout << "Valid Anagram Test " << (i + 1) << ": res = "
                    << (result == testCases[i].expected ? "PASS" : "FAIL")
                    << " (Expected: " << (testCases[i].expected ? "true" : "false")
                    << ", Got: " << (result ? "true" : "false") << ")" << endl;
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

        AnalyzeUserWebsiteVisitPattern1152 solver;

        for (size_t i = 0; i < testCases.size(); ++i) {
            vector<string> result_map = solver.mostVisitedPattern_usingMap(testCases[i].username, testCases[i].timestamp, testCases[i].website);
            vector<string> result_hashmap = solver.mostVisitedPattern_usingHashmap(testCases[i].username, testCases[i].timestamp, testCases[i].website);

            bool pass_map = (result_map == testCases[i].expected);
            bool pass_hashmap = (result_hashmap == testCases[i].expected);
            bool pass_consistency = (result_map == result_hashmap);

            cout << "AnalyzeUserWebsiteVisitPattern Test " << (i + 1) << ": \n";

            cout << " - Using Map: " << (pass_map ? "PASS" : "FAIL") << " (Expected: ";
            for (const auto& s : testCases[i].expected) cout << s << " ";
            cout << ", Got: ";
            for (const auto& s : result_map) cout << s << " ";
            cout << ")\n";

            cout << " - Using Hashmap: " << (pass_hashmap ? "PASS" : "FAIL") << " (Expected: ";
            for (const auto& s : testCases[i].expected) cout << s << " ";
            cout << ", Got: ";
            for (const auto& s : result_hashmap) cout << s << " ";
            cout << ")\n";

            cout << " - Consistency Check (Map vs Hashmap): " << (pass_consistency ? "PASS" : "FAIL") << "\n\n";
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
            vector<vector<string>> result_sorting = solution.groupAnagrams_sorting(testCases[i].input);
            vector<vector<string>> result_counting = solution.groupAnagrams_counting(testCases[i].input);

            // Convert results to a sorted form for comparison
            auto sortResult = [](vector<vector<string>>& result) {
                for (auto& group : result) sort(group.begin(), group.end());
                sort(result.begin(), result.end());
            };

            sortResult(result_sorting);
            sortResult(result_counting);
            sortResult(testCases[i].expected);

            bool pass_sorting = (result_sorting == testCases[i].expected);
            bool pass_counting = (result_counting == testCases[i].expected);
            bool identical_outputs = (result_sorting == result_counting);

            cout << "Group Anagrams Test " << i + 1 << ": "
                      << (pass_sorting ? "PASS" : "FAIL") << " (Sorting) | "
                      << (pass_counting ? "PASS" : "FAIL") << " (Counting) | "
                      << (identical_outputs ? "MATCH" : "DIFFERENT") << " (Comparison)"
                      << endl;
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
            FindCelebrity_277 solver;
            solver.knowsMatrix = testCases[i].matrix;
            int result = solver.findCelebrity((int)testCases[i].matrix.size());

            cout << "FindCelebrity Test " << (i + 1)
                      << ": res = " << (result == testCases[i].expected ? "PASS" : "FAIL")
                      << " (Expected: " << testCases[i].expected << ", Got: " << result << ")" << endl;
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

        LongestConsecutiveSequence_128 solution;
        for (size_t i = 0; i < testCases.size(); ++i) {
            int result = solution.longestConsecutive(testCases[i].input);
            cout << "Test " << (i+1) << ": res = "
                      << (result == testCases[i].expected ? "PASS" : "FAIL")
                      << " (Expected: " << testCases[i].expected
                      << ", Got: " << result << ")" << endl;
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

        FizzBuzz_412 solution;
        for (size_t i = 0; i < ns.size(); ++i) {
            auto result = solution.fizzBuzz(ns[i]);
            cout << "FizzBuzz Test " << (i + 1) << ": res = "
                      << (result == expected[i] ? "PASS" : "FAIL")
                      << " (n=" << ns[i] << ")" << endl;
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
        LongestRepeatingCharacterReplacement_424 solution;
        for (size_t i = 0; i < testCases.size(); ++i) {
            int result = solution.characterReplacement(testCases[i].input, testCases[i].k);
            cout << "LRCR_424 Test " << (i + 1) << ": res = "
                      << (result == testCases[i].expected ? "PASS" : "FAIL")
                      << " (Expected: " << testCases[i].expected
                      << ", Got: " << result << ")\n";
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

        for (size_t i = 0; i < testCases.size(); ++i) {
            cout << "LRUCache Test Case " << (i+1) << ":\n";
            LRUCache* cache = nullptr;
            for (size_t j = 0; j < testCases[i].operations.size(); ++j) {
                const auto& op  = testCases[i].operations[j];
                const auto& arg = testCases[i].arguments[j];
                const auto& exp = testCases[i].expected[j];

                if (op == "LRUCache") {
                    cache = new LRUCache(arg[0]);
                    cout << "  LRUCache(" << arg[0] << ") -> null\n";
                }
                else if (op == "put") {
                    cache->put(arg[0], arg[1]);
                    cout << "  put(" << arg[0] << ", " << arg[1] << ") -> null\n";
                }
                else if (op == "get") {
                    int res = cache->get(arg[0]);
                    bool pass = exp.has_value() && res == exp.value();
                    cout << "  get(" << arg[0] << ") -> " << res
                              << (pass ? " [PASS]\n" : " [FAIL]\n");
                }
            }
            delete cache;
            cout << "\n";
        }
    }

    static bool isValidFrequencySort(const string& orig, const string& res) {
        if (orig.size() != res.size()) return false;
        // count in orig
        unordered_map<char,int> freqOrig, freqRes;
        for (char c : orig) ++freqOrig[c];
        for (char c : res) ++freqRes[c];
        if (freqOrig != freqRes) return false;
        // extract runs from res
        vector<pair<char,int>> runs;
        for (size_t i = 0; i < res.size(); ) {
            char c = res[i];
            size_t j = i+1;
            while (j < res.size() && res[j]==c) ++j;
            runs.emplace_back(c, int(j-i));
            i = j;
        }
        // ensure each run length matches freq
        for (auto& [c, cnt] : runs) {
            if (freqOrig[c] != cnt) return false;
        }
        // ensure non-increasing frequencies
        for (size_t i = 1; i < runs.size(); ++i) {
            if (runs[i-1].second < runs[i].second) return false;
        }
        return true;
    }

    static void sortCharactersByFrequency_451_tests() {
        vector<string> inputs = {
            "tree",      // 'e'x2, 'r','t'
            "cccaaa",    // 'c'x3, 'a'x3
            "Aabb",      // 'b'x2, 'A','a'
            "dccbbbaaaa",// a4,b3,c2,d1
            "srrqqqpppp" // p4,q3,r2,s1
        };

        SortCharactersByFrequency_451 solution;
        for (size_t i = 0; i < inputs.size(); ++i) {
            string result = solution.frequencySort(inputs[i]);
            bool pass = isValidFrequencySort(inputs[i], result);
            cout << "SortCharactersByFrequency_451 Test " << (i + 1)
                      << ": " << (pass ? "PASS" : "FAIL")
                      << " (Got: " << result << ")\n";
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

        CoinChange_322 solution;
        for (size_t i = 0; i < testCases.size(); ++i) {
            int res = solution.coinChange(testCases[i].coins, testCases[i].amount);
            cout << "CoinChange Test " << (i+1)
                      << ": res = " << (res == testCases[i].expected ? "PASS" : "FAIL")
                      << " (Expected: " << testCases[i].expected
                      << ", Got: " << res << ")\n";
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

        TopKFrequentWords_692 solution;
        for (size_t i = 0; i < testCases.size(); ++i) {
            auto result = solution.topKFrequent(testCases[i].input, testCases[i].k);
            bool pass = (result == testCases[i].expected);
            cout << "TopKFrequentWords_692 Test " << (i + 1) << ": res = "
                      << (pass ? "PASS" : "FAIL")
                      << " (Expected: [";
            for (size_t j = 0; j < testCases[i].expected.size(); ++j) {
                cout << testCases[i].expected[j]
                          << (j + 1 < testCases[i].expected.size() ? ", " : "");
            }
            cout << "], Got: [";
            for (size_t j = 0; j < result.size(); ++j) {
                cout << result[j]
                          << (j + 1 < result.size() ? ", " : "");
            }
            cout << "])" << endl;
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

        LongestCycleInGraph_2360 solver;

        for (size_t i = 0; i < testCases.size(); ++i) {
            int res = solver.longestCycle(testCases[i].edges);
            cout << "LongestCycleInGraph_2360 Test " << (i + 1) << ": res = "
                      << (res == testCases[i].expected ? "PASS" : "FAIL")
                      << " (Expected: " << testCases[i].expected
                      << ", Got: " << res << ")" << endl;
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

        ShortestCycleInGraph_2608 solver;

        for (size_t i = 0; i < cases.size(); ++i) {
            int got = solver.findShortestCycle(cases[i].n, cases[i].edges);
            cout << "  Test " << (i + 1) << ": "
                      << (got == cases[i].expected ? "PASS" : "FAIL")
                      << "  (expected " << cases[i].expected
                      << ", got " << got << ")\n";
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

        UniquePathsII_63 solution;
        for (size_t i = 0; i < testCases.size(); ++i) {
            int result = solution.uniquePathsWithObstacles(testCases[i].input);
            cout << "Unique Paths II Test " << (i+1)
                      << ": " << (result == testCases[i].expected ? "PASS" : "FAIL")
                      << " (Expected: " << testCases[i].expected
                      << ", Got: " << result << ")\n";
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

        MaximumAverageSubarrayI_643 solution;
        for (size_t i = 0; i < testCases.size(); ++i) {
            double result = solution.findMaxAverage(testCases[i].input, testCases[i].k);
            bool pass = approxEqual(result, testCases[i].expected);
            cout << "MaxAvgSubarrayI_643 Test " << (i + 1) << ": "
                    << (pass ? "PASS" : "FAIL")
                    << " (expected=" << testCases[i].expected
                    << ", got=" << result << ")\n";
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

        MaxConsecutiveOnesIII_1004 solution;
        for (size_t i = 0; i < testCases.size(); ++i) {
            int result = solution.longestOnes(testCases[i].input, testCases[i].k);
            cout << "MaxConsecutiveOnesIII_1004 Test " << (i + 1) << ": res = "
                << (result == testCases[i].expected ? "PASS" : "FAIL")
                << " (Expected: " << testCases[i].expected
                << ", Got: " << result << ")" << endl;
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

        LongestSubstringWithoutRepeatingCharacters_3 solution;
        for (size_t i = 0; i < testCases.size(); ++i) {
            int res = solution.lengthOfLongestSubstring(testCases[i].input);
            cout << "Longest Substring Test " << (i + 1)
                << ": res = " << (res == testCases[i].expected ? "PASS" : "FAIL")
                << " (Expected: " << testCases[i].expected
                << ", Got: " << res << ")" << endl;
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

        MinimumSizeSubarraySum_209 solver;

        for (size_t i = 0; i < testCases.size(); ++i) {
            int got = solver.minSubArrayLen(testCases[i].target, testCases[i].input);
            cout << "MinimumSizeSubarraySum_209 Test " << (i + 1) << ": res = "
                << (got == testCases[i].expected ? "PASS" : "FAIL")
                << " (Expected: " << testCases[i].expected
                << ", Got: " << got << ")\n";
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

        PermutationInString_567 solver;

        for (size_t i = 0; i < testCases.size(); ++i) {
            bool result = solver.checkInclusion(testCases[i].s1, testCases[i].s2);
            cout << "PermutationInString Test " << (i + 1) << ": res = "
                << (result == testCases[i].expected ? "PASS" : "FAIL")
                << " (Expected: " << (testCases[i].expected ? "true" : "false")
                << ", Got: "      << (result ? "true" : "false")  << ")" << endl;
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

        SquaresOfSortedArray_977 solver;
        for (size_t i = 0; i < testCases.size(); ++i) {
            auto result = solver.sortedSquares(testCases[i].input);
            cout << "SquaresOfSortedArray_977 Test " << (i + 1) << ": res = "
                << (result == testCases[i].expected ? "PASS" : "FAIL") << endl;
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
            cout << "ReverseString_344 Test " << (i + 1) << ": res = "
                << (s == testCases[i].expected ? "PASS" : "FAIL") << endl;
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
            auto nums = testCases[i].input;  // work on a copy
            vector<int> res = solver.twoSum(nums, testCases[i].target);
            cout << "TwoSumII_167 Test " << (i + 1) << ": res = "
                << (res == testCases[i].expected ? "PASS" : "FAIL") << endl;
        }
    }

    static void validPalindrome_125_tests() {
        // Build a long palindrome (10 000 'a' separated by commas)
        string longStr;
        longStr.reserve(20000);
        for (int i = 0; i < 10000; ++i) {
            longStr.push_back('a');
            longStr.push_back(',');
        }

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
            bool res = solver.isPalindrome(testCases[i].input);
            cout << "ValidPalindrome_125 Test " << (i + 1) << ": res = "
                << (res == testCases[i].expected ? "PASS" : "FAIL") << endl;
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
            auto res = solver.threeSum(testCases[i].input);

            // sort each triplet then the whole vector for stable comparison
            auto norm = [](vector<vector<int>>& v) {
                for (auto& t : v) sort(t.begin(), t.end());
                sort(v.begin(), v.end());
            };
            norm(res);
            auto exp = testCases[i].expected;
            norm(exp);

            cout << "ThreeSum_15 Test " << (i + 1) << ": res = "
                << (res == exp ? "PASS" : "FAIL") << endl;
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
            int res = solver.maxArea(testCases[i].input);
            cout << "ContainerWithMostWater_11 Test " << (i + 1) << ": res = "
                << (res == testCases[i].expected ? "PASS" : "FAIL") << endl;
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
            int res = solver.trap(testCases[i].input);
            cout << "TrappingRainWater_42 Test " << (i + 1) << ": res = "
                << (res == testCases[i].expected ? "PASS" : "FAIL") << endl;
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
            int result = solver.maximalRectangle(testCases[i].matrix);
            cout << "Maximal Rectangle Test " << (i + 1) << ": res = "
                << (result == testCases[i].expected ? "PASS" : "FAIL")
                << " (Expected: " << testCases[i].expected
                << ", Got: " << result << ")\n";
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
            cout << "MaximumSubarray_53 Test " << (i + 1) << ": "
                    << (got == tc[i].expected ? "PASS" : "FAIL")
                    << " (expected " << tc[i].expected << ", got " << got << ")\n";
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
            auto res = solver.twoSum(cases[i].input, cases[i].target);

            // order-independent check
            auto exp = cases[i].expected;
            sort(res.begin(), res.end());
            sort(exp.begin(), exp.end());

            cout << "[TwoSum] Test " << (i + 1) << ": res = "
                 << (res == exp ? "PASS" : "FAIL") << '\n';
            cout << "Expected: "; printVec(exp);
            cout << "Got:      "; printVec(res);
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
            auto nums1 = cases[i].nums1;   // make a copy; we’ll mutate it
            merger.merge(nums1, cases[i].m, cases[i].nums2, cases[i].n);

            cout << "[MergeSortedArray] Test " << (i + 1) << ": res = "
                 << (nums1 == cases[i].expected ? "PASS" : "FAIL") << '\n';
            cout << "Expected: "; printVec(cases[i].expected);
            cout << "Got:      "; printVec(nums1);
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
            auto nums = cases[i].input;                    // copy to mutate
            int  k    = remover.removeElement(nums, cases[i].val);

            // prepare comparables (order-independent)
            vector<int> got(nums.begin(), nums.begin() + k);
            sort(got.begin(), got.end());
            auto exp = cases[i].expected;
            sort(exp.begin(), exp.end());

            cout << "[RemoveElement] Test " << (i + 1) << ": res = "
                 << ((k == cases[i].expectedK && got == exp) ? "PASS" : "FAIL") << '\n';
            cout << "Expected k=" << cases[i].expectedK << ", elems: "; printVec(exp);
            cout << "Got      k=" << k << ", elems: ";      printVec(got);
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
            int res = solver.maxNumberOfBalloons(cases[i].input);

            cout << "[MaxBalloons] Test " << (i + 1) << ": res = "
                 << (res == cases[i].expected ? "PASS" : "FAIL") << '\n';
            cout << "Expected: " << cases[i].expected
                 << ", Got: " << res << '\n';
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
            string res = solver.addBinary(cases[i].a, cases[i].b);

            cout << "[AddBinary] Test " << (i + 1) << ": res = "
                << (res == cases[i].expected ? "PASS" : "FAIL") << '\n';
            cout << "Expected: " << cases[i].expected
                << ", Got: " << res << '\n';
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
            int res = solver.pivotIndex(cases[i].input);

            cout << "[FindPivot] Test " << (i + 1) << ": res = "
                << (res == cases[i].expected ? "PASS" : "FAIL") << '\n';
            cout << "Expected: " << cases[i].expected
                << ", Got: " << res << '\n';
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
            int res = solver.hammingWeight(cases[i].n);

            cout << "[HammingWeight] Test " << (i + 1) << ": res = "
                << (res == cases[i].expected ? "PASS" : "FAIL") << '\n';
            cout << "Expected: " << cases[i].expected
                << ", Got: " << res << '\n';
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
            string result = solver.decode(testCases[i].input);
            cout << "DecodeString Test " << (i + 1) << ": res = "
                << (result == testCases[i].expected ? "PASS" : "FAIL")
                << " (Expected: " << testCases[i].expected
                << ", Got: " << result << ")\n";
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
            cout << "WildcardMatching_44 Test " << (i + 1) << ": res = "
                << (got == tc[i].expected ? "PASS" : "FAIL")
                << " (Expected: " << (tc[i].expected ? "true" : "false")
                << ", Got: "      << (got          ? "true" : "false") << ")\n";
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
            /* test QuickSelect version */
            auto in1  = cases[i].points;
            auto out1 = solver.kClosestQuickSelect(in1, cases[i].k);
            bool pass1 = isValidKClosestPoints(cases[i].points, cases[i].k, out1);

            /* test Heap version */
            auto in2  = cases[i].points;
            auto out2 = solver.kClosestHeap(in2, cases[i].k);
            bool pass2 = isValidKClosestPoints(cases[i].points, cases[i].k, out2);

            cout << "KClosest Test " << i + 1
                << "  QuickSelect:" << (pass1 ? "PASS" : "FAIL")
                << "  Heap:"        << (pass2 ? "PASS" : "FAIL") << endl;
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
            int res = solver.uniquePaths(cases[i].m, cases[i].n);
            cout << "UniquePaths_62 Test " << (i + 1) << ": res = "
                << (res == cases[i].expected ? "PASS" : "FAIL")
                << " (Expected: " << cases[i].expected
                << ", Got: " << res << ")\n";
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
            auto routesCopy = cases[i].routes;  // Guard against mutation
            int res = solver.numBusesToDestination(routesCopy, cases[i].source, cases[i].target);
            cout << "BusRoutes_815 Test " << (i + 1) << ": "
                << (res == cases[i].expected ? "PASS" : "FAIL")
                << " (Expected: " << cases[i].expected << ", Got: " << res << ")\n";
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
            auto gCopy = testCases[i].grid;          // solver mutates the grid
            int res    = solver.shortestPathBinaryMatrix(gCopy);

            cout << "ShortestPathBinaryMatrix_1091 Test " << (i + 1) << ": "
                 << (res == testCases[i].expected ? "PASS" : "FAIL")
                 << " (Expected: " << testCases[i].expected
                 << ", Got: " << res << ")\n";
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
            cout << "Graph2642 Test Case " << t + 1 << ":\n";
            Graph* g = nullptr;

            const auto& tc = testCases[t];
            for (size_t i = 0; i < tc.operations.size(); ++i) {
                const auto& op  = tc.operations[i];
                const auto& arg = tc.arguments[i];
                const auto& exp = tc.expected[i];

                if (op == "Graph") {
                    auto [n, edges] = get<pair<int,EdgeList>>(arg);
                    g = new Graph(n, edges);
                    cout << "  Graph(" << n << ", edges) -> null\n";
                } else if (op == "addEdge") {
                    g->addEdge(get<vector<int>>(arg));
                    cout << "  addEdge([...]) -> null\n";
                } else if (op == "shortestPath") {
                    auto [u, v] = get<pair<int,int>>(arg);
                    int res = g->shortestPath(u, v);
                    cout << "  shortestPath(" << u << ',' << v << ") -> " << res;
                    cout << ((exp && res == *exp) ? "  [PASS]\n" : "  [FAIL]\n");
                }
            }
            delete g;
            cout << '\n';
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
            int res = solver.maximumSafenessFactor(testCases[i].grid);
            cout << "Safest Path Test " << (i + 1) << ": res = "
                << (res == testCases[i].expected ? "PASS" : "FAIL")
                << " (Expected: " << testCases[i].expected
                << ", Got: " << res << ")\n";
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

            int dRec  = solver.maxDepthRecursive(root);
            int dStk  = solver.maxDepthDFSStack(root);
            int dBfs  = solver.maxDepthBFSQueue(root);

            bool pass = (dRec == testCases[i].expected &&
                        dStk == testCases[i].expected &&
                        dBfs == testCases[i].expected);

            cout << "MaxDepth Test " << (i + 1) << ": "
                << (pass ? "PASS" : "FAIL")
                << " (Expected " << testCases[i].expected
                << ", got rec="   << dRec
                << ", stack="     << dStk
                << ", queue="     << dBfs << ")\n";

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
            auto rooms = testCases[i].rooms;          // copy so we can mutate
            solver.wallsAndGates(rooms);

            cout << "Walls & Gates Test " << (i + 1) << ": res = "
                << (rooms == testCases[i].expected ? "PASS" : "FAIL")
                << endl;
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
            bool result = solver.isNumber(testCases[i].input);
            cout << "ValidNumber_65 Test " << (i + 1) << ": res = "
                << (result == testCases[i].expected ? "PASS" : "FAIL")
                << " (input: \"" << testCases[i].input << "\")" << endl;
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
            int result = solver.numJewelsInStones(testCases[i].jewels,
                                                testCases[i].stones);

            cout << "Jewels & Stones Test " << (i + 1) << ": res = "
                << (result == testCases[i].expected ? "PASS" : "FAIL")
                << " (Expected: " << testCases[i].expected
                << ", Got: "      << result << ")\n";
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
            bool res = solver.isPerfectSquare(cases[i].input);
            cout << "ValidPerfectSquare_367 Test " << (i + 1) << ": res = "
                << (res == cases[i].expected ? "PASS" : "FAIL")
                << " (Expected: " << (cases[i].expected ? "true" : "false")
                << ", Got: "      << (res ? "true" : "false") << ")\n";
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
            int res = solver.numSquares(testCases[i].input);
            cout << "PerfectSquares_279 Test " << (i + 1) << ": res = "
                << (res == testCases[i].expected ? "PASS" : "FAIL")
                << " (n=" << testCases[i].input
                << ", Expected: " << testCases[i].expected
                << ", Got: " << res << ")\n";
        }
    }

    static void sameTree_100_tests()
    {
        vector<SameTreeTestCase> cases = {
            {{1,2,3},        {1,2,3},        true},   // Example 1
            {{1,2},          {1,nullopt,2},  false},  // Example 2
            {{1,2,1},        {1,1,2},        false},  // Example 3
            // a few extra sanity checks
            {{},             {},             true},
            {{1,nullopt,2,3},{1,nullopt,2,3},true},
            {{10,nullopt,20,15,nullopt,nullopt,25,nullopt,nullopt,22,nullopt},
                             {10,nullopt,20,15,nullopt,nullopt,25,nullopt,nullopt,22,nullopt},
                             true},
        };

        SameTree_100 sol;
        for (size_t i = 0; i < cases.size(); ++i) {
            auto pTree = TreeUtils::vectorToTree<int>(cases[i].p);
            auto qTree = TreeUtils::vectorToTree<int>(cases[i].q);

            bool r1 = sol.isSameTreeRecursive(pTree, qTree);
            bool r2 = sol.isSameTreeIterativeDFS(pTree, qTree);
            bool r3 = sol.isSameTreeBFSQueue(pTree, qTree);

            cout << "SameTree_100 Test " << (i + 1) << ": "
                << ((r1 == cases[i].expected &&
                    r2 == cases[i].expected &&
                    r3 == cases[i].expected) ? "PASS" : "FAIL")
                << endl;
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
            int res = solution.missingNumber(testCases[i].input);
            cout << "Missing Number Test " << (i + 1) << ": res = "
                 << (res == testCases[i].expected ? "PASS" : "FAIL")
                 << " (Expected: " << testCases[i].expected
                 << ", Got: " << res << ")\n";
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
            auto out = solver.dailyTemperatures(tests[i].input);
            bool pass = (out == tests[i].expected);

            cout << "Daily Temperatures Test " << (i + 1) << ": res = "
                << (pass ? "PASS" : "FAIL");

            // On failure, print both expected and actual for quick inspection
            if (!pass) {
                cout << "  (Expected: ";
                for (int x : tests[i].expected) cout << x << ' ';
                cout << " | Got: ";
                for (int x : out) cout << x << ' ';
                cout << ')';
            }
            cout << '\n';
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
        vector<int> bigUnique;
        bigUnique.reserve(10000);
        for (int i = -5000; i < 5000; ++i) bigUnique.push_back(i);
        tests.push_back({ move(bigUnique), false });

        ContainsDuplicate_217 sol;

        for (size_t i = 0; i < tests.size(); ++i) {
            bool got = sol.containsDuplicate(tests[i].input);
            cout << "ContainsDuplicate 217 Test " << (i + 1) << ": res = "
                << (got == tests[i].expected ? "PASS" : "FAIL")
                << " (Expected: " << (tests[i].expected ? "true" : "false")
                << ", Got: " << (got ? "true" : "false") << ")\n";
        }

        // Bonus: stress variant with a large array + one duplicate appended
        vector<int> bigWithDup;
        bigWithDup.reserve(10001);
        for (int i = -5000; i < 5000; ++i) bigWithDup.push_back(i);
        bigWithDup.push_back(123); // duplicate
        bool got = sol.containsDuplicate(bigWithDup);
        cout << "ContainsDuplicate 217 Stress: "
            << (got ? "PASS" : "FAIL") << " (Expected: true, Got: "
            << (got ? "true" : "false") << ")\n";
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
            cout << "Fibonacci 509 Test " << (i + 1) << ": res = "
                << (got == tests[i].expected ? "PASS" : "FAIL")
                << " (n=" << tests[i].n
                << ", Expected: " << tests[i].expected
                << ", Got: " << got << ")\n";
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
            cout << "Climbing Stairs 70 Test " << (i + 1) << ": res = "
                << (got == tests[i].expected ? "PASS" : "FAIL")
                << " (n=" << tests[i].n
                << ", Expected: " << tests[i].expected
                << ", Got: " << got << ")\n";
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
            cout << "Min Cost Climbing Stairs 746 Test " << (i + 1) << ": res = "
                << (got == tests[i].expected ? "PASS" : "FAIL")
                << " (Expected: " << tests[i].expected
                << ", Got: " << got << ")\n";
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
            cout << "House Robber 198 Test " << (i + 1) << ": res = "
                << (got == tests[i].expected ? "PASS" : "FAIL")
                << " (Expected: " << tests[i].expected
                << ", Got: " << got << ")\n";
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
            cout << "Last Stone Weight 1046 Test " << (i + 1) << ": res = "
                << (got == tests[i].expected ? "PASS" : "FAIL")
                << " (Expected: " << tests[i].expected
                << ", Got: " << got << ")\n";
        }
    }

    static void topKFrequent_347_tests() {
        // Helper: compare ignoring order
        auto sameUnordered = [](vector<int> a, vector<int> b) {
            if (a.size() != b.size()) return false;
            sort(a.begin(), a.end());
            sort(b.begin(), b.end());
            return a == b;
        };

        vector<TopKFrequent347TestCase> tests = {
            // 2 from the statement
            {{1,1,1,2,2,3}, 2, {1,2}},
            {{1},           1, {1}},

            // 4 additional
            {{1,1,2,2,2,3}, 1, {2}},                 // single most frequent
            {{-1,-1,-1,0,0,2,2,2,2,3,3}, 2, {2,-1}}, // mixed signs, distinct freqs
            {{}, 3, {7,8,9}},                        // placeholder, will fill below
            {{}, 2, {42,-7}}                         // placeholder, will fill below
        };

        // Fill test 5: counts 7x'7', 6x'8', 5x'9' → k=3 => {7,8,9}
        {
            vector<int> v;
            v.reserve(7 + 6 + 5 + 4 + 3); // a bit extra
            v.insert(v.end(), 7, 7);
            v.insert(v.end(), 6, 8);
            v.insert(v.end(), 5, 9);
            v.insert(v.end(), 4, 10);
            v.insert(v.end(), 3, 11);
            tests[4] = { move(v), 3, {7,8,9} };
        }
        // Fill test 6: 42 appears 100x, -7 appears 80x, rest unique once
        {
            vector<int> v;
            v.reserve(100 + 80 + 1000);
            v.insert(v.end(), 100, 42);
            v.insert(v.end(),  80, -7);
            for (int i = 1; i <= 1000; ++i) v.push_back(10000 + i); // many uniques
            tests[5] = { move(v), 2, {42, -7} };
        }

        TopKFrequentElements_347 sol;
        for (size_t i = 0; i < tests.size(); ++i) {
            auto got = sol.topKFrequent(tests[i].input, tests[i].k);
            bool pass = sameUnordered(got, tests[i].expected);

            cout << "Top K Frequent 347 Test " << (i + 1) << ": "
                << (pass ? "PASS" : "FAIL")
                << " (k=" << tests[i].k << ")\n";
            if (!pass) {
                auto g = got, e = tests[i].expected;
                sort(g.begin(), g.end()); sort(e.begin(), e.end());
                cout << "  Expected: ["; for (size_t j=0;j<e.size();++j){cout<<e[j]<<(j+1<e.size()?", ":"");}
                cout << "]  Got: ["; for (size_t j=0;j<g.size();++j){cout<<g[j]<<(j+1<g.size()?", ":"");}
                cout << "]\n";
            }
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
            {{-1,1,2,-2},          1}     // tie at distance 1 → prefer +1
        };

        FindClosestNumberToZero_2239 sol;
        for (size_t i = 0; i < tests.size(); ++i) {
            int got = sol.findClosestNumber(tests[i].input);
            cout << "Find Closest Number to Zero 2239 Test " << (i + 1) << ": "
                << ((got == tests[i].expected) ? "PASS" : "FAIL")
                << " (Expected: " << tests[i].expected
                << ", Got: " << got << ")\n";
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
            cout << "Merge Strings Alternately 1768 Test " << (i + 1) << ": "
                << ((got == tests[i].expected) ? "PASS" : "FAIL")
                << " (Expected: \"" << tests[i].expected << "\", Got: \"" << got << "\")\n";
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
            cout << "Roman to Integer 13 Test " << (i + 1) << ": "
                << ((got == tests[i].expected) ? "PASS" : "FAIL")
                << " (\"" << tests[i].input << "\" -> Expected: " << tests[i].expected
                << ", Got: " << got << ")\n";
        }
    }

    static void isSubsequence_392_tests() {
        vector<IsSubsequence392TestCase> tests = {
            {"abc", "ahbgdc", true},
            {"axc", "ahbgdc", false},
            {"",    "ahbgdc", true},
            {"a",   "",        false},
            {"aaaaaa", "baaaacaa", true},
            {"abc", "acb", false}
        };

        for (size_t i = 0; i < tests.size(); ++i) {
            // (1) Two-pointer: no preprocessing
            IsSubsequence_392 plain;
            bool a = plain.isSubsequence_TwoPointer(tests[i].s, tests[i].t);

            // (2) Preprocess pos-index once, then query
            IsSubsequence_392 idxPos;
            idxPos.preprocess_PosIndex(tests[i].t);
            bool b = idxPos.isSubsequence_PosIndex(tests[i].s);

            // (3) Preprocess next-position table once, then query
            IsSubsequence_392 idxNext;
            idxNext.preprocess_NextTable(tests[i].t);
            bool c = idxNext.isSubsequence_NextTable(tests[i].s);

            auto pr = [&](const char* tag, bool got) {
                cout << "Is Subsequence 392 Test " << (i + 1) << " [" << tag << "]: "
                    << ((got == tests[i].expected) ? "PASS" : "FAIL")
                    << " (s=\"" << tests[i].s << "\", t=\"" << tests[i].t
                    << "\", Expected: " << (tests[i].expected ? "true" : "false")
                    << ", Got: " << (got ? "true" : "false") << ")\n";
            };
            pr("two-pointer", a);
            pr("pos-index",   b);
            pr("next-table",  c);
        }

        vector<IsSubsequence392FollowUpCase> futests = {
            {"ahbgdc", { {"abc", true}, {"axc", false}, {"agc", true}, {"", true}, {"aaaa", false} }},
            {"leetcode", { {"leet", true}, {"code", true}, {"leot", false}, {"leetcode", true} }}
        };

        for (size_t b = 0; b < futests.size(); ++b) {
            IsSubsequence_392 idxPos, idxNext;
            idxPos.preprocess_PosIndex(futests[b].t);
            idxNext.preprocess_NextTable(futests[b].t);

            for (size_t qi = 0; qi < futests[b].queries.size(); ++qi) {
                const auto& [qs, expected] = futests[b].queries[qi];
                bool a = IsSubsequence_392().isSubsequence_TwoPointer(qs, futests[b].t);
                bool p = idxPos.isSubsequence_PosIndex(qs);
                bool n = idxNext.isSubsequence_NextTable(qs);

                auto pr = [&](const char* tag, bool got) {
                    cout << "Is Subsequence 392 Follow-up Block " << (b + 1)
                        << " Query " << (qi + 1) << " [" << tag << "]: "
                        << ((got == expected) ? "PASS" : "FAIL")
                        << " (s=\"" << qs << "\", t=\"" << futests[b].t
                        << "\", Expected: " << (expected ? "true" : "false")
                        << ", Got: " << (got ? "true" : "false") << ")\n";
                };
                pr("two-pointer", a);
                pr("pos-index",   p);
                pr("next-table",  n);
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
            bool gotP = idxPos .isSubsequence_PosIndex  (qs[i].s);
            bool pass = (gotN == qs[i].expected) && (gotP == qs[i].expected);

            cout << "Is Subsequence 392 (nextPos) Big Test " << (i + 1) << ": "
                << (pass ? "PASS" : "FAIL")
                << " (|s|=" << qs[i].s.size()
                << ", Expected: " << (qs[i].expected ? "true" : "false")
                << ", Got(next)=" << (gotN ? "true" : "false")
                << ", Got(pos)="  << (gotP ? "true" : "false")
                << ")\n";
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
            string got = sol.longestCommonPrefix_Linear(tcs[i].strs);

            // Cross-check against the sort variant
            string got2 = sol.longestCommonPrefix_Sort(tcs[i].strs);
            if (got != got2) {
                cout << "[WARN] Sort-variant mismatch on case " << (i+1)
                     << "  primary='" << got << "' sort='" << got2 << "'\n";
            }

            cout << "LCP14 Test " << (i + 1) << ": res = "
                << (got == tcs[i].expected ? "PASS" : "FAIL")
                << " (Expected: \"" << tcs[i].expected << "\", Got: \"" << got << "\")\n";
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

            assertEqStrings("Summary Ranges 228 Test " + to_string(i + 1),
                                    tests[i].expected, got);
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
            assertEqVIntPrefix(
                "Remove Duplicates 26 Test " + to_string(i + 1),
                tests[i].expected, a, k
            );
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
            auto arr = tests[i].nums;  // method takes non-const ref by signature style
            int got = sol.jump(arr);
            bool pass = (got == tests[i].expected);

            cout << "Jump Game II 45 Test " << (i + 1) << ": "
                << (pass ? "PASS" : "FAIL") << '\n';
            if (!pass) {
                cout << "  Expected: " << tests[i].expected
                    << "  Got: " << got << '\n';
            }
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
            auto arr = tests[i].nums;  // method takes non-const ref by project style
            bool got = sol.canJump(arr);
            bool pass = (got == tests[i].expected);

            cout << "Jump Game 55 Test " << (i + 1) << ": "
                << (pass ? "PASS" : "FAIL") << '\n';
            if (!pass) {
                cout << "  Expected: " << (tests[i].expected ? "true" : "false")
                    << "  Got: " << (got ? "true" : "false") << '\n';
            }
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
            assertEqVVIntExact(
                "Subsets 78 (bitmask) Test " + to_string(i + 1),
                tests[i].expected, got
            );

            // Recursive/backtracking variant: order-insensitive comparison.
            in  = tests[i].nums;
            got = sol.subsets_recursive(in);
            assertEqVVIntAnyOrder(
                "Subsets 78 (recursive) Test " + to_string(i + 1),
                tests[i].expected, got
            );
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

            assertEqVVIntPermutations(
                "Permutations 46 Test " + to_string(i + 1),
                tests[i].expected,
                got
            );
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

            assertEqVVIntAnyOrder(
                "Combinations 77 Test " + to_string(i + 1),
                tests[i].expected,
                got
            );
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

            assertEqStringsAnyOrder(
                "Letter Combinations 17 Test " + to_string(i + 1),
                tests[i].expected,
                got
            );
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

            assertEqVVIntAnyOrder(
                "Combination Sum 39 Test " + to_string(i + 1),
                tests[i].expected,
                got
            );
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

            assertEqStringsAnyOrder(
                "Generate Parentheses 22 Test " + to_string(i + 1),
                tests[i].expected,
                got
            );
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
            cout << "ExamRoom_855 Case " << (t + 1) << ":\n";

            optional<ExamRoom_855> er; // automatic storage, constructed on demand

            const auto& C = cases[t];
            for (size_t i = 0; i < C.operations.size(); ++i) {
                const auto& op  = C.operations[i];
                const auto& a   = C.arguments[i];
                const auto& exp = C.expected[i];

                if (op == "ExamRoom" || op == "ExamRoom_855") {
                    er.emplace(a[0]);
                    cout << "  ExamRoom_855(" << a[0] << ") -> null\n";
                } else if (op == "seat") {
                    int res = er->seat();
                    bool pass = (exp && res == *exp);
                    cout << "  seat() -> " << res << (pass ? " [PASS]\n" : " [FAIL]\n");
                } else if (op == "leave") {
                    er->leave(a[0]);
                    cout << "  leave(" << a[0] << ") -> null\n";
                }
            }
            cout << '\n';
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
