#pragma once

#include <string>
#include <vector>

namespace TestCases {

// 277. Find the Celebrity
struct FindCelebrityTestCase {
    std::vector<std::vector<int>> matrix;
    int expected;
};
// 65. Valid Number
struct ValidNumberTestCase {
    std::string input;
    bool expected;
};
} // namespace TestCases
