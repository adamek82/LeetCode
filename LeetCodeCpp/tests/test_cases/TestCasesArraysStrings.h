#pragma once

#include <string>
#include <utility>
#include <vector>

namespace TestCases {

// 412. Fizz Buzz
struct FizzBuzzTestCase {
    int n;
    std::vector<std::string> expected;
};

// 2798. Number of Employees Who Met the Target
struct NumberOfEmployeesWhoMetTargetTestCase {
    std::vector<int> hours;
    int target;
    int expected;
};

// 1768. Merge Strings Alternately
struct MergeStringsAlternatelyTestCase {
    std::string word1;
    std::string word2;
    std::string expected;
};

// 2239. Find Closest Number to Zero
struct FindClosestNumberToZeroTestCase {
    std::vector<int> nums;
    int expected;
};

// 392. Is Subsequence
struct IsSubsequence392TestCase {
    std::string s;
    std::string t;
    bool expected;
};

// 14. Longest Common Prefix
struct LongestCommonPrefixTestCase {
    std::vector<std::string> strs;
    std::string expected;
};

// 228. Summary Ranges
struct SummaryRangesTestCase {
    std::vector<int> nums;
    std::vector<std::string> expected;
};

// 13. Roman to Integer
struct RomanToIntegerTestCase {
    std::string input;
    int expected;
};

// 26. Remove Duplicates from Sorted Array
struct RemoveDuplicates26TestCase {
    std::vector<int> nums;
    std::vector<int> expected;
};

// 27. Remove Element
struct RemoveElementTestCase {
    std::vector<int> nums;
    int val;
    int expectedK;
    std::vector<int> expected;
};

// 88. Merge Sorted Array
struct MergeSortedArrayTestCase {
    std::vector<int> nums1;
    int m;
    std::vector<int> nums2;
    int n;
    std::vector<int> expected;
};

// 80. Remove Duplicates from Sorted Array II
struct RemoveDuplicatesFromSortedArrayIITestCase {
    std::vector<int> input;
    int expectedK;
    std::vector<int> expected;
};

// 121. Best Time to Buy and Sell Stock
struct BestTimeToBuyAndSellStockTestCase {
    std::vector<int> prices;
    int expected;
};

// 122. Best Time to Buy and Sell Stock II
struct BestTimeToBuyAndSellStockIITestCase {
    std::vector<int> prices;
    int expected;
};

// 724. Find Pivot Index
struct FindPivotIndexTestCase {
    std::vector<int> input;
    int expected;
};

// 3074. Apple Redistribution into Boxes
struct AppleRedistributionIntoBoxesTestCase {
    std::vector<int> apple;
    std::vector<int> capacity;
    int expected;
};

// 3046. Split the Array
struct SplitTheArrayTestCase {
    std::vector<int> nums;
    bool expected;
};

// 118. Pascal's Triangle
struct PascalsTriangleTestCase {
    int numRows;
    std::vector<std::vector<int>> expected;
};

// 75. Sort Colors
struct SortColorsTestCase {
    std::vector<int> input;
    std::vector<int> expected;

    SortColorsTestCase(std::vector<int> in, std::vector<int> exp)
        : input(std::move(in)),
          expected(std::move(exp)) {}
};

// 238. Product of Array Except Self
struct ProductOfArrayExceptSelfTestCase {
    std::vector<int> input;
    std::vector<int> expected;
};

// 274. H-Index
struct HIndexTestCase {
    std::vector<int> input;
    int expected;
};

// 56. Merge Intervals
struct MergeIntervalsTestCase {
    std::vector<std::vector<int>> input;
    std::vector<std::vector<int>> expected;
};

// 6. Zigzag Conversion
struct ZigzagConversionTestCase {
    std::string input;
    int numRows;
    std::string expected;
};

// 48. Rotate Image
struct RotateImageTestCase {
    std::vector<std::vector<int>> input;
    std::vector<std::vector<int>> expected;
};

// 54. Spiral Matrix
struct SpiralMatrixTestCase {
    std::vector<std::vector<int>> matrix;
    std::vector<int> expected;
};

// 392. Is Subsequence follow-up
struct IsSubsequenceFollowUpTestCase {
    std::string t;
    std::vector<std::pair<std::string, bool>> queries;
};

} // namespace TestCases
