#pragma once

#include <string>
#include <vector>

namespace TestCases {

// 344. Reverse String
struct ReverseStringTestCase {
    std::vector<char> input;
    std::vector<char> expected;
};
// 125. Valid Palindrome
struct ValidPalindromeTestCase {
    std::string input;
    bool expected;
};
// 977. Squares of a Sorted Array
struct SquaresOfASortedArrayTestCase {
    std::vector<int> nums;
    std::vector<int> expected;
};
// 167. Two Sum II - Input Array Is Sorted
struct TwoSumIIInputArrayIsSortedTestCase {
    std::vector<int> numbers;
    int target;
    std::vector<int> expected;
};

// 1099. Two Sum Less Than K
struct TwoSumLessThanKTestCase {
    std::vector<int> nums;
    int k;
    int expected;
};
// 15. 3Sum
struct ThreeSumTestCase {
    std::vector<int> nums;
    std::vector<std::vector<int>> expected;
};
// 16. 3Sum Closest
struct ThreeSumClosestTestCase {
    std::vector<int> nums;
    int target;
    int expected;
};
// 18. 4Sum
struct FourSumTestCase {
    std::vector<int> nums;
    int target;
    std::vector<std::vector<int>> expected;
};

// 11. Container With Most Water
struct ContainerWithMostWaterTestCase {
    std::vector<int> height;
    int expected;
};
// 42. Trapping Rain Water
struct TrappingRainWaterTestCase {
    std::vector<int> height;
    int expected;
};
} // namespace TestCases
