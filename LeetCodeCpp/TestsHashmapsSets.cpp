#include "TestsHashmapsSets.h"

#include <algorithm>
#include <numeric>
#include <string>
#include <vector>

#include "TestCases.h"
#include "TestUtils.h"

#include "JewelsAndStones_771.h"
#include "ContainsDuplicate_217.h"

#include "RansomNote_383.h"
#include "ValidAnagram_242.h"
#include "MaximumNumberOfBalloons_1189.h"
#include "UniqueNumberOfOccurrences_1207.h"
#include "MajorityElement_169.h"

#include "TwoSum_1.h"

#include "GroupAnagrams_49.h"

#include "ValidSudoku_36.h"

#include "LongestConsecutiveSequence_128.h"

#include "SortCharactersByFrequency_451.h"
#include "TopKFrequentWords_692.h"

#include "AnalyzeUserWebsiteVisitPattern1152.h"

#include "DesignHashMap_706.h"

using namespace std;
using namespace TestCases;
using namespace TestUtils;

namespace {

// ============================================================================
// Hashmaps & Sets
// ============================================================================

/* Basic membership checks with sets and simple lookups */

bool numJewelsAndStones_771_tests() {
    vector<JewelsAndStonesTestCase> testCases = {
        // Problem-statement examples
        {"aA", "aAAbbbb", 3},
        {"z",  "ZZ",      0},

        // Extra, more demanding cases
        {"abc", "aabbccABCabc",                    9},
        {"abcdefghijklmnopqrstuvwxyz",
            "abcdefghijklmnopqrstuvwxyzABCDEFGHIJ",  26},
        {"Aa",  "aaaaaaaaAAAAAAAaA",              17}
    };

    JewelsAndStones_771 solver;

    for (size_t i = 0; i < testCases.size(); ++i) {
        int got = solver.numJewelsInStones(testCases[i].jewels, testCases[i].stones);

        const string label = "Jewels & Stones 771 Test " + to_string(i + 1);
        REQUIRE_ASSERT(assertEqScalar(label, testCases[i].expected, got));
    }

    return true;
}

bool containsDuplicate_217_tests() {
    vector<ContainsDuplicateTestCase> tests = {
        // 3 from the statement
        {{1, 2, 3, 1}, true},
        {{1, 2, 3, 4}, false},
        {{1, 1, 1, 3, 3, 4, 3, 2, 4, 2}, true},

        // 3 “complex”/edge-ish
        // extremes + duplicate far apart
        {{1000000000, -1000000000, 999999999, -999999999, 123456789, 987654321, 123456789}, true},
        // negative/zero/positive with early & late dup
        {{-7, 0, 5, 42, -7}, true},
        // large unique set
        {{}, false} // placeholder, will be replaced by bigUnique below
    };

    // Build a large unique vector [-5000..4999]
    vector<int> bigUnique(10000);
    iota(bigUnique.begin(), bigUnique.end(), -5000);
    tests.push_back({ move(bigUnique), false });

    ContainsDuplicate_217 sol;

    for (size_t i = 0; i < tests.size(); ++i) {
        bool got = sol.containsDuplicate(tests[i].nums);

        const string label = "ContainsDuplicate 217 Test " + to_string(i + 1);
        REQUIRE_ASSERT(assertEqScalar(label, tests[i].expected, got));
    }

    // Stress: large array + one duplicate appended
    vector<int> bigWithDup(10000);
    iota(bigWithDup.begin(), bigWithDup.end(), -5000);
    bigWithDup.push_back(123); // duplicate
    bool got = sol.containsDuplicate(bigWithDup);

    REQUIRE_ASSERT(assertEqScalar("ContainsDuplicate 217 Stress", true, got));

    return true;
}

/* Frequency counting on characters and values */

bool ransomNote_383_tests() {
    vector<RansomNoteTestCase> testCases = {
        // Examples from the problem statement
        {"a",  "b",   false},
        {"aa", "ab",  false},
        {"aa", "aab", true},

        // Additional tests
        {"abc", "cba",  true},   // same letters, different order
        {"aaa", "aa",   false}   // not enough copies of 'a' in magazine
    };

    RansomNote_383 sol;

    for (size_t i = 0; i < testCases.size(); ++i) {
        bool got = sol.canConstruct(testCases[i].ransomNote, testCases[i].magazine);

        const string label = "Ransom Note 383 Test " + to_string(i + 1);
        REQUIRE_ASSERT(assertEqScalar(label, testCases[i].expected, got));
    }

    return true;
}

bool validAnagram_242_tests() {
    vector<ValidAnagramTestCase> testCases = {
        // Examples from the problem statement
        {"anagram", "nagaram", true},
        {"rat", "car", false},

        // Additional complex test cases
        {"abcdefg", "gfedcba", true}, // Reverse order, still an anagram
        {"aabbcc", "abcabc", true},   // Same frequency, different order
        {string(50000, 'a') + "b", string(50000, 'a') + "c", false} // Edge case with large input, one character differs
    };

    ValidAnagram_242 sol;

    for (size_t i = 0; i < testCases.size(); ++i) {
        bool got = sol.isAnagram(testCases[i].s, testCases[i].t);

        const string label = "Valid Anagram 242 Test " + to_string(i + 1);
        REQUIRE_ASSERT(assertEqScalar(label, testCases[i].expected, got));
    }

    return true;
}

bool maximumNumberOfBalloons_1189_tests()
{
    vector<MaximumNumberOfBalloonsTestCase> cases = {
        {"nlaebolko",            1},   // example 1
        {"loonbalxballpoon",     2},   // example 2
        {"leetcode",             0},   // example 3
        {"balloonballoon",       2},   // two exact words
        {"balon",                0}    // missing letters
    };

    MaximumNumberOfBalloons_1189 solver;
    for (size_t i = 0; i < cases.size(); ++i) {
        int got = solver.maxNumberOfBalloons(cases[i].text);

        const string label = "Maximum Number of Balloons 1189 Test " + to_string(i + 1);
        REQUIRE_ASSERT(assertEqScalar(label, cases[i].expected, got));
    }

    return true;
}

bool uniqueNumberOfOccurrences_1207_tests() {
    vector<UniqueNumberOfOccurrencesTestCase> testCases = {
        // Examples from the problem statement
        {{1, 2, 2, 1, 1, 3},                true},
        {{1, 2},                            false},
        {{-3, 0, 1, -3, 1, 1, 1, -3, 10, 0}, true},

        // Additional tests
        {{42},                              true},  // single value
        {{1, 1, 2, 2, 3, 3},                false}, // all values occur twice
        {{1, 1, 1, 2, 2, 3},                true},  // counts 3, 2, 1 are all distinct
    };

    UniqueNumberOfOccurrences_1207 sol;
    for (size_t i = 0; i < testCases.size(); ++i) {
        auto arr = testCases[i].arr; // copy (method takes non-const ref, but doesn't modify)
        bool got = sol.uniqueOccurrences(arr);

        const string label = "Unique Number Of Occurrences 1207 Test " + to_string(i + 1);
        REQUIRE_ASSERT(assertEqScalar(label, testCases[i].expected, got));
    }

    return true;
}

bool majorityElement_169_tests() {
    // Define test cases
    vector<MajorityElementTestCase> testCases = {
        // Example 1
        {{3, 2, 3}, 3},
        // Example 2
        {{2, 2, 1, 1, 1, 2, 2}, 2},
        // Edge Case: Single element
        {{1}, 1},
        // Complex Case 1: Large input with clear majority
        {{1, 1, 1, 1, 2, 2, 2, 2, 1, 1}, 1},
        // Complex Case 2: Alternating majority
        {{5, 1, 5, 1, 5, 5, 5, 2, 5, 3, 5, 5}, 5},
        // Complex Case 3: Majority in large data
        {{10, 9, 9, 10, 10, 10, 9, 10, 9, 10, 10}, 10}
    };

    MajorityElement_169 sol;

    struct MajorityImpl {
        string name;
        function<int(const MajorityElementTestCase&)> run;
    };

    const vector<MajorityImpl> impls = {
        {
            "Boyer-Moore",
            [&](const MajorityElementTestCase& tc) {
                return sol.majorityElement(tc.nums);
            }
        },
        {
            "Hashmap",
            [&](const MajorityElementTestCase& tc) {
                return sol.majorityElementWithHashmap(tc.nums);
            }
        },
        {
            "Bit Counting",
            [&](const MajorityElementTestCase& tc) {
                return sol.majorityElementWithBitCounting(tc.nums);
            }
        },
    };

    for (size_t i = 0; i < testCases.size(); ++i) {
        const auto& tc = testCases[i];

        for (const auto& impl : impls) {
            int got = impl.run(tc);

            const string label =
                "Majority Element 169 Test " + to_string(i + 1) +
                " [" + impl.name + "]";
            REQUIRE_ASSERT(assertEqScalar(label, tc.expected, got));
        }
    }

    return true;
}

/* Hashmap lookup patterns for complements and associations */

bool twoSum_1_tests() {
    vector<TwoSumTestCase> cases = {
        {{2, 7, 11, 15},               9,  {0, 1}},
        {{3, 2, 4},                    6,  {1, 2}},
        {{3, 3},                       6,  {0, 1}},
        // Added tougher / edge scenarios
        {{-10, -1, 0, 1, 2, 8},       -9,  {0, 3}},           // negative + positive mix
        {{1000000000, -1000000000, 3, 4, 8}, 12,  {3, 4}}     // 4 + 8
    };

    TwoSum_1 solver;

    for (size_t i = 0; i < cases.size(); ++i) {
        auto got = solver.twoSum(cases[i].nums, cases[i].target);

        // Order-independent compare of index pairs
        auto expected = cases[i].expected;
        sort(got.begin(), got.end());
        sort(expected.begin(), expected.end());

        const string label = "Two Sum 1 Test " + to_string(i + 1);
        REQUIRE_ASSERT(assertEqVIntExact(label, expected, got));
    }

    return true;
}

/* Grouping values by a shared hashable signature */

bool groupAnagrams_49_tests() {
    vector<GroupAnagramsTestCase> testCases = {
        // Example 1
        {{"eat", "tea", "tan", "ate", "nat", "bat"},
            {{"bat"}, {"tan", "nat"}, {"eat", "tea", "ate"}}},

        // Example 2
        {{""}, { {""} }},

        // Example 3
        {{"a"}, { {"a"} }},

        // Large test case: Multiple anagram groups with long words
        {{"abcdefg", "gfedcba", "xyz", "zxy", "yxz", "longword", "wordlong"},
            {{"abcdefg", "gfedcba"}, {"xyz", "zxy", "yxz"}, {"longword", "wordlong"}}},

        // Large test case: Many unique words (no anagrams)
        {{"abcd", "efgh", "ijkl", "mnop", "qrst", "uvwx", "yz"},
            {{"abcd"}, {"efgh"}, {"ijkl"}, {"mnop"}, {"qrst"}, {"uvwx"}, {"yz"}}}
    };

    GroupAnagrams_49 solution;

    for (size_t i = 0; i < testCases.size(); ++i) {
        auto gotSorting = solution.groupAnagrams_sorting(testCases[i].input);
        auto gotCounting = solution.groupAnagrams_counting(testCases[i].input);

        const string base = "Group Anagrams 49 Test " + to_string(i + 1);
        REQUIRE_ASSERT(assertEqVVStrAnyOrder(base + " [sorting]", testCases[i].expected, gotSorting));
        REQUIRE_ASSERT(assertEqVVStrAnyOrder(base + " [counting]", testCases[i].expected, gotCounting));
        REQUIRE_ASSERT(assertEqVVStrAnyOrder(base + " [consistency]", gotSorting, gotCounting));
    }

    return true;
}

/* Using sets/maps to validate constraints and deduplicate states */

bool validSudoku_36_tests() {
    vector<ValidSudokuTestCase> testCases = {
        // Example 1: Valid Sudoku
        {{
            {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
            {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
            {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
            {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
            {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
            {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
            {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
            {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
            {'.', '.', '.', '.', '8', '.', '.', '7', '9'}
        }, true},

        // Example 2: Invalid Sudoku (Duplicate in Sub-box)
        {{
            {'8', '3', '.', '.', '7', '.', '.', '.', '.'},
            {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
            {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
            {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
            {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
            {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
            {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
            {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
            {'.', '.', '.', '.', '8', '.', '.', '7', '9'}
        }, false},

        // Example 3: Valid Complex Sudoku
        {{
            {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
            {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
            {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
            {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
            {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
            {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
            {'1', '6', '.', '.', '.', '.', '2', '8', '.'},
            {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
            {'2', '.', '.', '.', '8', '.', '.', '7', '9'}
        }, true},

        // Example 4: Invalid Sudoku (Duplicate in Row)
        {{
            {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
            {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
            {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
            {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
            {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
            {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
            {'1', '6', '.', '.', '.', '.', '2', '8', '.'},
            {'.', '.', '.', '4', '1', '9', '.', '1', '5'},
            {'2', '.', '.', '.', '8', '.', '.', '7', '9'}
        }, false},

        // Example 5: Invalid Sudoku (Duplicate in Column)
        {{
            {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
            {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
            {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
            {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
            {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
            {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
            {'1', '6', '.', '.', '.', '.', '2', '8', '.'},
            {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
            {'2', '.', '.', '.', '8', '.', '.', '7', '5'}
        }, false},
    };

    ValidSudoku_36 solver;

    for (size_t i = 0; i < testCases.size(); ++i) {

        bool got = solver.isValidSudoku(testCases[i].board);

        const string label = "Valid Sudoku Test " + to_string(i + 1);
        REQUIRE_ASSERT(assertEqScalar(label, testCases[i].expected, got));
    }

    return true;
}

/* More advanced set/map usage for ordering and sequence reasoning */

bool longestConsecutiveSequence_128_tests() {
    vector<LongestConsecutiveSequenceTestCase> testCases = {
        // Examples from problem statement
        {{100,4,200,1,3,2},         4},
        {{0,3,7,2,5,8,4,6,0,1},     9},
        {{1,0,1,2},                 3},
        // Additional complex cases
        {{-1,-2,-3,7,6,5,4,3,2,1},   7},          // 1,2,3,4,5,6,7
        {{10,5,12,3,55,30,4,11,11,5,13,14,6}, 5}  // 10–14
    };

    LongestConsecutiveSequence_128 sol;

    for (size_t i = 0; i < testCases.size(); ++i) {
        int got = sol.longestConsecutive(testCases[i].nums);

        const string label = "Longest Consecutive Sequence 128 Test " + to_string(i + 1);
        REQUIRE_ASSERT(assertEqScalar(label, testCases[i].expected, got));
    }

    return true;
}

/* Frequency buckets and top-k style counting problems */

bool sortCharactersByFrequency_451_tests() {
    vector<SortCharactersByFrequencyTestCase> testCases = {
        {"tree"},       // 'e'x2, 'r','t'
        {"cccaaa"},     // 'c'x3, 'a'x3
        {"Aabb"},       // 'b'x2, 'A','a'
        {"dccbbbaaaa"}, // a4,b3,c2,d1
        {"srrqqqpppp"}  // p4,q3,r2,s1
    };

    SortCharactersByFrequency_451 sol;

    for (size_t i = 0; i < testCases.size(); ++i) {
        const auto& tc = testCases[i];
        string got = sol.frequencySort(tc.input);

        const string label = "Sort Characters by Frequency 451 Test " + to_string(i + 1);
        REQUIRE_ASSERT(assertEqScalar(label, true, isValidFrequencySort(tc.input, got)));
    }

    return true;
}

bool topKFrequentWords_692_tests() {
    vector<TopKFrequentWordsTestCase> testCases = {
        // Examples from problem statement
        {{"i","love","leetcode","i","love","coding"}, 2, {"i","love"}},
        {{"the","day","is","sunny","the","the","the","sunny","is","is"}, 4, {"the","is","sunny","day"}},
        // Additional complex tests
        {{"a","b","c","a","b","c"},                    2, {"a","b"}},                    // all tie, pick lexicographically smallest
        {{"apple","app","apple","banana","banana","app","banana","car"}, 3, {"banana","app","apple"}}, // freq tie + lex order
        {{"z","y","z","x","y"},                       3, {"y","z","x"}}                // z,y freq tie, x last
    };

    TopKFrequentWords_692 sol;

    for (size_t i = 0; i < testCases.size(); ++i) {
        auto got = sol.topKFrequent(testCases[i].words, testCases[i].k);

        const string label =
            "Top K Frequent Words 692 Test " + to_string(i + 1) +
            " (k=" + to_string(testCases[i].k) + ")";
        REQUIRE_ASSERT(assertEqStrings(label, testCases[i].expected, got)); // exact order matters
    }

    return true;
}

/* Aggregation and pattern counting over grouped event data */

bool analyzeUserWebsiteVisitPattern_1152_tests() {
    vector<AnalyzeUserWebsiteVisitPatternTestCase> testCases = {
        // Example 1 (From Problem Statement)
        {
            {"joe", "joe", "joe", "james", "james", "james", "james", "mary", "mary", "mary"},
            {1, 2, 3, 4, 5, 6, 7, 8, 9, 10},
            {"home", "about", "career", "home", "cart", "maps", "home", "home", "about", "career"},
            {"home", "about", "career"}
        },
        // Example 2 (From Problem Statement)
        {
            {"ua", "ua", "ua", "ub", "ub", "ub"},
            {1, 2, 3, 4, 5, 6},
            {"a", "b", "a", "a", "b", "c"},
            {"a", "b", "a"}
        },
        // Corner Case: Only one user with exactly three visits
        {
            {"alice", "alice", "alice"},
            {1, 2, 3},
            {"x", "y", "z"},
            {"x", "y", "z"}
        },
        // Large Complex Case: Multiple users with different patterns
        {
            {"u1", "u1", "u1", "u1", "u2", "u2", "u2", "u3", "u3", "u3", "u3", "u3"},
            {1, 2, 3, 4, 5, 6, 7, 1, 2, 3, 4, 5},
            {"alpha", "beta", "gamma", "delta", "alpha", "beta", "gamma", "beta", "gamma", "alpha", "delta", "beta"},
            {"alpha", "beta", "gamma"}
        },
        // Another more complex test
        {
            {"u1", "u1", "u1", "u2", "u2", "u2", "u3", "u3", "u3", "u4", "u4", "u4"},
            {1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3},
            {"home", "about", "career", "home", "about", "career", "home", "career", "about", "career", "about", "home"},
            {"home", "about", "career"}
        },
        // Complex case with a tie, forcing lexicographical sorting
        {
            {"u1", "u1", "u1", "u2", "u2", "u2", "u3", "u3", "u3", "u4", "u4", "u4", "u5", "u5", "u5", "u6", "u6", "u6"},
            {1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3},
            {"alpha", "beta", "gamma", "alpha", "beta", "gamma", "beta", "gamma", "delta",
                "beta", "gamma", "delta", "alpha", "beta", "gamma", "alpha", "beta", "gamma"},
            {"alpha", "beta", "gamma"}  // Lexicographically smaller, tie-breaking case
        }
    };

    AnalyzeUserWebsiteVisitPattern1152 sol;

    for (size_t i = 0; i < testCases.size(); ++i) {
        auto m = sol.mostVisitedPattern_usingMap(
            testCases[i].username, testCases[i].timestamp, testCases[i].website);
        auto h = sol.mostVisitedPattern_usingHashmap(
            testCases[i].username, testCases[i].timestamp, testCases[i].website);

        const string base = "Analyze User Website Visit Pattern 1152 Test " + to_string(i + 1);
        REQUIRE_ASSERT(assertEqStrings(base + " [map]",     testCases[i].expected, m));
        REQUIRE_ASSERT(assertEqStrings(base + " [hashmap]", testCases[i].expected, h));
        REQUIRE_ASSERT(assertEqStrings(base + " [consistency]", m, h));
    }

    return true;
}

/* Hash-based data structure design */

bool designHashMap_706_tests() {
    vector<DesignHashMapTestCase> testCases = {
        // Example 1 (problem statement)
        {
            {"MyHashMap", "put", "put", "get", "get", "put", "get", "remove", "get"},
            {{}, {1, 1}, {2, 2}, {1}, {3}, {2, 1}, {2}, {2}, {2}},
            {nullopt, nullopt, nullopt, 1, -1, nullopt, 1, nullopt, -1}
        },

        // Keys at boundaries + overwrite
        {
            {"MyHashMap", "get", "put", "put", "get", "get", "remove", "get", "put", "get"},
            {{}, {0}, {0, 42}, {1'000'000, 7}, {0}, {1'000'000}, {0}, {0}, {0, 99}, {0}},
            {nullopt, -1, nullopt, nullopt, 42, 7, nullopt, -1, nullopt, 99}
        },

        // Removing missing key should be a no-op
        {
            {"MyHashMap", "put", "put", "remove", "get", "get", "remove", "get"},
            {{}, {5, 10}, {6, 20}, {7}, {5}, {7}, {6}, {6}},
            {nullopt, nullopt, nullopt, nullopt, 10, -1, nullopt, -1}
        },

        // Remove, then re-insert
        {
            {"MyHashMap", "put", "remove", "put", "get", "remove", "get"},
            {{}, {123, 456}, {123}, {123, 789}, {123}, {123}, {123}},
            {nullopt, nullopt, nullopt, nullopt, 789, nullopt, -1}
        },

        // Only gets/removes on a never-inserted key
        {
            {"MyHashMap", "get", "remove", "get"},
            {{}, {999}, {999}, {999}},
            {nullopt, -1, nullopt, -1}
        },
    };

    for (size_t i = 0; i < testCases.size(); ++i) {
        cout << "Running HashMap Test Case " << i + 1 << ":\n";

        MyHashMap hm; // Create once per test case

        for (size_t j = 0; j < testCases[i].operations.size(); ++j) {
            const auto& op  = testCases[i].operations[j];
            const auto& arg = testCases[i].arguments[j];
            const auto& exp = testCases[i].expected[j];

            if (op == "MyHashMap") { continue; } // No-op: hm already exists
            if (op == "put")    { hm.put(arg[0], arg[1]); continue; }
            if (op == "remove") { hm.remove(arg[0]);      continue; }

            if (op == "get") {
                int got = hm.get(arg[0]);
                int expected = exp.value();

                const string label = makeStepLabel("HashMap Case", i, j, op, to_string(arg[0]));
                REQUIRE_ASSERT(assertEqScalar(label, expected, got));
            }
        }

        cout << "\n";
    }

    return true;
}

} // namespace

namespace TestsHashmapsSets {

std::vector<TestRegistry::Entry> getTests() {
    return {
        // Basic membership checks with sets and simple lookups
        TEST(771,  "Jewels and Stones",                    numJewelsAndStones_771_tests),
        TEST(217,  "Contains Duplicate",                   containsDuplicate_217_tests),

        // Frequency counting on characters and values
        TEST(383,  "Ransom Note",                          ransomNote_383_tests),
        TEST(242,  "Valid Anagram",                        validAnagram_242_tests),
        TEST(1189, "Maximum Number of Balloons",           maximumNumberOfBalloons_1189_tests),
        TEST(1207, "Unique Number of Occurrences",         uniqueNumberOfOccurrences_1207_tests),
        TEST(169,  "Majority Element",                     majorityElement_169_tests),

        // Hashmap lookup patterns for complements and associations
        TEST(1,    "Two Sum",                              twoSum_1_tests),

        // Grouping values by a shared hashable signature
        TEST(49,   "Group Anagrams",                       groupAnagrams_49_tests),

        // Using sets/maps to validate constraints and deduplicate states
        TEST(36,   "Valid Sudoku",                         validSudoku_36_tests),

        // More advanced set/map usage for ordering and sequence reasoning
        TEST(128,  "Longest Consecutive Sequence",         longestConsecutiveSequence_128_tests),

        // Frequency buckets and top-k style counting problems
        TEST(451,  "Sort Characters by Frequency",         sortCharactersByFrequency_451_tests),
        TEST(692,  "Top K Frequent Words",                 topKFrequentWords_692_tests),

        // Aggregation and pattern counting over grouped event data
        TEST(1152, "Analyze User Website Visit Pattern",   analyzeUserWebsiteVisitPattern_1152_tests),

        // Hash-based data structure design
        TEST(706,  "Design HashMap",                       designHashMap_706_tests),
    };
}

} // namespace TestsHashmapsSets
