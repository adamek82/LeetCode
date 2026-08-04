#pragma once

#include <optional>
#include <string>
#include <vector>

namespace TestCases {

enum class MinHeapOpKind {
    Insert,
    ExtractMin,
    Update,
};

struct MinHeapOp {
    MinHeapOpKind kind;
    int value = 0;
    int newValue = 0;
};

struct MinHeapTestCase {
    std::vector<MinHeapOp> operations;
    std::vector<int> expected;
};

// 855. Exam Room
struct ExamRoomTestCase {
    std::vector<std::string> operations;
    std::vector<std::vector<int>> arguments;
    std::vector<std::optional<int>> expected;
};

} // namespace TestCases
