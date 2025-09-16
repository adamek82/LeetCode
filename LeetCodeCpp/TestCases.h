#pragma once
#include <vector>
#include <string>
#include <utility>  // for move

using namespace std;

namespace TestCases {

    // Common aliases reused across problems
    using Edges    = vector<vector<int>>;
    using GridChar = vector<vector<char>>;
    using GridInt  = vector<vector<int>>;
    using Points   = vector<vector<int>>;      // e.g., [[x,y], ...]
    using Coords   = vector<vector<int>>;      // e.g., [[r,c], ...]
    using List     = vector<int>;

    // 207. Course Schedule
    struct ScheduleTestCase {
        int   numCourses;
        Edges prerequisites;
        bool  expectedResult;

        // Note: pass-by-value + move to allow braced init without extra copies.
        ScheduleTestCase(int num, Edges prereq, bool result)
            : numCourses(num), prerequisites(move(prereq)), expectedResult(result) {}
    };

    // 1971. Find if Path Exists in Graph
    struct PathTestCase {
        int   n;
        Edges edges;
        int   source;
        int   destination;
        bool  expectedResult;

        PathTestCase(int nodes, Edges edg, int src, int dest, bool result)
            : n(nodes), edges(move(edg)), source(src), destination(dest), expectedResult(result) {}
    };

    // 200. Number of Islands
    struct NumIslandsTestCase {
        GridChar grid;
        int      expected;

        NumIslandsTestCase(GridChar g, int exp)
            : grid(move(g)), expected(exp) {}
    };

    // 695. Max Area of Island
    struct MaxAreaTestCase {
        GridInt grid;
        int     expected;

        MaxAreaTestCase(GridInt g, int exp)
            : grid(move(g)), expected(exp) {}
    };

    // 210. Course Schedule II
    struct CourseScheduleIITestCase {
        int        numCourses;
        Edges      prerequisites;
        vector<int> expectedOrder;  // empty means "cycle → no valid order"

        CourseScheduleIITestCase(int num, Edges prereq, vector<int> expected)
            : numCourses(num),
              prerequisites(move(prereq)),
              expectedOrder(move(expected)) {}
    };

    // 743. Network Delay Time
    struct NetworkDelayTimeTestCase {
        vector<vector<int>> times;
        int n;
        int k;
        int expected;

        NetworkDelayTimeTestCase(vector<vector<int>> t, int nodes, int start, int e)
            : times(move(t)), n(nodes), k(start), expected(e) {}
    };

    // 994. Rotting Oranges
    struct RottingOrangesTestCase {
        GridInt grid;
        int     expected;

        RottingOrangesTestCase(GridInt g, int e)
            : grid(move(g)), expected(e) {}
    };

    // 417. Pacific Atlantic Water Flow
    struct PacificAtlanticTestCase {
        GridInt heights; // heights matrix
        Coords  expected; // list of [r,c] coordinates (order-insensitive)

        PacificAtlanticTestCase(GridInt h, Coords e)
            : heights(move(h)), expected(move(e)) {}
    };

    // 1584. Min Cost to Connect All Points
    struct MinCostToConnectAllPointsTestCase {
        Points points;
        int    expected;

        MinCostToConnectAllPointsTestCase(Points p, int e)
            : points(move(p)), expected(e) {}
    };

    // Longest Common Subsequence
    struct LongestCommonSubsequenceTestCase {
        string text1;
        string text2;
        int         expected;

        LongestCommonSubsequenceTestCase(string t1, string t2, int e)
            : text1(move(t1)), text2(move(t2)), expected(e) {}
    };

    // 300. Longest Increasing Subsequence
    struct LongestIncreasingSubsequenceTestCase {
        List nums;
        int  expected;

        LongestIncreasingSubsequenceTestCase(List n, int e)
            : nums(move(n)), expected(e) {}
    };

    // 83. Remove Duplicates from Sorted List (LL)
    struct RemoveDuplicatesTestCase {
        List input;
        List expected;

        RemoveDuplicatesTestCase(List in, List exp)
            : input(move(in)), expected(move(exp)) {}
    };

    // 206. Reverse Linked List
    struct ReverseListTestCase {
        List input;
        List expected;

        ReverseListTestCase(List in, List exp)
            : input(move(in)), expected(move(exp)) {}
    };

    // 21. Merge Two Sorted Lists
    struct MergeTwoListsTestCase {
        List list1;
        List list2;
        List expected;

        MergeTwoListsTestCase(List a, List b, List exp)
            : list1(move(a)), list2(move(b)), expected(move(exp)) {}
    };

    // 141. Linked List Cycle
    struct LinkedListCycleTestCase {
        List input;
        int  pos;
        bool expected;

        LinkedListCycleTestCase(List in, int cyclePos, bool exp)
            : input(move(in)), pos(cyclePos), expected(exp) {}
    };
} // namespace TestCases
