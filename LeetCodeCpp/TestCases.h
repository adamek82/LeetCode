#pragma once
#include <vector>
#include <string>
#include <utility>  // for move

using namespace std;

namespace TestCases {

    /* ===========================================================
     * Shared aliases
     * =========================================================== */

    using Edges    = vector<vector<int>>;
    using GridChar = vector<vector<char>>;
    using GridInt  = vector<vector<int>>;
    using Points   = vector<vector<int>>;      // e.g., [[x,y], ...]
    using Coords   = vector<vector<int>>;      // e.g., [[r,c], ...]
    using List     = vector<int>;

    /* ===========================================================
     * Arrays & Strings
     * =========================================================== */

    /* Simple iteration, counting, and basic array/string traversal */

     // 412. Fizz Buzz
    struct FizzBuzzTestCase {
        int n;
        vector<string> expected;
    };

    // 2798. Number of Employees Who Met the Target
    struct NumberOfEmployeesWhoMetTargetTestCase {
        vector<int> hours;
        int target;
        int expected;
    };

    // 2239. Find Closest Number to Zero
    struct FindClosestNumberToZeroTestCase {
        vector<int> nums;
        int expected;
    };

    /* Sequence comparison, prefix checks, and simple string parsing */

    // 392. Is Subsequence
    struct IsSubsequence392TestCase {
        string s;
        string t;
        bool expected;
    };

    // 14. Longest Common Prefix
    struct LongestCommonPrefixTestCase {
        vector<string> strs;
        string expected;
    };

    // 228. Summary Ranges
    struct SummaryRangesTestCase {
        vector<int> nums;
        vector<string> expected;
    };

    // 13. Roman to Integer
    struct RomanToIntegerTestCase {
        string input;
        int expected;
    };

    /* In-place array updates and two-pointer style compaction/merge */

    // 26. Remove Duplicates from Sorted Array
    struct RemoveDuplicates26TestCase {
        vector<int> nums;
        vector<int> expected; // expected first k unique values
    };

    // 27. Remove Element
    struct RemoveElementTestCase {
        vector<int> nums;
        int val;
        int expectedK;
        vector<int> expected; // order-agnostic
    };

    // 88. Merge Sorted Array
    struct MergeSortedArrayTestCase {
        vector<int> nums1;
        int m;
        vector<int> nums2;
        int n;
        vector<int> expected;
    };

    // 80. Remove Duplicates from Sorted Array II
    struct RemoveDuplicatesFromSortedArrayIITestCase {
        vector<int> input;
        int expectedK;
        vector<int> expected;
    };

    /* Greedy scans, prefix thinking, and simple counting ideas */

    // 121. Best Time to Buy and Sell Stock
    struct BestTimeToBuyAndSellStockTestCase {
        vector<int> prices;
        int expected;
    };

    // 122. Best Time to Buy and Sell Stock II
    struct BestTimeToBuyAndSellStockIITestCase {
        vector<int> prices;
        int expected;
    };

    // 724. Find Pivot Index
    struct FindPivotIndexTestCase {
        vector<int> input;
        int expected;
    };

    // 3074. Apple Redistribution into Boxes
    struct AppleRedistributionIntoBoxesTestCase {
        vector<int> apple;
        vector<int> capacity;
        int expected;
    };

    // 3046. Split the Array
    struct SplitTheArrayTestCase {
        vector<int> nums;
        bool expected;
    };

    /* Core array techniques: construction, partitioning, and prefix products */

    // 118. Pascal's Triangle
    struct PascalsTriangleTestCase {
        int numRows;
        vector<vector<int>> expected;
    };

    // 75. Sort Colors
    struct SortColorsTestCase {
        vector<int> input;
        vector<int> expected;

        SortColorsTestCase(vector<int> in, vector<int> exp)
            : input(move(in)), expected(move(exp)) {}
    };

    // 238. Product of Array Except Self
    struct ProductOfArrayExceptSelfTestCase {
        vector<int> input;
        vector<int> expected;
    };

    // 274. H-Index
    struct HIndexTestCase {
        vector<int> input;
        int expected;
    };

    /* More advanced transformations on intervals, strings, and matrices */

    // 56. Merge Intervals
    struct MergeIntervalsTestCase {
        vector<vector<int>> input;
        vector<vector<int>> expected;
    };

    // 6. Zigzag Conversion
    struct ZigzagConversionTestCase {
        string input;
        int numRows;
        string expected;
    };

    /* 2D matrix traversal and in-place matrix transformation */

    // 48. Rotate Image
    struct RotateImageTestCase {
        vector<vector<int>> input;
        vector<vector<int>> expected;
    };

    // 54. Spiral Matrix
    struct SpiralMatrixTestCase {
        vector<vector<int>> matrix;
        vector<int> expected;
    };

    /* Preprocessing optimization for repeated subsequence queries */

    // 392. Is Subsequence (follow-up with next-position table)
    struct IsSubsequenceFollowUpTestCase {
        string t;
        vector<pair<string, bool>> queries;
    };

    /* ===========================================================
     * Hashmaps & Sets
     * =========================================================== */

    /* Basic membership checks with sets and simple lookups */

    // 771. Jewels and Stones
    struct JewelsAndStonesTestCase {
        string jewels;
        string stones;
        int expected;
    };

    // 217. Contains Duplicate
    struct ContainsDuplicateTestCase {
        vector<int> nums;
        bool expected;
    };

    // 383. Ransom Note
    struct RansomNoteTestCase {
        string ransomNote;
        string magazine;
        bool expected;
    };

    // 242. Valid Anagram
    struct ValidAnagramTestCase {
        string s;
        string t;
        bool expected;
    };

    // 1189. Maximum Number of Balloons
    struct MaximumNumberOfBalloonsTestCase {
        string text;
        int expected;
    };

    // 1207. Unique Number of Occurrences
    struct UniqueNumberOfOccurrencesTestCase {
        vector<int> arr;
        bool expected;
    };

    // 169. Majority Element
    struct MajorityElementTestCase {
        vector<int> nums;
        int expected;
    };

    /* Hashmap lookup patterns for complements and associations */

    // 1. Two Sum
    struct TwoSumTestCase {
        vector<int> nums;
        int target;
        vector<int> expected; // indices (any order)
    };

    /* Grouping values by a shared hashable signature */

    // 49. Group Anagrams
    struct GroupAnagramsTestCase {
        vector<string> input;
        vector<vector<string>> expected;
    };

    /* Using sets/maps to validate constraints and deduplicate states */

    // 36. Valid Sudoku
    struct ValidSudokuTestCase {
        vector<vector<char>> board;
        bool expected;
    };

    /* More advanced set/map usage for ordering and sequence reasoning */

    // 128. Longest Consecutive Sequence
    struct LongestConsecutiveSequenceTestCase {
        vector<int> nums;
        int expected;
    };

    /* Frequency buckets and top-k style counting problems */

    // 451. Sort Characters by Frequency
    struct SortCharactersByFrequencyTestCase {
        string input;
    };

    // 692. Top K Frequent Words
    struct TopKFrequentWordsTestCase {
        vector<string> words;
        int k;
        vector<string> expected;
    };

    /* Aggregation and pattern counting over grouped event data */

    // 1152. Analyze User Website Visit Pattern
    struct AnalyzeUserWebsiteVisitPatternTestCase {
        vector<string> username;
        vector<int> timestamp;
        vector<string> website;
        vector<string> expected;
    };

    /* Hash-based data structure design */

    // 706. Design HashMap
    struct DesignHashMapTestCase {
        vector<string> operations;
        vector<vector<int>> arguments;   // op args: [] / [key] / [key,value]
        vector<optional<int>> expected;  // nullopt for void ops, value for get()
    };

    /* ===========================================================
     * 2 Pointers
     * =========================================================== */

    /* Opposite-end pointers for simple in-place processing */

    // 344. Reverse String
    struct ReverseStringTestCase {
        vector<char> input;
        vector<char> expected;
    };

    // 125. Valid Palindrome
    struct ValidPalindromeTestCase {
        string input;
        bool expected;
    };

    /* Two-pointer scans on sorted arrays */

    // 977. Squares of a Sorted Array
    struct SquaresOfASortedArrayTestCase {
        vector<int> nums;
        vector<int> expected;
    };

    // 167. Two Sum II – Input Array Is Sorted
    struct TwoSumIIInputArrayIsSortedTestCase {
        vector<int> numbers;   // sorted
        int target;
        vector<int> expected;  // 1-indexed result
    };

    // 1099. Two Sum Less Than K
    struct TwoSumLessThanKTestCase {
        vector<int> nums;
        int k;
        int expected;
    };

    /* Two-pointer optimization after sorting */

    // 15. 3Sum
    struct ThreeSumTestCase {
        vector<int> nums;
        vector<vector<int>> expected;
    };

    // 16. 3Sum Closest
    struct ThreeSumClosestTestCase {
        vector<int> nums;
        int target;
        int expected;
    };

    // 18. 4Sum
    struct FourSumTestCase {
        vector<int> nums;
        int target;
        vector<vector<int>> expected;
    };

    /* Shrinking-window reasoning with left/right boundaries */

    // 11. Container With Most Water
    struct ContainerWithMostWaterTestCase {
        vector<int> height;
        int expected;
    };

    // 42. Trapping Rain Water
    struct TrappingRainWaterTestCase {
        vector<int> height;
        int expected;
    };

    /* ===========================================================
     * Stacks
     * =========================================================== */

    /* Basic stack simulation for push/pop-style processing */

    // 682. Baseball Game
    struct BaseballGameTestCase {
        vector<string> operations;
        int expected;
    };

    // 20. Valid Parentheses
    struct ValidParenthesesTestCase {
        string input;
        bool expected;
    };

    // 150. Evaluate Reverse Polish Notation
    struct EvaluateReversePolishNotationTestCase {
        vector<string> input;
        int expected;
    };

    /* Stack-based parsing and nested expression decoding */

    // 394. Decode String
    struct DecodeStringTestCase {
        string input;
        string expected;
    };

    /* Monotonic stack patterns for next greater / smaller reasoning */

    // 739. Daily Temperatures
    struct DailyTemperaturesTestCase {
        vector<int> temperatures;
        vector<int> expected;
    };

    // 84. Largest Rectangle in Histogram
    struct LargestRectangleInHistogramTestCase {
        vector<int> heights;
        int expected;
    };

    /* Stack-backed data structure design */

    // 155. Min Stack
    struct MinStackTestCase {
        // operations that produce outputs in order: only "top" and "getMin"
        vector<pair<string, int>> operations; // {op, arg}; arg ignored for ops without arg
        vector<int> expected;
    };

    /* Matrix reduction to a histogram-based stack problem */

    // 85. Maximal Rectangle
    struct MaximalRectangleTestCase {
        vector<vector<char>> matrix;
        int expected;
    };

    /* ===========================================================
     * Linked Lists
     * =========================================================== */

    /* Basic traversal and local pointer updates in linked lists */

    // 83. Remove Duplicates from Sorted List (LL)
    struct RemoveDuplicatesFromSortedListTestCase {
        List input;
        List expected;
    };

    // 2807. Insert Greatest Common Divisors in Linked List
    struct InsertGreatestCommonDivisorsTestCase {
        List input;
        List expected;
    };

    /* Fast/slow pointer techniques on linked lists */

    // 141. Linked List Cycle
    struct LinkedListCycleTestCase {
        List value;
        int  pos;
        bool expected;
    };

    // 876. Middle of the Linked List
    struct MiddleOfTheLinkedListTestCase {
        vector<int> values;
        vector<int> expected;
    };

    // 19. Remove Nth Node From End of List
    struct RemoveNthNodeFromEndOfListTestCase {
        vector<int> values;
        int n;
        vector<int> expected;
    };

    /* More advanced linked structures with extra references */

    // 138. Copy List with Random Pointer
    struct CopyRandomListTestCase {
        vector<pair<int, optional<int>>> nodes;    // {val, randomIndex or nullopt}
        vector<pair<int, optional<int>>> expected;
    };

    /* Linked-list-based data structure design */

    // 146. LRU Cache
    struct LRUCacheTestCase {
        vector<string> operations;
        vector<vector<int>> arguments;      // [] / [key,value] / [key]
        vector<optional<int>> expected;     // nullopt for put(), value for get()
    };

    /* ===========================================================
     * Binary Search
     * =========================================================== */

    /* Basic binary search on sorted arrays and monotonic positions */

    // 704. Binary Search
    struct BinarySearchTestCase {
        vector<int> nums;
        int target;
        int expected;
    };

    // 35. Search Insert Position
    // Reuses BinarySearchTestCase: same input/target/result shape.

    // 278. First Bad Version
    struct FirstBadVersionTestCase {
        int n;          // total number of versions
        int firstBad;   // ground truth "first bad" version
        int expected;   // expected result from firstBadVersion(n)
    };

    /* Binary search over a numeric answer space */

    // 367. Valid Perfect Square
    struct ValidPerfectSquareTestCase {
        int num;
        bool expected;
    };

    // 875. Koko Eating Bananas
    struct KokoEatingBananasTestCase {
        vector<int> piles;
        int h;
        int expected;
    };

    /* Binary search on matrix and rotated-array structure */

    // 74. Search a 2D Matrix
    struct Search2DMatrixTestCase {
        vector<vector<int>> matrix;
        int target;
        bool expected;
    };

    // 153. Find Minimum in Rotated Sorted Array
    struct FindMinimumInRotatedSortedArrayTestCase {
        vector<int> nums;
        int expected;
    };

    // 33. Search in Rotated Sorted Array
    // Reuses BinarySearchTestCase: same nums/target/result shape.

    /* ===========================================================
     * Graphs and traversal
     * =========================================================== */

    // 1971. Find if Path Exists in Graph
    struct FindIfPathExistsInGraphTestCase {
        int   n;
        Edges edges;
        int   source;
        int   destination;
        bool  expected;
    };

    // 200. Number of Islands
    struct NumberOfIslandsTestCase {
        GridChar grid;
        int      expected;
    };

    // 695. Max Area of Island
    struct MaxAreaOfIslandTestCase {
        GridInt grid;
        int     expected;
    };

    // 994. Rotting Oranges
    struct RottingOrangesTestCase {
        GridInt grid;
        int     expected;
    };

    // 1091. Shortest Path in Binary Matrix
    struct ShortestPathInBinaryMatrixTestCase {
        vector<vector<int>> grid;
        int expected;
    };

    // 815. Bus Routes
    struct BusRoutesTestCase {
        vector<vector<int>> routes;
        int source;
        int target;
        int expected;
    };

    // 773. Sliding Puzzle
    struct SlidingPuzzleTestCase {
        vector<vector<int>> board;
        int expected;
    };

    // 207. Course Schedule
    struct CourseScheduleTestCase {
        int   numCourses;
        Edges prerequisites;
        bool  expected;
    };

    // 210. Course Schedule II
    struct CourseScheduleIITestCase {
        int        numCourses;
        Edges      prerequisites;
        vector<int> expectedOrder;  // empty => cycle / no valid order
    };

    // 417. Pacific Atlantic Water Flow
    struct PacificAtlanticTestCase {
        GridInt heights; // heights matrix
        Coords  expected; // list of [r,c] coordinates (order-insensitive)
    };

    // 329. Longest Increasing Path in a Matrix
    struct LongestIncreasingPathInMatrixTestCase {
        GridInt matrix;
        int expected;
    };

    // 743. Network Delay Time
    struct NetworkDelayTimeTestCase {
        vector<vector<int>> times;
        int n;
        int k;
        int expected;
    };

    // 2642. Design Graph With Shortest Path Calculator
    struct DesignGraphWithShortestPathCalculatorTestCase {
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

    // 1584. Min Cost to Connect All Points
    struct MinCostToConnectAllPointsTestCase {
        Points points;
        int    expected;
    };

    // 2360. Longest Cycle in a Graph
    struct LongestCycleInGraphTestCase {
        vector<int> edges;
        int expected;
    };

    // 2608. Shortest Cycle in a Graph
    struct ShortestCycleInGraphTestCase {
        int n;
        vector<vector<int>> edges;
        int expected;
    };

    // 289. Game of Life
    struct GameOfLifeTestCase {
        vector<vector<int>> input;
        vector<vector<int>> expected;
    };

    // 286. Walls and Gates
    struct WallsAndGatesTestCase {
        vector<vector<int>> rooms;
        vector<vector<int>> expected;
    };

    // 463. Island Perimeter
    struct IslandPerimeterTestCase {
        GridInt grid;
        int expected;
    };
//

    // Longest Common Subsequence
    struct LongestCommonSubsequenceTestCase {
        string text1;
        string text2;
        int expected;
    };

    // 300. Longest Increasing Subsequence
    struct LongestIncreasingSubsequenceTestCase {
        List nums;
        int  expected;
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

    // 23. Merge k Sorted Lists
    struct MergeKListsTestCase {
        vector<vector<int>> input;
        vector<int> expected;

    };

    // 79. Word Search
    struct WordSearchTestCase {
        vector<vector<char>> board;
        string word;
        bool expected;
    };

    // 277. Find the Celebrity
    struct FindCelebrityTestCase {
        vector<vector<int>> matrix;
        int expected;
    };

    // 424. Longest Repeating Character Replacement
    struct LongestRepeatingCharReplacementTestCase {
        string input;
        int k;
        int expected;
    };

    // 322. Coin Change
    struct CoinChangeTestCase {
        vector<int> coins;
        int amount;
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

    // 53. Maximum Subarray
    struct MaximumSubarrayTestCase {
        vector<int> input;
        int expected;
    };

    // 1768. Merge Strings Alternately
    struct MergeStringsAlternatelyTestCase {
        string word1;
        string word2;
        string expected;
    };

    // 191. Number of 1 Bits
    struct HWCase {
        uint32_t n;
        int expected;
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

    // 65. Valid Number
    struct ValidNumberTestCase {
        string input;
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

    // 1768. Merge Strings Alternately
    struct MergeStringsAlternately1768TestCase {
        string a;
        string b;
        string expected;
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

    // 226. Invert Binary Tree
    struct InvertBinaryTreeTestCase {
        vector<optional<int>> input;    // level-order representation of the original tree
        vector<optional<int>> expected; // level-order representation of the inverted tree
    };

    // 110. Balanced Binary Tree
    struct BalancedBinaryTreeTestCase {
        vector<optional<int>> tree;     // level-order input
        bool expected;
    };

    // 543. Diameter of Binary Tree
    struct DiameterOfBinaryTreeTestCase {
        vector<optional<int>> tree;     // level-order input
        int expected;                   // diameter in edges
    };

    // 101. Symmetric Tree
    struct SymmetricTreeTestCase {
        vector<optional<int>> tree;     // level-order input
        bool expected;
    };

    // 112. Path Sum
    struct PathSumTestCase {
        vector<optional<int>> tree;     // level-order input
        int target;
        bool expected;
    };

    // 572. Subtree of Another Tree
    struct SubtreeOfAnotherTreeTestCase {
        vector<optional<int>> root;     // level-order representation of main tree
        vector<optional<int>> subRoot;  // level-order representation of subtree
        bool expected;
    };

    // 102. Binary Tree Level Order Traversal
    struct BinaryTreeLevelOrderTraversalTestCase {
        vector<optional<int>> tree;     // level-order input
        vector<vector<int>> expected;   // values per level, left-to-right
    };

    // 637. Average of Levels in Binary Tree
    struct AverageOfLevelsInBinaryTreeTestCase {
        vector<optional<int>> tree;     // level-order input
        vector<double> expected;        // averages per level
    };

    // 530. Minimum Absolute Difference in BST
    struct MinimumAbsoluteDifferenceInBSTTestCase {
        vector<optional<int>> tree;     // level-order input (BST)
        int expected;                   // minimum absolute difference
    };

    // 504. Base 7
    struct Base7TestCase {
        int num;
        string expected;
    };

    // 136. Single Number
    struct SingleNumber136TestCase {
        vector<int> nums;
        int expected;
    };

    // 37. Sudoku Solver
    struct SudokuSolverTestCase {
        vector<vector<char>> input;
        vector<vector<char>> expected;
    };
} // namespace TestCases
