#include "TestsGraphs.h"

#include <memory>
#include <optional>
#include <string>
#include <utility>
#include <variant>
#include <vector>

#include "TestCases.h"
#include "TestUtils.h"

#include "FindIfPathExistsInGraph_1971.h"
#include "NumberOfIslands_200.h"
#include "MaxAreaOfIsland_695.h"
#include "GraphNode.h"
#include "GraphUtils.h"
#include "CloneGraph_133.h"

#include "RottingOranges_994.h"
#include "ShortestPathInBinaryMatrix_1091.h"
#include "BusRoutes_815.h"
#include "SlidingPuzzle_773.h"

#include "CourseSchedule_207.h"
#include "CourseScheduleII_210.h"

#include "PacificAtlanticWaterFlow_417.h"
#include "LongestIncreasingPathInMatrix_329.h"

#include "NetworkDelayTime_743.h"
#include "DesignGraphWithShortestPathCalculator_2642.h"
#include "MinCostToConnectAllPoints_1584.h"

#include "LongestCycleInGraph_2360.h"
#include "ShortestCycleInGraph_2608.h"

#include "GameOfLife_289.h"
#include "WallsAndGates_286.h"
#include "IslandPerimeter_463.h"

using namespace std;
using namespace TestCases;
using namespace TestUtils;

namespace {

/* Basic graph / grid traversal for reachability and connected components */

static bool findIfPathExistsInGraph_1971_tests() {
    vector<FindIfPathExistsInGraphTestCase> testCases = {
        {3, {{0, 1}, {1, 2}, {2, 0}}, 0, 2, true},
        {6, {{0, 1}, {0, 2}, {3, 5}, {5, 4}, {4, 3}}, 0, 5, false},
        {4, {{0, 1}, {1, 2}, {2, 3}}, 0, 3, true},
        {5, {{0, 4}, {4, 3}, {3, 2}, {2, 1}}, 0, 1, true},
        {4, {{0, 1}, {1, 2}}, 0, 3, false},
    };

    FindIfPathExistsInGraph_1971 fp1971;

    auto runWith = [&](auto method, const FindIfPathExistsInGraphTestCase& tc) {
        return (fp1971.*method)(tc.n, tc.edges, tc.source, tc.destination);
    };

    using Method = bool (FindIfPathExistsInGraph_1971::*)(
        int, const vector<vector<int>>&, int, int
    );

    const vector<pair<string, Method>> impls = {
        {"DFS-rec",   &FindIfPathExistsInGraph_1971::validPathRecursiveDFS},
        {"DFS-iter",  &FindIfPathExistsInGraph_1971::validPathIterativeDFS},
        {"BFS",       &FindIfPathExistsInGraph_1971::validPathBFS},
        {"UnionFind", &FindIfPathExistsInGraph_1971::validPathUnionFind},
    };

    for (size_t i = 0; i < testCases.size(); ++i) {
        const auto& tc = testCases[i];
        for (const auto& [name, method] : impls) {

            const string label = "Find Path 1971 [" + name + "] " + to_string(i + 1);
            REQUIRE_ASSERT(assertEqScalar(label, tc.expected, runWith(method, tc)));
        }
    }

    return true;
}

static bool numIslands_200_tests()
{
    // Define test cases
    vector<NumberOfIslandsTestCase> testCases = {
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

        const string label = "Test " + to_string(i + 1);
        REQUIRE_ASSERT(assertEqScalar(label, testCases[i].expected, result));
    }

    return true;
}

static bool maxAreaOfIsland_695_tests() {
    vector<MaxAreaOfIslandTestCase> testCases = {
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

        const string base = "Max Area Test" + to_string(i + 1);
        REQUIRE_ASSERT(assertEqScalar(base + " (recursive)", testCases[i].expected, resRec));
        REQUIRE_ASSERT(assertEqScalar(base + " (iterative)", testCases[i].expected, resIter));
    }

    return true;
}

static bool cloneGraph_133_tests() {
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

        const string label = "Clone Graph 133 Test " + to_string(i + 1);
        REQUIRE_ASSERT(assertEqScalar(label, true, iso));

        GraphUtils::freeGraph(original);
        GraphUtils::freeGraph(cloned);
    }

    return true;
}

/* Shortest-path BFS on grids, transit networks, and implicit state graphs */

static bool rottingOranges_994_tests()
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

        const string label = "Test " + to_string(i + 1);
        REQUIRE_ASSERT(assertEqScalar(label, testCases[i].expected, result));
    }

    return true;
}

static bool shortestPathBinaryMatrix_1091_tests() {
    vector<ShortestPathInBinaryMatrixTestCase> testCases = {
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

        const string label = "Shortest Path Binary Matrix 1091 Test " + to_string(i + 1);
        REQUIRE_ASSERT(assertEqScalar(label, testCases[i].expected, got));
    }

    return true;
}

static bool busRoutes_815_tests() {
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

        const string label = "Bus Routes 815 Test " + to_string(i + 1);
        REQUIRE_ASSERT(assertEqScalar(label, cases[i].expected, got));
    }

    return true;
}

static bool slidingPuzzle_773_tests() {
    vector<SlidingPuzzleTestCase> testCases = {
        // examples from the statement
        {{{1,2,3},{4,0,5}}, 1},
        {{{1,2,3},{5,4,0}}, -1},
        {{{4,1,2},{5,0,3}}, 5},

        // already solved
        {{{1,2,3},{4,5,0}}, 0},

        // simple solvable cases
        {{{1,2,0},{4,5,3}}, 1},
        {{{1,0,3},{4,2,5}}, 2},
        {{{0,1,2},{4,5,3}}, 3},

        // unsolvable parity case
        {{{1,2,3},{5,4,0}}, -1},
    };

    SlidingPuzzle_773 solver;

    for (size_t i = 0; i < testCases.size(); ++i) {
        auto board = testCases[i].board;
        int got = solver.slidingPuzzle(board);

        const string label = "Sliding Puzzle 773 Test " + to_string(i + 1);
        REQUIRE_ASSERT(assertEqScalar(label, testCases[i].expected, got));
    }

    return true;
}

/* Directed-graph reasoning with topological order and cycle detection */

static bool courseSchedule_207_tests() {
    vector<CourseScheduleTestCase> testCases = {
        {2, {{1, 0}}, true},
        {2, {{1, 0}, {0, 1}}, false},
        {5, {{0, 1}, {2, 3}, {3, 4}, {2, 1}}, true},
        {5, {{0, 1}, {2, 3}, {3, 4}, {2, 1}, {4, 2}}, false},
    };

    CourseSchedule_207 solver;

    for (size_t i = 0; i < testCases.size(); ++i) {
        const auto& tc = testCases[i];
        const string base = "Course Schedule 207 Test " + to_string(i + 1);

        bool dfsGot = solver.canFinishDFS(tc.numCourses, tc.prerequisites);
        REQUIRE_ASSERT(assertEqScalar(base + " [DFS]", tc.expected, dfsGot));

        bool kahnGot = solver.canFinishKahns(tc.numCourses, tc.prerequisites);
        REQUIRE_ASSERT(assertEqScalar(base + " [Kahn]", tc.expected, kahnGot));
    }

    return true;
}

static bool courseScheduleII_210_tests() {
    vector<CourseScheduleIITestCase> testCases = {
        {2, {{1, 0}}, {0, 1}},
        {4, {{1, 0}, {2, 0}, {3, 1}, {3, 2}}, {0, 1, 2, 3}},
        {1, {}, {0}},
        {6, {{1, 0}, {2, 0}, {3, 4}, {5, 4}}, {0, 4, 1, 2, 3, 5}},
        {5, {{0, 1}, {1, 2}, {2, 3}, {3, 4}, {4, 0}}, {}},
    };

    auto isValidTopoOrder = [](int n, const vector<vector<int>>& prerequisites,
                            const vector<int>& order) {
        if ((int)order.size() != n) {
            return false;
        }

        vector<int> pos(n, -1);

        for (int i = 0; i < n; ++i) {
            int course = order[i];

            if (course < 0 || course >= n || pos[course] != -1) {
                return false;
            }

            pos[course] = i;
        }

        for (const auto& edge : prerequisites) {
            int course = edge[0];
            int prereq = edge[1];

            if (pos[prereq] > pos[course]) {
                return false;
            }
        }

        return true;
    };

    auto isExpectedResult = [&](const CourseScheduleIITestCase& tc,
                                const vector<int>& order) {
        if (tc.expectedOrder.empty()) {
            return order.empty();
        }

        return isValidTopoOrder(tc.numCourses, tc.prerequisites, order);
    };

    CourseScheduleII_210 solver;

    for (size_t i = 0; i < testCases.size(); ++i) {
        const auto& tc = testCases[i];
        const string base = "Course Schedule II 210 Test " + to_string(i + 1);

        auto dfsPrerequisites = tc.prerequisites;
        vector<int> dfsOrder = solver.findOrderByDFSTraversal(
            tc.numCourses,
            dfsPrerequisites);
        REQUIRE_ASSERT(assertEqScalar(
            base + " [DFS]",
            true,
            isExpectedResult(tc, dfsOrder)));

        auto kahnPrerequisites = tc.prerequisites;
        vector<int> kahnOrder = solver.findOrderByKahnsAlgorithm(
            tc.numCourses,
            kahnPrerequisites);
        REQUIRE_ASSERT(assertEqScalar(
            base + " [Kahn]",
            true,
            isExpectedResult(tc, kahnOrder)));
    }

    return true;
}

/* Graph traversal on matrices with directional / monotonic constraints */

static bool pacificAtlantic_417_tests()
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

        const string label = "Test " + to_string(i + 1);
        REQUIRE_ASSERT(assertEqVVIntExact(label, testCases[i].expected, result));
    }

    return true;
}

static bool longestIncreasingPathInMatrix_329_tests() {
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

        const string label = "Longest Increasing Path in Matrix 329 Test " + to_string(i + 1);
        REQUIRE_ASSERT(assertEqScalar(label, testCases[i].expected, got));
    }

    return true;
}

/* Weighted graph algorithms: shortest paths and minimum spanning tree */

static bool networkDelayTime_743_tests() {
    vector<NetworkDelayTimeTestCase> testCases = {
        // Provided examples
        {{{2, 1, 1}, {2, 3, 1}, {3, 4, 1}}, 4, 2, 2},
        {{{1, 2, 1}}, 2, 1, 1},
        {{{1, 2, 1}}, 2, 2, -1},

        // Additional complex example 1: 6 nodes
        {{{1, 2, 2}, {1, 3, 4}, {2, 4, 7}, {3, 4, 1},
        {2, 5, 5}, {5, 6, 3}, {4, 6, 2}},
        6, 1, 7},

        // Additional complex example 2: 8 nodes
        {{{1, 2, 2}, {1, 3, 1}, {3, 4, 4}, {2, 5, 7},
        {5, 6, 1}, {6, 7, 5}, {7, 8, 2}, {4, 8, 3}},
        8, 1, 15},
    };

    NetworkDelayTime_743 solver;

    for (size_t i = 0; i < testCases.size(); ++i) {
        const auto& tc = testCases[i];

        auto times = tc.times; // solver takes non-const ref
        int got = solver.networkDelayTime(times, tc.n, tc.k);

        const string label = "Network Delay Time 743 Test " + to_string(i + 1);
        REQUIRE_ASSERT(assertEqScalar(label, tc.expected, got));
    }

    return true;
}

static bool designGraphWithShortestPathCalculator_2642_tests() {
    using EdgeList = vector<vector<int>>;

    {
        const string base = "Graph_2642 official example";

        Graph g(4, EdgeList{{0, 2, 5}, {0, 1, 2}, {1, 2, 1}, {3, 0, 3}});

        REQUIRE_ASSERT(assertEqScalar(base + " shortestPath(3,2)", 6,
                                        g.shortestPath(3, 2)));
        REQUIRE_ASSERT(assertEqScalar(base + " shortestPath(0,3)", -1,
                                        g.shortestPath(0, 3)));

        g.addEdge({1, 3, 4});

        REQUIRE_ASSERT(assertEqScalar(base + " shortestPath(0,3) after addEdge", 6,
                                        g.shortestPath(0, 3)));
    }

    {
        const string base = "Graph_2642 empty graph then one edge";

        Graph g(2, EdgeList{});

        REQUIRE_ASSERT(assertEqScalar(base + " shortestPath(0,1)", -1,
                                        g.shortestPath(0, 1)));

        g.addEdge({0, 1, 10});

        REQUIRE_ASSERT(assertEqScalar(base + " shortestPath(0,1) after addEdge", 10,
                                        g.shortestPath(0, 1)));
    }

    {
        const string base = "Graph_2642 cheaper path appears after addEdge";

        Graph g(5, EdgeList{{0, 1, 3}, {1, 2, 4}, {2, 3, 5}, {3, 4, 6}, {0, 4, 20}});

        REQUIRE_ASSERT(assertEqScalar(base + " shortestPath(0,4)", 18,
                                        g.shortestPath(0, 4)));

        g.addEdge({1, 4, 1});

        REQUIRE_ASSERT(assertEqScalar(base + " shortestPath(0,4) after addEdge", 4,
                                        g.shortestPath(0, 4)));
    }

    return true;
}

static bool minCostToConnectAllPoints_1584_tests() {
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

        const string base = "Min Cost Test" + to_string(i + 1);
        REQUIRE_ASSERT(assertEqScalar(base + " (heap)", testCases[i].expected, resHeap));
        REQUIRE_ASSERT(assertEqScalar(base + " (array)", testCases[i].expected, resArray));
    }

    return true;
}

/* Cycle analysis in directed and undirected graphs */

static bool longestCycleInGraph_2360_tests() {
    vector<LongestCycleInGraphTestCase> testCases = {
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
        REQUIRE_ASSERT(assertEqScalar(label, testCases[i].expected, got));
    }

    return true;
}

static bool shortestCycleInGraph_2608_tests() {
    vector<ShortestCycleInGraphTestCase> cases = {
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

        const string label = "Shortest Cycle in Graph 2608 Test " + to_string(i + 1);
        REQUIRE_ASSERT(assertEqScalar(label, cases[i].expected, got));
    }

    return true;
}

/* Grid simulation, multi-source expansion, and neighbor-based reasoning */

static bool gameOfLife_289_tests() {
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

        const string label = "Game of Life Test " + to_string(i + 1);
        REQUIRE_ASSERT(assertEqVVIntExact(label, testCases[i].expected, board));
    }

    return true;
}

static bool wallsAndGates_286_tests() {
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

        const string label = "Walls & Gates 286 Test " + to_string(i + 1);
        REQUIRE_ASSERT(assertEqVVIntExact(label, testCases[i].expected, rooms));
    }

    return true;
}

static bool islandPerimeter_463_tests() {
    vector<IslandPerimeterTestCase> testCases = {
        // Example 1 from the statement
        {
            {
                {0,1,0,0},
                {1,1,1,0},
                {0,1,0,0},
                {1,1,0,0}
            },
            16
        },
        // Example 2
        {
            {
                {1}
            },
            4
        },
        // Example 3
        {
            {
                {1,0}
            },
            4
        },
        // Single land cell surrounded by water in a larger grid
        {
            {
                {0,0,0},
                {0,1,0},
                {0,0,0}
            },
            4
        },
        // Two adjacent horizontal land cells
        {
            {
                {1,1}
            },
            6
        },
        // Two adjacent vertical land cells
        {
            {
                {1},
                {1}
            },
            6
        }
    };

    IslandPerimeter_463 solver;

    for (size_t i = 0; i < testCases.size(); ++i) {
        int got = solver.islandPerimeter(testCases[i].grid);

        const string label = "Island Perimeter 463 Test " + to_string(i + 1);
        REQUIRE_ASSERT(assertEqScalar(label, testCases[i].expected, got));
    }

    return true;
}


} // namespace

namespace TestsGraphs {

std::vector<TestRegistry::Entry> getTests() {
    return {
        // Basic graph / grid traversal for reachability and connected components
        TEST(1971, "Find if Path Exists in Graph",                findIfPathExistsInGraph_1971_tests),
        TEST(200,  "Number of Islands",                           numIslands_200_tests),
        TEST(695,  "Max Area of Island",                          maxAreaOfIsland_695_tests),
        TEST(133,  "Clone Graph",                                 cloneGraph_133_tests),

        // Shortest-path BFS on grids, transit networks, and implicit state graphs
        TEST(994,  "Rotting Oranges",                             rottingOranges_994_tests),
        TEST(1091, "Shortest Path Binary Matrix",                 shortestPathBinaryMatrix_1091_tests),
        TEST(815,  "Bus Routes",                                  busRoutes_815_tests),
        TEST(773,  "Sliding Puzzle",                              slidingPuzzle_773_tests),

        // Directed-graph reasoning with topological order and cycle detection
        TEST(207,  "Course Schedule",                             courseSchedule_207_tests),
        TEST(210,  "Course Schedule II",                          courseScheduleII_210_tests),

        // Graph traversal on matrices with directional / monotonic constraints
        TEST(417,  "Pacific Atlantic Water Flow",                 pacificAtlantic_417_tests),
        TEST(329,  "Longest Increasing Path in a Matrix",         longestIncreasingPathInMatrix_329_tests),

        // Weighted graph algorithms: shortest paths and minimum spanning tree
        TEST(743,  "Network Delay Time",                          networkDelayTime_743_tests),
        TEST(2642, "Design Graph With Shortest Path Calculator",  designGraphWithShortestPathCalculator_2642_tests),
        TEST(1584, "Min Cost to Connect All Points",              minCostToConnectAllPoints_1584_tests),

        // Cycle analysis in directed and undirected graphs
        TEST(2360, "Longest Cycle in a Graph",                    longestCycleInGraph_2360_tests),
        TEST(2608, "Shortest Cycle in a Graph",                   shortestCycleInGraph_2608_tests),

        // Grid simulation, multi-source expansion, and neighbor-based reasoning
        TEST(289,  "Game of Life",                                gameOfLife_289_tests),
        TEST(286,  "Walls and Gates",                             wallsAndGates_286_tests),
        TEST(463,  "Island Perimeter",                            islandPerimeter_463_tests),
    };
}

} // namespace TestsGraphs
