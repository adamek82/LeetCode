#pragma once
#include <vector>
#include <utility>  // for std::move

using namespace std;

namespace TestCases {

    // Common aliases reused across problems
    using Edges    = vector<vector<int>>;
    using GridChar = vector<vector<char>>;
    using GridInt  = vector<vector<int>>;

    // 207. Course Schedule
    struct ScheduleTestCase {
        int   numCourses;
        Edges prerequisites;
        bool  expectedResult;

        // Note: pass-by-value + move to allow braced init without extra copies.
        ScheduleTestCase(int num, Edges prereq, bool result)
            : numCourses(num), prerequisites(std::move(prereq)), expectedResult(result) {}
    };

    // 1971. Find if Path Exists in Graph
    struct PathTestCase {
        int   n;
        Edges edges;
        int   source;
        int   destination;
        bool  expectedResult;

        PathTestCase(int nodes, Edges edg, int src, int dest, bool result)
            : n(nodes), edges(std::move(edg)), source(src), destination(dest), expectedResult(result) {}
    };

    // 200. Number of Islands
    struct NumIslandsTestCase {
        GridChar grid;
        int      expected;

        NumIslandsTestCase(GridChar g, int exp)
            : grid(std::move(g)), expected(exp) {}
    };

    // 695. Max Area of Island
    struct MaxAreaTestCase {
        GridInt grid;
        int     expected;

        MaxAreaTestCase(GridInt g, int exp)
            : grid(std::move(g)), expected(exp) {}
    };

    // 210. Course Schedule II
    struct CourseScheduleIITestCase {
        int        numCourses;
        Edges      prerequisites;
        vector<int> expectedOrder;  // empty means "cycle → no valid order"

        CourseScheduleIITestCase(int num, Edges prereq, vector<int> expected)
            : numCourses(num),
              prerequisites(std::move(prereq)),
              expectedOrder(std::move(expected)) {}
    };
} // namespace TestCases
