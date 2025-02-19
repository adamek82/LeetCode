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

struct ScheduleTestCase {
    int numCourses;
    std::vector<std::vector<int>> prerequisites;
    bool expectedResult;

    ScheduleTestCase(int num, std::vector<std::vector<int>> prereq, bool result)
        : numCourses(num), prerequisites(std::move(prereq)), expectedResult(result) {}
};

struct PathTestCase {
    int n;
    std::vector<std::vector<int>> edges;
    int source;
    int destination;
    bool expectedResult;

    PathTestCase(int nodes, std::vector<std::vector<int>> edg, int src, int dest, bool result)
        : n(nodes), edges(std::move(edg)), source(src), destination(dest), expectedResult(result) {}
};

struct NumIslandsTestCase {
    std::vector<std::vector<char>> grid;
    int expectedResult;

    NumIslandsTestCase(std::vector<std::vector<char>> g, int e)
        : grid(std::move(g)), expectedResult(e) {}
};

struct MaxAreaTestCase {
    std::vector<std::vector<int>> grid;
    int expectedResult;

    MaxAreaTestCase(std::vector<std::vector<int>> g, int e)
        : grid(std::move(g)), expectedResult(e) {}
};

struct CourseScheduleIITestCase {
    int numCourses;
    std::vector<std::vector<int>> prerequisites;
    std::vector<int> expectedOrder;

    CourseScheduleIITestCase(int num, std::vector<std::vector<int>> prereq, std::vector<int> order)
        : numCourses(num), prerequisites(std::move(prereq)), expectedOrder(std::move(order)) {}
};

struct NetworkDelayTimeTestCase {
    std::vector<std::vector<int>> times;
    int n;
    int k;
    int expectedResult;

    NetworkDelayTimeTestCase(std::vector<std::vector<int>> t, int nodes, int start, int result)
        : times(std::move(t)), n(nodes), k(start), expectedResult(result) {}
};

struct RottingOrangesTestCase {
    std::vector<std::vector<int>> grid;
    int expectedResult;

    RottingOrangesTestCase(std::vector<std::vector<int>> g, int e)
        : grid(std::move(g)), expectedResult(e) {}
};

struct PacificAtlanticTestCase {
    std::vector<std::vector<int>> heights;
    std::vector<std::vector<int>> expectedResult;

    PacificAtlanticTestCase(std::vector<std::vector<int>> h, std::vector<std::vector<int>> e)
        : heights(std::move(h)), expectedResult(std::move(e)) {}
};

struct MinCostToConnectAllPointsTestCase {
    std::vector<std::vector<int>> points;
    int expectedResult;

    MinCostToConnectAllPointsTestCase(std::vector<std::vector<int>> p, int e)
        : points(std::move(p)), expectedResult(e) {}
};

struct LongestCommonSubsequenceTestCase {
    std::string text1;
    std::string text2;
    int expectedResult;

    LongestCommonSubsequenceTestCase(std::string t1, std::string t2, int e)
        : text1(std::move(t1)), text2(std::move(t2)), expectedResult(e) {}
};

struct LongestIncreasingSubsequenceTestCase {
    std::vector<int> nums;
    int expectedResult;

    LongestIncreasingSubsequenceTestCase(std::vector<int> n, int e)
        : nums(std::move(n)), expectedResult(e) {}
};

struct RemoveDuplicatesTestCase {
    std::vector<int> inputList;
    std::vector<int> expectedList;

    RemoveDuplicatesTestCase(std::vector<int> input, std::vector<int> expected)
        : inputList(std::move(input)), expectedList(std::move(expected)) {}
};

struct ReverseListTestCase {
    std::vector<int> inputList;
    std::vector<int> expectedList;

    ReverseListTestCase(std::vector<int> input, std::vector<int> expected)
        : inputList(std::move(input)), expectedList(std::move(expected)) {}
};

struct MergeTwoListsTestCase {
    std::vector<int> list1;
    std::vector<int> list2;
    std::vector<int> expectedList;

    MergeTwoListsTestCase(std::vector<int> l1, std::vector<int> l2, std::vector<int> expected)
        : list1(std::move(l1)), list2(std::move(l2)), expectedList(std::move(expected)) {}
};

struct LinkedListCycleTestCase {
    std::vector<int> inputList;
    int pos;
    bool expectedResult;

    LinkedListCycleTestCase(std::vector<int> input, int cyclePos, bool expected)
        : inputList(std::move(input)), pos(cyclePos), expectedResult(expected) {}
};

struct MiddleOfLinkedListTestCase {
    std::vector<int> inputList;
    std::vector<int> expectedList;

    MiddleOfLinkedListTestCase(std::vector<int> input, std::vector<int> expected)
        : inputList(std::move(input)), expectedList(std::move(expected)) {}
};

struct RemoveNthNodeTestCase {
    std::vector<int> inputList;
    int n;
    std::vector<int> expectedList;

    RemoveNthNodeTestCase(std::vector<int> input, int nth, std::vector<int> expected)
        : inputList(std::move(input)), n(nth), expectedList(std::move(expected)) {}
};

struct MaxProfitTestCase {
    std::vector<int> prices;
    int expectedResult;

    MaxProfitTestCase(std::vector<int> p, int e) : prices(std::move(p)), expectedResult(e) {}
};

struct SpiralMatrixTestCase {
    std::vector<std::vector<int>> matrix;
    std::vector<int> expectedResult;

    SpiralMatrixTestCase(std::vector<std::vector<int>> m, std::vector<int> e)
        : matrix(std::move(m)), expectedResult(std::move(e)) {}
};

struct ValidateBinarySearchTreeTestCase {
    std::vector<std::optional<int>> tree; // Input as vector
    bool expectedResult;                  // Expected output

    ValidateBinarySearchTreeTestCase(std::vector<std::optional<int>> t, bool e)
        : tree(std::move(t)), expectedResult(e) {}
};

struct LowestCommonAncestorTestCase {
    std::vector<std::optional<int>> tree; // Tree represented as a vector
    int p;                                // Value of the first node
    int q;                                // Value of the second node
    int expectedLCA;                      // Expected LCA value

    LowestCommonAncestorTestCase(const std::vector<std::optional<int>>& t, int node1, int node2, int lca)
        : tree(std::move(t)), p(node1), q(node2), expectedLCA(lca) {}
};

struct CopyRandomListTestCase {
    std::vector<std::pair<int, std::optional<int>>> inputList;
    std::vector<std::pair<int, std::optional<int>>> expectedList;

    CopyRandomListTestCase(std::vector<std::pair<int, std::optional<int>>> input,
                           std::vector<std::pair<int, std::optional<int>>> expected)
        : inputList(std::move(input)), expectedList(std::move(expected)) {}
};

struct KthSmallestTestCase {
    std::vector<std::optional<int>> tree; // Tree represented as a vector
    int k;                                // kth position
    int expectedResult;                   // Expected result

    KthSmallestTestCase(const std::vector<std::optional<int>>& t, int kVal, int e)
        : tree(std::move(t)), k(kVal), expectedResult(e) {}
};

struct TrieTestCase {
    std::vector<std::string> operations;
    std::vector<std::optional<std::string>> arguments;
    std::vector<std::optional<bool>> expectedResults;

    TrieTestCase(const std::vector<std::string> ops, const std::vector<std::optional<std::string>> args, const std::vector<std::optional<bool>> expected)
        : operations(std::move(ops)), arguments(std::move(args)), expectedResults(std::move(expected)) {}
};

struct KthLargestElementTestCase {
    std::vector<int> nums;
    int k;
    int expectedResult;

    KthLargestElementTestCase(std::vector<int> n, int kVal, int e)
        : nums(std::move(n)), k(kVal), expectedResult(e) {}
};

struct MinHeapTestCase {
    std::vector<std::pair<std::string, int>> operations; // {operation, value (if any)}
    std::vector<int> expectedResults;                   // Expected results for operations

    MinHeapTestCase(std::vector<std::pair<std::string, int>> ops, std::vector<int> results)
        : operations(std::move(ops)), expectedResults(std::move(results)) {}
};

struct RotateImageTestCase {
    std::vector<std::vector<int>> inputMatrix;
    std::vector<std::vector<int>> expectedMatrix;

    RotateImageTestCase(std::vector<std::vector<int>> input, std::vector<std::vector<int>> expected)
        : inputMatrix(std::move(input)), expectedMatrix(std::move(expected)) {}
};

struct MergeIntervalsTestCase {
    std::vector<std::vector<int>> intervals;
    std::vector<std::vector<int>> expectedResult;

    MergeIntervalsTestCase(std::vector<std::vector<int>> input, std::vector<std::vector<int>> expected)
        : intervals(std::move(input)), expectedResult(std::move(expected)) {}
};

struct MergeKListsTestCase {
    std::vector<std::vector<int>> inputLists;
    std::vector<int> expectedList;

    MergeKListsTestCase(std::vector<std::vector<int>> inputs, std::vector<int> expected)
        : inputLists(std::move(inputs)), expectedList(std::move(expected)) {}
};

struct ProductOfArrayExceptSelfTestCase {
    std::vector<int> nums;
    std::vector<int> expectedResult;

    ProductOfArrayExceptSelfTestCase(std::vector<int> input, std::vector<int> expected)
        : nums(std::move(input)), expectedResult(std::move(expected)) {}
};

struct MajorityElementTestCase {
    std::vector<int> nums;
    int expectedResult;

    MajorityElementTestCase(std::vector<int> nums, int result)
        : nums(std::move(nums)), expectedResult(result) {}
};

struct EvaluateRPNTestCase {
    std::vector<std::string> tokens;
    int expectedResult;

    EvaluateRPNTestCase(std::vector<std::string> t, int e)
        : tokens(std::move(t)), expectedResult(e) {}
};

struct LargestRectangleTestCase {
    std::vector<int> heights;
    int expectedArea;

    LargestRectangleTestCase(std::vector<int> h, int area)
        : heights(std::move(h)), expectedArea(area) {}
};

struct WordSearchTestCase {
    std::vector<std::vector<char>> board;
    std::string word;
    bool expectedResult;

    WordSearchTestCase(std::vector<std::vector<char>> b, std::string w, bool e)
        : board(std::move(b)), word(std::move(w)), expectedResult(e) {}
};

struct ValidParenthesesTestCase {
    std::string input;
    bool expectedResult;

    ValidParenthesesTestCase(std::string in, bool result)
        : input(std::move(in)), expectedResult(result) {}
};

struct ValidSudokuTestCase {
    std::vector<std::vector<char>> board;
    bool expectedResult;

    ValidSudokuTestCase(std::vector<std::vector<char>> b, bool e)
        : board(std::move(b)), expectedResult(e) {}
};

struct BinarySearchTestCase {
    std::vector<int> nums;
    int target;
    int expectedResult;

    BinarySearchTestCase(std::vector<int> n, int t, int e)
        : nums(std::move(n)), target(t), expectedResult(e) {}
};

struct Search2DMatrixTestCase {
    std::vector<std::vector<int>> matrix;
    int target;
    bool expectedResult;

    Search2DMatrixTestCase(std::vector<std::vector<int>> mat, int tgt, bool result)
        : matrix(std::move(mat)), target(tgt), expectedResult(result) {}
};

struct FindMinTestCase {
    std::vector<int> nums;
    int expectedResult;

    FindMinTestCase(std::vector<int> n, int e) : nums(std::move(n)), expectedResult(e) {}
};

struct ZigzagTestCase {
    std::string input;
    int numRows;
    std::string expected;

    ZigzagTestCase(std::string s, int n, std::string e)
        : input(std::move(s)), numRows(n), expected(std::move(e)) {}
};

struct HIndexTestCase {
    std::vector<int> citations;
    int expectedResult;

    HIndexTestCase(std::vector<int> c, int e)
        : citations(std::move(c)), expectedResult(e) {}
};

struct SortColorsTestCase {
    std::vector<int> input;
    std::vector<int> expected;

    SortColorsTestCase(std::vector<int> in, std::vector<int> exp)
        : input(std::move(in)), expected(std::move(exp)) {}
};

struct RemoveDuplicatesFromSortedArrayIITestCase {
    std::vector<int> input;
    int expectedK;
    std::vector<int> expectedResult;

    RemoveDuplicatesFromSortedArrayIITestCase(std::vector<int> in, int k, std::vector<int> exp)
        : input(std::move(in)), expectedK(k), expectedResult(std::move(exp)) {}
};

struct BestTimeToBuyAndSellStockII_122_TestCase {
    std::vector<int> prices;
    int expectedProfit;

    BestTimeToBuyAndSellStockII_122_TestCase(std::vector<int> p, int e)
        : prices(std::move(p)), expectedProfit(e) {}
};

struct ValidAnagramTestCase {
    std::string s;
    std::string t;
    bool expectedResult;

    ValidAnagramTestCase(std::string str1, std::string str2, bool result)
        : s(std::move(str1)), t(std::move(str2)), expectedResult(result) {}
};

struct AnalyzeUserWebsiteVisitPatternTestCase {
    std::vector<std::string> username;
    std::vector<int> timestamp;
    std::vector<std::string> website;
    std::vector<std::string> expectedResult;

    AnalyzeUserWebsiteVisitPatternTestCase(std::vector<std::string> u, std::vector<int> t, std::vector<std::string> w, std::vector<std::string> e)
        : username(std::move(u)), timestamp(std::move(t)), website(std::move(w)), expectedResult(std::move(e)) {}
};

class TestsRunner {
public:
    static void courseSchedule_207_tests() {
        std::vector<ScheduleTestCase> testCases = {
            ScheduleTestCase(2, {{1, 0}}, true),
            ScheduleTestCase(2, {{1, 0}, {0, 1}}, false),
            ScheduleTestCase(5, {{0, 1}, {2, 3}, {3, 4}, {2, 1}}, true),
            ScheduleTestCase(5, {{0, 1}, {2, 3}, {3, 4}, {2, 1}, {4, 2}}, false),
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
            PathTestCase(3, {{0, 1}, {1, 2}, {2, 0}}, 0, 2, true),
            PathTestCase(6, {{0, 1}, {0, 2}, {3, 5}, {5, 4}, {4, 3}}, 0, 5, false),
            PathTestCase(4, {{0, 1}, {1, 2}, {2, 3}}, 0, 3, true),
            PathTestCase(5, {{0, 4}, {4, 3}, {3, 2}, {2, 1}}, 0, 1, true),
            PathTestCase(4, {{0, 1}, {1, 2}}, 0, 3, false),
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
            CourseScheduleIITestCase({2, {{1, 0}}, {0, 1}}),
            // Example 2
            CourseScheduleIITestCase({4, {{1, 0}, {2, 0}, {3, 1}, {3, 2}}, {0, 1, 2, 3}}),
            // Example 3
            CourseScheduleIITestCase({1, {}, {0}}),
            // Additional Complex Test 1: A graph with two independent subgraphs
            CourseScheduleIITestCase({6, {{1, 0}, {2, 0}, {3, 4}, {5, 4}}, {0, 4, 1, 2, 3, 5}}),
            // Additional Complex Test 2: A cycle detection case
            CourseScheduleIITestCase({5, {{0, 1}, {1, 2}, {2, 3}, {3, 4}, {4, 0}}, {}})
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
            NetworkDelayTimeTestCase({{ {2, 1, 1}, {2, 3, 1}, {3, 4, 1} }, 4, 2, 2}),
            NetworkDelayTimeTestCase({{ {1, 2, 1} }, 2, 1, 1}),
            NetworkDelayTimeTestCase({{ {1, 2, 1} }, 2, 2, -1}),

            // Additional Complex Example 1: 6 nodes, complex network
            NetworkDelayTimeTestCase({{ {1, 2, 2}, {1, 3, 4}, {2, 4, 7}, {3, 4, 1}, {2, 5, 5}, {5, 6, 3}, {4, 6, 2} }, 6, 1, 7}),

            // Additional Complex Example 2: 8 nodes, complex network
            NetworkDelayTimeTestCase({{ {1, 2, 2}, {1, 3, 1}, {3, 4, 4}, {2, 5, 7}, {5, 6, 1}, {6, 7, 5}, {7, 8, 2}, {4, 8, 3} }, 8, 1, 15}),
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
            KthSmallestTestCase({15, 10, 20, 5, 13, 17, 25, 3, 8, std::nullopt, 14, 16, 18}, 6, 14),
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

    static void implementTrie_208_tests() {
        std::vector<TrieTestCase> testCases = {
            // Example 1
            TrieTestCase(
                {"Trie", "insert", "search", "search", "startsWith", "insert", "search"},
                {std::nullopt, "apple", "apple", "app", "app", "app", "app"},
                {std::nullopt, std::nullopt, true, false, true, std::nullopt, true}
            ),
            // Example 2: Overlapping words
            TrieTestCase(
                {"Trie", "insert", "insert", "search", "search", "startsWith"},
                {std::nullopt, "apple", "applause", "apple", "applause", "app"},
                {std::nullopt, std::nullopt, std::nullopt, true, true, true}
            ),
            // Example 3: Single-character operations
            TrieTestCase(
                {"Trie", "insert", "search", "startsWith", "search"},
                {std::nullopt, "a", "a", "a", "b"},
                {std::nullopt, std::nullopt, true, true, false}
            ),
            // Example 4: No matching prefix
            TrieTestCase(
                {"Trie", "insert", "insert", "startsWith", "startsWith", "search"},
                {std::nullopt, "car", "cart", "ca", "cat", "carrot"},
                {std::nullopt, std::nullopt, std::nullopt, true, false, false}
            ),
            // Example 5: Large input set
            TrieTestCase(
                {"Trie", "insert", "insert", "insert", "search", "search", "startsWith"},
                {std::nullopt, "dictionary", "dictionaries", "dictator", "dictionary", "dictionaries", "dict"},
                {std::nullopt, std::nullopt, std::nullopt, std::nullopt, true, true, true}
            )
        };

        for (size_t i = 0; i < testCases.size(); ++i) {
            std::cout << "Running Trie Test Case " << i + 1 << ":\n";
            Trie* trie = nullptr;

            for (size_t j = 0; j < testCases[i].operations.size(); ++j) {
                const auto& op = testCases[i].operations[j];
                const auto& arg = testCases[i].arguments[j];
                const auto& expected = testCases[i].expectedResults[j];

                if (op == "Trie") {
                    trie = new Trie();
                    std::cout << "Operation: Trie() -> null\n";
                } else if (op == "insert") {
                    trie->insert(arg.value());
                    std::cout << "Operation: insert(\"" << arg.value() << "\") -> null\n";
                } else if (op == "search") {
                    bool result = trie->search(arg.value());
                    std::cout << "Operation: search(\"" << arg.value() << "\") -> " << (result ? "true" : "false");
                    if (expected.has_value() && result == expected.value()) {
                        std::cout << " [PASS]\n";
                    } else {
                        std::cout << " [FAIL]\n";
                    }
                } else if (op == "startsWith") {
                    bool result = trie->startsWith(arg.value());
                    std::cout << "Operation: startsWith(\"" << arg.value() << "\") -> " << (result ? "true" : "false");
                    if (expected.has_value() && result == expected.value()) {
                        std::cout << " [PASS]\n";
                    } else {
                        std::cout << " [FAIL]\n";
                    }
                }
            }

            delete trie;
            std::cout << "\n";
        }
    }

    static void kthLargestElement_215_tests()
    {
        std::vector<KthLargestElementTestCase> testCases = {
            // Problem statement examples
            KthLargestElementTestCase({3, 2, 1, 5, 6, 4}, 2, 5),
            KthLargestElementTestCase({3, 2, 3, 1, 2, 4, 5, 5, 6}, 4, 4),

            // Additional test cases
            KthLargestElementTestCase({1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, 1, 10), // Largest element
            KthLargestElementTestCase({7, 10, 4, 3, 20, 15}, 3, 10),           // Mixed elements
            KthLargestElementTestCase({2, 2, 2, 2, 2}, 3, 2)                   // Repeated elements
        };

        KthLargestElementInArray_215 solution;

        for (size_t i = 0; i < testCases.size(); ++i)
        {
            int result = solution.findKthLargest(testCases[i].nums, testCases[i].k);
            std::cout << "Kth Largest Element Test " << (i + 1) << ": res = "
                      << (result == testCases[i].expectedResult ? "PASS" : "FAIL")
                      << " (Expected: " << testCases[i].expectedResult << ", Got: " << result << ")" << std::endl;
        }
    }

    static void minHeap_tests() {
        std::vector<MinHeapTestCase> testCases = {
            MinHeapTestCase(
                {{"insert", 5}, {"insert", 3}, {"insert", 8}, {"insert", 1}, {"insert", 2}, {"extractMin", 0}, {"extractMin", 0}},
                {1, 2} // Expected results of the extractMin calls
            ),
            MinHeapTestCase(
                {{"insert", 10}, {"insert", 20}, {"insert", 5}, {"update", 1}, {"extractMin", 0}},
                {1} // Updated root is extracted
            ),
            MinHeapTestCase(
                {{"insert", 100}, {"insert", 50}, {"insert", 25}, {"extractMin", 0}, {"extractMin", 0}},
                {25, 50} // Both extractions
            )
        };

        for (size_t i = 0; i < testCases.size(); ++i) {
            MinHeap heap;
            std::vector<int> results;

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
            bool pass = results == testCases[i].expectedResults;
            std::cout << "MinHeap Test " << (i + 1) << ": " << (pass ? "PASS" : "FAIL") << "\n";
            if (!pass) {
                std::cout << "Expected: ";
                for (int r : testCases[i].expectedResults) std::cout << r << " ";
                std::cout << "\nGot: ";
                for (int r : results) std::cout << r << " ";
                std::cout << "\n";
            }
        }
    }

    static void rotateImage_48_tests() {
        std::vector<RotateImageTestCase> testCases = {
            // Example 1
            RotateImageTestCase({{1, 2, 3}, {4, 5, 6}, {7, 8, 9}}, {{7, 4, 1}, {8, 5, 2}, {9, 6, 3}}),
            // Example 2
            RotateImageTestCase({{5, 1, 9, 11}, {2, 4, 8, 10}, {13, 3, 6, 7}, {15, 14, 12, 16}},
                                {{15, 13, 2, 5}, {14, 3, 4, 1}, {12, 6, 8, 9}, {16, 7, 10, 11}}),
            // Additional Test Cases
            RotateImageTestCase({{1}}, {{1}}), // Single element
            RotateImageTestCase({{1, 2}, {3, 4}}, {{3, 1}, {4, 2}}), // 2x2 matrix
            RotateImageTestCase(
                {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}},
                {{13, 9, 5, 1}, {14, 10, 6, 2}, {15, 11, 7, 3}, {16, 12, 8, 4}}) // Larger 4x4 matrix
        };

        RotateImage_48 rotateImage;

        for (size_t i = 0; i < testCases.size(); ++i) {
            auto input = testCases[i].inputMatrix;
            rotateImage.rotate(input);

            std::cout << "Rotate Image Test " << (i + 1) << ": res = "
                    << (input == testCases[i].expectedMatrix ? "PASS" : "FAIL")
                    << "\nExpected: ";
            for (const auto& row : testCases[i].expectedMatrix) {
                for (int val : row) std::cout << val << " ";
                std::cout << "\n";
            }
            std::cout << "Got: ";
            for (const auto& row : input) {
                for (int val : row) std::cout << val << " ";
                std::cout << "\n";
            }
        }
    }

    static void mergeIntervals_56_tests() {
        std::vector<MergeIntervalsTestCase> testCases = {
            // Problem statement examples
            MergeIntervalsTestCase({{1, 3}, {2, 6}, {8, 10}, {15, 18}}, {{1, 6}, {8, 10}, {15, 18}}),
            MergeIntervalsTestCase({{1, 4}, {4, 5}}, {{1, 5}}),

            // Additional complex test cases
            MergeIntervalsTestCase({{1, 4}, {0, 2}, {3, 5}}, {{0, 5}}),
            MergeIntervalsTestCase({{1, 10}, {2, 6}, {8, 9}, {15, 20}, {18, 22}}, {{1, 10}, {15, 22}}),

            // Edge case: Single interval
            MergeIntervalsTestCase({{5, 10}}, {{5, 10}})
        };

        MergeIntervals_56 solution;

        for (size_t i = 0; i < testCases.size(); ++i) {
            auto result = solution.merge(testCases[i].intervals);

            std::cout << "Merge Intervals Test " << (i + 1) << ": res = "
                    << (result == testCases[i].expectedResult ? "PASS" : "FAIL")
                    << "\nExpected: ";
            for (const auto& interval : testCases[i].expectedResult) {
                std::cout << "[" << interval[0] << "," << interval[1] << "] ";
            }
            std::cout << "\nGot: ";
            for (const auto& interval : result) {
                std::cout << "[" << interval[0] << "," << interval[1] << "] ";
            }
            std::cout << "\n\n";
        }
    }

    static void mergeKLists_tests() {
        using IntListNode = ListNode<int>;

        std::vector<MergeKListsTestCase> testCases = {
            // Example 1
            MergeKListsTestCase({{1, 4, 5}, {1, 3, 4}, {2, 6}}, {1, 1, 2, 3, 4, 4, 5, 6}),
            // Example 2
            MergeKListsTestCase({}, {}),
            // Example 3
            MergeKListsTestCase({{}}, {}),
            // Additional Test 1: Single long list
            MergeKListsTestCase({{1, 2, 3, 4, 5}}, {1, 2, 3, 4, 5}),
            // Additional Test 2: Large overlapping lists
            MergeKListsTestCase({{1, 3, 5}, {2, 4, 6}, {0, 7, 8, 9}}, {0, 1, 2, 3, 4, 5, 6, 7, 8, 9})
        };

        MergeKSortedLists_23 solution;

        for (size_t i = 0; i < testCases.size(); ++i) {
            // Create input linked lists
            std::vector<IntListNode*> inputLists;
            for (const auto& list : testCases[i].inputLists) {
                inputLists.push_back(ListUtils::createLinkedList<int>(list));
            }

            // Run the solution
            IntListNode* result = solution.mergeKLists(inputLists);

            // Convert result to vector
            std::vector<int> resultVector = ListUtils::toVector<int>(result);

            // Print test results
            std::cout << "Merge K Lists Test " << i + 1 << ": res = "
                    << (resultVector == testCases[i].expectedList ? "PASS" : "FAIL")
                    << " (Expected: " << ListUtils::toString<int>(ListUtils::createLinkedList<int>(testCases[i].expectedList))
                    << ", Got: " << ListUtils::toString<int>(result) << ")" << std::endl;

            // Free allocated memory
            ListUtils::freeList<int>(result);
        }
    }

    static void productOfArrayExceptSelf_tests() {
        std::vector<ProductOfArrayExceptSelfTestCase> testCases = {
            // Example 1
            ProductOfArrayExceptSelfTestCase({1, 2, 3, 4}, {24, 12, 8, 6}),
            // Example 2
            ProductOfArrayExceptSelfTestCase({-1, 1, 0, -3, 3}, {0, 0, 9, 0, 0}),
            // Corner Case: All ones
            ProductOfArrayExceptSelfTestCase({1, 1, 1, 1}, {1, 1, 1, 1}),
            // Complex Case 1: Mixed positive and negative numbers
            ProductOfArrayExceptSelfTestCase({-2, -3, 4, 5}, {-60, -40, 30, 24}),
            // Complex Case 2: Large array
            ProductOfArrayExceptSelfTestCase({10, 20, 30, 40, 50}, {1200000, 600000, 400000, 300000, 240000})
        };

        ProductOfArrayExceptSelf solution;

        for (size_t i = 0; i < testCases.size(); ++i) {
            auto result = solution.productExceptSelf(testCases[i].nums);
            std::cout << "Product of Array Except Self Test " << (i + 1) << ": res = "
                    << (result == testCases[i].expectedResult ? "PASS" : "FAIL")
                    << " (Expected: ";
            for (int val : testCases[i].expectedResult) std::cout << val << " ";
            std::cout << ", Got: ";
            for (int val : result) std::cout << val << " ";
            std::cout << ")\n";
        }
    }

    static void majorityElement_tests() {
        // Define test cases
        std::vector<MajorityElementTestCase> testCases = {
            // Example 1
            MajorityElementTestCase({3, 2, 3}, 3),
            // Example 2
            MajorityElementTestCase({2, 2, 1, 1, 1, 2, 2}, 2),
            // Edge Case: Single element
            MajorityElementTestCase({1}, 1),
            // Complex Case 1: Large input with clear majority
            MajorityElementTestCase({1, 1, 1, 1, 2, 2, 2, 2, 1, 1}, 1),
            // Complex Case 2: Alternating majority
            MajorityElementTestCase({5, 1, 5, 1, 5, 5, 5, 2, 5, 3, 5, 5}, 5),
            // Complex Case 3: Majority in large data
            MajorityElementTestCase({10, 9, 9, 10, 10, 10, 9, 10, 9, 10, 10}, 10)
        };

        std::cout << "-> Boyer–Moore Majority Vote Algorithm:\n";
        for (size_t i = 0; i < testCases.size(); ++i) {
            MajorityElement_169 solution;
            int result = solution.majorityElement(testCases[i].nums);
            std::cout << "Test " << (i + 1) << ": ";
            if (result == testCases[i].expectedResult) {
                std::cout << "PASS\n";
            } else {
                std::cout << "FAIL (Expected: " << testCases[i].expectedResult
                        << ", Got: " << result << ")\n";
            }
        }

        std::cout << "-> Frequency Counting with a Hashmap Algorithm:\n";
        for (size_t i = 0; i < testCases.size(); ++i) {
            MajorityElement_169 solution;
            int result = solution.majorityElementWithHashmap(testCases[i].nums);
            std::cout << "Test " << (i + 1) << ": ";
            if (result == testCases[i].expectedResult) {
                std::cout << "PASS\n";
            } else {
                std::cout << "FAIL (Expected: " << testCases[i].expectedResult
                        << ", Got: " << result << ")\n";
            }
        }
    }

    static void evaluateReversePolishNotation_150_tests() {
        std::vector<EvaluateRPNTestCase> testCases = {
            EvaluateRPNTestCase({"2", "1", "+", "3", "*"}, 9),  // Example 1
            EvaluateRPNTestCase({"4", "13", "5", "/", "+"}, 6), // Example 2
            EvaluateRPNTestCase({"10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"}, 22), // Example 3
            // Additional test cases
            EvaluateRPNTestCase({"3", "4", "+", "2", "*", "7", "/"}, 2), // Complex case: (((3+4)*2)/7)
            EvaluateRPNTestCase({"5", "-2", "4", "+", "*", "3", "+"}, 13) // Complex case: ((5*(-2+4))+3)
        };

        EvaluateReversePolishNotation_150 evaluator;

        for (size_t i = 0; i < testCases.size(); ++i) {
            int result = evaluator.evalRPN(testCases[i].tokens);
            std::cout << "Evaluate RPN Test " << (i + 1) << ": res = "
                      << (result == testCases[i].expectedResult ? "PASS" : "FAIL")
                      << " (Expected: " << testCases[i].expectedResult << ", Got: " << result << ")\n";
        }
    }

    static void largestRectangleArea_tests() {
        std::vector<LargestRectangleTestCase> testCases = {
            // Example 1
            LargestRectangleTestCase({2, 1, 5, 6, 2, 3}, 10),
            // Example 2
            LargestRectangleTestCase({2, 4}, 4),
            // Additional Test 1: All bars of the same height
            LargestRectangleTestCase({1, 1, 1, 1, 1}, 5),
            // Additional Test 2: Decreasing heights
            LargestRectangleTestCase({5, 4, 3, 2, 1}, 9),
            // Additional Test 3: Complex case
            LargestRectangleTestCase({2, 1, 4, 5, 1, 3, 3}, 8)
        };

        LargestRectangleInHistogram_84 solution;

        for (size_t i = 0; i < testCases.size(); ++i) {
            int result = solution.largestRectangleArea(testCases[i].heights);
            std::cout << "Test " << (i + 1) << ": res = "
                      << (result == testCases[i].expectedArea ? "PASS" : "FAIL")
                      << " (Expected: " << testCases[i].expectedArea
                      << ", Got: " << result << ")" << std::endl;
        }
    }

    static void runWordSearchTests() {
        std::vector<WordSearchTestCase> testCases = {
            // Example 1 from problem statement
            WordSearchTestCase({{'A','B','C','E'},
                                {'S','F','C','S'},
                                {'A','D','E','E'}},
                            "ABCCED", true),

            // Example 2 from problem statement
            WordSearchTestCase({{'A','B','C','E'},
                                {'S','F','C','S'},
                                {'A','D','E','E'}},
                            "SEE", true),

            // Example 3 from problem statement
            WordSearchTestCase({{'A','B','C','E'},
                                {'S','F','C','S'},
                                {'A','D','E','E'}},
                            "ABCB", false),

            // Additional complex test case 1
            WordSearchTestCase({{'A','B','C','E','F','G'},
                                {'H','I','J','K','L','M'},
                                {'N','O','P','Q','R','S'},
                                {'T','U','V','W','X','Y'},
                                {'Z','A','B','C','D','E'}},
                            "ABCEFGMLKJIHNT", true),

            // Additional complex test case 2
            WordSearchTestCase({{'A','B','C','E','F','G'},
                                {'H','I','J','K','L','M'},
                                {'N','O','P','Q','R','S'},
                                {'T','U','V','W','X','Y'},
                                {'Z','A','B','C','D','E'}},
                            "ZYXWVUTSRQPONMLK", false)
        };

        WordSearch_79 solution;

        for (size_t i = 0; i < testCases.size(); ++i) {
            bool result = solution.exist(testCases[i].board, testCases[i].word);
            std::cout << "Test " << (i + 1) << ": res = "
                    << (result == testCases[i].expectedResult ? "PASS" : "FAIL")
                    << " (Expected: " << (testCases[i].expectedResult ? "true" : "false")
                    << ", Got: " << (result ? "true" : "false") << ")" << std::endl;
        }
    }

    static void runValidParenthesesTests() {
        std::vector<ValidParenthesesTestCase> testCases = {
            {"()", true},
            {"()[]{}", true},
            {"(]", false},
            {"([])", true},
            {"({[(){}[]]})", true} // Additional complex test case
        };

        ValidParentheses_20 solution;

        for (size_t i = 0; i < testCases.size(); ++i) {
            bool result = solution.isValid(testCases[i].input);
            std::cout << "Test " << (i + 1) << ": res = "
                    << (result == testCases[i].expectedResult ? "PASS" : "FAIL")
                    << " (Expected: " << (testCases[i].expectedResult ? "true" : "false")
                    << ", Got: " << (result ? "true" : "false") << ")" << std::endl;
        }
    }

    static void validSudoku_36_tests() {
        std::vector<ValidSudokuTestCase> testCases = {
            // Example 1: Valid Sudoku
            ValidSudokuTestCase({
                {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
                {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
                {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
                {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
                {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
                {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
                {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
                {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
                {'.', '.', '.', '.', '8', '.', '.', '7', '9'}
            }, true),

            // Example 2: Invalid Sudoku (Duplicate in Sub-box)
            ValidSudokuTestCase({
                {'8', '3', '.', '.', '7', '.', '.', '.', '.'},
                {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
                {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
                {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
                {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
                {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
                {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
                {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
                {'.', '.', '.', '.', '8', '.', '.', '7', '9'}
            }, false),

            // Example 3: Valid Complex Sudoku
            ValidSudokuTestCase({
                {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
                {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
                {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
                {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
                {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
                {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
                {'1', '6', '.', '.', '.', '.', '2', '8', '.'},
                {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
                {'2', '.', '.', '.', '8', '.', '.', '7', '9'}
            }, true),

            // Example 4: Invalid Sudoku (Duplicate in Row)
            ValidSudokuTestCase({
                {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
                {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
                {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
                {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
                {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
                {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
                {'1', '6', '.', '.', '.', '.', '2', '8', '.'},
                {'.', '.', '.', '4', '1', '9', '.', '1', '5'},
                {'2', '.', '.', '.', '8', '.', '.', '7', '9'}
            }, false),

            // Example 5: Invalid Sudoku (Duplicate in Column)
            ValidSudokuTestCase({
                {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
                {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
                {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
                {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
                {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
                {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
                {'1', '6', '.', '.', '.', '.', '2', '8', '.'},
                {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
                {'2', '.', '.', '.', '8', '.', '.', '7', '5'}
            }, false),
        };

        ValidSudoku_36 solver;

        for (size_t i = 0; i < testCases.size(); ++i) {
            bool result = solver.isValidSudoku(testCases[i].board);
            std::cout << "Valid Sudoku Test " << (i + 1) << ": res = "
                    << (result == testCases[i].expectedResult ? "PASS" : "FAIL")
                    << " (Expected: " << (testCases[i].expectedResult ? "true" : "false")
                    << ", Got: " << (result ? "true" : "false") << ")" << std::endl;
        }
    }

    static void binarySearch_704_tests() {
        std::vector<BinarySearchTestCase> testCases = {
            // Example 1
            BinarySearchTestCase({-1, 0, 3, 5, 9, 12}, 9, 4),
            // Example 2
            BinarySearchTestCase({-1, 0, 3, 5, 9, 12}, 2, -1),
            // Complex Case 1: Large range with the target in the middle
            BinarySearchTestCase({-10000, -5000, 0, 5000, 10000}, 0, 2),
            // Complex Case 2: Target near boundaries
            BinarySearchTestCase({1, 3, 5, 7, 9, 11}, 11, 5), // Target is the last element
            // Corner Case: Single element, no match
            BinarySearchTestCase({1}, 0, -1)
        };

        BinarySearch_704 solution;

        for (size_t i = 0; i < testCases.size(); ++i) {
            int result = solution.search(testCases[i].nums, testCases[i].target);
            std::cout << "Binary Search Test " << (i + 1) << ": res = "
                    << (result == testCases[i].expectedResult ? "PASS" : "FAIL")
                    << " (Expected: " << testCases[i].expectedResult
                    << ", Got: " << result << ")" << std::endl;
        }
    }

    static void searchInsertPosition_35_tests() {
        std::vector<BinarySearchTestCase> testCases = {
            // Example 1: Target is found
            BinarySearchTestCase({1, 3, 5, 6}, 5, 2),
            // Example 2: Target is not found, insert at index 1
            BinarySearchTestCase({1, 3, 5, 6}, 2, 1),
            // Example 3: Target is not found, insert at the end
            BinarySearchTestCase({1, 3, 5, 6}, 7, 4),
            // Complex Case 1: Large range with insertion at the beginning
            BinarySearchTestCase({10, 20, 30, 40, 50}, 5, 0),
            // Complex Case 2: Large range with insertion in the middle
            BinarySearchTestCase({10, 20, 30, 40, 50, 60, 70, 80, 90, 100}, 55, 5)
        };

        SearchInsertPosition_35 solution;

        for (size_t i = 0; i < testCases.size(); ++i) {
            int result = solution.searchInsert(testCases[i].nums, testCases[i].target);
            std::cout << "Search Insert Position Test " << (i + 1) << ": res = "
                    << (result == testCases[i].expectedResult ? "PASS" : "FAIL")
                    << " (Expected: " << testCases[i].expectedResult
                    << ", Got: " << result << ")" << std::endl;
        }
    }

    static void search2DMatrixTests() {
        std::vector<Search2DMatrixTestCase> testCases = {
            // Provided examples
            Search2DMatrixTestCase({{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}}, 3, true),
            Search2DMatrixTestCase({{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}}, 13, false),

            // Additional complex test cases
            Search2DMatrixTestCase({{1, 5, 9}, {14, 20, 23}, {30, 34, 50}}, 20, true),
            Search2DMatrixTestCase({{1, 3, 6, 10}, {15, 20, 25, 30}, {35, 40, 45, 50}}, 7, false),
            Search2DMatrixTestCase({{5, 7, 9, 11}, {13, 15, 17, 19}, {21, 23, 25, 27}}, 27, true),
        };

        Search2DMatrix_74 solution;

        for (size_t i = 0; i < testCases.size(); ++i) {
            bool result = solution.searchMatrix(testCases[i].matrix, testCases[i].target);
            std::cout << "Test " << (i + 1) << ": res = "
                    << (result == testCases[i].expectedResult ? "PASS" : "FAIL")
                    << " (Expected: " << (testCases[i].expectedResult ? "true" : "false")
                    << ", Got: " << (result ? "true" : "false") << ")\n";
        }
    }

    static bool inSet(const std::string& s, std::initializer_list<std::string> candidates) {
        // Helper to handle the fact that getMaxKey / getMinKey can return any
        // of the keys sharing min/max count
        for (auto& c : candidates) {
            if (s == c) return true;
        }
        return false;
    }

    static void allOne_432_tests() {
        // Test 1: Basic example from problem statement
        {
            AllOOneDataStructure_432 allOne;
            allOne.inc("hello");
            allOne.inc("hello");
            // "hello" now has count 2
            std::string mx = allOne.getMaxKey();  // expect "hello"
            std::string mn = allOne.getMinKey();  // expect "hello"
            bool t1a = (mx == "hello") && (mn == "hello");

            allOne.inc("leet");
            // "hello"=2, "leet"=1
            mx = allOne.getMaxKey(); // still "hello"
            mn = allOne.getMinKey(); // now "leet"
            bool t1b = (mx == "hello") && (mn == "leet");

            bool pass = t1a && t1b;
            std::cout << "Test 1: " << (pass ? "PASS" : "FAIL") << std::endl;
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
            std::cout << "Test 2: " << (pass ? "PASS" : "FAIL") << std::endl;
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
            std::cout << "Test 3: " << (pass ? "PASS" : "FAIL") << std::endl;
        }
    }

    static void findMinimumInRotatedSortedArray_153_tests() {
        std::vector<FindMinTestCase> testCases = {
            FindMinTestCase({3, 4, 5, 1, 2}, 1),                     // Example 1
            FindMinTestCase({4, 5, 6, 7, 0, 1, 2}, 0),               // Example 2
            FindMinTestCase({11, 13, 15, 17}, 11),                   // Example 3
            FindMinTestCase({5, 6, 7, 8, 9, 1, 2, 3, 4}, 1),         // Additional Test 1
            FindMinTestCase({30, 40, 50, 5, 10, 20}, 5)              // Additional Test 2
        };

        FindMinimumInRotatedSortedArray_153 solution;

        for (size_t i = 0; i < testCases.size(); ++i) {
            int result = solution.findMin(testCases[i].nums);
            std::cout << "Test " << (i + 1) << ": res = "
                    << (result == testCases[i].expectedResult ? "PASS" : "FAIL")
                    << " (Expected: " << testCases[i].expectedResult << ", Got: " << result << ")" << std::endl;
        }
    }

    // Helper function to check if two graphs are isomorphic
    static bool areGraphsIsomorphic(GraphNode<int>* original, GraphNode<int>* cloned) {
        if (!original && !cloned) return true;
        if (!original || !cloned) return false;
        if (original->val != cloned->val) return false;

        std::unordered_map<GraphNode<int>*, GraphNode<int>*> visited;
        std::function<bool(GraphNode<int>*, GraphNode<int>*)> dfs = [&](GraphNode<int>* n1, GraphNode<int>* n2) -> bool {
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
    static GraphNode<int>* buildGraph(const std::vector<std::vector<int>>& adjList) {
        if (adjList.empty()) return nullptr;

        std::unordered_map<int, GraphNode<int>*> nodeMap;
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
        std::vector<std::vector<std::vector<int>>> testCases = {
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
            std::cout << "Clone Graph Test " << (i + 1) << ": " << (result ? "PASS" : "FAIL") << std::endl;
        }
    }

    static void zigzagConversion_6_tests() {
        std::vector<ZigzagTestCase> testCases = {
            ZigzagTestCase("PAYPALISHIRING", 3, "PAHNAPLSIIGYIR"),
            ZigzagTestCase("PAYPALISHIRING", 4, "PINALSIGYAHRPI"),
            ZigzagTestCase("A", 1, "A"),
            ZigzagTestCase("ABCDEFGHIJKLMNOPQRSTUVWXYZ", 5, "AIQYBHJPRXZCGKOSWDFLNTVEMU"),
            ZigzagTestCase("THISISAZIGZAGCONVERSIONTEST", 6, "TZIHGASOIIGRNSZCETIAOVETSNS")
        };

        ZigzagConversion_6 solution;
        for (size_t i = 0; i < testCases.size(); ++i) {
            std::string result_rowWise = solution.convert_rowWise(testCases[i].input, testCases[i].numRows);
            std::string result_jumpPattern = solution.convert_jumpPattern(testCases[i].input, testCases[i].numRows);

            std::cout << "Test " << (i + 1) << " (Row-Wise): "
                      << (result_rowWise == testCases[i].expected ? "PASS" : "FAIL")
                      << " (Expected: " << testCases[i].expected
                      << ", Got: " << result_rowWise << ")" << std::endl;

            std::cout << "Test " << (i + 1) << " (Jump-Pattern): "
                      << (result_jumpPattern == testCases[i].expected ? "PASS" : "FAIL")
                      << " (Expected: " << testCases[i].expected
                      << ", Got: " << result_jumpPattern << ")" << std::endl;
        }
    }

    static void hIndex_274_tests() {
        // 5 test cases: the 2 from the LeetCode examples + 3 additional
        std::vector<HIndexTestCase> testCases = {
            // Example 1
            HIndexTestCase({3, 0, 6, 1, 5}, 3),
            // Example 2
            HIndexTestCase({1, 3, 1}, 1),

            // Additional (more complex) test cases
            HIndexTestCase({10, 8, 5, 4, 3}, 4),  // H-index should be 4
            HIndexTestCase({0, 0, 0, 0}, 0),      // H-index should be 0
            HIndexTestCase({4, 4, 4, 4, 4}, 4)    // H-index should be 4
        };

        HIndex_274 solution;

        for (size_t i = 0; i < testCases.size(); ++i) {
            int result = solution.hIndex(testCases[i].citations);
            std::cout << "HIndex_274 Test " << (i + 1) << ": res = "
                      << ((result == testCases[i].expectedResult) ? "PASS" : "FAIL")
                      << " (Expected: " << testCases[i].expectedResult
                      << ", Got: " << result << ")" << std::endl;
        }
    }

    static void sortColors_75_tests() {
        // Create test cases (two from the problem statement + three more)
        std::vector<SortColorsTestCase> testCases = {
            // Example 1
            SortColorsTestCase({2, 0, 2, 1, 1, 0}, {0, 0, 1, 1, 2, 2}),
            // Example 2
            SortColorsTestCase({2, 0, 1}, {0, 1, 2}),
            // Additional Test 1: Single element
            SortColorsTestCase({0}, {0}),
            // Additional Test 2: All the same element
            SortColorsTestCase({2, 2, 2, 2}, {2, 2, 2, 2}),
            // Additional Test 3: Mixed with more 1s
            SortColorsTestCase({1, 0, 2, 2, 1, 0}, {0, 0, 1, 1, 2, 2})
        };

        SortColors_75 solution;

        for (size_t i = 0; i < testCases.size(); ++i) {
            std::vector<int> arr = testCases[i].input;
            solution.sortColors(arr);

            bool pass = (arr == testCases[i].expected);
            std::cout << "SortColors Test " << (i + 1) << ": "
                    << (pass ? "PASS" : "FAIL")
                    << " (Expected: [";
            for (size_t j = 0; j < testCases[i].expected.size(); ++j) {
                std::cout << testCases[i].expected[j]
                        << (j + 1 < testCases[i].expected.size() ? ", " : "");
            }
            std::cout << "], Got: [";
            for (size_t j = 0; j < arr.size(); ++j) {
                std::cout << arr[j] << (j + 1 < arr.size() ? ", " : "");
            }
            std::cout << "])" << std::endl;
        }
    }

    static void removeDuplicatesFromSortedArrayII_80_tests() {
        // Prepare test cases:
        std::vector<RemoveDuplicatesFromSortedArrayIITestCase> testCases = {
            // 2 examples from the problem statement:
            RemoveDuplicatesFromSortedArrayIITestCase({1,1,1,2,2,3}, 5, {1,1,2,2,3}),           // Example 1
            RemoveDuplicatesFromSortedArrayIITestCase({0,0,1,1,1,1,2,3,3}, 7, {0,0,1,1,2,3,3}), // Example 2

            // 3 additional (one corner case):
            RemoveDuplicatesFromSortedArrayIITestCase({42}, 1, {42}),                       // Corner: single element
            RemoveDuplicatesFromSortedArrayIITestCase({2,2,2,2}, 2, {2,2}),                 // All duplicates
            RemoveDuplicatesFromSortedArrayIITestCase({1,1,2,2,2,3,3}, 6, {1,1,2,2,3,3})    // Mixed duplicates
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
                    if (nums[idx] != testCases[i].expectedResult[idx]) {
                        pass = false;
                        break;
                    }
                }
            }

            std::cout << "RemoveDuplicatesFromSortedArrayII_80 Test " << (i + 1) << ": "
                    << (pass ? "PASS" : "FAIL")
                    << " (Expected k=" << testCases[i].expectedK
                    << ", got k=" << k << ")" << std::endl;
        }
    }

    static void bestTimeToBuyAndSellStockII_122_tests() {
        std::vector<BestTimeToBuyAndSellStockII_122_TestCase> testCases = {
            // 3 examples from the problem statement:
            BestTimeToBuyAndSellStockII_122_TestCase({7,1,5,3,6,4}, 7), // Example 1
            BestTimeToBuyAndSellStockII_122_TestCase({1,2,3,4,5}, 4),   // Example 2
            BestTimeToBuyAndSellStockII_122_TestCase({7,6,4,3,1}, 0),   // Example 3

            // 2 additional, more complicated examples:
            // For prices = [2,4,1,10,9,11]:
            // Day-to-day profit breakdown: (4-2)=2, (10-1)=9, (11-9)=2, total profit = 2+9+2 = 13.
            BestTimeToBuyAndSellStockII_122_TestCase({2,4,1,10,9,11}, 13),

            // For prices = [3,3,5,0,0,3,1,4]:
            // Day-to-day profit breakdown: (5-3)=2, (3-0)=3, (4-1)=3, total profit = 2+3+3 = 8.
            BestTimeToBuyAndSellStockII_122_TestCase({3,3,5,0,0,3,1,4}, 8)
        };

        // Instantiate the solution class
        BestTimeToBuyAndSellStockII_122 solution;

        // Test each case
        for (size_t i = 0; i < testCases.size(); ++i) {
            int result = solution.maxProfit(testCases[i].prices);

            bool pass = (result == testCases[i].expectedProfit);
            std::cout << "BestTimeToBuyAndSellStockII_122 Test " << (i + 1) << ": "
                    << (pass ? "PASS" : "FAIL")
                    << " (Expected " << testCases[i].expectedProfit
                    << ", got " << result << ")" << std::endl;
        }
    }

    static void validAnagram_242_tests() {
        std::vector<ValidAnagramTestCase> testCases = {
            // Examples from the problem statement
            ValidAnagramTestCase("anagram", "nagaram", true),
            ValidAnagramTestCase("rat", "car", false),

            // Additional complex test cases
            ValidAnagramTestCase("abcdefg", "gfedcba", true), // Reverse order, still an anagram
            ValidAnagramTestCase("aabbcc", "abcabc", true),   // Same frequency, different order
            ValidAnagramTestCase(std::string(50000, 'a') + "b", std::string(50000, 'a') + "c", false) // Edge case with large input, one character differs
        };

        ValidAnagram_242 solution;

        for (size_t i = 0; i < testCases.size(); ++i) {
            bool result = solution.isAnagram(testCases[i].s, testCases[i].t);
            std::cout << "Valid Anagram Test " << (i + 1) << ": res = "
                    << (result == testCases[i].expectedResult ? "PASS" : "FAIL")
                    << " (Expected: " << (testCases[i].expectedResult ? "true" : "false")
                    << ", Got: " << (result ? "true" : "false") << ")" << std::endl;
        }
    }

    static void analyzeUserWebsiteVisitPattern_1152_tests() {
        std::vector<AnalyzeUserWebsiteVisitPatternTestCase> testCases = {
            // Example 1 (From Problem Statement)
            AnalyzeUserWebsiteVisitPatternTestCase(
                {"joe", "joe", "joe", "james", "james", "james", "james", "mary", "mary", "mary"},
                {1, 2, 3, 4, 5, 6, 7, 8, 9, 10},
                {"home", "about", "career", "home", "cart", "maps", "home", "home", "about", "career"},
                {"home", "about", "career"}
            ),
            // Example 2 (From Problem Statement)
            AnalyzeUserWebsiteVisitPatternTestCase(
                {"ua", "ua", "ua", "ub", "ub", "ub"},
                {1, 2, 3, 4, 5, 6},
                {"a", "b", "a", "a", "b", "c"},
                {"a", "b", "a"}
            ),
            // Corner Case: Only one user with exactly three visits
            AnalyzeUserWebsiteVisitPatternTestCase(
                {"alice", "alice", "alice"},
                {1, 2, 3},
                {"x", "y", "z"},
                {"x", "y", "z"}
            ),
            // Large Complex Case: Multiple users with different patterns
            AnalyzeUserWebsiteVisitPatternTestCase(
                {"u1", "u1", "u1", "u1", "u2", "u2", "u2", "u3", "u3", "u3", "u3", "u3"},
                {1, 2, 3, 4, 5, 6, 7, 1, 2, 3, 4, 5},
                {"alpha", "beta", "gamma", "delta", "alpha", "beta", "gamma", "beta", "gamma", "alpha", "delta", "beta"},
                {"alpha", "beta", "gamma"}
            ),
            // Another more complex test
            AnalyzeUserWebsiteVisitPatternTestCase(
                {"u1", "u1", "u1", "u2", "u2", "u2", "u3", "u3", "u3", "u4", "u4", "u4"},
                {1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3},
                {"home", "about", "career", "home", "about", "career", "home", "career", "about", "career", "about", "home"},
                {"home", "about", "career"}
            ),
            // Complex case with a tie, forcing lexicographical sorting
            AnalyzeUserWebsiteVisitPatternTestCase(
                {"u1", "u1", "u1", "u2", "u2", "u2", "u3", "u3", "u3", "u4", "u4", "u4", "u5", "u5", "u5", "u6", "u6", "u6"},
                {1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3},
                {"alpha", "beta", "gamma", "alpha", "beta", "gamma", "beta", "gamma", "delta",
                 "beta", "gamma", "delta", "alpha", "beta", "gamma", "alpha", "beta", "gamma"},
                {"alpha", "beta", "gamma"}  // Lexicographically smaller, tie-breaking case
            )
        };
    
        AnalyzeUserWebsiteVisitPattern1152 solver;
    
        for (size_t i = 0; i < testCases.size(); ++i) {
            std::vector<std::string> result_map = solver.mostVisitedPattern_usingMap(testCases[i].username, testCases[i].timestamp, testCases[i].website);
            std::vector<std::string> result_hashmap = solver.mostVisitedPattern_usingHashmap(testCases[i].username, testCases[i].timestamp, testCases[i].website);
    
            bool pass_map = (result_map == testCases[i].expectedResult);
            bool pass_hashmap = (result_hashmap == testCases[i].expectedResult);
            bool pass_consistency = (result_map == result_hashmap);
    
            std::cout << "AnalyzeUserWebsiteVisitPattern Test " << (i + 1) << ": \n";
    
            std::cout << " - Using Map: " << (pass_map ? "PASS" : "FAIL") << " (Expected: ";
            for (const auto& s : testCases[i].expectedResult) std::cout << s << " ";
            std::cout << ", Got: ";
            for (const auto& s : result_map) std::cout << s << " ";
            std::cout << ")\n";
    
            std::cout << " - Using Hashmap: " << (pass_hashmap ? "PASS" : "FAIL") << " (Expected: ";
            for (const auto& s : testCases[i].expectedResult) std::cout << s << " ";
            std::cout << ", Got: ";
            for (const auto& s : result_hashmap) std::cout << s << " ";
            std::cout << ")\n";
    
            std::cout << " - Consistency Check (Map vs Hashmap): " << (pass_consistency ? "PASS" : "FAIL") << "\n\n";
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
        std::cout << "Running ImplementTrie_208 tests:\n";
        implementTrie_208_tests();
        std::cout << "Running KthLargestElementInArray_215 tests:\n";
        kthLargestElement_215_tests();
        std::cout << "Running MinHeap tests:\n";
        minHeap_tests();
        std::cout << "Running RotateImage_48 tests:\n";
        rotateImage_48_tests();
        std::cout << "Running MergeIntervals_56 tests:\n";
        mergeIntervals_56_tests();
        std::cout << "Running MergeKSortedLists_23 tests:\n";
        mergeKLists_tests();
        std::cout << "Running ProductOfArrayExceptSelf_238 tests:\n";
        productOfArrayExceptSelf_tests();
        std::cout << "Running MajorityElement_169 tests:\n";
        majorityElement_tests();
        std::cout << "Running Evaluate Reverse Polish Notation_150 tests:\n";
        evaluateReversePolishNotation_150_tests();
        std::cout << "Running LargestRectangleInHistogram_84 tests:\n";
        largestRectangleArea_tests();
        std::cout << "Running WordSearch_79 tests:\n";
        runWordSearchTests();
        std::cout << "Running ValidParentheses_20 tests:\n";
        runValidParenthesesTests();
        std::cout << "Running ValidSudoku_36 tests:\n";
        validSudoku_36_tests();
        std::cout << "Running BinarySearch_704 tests:\n";
        binarySearch_704_tests();
        std::cout << "Running Search Insert Position_35 tests:\n";
        searchInsertPosition_35_tests();
        std::cout << "Running Search 2D Matrix_74 tests:\n";
        search2DMatrixTests();
        std::cout << "Running All O One Data Structure_432) tests:\n";
        allOne_432_tests();
        std::cout << "Running Find Minimum in Rotated Sorted Array_153 tests:\n";
        findMinimumInRotatedSortedArray_153_tests();
        std::cout << "Clone Graph_133 tests:\n";
        cloneGraph_133_tests();
        std::cout << "Zigzag Conversion_6 tests:\n";
        zigzagConversion_6_tests();
        std::cout << "H-Index_274 tests:\n";
        hIndex_274_tests();
        std::cout << "Sort Colors_75 tests:\n";
        sortColors_75_tests();
        std::cout << "Remove Duplicates From Sorted Array II_80 tests:\n";
        removeDuplicatesFromSortedArrayII_80_tests();
        std::cout << "Best Time To Buy And Sell Stock II_122 tests:\n";
        bestTimeToBuyAndSellStockII_122_tests();
        std::cout << "Valid Annagram_242 tests:\n";
        validAnagram_242_tests();
        std::cout << "Analyze User Website Visit Pattern_1152 tests:\n";
        analyzeUserWebsiteVisitPattern_1152_tests();
    }
};

int main() {
    std::cout << "Running LeetCodeCpp tests:\n";
    TestsRunner::runAllTests();
    return 0;
}
