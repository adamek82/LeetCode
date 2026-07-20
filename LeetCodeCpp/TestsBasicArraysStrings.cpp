#include "TestsBasicArraysStrings.h"

#include <climits>
#include <string>
#include <vector>

#include "TestCases.h"
#include "TestUtils.h"

#include "FizzBuzz_412.h"
#include "NumberOfEmployeesWhoMetTarget_2798.h"
#include "MergeStringsAlternately_1768.h"
#include "FindClosestNumberToZero_2239.h"

#include "IsSubsequence_392.h"
#include "LongestCommonPrefix_14.h"
#include "SummaryRanges_228.h"
#include "RomanToInteger_13.h"

using namespace std;
using namespace TestCases;
using namespace TestUtils;

namespace {

/* Simple iteration, counting, and basic array/string traversal */

static bool fizzBuzz_412_tests() {
    vector<FizzBuzzTestCase> testCases = {
        {
            3,
            {"1", "2", "Fizz"}
        },
        {
            5,
            {"1", "2", "Fizz", "4", "Buzz"}
        },
        {
            15,
            {"1", "2", "Fizz", "4", "Buzz", "Fizz", "7", "8", "Fizz", "Buzz", "11", "Fizz", "13", "14", "FizzBuzz"}
        },
        {
            16,
            {"1", "2", "Fizz", "4", "Buzz", "Fizz", "7", "8", "Fizz", "Buzz", "11", "Fizz", "13", "14", "FizzBuzz", "16"}
        },
        {
            30,
            {"1", "2", "Fizz", "4", "Buzz", "Fizz", "7", "8", "Fizz", "Buzz", "11", "Fizz", "13", "14", "FizzBuzz",
            "16", "17", "Fizz", "19", "Buzz", "Fizz", "22", "23", "Fizz", "Buzz", "26", "Fizz", "28", "29", "FizzBuzz"}
        }
    };

    FizzBuzz_412 sol;

    for (size_t i = 0; i < testCases.size(); ++i) {
        const auto& tc = testCases[i];
        auto got = sol.fizzBuzz(tc.n);

        const string label =
            "FizzBuzz 412 Test " + to_string(i + 1) + " (n=" + to_string(tc.n) + ")";
        REQUIRE_ASSERT(assertEqGeneric(label, tc.expected, got,
                                        [](vector<string> v) { return v; },
                                        PrintQuotedStrings{}));
    }

    return true;
}

static bool numberOfEmployeesWhoMetTarget_2798_tests() {
    using namespace TestCases;

    vector<NumberOfEmployeesWhoMetTargetTestCase> testCases = {
        // Examples from the problem statement
        {{0, 1, 2, 3, 4}, 2, 3},
        {{5, 1, 4, 2, 2}, 6, 0},

        // Additional edge / sanity tests
        {{0},             0, 1}, // target 0, everyone meets it
        {{0},             1, 0}, // nobody meets target
        {{3, 3, 3},       3, 3}, // all meet target exactly
        {{1, 2, 3, 4, 5}, 5, 1}, // exactly one employee meets target
    };

    NumberOfEmployeesWhoMetTarget_2798 sol;

    for (size_t i = 0; i < testCases.size(); ++i) {
        auto hours1 = testCases[i].hours;
        auto hours2 = testCases[i].hours;

        int gotLoop = sol.numberOfEmployeesWhoMetTarget_CountingLoop(
            hours1, testCases[i].target);
        int gotIf = sol.numberOfEmployeesWhoMetTarget_CountIf(
            hours2, testCases[i].target);

        const string base =
            "Number of Employees Who Met Target 2798 Test " + to_string(i + 1);
        REQUIRE_ASSERT(assertEqScalar(
            base + " [CountingLoop]",
            testCases[i].expected,
            gotLoop));
        REQUIRE_ASSERT(assertEqScalar(
            base + " [CountIf]",
            testCases[i].expected,
            gotIf));
    }

    return true;
}

static bool mergeStringsAlternately_1768_tests() {
    vector<MergeStringsAlternatelyTestCase> tests = {
        // From the statement
        {"abc",   "pqr",   "apbqcr"},
        {"ab",    "pqrs",  "apbqrs"},
        {"abcd",  "pq",    "apbqcd"},
        // Additional
        {"z",     "abcdef","zabcdef"},  // word1 shorter by far
        {"ace",   "bdf",   "abcdef"},   // equal lengths
        {"aaaaa", "b",     "abaaaa"}    // word2 very short
    };

    MergeStringsAlternately_1768 sol;

    for (size_t i = 0; i < tests.size(); ++i) {
        string got = sol.mergeAlternately(tests[i].word1, tests[i].word2);

        const string label = "Merge Strings Alternately 1768 Test " + to_string(i + 1);
        REQUIRE_ASSERT(assertEqScalar(label, tests[i].expected, got));
    }

    return true;
}

static bool findClosestNumber_2239_tests() {
    vector<FindClosestNumberToZeroTestCase> tests = {
        // From the statement
        {{-4,-2,1,4,8}, 1},
        {{2,-1,1},      1},

        // Additional
        {{0,5,-5},              0},   // zero present → always closest
        {{-7,-3,-2,-2},        -2},   // all negatives; tie between -2s → -2
        {{-100000,100000}, 100000},   // extremes; tie → prefer positive
        {{-1,1,2,-2},           1}    // tie at distance 1 → prefer +1
    };

    FindClosestNumberToZero_2239 sol;

    for (size_t i = 0; i < tests.size(); ++i) {
        int got = sol.findClosestNumber(tests[i].nums);

        const string label = "Find Closest Number to Zero 2239 Test " + to_string(i + 1);
        REQUIRE_ASSERT(assertEqScalar(label, tests[i].expected, got));
    }

    return true;
}

/* Sequence comparison, prefix checks, and simple string parsing */

static bool isSubsequence_392_tests() {
    vector<IsSubsequence392TestCase> tests = {
        {"abc",     "ahbgdc",   true},
        {"axc",     "ahbgdc",   false},
        {"",        "ahbgdc",   true},
        {"a",       "",         false},
        {"aaaaaa",  "baaaacaa", true},
        {"abc",     "acb",      false}
    };

    // Single-query tests across all three methods
    for (size_t i = 0; i < tests.size(); ++i) {
        const string& s = tests[i].s;
        const string& t = tests[i].t;

        IsSubsequence_392 plain;
        bool a = plain.isSubsequence_TwoPointer(s, t);

        IsSubsequence_392 idxPos;
        idxPos.preprocess_PosIndex(t);
        bool b = idxPos.isSubsequence_PosIndex(s);

        IsSubsequence_392 idxNext;
        idxNext.preprocess_NextTable(t);
        bool c = idxNext.isSubsequence_NextTable(s);

        const string base = "Is Subsequence 392 Test " + to_string(i + 1);
        REQUIRE_ASSERT(assertEqScalar(base + " [two-pointer]", tests[i].expected, a));
        REQUIRE_ASSERT(assertEqScalar(base + " [pos-index]", tests[i].expected, b));
        REQUIRE_ASSERT(assertEqScalar(base + " [next-table]",  tests[i].expected, c));
        REQUIRE_ASSERT(assertEqScalar(base + " [consistency pos vs next]", b, c));
    }

    // Follow-up: many queries for the same t (reuse preprocessed data)
    vector<IsSubsequenceFollowUpTestCase> futests = {
        {"ahbgdc", { {"abc", true}, {"axc", false}, {"agc", true}, {"", true}, {"aaaa", false} }},
        {"leetcode", { {"leet", true}, {"code", true}, {"leot", false}, {"leetcode", true} }}
    };

    for (size_t b = 0; b < futests.size(); ++b) {
        const string& t = futests[b].t;

        IsSubsequence_392 idxPos, idxNext;
        idxPos.preprocess_PosIndex(t);
        idxNext.preprocess_NextTable(t);

        for (size_t qi = 0; qi < futests[b].queries.size(); ++qi) {
            const auto& [qs, expected] = futests[b].queries[qi];

            bool a = IsSubsequence_392().isSubsequence_TwoPointer(qs, t);
            bool p = idxPos.isSubsequence_PosIndex(qs);
            bool n = idxNext.isSubsequence_NextTable(qs);

            const string base =
                "Is Subsequence 392 FU " + to_string(b + 1) +
                " Q" + to_string(qi + 1);
            REQUIRE_ASSERT(assertEqScalar(base + " [two-pointer]", expected, a));
            REQUIRE_ASSERT(assertEqScalar(base + " [pos-index]", expected, p));
            REQUIRE_ASSERT(assertEqScalar(base + " [next-table]",  expected, n));
            REQUIRE_ASSERT(assertEqScalar(base + " [consistency pos vs next]", p, n));
        }
    }

    return true;
}

static bool longestCommonPrefix_14_tests() {
    vector<LongestCommonPrefixTestCase> tcs = {
        // Provided examples
        {{"flower","flow","flight"}, "fl"},
        {{"dog","racecar","car"}, ""},

        // Edge cases / extras
        {{""}, ""},
        {{"a"}, "a"},
        {{"", "b"}, ""},
        {{"interspecies","interstellar","interstate"}, "inters"},
        {{"throne","throne"}, "throne"},
        {{"throne","throne","throne"}, "throne"},
        {{"cir","car"}, "c"},
        {{"reflower","flow","flight"}, ""},
        {{"aa","a"}, "a"},
        {{"leetcode","leet","le","l"}, "l"}
    };

    LongestCommonPrefix_14 sol;

    for (size_t i = 0; i < tcs.size(); ++i) {
        string gotL = sol.longestCommonPrefix_Linear(tcs[i].strs);
        string gotS = sol.longestCommonPrefix_Sort(tcs[i].strs);
        string gotV = sol.longestCommonPrefix_Vertical(tcs[i].strs);

        if (gotL != gotS || gotL != gotV) {
            cout << "[WARN] LCP variants disagree on case " << (i + 1)
                << "  linear=\"" << gotL << "\" sort=\"" << gotS
                << "\" vertical=\"" << gotV << "\"\n";
        }

        const string base = "LCP14 Test " + to_string(i + 1);
        REQUIRE_ASSERT(assertEqScalar(base + " [linear]", tcs[i].expected, gotL));
        REQUIRE_ASSERT(assertEqScalar(base + " [vertical]", tcs[i].expected, gotV));
        REQUIRE_ASSERT(assertEqScalar(base + " [sort]", tcs[i].expected, gotS));
    }

    return true;
}

static bool summaryRanges_228_tests() {
    vector<SummaryRangesTestCase> tests = {
        {{0,1,2,4,5,7},                   {"0->2","4->5","7"}},
        {{0,2,3,4,6,8,9},                 {"0","2->4","6","8->9"}},
        {{},                              {}},
        {{5},                             {"5"}},
        {{-3,-2,-1,0,2},                  {"-3->0","2"}},
        {{INT_MAX-1, INT_MAX},            {to_string(INT_MAX-1) + "->" + to_string(INT_MAX)}},
        {{INT_MIN, INT_MIN+1, INT_MIN+3}, {to_string(INT_MIN) + "->" + to_string(INT_MIN+1), to_string(INT_MIN+3)}},
        {{1,3,5},                         {"1","3","5"}}
    };

    SummaryRanges_228 sol;

    for (size_t i = 0; i < tests.size(); ++i) {
        auto in = tests[i].nums; // method takes non-const ref
        auto got = sol.summaryRanges(in);

        const string label = "Summary Ranges 228 Test " + to_string(i + 1);
        REQUIRE_ASSERT(assertEqStrings(label, tests[i].expected, got));
    }

    return true;
}

static bool romanToInteger_13_tests() {
    vector<RomanToIntegerTestCase> tests = {
        // From the statement
        {"III", 3},
        {"LVIII", 58},
        {"MCMXCIV", 1994},
        // Additional
        {"IX", 9},             // simple subtractive
        {"CDXLIV", 444},       // multiple subtractive pairs (CD + XL + IV)
        {"MMMCMXCIX", 3999}    // maximum in range
    };

    RomanToInteger_13 sol;

    for (size_t i = 0; i < tests.size(); ++i) {
        int got = sol.romanToInt(tests[i].input);

        const string label =
            "Roman to Integer 13 Test " + to_string(i + 1) +
            " [\"" + tests[i].input + "\"]";
        REQUIRE_ASSERT(assertEqScalar(label, tests[i].expected, got));
    }

    return true;
}

/* Preprocessing optimization for repeated subsequence queries */

// Stress test for next-position preprocessing; also cross-checks pos-index.
static bool isSubsequence_392_nextpos_tests() {
    string t;
    t.reserve(10000);

    for (int i = 0; i < 10000; ++i) {
        t.push_back(char('a' + (i % 26)));
    }

    IsSubsequence_392 idxNext;
    IsSubsequence_392 idxPos;

    idxNext.preprocess_NextTable(t);
    idxPos.preprocess_PosIndex(t);

    struct Query {
        string s;
        bool expected;
    };

    vector<Query> queries;

    {
        string s;
        s.reserve(26 * 100);

        for (int rep = 0; rep < 100; ++rep) {
            for (char c = 'a'; c <= 'z'; ++c) {
                s.push_back(c);
            }
        }

        queries.push_back({move(s), true});
    }

    queries.push_back({string(384, 'z'), true});
    queries.push_back({string(385, 'z'), false});
    queries.push_back({"leetcode", true});
    queries.push_back({"zzzay", true});
    queries.push_back({"", true});

    for (size_t i = 0; i < queries.size(); ++i) {
        bool gotNext = idxNext.isSubsequence_NextTable(queries[i].s);
        bool gotPos = idxPos.isSubsequence_PosIndex(queries[i].s);

        const string base = "Is Subsequence 392 Big Test " + to_string(i + 1);
        REQUIRE_ASSERT(assertEqScalar(base + " [NextTable]", queries[i].expected, gotNext));
        REQUIRE_ASSERT(assertEqScalar(base + " [PosIndex]", queries[i].expected, gotPos));
        REQUIRE_ASSERT(assertEqScalar(base + " [Consistency]", gotNext, gotPos));
    }

    return true;
}

} // namespace

namespace TestsBasicArraysStrings {

std::vector<TestRegistry::Entry> getTests() {
    return {
        // Simple iteration, counting, and basic array/string traversal
        TEST(412,  "FizzBuzz",                              fizzBuzz_412_tests),
        TEST(2798, "Number of Employees Who Met the Target", numberOfEmployeesWhoMetTarget_2798_tests),
        TEST(1768, "Merge Strings Alternately",             mergeStringsAlternately_1768_tests),
        TEST(2239, "Find Closest Number to Zero",           findClosestNumber_2239_tests),

        // Sequence comparison, prefix checks, and simple string parsing
        TEST(392,  "Is Subsequence",                        isSubsequence_392_tests),
        TEST(14,   "Longest Common Prefix",                 longestCommonPrefix_14_tests),
        TEST(228,  "Summary Ranges",                        summaryRanges_228_tests),
        TEST(13,   "Roman to Integer",                      romanToInteger_13_tests),

        // Preprocessing optimization for repeated subsequence queries
        TEST(392,  "Is Subsequence (next-position table)",  isSubsequence_392_nextpos_tests),
    };
}

} // namespace TestsBasicArraysStrings
