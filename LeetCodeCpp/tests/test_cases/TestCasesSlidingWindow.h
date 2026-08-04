#pragma once

#include <string>
#include <vector>

namespace TestCases {

// 643. Maximum Average Subarray I
struct MaximumAverageSubarrayITestCase {
    std::vector<int> nums;
    int k;
    double expected;
};

// 1004. Max Consecutive Ones III
struct MaxConsecutiveOnesIIITestCase {
    std::vector<int> nums;
    int k;
    int expected;
};

// 209. Minimum Size Subarray Sum
struct MinimumSizeSubarraySumTestCase {
    int target;
    std::vector<int> nums;
    int expected;
};

// 3. Longest Substring Without Repeating Characters
struct LongestSubstringWithoutRepeatingCharactersTestCase {
    std::string input;
    int expected;
};

// 424. Longest Repeating Character Replacement
struct LongestRepeatingCharacterReplacementTestCase {
    std::string input;
    int k;
    int expected;
};

// 567. Permutation in String
struct PermutationInStringTestCase {
    std::string s1;
    std::string s2;
    bool expected;
};

} // namespace TestCases
