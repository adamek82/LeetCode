#pragma once

#include <string>
#include <utility>
#include <vector>

namespace TestCases {

// 682. Baseball Game
struct BaseballGameTestCase {
    std::vector<std::string> operations;
    int expected;
};
// 20. Valid Parentheses
struct ValidParenthesesTestCase {
    std::string input;
    bool expected;
};
// 150. Evaluate Reverse Polish Notation
struct EvaluateReversePolishNotationTestCase {
    std::vector<std::string> input;
    int expected;
};
// 394. Decode String
struct DecodeStringTestCase {
    std::string input;
    std::string expected;
};
// 739. Daily Temperatures
struct DailyTemperaturesTestCase {
    std::vector<int> temperatures;
    std::vector<int> expected;
};
// 84. Largest Rectangle in Histogram
struct LargestRectangleInHistogramTestCase {
    std::vector<int> heights;
    int expected;
};
// 155. Min Stack
struct MinStackTestCase {
    std::vector<std::pair<std::string, int>> operations;
    std::vector<int> expected;
};

// 85. Maximal Rectangle
struct MaximalRectangleTestCase {
    std::vector<std::vector<char>> matrix;
    int expected;
};
} // namespace TestCases
