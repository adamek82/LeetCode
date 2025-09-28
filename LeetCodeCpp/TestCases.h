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
        bool  expected;
    };

    // 1971. Find if Path Exists in Graph
    struct PathTestCase {
        int   n;
        Edges edges;
        int   source;
        int   destination;
        bool  expected;
    };

    // 200. Number of Islands
    struct NumIslandsTestCase {
        GridChar grid;
        int      expected;
    };

    // 695. Max Area of Island
    struct MaxAreaTestCase {
        GridInt grid;
        int     expected;
    };

    // 210. Course Schedule II
    struct CourseScheduleIITestCase {
        int        numCourses;
        Edges      prerequisites;
        vector<int> expectedOrder;  // empty means "cycle → no valid order"
    };

    // 743. Network Delay Time
    struct NetworkDelayTimeTestCase {
        vector<vector<int>> times;
        int n;
        int k;
        int expected;
    };

    // 994. Rotting Oranges
    struct RottingOrangesTestCase {
        GridInt grid;
        int     expected;
    };

    // 417. Pacific Atlantic Water Flow
    struct PacificAtlanticTestCase {
        GridInt heights; // heights matrix
        Coords  expected; // list of [r,c] coordinates (order-insensitive)
    };

    // 1584. Min Cost to Connect All Points
    struct MinCostToConnectAllPointsTestCase {
        Points points;
        int    expected;
    };

    // Longest Common Subsequence
    struct LongestCommonSubsequenceTestCase {
        string text1;
        string text2;
        int         expected;
    };

    // 300. Longest Increasing Subsequence
    struct LongestIncreasingSubsequenceTestCase {
        List nums;
        int  expected;
    };

    // 83. Remove Duplicates from Sorted List (LL)
    struct RemoveDuplicatesTestCase {
        List input;
        List expected;
    };

    // 206. Reverse Linked List
    struct ReverseListTestCase {
        List input;
        List expected;
    };

    // 21. Merge Two Sorted Lists
    struct MergeTwoListsTestCase {
        List list1;
        List list2;
        List expected;
    };

    // 141. Linked List Cycle
    struct LinkedListCycleTestCase {
        List input;
        int  pos;
        bool expected;
    };

    // 876. Middle of the Linked List
    struct MiddleOfLinkedListTestCase {
        vector<int> input;
        vector<int> expected;
    };

    // 19. Remove Nth Node From End of List
    struct RemoveNthNodeTestCase {
        vector<int> input;
        int n;
        vector<int> expected;
    };

    // 121. Best Time to Buy and Sell Stock
    struct MaxProfitTestCase {
        vector<int> prices;
        int expected;
    };

    // 54. Spiral Matrix
    struct SpiralMatrixTestCase {
        vector<vector<int>> matrix;
        vector<int> expected;
    };

    // 98. Validate Binary Search Tree
    struct ValidateBinarySearchTreeTestCase {
        vector<optional<int>> tree; // level-order input
        bool expected;
    };

    // 235. Lowest Common Ancestor of a BST
    struct LowestCommonAncestorTestCase {
        vector<optional<int>> tree; // level-order input
        int p;
        int q;
        int expected;
    };

    // 138. Copy List with Random Pointer
    struct CopyRandomListTestCase {
        vector<pair<int, optional<int>>> input;    // {val, randomIndex or nullopt}
        vector<pair<int, optional<int>>> expected;
    };

    // 230. Kth Smallest Element in a BST
    struct KthSmallestTestCase {
        vector<optional<int>> tree; // BST as vector
        int k;
        int expected;
    };

    // 208. Implement Trie (Prefix Tree)
    struct TrieTestCase {
        vector<string> operations;
        vector<optional<string>> arguments;
        vector<optional<bool>> expected;
    };

    // 215. Kth Largest Element in an Array
    struct KthLargestElementTestCase {
        vector<int> nums;
        int k;
        int expected;
    };

    // Min Heap (custom)
    struct MinHeapTestCase {
        vector<pair<string, int>> operations; // {op, value(if any)}
        vector<int> expected;
    };

    // 48. Rotate Image
    struct RotateImageTestCase {
        vector<vector<int>> input;
        vector<vector<int>> expected;
    };

    // 56. Merge Intervals
    struct MergeIntervalsTestCase {
        vector<vector<int>> input;
        vector<vector<int>> expected;
    };

    // 23. Merge k Sorted Lists
    struct MergeKListsTestCase {
        vector<vector<int>> input;
        vector<int> expected;

    };

    // 238. Product of Array Except Self
    struct ProductOfArrayExceptSelfTestCase {
        vector<int> input;
        vector<int> expected;
    };

    // 169. Majority Element
    struct MajorityElementTestCase {
        vector<int> input;
        int expected;
    };

    // 150. Evaluate Reverse Polish Notation
    struct EvaluateRPNTestCase {
        vector<string> input;
        int expected;
    };

    // 84. Largest Rectangle in Histogram
    struct LargestRectangleTestCase {
        vector<int> input;
        int expected;
    };

    // 79. Word Search
    struct WordSearchTestCase {
        vector<vector<char>> board;
        string word;
        bool expected;
    };

    // 20. Valid Parentheses
    struct ValidParenthesesTestCase {
        string input;
        bool expected;
    };

    // 36. Valid Sudoku
    struct ValidSudokuTestCase {
        vector<vector<char>> board;
        bool expected;
    };

    // 704. Binary Search
    struct BinarySearchTestCase {
        vector<int> input;
        int target;
        int expected;
    };

    // 74. Search a 2D Matrix
    struct Search2DMatrixTestCase {
        vector<vector<int>> matrix;
        int target;
        bool expected;
    };

    // 153. Find Minimum in Rotated Sorted Array
    struct FindMinTestCase {
        vector<int> input;
        int expected;
    };

    // 6. Zigzag Conversion
    struct ZigzagTestCase {
        string input;
        int numRows;
        string expected;
    };

    // 274. H-Index
    struct HIndexTestCase {
        vector<int> input;
        int expected;
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
    };

    // 122. Best Time to Buy and Sell Stock II
    struct BestTimeToBuyAndSellStockII_122_TestCase {
        vector<int> prices;
        int expected;
    };

    // 242. Valid Anagram
    struct ValidAnagramTestCase {
        string s;
        string t;
        bool expected;
    };

    // 692. Top K Frequent Words
    struct TopKFrequentWordsTestCase {
        vector<string> input;
        int k;
        vector<string> expected;
    };

    // 1152. Analyze User Website Visit Pattern
    struct AnalyzeUserWebsiteVisitPatternTestCase {
        vector<string> username;
        vector<int> timestamp;
        vector<string> website;
        vector<string> expected;
    };

    // 49. Group Anagrams
    struct GroupAnagramsTestCase {
        vector<string> input;
        vector<vector<string>> expected;
    };

    // 277. Find the Celebrity
    struct FindCelebrityTestCase {
        vector<vector<int>> matrix;
        int expected;
    };

    // 128. Longest Consecutive Sequence
    struct LongestConsecutiveSequenceTestCase {
        vector<int> input;
        int expected;
    };

    // 424. Longest Repeating Character Replacement
    struct LongestRepeatingCharReplacementTestCase {
        string input;
        int k;
        int expected;
    };

    // 146. LRU Cache
    struct LRUCacheTestCase {
        vector<string> operations;
        vector<vector<int>> arguments;
        vector<optional<int>> expected;
    };

    // 322. Coin Change
    struct CoinChangeTestCase {
        vector<int> coins;
        int amount;
        int expected;
    };

    // 2360. Longest Cycle in a Graph
    struct LongestCycleTestCase {
        vector<int> edges;
        int expected;
    };

    // 2608. Shortest Cycle in a Graph
    struct ShortestCycleTestCase {
        int n;
        vector<vector<int>> edges;
        int expected;
    };

    // 63. Unique Paths II
    struct UniquePathsIITestCase {
        vector<vector<int>> input;
        int expected;
    };

    // 855. Exam Room
    struct ExamRoomTestCase {
        vector<string> operations;
        vector<vector<int>> arguments;       // each op's int args
        vector<optional<int>> expected;      // nullopt for void ops
    };

    // 643. Maximum Average Subarray I
    struct MaxAvgTestCase {
        vector<int> input;
        int k;
        double expected;
    };

    // 1004. Max Consecutive Ones III
    struct MaxConsecutiveOnesTestCase {
        vector<int> input;
        int k;
        int expected;
    };

    // 3. Longest Substring Without Repeating Characters
    struct LongestSubstringWithoutRepeatingCharactersTestCase {
        string input;
        int expected;
    };

    // 209. Minimum Size Subarray Sum
    struct MinimumSizeSubarraySumTestCase {
        int target;
        vector<int> input;
        int expected;
    };

    // 567. Permutation in String
    struct PermutationInStringTestCase {
        string s1;
        string s2;
        bool expected;
    };

    // 977. Squares of a Sorted Array
    struct SquaresOfSortedArrayTestCase {
        vector<int> input;
        vector<int> expected;
    };

    // 344. Reverse String
    struct ReverseStringTestCase {
        vector<char> input;
        vector<char> expected;
    };

    // 167. Two Sum II – Input Array Is Sorted
    struct TwoSumIITestCase {
        vector<int> input;   // sorted
        int target;
        vector<int> expected; // 1-indexed result
    };

    // 125. Valid Palindrome
    struct ValidPalindromeTestCase {
        string input;
        bool expected;
    };

    // 15. 3Sum
    struct ThreeSumTestCase {
        vector<int> input;
        vector<vector<int>> expected;
    };

    // 11. Container With Most Water
    struct ContainerWithMostWaterTestCase {
        vector<int> input;
        int expected;
    };

    // 42. Trapping Rain Water
    struct TrappingRainWaterTestCase {
        vector<int> input;
        int expected;
    };

    // 85. Maximal Rectangle
    struct MaximalRectangleTestCase {
        vector<vector<char>> matrix;
        int expected;
    };

    // 53. Maximum Subarray
    struct MaximumSubarrayTestCase {
        vector<int> input;
        int expected;
    };

    // 1. Two Sum
    struct TwoSumCase {
        vector<int> input;
        int target;
        vector<int> expected; // indices (any order)
    };

    // 88. Merge Sorted Array
    struct MergeCase {
        vector<int> nums1;
        int m;
        vector<int> nums2;
        int n;
        vector<int> expected;
    };

    // 27. Remove Element
    struct RemCase {
        vector<int> input;
        int val;
        int expectedK;
        vector<int> expected; // order-agnostic
    };

    // 1189. Maximum Number of Balloons
    struct BalloonCase {
        string input;
        int expected;
    };

    // 1768. Merge Strings Alternately
    struct ABCase {
        string a;
        string b;
        string expected;
    };

    // 724. Find Pivot Index
    struct PivotCase {
        vector<int> input;
        int expected;
    };

    // 191. Number of 1 Bits
    struct HWCase {
        uint32_t n;
        int expected;
    };

    // 394. Decode String
    struct DecodeStringTestCase {
        string input;
        string expected;
    };

    // 44. Wildcard Matching
    struct WildcardMatchingTestCase {
        string s;
        string p;
        bool expected;
    };

    // 973. K Closest Points to Origin
    struct KClosestTestCase {
        vector<vector<int>> points;
        int k;
        vector<vector<int>> expected; // order-agnostic
    };

    // 62. Unique Paths
    struct UniquePaths62TestCase {
        int m;
        int n;
        int expected;
    };

    // 815. Bus Routes
    struct BusRoutesTestCase {
        vector<vector<int>> routes;
        int source;
        int target;
        int expected;
    };

    // 1091. Shortest Path in Binary Matrix
    struct ShortestPathTestCase {
        vector<vector<int>> grid;
        int expected;
    };

    // 2642. Design Graph With Shortest Path Calculator
    struct GraphTC {
        vector<string> operations;
        vector<variant<
            monostate,
            int,
            vector<int>,
            pair<int,int>,
            pair<int,vector<vector<int>>>>>
            arguments;
        vector<optional<int>> expected;
    };

    // 2812. Find Safest Path in Grid
    struct SafestPathTestCase {
        vector<vector<int>> grid;
        int expected;
    };

    // 104. Maximum Depth of Binary Tree
    struct MaxDepthTestCase {
        vector<optional<int>> tree; // level-order
        int expected;
    };

    // 286. Walls and Gates
    struct WallsAndGatesTestCase {
        vector<vector<int>> rooms;
        vector<vector<int>> expected;
    };

    // 65. Valid Number
    struct ValidNumberTestCase {
        string input;
        bool expected;
    };

    // 771. Jewels and Stones
    struct JewelsAndStonesTestCase {
        string jewels;
        string stones;
        int expected;
    };

    // 367. Valid Perfect Square
    struct PerfectSquareTestCase {
        int input;
        bool expected;
    };

    // 279. Perfect Squares
    struct PerfectSquares279TestCase {
        int input;
        int expected;
    };

    // 100. Same Tree
    struct SameTreeTestCase {
        vector<optional<int>> p;
        vector<optional<int>> q;
        bool expected;
    };

    // 268. Missing Number
    struct MissingNumberTestCase {
        vector<int> input;
        int expected;
    };

    // 739. Daily Temperatures
    struct DailyTemperatures739TestCase {
        vector<int> input;
        vector<int> expected;
    };

    // 217. Contains Duplicate
    struct ContainsDuplicate217TestCase {
        vector<int> input;
        bool expected;
    };

    // 509. Fibonacci Number
    struct Fibonacci509TestCase {
        int n;
        int expected;
    };

    // 70. Climbing Stairs
    struct ClimbingStairs70TestCase {
        int n;
        int expected;
    };

    // 746. Min Cost Climbing Stairs
    struct MinCostClimbingStairs746TestCase {
        vector<int> cost;
        int expected;
    };

    // 198. House Robber
    struct HouseRobber198TestCase {
        vector<int> input;
        int expected;
    };

    // 1046. Last Stone Weight
    struct LastStoneWeight1046TestCase {
        vector<int> input;
        int expected;
    };

    // 347. Top K Frequent Elements
    struct TopKFrequent347TestCase {
        vector<int> input;
        int k;
        vector<int> expected; // order-agnostic
    };

    // 2239. Find Closest Number to Zero
    struct FindClosest2239TestCase {
        vector<int> input;
        int expected;
    };

    // 1768. Merge Strings Alternately
    struct MergeStringsAlternately1768TestCase {
        string a;
        string b;
        string expected;
    };

    // 13. Roman to Integer
    struct RomanToInteger13TestCase {
        string input;
        int expected;
    };

    // 392. Is Subsequence
    struct IsSubsequence392TestCase {
        string s;
        string t;
        bool expected;
    };

    // 392. Is Subsequence (follow-up with next-position table)
    struct IsSubsequence392FollowUpCase {
        string t;
        vector<pair<string, bool>> queries;
    };

    // 14. Longest Common Prefix
    struct LongestCommonPrefix14TestCase {
        vector<string> strs;
        string expected;
    };

    // 228. Summary Ranges
    struct SummaryRanges228TestCase {
        vector<int> nums;
        vector<string> expected;
    };

    // 26. Remove Duplicates from Sorted Array
    struct RemoveDuplicates26TestCase {
        vector<int> nums;
        vector<int> expected; // expected first k unique values
    };

    // 45. Jump Game II
    struct JumpGameII45TestCase {
        vector<int> nums;
        int expected;
    };

    // 55. Jump Game
    struct JumpGame55TestCase {
        vector<int> nums;
        bool expected;
    };

    // 78. Subsets
    struct Subsets78TestCase {
        vector<int> nums;
        vector<vector<int>> expected; // mask-order to match implementation
    };

    // 46. Permutations
    struct Permutations46TestCase {
        vector<int> nums;
        vector<vector<int>> expected; // order-insensitive
    };

    // 77. Combinations
    struct Combinations77TestCase {
        int n;
        int k;
        vector<vector<int>> expected; // order-insensitive
    };

    // 17. Letter Combinations of a Phone Number
    struct LetterCombinations17TestCase {
        string digits;
        vector<string> expected; // order-insensitive
    };

    // 39. Combination Sum
    struct CombinationSum39TestCase {
        vector<int> candidates;
        int target;
        vector<vector<int>> expected; // order-insensitive
    };

    // 22. Generate Parentheses
    struct GenerateParentheses22TestCase {
        int n;
        vector<string> expected; // order-insensitive
    };

    // 209. Game of Life
    struct GameOfLifeTestCase {
        vector<vector<int>> input;
        vector<vector<int>> expected;
    };
} // namespace TestCases
