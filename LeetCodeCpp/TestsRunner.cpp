#include <iostream>
#include <string>
#include <vector>
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
#include "RemoveDuplicatesFromSortedList_83.h"

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
    }
};

int main() {
    std::cout << "Running LeetCodeCpp tests:\n";
    TestsRunner::runAllTests();
    return 0;
}
