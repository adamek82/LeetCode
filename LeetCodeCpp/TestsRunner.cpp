#include <iostream>
#include <string>
#include <vector>
#include <optional>
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

struct ScheduleTestCase {
    int numCourses;
    std::vector<std::vector<int>> prerequisites;
    bool expectedResult;
};

struct PathTestCase {
    int n;
    std::vector<std::vector<int>> edges;
    int source;
    int destination;
    bool expectedResult;
};

struct NumIslandsTestCase {
    std::vector<std::vector<char>> grid;
    int expectedResult;

    NumIslandsTestCase(std::vector<std::vector<char>> g, int e) : grid(g), expectedResult(e) {}
};

struct MaxAreaTestCase {
    std::vector<std::vector<int>> grid;
    int expectedResult;
    MaxAreaTestCase(std::vector<std::vector<int>> g, int e) : grid(g), expectedResult(e) {}
};

struct CourseScheduleIITestCase {
    int numCourses;
    std::vector<std::vector<int>> prerequisites;
    std::vector<int> expectedOrder;  // An empty vector means no valid order (cycle detected)
};

struct NetworkDelayTimeTestCase {
    std::vector<std::vector<int>> times;
    int n;
    int k;
    int expectedResult;
};

struct RottingOrangesTestCase {
    std::vector<std::vector<int>> grid;
    int expectedResult;

    RottingOrangesTestCase(std::vector<std::vector<int>> g, int e) : grid(g), expectedResult(e) {}
};

struct PacificAtlanticTestCase {
    std::vector<std::vector<int>> heights;
    std::vector<std::vector<int>> expectedResult;

    PacificAtlanticTestCase(std::vector<std::vector<int>> h, std::vector<std::vector<int>> e)
        : heights(h), expectedResult(e) {}
};

struct MinCostToConnectAllPointsTestCase {
    std::vector<std::vector<int>> points;
    int expectedResult;

    MinCostToConnectAllPointsTestCase(std::vector<std::vector<int>> p, int e) : points(p), expectedResult(e) {}
};

struct LongestCommonSubsequenceTestCase {
    std::string text1;
    std::string text2;
    int expectedResult;

    LongestCommonSubsequenceTestCase(std::string t1, std::string t2, int e)
        : text1(t1), text2(t2), expectedResult(e) {}
};

struct LongestIncreasingSubsequenceTestCase {
    std::vector<int> nums;
    int expectedResult;

    LongestIncreasingSubsequenceTestCase(std::vector<int> n, int e) : nums(n), expectedResult(e) {}
};

struct RemoveDuplicatesTestCase {
    std::vector<int> inputList;
    std::vector<int> expectedList;

    RemoveDuplicatesTestCase(std::vector<int> input, std::vector<int> expected)
        : inputList(input), expectedList(expected) {}
};

struct ReverseListTestCase {
    std::vector<int> inputList;
    std::vector<int> expectedList;

    ReverseListTestCase(std::vector<int> input, std::vector<int> expected)
        : inputList(input), expectedList(expected) {}
};

struct MergeTwoListsTestCase {
    std::vector<int> list1;
    std::vector<int> list2;
    std::vector<int> expectedList;

    MergeTwoListsTestCase(std::vector<int> l1, std::vector<int> l2, std::vector<int> expected)
        : list1(l1), list2(l2), expectedList(expected) {}
};

struct LinkedListCycleTestCase {
    std::vector<int> inputList;
    int pos;
    bool expectedResult;

    LinkedListCycleTestCase(std::vector<int> input, int cyclePos, bool expected)
        : inputList(input), pos(cyclePos), expectedResult(expected) {}
};

struct MiddleOfLinkedListTestCase {
    std::vector<int> inputList;
    std::vector<int> expectedList;

    MiddleOfLinkedListTestCase(std::vector<int> input, std::vector<int> expected)
        : inputList(input), expectedList(expected) {}
};

struct RemoveNthNodeTestCase {
    std::vector<int> inputList;
    int n;
    std::vector<int> expectedList;

    RemoveNthNodeTestCase(std::vector<int> input, int nth, std::vector<int> expected)
        : inputList(input), n(nth), expectedList(expected) {}
};

struct MaxProfitTestCase {
    std::vector<int> prices;
    int expectedResult;

    MaxProfitTestCase(std::vector<int> p, int e) : prices(p), expectedResult(e) {}
};

struct SpiralMatrixTestCase {
    std::vector<std::vector<int>> matrix;
    std::vector<int> expectedResult;

    SpiralMatrixTestCase(std::vector<std::vector<int>> m, std::vector<int> e)
        : matrix(m), expectedResult(e) {}
};

struct ValidateBinarySearchTreeTestCase {
    std::vector<std::optional<int>> tree; // Input as vector
    bool expectedResult;                  // Expected output

    ValidateBinarySearchTreeTestCase(std::vector<std::optional<int>> t, bool e)
        : tree(t), expectedResult(e) {}
};

struct LowestCommonAncestorTestCase {
    std::vector<std::optional<int>> tree; // Tree represented as a vector
    int p;                                // Value of the first node
    int q;                                // Value of the second node
    int expectedLCA;                      // Expected LCA value

    LowestCommonAncestorTestCase(const std::vector<std::optional<int>>& t, int node1, int node2, int lca)
        : tree(t), p(node1), q(node2), expectedLCA(lca) {}
};

struct CopyRandomListTestCase {
    std::vector<std::pair<int, std::optional<int>>> inputList;
    std::vector<std::pair<int, std::optional<int>>> expectedList;

    CopyRandomListTestCase(std::vector<std::pair<int, std::optional<int>>> input,
                           std::vector<std::pair<int, std::optional<int>>> expected)
        : inputList(input), expectedList(expected) {}
};

struct KthSmallestTestCase {
    std::vector<std::optional<int>> tree; // Tree represented as a vector
    int k;                                // kth position
    int expectedResult;                   // Expected result

    KthSmallestTestCase(const std::vector<std::optional<int>>& t, int kVal, int e)
        : tree(t), k(kVal), expectedResult(e) {}
};

class TestsRunner {
public:
    static void courseSchedule_207_tests() {
        std::vector<ScheduleTestCase> testCases = {
            {2, {{1, 0}}, true},
            {2, {{1, 0}, {0, 1}}, false},
            {5, {{0, 1}, {2, 3}, {3, 4}, {2, 1}}, true},
            {5, {{0, 1}, {2, 3}, {3, 4}, {2, 1}, {4, 2}}, false},
        };

        CourseSchedule_207 cs207;

        for (size_t i = 0; i < testCases.size(); ++i) {
            bool result = cs207.canFinish(testCases[i].numCourses, testCases[i].prerequisites);
            std::cout << "Test " << (i + 1) << ": res = "
                << (result == testCases[i].expectedResult ? "PASS" : "FAIL") << std::endl;
        }
    }

    static void findIfPathExistsInGraph_1971_tests() {
        std::vector<PathTestCase> testCases = {
            {3, {{0, 1}, {1, 2}, {2, 0}}, 0, 2, true},
            {6, {{0, 1}, {0, 2}, {3, 5}, {5, 4}, {4, 3}}, 0, 5, false},
            {4, {{0, 1}, {1, 2}, {2, 3}}, 0, 3, true},
            {5, {{0, 4}, {4, 3}, {3, 2}, {2, 1}}, 0, 1, true},
            {4, {{0, 1}, {1, 2}}, 0, 3, false},
        };

        FindIfPathExistsInGraph_1971 fp1971;

        std::cout << "-> Recursive DFS version:\n";
        for (size_t i = 0; i < testCases.size(); ++i) {
            bool result = fp1971.validPathRecursiveDFS(testCases[i].n, testCases[i].edges, testCases[i].source, testCases[i].destination);
            std::cout << "Test " << (i + 1) << ": res = "
                      << (result == testCases[i].expectedResult ? "PASS" : "FAIL") << std::endl;
        }

        std::cout << "-> Iterative DFS version with a stack:\n";
        for (size_t i = 0; i < testCases.size(); ++i) {
            bool result = fp1971.validPathIterativeDFS(testCases[i].n, testCases[i].edges, testCases[i].source, testCases[i].destination);
            std::cout << "Test " << (i + 1) << ": res = "
                      << (result == testCases[i].expectedResult ? "PASS" : "FAIL") << std::endl;
        }

        std::cout << "-> BFS version with a queue:\n";
        for (size_t i = 0; i < testCases.size(); ++i) {
            bool result = fp1971.validPathBFS(testCases[i].n, testCases[i].edges, testCases[i].source, testCases[i].destination);
            std::cout << "Test " << (i + 1) << ": res = "
                      << (result == testCases[i].expectedResult ? "PASS" : "FAIL") << std::endl;
        }

        std::cout << "-> Union-find version:\n";
        for (size_t i = 0; i < testCases.size(); ++i) {
            bool result = fp1971.validPathUnionFind(testCases[i].n, testCases[i].edges, testCases[i].source, testCases[i].destination);
            std::cout << "Test " << (i + 1) << ": res = "
                      << (result == testCases[i].expectedResult ? "PASS" : "FAIL") << std::endl;
        }
    }

    static void numIslands_200_tests()
    {
        // Define test cases
        std::vector<NumIslandsTestCase> testCases = {
            NumIslandsTestCase({{'1', '1', '1', '1', '0'},
                                {'1', '1', '0', '1', '0'},
                                {'1', '1', '0', '0', '0'},
                                {'0', '0', '0', '0', '0'}},
                               1),

            NumIslandsTestCase({{'1', '1', '0', '0', '0'},
                                {'1', '1', '0', '0', '0'},
                                {'0', '0', '1', '0', '0'},
                                {'0', '0', '0', '1', '1'}},
                               3),

            // Additional test case 1
            NumIslandsTestCase({{'1', '0', '0', '0', '1'},
                                {'0', '1', '1', '1', '0'},
                                {'0', '1', '0', '1', '0'},
                                {'1', '0', '0', '0', '1'}},
                               5), // Expected output: 5 (each isolated "1" or group of "1"s is an island)

            // Additional test case 2
            NumIslandsTestCase({{'1', '1', '1'},
                                {'0', '1', '0'},
                                {'1', '1', '1'}},
                               1) // Expected output: 1 (entire grid is a single connected island)
        };

        NumberOfIslands_200 noi200;

        // Run test cases
        for (size_t i = 0; i < testCases.size(); i++)
        {
            int result = noi200.numIslands(testCases[i].grid);
            std::cout << "Test " << i + 1 << ": res = " << (result == testCases[i].expectedResult ? "PASS" : "FAIL")
                      << " (Expected: " << testCases[i].expectedResult << ", Got: " << result << ")" << std::endl;
        }
    }

    static void maxAreaOfIsland_695_tests() {
        std::vector<MaxAreaTestCase> testCases = {
            MaxAreaTestCase({{0,0,1,0,0,0,0,1,0,0,0,0,0},
                             {0,0,0,0,0,0,0,1,1,1,0,0,0},
                             {0,1,1,0,1,0,0,0,0,0,0,0,0},
                             {0,1,0,0,1,1,0,0,1,0,1,0,0},
                             {0,1,0,0,1,1,0,0,1,1,1,0,0},
                             {0,0,0,0,0,0,0,0,0,0,1,0,0},
                             {0,0,0,0,0,0,0,1,1,1,0,0,0},
                             {0,0,0,0,0,0,0,1,1,0,0,0,0}}, 6),

            MaxAreaTestCase({{0,0,0,0,0,0,0,0}}, 0),  // Expected output: 0 (no land)

            // Additional test case 1
            MaxAreaTestCase({{1, 1, 0, 0, 1, 1},
                             {1, 0, 0, 0, 1, 1},
                             {0, 0, 1, 1, 1, 0},
                             {0, 0, 1, 0, 1, 1}}, 10), // Expected output: 10

            // Additional test case 2
            MaxAreaTestCase({{0, 1, 1, 1},
                             {1, 1, 0, 0},
                             {1, 0, 0, 1},
                             {1, 1, 1, 0}}, 9)  // Expected output: 9
        };

        MaxAreaOfIsland_695 mai695;

        for (size_t i = 0; i < testCases.size(); i++) {
            int result = mai695.maxAreaOfIsland(testCases[i].grid);
            std::cout << "Max Area Test " << i + 1 << ": res = "
                      << (result == testCases[i].expectedResult ? "PASS" : "FAIL")
                      << " (Expected: " << testCases[i].expectedResult << ", Got: " << result << ")" << std::endl;
        }
    }

    static void courseScheduleII_210_tests() {
        std::vector<CourseScheduleIITestCase> testCases = {
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
        std::function<bool(const std::vector<int>&, int, const std::vector<std::vector<int>>&, const std::vector<int>&)>
        isValidOrder = [](const std::vector<int>& order, int numCourses,
                          const std::vector<std::vector<int>>& prerequisites,
                          const std::vector<int>& expectedOrder) {
            // If expectedOrder is empty, we expect an empty result (cycle case)
            if (expectedOrder.empty()) return order.empty();

            // Create a position map to check the order of prerequisites
            std::unordered_map<int, int> position;
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

        std::cout << "-> DFS-based topological sort version:\n";
        for (size_t i = 0; i < testCases.size(); ++i) {
            std::vector<int> result = cs210.findOrderByDFSTraversal(testCases[i].numCourses, testCases[i].prerequisites);

            bool pass = isValidOrder(result, testCases[i].numCourses, testCases[i].prerequisites, testCases[i].expectedOrder);

            std::cout << "Test " << (i + 1) << ": res = " << (pass ? "PASS" : "FAIL") << std::endl;
        }

        std::cout << "-> Kahn's algorithm version:\n";
        for (size_t i = 0; i < testCases.size(); ++i) {
            std::vector<int> result = cs210.findOrderByKahnsAlgorithm(testCases[i].numCourses, testCases[i].prerequisites);

            bool pass = isValidOrder(result, testCases[i].numCourses, testCases[i].prerequisites, testCases[i].expectedOrder);

            std::cout << "Test " << (i + 1) << ": res = " << (pass ? "PASS" : "FAIL") << std::endl;
        }
    }

    static void networkDelayTime_743_tests() {
        std::vector<NetworkDelayTimeTestCase> testCases = {
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
            std::cout << "Network Delay Time Test " << (i + 1) << ": res = "
                      << (result == testCases[i].expectedResult ? "PASS" : "FAIL")
                      << " (Expected: " << testCases[i].expectedResult << ", Got: " << result << ")" << std::endl;
        }
    }

    static void rottingOranges_994_tests()
    {
        std::vector<RottingOrangesTestCase> testCases = {
            RottingOrangesTestCase({{2, 1, 1}, {1, 1, 0}, {0, 1, 1}}, 4),  // Example 1
            RottingOrangesTestCase({{2, 1, 1}, {0, 1, 1}, {1, 0, 1}}, -1), // Example 2
            RottingOrangesTestCase({{0, 2}}, 0),                           // Example 3
            // Additional Test Case 1
            RottingOrangesTestCase({{2, 1, 1, 0, 0, 1, 2},
                                    {1, 0, 0, 0, 1, 1, 0},
                                    {0, 1, 2, 1, 0, 1, 0},
                                    {0, 1, 0, 2, 2, 1, 0}},
                                   3),
            // Additional Test Case 2
            RottingOrangesTestCase({{2, 2, 1, 1, 1, 0, 0},
                                    {0, 1, 1, 2, 1, 1, 0},
                                    {1, 1, 0, 1, 1, 2, 1},
                                    {2, 0, 0, 1, 1, 1, 1},
                                    {0, 0, 1, 1, 0, 0, 0}},
                                   4)};

        RottingOranges_994 solution;

        for (size_t i = 0; i < testCases.size(); ++i)
        {
            int result = solution.orangesRotting(testCases[i].grid);
            std::cout << "Rotting Oranges Test " << i + 1 << ": res = "
                      << (result == testCases[i].expectedResult ? "PASS" : "FAIL")
                      << " (Expected: " << testCases[i].expectedResult << ", Got: " << result << ")" << std::endl;
        }
    }

    static void pacificAtlantic_417_tests()
    {
        std::vector<PacificAtlanticTestCase> testCases = {
            // Example 1
            PacificAtlanticTestCase({{1, 2, 2, 3, 5},
                                     {3, 2, 3, 4, 4},
                                     {2, 4, 5, 3, 1},
                                     {6, 7, 1, 4, 5},
                                     {5, 1, 1, 2, 4}},
                                    {{0, 4}, {1, 3}, {1, 4}, {2, 2}, {3, 0}, {3, 1}, {4, 0}}),

            // Example 2
            PacificAtlanticTestCase({{1}}, {{0, 0}}),

            // Additional Test Case 1
            PacificAtlanticTestCase({{10, 10, 10},
                                     {10, 1, 10},
                                     {10, 10, 10}},
                                    {{0, 0}, {0, 1}, {0, 2}, {1, 0}, {1, 2}, {2, 0}, {2, 1}, {2, 2}}),

            // Additional Test Case 2
            PacificAtlanticTestCase({{1, 2, 2, 3, 5},
                                     {3, 2, 3, 4, 4},
                                     {2, 4, 5, 6, 7},
                                     {6, 7, 8, 9, 10}},
                                    {{0, 4}, {1, 3}, {1, 4}, {2, 3}, {2, 4}, {3, 0}, {3, 1}, {3, 2}, {3, 3}, {3, 4}}),

            // Additional Test Case 3
            PacificAtlanticTestCase({{5, 5, 5, 5, 5},
                                     {5, 1, 1, 1, 5},
                                     {5, 1, 1, 1, 5},
                                     {5, 1, 1, 1, 5},
                                     {5, 5, 5, 5, 5}},
                                    {{0, 0}, {0, 1}, {0, 2}, {0, 3}, {0, 4}, {1, 0}, {1, 4}, {2, 0}, {2, 4}, {3, 0}, {3, 4}, {4, 0}, {4, 1}, {4, 2}, {4, 3}, {4, 4}})};

        PacificAtlanticWaterFlow_417 pacificAtlanticSolution;

        for (size_t i = 0; i < testCases.size(); ++i)
        {
            auto result = pacificAtlanticSolution.pacificAtlantic(testCases[i].heights);

            std::cout << "Test " << (i + 1) << ": res = "
                      << (result == testCases[i].expectedResult ? "PASS" : "FAIL") << std::endl;
        }
    }

    static void minCostToConnectAllPoints_1584_tests() {
        std::vector<MinCostToConnectAllPointsTestCase> testCases = {
            // Provided examples
            MinCostToConnectAllPointsTestCase({{0, 0}, {2, 2}, {3, 10}, {5, 2}, {7, 0}}, 20),
            MinCostToConnectAllPointsTestCase({{3, 12}, {-2, 5}, {-4, 1}}, 18),

            // Additional complex examples
            MinCostToConnectAllPointsTestCase({{1, 1}, {3, 3}, {7, 7}, {10, 10}, {15, 15}}, 28), // Sequential points
            MinCostToConnectAllPointsTestCase({{0, 0}, {1, 1}, {1, 0}, {0, 1}, {2, 2}}, 5), // Compact grid
            MinCostToConnectAllPointsTestCase({{-100, -100}, {100, 100}, {-100, 100}, {100, -100}}, 600), // Distant points
        };

        MinCostToConnectAllPoints_1584 solution;

        for (size_t i = 0; i < testCases.size(); ++i) {
            int result = solution.minCostConnectPoints(testCases[i].points);
            std::cout << "Min Cost Test " << (i + 1) << ": res = "
                    << (result == testCases[i].expectedResult ? "PASS" : "FAIL")
                    << " (Expected: " << testCases[i].expectedResult << ", Got: " << result << ")" << std::endl;
        }
    }

    static void longestCommonSubsequence_tests() {
        std::vector<LongestCommonSubsequenceTestCase> testCases = {
            // Provided examples
            LongestCommonSubsequenceTestCase("abcde", "ace", 3), // Example 1
            LongestCommonSubsequenceTestCase("abc", "abc", 3),   // Example 2
            LongestCommonSubsequenceTestCase("abc", "def", 0),   // Example 3

            // Additional complex examples
            LongestCommonSubsequenceTestCase("abcdefghijabcdefghij", "acegikacegik", 10), // Alternating match
            LongestCommonSubsequenceTestCase("abcdefghijklmnopqrst", "zyxwvutsrqponmlkjih", 1) // No common subsequence
        };

        LongestCommonSubsequence_1143 solution;

        for (size_t i = 0; i < testCases.size(); ++i) {
            int result = solution.longestCommonSubsequence(testCases[i].text1, testCases[i].text2);
            std::cout << "LCS Test " << i + 1 << ": res = "
                    << (result == testCases[i].expectedResult ? "PASS" : "FAIL")
                    << " (Expected: " << testCases[i].expectedResult
                    << ", Got: " << result << ")" << std::endl;
        }
    }

    static void longestIncreasingSubsequence_tests() {
        std::vector<LongestIncreasingSubsequenceTestCase> testCases = {
            // Provided examples
            LongestIncreasingSubsequenceTestCase({10, 9, 2, 5, 3, 7, 101, 18}, 4), // Example 1
            LongestIncreasingSubsequenceTestCase({0, 1, 0, 3, 2, 3}, 4),           // Example 2
            LongestIncreasingSubsequenceTestCase({7, 7, 7, 7, 7, 7, 7}, 1),        // Example 3

            // Additional complex examples
            LongestIncreasingSubsequenceTestCase({3, 10, 2, 1, 20, 4, 6, 21, 22, 23}, 6), // Example 4
            LongestIncreasingSubsequenceTestCase({9, 2, 5, 3, 7, 101, 18, 9, 4, 5, 6, 7, 8}, 7) // Example 5
        };

        LongestIncreasingSubsequence_300 solution; // Assuming your LIS solution is implemented in this class

        for (size_t i = 0; i < testCases.size(); ++i) {
            int result = solution.lengthOfLIS(testCases[i].nums);
            std::cout << "LIS Test " << i + 1 << ": res = "
                    << (result == testCases[i].expectedResult ? "PASS" : "FAIL")
                    << " (Expected: " << testCases[i].expectedResult
                    << ", Got: " << result << ")" << std::endl;
        }
    }

    static void removeDuplicatesFromSortedList_83_tests() {
        using IntListNode = ListNode<int>;

        // Define test cases
        std::vector<RemoveDuplicatesTestCase> testCases = {
            // Provided examples
            RemoveDuplicatesTestCase({1, 1, 2}, {1, 2}),
            RemoveDuplicatesTestCase({1, 1, 2, 3, 3}, {1, 2, 3}),

            // Additional complex test cases
            RemoveDuplicatesTestCase({1, 1, 1, 1, 1}, {1}),                         // Single value repeated many times
            RemoveDuplicatesTestCase({1, 2, 2, 3, 3, 4, 4, 5, 5, 6}, {1, 2, 3, 4, 5, 6}), // Alternating duplicates
            RemoveDuplicatesTestCase({-10, -10, -5, 0, 0, 1, 1, 2, 2, 2, 100}, {-10, -5, 0, 1, 2, 100}), // Mixed negative and positive numbers
        };

        RemoveDuplicatesFromSortedList_83 solution;

        for (size_t i = 0; i < testCases.size(); ++i) {
            // Create a linked list using ListUtils
            IntListNode* input = ListUtils::createLinkedList<int>(testCases[i].inputList);

            // Run the solution
            IntListNode* result = solution.deleteDuplicates(input);

            // Convert result to vector
            std::vector<int> resultVector = ListUtils::toVector<int>(result);

            // Print test results
            std::cout << "Remove Duplicates Test " << i + 1 << ": res = "
                    << (resultVector == testCases[i].expectedList ? "PASS" : "FAIL")
                    << " (Expected: " << ListUtils::toString<int>(ListUtils::createLinkedList<int>(testCases[i].expectedList))
                    << ", Got: " << ListUtils::toString<int>(result) << ")" << std::endl;

            // Free the allocated linked list
            ListUtils::freeList<int>(result);
        }
    }

    static void reverseLinkedList_206_tests() {
        using IntListNode = ListNode<int>;

        // Define test cases
        std::vector<ReverseListTestCase> testCases = {
            // Provided examples
            ReverseListTestCase({1, 2, 3, 4, 5}, {5, 4, 3, 2, 1}),
            ReverseListTestCase({1, 2}, {2, 1}),
            ReverseListTestCase({}, {}),

            // Additional complex test cases
            ReverseListTestCase({-5, -4, -3, -2, -1}, {-1, -2, -3, -4, -5}), // Negative values
            ReverseListTestCase({10, 20, 30, 40, 50, 60}, {60, 50, 40, 30, 20, 10}) // Longer list
        };

        ReverseLinkedList_206 solution;

        for (size_t i = 0; i < testCases.size(); ++i) {
            // Create a linked list using ListUtils
            IntListNode* input = ListUtils::createLinkedList<int>(testCases[i].inputList);

            // Run the solution
            IntListNode* result = solution.reverseList(input);

            // Convert result to vector
            std::vector<int> resultVector = ListUtils::toVector<int>(result);

            // Print test results
            std::cout << "Reverse Linked List Test " << i + 1 << ": res = "
                    << (resultVector == testCases[i].expectedList ? "PASS" : "FAIL")
                    << " (Expected: " << ListUtils::toString<int>(ListUtils::createLinkedList<int>(testCases[i].expectedList))
                    << ", Got: " << ListUtils::toString<int>(result) << ")" << std::endl;

            // Free the allocated linked list
            ListUtils::freeList<int>(result);
        }
    }

    static void mergeTwoSortedLists_21_tests() {
        using IntListNode = ListNode<int>;

        // Define test cases
        std::vector<MergeTwoListsTestCase> testCases = {
            // Provided examples
            MergeTwoListsTestCase({1, 2, 4}, {1, 3, 4}, {1, 1, 2, 3, 4, 4}),
            MergeTwoListsTestCase({}, {}, {}),
            MergeTwoListsTestCase({}, {0}, {0}),

            // Additional complex test cases
            MergeTwoListsTestCase({-10, -5, 0, 3}, {-8, -6, 2, 4}, {-10, -8, -6, -5, 0, 2, 3, 4}),
            MergeTwoListsTestCase({1, 3, 5, 7}, {2, 4, 6, 8, 10}, {1, 2, 3, 4, 5, 6, 7, 8, 10})
        };

        MergeTwoSortedLists_21 solution;

        for (size_t i = 0; i < testCases.size(); ++i) {
            // Create linked lists using ListUtils
            IntListNode* list1 = ListUtils::createLinkedList<int>(testCases[i].list1);
            IntListNode* list2 = ListUtils::createLinkedList<int>(testCases[i].list2);

            // Run the solution
            IntListNode* result = solution.mergeTwoLists(list1, list2);

            // Convert result to vector
            std::vector<int> resultVector = ListUtils::toVector<int>(result);

            // Print test results
            std::cout << "Merge Two Sorted Lists Test " << i + 1 << ": res = "
                    << (resultVector == testCases[i].expectedList ? "PASS" : "FAIL")
                    << " (Expected: " << ListUtils::toString<int>(ListUtils::createLinkedList<int>(testCases[i].expectedList))
                    << ", Got: " << ListUtils::toString<int>(result) << ")" << std::endl;

            // Free the allocated merged list
            ListUtils::freeList<int>(result);
        }
    }

    static void hasCycle_141_tests() {
        std::vector<LinkedListCycleTestCase> testCases = {
            // Provided examples
            LinkedListCycleTestCase({3, 2, 0, -4}, 1, true),
            LinkedListCycleTestCase({1, 2}, 0, true),
            LinkedListCycleTestCase({1}, -1, false),

            // Additional examples
            LinkedListCycleTestCase({1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, 4, true),
            LinkedListCycleTestCase({10, 20, 30, 40, 50, 60, 70, 80}, 2, true)
        };

        LinkedListCycle_141 solution;

        for (size_t i = 0; i < testCases.size(); ++i) {
            // Create a linked list with a cycle
            ListNode<int>* head = ListUtils::createLinkedListWithCycle<int>(testCases[i].inputList, testCases[i].pos);

            // Run the hasCycle function
            bool result = solution.hasCycle(head);

            // Print test results
            std::cout << "Test " << (i + 1) << ": res = "
                      << (result == testCases[i].expectedResult ? "PASS" : "FAIL")
                      << " (Expected: " << testCases[i].expectedResult
                      << ", Got: " << result << ")\n"
                      << "List: " << ListUtils::toString<int>(head) << std::endl;

            // Free the linked list
            ListUtils::freeList<int>(head);
        }
    }

    static void middleOfLinkedList_876_tests() {
        using IntListNode = ListNode<int>;

        std::vector<MiddleOfLinkedListTestCase> testCases = {
            // Provided examples
            MiddleOfLinkedListTestCase({1, 2, 3, 4, 5}, {3, 4, 5}),
            MiddleOfLinkedListTestCase({1, 2, 3, 4, 5, 6}, {4, 5, 6}),

            // Additional test cases
            MiddleOfLinkedListTestCase({}, {}),                         // Edge case: empty list
            MiddleOfLinkedListTestCase({1}, {1}),                       // Edge case: single element
            MiddleOfLinkedListTestCase({1, 2, 3, 4, 5, 6, 7}, {4, 5, 6, 7}) // Odd-length list
        };

        MiddleOfLinkedList_876 solution;

        for (size_t i = 0; i < testCases.size(); ++i) {
            // Create a linked list using ListUtils
            IntListNode* input = ListUtils::createLinkedList<int>(testCases[i].inputList);

            // Run the solution
            IntListNode* result = solution.middleNode(input);

            // Convert result to vector
            std::vector<int> resultVector = ListUtils::toVector<int>(result);

            // Print test results
            std::cout << "Middle of Linked List Test " << i + 1 << ": res = "
                    << (resultVector == testCases[i].expectedList ? "PASS" : "FAIL")
                    << " (Expected: " << ListUtils::toString<int>(ListUtils::createLinkedList<int>(testCases[i].expectedList))
                    << ", Got: " << ListUtils::toString<int>(result) << ")" << std::endl;

            // Free the allocated linked list
            ListUtils::freeList<int>(input);
        }
    }

    static void removeNthFromEnd_tests() {
        using IntListNode = ListNode<int>;

        std::vector<RemoveNthNodeTestCase> testCases = {
            // Provided examples
            RemoveNthNodeTestCase({1, 2, 3, 4, 5}, 2, {1, 2, 3, 5}),
            RemoveNthNodeTestCase({1}, 1, {}),
            RemoveNthNodeTestCase({1, 2}, 1, {1}),

            // Additional test cases
            RemoveNthNodeTestCase({10, 20, 30, 40, 50, 60, 70}, 3, {10, 20, 30, 40, 60, 70}), // Bigger list
            RemoveNthNodeTestCase({5, 10, 15, 20}, 4, {10, 15, 20}) // Removing the head
        };

        RemoveNthNodeFromEndOfList_19 solution;

        for (size_t i = 0; i < testCases.size(); ++i) {
            // Create a linked list using ListUtils
            IntListNode* input = ListUtils::createLinkedList<int>(testCases[i].inputList);

            // Run the solution
            IntListNode* result = solution.removeNthFromEnd(input, testCases[i].n);

            // Convert result to vector
            std::vector<int> resultVector = ListUtils::toVector<int>(result);

            // Print test results
            std::cout << "Remove Nth Node From End Test " << i + 1 << ": res = "
                    << (resultVector == testCases[i].expectedList ? "PASS" : "FAIL")
                    << " (Expected: " << ListUtils::toString<int>(ListUtils::createLinkedList<int>(testCases[i].expectedList))
                    << ", Got: " << ListUtils::toString<int>(result) << ")" << std::endl;

            // Free the allocated linked list
            ListUtils::freeList<int>(result);
        }
    }

    static void maxProfit_121_tests() {
        std::vector<MaxProfitTestCase> testCases = {
            // Provided examples
            MaxProfitTestCase({7, 1, 5, 3, 6, 4}, 5),  // Example 1
            MaxProfitTestCase({7, 6, 4, 3, 1}, 0),    // Example 2

            // Additional complex test cases
            MaxProfitTestCase({1, 2, 3, 4, 5, 6, 7, 8, 9}, 8),       // Buy on day 1, sell on day 9
            MaxProfitTestCase({9, 8, 7, 1, 5, 3, 6, 4}, 5),          // Buy on day 4, sell on day 7

            // Edge case
            MaxProfitTestCase({5}, 0)  // Single price: no transactions possible
        };

        BestTimeToBuyAndSellStock_121 solution;

        for (size_t i = 0; i < testCases.size(); ++i) {
            int result = solution.maxProfit(testCases[i].prices);
            std::cout << "Max Profit Test " << i + 1 << ": res = "
                    << (result == testCases[i].expectedResult ? "PASS" : "FAIL")
                    << " (Expected: " << testCases[i].expectedResult << ", Got: " << result << ")" << std::endl;
        }
    }

    static void spiralMatrix_54_tests() {
        std::vector<SpiralMatrixTestCase> testCases = {
            // Provided examples
            SpiralMatrixTestCase({{1, 2, 3}, {4, 5, 6}, {7, 8, 9}}, {1, 2, 3, 6, 9, 8, 7, 4, 5}),
            SpiralMatrixTestCase({{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}}, {1, 2, 3, 4, 8, 12, 11, 10, 9, 5, 6, 7}),

            // Additional test cases
            // Edge case: Single element matrix
            SpiralMatrixTestCase({{1}}, {1}),

            // More complicated matrix: Rectangular (more rows)
            SpiralMatrixTestCase({{1, 2}, {3, 4}, {5, 6}, {7, 8}}, {1, 2, 4, 6, 8, 7, 5, 3}),

            // More complicated matrix: Rectangular (more columns)
            SpiralMatrixTestCase({{1, 2, 3, 4, 5}, {6, 7, 8, 9, 10}}, {1, 2, 3, 4, 5, 10, 9, 8, 7, 6}),
        };

        SpiralMatrix_54 sm54;

        for (size_t i = 0; i < testCases.size(); ++i) {
            std::vector<int> result = sm54.spiralOrder(testCases[i].matrix);
            std::cout << "Spiral Matrix Test " << (i + 1) << ": res = "
                    << (result == testCases[i].expectedResult ? "PASS" : "FAIL")
                    << " (Expected: ";
            for (int val : testCases[i].expectedResult) std::cout << val << " ";
            std::cout << ", Got: ";
            for (int val : result) std::cout << val << " ";
            std::cout << ")" << std::endl;
        }
    }

    static void validateBinarySearchTree_98_tests() {
        std::vector<ValidateBinarySearchTreeTestCase> testCases = {
            // Provided examples
            ValidateBinarySearchTreeTestCase({2, 1, 3}, true),
            ValidateBinarySearchTreeTestCase({5, 1, 4, std::nullopt, std::nullopt, 3, 6}, false),

            // Additional complex test cases
            ValidateBinarySearchTreeTestCase({10, 5, 15, std::nullopt, std::nullopt, 6, 20}, false), // Violates BST in right subtree
            ValidateBinarySearchTreeTestCase({3, 1, 5, 0, 2, 4, 6}, true),                          // Valid BST
            ValidateBinarySearchTreeTestCase({1, std::nullopt, 2, std::nullopt, 3, std::nullopt, 4}, true) // Skewed right
        };

        ValidateBinarySearchTree_98 validator;

        for (size_t i = 0; i < testCases.size(); ++i) {
            TreeNode<int>* root = TreeUtils::vectorToTree(testCases[i].tree);

            std::cout << "Test Case " << (i + 1) << " Tree:" << std::endl;
            TreeUtils::printTree(root); // Print the tree

            bool result = validator.isValidBST(root);

            std::cout << "Validate BST Test " << (i + 1) << ": res = "
                    << (result == testCases[i].expectedResult ? "PASS" : "FAIL")
                    << " (Expected: " << (testCases[i].expectedResult ? "true" : "false")
                    << ", Got: " << (result ? "true" : "false") << ")" << std::endl;

            TreeUtils::freeTree(root); // Free the memory after use
        }
    }

    static void lowestCommonAncestor_235_tests() {
        std::vector<LowestCommonAncestorTestCase> testCases = {
            // Example 1
            LowestCommonAncestorTestCase({6, 2, 8, 0, 4, 7, 9, std::nullopt, std::nullopt, 3, 5}, 2, 8, 6),
            // Example 2
            LowestCommonAncestorTestCase({6, 2, 8, 0, 4, 7, 9, std::nullopt, std::nullopt, 3, 5}, 2, 4, 2),
            // Example 3
            LowestCommonAncestorTestCase({2, 1}, 2, 1, 2),
            // Additional Complex Test 1
            LowestCommonAncestorTestCase({10, 5, 15, 3, 8, 12, 20, 1, 4, 7, 9, std::nullopt, std::nullopt, 18, 25}, 4, 9, 5),
            // Additional Complex Test 2
            LowestCommonAncestorTestCase({30, 10, 50, 5, 20, 40, 60, std::nullopt, 8, 15, 25, 35, 45, std::nullopt, 70}, 15, 45, 30),
        };

        LowestCommonAncestorOfBST_235 lcaSolver;

        for (size_t i = 0; i < testCases.size(); ++i) {
            TreeNode<int>* root = TreeUtils::vectorToTree(testCases[i].tree);
            TreeNode<int>* p = TreeUtils::findNode(root, testCases[i].p);
            TreeNode<int>* q = TreeUtils::findNode(root, testCases[i].q);

            TreeNode<int>* result = lcaSolver.lowestCommonAncestor(root, p, q);

            std::cout << "LCA Test " << (i + 1) << ": res = "
                    << ((result && result->val == testCases[i].expectedLCA) ? "PASS" : "FAIL")
                    << " (Expected: " << testCases[i].expectedLCA << ", Got: " << (result ? result->val : -1) << ")" << std::endl;

            TreeUtils::freeTree(root);
        }
    }

    static void copyRandomList_tests() {
        using IntListNode = ListNode<int>;

        std::vector<CopyRandomListTestCase> testCases = {
            // Provided test cases
            CopyRandomListTestCase({{7, std::nullopt}, {13, 0}, {11, 4}, {10, 2}, {1, 0}},
                                {{7, std::nullopt}, {13, 0}, {11, 4}, {10, 2}, {1, 0}}),
            CopyRandomListTestCase({{1, 1}, {2, 1}}, {{1, 1}, {2, 1}}),
            CopyRandomListTestCase({{3, std::nullopt}, {3, 0}, {3, std::nullopt}},
                                {{3, std::nullopt}, {3, 0}, {3, std::nullopt}}),

            // Additional complex test cases
            CopyRandomListTestCase({{1, std::nullopt}, {2, 0}, {3, 1}, {4, 3}, {5, 2}},
                                {{1, std::nullopt}, {2, 0}, {3, 1}, {4, 3}, {5, 2}}),
            CopyRandomListTestCase({{10, 4}, {20, 3}, {30, 2}, {40, 1}, {50, std::nullopt}},
                                {{10, 4}, {20, 3}, {30, 2}, {40, 1}, {50, std::nullopt}})
        };

        CopyListWithRandomPointer_138 solution;

        for (size_t i = 0; i < testCases.size(); ++i) {
            IntListNode* input = ListUtils::createLinkedListWithRandom<int>(testCases[i].inputList);
            IntListNode* expected = ListUtils::createLinkedListWithRandom<int>(testCases[i].expectedList);

            IntListNode* result = solution.copyRandomList(input);

            bool isCorrect = ListUtils::compareListsWithRandom<int>(result, expected);

            std::cout << "Test " << (i + 1) << ": " << (isCorrect ? "PASS" : "FAIL") << std::endl;

            ListUtils::freeList(input);
            ListUtils::freeList(result);
            ListUtils::freeList(expected);
        }
    }

    static void kthSmallestElementInBST_230_tests() {
        std::vector<KthSmallestTestCase> testCases = {
            // Example 1
            KthSmallestTestCase({3, 1, 4, std::nullopt, 2}, 1, 1),
            // Example 2
            KthSmallestTestCase({5, 3, 6, 2, 4, std::nullopt, std::nullopt, 1}, 3, 3),
            // Additional Test 1: Larger balanced tree
            KthSmallestTestCase({15, 10, 20, 5, 13, 17, 25, 3, 8, std::nullopt, 14, 16, 18}, 6, 15),
            // Additional Test 2: Single node tree
            KthSmallestTestCase({42}, 1, 42),
            // Additional Test 3: Skewed tree
            KthSmallestTestCase({1, std::nullopt, 2, std::nullopt, 3, std::nullopt, 4}, 4, 4)
        };

        KthSmallestElementInBST_230 solution;

        for (size_t i = 0; i < testCases.size(); ++i) {
            TreeNode<int>* root = TreeUtils::vectorToTree(testCases[i].tree);

            int result = solution.kthSmallest(root, testCases[i].k);
            std::cout << "Kth Smallest Element Test " << (i + 1) << ": res = "
                    << (result == testCases[i].expectedResult ? "PASS" : "FAIL")
                    << " (Expected: " << testCases[i].expectedResult << ", Got: " << result << ")" << std::endl;

            TreeUtils::freeTree(root); // Free tree memory
        }
    }

    static void runAllTests() {
        std::cout << "Running CourseSchedule_207 tests:\n";
        courseSchedule_207_tests();
        std::cout << "Running FindIfPathExistsInGraph_1971 tests:\n";
        findIfPathExistsInGraph_1971_tests();
        std::cout << "Running NumberOfIslands_200 tests:\n";
        numIslands_200_tests();
        std::cout << "Running MaxAreaOfIsland_695 tests:\n";
        maxAreaOfIsland_695_tests();
        std::cout << "Running CourseScheduleII_210 tests:\n";
        courseScheduleII_210_tests();
        std::cout << "Running NetworkDelayTime_743 tests:\n";
        networkDelayTime_743_tests();
        std::cout << "Running RottingOranges_994 tests:\n";
        rottingOranges_994_tests();
        std::cout << "Running PacificAtlanticWaterFlow_417 tests:\n";
        pacificAtlantic_417_tests();
        std::cout << "Running MinCostToConnectAllPoints_1584 tests:\n";
        minCostToConnectAllPoints_1584_tests();
        std::cout << "Running LongestCommonSubsequence tests:\n";
        longestCommonSubsequence_tests();
        std::cout << "Running LongestIncreasingSubsequence_300 tests:\n";
        longestIncreasingSubsequence_tests();
        std::cout << "Running RemoveDuplicatesFromSortedList_83 tests:\n";
        removeDuplicatesFromSortedList_83_tests();
        std::cout << "Running ReverseLinkedListLeetcode_206 tests:\n";
        reverseLinkedList_206_tests();
        std::cout << "Running MergeTwoSortedLists_21 tests:\n";
        mergeTwoSortedLists_21_tests();
        std::cout << "Running LinkedListCycle_141 tests:\n";
        hasCycle_141_tests();
        std::cout << "Running MiddleOfLinkedList_876 tests:\n";
        middleOfLinkedList_876_tests();
        std::cout << "Running RemoveNthFromEnd tests:\n";
        removeNthFromEnd_tests();
        std::cout << "Running MaxProfit_121 tests:\n";
        maxProfit_121_tests();
        std::cout << "Running SpiralMatrix_54 tests:\n";
        spiralMatrix_54_tests();
        std::cout << "Running ValidateBinarySearchTree_98 tests:\n";
        validateBinarySearchTree_98_tests();
        std::cout << "Running LowestCommonAncestor_235 tests:\n";
        lowestCommonAncestor_235_tests();
        std::cout << "Running CopyListWithRandomPointer_138 tests:\n";
        copyRandomList_tests();
        std::cout << "Running KthSmallestElementInBST_230 tests:\n";
        kthSmallestElementInBST_230_tests();
    }
};

int main() {
    std::cout << "Running LeetCodeCpp tests:\n";
    TestsRunner::runAllTests();
    return 0;
}
