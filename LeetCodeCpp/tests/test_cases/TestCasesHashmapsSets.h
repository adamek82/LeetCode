#pragma once

#include <optional>
#include <string>
#include <vector>

namespace TestCases {

// 771. Jewels and Stones
struct JewelsAndStonesTestCase { std::string jewels; std::string stones; int expected; };

// 217. Contains Duplicate
struct ContainsDuplicateTestCase { std::vector<int> nums; bool expected; };

// 383. Ransom Note
struct RansomNoteTestCase { std::string ransomNote; std::string magazine; bool expected; };

// 242. Valid Anagram
struct ValidAnagramTestCase { std::string s; std::string t; bool expected; };

// 1189. Maximum Number of Balloons
struct MaximumNumberOfBalloonsTestCase { std::string text; int expected; };

// 1207. Unique Number of Occurrences
struct UniqueNumberOfOccurrencesTestCase { std::vector<int> arr; bool expected; };

// 169. Majority Element
struct MajorityElementTestCase { std::vector<int> nums; int expected; };

// 1. Two Sum
struct TwoSumTestCase { std::vector<int> nums; int target; std::vector<int> expected; };

// 49. Group Anagrams
struct GroupAnagramsTestCase {
    std::vector<std::string> input;
    std::vector<std::vector<std::string>> expected;
};

// 36. Valid Sudoku
struct ValidSudokuTestCase { std::vector<std::vector<char>> board; bool expected; };

// 128. Longest Consecutive Sequence
struct LongestConsecutiveSequenceTestCase { std::vector<int> nums; int expected; };

// 451. Sort Characters by Frequency
struct SortCharactersByFrequencyTestCase { std::string input; };

// 692. Top K Frequent Words
struct TopKFrequentWordsTestCase {
    std::vector<std::string> words;
    int k;
    std::vector<std::string> expected;
};

// 1152. Analyze User Website Visit Pattern
struct AnalyzeUserWebsiteVisitPatternTestCase {
    std::vector<std::string> username;
    std::vector<int> timestamp;
    std::vector<std::string> website;
    std::vector<std::string> expected;
};

// 706. Design HashMap
struct DesignHashMapTestCase {
    std::vector<std::string> operations;
    std::vector<std::vector<int>> arguments;
    std::vector<std::optional<int>> expected;
};

} // namespace TestCases
