#pragma once

#include <optional>
#include <string>
#include <utility>
#include <variant>
#include <vector>

#include "tests/framework/TestCaseTypes.h"

namespace TestCases {

// 1971. Find if Path Exists in Graph
struct FindIfPathExistsInGraphTestCase {
    int n;
    Edges edges;
    int source;
    int destination;
    bool expected;
};
// 200. Number of Islands
struct NumberOfIslandsTestCase {
    GridChar grid;
    int expected;
};
// 695. Max Area of Island
struct MaxAreaOfIslandTestCase {
    GridInt grid;
    int expected;
};
// 994. Rotting Oranges
struct RottingOrangesTestCase {
    GridInt grid;
    int expected;
};
// 1091. Shortest Path in Binary Matrix
struct ShortestPathInBinaryMatrixTestCase {
    std::vector<std::vector<int>> grid;
    int expected;
};
// 815. Bus Routes
struct BusRoutesTestCase {
    std::vector<std::vector<int>> routes;
    int source;
    int target;
    int expected;
};
// 773. Sliding Puzzle
struct SlidingPuzzleTestCase {
    std::vector<std::vector<int>> board;
    int expected;
};
// 207. Course Schedule
struct CourseScheduleTestCase {
    int numCourses;
    Edges prerequisites;
    bool expected;
};
// 210. Course Schedule II
struct CourseScheduleIITestCase {
    int numCourses;
    Edges prerequisites;
    std::vector<int> expectedOrder;
};
// 417. Pacific Atlantic Water Flow
struct PacificAtlanticTestCase {
    GridInt heights;
    Coords expected;
};
// 329. Longest Increasing Path in a Matrix
struct LongestIncreasingPathInMatrixTestCase {
    GridInt matrix;
    int expected;
};
// 743. Network Delay Time
struct NetworkDelayTimeTestCase {
    std::vector<std::vector<int>> times;
    int n;
    int k;
    int expected;
};
// 2642. Design Graph With Shortest Path Calculator
struct DesignGraphWithShortestPathCalculatorTestCase {
    std::vector<std::string> operations;
    std::vector<std::variant<
        std::monostate,
        int,
        std::vector<int>,
        std::pair<int, int>,
        std::pair<int, std::vector<std::vector<int>>>>>
        arguments;
    std::vector<std::optional<int>> expected;
};

// 1584. Min Cost to Connect All Points
struct MinCostToConnectAllPointsTestCase {
    Points points;
    int expected;
};
// 2360. Longest Cycle in a Graph
struct LongestCycleInGraphTestCase {
    std::vector<int> edges;
    int expected;
};
// 2608. Shortest Cycle in a Graph
struct ShortestCycleInGraphTestCase {
    int n;
    std::vector<std::vector<int>> edges;
    int expected;
};
// 289. Game of Life
struct GameOfLifeTestCase {
    std::vector<std::vector<int>> input;
    std::vector<std::vector<int>> expected;
};
// 286. Walls and Gates
struct WallsAndGatesTestCase {
    std::vector<std::vector<int>> rooms;
    std::vector<std::vector<int>> expected;
};
// 463. Island Perimeter
struct IslandPerimeterTestCase {
    GridInt grid;
    int expected;
};
} // namespace TestCases
