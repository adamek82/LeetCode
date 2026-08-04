#pragma once

#include <cstdint>
#include <string>
#include <vector>

namespace TestCases {

// 504. Base 7
struct Base7TestCase { int num; std::string expected; };

// 268. Missing Number
struct MissingNumberTestCase { std::vector<int> nums; int expected; };

// 136. Single Number
struct SingleNumberTestCase { std::vector<int> nums; int expected; };

// 191. Number of 1 Bits
struct NumberOf1BitsTestCase { std::uint32_t n; int expected; };

// 67. Add Binary
struct AddBinaryTestCase { std::string a; std::string b; std::string expected; };

} // namespace TestCases
