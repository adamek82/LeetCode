#pragma once

#include <vector>

namespace TestCases {

// 704. Binary Search
struct BinarySearchTestCase {
    std::vector<int> nums;
    int target;
    int expected;
};
// 35. Search Insert Position
// Reuses BinarySearchTestCase: same input/target/result shape.

// 278. First Bad Version
struct FirstBadVersionTestCase {
    int n;
    int firstBad;
    int expected;
};
// 69. Sqrt(x)
struct SqrtXTestCase {
    int x;
    int expected;
};
// 367. Valid Perfect Square
struct ValidPerfectSquareTestCase {
    int num;
    bool expected;
};
// 875. Koko Eating Bananas
struct KokoEatingBananasTestCase {
    std::vector<int> piles;
    int h;
    int expected;
};
// 74. Search a 2D Matrix
struct Search2DMatrixTestCase {
    std::vector<std::vector<int>> matrix;
    int target;
    bool expected;
};
// 153. Find Minimum in Rotated Sorted Array
struct FindMinimumInRotatedSortedArrayTestCase {
    std::vector<int> nums;
    int expected;
};
// 33. Search in Rotated Sorted Array
// Reuses BinarySearchTestCase: same nums/target/result shape.

} // namespace TestCases
