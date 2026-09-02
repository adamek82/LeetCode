#pragma once

#include <optional>
#include <string>
#include <vector>

namespace TestCases {

// 855. Exam Room
struct ExamRoomTestCase {
    std::vector<std::string> operations;
    std::vector<std::vector<int>> arguments;
    std::vector<std::optional<int>> expected;
};

} // namespace TestCases
