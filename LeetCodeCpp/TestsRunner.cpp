#include <iostream>
#include <string>
#include <vector>
#include <optional>
#include <cmath>
#include <variant>
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

using namespace std;

// Helper to compare two doubles within 1e-5
static bool approxEqual(double a, double b, double eps = 1e-5) {
    return fabs(a - b) < eps;
}

struct ScheduleTestCase {
    int numCourses;
    vector<vector<int>> prerequisites;
    bool expectedResult;

    ScheduleTestCase(int num, vector<vector<int>> prereq, bool result)
        : numCourses(num), prerequisites(move(prereq)), expectedResult(result) {}
};

struct PathTestCase {
    int n;
    vector<vector<int>> edges;
    int source;
    int destination;
    bool expectedResult;

    PathTestCase(int nodes, vector<vector<int>> edg, int src, int dest, bool result)
        : n(nodes), edges(move(edg)), source(src), destination(dest), expectedResult(result) {}
};

struct NumIslandsTestCase {
    vector<vector<char>> grid;
    int expectedResult;

    NumIslandsTestCase(vector<vector<char>> g, int e)
        : grid(move(g)), expectedResult(e) {}
};

struct MaxAreaTestCase {
    vector<vector<int>> grid;
    int expectedResult;

    MaxAreaTestCase(vector<vector<int>> g, int e)
        : grid(move(g)), expectedResult(e) {}
};

struct CourseScheduleIITestCase {
    int numCourses;
    vector<vector<int>> prerequisites;
    vector<int> expectedOrder;

    CourseScheduleIITestCase(int num, vector<vector<int>> prereq, vector<int> order)
        : numCourses(num), prerequisites(move(prereq)), expectedOrder(move(order)) {}
};

struct NetworkDelayTimeTestCase {
    vector<vector<int>> times;
    int n;
    int k;
    int expectedResult;

    NetworkDelayTimeTestCase(vector<vector<int>> t, int nodes, int start, int result)
        : times(move(t)), n(nodes), k(start), expectedResult(result) {}
};

struct RottingOrangesTestCase {
    vector<vector<int>> grid;
    int expectedResult;

    RottingOrangesTestCase(vector<vector<int>> g, int e)
        : grid(move(g)), expectedResult(e) {}
};

struct PacificAtlanticTestCase {
    vector<vector<int>> heights;
    vector<vector<int>> expectedResult;

    PacificAtlanticTestCase(vector<vector<int>> h, vector<vector<int>> e)
        : heights(move(h)), expectedResult(move(e)) {}
};

struct MinCostToConnectAllPointsTestCase {
    vector<vector<int>> points;
    int expectedResult;

    MinCostToConnectAllPointsTestCase(vector<vector<int>> p, int e)
        : points(move(p)), expectedResult(e) {}
};

struct LongestCommonSubsequenceTestCase {
    string text1;
    string text2;
    int expectedResult;

    LongestCommonSubsequenceTestCase(string t1, string t2, int e)
        : text1(move(t1)), text2(move(t2)), expectedResult(e) {}
};

struct LongestIncreasingSubsequenceTestCase {
    vector<int> nums;
    int expectedResult;

    LongestIncreasingSubsequenceTestCase(vector<int> n, int e)
        : nums(move(n)), expectedResult(e) {}
};

struct RemoveDuplicatesTestCase {
    vector<int> inputList;
    vector<int> expectedList;

    RemoveDuplicatesTestCase(vector<int> input, vector<int> expected)
        : inputList(move(input)), expectedList(move(expected)) {}
};

struct ReverseListTestCase {
    vector<int> inputList;
    vector<int> expectedList;

    ReverseListTestCase(vector<int> input, vector<int> expected)
        : inputList(move(input)), expectedList(move(expected)) {}
};

struct MergeTwoListsTestCase {
    vector<int> list1;
    vector<int> list2;
    vector<int> expectedList;

    MergeTwoListsTestCase(vector<int> l1, vector<int> l2, vector<int> expected)
        : list1(move(l1)), list2(move(l2)), expectedList(move(expected)) {}
};

struct LinkedListCycleTestCase {
    vector<int> inputList;
    int pos;
    bool expectedResult;

    LinkedListCycleTestCase(vector<int> input, int cyclePos, bool expected)
        : inputList(move(input)), pos(cyclePos), expectedResult(expected) {}
};

struct MiddleOfLinkedListTestCase {
    vector<int> inputList;
    vector<int> expectedList;

    MiddleOfLinkedListTestCase(vector<int> input, vector<int> expected)
        : inputList(move(input)), expectedList(move(expected)) {}
};

struct RemoveNthNodeTestCase {
    vector<int> inputList;
    int n;
    vector<int> expectedList;

    RemoveNthNodeTestCase(vector<int> input, int nth, vector<int> expected)
        : inputList(move(input)), n(nth), expectedList(move(expected)) {}
};

struct MaxProfitTestCase {
    vector<int> prices;
    int expectedResult;

    MaxProfitTestCase(vector<int> p, int e) : prices(move(p)), expectedResult(e) {}
};

struct SpiralMatrixTestCase {
    vector<vector<int>> matrix;
    vector<int> expectedResult;

    SpiralMatrixTestCase(vector<vector<int>> m, vector<int> e)
        : matrix(move(m)), expectedResult(move(e)) {}
};

struct ValidateBinarySearchTreeTestCase {
    vector<optional<int>> tree; // Input as vector
    bool expectedResult;                  // Expected output

    ValidateBinarySearchTreeTestCase(vector<optional<int>> t, bool e)
        : tree(move(t)), expectedResult(e) {}
};

struct LowestCommonAncestorTestCase {
    vector<optional<int>> tree; // Tree represented as a vector
    int p;                                // Value of the first node
    int q;                                // Value of the second node
    int expectedLCA;                      // Expected LCA value

    LowestCommonAncestorTestCase(const vector<optional<int>>& t, int node1, int node2, int lca)
        : tree(move(t)), p(node1), q(node2), expectedLCA(lca) {}
};

struct CopyRandomListTestCase {
    vector<pair<int, optional<int>>> inputList;
    vector<pair<int, optional<int>>> expectedList;

    CopyRandomListTestCase(vector<pair<int, optional<int>>> input,
                           vector<pair<int, optional<int>>> expected)
        : inputList(move(input)), expectedList(move(expected)) {}
};

struct KthSmallestTestCase {
    vector<optional<int>> tree; // Tree represented as a vector
    int k;                                // kth position
    int expectedResult;                   // Expected result

    KthSmallestTestCase(const vector<optional<int>>& t, int kVal, int e)
        : tree(move(t)), k(kVal), expectedResult(e) {}
};

struct TrieTestCase {
    vector<string> operations;
    vector<optional<string>> arguments;
    vector<optional<bool>> expectedResults;

    TrieTestCase(const vector<string> ops, const vector<optional<string>> args, const vector<optional<bool>> expected)
        : operations(move(ops)), arguments(move(args)), expectedResults(move(expected)) {}
};

struct KthLargestElementTestCase {
    vector<int> nums;
    int k;
    int expectedResult;

    KthLargestElementTestCase(vector<int> n, int kVal, int e)
        : nums(move(n)), k(kVal), expectedResult(e) {}
};

struct MinHeapTestCase {
    vector<pair<string, int>> operations; // {operation, value (if any)}
    vector<int> expectedResults;                   // Expected results for operations

    MinHeapTestCase(vector<pair<string, int>> ops, vector<int> results)
        : operations(move(ops)), expectedResults(move(results)) {}
};

struct RotateImageTestCase {
    vector<vector<int>> inputMatrix;
    vector<vector<int>> expectedMatrix;

    RotateImageTestCase(vector<vector<int>> input, vector<vector<int>> expected)
        : inputMatrix(move(input)), expectedMatrix(move(expected)) {}
};

struct MergeIntervalsTestCase {
    vector<vector<int>> intervals;
    vector<vector<int>> expectedResult;

    MergeIntervalsTestCase(vector<vector<int>> input, vector<vector<int>> expected)
        : intervals(move(input)), expectedResult(move(expected)) {}
};

struct MergeKListsTestCase {
    vector<vector<int>> inputLists;
    vector<int> expectedList;

    MergeKListsTestCase(vector<vector<int>> inputs, vector<int> expected)
        : inputLists(move(inputs)), expectedList(move(expected)) {}
};

struct ProductOfArrayExceptSelfTestCase {
    vector<int> nums;
    vector<int> expectedResult;

    ProductOfArrayExceptSelfTestCase(vector<int> input, vector<int> expected)
        : nums(move(input)), expectedResult(move(expected)) {}
};

struct MajorityElementTestCase {
    vector<int> nums;
    int expectedResult;

    MajorityElementTestCase(vector<int> nums, int result)
        : nums(move(nums)), expectedResult(result) {}
};

struct EvaluateRPNTestCase {
    vector<string> tokens;
    int expectedResult;

    EvaluateRPNTestCase(vector<string> t, int e)
        : tokens(move(t)), expectedResult(e) {}
};

struct LargestRectangleTestCase {
    vector<int> heights;
    int expectedArea;

    LargestRectangleTestCase(vector<int> h, int area)
        : heights(move(h)), expectedArea(area) {}
};

struct WordSearchTestCase {
    vector<vector<char>> board;
    string word;
    bool expectedResult;

    WordSearchTestCase(vector<vector<char>> b, string w, bool e)
        : board(move(b)), word(move(w)), expectedResult(e) {}
};

struct ValidParenthesesTestCase {
    string input;
    bool expectedResult;

    ValidParenthesesTestCase(string in, bool result)
        : input(move(in)), expectedResult(result) {}
};

struct ValidSudokuTestCase {
    vector<vector<char>> board;
    bool expectedResult;

    ValidSudokuTestCase(vector<vector<char>> b, bool e)
        : board(move(b)), expectedResult(e) {}
};

struct BinarySearchTestCase {
    vector<int> nums;
    int target;
    int expectedResult;

    BinarySearchTestCase(vector<int> n, int t, int e)
        : nums(move(n)), target(t), expectedResult(e) {}
};

struct Search2DMatrixTestCase {
    vector<vector<int>> matrix;
    int target;
    bool expectedResult;

    Search2DMatrixTestCase(vector<vector<int>> mat, int tgt, bool result)
        : matrix(move(mat)), target(tgt), expectedResult(result) {}
};

struct FindMinTestCase {
    vector<int> nums;
    int expectedResult;

    FindMinTestCase(vector<int> n, int e) : nums(move(n)), expectedResult(e) {}
};

struct ZigzagTestCase {
    string input;
    int numRows;
    string expected;

    ZigzagTestCase(string s, int n, string e)
        : input(move(s)), numRows(n), expected(move(e)) {}
};

struct HIndexTestCase {
    vector<int> citations;
    int expectedResult;

    HIndexTestCase(vector<int> c, int e)
        : citations(move(c)), expectedResult(e) {}
};

struct SortColorsTestCase {
    vector<int> input;
    vector<int> expected;

    SortColorsTestCase(vector<int> in, vector<int> exp)
        : input(move(in)), expected(move(exp)) {}
};

struct RemoveDuplicatesFromSortedArrayIITestCase {
    vector<int> input;
    int expectedK;
    vector<int> expectedResult;

    RemoveDuplicatesFromSortedArrayIITestCase(vector<int> in, int k, vector<int> exp)
        : input(move(in)), expectedK(k), expectedResult(move(exp)) {}
};

struct BestTimeToBuyAndSellStockII_122_TestCase {
    vector<int> prices;
    int expectedProfit;

    BestTimeToBuyAndSellStockII_122_TestCase(vector<int> p, int e)
        : prices(move(p)), expectedProfit(e) {}
};

struct ValidAnagramTestCase {
    string s;
    string t;
    bool expectedResult;

    ValidAnagramTestCase(string str1, string str2, bool result)
        : s(move(str1)), t(move(str2)), expectedResult(result) {}
};

struct TopKFrequentWordsTestCase {
    vector<string> words;
    int k;
    vector<string> expected;

    TopKFrequentWordsTestCase(vector<string> w, int kk, vector<string> e)
        : words(move(w)), k(kk), expected(move(e)) {}
};

struct AnalyzeUserWebsiteVisitPatternTestCase {
    vector<string> username;
    vector<int> timestamp;
    vector<string> website;
    vector<string> expectedResult;

    AnalyzeUserWebsiteVisitPatternTestCase(vector<string> u, vector<int> t, vector<string> w, vector<string> e)
        : username(move(u)), timestamp(move(t)), website(move(w)), expectedResult(move(e)) {}
};

struct GroupAnagramsTestCase {
    vector<string> input;
    vector<vector<string>> expected;

    GroupAnagramsTestCase(vector<string> in, vector<vector<string>> exp)
        : input(move(in)), expected(move(exp)) {}
};

struct FindCelebrityTestCase {
    vector<vector<int>> matrix;
    int expectedResult;

    FindCelebrityTestCase(vector<vector<int>> m, int e)
        : matrix(move(m)), expectedResult(e) {}
};

struct LongestConsecutiveSequenceTestCase {
    vector<int> nums;
    int expectedResult;
    LongestConsecutiveSequenceTestCase(vector<int> n, int e)
        : nums(move(n)), expectedResult(e) {}
};

struct LongestRepeatingCharReplacementTestCase {
    string s;
    int k;
    int expectedResult;
    LongestRepeatingCharReplacementTestCase(string str, int kk, int exp)
        : s(move(str)), k(kk), expectedResult(exp) {}
};

struct LRUCacheTestCase {
    vector<string> operations;
    vector<vector<int>> arguments;
    vector<optional<int>> expectedResults;

    LRUCacheTestCase(
        vector<string> ops,
        vector<vector<int>> args,
        vector<optional<int>> exps
    )
      : operations(move(ops))
      , arguments(move(args))
      , expectedResults(move(exps))
    {}
};

struct CoinChangeTestCase {
    vector<int> coins;
    int amount;
    int expectedResult;

    CoinChangeTestCase(vector<int> c, int a, int e)
        : coins(move(c)), amount(a), expectedResult(e) {}
};

struct LongestCycleTestCase {
    vector<int> edges;
    int expectedResult;

    LongestCycleTestCase(vector<int> e, int r)
        : edges(move(e)), expectedResult(r) {}
};

struct ShortestCycleTestCase {
    int n;
    vector<vector<int>> edges;
    int expected;

    ShortestCycleTestCase(int nn,
                          vector<vector<int>> e,
                          int exp)
        : n(nn), edges(move(e)), expected(exp) {}
};

struct UniquePathsIITestCase {
    vector<vector<int>> grid;
    int expectedResult;
    UniquePathsIITestCase(vector<vector<int>> g, int e)
        : grid(move(g)), expectedResult(e) {}
};

struct MaxAvgTestCase {
    vector<int> nums;
    int k;
    double expected;
    MaxAvgTestCase(vector<int> n, int kk, double e)
        : nums(move(n)), k(kk), expected(e) {}
};

struct MaxConsecutiveOnesTestCase {
    vector<int> nums;
    int k;
    int expectedResult;

    MaxConsecutiveOnesTestCase(vector<int> n, int kk, int e)
        : nums(move(n)), k(kk), expectedResult(e) {}
};

struct LongestSubstringWithoutRepeatingCharactersTestCase {
    string s;
    int expectedResult;

    LongestSubstringWithoutRepeatingCharactersTestCase(string str, int exp)
        : s(move(str)), expectedResult(exp) {}
};

struct MinimumSizeSubarraySumTestCase {
    int target;
    vector<int> nums;
    int expectedResult;

    MinimumSizeSubarraySumTestCase(int tgt, vector<int> n, int e)
        : target(tgt), nums(move(n)), expectedResult(e) {}
};

struct PermutationInStringTestCase {
    string s1;
    string s2;
    bool expectedResult;

    PermutationInStringTestCase(string first, string second, bool expected)
        : s1(move(first)), s2(move(second)), expectedResult(expected) {}
};

struct SquaresOfSortedArrayTestCase {
    vector<int> nums;
    vector<int> expectedResult;
    SquaresOfSortedArrayTestCase(vector<int> n, vector<int> e)
        : nums(move(n)), expectedResult(move(e)) {}
};

struct ReverseStringTestCase {
    vector<char> input;
    vector<char> expected;
    ReverseStringTestCase(vector<char> i, vector<char> e)
        : input(move(i)), expected(move(e)) {}
};

struct TwoSumIITestCase {
    vector<int> numbers;
    int         target;
    vector<int> expected;   // 1-indexed answer
    TwoSumIITestCase(vector<int> nums, int t, vector<int> exp)
        : numbers(move(nums)), target(t), expected(move(exp)) {}
};

struct ValidPalindromeTestCase {
    string input;
    bool expected;
    ValidPalindromeTestCase(string i, bool e)
        : input(move(i)), expected(e) {}
};

struct ThreeSumTestCase {
    vector<int> nums;
    vector<vector<int>> expected;
    ThreeSumTestCase(vector<int> n, vector<vector<int>> e)
        : nums(move(n)), expected(move(e)) {}
};

struct ContainerWithMostWaterTestCase {
    vector<int> heights;
    int expected;
    ContainerWithMostWaterTestCase(vector<int> h, int e)
        : heights(move(h)), expected(e) {}
};

struct TrappingRainWaterTestCase {
    vector<int> heights;
    int expected;
    TrappingRainWaterTestCase(vector<int> h, int e)
        : heights(move(h)), expected(e) {}
};

struct MaximalRectangleTestCase {
    vector<vector<char>> matrix;
    int expectedArea;

    MaximalRectangleTestCase(vector<vector<char>> m, int area)
        : matrix(move(m)), expectedArea(area) {}
};

struct MaximumSubarrayTestCase {
    vector<int> nums;
    int expected;

    MaximumSubarrayTestCase(vector<int> v, int e)
        : nums(move(v)), expected(e) {}
};

struct TwoSumCase {
    vector<int> nums;
    int              target;
    vector<int> expected;   // indices (any order)

    TwoSumCase(vector<int> n, int t, vector<int> e)
        : nums(move(n)), target(t), expected(move(e)) {}
};

struct MergeCase {
    vector<int> nums1;
    int              m;
    vector<int> nums2;
    int              n;
    vector<int> expected;

    MergeCase(vector<int> a, int ma,
              vector<int> b, int nb,
              vector<int> e)
        : nums1(move(a)), m(ma),
          nums2(move(b)), n(nb),
          expected(move(e)) {}
};

struct RemCase {
    vector<int> nums;
    int         val;
    int         expectedK;
    vector<int> expectedElems;   // order-agnostic

    RemCase(vector<int> a, int v, int k, vector<int> e)
        : nums(move(a)), val(v), expectedK(k),
          expectedElems(move(e)) {}
};

struct BalloonCase {
    string text;
    int         expected;
    BalloonCase(string t, int e) : text(move(t)), expected(e) {}
};

struct ABCase {
    string a, b, expected;
    ABCase(string x, string y, string e)
        : a(move(x)), b(move(y)), expected(move(e)) {}
};

struct PivotCase {
    vector<int> nums;
    int         expected;
    PivotCase(vector<int> n, int e) : nums(move(n)), expected(e) {}
};

struct HWCase {
    uint32_t n;
    int      expected;
    HWCase(uint32_t x, int e) : n(x), expected(e) {}
};

struct DecodeStringTestCase {
    string input;
    string expected;
    DecodeStringTestCase(string i, string e)
        : input(move(i)), expected(move(e)) {}
};

struct WildcardMatchingTestCase {
    string s;
    string p;
    bool   expected;
    WildcardMatchingTestCase(string ss, string pp, bool e)
        : s(move(ss)), p(move(pp)), expected(e) {}
};

struct KClosestTestCase {
    vector<vector<int>> points;
    int k;
    vector<vector<int>> expected;   // order-agnostic
    KClosestTestCase(vector<vector<int>> p, int kk, vector<vector<int>> e)
        : points(move(p)), k(kk), expected(move(e)) {}
};

struct UniquePaths62TestCase {
    int m;
    int n;
    int expected;
    UniquePaths62TestCase(int mm, int nn, int e)
        : m(mm), n(nn), expected(e) {}
};

struct BusRoutesTestCase {
    vector<vector<int>> routes;
    int source;
    int target;
    int expectedResult;

    BusRoutesTestCase(vector<vector<int>> r, int s, int t, int e)
        : routes(move(r)), source(s), target(t), expectedResult(e) {}
};

struct ShortestPathTestCase {
    vector<vector<int>> grid;
    int expected;

    ShortestPathTestCase(vector<vector<int>> g, int e)
        : grid(move(g)), expected(e) {}
};

struct GraphTC {
    vector<string> operations;
    vector<variant<monostate,
                   int,
                   vector<int>,
                   pair<int,int>,
                   pair<int,vector<vector<int>>>>> arguments;
    vector<optional<int>> expected;

    GraphTC(vector<string>  op,
            vector<variant<monostate,
                           int,
                           vector<int>,
                           pair<int,int>,
                           pair<int,vector<vector<int>>>>> arg,
            vector<optional<int>> exp)
        : operations(move(op)), arguments(move(arg)), expected(move(exp)) {}
};

struct SafestPathTestCase {
    vector<vector<int>> grid;
    int expectedResult;

    SafestPathTestCase(vector<vector<int>> g, int e)
        : grid(std::move(g)), expectedResult(e) {}
};

struct MaxDepthTestCase {
    vector<optional<int>> tree;     // level-order representation
    int expectedDepth;              // ground-truth answer

    MaxDepthTestCase(vector<optional<int>> t, int e)
        : tree(move(t)), expectedDepth(e) {}
};

struct WallsAndGatesTestCase {
    vector<vector<int>> rooms;
    vector<vector<int>> expected;

    WallsAndGatesTestCase(vector<vector<int>> r, vector<vector<int>> e)
        : rooms(move(r)), expected(move(e)) {}
};

struct ValidNumberTestCase {
    string s;
    bool   expectedResult;
    ValidNumberTestCase(string str, bool exp)
        : s(move(str)), expectedResult(exp) {}
};

struct JewelsAndStonesTestCase {
    string jewels;
    string stones;
    int    expectedResult;

    JewelsAndStonesTestCase(string j, string s, int e)
        : jewels(move(j)), stones(move(s)), expectedResult(e) {}
};

struct PerfectSquareTestCase {
    int  num;
    bool expected;
    PerfectSquareTestCase(int n, bool e) : num(n), expected(e) {}
};

static bool equalMultiset(vector<vector<int>> a, vector<vector<int>> b) {
    auto key = [](const vector<int>& p){ return make_pair(p[0], p[1]); };
    sort(a.begin(), a.end(), [&](auto& x, auto& y){ return key(x) < key(y); });
    sort(b.begin(), b.end(), [&](auto& x, auto& y){ return key(x) < key(y); });
    return a == b;
}

/* ---------- generic distance helper ---------------------------------- */
static long long distSq(const vector<int>& p) {
    return 1LL * p[0] * p[0] + 1LL * p[1] * p[1];
}

/* ---------- new validator -------------------------------------------- *
 * Returns true iff `out`
 *   1) has exactly k points,
 *   2) every point comes from the original `input`,
 *   3) every point’s distance² is ≤ the k-th smallest distance²
 *      found in the entire input set.
 */
static bool isValidKClosest(const vector<vector<int>>& input,
                            int k,
                            const vector<vector<int>>& out)
{
    if ((int)out.size() != k) return false;

    /*  Build a multiset of all original points for membership check.     */
    multiset<pair<int,int>> pool;
    for (auto& p : input) pool.emplace(p[0], p[1]);

    /*  Find the kth smallest distance² in O(n) with nth_element.         */
    vector<long long> dists;
    dists.reserve(input.size());
    for (auto& p : input) dists.push_back(distSq(p));
    nth_element(dists.begin(), dists.begin() + (k - 1), dists.end());
    long long kthDist = dists[k - 1];

    /*  Validate every output point.                                      */
    for (auto& p : out) {
        auto it = pool.find({p[0], p[1]});
        if (it == pool.end()) return false;            // not in original set
        if (distSq(p) > kthDist)   return false;       // too far
        pool.erase(it);                                // consume one copy
    }
    return true;
}

//----------------------------------------------------------------------------
// Reusable helpers for dumping containers in tests
//----------------------------------------------------------------------------
template <typename T>
void printVec(const vector<T>& v) {
    for (const auto& x : v) cout << x << ' ';
    cout << '\n';
}

template <typename T>
void printMatrix(const vector<vector<T>>& m) {
    for (const auto& row : m) printVec(row);
}

class TestsRunner {
public:
    static void courseSchedule_207_tests() {
        vector<ScheduleTestCase> testCases = {
            ScheduleTestCase(2, {{1, 0}}, true),
            ScheduleTestCase(2, {{1, 0}, {0, 1}}, false),
            ScheduleTestCase(5, {{0, 1}, {2, 3}, {3, 4}, {2, 1}}, true),
            ScheduleTestCase(5, {{0, 1}, {2, 3}, {3, 4}, {2, 1}, {4, 2}}, false),
        };

        CourseSchedule_207 cs207;

        cout << "-> DFS (three-state) version:\n";
        for (size_t i = 0; i < testCases.size(); ++i) {
            bool result = cs207.canFinishDFS(testCases[i].numCourses,
                                             testCases[i].prerequisites);
            cout << "Test " << (i + 1) << ": res = "
                 << (result == testCases[i].expectedResult ? "PASS" : "FAIL") << endl;
        }

        cout << "-> Kahn's algorithm version:\n";
        for (size_t i = 0; i < testCases.size(); ++i) {
            bool result = cs207.canFinishKahns(testCases[i].numCourses,
                                               testCases[i].prerequisites);
            cout << "Test " << (i + 1) << ": res = "
                 << (result == testCases[i].expectedResult ? "PASS" : "FAIL") << endl;
        }
    }

    static void findIfPathExistsInGraph_1971_tests() {
        vector<PathTestCase> testCases = {
            PathTestCase(3, {{0, 1}, {1, 2}, {2, 0}}, 0, 2, true),
            PathTestCase(6, {{0, 1}, {0, 2}, {3, 5}, {5, 4}, {4, 3}}, 0, 5, false),
            PathTestCase(4, {{0, 1}, {1, 2}, {2, 3}}, 0, 3, true),
            PathTestCase(5, {{0, 4}, {4, 3}, {3, 2}, {2, 1}}, 0, 1, true),
            PathTestCase(4, {{0, 1}, {1, 2}}, 0, 3, false),
        };

        FindIfPathExistsInGraph_1971 fp1971;

        cout << "-> Recursive DFS version:\n";
        for (size_t i = 0; i < testCases.size(); ++i) {
            bool result = fp1971.validPathRecursiveDFS(testCases[i].n, testCases[i].edges, testCases[i].source, testCases[i].destination);
            cout << "Test " << (i + 1) << ": res = "
                      << (result == testCases[i].expectedResult ? "PASS" : "FAIL") << endl;
        }

        cout << "-> Iterative DFS version with a stack:\n";
        for (size_t i = 0; i < testCases.size(); ++i) {
            bool result = fp1971.validPathIterativeDFS(testCases[i].n, testCases[i].edges, testCases[i].source, testCases[i].destination);
            cout << "Test " << (i + 1) << ": res = "
                      << (result == testCases[i].expectedResult ? "PASS" : "FAIL") << endl;
        }

        cout << "-> BFS version with a queue:\n";
        for (size_t i = 0; i < testCases.size(); ++i) {
            bool result = fp1971.validPathBFS(testCases[i].n, testCases[i].edges, testCases[i].source, testCases[i].destination);
            cout << "Test " << (i + 1) << ": res = "
                      << (result == testCases[i].expectedResult ? "PASS" : "FAIL") << endl;
        }

        cout << "-> Union-find version:\n";
        for (size_t i = 0; i < testCases.size(); ++i) {
            bool result = fp1971.validPathUnionFind(testCases[i].n, testCases[i].edges, testCases[i].source, testCases[i].destination);
            cout << "Test " << (i + 1) << ": res = "
                      << (result == testCases[i].expectedResult ? "PASS" : "FAIL") << endl;
        }
    }

    static void numIslands_200_tests()
    {
        // Define test cases
        vector<NumIslandsTestCase> testCases = {
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
            cout << "Test " << i + 1 << ": res = " << (result == testCases[i].expectedResult ? "PASS" : "FAIL")
                      << " (Expected: " << testCases[i].expectedResult << ", Got: " << result << ")" << endl;
        }
    }

    static void maxAreaOfIsland_695_tests() {
        vector<MaxAreaTestCase> testCases = {
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
            // make independent copies because each routine mutates the grid
            auto gridRec  = testCases[i].grid;
            auto gridIter = testCases[i].grid;

            int resRec  = mai695.maxAreaOfIslandRecursive(gridRec);
            int resIter = mai695.maxAreaOfIslandIterative(gridIter);

            cout << "Max Area Test " << (i + 1) << " (recursive): "
                << (resRec  == testCases[i].expectedResult ? "PASS" : "FAIL")
                << " (Expected " << testCases[i].expectedResult
                << ", Got " << resRec  << ")\n";

            cout << "Max Area Test " << (i + 1) << " (iterative): "
                << (resIter == testCases[i].expectedResult ? "PASS" : "FAIL")
                << " (Expected " << testCases[i].expectedResult
                << ", Got " << resIter << ")\n";
        }
    }

    static void courseScheduleII_210_tests() {
        vector<CourseScheduleIITestCase> testCases = {
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
            cout << "Network Delay Time Test " << (i + 1) << ": res = "
                      << (result == testCases[i].expectedResult ? "PASS" : "FAIL")
                      << " (Expected: " << testCases[i].expectedResult << ", Got: " << result << ")" << endl;
        }
    }

    static void rottingOranges_994_tests()
    {
        vector<RottingOrangesTestCase> testCases = {
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
            cout << "Rotting Oranges Test " << i + 1 << ": res = "
                      << (result == testCases[i].expectedResult ? "PASS" : "FAIL")
                      << " (Expected: " << testCases[i].expectedResult << ", Got: " << result << ")" << endl;
        }
    }

    static void pacificAtlantic_417_tests()
    {
        vector<PacificAtlanticTestCase> testCases = {
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

            cout << "Test " << (i + 1) << ": res = "
                      << (result == testCases[i].expectedResult ? "PASS" : "FAIL") << endl;
        }
    }

    static void minCostToConnectAllPoints_1584_tests() {
        vector<MinCostToConnectAllPointsTestCase> testCases = {
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
            auto ptsHeap  = testCases[i].points;
            auto ptsArray = testCases[i].points;

            int resHeap  = solution.minCostConnectPointsHeap(testCases[i].points);
            int resArray = solution.minCostConnectPointsArray(testCases[i].points);

            bool passHeap  = (resHeap  == testCases[i].expectedResult);
            bool passArray = (resArray == testCases[i].expectedResult);

            cout << "Min Cost Test " << (i + 1) << ":\n"
                 << "  Heap   : " << (passHeap  ? "PASS" : "FAIL") << " (Expected: "
                 << testCases[i].expectedResult << ", Got: " << resHeap  << ")\n"
                 << "  Array  : " << (passArray ? "PASS" : "FAIL") << " (Expected: "
                 << testCases[i].expectedResult << ", Got: " << resArray << ")\n";
        }
    }

    static void longestCommonSubsequence_tests() {
        vector<LongestCommonSubsequenceTestCase> testCases = {
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
            cout << "LCS Test " << i + 1 << ": res = "
                    << (result == testCases[i].expectedResult ? "PASS" : "FAIL")
                    << " (Expected: " << testCases[i].expectedResult
                    << ", Got: " << result << ")" << endl;
        }
    }

    static void longestIncreasingSubsequence_tests() {
        vector<LongestIncreasingSubsequenceTestCase> testCases = {
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
            cout << "LIS Test " << i + 1 << ": res = "
                    << (result == testCases[i].expectedResult ? "PASS" : "FAIL")
                    << " (Expected: " << testCases[i].expectedResult
                    << ", Got: " << result << ")" << endl;
        }
    }

    static void removeDuplicatesFromSortedList_83_tests() {
        using IntListNode = ListNode<int>;

        // Define test cases
        vector<RemoveDuplicatesTestCase> testCases = {
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
            vector<int> resultVector = ListUtils::toVector<int>(result);

            // Print test results
            cout << "Remove Duplicates Test " << i + 1 << ": res = "
                    << (resultVector == testCases[i].expectedList ? "PASS" : "FAIL")
                    << " (Expected: " << ListUtils::toString<int>(ListUtils::createLinkedList<int>(testCases[i].expectedList))
                    << ", Got: " << ListUtils::toString<int>(result) << ")" << endl;

            // Free the allocated linked list
            ListUtils::freeList<int>(result);
        }
    }

    static void reverseLinkedList_206_tests() {
        using IntListNode = ListNode<int>;

        // Define test cases
        vector<ReverseListTestCase> testCases = {
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
            vector<int> resultVector = ListUtils::toVector<int>(result);

            // Print test results
            cout << "Reverse Linked List Test " << i + 1 << ": res = "
                    << (resultVector == testCases[i].expectedList ? "PASS" : "FAIL")
                    << " (Expected: " << ListUtils::toString<int>(ListUtils::createLinkedList<int>(testCases[i].expectedList))
                    << ", Got: " << ListUtils::toString<int>(result) << ")" << endl;

            // Free the allocated linked list
            ListUtils::freeList<int>(result);
        }
    }

    static void mergeTwoSortedLists_21_tests() {
        using IntListNode = ListNode<int>;

        // Define test cases
        vector<MergeTwoListsTestCase> testCases = {
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
            vector<int> resultVector = ListUtils::toVector<int>(result);

            // Print test results
            cout << "Merge Two Sorted Lists Test " << i + 1 << ": res = "
                    << (resultVector == testCases[i].expectedList ? "PASS" : "FAIL")
                    << " (Expected: " << ListUtils::toString<int>(ListUtils::createLinkedList<int>(testCases[i].expectedList))
                    << ", Got: " << ListUtils::toString<int>(result) << ")" << endl;

            // Free the allocated merged list
            ListUtils::freeList<int>(result);
        }
    }

    static void hasCycle_141_tests() {
        vector<LinkedListCycleTestCase> testCases = {
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
            cout << "Test " << (i + 1) << ": res = "
                      << (result == testCases[i].expectedResult ? "PASS" : "FAIL")
                      << " (Expected: " << testCases[i].expectedResult
                      << ", Got: " << result << ")\n"
                      << "List: " << ListUtils::toString<int>(head) << endl;

            // Free the linked list
            ListUtils::freeList<int>(head);
        }
    }

    static void middleOfLinkedList_876_tests() {
        using IntListNode = ListNode<int>;

        vector<MiddleOfLinkedListTestCase> testCases = {
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
            vector<int> resultVector = ListUtils::toVector<int>(result);

            // Print test results
            cout << "Middle of Linked List Test " << i + 1 << ": res = "
                    << (resultVector == testCases[i].expectedList ? "PASS" : "FAIL")
                    << " (Expected: " << ListUtils::toString<int>(ListUtils::createLinkedList<int>(testCases[i].expectedList))
                    << ", Got: " << ListUtils::toString<int>(result) << ")" << endl;

            // Free the allocated linked list
            ListUtils::freeList<int>(input);
        }
    }

    static void removeNthFromEnd_tests() {
        using IntListNode = ListNode<int>;

        vector<RemoveNthNodeTestCase> testCases = {
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
            vector<int> resultVector = ListUtils::toVector<int>(result);

            // Print test results
            cout << "Remove Nth Node From End Test " << i + 1 << ": res = "
                    << (resultVector == testCases[i].expectedList ? "PASS" : "FAIL")
                    << " (Expected: " << ListUtils::toString<int>(ListUtils::createLinkedList<int>(testCases[i].expectedList))
                    << ", Got: " << ListUtils::toString<int>(result) << ")" << endl;

            // Free the allocated linked list
            ListUtils::freeList<int>(result);
        }
    }

    static void maxProfit_121_tests() {
        vector<MaxProfitTestCase> testCases = {
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
            cout << "Max Profit Test " << i + 1 << ": res = "
                    << (result == testCases[i].expectedResult ? "PASS" : "FAIL")
                    << " (Expected: " << testCases[i].expectedResult << ", Got: " << result << ")" << endl;
        }
    }

    static void spiralMatrix_54_tests() {
        vector<SpiralMatrixTestCase> testCases = {
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
            vector<int> result = sm54.spiralOrder(testCases[i].matrix);
            cout << "Spiral Matrix Test " << (i + 1) << ": res = "
                    << (result == testCases[i].expectedResult ? "PASS" : "FAIL")
                    << " (Expected: ";
            for (int val : testCases[i].expectedResult) cout << val << " ";
            cout << ", Got: ";
            for (int val : result) cout << val << " ";
            cout << ")" << endl;
        }
    }

    static void validateBinarySearchTree_98_tests() {
        vector<ValidateBinarySearchTreeTestCase> testCases = {
            // Provided examples
            ValidateBinarySearchTreeTestCase({2, 1, 3}, true),
            ValidateBinarySearchTreeTestCase({5, 1, 4, nullopt, nullopt, 3, 6}, false),

            // Additional complex test cases
            ValidateBinarySearchTreeTestCase({10, 5, 15, nullopt, nullopt, 6, 20}, false), // Violates BST in right subtree
            ValidateBinarySearchTreeTestCase({3, 1, 5, 0, 2, 4, 6}, true),                          // Valid BST
            ValidateBinarySearchTreeTestCase({1, nullopt, 2, nullopt, 3, nullopt, 4}, true) // Skewed right
        };

        ValidateBinarySearchTree_98 validator;

        for (size_t i = 0; i < testCases.size(); ++i) {
            TreeNode<int>* root = TreeUtils::vectorToTree(testCases[i].tree);

            cout << "Test Case " << (i + 1) << " Tree:" << endl;
            TreeUtils::printTree(root); // Print the tree

            bool result = validator.isValidBST(root);

            cout << "Validate BST Test " << (i + 1) << ": res = "
                    << (result == testCases[i].expectedResult ? "PASS" : "FAIL")
                    << " (Expected: " << (testCases[i].expectedResult ? "true" : "false")
                    << ", Got: " << (result ? "true" : "false") << ")" << endl;

            TreeUtils::freeTree(root); // Free the memory after use
        }
    }

    static void lowestCommonAncestor_235_tests() {
        vector<LowestCommonAncestorTestCase> testCases = {
            // Example 1
            LowestCommonAncestorTestCase({6, 2, 8, 0, 4, 7, 9, nullopt, nullopt, 3, 5}, 2, 8, 6),
            // Example 2
            LowestCommonAncestorTestCase({6, 2, 8, 0, 4, 7, 9, nullopt, nullopt, 3, 5}, 2, 4, 2),
            // Example 3
            LowestCommonAncestorTestCase({2, 1}, 2, 1, 2),
            // Additional Complex Test 1
            LowestCommonAncestorTestCase({10, 5, 15, 3, 8, 12, 20, 1, 4, 7, 9, nullopt, nullopt, 18, 25}, 4, 9, 5),
            // Additional Complex Test 2
            LowestCommonAncestorTestCase({30, 10, 50, 5, 20, 40, 60, nullopt, 8, 15, 25, 35, 45, nullopt, 70}, 15, 45, 30),
        };

        LowestCommonAncestorOfBST_235 lcaSolver;

        for (size_t i = 0; i < testCases.size(); ++i) {
            TreeNode<int>* root = TreeUtils::vectorToTree(testCases[i].tree);
            TreeNode<int>* p = TreeUtils::findNode(root, testCases[i].p);
            TreeNode<int>* q = TreeUtils::findNode(root, testCases[i].q);

            TreeNode<int>* result = lcaSolver.lowestCommonAncestor(root, p, q);

            cout << "LCA Test " << (i + 1) << ": res = "
                    << ((result && result->val == testCases[i].expectedLCA) ? "PASS" : "FAIL")
                    << " (Expected: " << testCases[i].expectedLCA << ", Got: " << (result ? result->val : -1) << ")" << endl;

            TreeUtils::freeTree(root);
        }
    }

    static void copyRandomList_tests() {
        using IntListNode = ListNode<int>;

        vector<CopyRandomListTestCase> testCases = {
            // Provided test cases
            CopyRandomListTestCase({{7, nullopt}, {13, 0}, {11, 4}, {10, 2}, {1, 0}},
                                {{7, nullopt}, {13, 0}, {11, 4}, {10, 2}, {1, 0}}),
            CopyRandomListTestCase({{1, 1}, {2, 1}}, {{1, 1}, {2, 1}}),
            CopyRandomListTestCase({{3, nullopt}, {3, 0}, {3, nullopt}},
                                {{3, nullopt}, {3, 0}, {3, nullopt}}),

            // Additional complex test cases
            CopyRandomListTestCase({{1, nullopt}, {2, 0}, {3, 1}, {4, 3}, {5, 2}},
                                {{1, nullopt}, {2, 0}, {3, 1}, {4, 3}, {5, 2}}),
            CopyRandomListTestCase({{10, 4}, {20, 3}, {30, 2}, {40, 1}, {50, nullopt}},
                                {{10, 4}, {20, 3}, {30, 2}, {40, 1}, {50, nullopt}})
        };

        CopyListWithRandomPointer_138 solution;

        for (size_t i = 0; i < testCases.size(); ++i) {
            IntListNode* input = ListUtils::createLinkedListWithRandom<int>(testCases[i].inputList);
            IntListNode* expected = ListUtils::createLinkedListWithRandom<int>(testCases[i].expectedList);

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
            KthSmallestTestCase({3, 1, 4, nullopt, 2}, 1, 1),
            // Example 2
            KthSmallestTestCase({5, 3, 6, 2, 4, nullopt, nullopt, 1}, 3, 3),
            // Additional Test 1: Larger balanced tree
            KthSmallestTestCase({15, 10, 20, 5, 13, 17, 25, 3, 8, nullopt, 14, 16, 18}, 6, 14),
            // Additional Test 2: Single node tree
            KthSmallestTestCase({42}, 1, 42),
            // Additional Test 3: Skewed tree
            KthSmallestTestCase({1, nullopt, 2, nullopt, 3, nullopt, 4}, 4, 4)
        };

        KthSmallestElementInBST_230 solution;

        for (size_t i = 0; i < testCases.size(); ++i) {
            TreeNode<int>* root = TreeUtils::vectorToTree(testCases[i].tree);

            int result = solution.kthSmallest(root, testCases[i].k);
            cout << "Kth Smallest Element Test " << (i + 1) << ": res = "
                    << (result == testCases[i].expectedResult ? "PASS" : "FAIL")
                    << " (Expected: " << testCases[i].expectedResult << ", Got: " << result << ")" << endl;

            TreeUtils::freeTree(root); // Free tree memory
        }
    }

    static void implementTrie_208_tests() {
        vector<TrieTestCase> testCases = {
            // Example 1
            TrieTestCase(
                {"Trie", "insert", "search", "search", "startsWith", "insert", "search"},
                {nullopt, "apple", "apple", "app", "app", "app", "app"},
                {nullopt, nullopt, true, false, true, nullopt, true}
            ),
            // Example 2: Overlapping words
            TrieTestCase(
                {"Trie", "insert", "insert", "search", "search", "startsWith"},
                {nullopt, "apple", "applause", "apple", "applause", "app"},
                {nullopt, nullopt, nullopt, true, true, true}
            ),
            // Example 3: Single-character operations
            TrieTestCase(
                {"Trie", "insert", "search", "startsWith", "search"},
                {nullopt, "a", "a", "a", "b"},
                {nullopt, nullopt, true, true, false}
            ),
            // Example 4: No matching prefix
            TrieTestCase(
                {"Trie", "insert", "insert", "startsWith", "startsWith", "search"},
                {nullopt, "car", "cart", "ca", "cat", "carrot"},
                {nullopt, nullopt, nullopt, true, false, false}
            ),
            // Example 5: Large input set
            TrieTestCase(
                {"Trie", "insert", "insert", "insert", "search", "search", "startsWith"},
                {nullopt, "dictionary", "dictionaries", "dictator", "dictionary", "dictionaries", "dict"},
                {nullopt, nullopt, nullopt, nullopt, true, true, true}
            )
        };

        for (size_t i = 0; i < testCases.size(); ++i) {
            cout << "Running Trie Test Case " << i + 1 << ":\n";
            Trie* trie = nullptr;

            for (size_t j = 0; j < testCases[i].operations.size(); ++j) {
                const auto& op = testCases[i].operations[j];
                const auto& arg = testCases[i].arguments[j];
                const auto& expected = testCases[i].expectedResults[j];

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

    static void kthLargestElement_215_tests()
    {
        vector<KthLargestElementTestCase> testCases = {
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
            cout << "Kth Largest Element Test " << (i + 1) << ": res = "
                      << (result == testCases[i].expectedResult ? "PASS" : "FAIL")
                      << " (Expected: " << testCases[i].expectedResult << ", Got: " << result << ")" << endl;
        }
    }

    static void minHeap_tests() {
        vector<MinHeapTestCase> testCases = {
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
            bool pass = results == testCases[i].expectedResults;
            cout << "MinHeap Test " << (i + 1) << ": " << (pass ? "PASS" : "FAIL") << "\n";
            if (!pass) {
                cout << "Expected: ";
                for (int r : testCases[i].expectedResults) cout << r << " ";
                cout << "\nGot: ";
                for (int r : results) cout << r << " ";
                cout << "\n";
            }
        }
    }

    static void rotateImage_48_tests() {
        vector<RotateImageTestCase> testCases = {
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

        RotateImage_48 rotator;

        // -------- Transpose-then-Reverse variant --------------------------------
        for (size_t i = 0; i < testCases.size(); ++i) {
            auto input = testCases[i].inputMatrix;      // fresh copy
            rotator.rotateTransposeReverse(input);

            cout << "[Transpose+Reverse] Test " << (i + 1) << ": res = "
                    << (input == testCases[i].expectedMatrix ? "PASS" : "FAIL") << '\n';
            cout << "Expected:\n";
            printMatrix(testCases[i].expectedMatrix);
            cout << "Got:\n";
            printMatrix(input);
        }

        // -------- Layer-by-Layer (“onion”) swap variant -------------------------
        for (size_t i = 0; i < testCases.size(); ++i) {
            auto input = testCases[i].inputMatrix;      // fresh copy
            rotator.rotateLayerSwap(input);

            cout << "[LayerSwap]        Test " << (i + 1) << ": res = "
                    << (input == testCases[i].expectedMatrix ? "PASS" : "FAIL") << '\n';
            cout << "Expected:\n";
            printMatrix(testCases[i].expectedMatrix);
            cout << "Got:\n";
            printMatrix(input);
        }
    }

    static void mergeIntervals_56_tests() {
        vector<MergeIntervalsTestCase> testCases = {
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

            cout << "Merge Intervals Test " << (i + 1) << ": res = "
                    << (result == testCases[i].expectedResult ? "PASS" : "FAIL")
                    << "\nExpected: ";
            for (const auto& interval : testCases[i].expectedResult) {
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
            vector<IntListNode*> inputLists;
            for (const auto& list : testCases[i].inputLists) {
                inputLists.push_back(ListUtils::createLinkedList<int>(list));
            }

            // Run the solution
            IntListNode* result = solution.mergeKLists(inputLists);

            // Convert result to vector
            vector<int> resultVector = ListUtils::toVector<int>(result);

            // Print test results
            cout << "Merge K Lists Test " << i + 1 << ": res = "
                    << (resultVector == testCases[i].expectedList ? "PASS" : "FAIL")
                    << " (Expected: " << ListUtils::toString<int>(ListUtils::createLinkedList<int>(testCases[i].expectedList))
                    << ", Got: " << ListUtils::toString<int>(result) << ")" << endl;

            // Free allocated memory
            ListUtils::freeList<int>(result);
        }
    }

    static void productOfArrayExceptSelf_tests() {
        vector<ProductOfArrayExceptSelfTestCase> testCases = {
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
            cout << "Product of Array Except Self Test " << (i + 1) << ": res = "
                    << (result == testCases[i].expectedResult ? "PASS" : "FAIL")
                    << " (Expected: ";
            for (int val : testCases[i].expectedResult) cout << val << " ";
            cout << ", Got: ";
            for (int val : result) cout << val << " ";
            cout << ")\n";
        }
    }

    static void majorityElement_tests() {
        // Define test cases
        vector<MajorityElementTestCase> testCases = {
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

        cout << "-> Boyer–Moore Majority Vote Algorithm:\n";
        for (size_t i = 0; i < testCases.size(); ++i) {
            MajorityElement_169 solution;
            int result = solution.majorityElement(testCases[i].nums);
            cout << "Test " << (i + 1) << ": ";
            if (result == testCases[i].expectedResult) {
                cout << "PASS\n";
            } else {
                cout << "FAIL (Expected: " << testCases[i].expectedResult
                        << ", Got: " << result << ")\n";
            }
        }

        cout << "-> Frequency Counting with a Hashmap Algorithm:\n";
        for (size_t i = 0; i < testCases.size(); ++i) {
            MajorityElement_169 solution;
            int result = solution.majorityElementWithHashmap(testCases[i].nums);
            cout << "Test " << (i + 1) << ": ";
            if (result == testCases[i].expectedResult) {
                cout << "PASS\n";
            } else {
                cout << "FAIL (Expected: " << testCases[i].expectedResult
                        << ", Got: " << result << ")\n";
            }
        }
    }

    static void evaluateReversePolishNotation_150_tests() {
        vector<EvaluateRPNTestCase> testCases = {
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
            cout << "Evaluate RPN Test " << (i + 1) << ": res = "
                      << (result == testCases[i].expectedResult ? "PASS" : "FAIL")
                      << " (Expected: " << testCases[i].expectedResult << ", Got: " << result << ")\n";
        }
    }

    static void largestRectangleArea_tests() {
        vector<LargestRectangleTestCase> testCases = {
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
            cout << "Test " << (i + 1) << ": res = "
                      << (result == testCases[i].expectedArea ? "PASS" : "FAIL")
                      << " (Expected: " << testCases[i].expectedArea
                      << ", Got: " << result << ")" << endl;
        }
    }

    static void runWordSearchTests() {
        vector<WordSearchTestCase> testCases = {
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
            cout << "Test " << (i + 1) << ": res = "
                    << (result == testCases[i].expectedResult ? "PASS" : "FAIL")
                    << " (Expected: " << (testCases[i].expectedResult ? "true" : "false")
                    << ", Got: " << (result ? "true" : "false") << ")" << endl;
        }
    }

    static void runValidParenthesesTests() {
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
                    << (result == testCases[i].expectedResult ? "PASS" : "FAIL")
                    << " (Expected: " << (testCases[i].expectedResult ? "true" : "false")
                    << ", Got: " << (result ? "true" : "false") << ")" << endl;
        }
    }

    static void validSudoku_36_tests() {
        vector<ValidSudokuTestCase> testCases = {
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
            cout << "Valid Sudoku Test " << (i + 1) << ": res = "
                    << (result == testCases[i].expectedResult ? "PASS" : "FAIL")
                    << " (Expected: " << (testCases[i].expectedResult ? "true" : "false")
                    << ", Got: " << (result ? "true" : "false") << ")" << endl;
        }
    }

    static void binarySearch_704_tests() {
        vector<BinarySearchTestCase> testCases = {
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
            cout << "Binary Search Test " << (i + 1) << ": res = "
                    << (result == testCases[i].expectedResult ? "PASS" : "FAIL")
                    << " (Expected: " << testCases[i].expectedResult
                    << ", Got: " << result << ")" << endl;
        }
    }

    static void searchInsertPosition_35_tests() {
        vector<BinarySearchTestCase> testCases = {
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
            cout << "Search Insert Position Test " << (i + 1) << ": res = "
                    << (result == testCases[i].expectedResult ? "PASS" : "FAIL")
                    << " (Expected: " << testCases[i].expectedResult
                    << ", Got: " << result << ")" << endl;
        }
    }

    static void search2DMatrixTests() {
        vector<Search2DMatrixTestCase> testCases = {
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
            cout << "Test " << (i + 1) << ": res = "
                    << (result == testCases[i].expectedResult ? "PASS" : "FAIL")
                    << " (Expected: " << (testCases[i].expectedResult ? "true" : "false")
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

    static void allOne_432_tests() {
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
            FindMinTestCase({3, 4, 5, 1, 2}, 1),                     // Example 1
            FindMinTestCase({4, 5, 6, 7, 0, 1, 2}, 0),               // Example 2
            FindMinTestCase({11, 13, 15, 17}, 11),                   // Example 3
            FindMinTestCase({5, 6, 7, 8, 9, 1, 2, 3, 4}, 1),         // Additional Test 1
            FindMinTestCase({30, 40, 50, 5, 10, 20}, 5)              // Additional Test 2
        };

        FindMinimumInRotatedSortedArray_153 solution;

        for (size_t i = 0; i < testCases.size(); ++i) {
            int result = solution.findMin(testCases[i].nums);
            cout << "Test " << (i + 1) << ": res = "
                    << (result == testCases[i].expectedResult ? "PASS" : "FAIL")
                    << " (Expected: " << testCases[i].expectedResult << ", Got: " << result << ")" << endl;
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
            ZigzagTestCase("PAYPALISHIRING", 3, "PAHNAPLSIIGYIR"),
            ZigzagTestCase("PAYPALISHIRING", 4, "PINALSIGYAHRPI"),
            ZigzagTestCase("A", 1, "A"),
            ZigzagTestCase("ABCDEFGHIJKLMNOPQRSTUVWXYZ", 5, "AIQYBHJPRXZCGKOSWDFLNTVEMU"),
            ZigzagTestCase("THISISAZIGZAGCONVERSIONTEST", 6, "TZIHGASOIIGRNSZCETIAOVETSNS")
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
            cout << "HIndex_274 Test " << (i + 1) << ": res = "
                      << ((result == testCases[i].expectedResult) ? "PASS" : "FAIL")
                      << " (Expected: " << testCases[i].expectedResult
                      << ", Got: " << result << ")" << endl;
        }
    }

    static void sortColors_75_tests() {
        // Create test cases (two from the problem statement + three more)
        vector<SortColorsTestCase> testCases = {
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

            cout << "RemoveDuplicatesFromSortedArrayII_80 Test " << (i + 1) << ": "
                    << (pass ? "PASS" : "FAIL")
                    << " (Expected k=" << testCases[i].expectedK
                    << ", got k=" << k << ")" << endl;
        }
    }

    static void bestTimeToBuyAndSellStockII_122_tests() {
        vector<BestTimeToBuyAndSellStockII_122_TestCase> testCases = {
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
            cout << "BestTimeToBuyAndSellStockII_122 Test " << (i + 1) << ": "
                    << (pass ? "PASS" : "FAIL")
                    << " (Expected " << testCases[i].expectedProfit
                    << ", got " << result << ")" << endl;
        }
    }

    static void validAnagram_242_tests() {
        vector<ValidAnagramTestCase> testCases = {
            // Examples from the problem statement
            ValidAnagramTestCase("anagram", "nagaram", true),
            ValidAnagramTestCase("rat", "car", false),

            // Additional complex test cases
            ValidAnagramTestCase("abcdefg", "gfedcba", true), // Reverse order, still an anagram
            ValidAnagramTestCase("aabbcc", "abcabc", true),   // Same frequency, different order
            ValidAnagramTestCase(string(50000, 'a') + "b", string(50000, 'a') + "c", false) // Edge case with large input, one character differs
        };

        ValidAnagram_242 solution;

        for (size_t i = 0; i < testCases.size(); ++i) {
            bool result = solution.isAnagram(testCases[i].s, testCases[i].t);
            cout << "Valid Anagram Test " << (i + 1) << ": res = "
                    << (result == testCases[i].expectedResult ? "PASS" : "FAIL")
                    << " (Expected: " << (testCases[i].expectedResult ? "true" : "false")
                    << ", Got: " << (result ? "true" : "false") << ")" << endl;
        }
    }

    static void analyzeUserWebsiteVisitPattern_1152_tests() {
        vector<AnalyzeUserWebsiteVisitPatternTestCase> testCases = {
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
            vector<string> result_map = solver.mostVisitedPattern_usingMap(testCases[i].username, testCases[i].timestamp, testCases[i].website);
            vector<string> result_hashmap = solver.mostVisitedPattern_usingHashmap(testCases[i].username, testCases[i].timestamp, testCases[i].website);

            bool pass_map = (result_map == testCases[i].expectedResult);
            bool pass_hashmap = (result_hashmap == testCases[i].expectedResult);
            bool pass_consistency = (result_map == result_hashmap);

            cout << "AnalyzeUserWebsiteVisitPattern Test " << (i + 1) << ": \n";

            cout << " - Using Map: " << (pass_map ? "PASS" : "FAIL") << " (Expected: ";
            for (const auto& s : testCases[i].expectedResult) cout << s << " ";
            cout << ", Got: ";
            for (const auto& s : result_map) cout << s << " ";
            cout << ")\n";

            cout << " - Using Hashmap: " << (pass_hashmap ? "PASS" : "FAIL") << " (Expected: ";
            for (const auto& s : testCases[i].expectedResult) cout << s << " ";
            cout << ", Got: ";
            for (const auto& s : result_hashmap) cout << s << " ";
            cout << ")\n";

            cout << " - Consistency Check (Map vs Hashmap): " << (pass_consistency ? "PASS" : "FAIL") << "\n\n";
        }
    }

    static void groupAnagrams_49_tests() {
        vector<GroupAnagramsTestCase> testCases = {
            // Example 1
            GroupAnagramsTestCase({"eat", "tea", "tan", "ate", "nat", "bat"},
                                  {{"bat"}, {"tan", "nat"}, {"eat", "tea", "ate"}}),

            // Example 2
            GroupAnagramsTestCase({""}, { {""} }),

            // Example 3
            GroupAnagramsTestCase({"a"}, { {"a"} }),

            // Large test case: Multiple anagram groups with long words
            GroupAnagramsTestCase({"abcdefg", "gfedcba", "xyz", "zxy", "yxz", "longword", "wordlong"},
                                  {{"abcdefg", "gfedcba"}, {"xyz", "zxy", "yxz"}, {"longword", "wordlong"}}),

            // Large test case: Many unique words (no anagrams)
            GroupAnagramsTestCase({"abcd", "efgh", "ijkl", "mnop", "qrst", "uvwx", "yz"},
                                  {{"abcd"}, {"efgh"}, {"ijkl"}, {"mnop"}, {"qrst"}, {"uvwx"}, {"yz"}})
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
            FindCelebrityTestCase({{0, 1}, {0, 0}}, 1),

            // Edge: 1 person only
            FindCelebrityTestCase({{0}}, 0),

            // Edge: 3 people, 2 is celeb
            FindCelebrityTestCase({
                {0, 1, 1},
                {0, 0, 1},
                {0, 0, 0}
            }, 2),

            // 4x4 complex
            FindCelebrityTestCase({
                {0, 1, 1, 1},
                {0, 0, 1, 1},
                {0, 0, 0, 1},
                {0, 0, 0, 0}
            }, 3),

            // 7x7 larger case, celebrity at 6
            FindCelebrityTestCase({
                {0,1,1,1,1,1,1},
                {0,0,1,1,1,1,1},
                {0,0,0,1,1,1,1},
                {0,0,0,0,1,1,1},
                {0,0,0,0,0,1,1},
                {0,0,0,0,0,0,1},
                {0,0,0,0,0,0,0}
            }, 6)
        };

        for (size_t i = 0; i < testCases.size(); ++i) {
            FindCelebrity_277 solver;
            solver.knowsMatrix = testCases[i].matrix;
            int result = solver.findCelebrity((int)testCases[i].matrix.size());

            cout << "FindCelebrity Test " << (i + 1)
                      << ": res = " << (result == testCases[i].expectedResult ? "PASS" : "FAIL")
                      << " (Expected: " << testCases[i].expectedResult << ", Got: " << result << ")" << endl;
        }
    }

    static void longestConsecutiveSequence_128_tests() {
        vector<LongestConsecutiveSequenceTestCase> testCases = {
            // Examples from problem statement
            LongestConsecutiveSequenceTestCase({100,4,200,1,3,2},         4),
            LongestConsecutiveSequenceTestCase({0,3,7,2,5,8,4,6,0,1},     9),
            LongestConsecutiveSequenceTestCase({1,0,1,2},                 3),
            // Additional complex cases
            LongestConsecutiveSequenceTestCase({-1,-2,-3,7,6,5,4,3,2,1},   7),          // 1,2,3,4,5,6,7
            LongestConsecutiveSequenceTestCase({10,5,12,3,55,30,4,11,11,5,13,14,6}, 5)  // 10–14
        };

        LongestConsecutiveSequence_128 solution;
        for (size_t i = 0; i < testCases.size(); ++i) {
            int result = solution.longestConsecutive(testCases[i].nums);
            cout << "Test " << (i+1) << ": res = "
                      << (result == testCases[i].expectedResult ? "PASS" : "FAIL")
                      << " (Expected: " << testCases[i].expectedResult
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
            int result = solution.characterReplacement(testCases[i].s, testCases[i].k);
            cout << "LRCR_424 Test " << (i + 1) << ": res = "
                      << (result == testCases[i].expectedResult ? "PASS" : "FAIL")
                      << " (Expected: " << testCases[i].expectedResult
                      << ", Got: " << result << ")\n";
        }
    }

    static void lRUCache_tests() {
        vector<LRUCacheTestCase> testCases = {
            // From problem statement
            LRUCacheTestCase(
                {"LRUCache","put","put","get","put","get","put","get","get","get"},
                {{2},      {1,1}, {2,2}, {1},  {3,3}, {2},  {4,4}, {1},  {3},   {4}},
                { nullopt, nullopt, nullopt, 1,
                  nullopt, -1,         nullopt, -1,
                   3,            4 }
            ),
            // Additional: overwrite existing key and capacity=1 edge
            LRUCacheTestCase(
                {"LRUCache","put","put","get","put","get","get"},
                {{1},      {1,10},{1,20},{1},  {2,30},{1},  {2}},
                { nullopt, nullopt, nullopt, 20,
                  nullopt,  -1,           30 }
            ),
            // Additional: complex sequence with capacity = 3 and multiple evictions
            LRUCacheTestCase(
                {"LRUCache","put","put","put","get","put","get","get","put","get","get"},
                {{3},      {1,1}, {2,2}, {3,3}, {1},  {4,4}, {2},  {3},  {5,5}, {1},  {4}},
                { nullopt, nullopt, nullopt, nullopt, 1,
                  nullopt, -1,          3,          nullopt, -1,        4}
            ),
        };

        for (size_t i = 0; i < testCases.size(); ++i) {
            cout << "LRUCache Test Case " << (i+1) << ":\n";
            LRUCache* cache = nullptr;
            for (size_t j = 0; j < testCases[i].operations.size(); ++j) {
                const auto& op  = testCases[i].operations[j];
                const auto& arg = testCases[i].arguments[j];
                const auto& exp = testCases[i].expectedResults[j];

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
                      << ": res = " << (res == testCases[i].expectedResult ? "PASS" : "FAIL")
                      << " (Expected: " << testCases[i].expectedResult
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
            auto result = solution.topKFrequent(testCases[i].words, testCases[i].k);
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
            LongestCycleTestCase({3, 3, 4, 2, 3}, 3),   // Example 1
            LongestCycleTestCase({2, -1, 3, 1}, -1),    // Example 2

            // 3 additional, more complex cases
            LongestCycleTestCase({1, 2, 3, 4, 0}, 5),         // single 5-node cycle
            LongestCycleTestCase({1, 0, 4, 2, 3}, 3),         // two cycles, longest = 3
            LongestCycleTestCase({1, 2, 3, 4, 5, 6, 0}, 7)    // single 7-node cycle
        };

        LongestCycleInGraph_2360 solver;

        for (size_t i = 0; i < testCases.size(); ++i) {
            int res = solver.longestCycle(testCases[i].edges);
            cout << "LongestCycleInGraph_2360 Test " << (i + 1) << ": res = "
                      << (res == testCases[i].expectedResult ? "PASS" : "FAIL")
                      << " (Expected: " << testCases[i].expectedResult
                      << ", Got: " << res << ")" << endl;
        }
    }

    static void shortestCycleInGraph_2608_tests() {
        vector<ShortestCycleTestCase> cases = {
            // ── 2 examples from the problem statement ───────────────────────────
            ShortestCycleTestCase(
                7,
                {{0,1},{1,2},{2,0},{3,4},{4,5},{5,6},{6,3}},
                3),
            ShortestCycleTestCase(
                4,
                {{0,1},{0,2}},
                -1),

            // ── extra #1 : tiny corner-case – only one edge, no cycle ───────────
            ShortestCycleTestCase(
                2,
                {{0,1}},
                -1),

            /* ── extra #2 : larger, multiple cycles, shortest = 3 ───────────────
                   triangle 0-1-2-0  (len 3)
                   square   3-4-5-6-3 (len 4)
                   edges 2-3 and 4-7-5 add inter-connections                  */
            ShortestCycleTestCase(
                8,
                {{0,1},{1,2},{2,0},
                 {3,4},{4,5},{5,6},{6,3},
                 {2,3},
                 {4,7},{7,5}},
                3),

            /* ── extra #3 : “outer-loop needed” case (path + remote triangle) ───
               0-1-2-3-4-5-6   long arm
                         ╲
                          7
                         ╱ ╲
                        8 - 6          shortest = 3 (6-7-8-6)
               With BFS from 0 the first detected cycle would be very long,
               so we need one BFS per start vertex to get the true minimum.      */
            ShortestCycleTestCase(
                9,
                {{0,1},{1,2},{2,3},{3,4},{4,5},{5,6},   // path
                 {6,7},{7,8},{8,6}},                    // triangle at the end
                3)
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
            UniquePathsIITestCase({{0,0,0},{0,1,0},{0,0,0}}, 2),
            UniquePathsIITestCase({{0,1},{0,0}}, 1),

            // Additional complex cases
            // 1) Single‐row with an obstacle blocking all paths past it
            UniquePathsIITestCase({{0,1,0,0,0}}, 0),

            // 2) 3×3 with no obstacles: C(4,2)=6
            UniquePathsIITestCase({{0,0,0},{0,0,0},{0,0,0}}, 6),

            // 3) Larger 10×10 grid with no obstacles:
            //    number of paths = C(18,9) = 48620
            UniquePathsIITestCase(
                vector<vector<int>>(10, vector<int>(10, 0)),
                48620
            )
        };

        UniquePathsII_63 solution;
        for (size_t i = 0; i < testCases.size(); ++i) {
            int result = solution.uniquePathsWithObstacles(testCases[i].grid);
            cout << "Unique Paths II Test " << (i+1)
                      << ": " << (result == testCases[i].expectedResult ? "PASS" : "FAIL")
                      << " (Expected: " << testCases[i].expectedResult
                      << ", Got: " << result << ")\n";
        }
    }

    static void maximumAverageSubarrayI_643_tests() {
        vector<MaxAvgTestCase> testCases = {
            // problem examples
            MaxAvgTestCase({1, 12, -5, -6, 50, 3}, 4, 12.75),
            MaxAvgTestCase({5},                    1,  5.0),

            // additional complex tests
            MaxAvgTestCase({1,2,3,4,5,6,7,8,9,10},   5,  8.0),          // increasing sequence
            MaxAvgTestCase({-5,-10,-3,-4,-1,-2},     3, -2.3333333333), // all negatives
            MaxAvgTestCase({0,100,0,100,0,100},      2,  50.0)          // alternating highs/lows
        };

        MaximumAverageSubarrayI_643 solution;
        for (size_t i = 0; i < testCases.size(); ++i) {
            double result = solution.findMaxAverage(testCases[i].nums, testCases[i].k);
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
            MaxConsecutiveOnesTestCase({1,1,1,0,0,0,1,1,1,1,0},           2,  6),
            MaxConsecutiveOnesTestCase({0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1}, 3, 10),

            // three more:
            MaxConsecutiveOnesTestCase({1,0,1,0,1,0,1},                   1,  3),  // alternating
            MaxConsecutiveOnesTestCase({1,1,0,0,1,1,1,0,1},               2,  7),  // mixed blocks
            MaxConsecutiveOnesTestCase({0,0,0,0},                         0,  0)   // all zeros, no flips
        };

        MaxConsecutiveOnesIII_1004 solution;
        for (size_t i = 0; i < testCases.size(); ++i) {
            int result = solution.longestOnes(testCases[i].nums, testCases[i].k);
            cout << "MaxConsecutiveOnesIII_1004 Test " << (i + 1) << ": res = "
                << (result == testCases[i].expectedResult ? "PASS" : "FAIL")
                << " (Expected: " << testCases[i].expectedResult
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
            int res = solution.lengthOfLongestSubstring(testCases[i].s);
            cout << "Longest Substring Test " << (i + 1)
                << ": res = " << (res == testCases[i].expectedResult ? "PASS" : "FAIL")
                << " (Expected: " << testCases[i].expectedResult
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
            int got = solver.minSubArrayLen(testCases[i].target, testCases[i].nums);
            cout << "MinimumSizeSubarraySum_209 Test " << (i + 1) << ": res = "
                << (got == testCases[i].expectedResult ? "PASS" : "FAIL")
                << " (Expected: " << testCases[i].expectedResult
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
                << (result == testCases[i].expectedResult ? "PASS" : "FAIL")
                << " (Expected: " << (testCases[i].expectedResult ? "true" : "false")
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
            auto result = solver.sortedSquares(testCases[i].nums);
            cout << "SquaresOfSortedArray_977 Test " << (i + 1) << ": res = "
                << (result == testCases[i].expectedResult ? "PASS" : "FAIL") << endl;
        }
    }

    static void reverseString_344_tests() {
        // build a large case up-front so it can be placed inside the uniform-init list
        vector<char> longIn;
        for (int i = 0; i < 10000; ++i) longIn.push_back('a' + (i % 26));
        vector<char> longOut(longIn.rbegin(), longIn.rend());

        vector<ReverseStringTestCase> testCases = {
            // two examples from the problem statement
            ReverseStringTestCase({'h','e','l','l','o'},            {'o','l','l','e','h'}),
            ReverseStringTestCase({'H','a','n','n','a','h'},        {'h','a','n','n','a','H'}),

            // three additional cases
            ReverseStringTestCase({'a'},                            {'a'}),                       // length-1
            ReverseStringTestCase({'a','b','c','c','b','a'},        {'a','b','c','c','b','a'}),   // palindrome
            ReverseStringTestCase(move(longIn),                     move(longOut))                // 10 000 chars
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
            TwoSumIITestCase({2,7,11,15},                  9,  {1,2}),
            TwoSumIITestCase({2,3,4},                      6,  {1,3}),
            TwoSumIITestCase({-1,0},                      -1,  {1,2}),

            // two additional cases
            TwoSumIITestCase({1,3,4,7,11,15},             15,  {3,5}),          // mid-array pair
            TwoSumIITestCase(move(longNums),               0,  move(longAns))   // 2001-element stress
        };

        TwoSumII_167 solver;
        for (size_t i = 0; i < testCases.size(); ++i) {
            auto nums = testCases[i].numbers;  // work on a copy
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
            ValidPalindromeTestCase("A man, a plan, a canal: Panama", true),
            ValidPalindromeTestCase("race a car",                     false),

            // third example from the statement
            ValidPalindromeTestCase(" ",                              true),

            // two additional cases
            ValidPalindromeTestCase("0P",                             false), // mixed digit/letter
            ValidPalindromeTestCase(move(longStr),                    true)   // long palindrome
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
            ThreeSumTestCase({-1,0,1,2,-1,-4},            {{-1,-1,2},{-1,0,1}}),
            ThreeSumTestCase({0,1,1},                     {}),

            // third statement example
            ThreeSumTestCase({0,0,0},                     {{0,0,0}}),

            // two additional cases
            ThreeSumTestCase({-2,0,1,1,2},                {{-2,0,2},{-2,1,1}}),
            ThreeSumTestCase({-2,-2,1,3,1,2,0,0},         {{-2,0,2},{-2,1,1}})
        };

        ThreeSum_15 solver;
        for (size_t i = 0; i < testCases.size(); ++i) {
            auto res = solver.threeSum(testCases[i].nums);

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
            ContainerWithMostWaterTestCase({1,8,6,2,5,4,8,3,7}, 49),
            ContainerWithMostWaterTestCase({1,1},                1),

            // three additional cases
            ContainerWithMostWaterTestCase({4,3,2,1,4},          16), // equal ends
            ContainerWithMostWaterTestCase({1,2,1},              2),  // small valley
            ContainerWithMostWaterTestCase({2,3,10,5,7,8,9},     36)  // tall inner peak
        };

        ContainerWithMostWater_11 solver;
        for (size_t i = 0; i < testCases.size(); ++i) {
            int res = solver.maxArea(testCases[i].heights);
            cout << "ContainerWithMostWater_11 Test " << (i + 1) << ": res = "
                << (res == testCases[i].expected ? "PASS" : "FAIL") << endl;
        }
    }

    static void trappingRainWater_42_tests() {
        vector<TrappingRainWaterTestCase> testCases = {
            // two examples from the statement
            TrappingRainWaterTestCase({0,1,0,2,1,0,1,3,2,1,2,1}, 6),
            TrappingRainWaterTestCase({4,2,0,3,2,5},             9),

            // three additional cases
            TrappingRainWaterTestCase({0,0,0},                   0),  // flat
            TrappingRainWaterTestCase({1,2,3,4,5},               0),  // monotonic
            TrappingRainWaterTestCase({5,4,1,2},                 1),  // small basin
            TrappingRainWaterTestCase({4,0,0,0,4},               12)
        };

        TrappingRainWater_42 solver;
        for (size_t i = 0; i < testCases.size(); ++i) {
            int res = solver.trap(testCases[i].heights);
            cout << "TrappingRainWater_42 Test " << (i + 1) << ": res = "
                << (res == testCases[i].expected ? "PASS" : "FAIL") << endl;
        }
    }

    static void maximalRectangle_85_tests() {
        vector<MaximalRectangleTestCase> testCases = {
            // ── three examples from the problem statement ──
            MaximalRectangleTestCase({{'1','0','1','0','0'},
                                    {'1','0','1','1','1'},
                                    {'1','1','1','1','1'},
                                    {'1','0','0','1','0'}}, 6),
            MaximalRectangleTestCase({{'0'}}, 0),
            MaximalRectangleTestCase({{'1'}}, 1),

            // ── additional, larger & denser cases ──
            // 1) 8×8 block of 1 s → area 64
            MaximalRectangleTestCase(vector<vector<char>>(8, vector<char>(8, '1')), 64),

            // 2) 4×10 mixed grid (largest 5×4 block) → area 20
            MaximalRectangleTestCase({{'1','1','1','1','1','0','0','0','1','1'},
                                    {'1','1','1','1','1','1','1','1','1','0'},
                                    {'1','1','1','1','1','1','1','1','0','0'},
                                    {'1','1','1','1','1','0','0','0','0','0'}}, 20)
        };

        MaximalRectangle_85 solver;
        for (size_t i = 0; i < testCases.size(); ++i) {
            int result = solver.maximalRectangle(testCases[i].matrix);
            cout << "Maximal Rectangle Test " << (i + 1) << ": res = "
                << (result == testCases[i].expectedArea ? "PASS" : "FAIL")
                << " (Expected: " << testCases[i].expectedArea
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
            int got = solver.maxSubArray(tc[i].nums);
            cout << "MaximumSubarray_53 Test " << (i + 1) << ": "
                    << (got == tc[i].expected ? "PASS" : "FAIL")
                    << " (expected " << tc[i].expected << ", got " << got << ")\n";
        }
    }

    static void twoSum_1_tests() {
        vector<TwoSumCase> cases = {
            TwoSumCase({2, 7, 11, 15},               9,  {0, 1}),
            TwoSumCase({3, 2, 4},                    6,  {1, 2}),
            TwoSumCase({3, 3},                       6,  {0, 1}),
            // Added tougher / edge scenarios
            TwoSumCase({-10, -1, 0, 1, 2, 8},       -9,  {0, 3}),           // negative + positive mix
            TwoSumCase({1000000000, -1000000000, 3, 4, 8}, 12,  {3, 4})     // 4 + 8
        };

        TwoSum_1 solver;
        for (size_t i = 0; i < cases.size(); ++i) {
            auto res = solver.twoSum(cases[i].nums, cases[i].target);

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
            MergeCase({1,2,3,0,0,0}, 3, {2,5,6}, 3, {1,2,2,3,5,6}),
            MergeCase({1},           1, {},       0, {1}),
            MergeCase({0},           0, {1},      1, {1}),
            MergeCase({2,0},         1, {1},      1, {1,2}),               // reversed order input
            MergeCase({-3,-1,0,0,0}, 2, {-2,-2,4},3, {-3,-2,-2,-1,4})      // negatives & duplicates
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
            RemCase({3,2,2,3},           3, 2, {2,2}),           // example 1
            RemCase({0,1,2,2,3,0,4,2},   2, 5, {0,0,1,3,4}),     // example 2
            RemCase({},                  0, 0, {}),              // empty array
            RemCase({1,1,1},             2, 3, {1,1,1}),         // value absent
            RemCase({4,4,4},             4, 0, {})               // all removed
        };

        RemoveElement_27 remover;
        for (size_t i = 0; i < cases.size(); ++i) {
            auto nums = cases[i].nums;                    // copy to mutate
            int  k    = remover.removeElement(nums, cases[i].val);

            // prepare comparables (order-independent)
            vector<int> got(nums.begin(), nums.begin() + k);
            sort(got.begin(), got.end());
            auto exp = cases[i].expectedElems;
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
            int res = solver.maxNumberOfBalloons(cases[i].text);

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
            int res = solver.pivotIndex(cases[i].nums);

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
            {"baaaacxyz",     "*a*?xyz",     true }
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

    static void kClosestPoints_973_tests() {
        vector<KClosestTestCase> cases = {
            // Two official examples
            KClosestTestCase({{1,3}, {-2,2}}, 1, {{-2,2}}),
            KClosestTestCase({{3,3}, {5,-1}, {-2,4}}, 2, {{3,3}, {-2,4}}),

            // Three extra, trickier cases
            // 1) Many symmetrically placed points, ask for almost all
            KClosestTestCase({{0,1}, {1,0}, {-1,0}, {0,-1}}, 3,
                            {{0,1}, {1,0}, {-1,0}}),
            // 2) Points at extreme coordinates
            KClosestTestCase({{10000,10000}, {-10000,-10000}, {5000,0}, {0,5000}}, 2,
                            {{5000,0}, {0,5000}}),
            // 3) Mixed positives and negatives, k near n
            KClosestTestCase({{2,2}, {1,1}, {3,3}, {-2,-2}, {-1,-1}}, 4,
                            {{-2,-2}, {-1,-1}, {1,1}, {2,2}})
        };

        KClosestPointsToOrigin_973 solver;
        for (size_t i = 0; i < cases.size(); ++i) {
            /* test QuickSelect version */
            auto in1  = cases[i].points;
            auto out1 = solver.kClosestQuickSelect(in1, cases[i].k);
            bool pass1 = isValidKClosest(cases[i].points, cases[i].k, out1);

            /* test Heap version */
            auto in2  = cases[i].points;
            auto out2 = solver.kClosestHeap(in2, cases[i].k);
            bool pass2 = isValidKClosest(cases[i].points, cases[i].k, out2);

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
            BusRoutesTestCase({{1,2,7},{3,6,7}}, 1, 6, 2),
            BusRoutesTestCase({{7,12},{4,5,15},{6},{15,19},{9,12,13}}, 15, 12, -1),
            // Additional tougher cases
            BusRoutesTestCase({{1,2,3,4,5},{5,6,7,8},{8,9,10,11},{11,12,13,1}}, 1, 13, 1),
            BusRoutesTestCase({{1,2,3},{4,5,6}}, 5, 5, 0),
            BusRoutesTestCase({{1,2,3},{3,4,5},{5,6,7},{7,8,9}}, 2, 8, 4)
        };

        BusRoutes_815 solver;
        for (size_t i = 0; i < cases.size(); ++i) {
            auto routesCopy = cases[i].routes;  // Guard against mutation
            int res = solver.numBusesToDestination(routesCopy, cases[i].source, cases[i].target);
            cout << "BusRoutes_815 Test " << (i + 1) << ": "
                << (res == cases[i].expectedResult ? "PASS" : "FAIL")
                << " (Expected: " << cases[i].expectedResult << ", Got: " << res << ")\n";
        }
    }

    static void shortestPathBinaryMatrix_1091_tests() {
        vector<ShortestPathTestCase> testCases = {
            /* 3 examples from the problem statement */
            ShortestPathTestCase({{0, 1},
                                {1, 0}},                                   2),
            ShortestPathTestCase({{0, 0, 0},
                                {1, 1, 0},
                                {1, 1, 0}},                                4),
            ShortestPathTestCase({{1, 0, 0},
                                {1, 1, 0},
                                {1, 1, 0}},                               -1),
            /* 2 extra, larger cases */
            ShortestPathTestCase({{0, 0, 0, 0, 0},
                                {1, 1, 1, 1, 0},
                                {0, 0, 0, 1, 0},
                                {0, 1, 0, 1, 0},
                                {0, 1, 0, 0, 0}},                          8),   // reachable
            ShortestPathTestCase({{0, 1, 1, 1, 1},
                                {1, 1, 1, 1, 1},
                                {1, 1, 1, 1, 1},
                                {1, 1, 1, 1, 1},
                                {1, 1, 1, 1, 0}},                         -1)    // unreachable
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
            GraphTC(
                {"Graph","shortestPath","shortestPath","addEdge","shortestPath"},
                {
                    pair<int,EdgeList>{4, {{0,2,5},{0,1,2},{1,2,1},{3,0,3}}},
                    pair<int,int>{3,2},
                    pair<int,int>{0,3},
                    vector<int>{1,3,4},
                    pair<int,int>{0,3}
                },
                {nullopt, 6, -1, nullopt, 6}
            ),
            // Case 2 – empty graph, then one edge
            GraphTC(
                {"Graph","shortestPath","addEdge","shortestPath"},
                {
                    pair<int,EdgeList>{2, {}},
                    pair<int,int>{0,1},
                    vector<int>{0,1,10},
                    pair<int,int>{0,1}
                },
                {nullopt, -1, nullopt, 10}
            ),
            // Case 3 – cheaper path appears after addEdge
            GraphTC(
                {"Graph","shortestPath","addEdge","shortestPath"},
                {
                    pair<int,EdgeList>{5, {{0,1,3},{1,2,4},{2,3,5},{3,4,6},{0,4,20}}},
                    pair<int,int>{0,4},
                    vector<int>{1,4,1},
                    pair<int,int>{0,4}
                },
                {nullopt, 18, nullopt, 4}
            )
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

    static void findSafestPathInGrid_2812_tests() {
        vector<SafestPathTestCase> testCases = {
            // three examples from the statement
            SafestPathTestCase({{1,0,0},
                                {0,0,0},
                                {0,0,1}}, 0),
            SafestPathTestCase({{0,0,1},
                                {0,0,0},
                                {0,0,0}}, 2),
            SafestPathTestCase({{0,0,0,1},
                                {0,0,0,0},
                                {0,0,0,0},
                                {1,0,0,0}}, 2),

            // extra – single thief in the centre of a 5×5 grid (answer = 2)
            SafestPathTestCase({{0,0,0,0,0},
                                {0,0,0,0,0},
                                {0,0,1,0,0},
                                {0,0,0,0,0},
                                {0,0,0,0,0}}, 2),

            // extra – two thieves forcing a bottleneck of 1
            SafestPathTestCase({{0,0,1},
                                {0,0,0},
                                {1,0,0}}, 1)
        };

        FindSafestPathInGrid_2812 solver;

        for (size_t i = 0; i < testCases.size(); ++i) {
            int res = solver.maximumSafenessFactor(testCases[i].grid);
            cout << "Safest Path Test " << (i + 1) << ": res = "
                << (res == testCases[i].expectedResult ? "PASS" : "FAIL")
                << " (Expected: " << testCases[i].expectedResult
                << ", Got: " << res << ")\n";
        }
    }

    static void maximumDepthOfBinaryTree_104_tests() {
        vector<MaxDepthTestCase> testCases = {
            // two examples from the problem statement
            MaxDepthTestCase({3, 9, 20, nullopt, nullopt, 15, 7}, 3),
            MaxDepthTestCase({1, nullopt, 2},                     2),

            // three extra, increasingly tricky, cases
            // (a) irregular but shallow left/right mix – depth 4
            MaxDepthTestCase({1, 2, 3, 4, nullopt, nullopt, 5, nullopt, 6}, 4),
            // (b) strongly left-skewed – depth 5
            MaxDepthTestCase({1, 2, nullopt, 3, nullopt, 4, nullopt, 5}, 5),
            // (c) empty tree – depth 0
            MaxDepthTestCase({}, 0)
        };

        MaximumDepthOfBinaryTree_104 solver;

        for (size_t i = 0; i < testCases.size(); ++i) {
            TreeNode<int>* root = TreeUtils::vectorToTree<int>(testCases[i].tree);

            int dRec  = solver.maxDepthRecursive(root);
            int dStk  = solver.maxDepthDFSStack(root);
            int dBfs  = solver.maxDepthBFSQueue(root);

            bool pass = (dRec == testCases[i].expectedDepth &&
                        dStk == testCases[i].expectedDepth &&
                        dBfs == testCases[i].expectedDepth);

            cout << "MaxDepth Test " << (i + 1) << ": "
                << (pass ? "PASS" : "FAIL")
                << " (Expected " << testCases[i].expectedDepth
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
            WallsAndGatesTestCase(
                {{INF, -1, 0,   INF},
                {INF, INF, INF, -1},
                {INF, -1,  INF, -1},
                {0,   -1,  INF, INF}},
                {{3, -1, 0, 1},
                {2, 2, 1, -1},
                {1, -1, 2, -1},
                {0, -1, 3, 4}}
            ),
            // Example 2
            WallsAndGatesTestCase(
                {{0, INF}},
                {{0, 1}}
            ),
            // Example 3
            WallsAndGatesTestCase(
                {{INF}},
                {{INF}}
            ),
            // Complex 1: 4×4 grid, two gates
            WallsAndGatesTestCase(
                {{0,   INF, INF, INF},
                {INF, -1,  INF, INF},
                {INF, INF, INF, 0  },
                {INF, -1,  INF, INF}},
                {{0, 1, 2, 2},
                {1, -1, 2, 1},
                {2, 2, 1, 0},
                {3, -1, 2, 1}}
            ),
            // Complex 2: unreachable rooms stay INF
            WallsAndGatesTestCase(
                {{INF, -1, 0,   INF, INF},
                {-1,  INF, -1, INF, -1 },
                {INF, -1,  INF, -1, INF}},
                {{INF, -1, 0, 1, 2},
                {-1,  INF, -1, 2, -1},
                {INF, -1,  INF, -1, INF}}
            )
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
            bool result = solver.isNumber(testCases[i].s);
            cout << "ValidNumber_65 Test " << (i + 1) << ": res = "
                << (result == testCases[i].expectedResult ? "PASS" : "FAIL")
                << " (input: \"" << testCases[i].s << "\")" << endl;
        }
    }

    static void numJewelsAndStones_771_tests() {
        vector<JewelsAndStonesTestCase> testCases = {
            // Problem-statement examples
            JewelsAndStonesTestCase("aA", "aAAbbbb", 3),
            JewelsAndStonesTestCase("z",  "ZZ",      0),

            // Extra, more demanding cases
            JewelsAndStonesTestCase("abc", "aabbccABCabc",                    9),
            JewelsAndStonesTestCase("abcdefghijklmnopqrstuvwxyz",
                                    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJ",  26),
            JewelsAndStonesTestCase("Aa",  "aaaaaaaaAAAAAAAaA",              17)
        };

        JewelsAndStones_771 solver;

        for (size_t i = 0; i < testCases.size(); ++i) {
            int result = solver.numJewelsInStones(testCases[i].jewels,
                                                testCases[i].stones);

            cout << "Jewels & Stones Test " << (i + 1) << ": res = "
                << (result == testCases[i].expectedResult ? "PASS" : "FAIL")
                << " (Expected: " << testCases[i].expectedResult
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
            bool res = solver.isPerfectSquare(cases[i].num);
            cout << "ValidPerfectSquare_367 Test " << (i + 1) << ": res = "
                << (res == cases[i].expected ? "PASS" : "FAIL")
                << " (Expected: " << (cases[i].expected ? "true" : "false")
                << ", Got: "      << (res ? "true" : "false") << ")\n";
        }
    }

    static void runAllTests() {
        cout << "Running CourseSchedule_207 tests:\n";
        courseSchedule_207_tests();
        cout << "Running FindIfPathExistsInGraph_1971 tests:\n";
        findIfPathExistsInGraph_1971_tests();
        cout << "Running NumberOfIslands_200 tests:\n";
        numIslands_200_tests();
        cout << "Running MaxAreaOfIsland_695 tests:\n";
        maxAreaOfIsland_695_tests();
        cout << "Running CourseScheduleII_210 tests:\n";
        courseScheduleII_210_tests();
        cout << "Running NetworkDelayTime_743 tests:\n";
        networkDelayTime_743_tests();
        cout << "Running RottingOranges_994 tests:\n";
        rottingOranges_994_tests();
        cout << "Running PacificAtlanticWaterFlow_417 tests:\n";
        pacificAtlantic_417_tests();
        cout << "Running MinCostToConnectAllPoints_1584 tests:\n";
        minCostToConnectAllPoints_1584_tests();
        cout << "Running LongestCommonSubsequence tests:\n";
        longestCommonSubsequence_tests();
        cout << "Running LongestIncreasingSubsequence_300 tests:\n";
        longestIncreasingSubsequence_tests();
        cout << "Running RemoveDuplicatesFromSortedList_83 tests:\n";
        removeDuplicatesFromSortedList_83_tests();
        cout << "Running ReverseLinkedListLeetcode_206 tests:\n";
        reverseLinkedList_206_tests();
        cout << "Running MergeTwoSortedLists_21 tests:\n";
        mergeTwoSortedLists_21_tests();
        cout << "Running LinkedListCycle_141 tests:\n";
        hasCycle_141_tests();
        cout << "Running MiddleOfLinkedList_876 tests:\n";
        middleOfLinkedList_876_tests();
        cout << "Running RemoveNthFromEnd tests:\n";
        removeNthFromEnd_tests();
        cout << "Running MaxProfit_121 tests:\n";
        maxProfit_121_tests();
        cout << "Running SpiralMatrix_54 tests:\n";
        spiralMatrix_54_tests();
        cout << "Running ValidateBinarySearchTree_98 tests:\n";
        validateBinarySearchTree_98_tests();
        cout << "Running LowestCommonAncestor_235 tests:\n";
        lowestCommonAncestor_235_tests();
        cout << "Running CopyListWithRandomPointer_138 tests:\n";
        copyRandomList_tests();
        cout << "Running KthSmallestElementInBST_230 tests:\n";
        kthSmallestElementInBST_230_tests();
        cout << "Running ImplementTrie_208 tests:\n";
        implementTrie_208_tests();
        cout << "Running KthLargestElementInArray_215 tests:\n";
        kthLargestElement_215_tests();
        cout << "Running MinHeap tests:\n";
        minHeap_tests();
        cout << "Running RotateImage_48 tests:\n";
        rotateImage_48_tests();
        cout << "Running MergeIntervals_56 tests:\n";
        mergeIntervals_56_tests();
        cout << "Running MergeKSortedLists_23 tests:\n";
        mergeKLists_tests();
        cout << "Running ProductOfArrayExceptSelf_238 tests:\n";
        productOfArrayExceptSelf_tests();
        cout << "Running MajorityElement_169 tests:\n";
        majorityElement_tests();
        cout << "Running Evaluate Reverse Polish Notation_150 tests:\n";
        evaluateReversePolishNotation_150_tests();
        cout << "Running LargestRectangleInHistogram_84 tests:\n";
        largestRectangleArea_tests();
        cout << "Running WordSearch_79 tests:\n";
        runWordSearchTests();
        cout << "Running ValidParentheses_20 tests:\n";
        runValidParenthesesTests();
        cout << "Running ValidSudoku_36 tests:\n";
        validSudoku_36_tests();
        cout << "Running BinarySearch_704 tests:\n";
        binarySearch_704_tests();
        cout << "Running Search Insert Position_35 tests:\n";
        searchInsertPosition_35_tests();
        cout << "Running Search 2D Matrix_74 tests:\n";
        search2DMatrixTests();
        cout << "Running All O One Data Structure_432) tests:\n";
        allOne_432_tests();
        cout << "Running Find Minimum in Rotated Sorted Array_153 tests:\n";
        findMinimumInRotatedSortedArray_153_tests();
        cout << "Clone Graph_133 tests:\n";
        cloneGraph_133_tests();
        cout << "Zigzag Conversion_6 tests:\n";
        zigzagConversion_6_tests();
        cout << "H-Index_274 tests:\n";
        hIndex_274_tests();
        cout << "Sort Colors_75 tests:\n";
        sortColors_75_tests();
        cout << "Remove Duplicates From Sorted Array II_80 tests:\n";
        removeDuplicatesFromSortedArrayII_80_tests();
        cout << "Best Time To Buy And Sell Stock II_122 tests:\n";
        bestTimeToBuyAndSellStockII_122_tests();
        cout << "Valid Annagram_242 tests:\n";
        validAnagram_242_tests();
        cout << "Analyze User Website Visit Pattern_1152 tests:\n";
        analyzeUserWebsiteVisitPattern_1152_tests();
        cout << "Group Anagrams_49 tests:\n";
        groupAnagrams_49_tests();
        cout << "Find the Celebrity_277 tests:\n";
        findCelebrity_277_tests();
        cout << "Running LongestConsecutiveSequence_128 tests:\n";
        longestConsecutiveSequence_128_tests();
        cout << "Running FizzBuzz_412 tests:\n";
        fizzBuzz_412_tests();
        cout << "Running Longest Repeating Character Replacement_424 tests:\n";
        longestRepeatingCharacterReplacement_424_tests();
        cout << "Running LRUCache_146 tests:\n";
        lRUCache_tests();
        cout << "Running SortCharactersByFrequency_451 tests:\n";
        sortCharactersByFrequency_451_tests();
        cout << "Running Coin Change_322 tests:\n";
        TestsRunner::coinChange_322_tests();
        cout << "Running TopKFrequentWords_692 tests:\n";
        TestsRunner::topKFrequentWords_692_tests();
        cout << "Running LongestCycleInGraph_2360 tests:\n";
        longestCycleInGraph_2360_tests();
        cout << "2608. Shortest Cycle in a Graph tests:\n";
        shortestCycleInGraph_2608_tests();
        cout << "Running Unique Paths II_63 tests:\n";
        uniquePathsII_63_tests();
        cout << "Running Maximum Average Subarray I_643 tests:\n";
        maximumAverageSubarrayI_643_tests();
        cout << "Running Max Consecutive Ones III_1004 tests:\n";
        maxConsecutiveOnesIII_1004_tests();
        cout << "Running Longest Substring Without Repeating Characters_3 tests:\n";
        longestSubstringWithoutRepeatingCharacters_3_tests();
        cout << "Running MinimumSizeSubarraySum_209 tests:\n";
        minimumSizeSubarraySum_209_tests();
        cout << "Running PermutationInString_567 tests:\n";
        permutationInString_567_tests();
        cout << "Running SquaresOfSortedArray_977 tests:\n";
        squaresOfSortedArray_977_tests();
        cout << "Running ReverseString_344 tests:\n";
        reverseString_344_tests();
        cout << "Running TwoSumII_167 tests:\n";
        twoSumII_167_tests();
        cout << "Running ValidPalindrome_125 tests:\n";
        validPalindrome_125_tests();
        cout << "Running ThreeSum_15 tests:\n";
        threeSum_15_tests();
        cout << "Running ContainerWithMostWater_11 tests:\n";
        containerWithMostWater_11_tests();
        cout << "Running TrappingRainWater_42 tests:\n";
        trappingRainWater_42_tests();
        cout << "Running MaximalRectangle_85 tests:\n";
        maximalRectangle_85_tests();
        cout << "Running MaximumSubarray_53 tests:\n";
        maximumSubarray_53_tests();
        cout << "Running TwoSum_1 tests:\n";
        twoSum_1_tests();
        cout << "Running MergeSortedArray_88 tests:\n";
        mergeSortedArray_88_tests();
        cout << "Running RemoveElement_27 tests:\n";
        removeElement_27_tests();
        cout << "Running MaximumNumberOfBalloons_1189 tests:\n";
        maximumNumberOfBalloons_1189_tests();
        cout << "Running AddBinary_67 tests:\n";
        addBinary_67_tests();
        cout << "Find Pivot Index_724 tests:\n";
        findPivotIndex_724_tests();
        cout << "Number of 1 Bits_191 tests:\n";
        numberOf1Bits_191_tests();
        cout << "Running DecodeString_GoogleOnsite tests:\n";
        decodeString_GoogleOnsite_tests();
        cout << "Running WildcardMatching_44 tests:\n";
        wildcardMatching_44_tests();
        cout << "Running K Closest Points_973 tests:\n";
        kClosestPoints_973_tests();
        cout << "Running Unique Paths_62 tests:\n";
        uniquePaths_62_tests();
        cout << "Running BusRoutes_815 tests:\n";
        busRoutes_815_tests();
        cout << "Running ShortestPathBinaryMatrix_1091 tests:\n";
        shortestPathBinaryMatrix_1091_tests();
        cout << "Running DesignGraphWithShortestPathCalculator_2642 tests:\n";
        designGraphWithShortestPathCalculator_2642_tests();
        cout << "Running Find Safest Path In Grid_2812 tests:\n";
        findSafestPathInGrid_2812_tests();
        cout << "Running Maximum Depth Of Binary Tree_104 tests:\n";
        maximumDepthOfBinaryTree_104_tests();
        cout << "Running Walls and Gates_286 tests:\n";
        wallsAndGates_286_tests();
        cout << "Running Valid Number_65 tests:\n";
        validNumber_65_tests();
        cout << "Running Jewels and Stones_771 ests:\n";
        numJewelsAndStones_771_tests();
        cout << "Running Valid Perfect Square_367 tests:\n";
        validPerfectSquare_367_tests();
    }
};

int main() {
    cout << "Running LeetCodeCpp tests:\n";
    TestsRunner::runAllTests();
    return 0;
}
