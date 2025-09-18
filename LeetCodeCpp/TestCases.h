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

    // 876. Middle of the Linked List
    struct MiddleOfLinkedListTestCase {
        vector<int> input;
        vector<int> expected;

        MiddleOfLinkedListTestCase(vector<int> in, vector<int> exp)
            : input(move(in)), expected(move(exp)) {}
    };

    // 19. Remove Nth Node From End of List
    struct RemoveNthNodeTestCase {
        vector<int> input;
        int n;
        vector<int> expected;

        RemoveNthNodeTestCase(vector<int> in, int nth, vector<int> exp)
            : input(move(in)), n(nth), expected(move(exp)) {}
    };

    // 121. Best Time to Buy and Sell Stock
    struct MaxProfitTestCase {
        vector<int> prices;
        int expected;

        MaxProfitTestCase(vector<int> p, int e)
            : prices(move(p)), expected(e) {}
    };

    // 54. Spiral Matrix
    struct SpiralMatrixTestCase {
        vector<vector<int>> matrix;
        vector<int> expected;

        SpiralMatrixTestCase(vector<vector<int>> m, vector<int> exp)
            : matrix(move(m)), expected(move(exp)) {}
    };

    // 98. Validate Binary Search Tree
    struct ValidateBinarySearchTreeTestCase {
        vector<optional<int>> tree; // level-order input
        bool expected;

        ValidateBinarySearchTreeTestCase(vector<optional<int>> t, bool e)
            : tree(move(t)), expected(e) {}
    };

    // 235. Lowest Common Ancestor of a BST
    struct LowestCommonAncestorTestCase {
        vector<optional<int>> tree; // level-order input
        int p;
        int q;
        int expected;

        LowestCommonAncestorTestCase(vector<optional<int>> t, int node1, int node2, int lca)
            : tree(move(t)), p(node1), q(node2), expected(lca) {}
    };

    // 138. Copy List with Random Pointer
    struct CopyRandomListTestCase {
        vector<pair<int, optional<int>>> input;    // {val, randomIndex or nullopt}
        vector<pair<int, optional<int>>> expected;

        CopyRandomListTestCase(vector<pair<int, optional<int>>> in,
                            vector<pair<int, optional<int>>> exp)
            : input(move(in)), expected(move(exp)) {}
    };

    // 230. Kth Smallest Element in a BST
    struct KthSmallestTestCase {
        vector<optional<int>> tree; // BST as vector
        int k;
        int expected;

        KthSmallestTestCase(vector<optional<int>> t, int kVal, int e)
            : tree(move(t)), k(kVal), expected(e) {}
    };

    // 208. Implement Trie (Prefix Tree)
    struct TrieTestCase {
        vector<string> operations;
        vector<optional<string>> arguments;
        vector<optional<bool>> expected;

        TrieTestCase(vector<string> ops,
                    vector<optional<string>> args,
                    vector<optional<bool>> exp)
            : operations(move(ops)), arguments(move(args)), expected(move(exp)) {}
    };

    // 215. Kth Largest Element in an Array
    struct KthLargestElementTestCase {
        vector<int> nums;
        int k;
        int expected;

        KthLargestElementTestCase(vector<int> n, int kVal, int e)
            : nums(move(n)), k(kVal), expected(e) {}
    };

    // Min Heap (custom)
    struct MinHeapTestCase {
        vector<pair<string, int>> operations; // {op, value(if any)}
        vector<int> expected;

        MinHeapTestCase(vector<pair<string, int>> ops, vector<int> exp)
            : operations(move(ops)), expected(move(exp)) {}
    };

    // 48. Rotate Image
    struct RotateImageTestCase {
        vector<vector<int>> input;
        vector<vector<int>> expected;

        RotateImageTestCase(vector<vector<int>> in, vector<vector<int>> exp)
            : input(move(in)), expected(move(exp)) {}
    };

    // 56. Merge Intervals
    struct MergeIntervalsTestCase {
        vector<vector<int>> input;
        vector<vector<int>> expected;

        MergeIntervalsTestCase(vector<vector<int>> in, vector<vector<int>> exp)
            : input(move(in)), expected(move(exp)) {}
    };

    // 23. Merge k Sorted Lists
    struct MergeKListsTestCase {
        vector<vector<int>> input;
        vector<int> expected;

        MergeKListsTestCase(vector<vector<int>> in, vector<int> exp)
            : input(move(in)), expected(move(exp)) {}
    };

    // 238. Product of Array Except Self
    struct ProductOfArrayExceptSelfTestCase {
        vector<int> input;
        vector<int> expected;

        ProductOfArrayExceptSelfTestCase(vector<int> in, vector<int> exp)
            : input(move(in)), expected(move(exp)) {}
    };

    // 169. Majority Element
    struct MajorityElementTestCase {
        vector<int> input;
        int expected;

        MajorityElementTestCase(vector<int> in, int exp)
            : input(move(in)), expected(exp) {}
    };

    // 150. Evaluate Reverse Polish Notation
    struct EvaluateRPNTestCase {
        vector<string> input;
        int expected;

        EvaluateRPNTestCase(vector<string> in, int exp)
            : input(move(in)), expected(exp) {}
    };

    // 84. Largest Rectangle in Histogram
    struct LargestRectangleTestCase {
        vector<int> input;
        int expected;

        LargestRectangleTestCase(vector<int> in, int exp)
            : input(move(in)), expected(exp) {}
    };

    // 79. Word Search
    struct WordSearchTestCase {
        vector<vector<char>> board;
        string word;
        bool expected;

        WordSearchTestCase(vector<vector<char>> b, string w, bool exp)
            : board(move(b)), word(move(w)), expected(exp) {}
    };

    // 20. Valid Parentheses
    struct ValidParenthesesTestCase {
        string input;
        bool expected;

        ValidParenthesesTestCase(string in, bool exp)
            : input(move(in)), expected(exp) {}
    };

    // 36. Valid Sudoku
    struct ValidSudokuTestCase {
        vector<vector<char>> board;
        bool expected;

        ValidSudokuTestCase(vector<vector<char>> b, bool exp)
            : board(move(b)), expected(exp) {}
    };

    // 704. Binary Search
    struct BinarySearchTestCase {
        vector<int> input;
        int target;
        int expected;

        BinarySearchTestCase(vector<int> in, int tgt, int exp)
            : input(move(in)), target(tgt), expected(exp) {}
    };

    // 74. Search a 2D Matrix
    struct Search2DMatrixTestCase {
        vector<vector<int>> matrix;
        int target;
        bool expected;

        Search2DMatrixTestCase(vector<vector<int>> mat, int tgt, bool exp)
            : matrix(move(mat)), target(tgt), expected(exp) {}
    };

    // 153. Find Minimum in Rotated Sorted Array
    struct FindMinTestCase {
        vector<int> input;
        int expected;

        FindMinTestCase(vector<int> in, int exp) : input(move(in)), expected(exp) {}
    };

    // 6. Zigzag Conversion
    struct ZigzagTestCase {
        string input;
        int numRows;
        string expected;

        ZigzagTestCase(string s, int n, string exp)
            : input(move(s)), numRows(n), expected(move(exp)) {}
    };

    // 274. H-Index
    struct HIndexTestCase {
        vector<int> input;
        int expected;

        HIndexTestCase(vector<int> in, int exp)
            : input(move(in)), expected(exp) {}
    };

    // 75. Sort Colors
    struct SortColorsTestCase {
        vector<int> input;
        vector<int> expected;

        SortColorsTestCase(vector<int> in, vector<int> exp)
            : input(move(in)), expected(move(exp)) {}
    };

    // 80. Remove Duplicates from Sorted Array II
    struct RemoveDuplicatesFromSortedArrayIITestCase {
        vector<int> input;
        int expectedK;
        vector<int> expected;

        RemoveDuplicatesFromSortedArrayIITestCase(vector<int> in, int k, vector<int> exp)
            : input(move(in)), expectedK(k), expected(move(exp)) {}
    };

    // 122. Best Time to Buy and Sell Stock II
    struct BestTimeToBuyAndSellStockII_122_TestCase {
        vector<int> prices;
        int expected;

        BestTimeToBuyAndSellStockII_122_TestCase(vector<int> p, int exp)
            : prices(move(p)), expected(exp) {}
    };

    // 242. Valid Anagram
    struct ValidAnagramTestCase {
        string s;
        string t;
        bool expected;

        ValidAnagramTestCase(string s1, string s2, bool exp)
            : s(move(s1)), t(move(s2)), expected(exp) {}
    };

    // 692. Top K Frequent Words
    struct TopKFrequentWordsTestCase {
        vector<string> input;
        int k;
        vector<string> expected;

        TopKFrequentWordsTestCase(vector<string> in, int kk, vector<string> exp)
            : input(move(in)), k(kk), expected(move(exp)) {}
    };

    // 1152. Analyze User Website Visit Pattern
    struct AnalyzeUserWebsiteVisitPatternTestCase {
        vector<string> username;
        vector<int> timestamp;
        vector<string> website;
        vector<string> expected;

        AnalyzeUserWebsiteVisitPatternTestCase(vector<string> u, vector<int> t, vector<string> w, vector<string> exp)
            : username(move(u)), timestamp(move(t)), website(move(w)), expected(move(exp)) {}
    };

    // 49. Group Anagrams
    struct GroupAnagramsTestCase {
        vector<string> input;
        vector<vector<string>> expected;

        GroupAnagramsTestCase(vector<string> in, vector<vector<string>> exp)
            : input(move(in)), expected(move(exp)) {}
    };

    // 277. Find the Celebrity
    struct FindCelebrityTestCase {
        vector<vector<int>> matrix;
        int expected;

        FindCelebrityTestCase(vector<vector<int>> m, int exp)
            : matrix(move(m)), expected(exp) {}
    };

    // 128. Longest Consecutive Sequence
    struct LongestConsecutiveSequenceTestCase {
        vector<int> input;
        int expected;

        LongestConsecutiveSequenceTestCase(vector<int> in, int exp)
            : input(move(in)), expected(exp) {}
    };

    // 424. Longest Repeating Character Replacement
    struct LongestRepeatingCharReplacementTestCase {
        string input;
        int k;
        int expected;

        LongestRepeatingCharReplacementTestCase(string s, int kk, int exp)
            : input(move(s)), k(kk), expected(exp) {}
    };

    // 146. LRU Cache
    struct LRUCacheTestCase {
        vector<string> operations;
        vector<vector<int>> arguments;
        vector<optional<int>> expected;

        LRUCacheTestCase(vector<string> ops, vector<vector<int>> args, vector<optional<int>> exp)
            : operations(move(ops)), arguments(move(args)), expected(move(exp)) {}
    };

    // 322. Coin Change
    struct CoinChangeTestCase {
        vector<int> coins;
        int amount;
        int expected;

        CoinChangeTestCase(vector<int> c, int a, int exp)
            : coins(move(c)), amount(a), expected(exp) {}
    };

    // 2360. Longest Cycle in a Graph
    struct LongestCycleTestCase {
        vector<int> edges;
        int expected;

        LongestCycleTestCase(vector<int> e, int exp)
            : edges(move(e)), expected(exp) {}
    };

    // 2608. Shortest Cycle in a Graph
    struct ShortestCycleTestCase {
        int n;
        vector<vector<int>> edges;
        int expected;

        ShortestCycleTestCase(int nn, vector<vector<int>> e, int exp)
            : n(nn), edges(move(e)), expected(exp) {}
    };

    // 63. Unique Paths II
    struct UniquePathsIITestCase {
        vector<vector<int>> input;
        int expected;

        UniquePathsIITestCase(vector<vector<int>> in, int exp)
            : input(move(in)), expected(exp) {}
    };

    // 855. Exam Room
    struct ExamRoomTestCase {
        vector<string> operations;
        vector<vector<int>> arguments;       // each op's int args
        vector<optional<int>> expected;      // nullopt for void ops
    };
} // namespace TestCases
