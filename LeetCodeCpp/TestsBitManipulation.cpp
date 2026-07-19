#include "TestsBitManipulation.h"

#include <string>
#include <vector>

#include "TestCases.h"
#include "TestUtils.h"

#include "AddBinary_67.h"
#include "Base7_504.h"
#include "NumberOf1Bits_191.h"
#include "SingleNumber_136.h"
#include "MissingNumber_268.h"

using namespace std;
using namespace TestCases;
using namespace TestUtils;

namespace {

/* Bitwise representation, bit counting, XOR, and binary-string arithmetic */

static bool base7_504_tests() {
    using namespace TestCases;

    vector<Base7TestCase> testCases = {
        // Examples from the problem statement
        {100, "202"},
        {-7, "-10"},

        // Additional checks
        {0, "0"},
        {1, "1"},
        {7, "10"},
        {343, "1000"}, // 7^3
        {49, "100"},   // 7^2
        {-1, "-1"},
    };

    Base7_504 sol;

    for (size_t i = 0; i < testCases.size(); ++i) {
        const auto& tc = testCases[i];

        string got = sol.convertToBase7(tc.num);

        const string label = "Base 7 504 Test " + to_string(i + 1);
        REQUIRE_ASSERT(assertEqScalar(label, tc.expected, got));
    }

    return true;
}

static bool missingNumber_268_tests() {
    vector<MissingNumberTestCase> testCases = {
        // Problem statement examples
        {{3, 0, 1}, 2},
        {{0, 1}, 2},
        {{9, 6, 4, 2, 3, 5, 7, 0, 1}, 8},

        // Additional edge/complex cases
        {{1, 2, 3}, 0},    // missing 0
        {{0, 1, 2, 3}, 4}, // missing n

        // Unsorted, includes n
        {{10, 9, 8, 7, 5, 4, 3, 2, 1, 0}, 6},
    };

    MissingNumber_268 solution;

    for (size_t i = 0; i < testCases.size(); ++i) {
        const auto& tc = testCases[i];

        auto nums = tc.nums; // solver takes non-const ref
        int got = solution.missingNumber(nums);

        const string label = "Missing Number 268 Test " + to_string(i + 1);
        REQUIRE_ASSERT(assertEqScalar(label, tc.expected, got));
    }

    return true;
}

static bool singleNumber_136_tests() {
    using namespace TestCases;

    vector<SingleNumberTestCase> testCases = {
        // Examples from the problem statement
        {{2, 2, 1}, 1},
        {{4, 1, 2, 1, 2}, 4},
        {{1}, 1},

        // Additional checks with zeros / negatives
        {{0, 1, 0}, 1},
        {{-1, -1, -2}, -2},
        {{-3, 0, 0, -3, 7}, 7},
    };

    SingleNumber_136 sol;

    for (size_t i = 0; i < testCases.size(); ++i) {
        const auto& tc = testCases[i];

        auto nums = tc.nums; // method takes non-const ref
        int got = sol.singleNumber(nums);

        const string label = "Single Number 136 Test " + to_string(i + 1);
        REQUIRE_ASSERT(assertEqScalar(label, tc.expected, got));
    }

    return true;
}

static bool numberOf1Bits_191_tests() {
    vector<NumberOf1BitsTestCase> testCases = {
        {11u, 3},          // 1011
        {128u, 1},         // 10000000
        {2147483645u, 30}, // 0x7FFFFFFD
        {0u, 0},           // zero
        {0xFFFFFFFFu, 32}, // all ones
    };

    NumberOf1Bits_191 solver;

    for (size_t i = 0; i < testCases.size(); ++i) {
        const auto& tc = testCases[i];

        int gotKernighan = solver.hammingWeightKernighan(tc.n);
        int gotLookup = solver.hammingWeightLookup(tc.n);

        const string base =
            "Number of 1 Bits 191 Test " + to_string(i + 1) +
            " (n=" + to_string(tc.n) + ")";

        REQUIRE_ASSERT(assertEqScalar(base + " [Kernighan]", tc.expected, gotKernighan));
        REQUIRE_ASSERT(assertEqScalar(base + " [Lookup]", tc.expected, gotLookup));
    }

    return true;
}

static bool addBinary_67_tests() {
    vector<AddBinaryTestCase> testCases = {
        {"11", "1", "100"},        // example 1
        {"1010", "1011", "10101"}, // example 2
        {"0", "0", "0"},           // both zero
        {"1111", "1", "10000"},    // carry over entire length
        {"100", "110010", "110110"}, // different lengths
    };

    AddBinary_67 solver;

    for (size_t i = 0; i < testCases.size(); ++i) {
        const auto& tc = testCases[i];

        string got = solver.addBinary(tc.a, tc.b);

        const string label = "Add Binary 67 Test " + to_string(i + 1);
        REQUIRE_ASSERT(assertEqScalar(label, tc.expected, got));
    }

    return true;
}

} // namespace

namespace TestsBitManipulation {

std::vector<TestRegistry::Entry> getTests() {
    return {
        // Basic integer representation and bit-counting
        TEST(504,  "Base 7",           base7_504_tests),
        TEST(268,  "Missing Number",   missingNumber_268_tests),
        TEST(136,  "Single Number",    singleNumber_136_tests),
        TEST(191,  "Number of 1 Bits", numberOf1Bits_191_tests),
        TEST(67,   "Add Binary",       addBinary_67_tests),
    };
}

} // namespace TestsBitManipulation
