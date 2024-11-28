#include <iostream>
#include <vector>
#include "CourseSchedule_207.h"
#include "FindIfPathExistsInGraph_1971.h"
#include "NumberOfIslands_200.h"
#include "MaxAreaOfIsland_695.h"
#include "CourseScheduleII_210.h"
#include "NetworkDelayTime_743.h"

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

        for (size_t i = 0; i < testCases.size(); ++i) {
            std::vector<int> result = cs210.findOrder(testCases[i].numCourses, testCases[i].prerequisites);

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
    }
};

int main() {
    std::cout << "Running LeetCodeCpp tests:\n";
    TestsRunner::runAllTests();
    return 0;
}
