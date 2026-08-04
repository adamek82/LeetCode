#pragma once

#include <string>
#include <vector>

namespace TestCases {

// 78. Subsets
struct SubsetsTestCase {
    std::vector<int> nums;
    std::vector<std::vector<int>> expected;
};

// 77. Combinations
struct CombinationsTestCase {
    int n;
    int k;
    std::vector<std::vector<int>> expected;
};

// 46. Permutations
struct PermutationsTestCase {
    std::vector<int> nums;
    std::vector<std::vector<int>> expected;
};

// 17. Letter Combinations of a Phone Number
struct LetterCombinationsTestCase {
    std::string digits;
    std::vector<std::string> expected;
};

// 22. Generate Parentheses
struct GenerateParenthesesTestCase {
    int n;
    std::vector<std::string> expected;
};

// 39. Combination Sum
struct CombinationSumTestCase {
    std::vector<int> candidates;
    int target;
    std::vector<std::vector<int>> expected;
};

// 37. Sudoku Solver
struct SudokuSolverTestCase {
    std::vector<std::vector<char>> input;
    std::vector<std::vector<char>> expected;
};

// 79. Word Search
struct WordSearchTestCase {
    std::vector<std::vector<char>> board;
    std::string word;
    bool expected;
};

} // namespace TestCases
