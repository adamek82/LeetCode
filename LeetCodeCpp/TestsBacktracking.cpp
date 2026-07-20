#include "TestsBacktracking.h"

#include <string>
#include <vector>

#include "TestCases.h"
#include "TestUtils.h"

#include "Subsets_78.h"
#include "Permutations_46.h"
#include "Combinations_77.h"

#include "LetterCombinations_17.h"
#include "CombinationSum_39.h"
#include "GenerateParentheses_22.h"

#include "WordSearch_79.h"
#include "SudokuSolver_37.h"

using namespace std;
using namespace TestCases;
using namespace TestUtils;

namespace {

/* Basic recursive generation of subsets, combinations, and permutations */

bool subsets_78_tests() {
    vector<SubsetsTestCase> tests = {
        // Example 1 (mask order for the bitmask method)
        {{1,2,3}, { {}, {1}, {2}, {1,2}, {3}, {1,3}, {2,3}, {1,2,3} }},
        // Example 2
        {{0},     { {}, {0} }},
        // Additional
        {{5,6},   { {}, {5}, {6}, {5,6} }},
        {{-1,2},  { {}, {-1}, {2}, {-1,2} }},
    };

    Subsets_78 sol;

    for (size_t i = 0; i < tests.size(); ++i) {
        const auto& tc = tests[i];
        const string base = "Subsets 78 Test " + to_string(i + 1);

        auto bitmaskInput = tc.nums;
        vector<vector<int>> bitmaskGot = sol.subsets_bitmask(bitmaskInput);
        REQUIRE_ASSERT(assertEqVVIntExact(base + " [bitmask]", tc.expected, bitmaskGot));

        auto prefixInput = tc.nums;
        vector<vector<int>> prefixGot = sol.subsets_recursive_prefix(prefixInput);
        REQUIRE_ASSERT(assertEqVVIntAnyOrder(base + " [recursive prefix]", tc.expected, prefixGot));

        auto binaryInput = tc.nums;
        vector<vector<int>> binaryGot = sol.subsets_recursive_binary(binaryInput);
        REQUIRE_ASSERT(assertEqVVIntAnyOrder(base + " [recursive binary]", tc.expected, binaryGot));
    }

    return true;
}

bool combinations_77_tests() {
    vector<CombinationsTestCase> tests = {
        {4, 2, {{1,2},{1,3},{1,4},{2,3},{2,4},{3,4}}},
        {1, 1, {{1}}},
        {3, 1, {{1},{2},{3}}},
        {3, 3, {{1,2,3}}},
        {5, 3, {{1,2,3},{1,2,4},{1,2,5},{1,3,4},{1,3,5},
                {1,4,5},{2,3,4},{2,3,5},{2,4,5},{3,4,5}}},
    };

    Combinations_77 sol;

    struct Impl {
        string name;
        function<vector<vector<int>>(const CombinationsTestCase&)> run;
    };

    const vector<Impl> impls = {
        {
            "PickNext",
            [&](const CombinationsTestCase& tc) {
                return sol.combinePickNext(tc.n, tc.k);
            }
        },
        {
            "TakeSkip",
            [&](const CombinationsTestCase& tc) {
                return sol.combineTakeSkip(tc.n, tc.k);
            }
        },
    };

    for (size_t i = 0; i < tests.size(); ++i) {
        const auto& tc = tests[i];
        const string base = "Combinations 77 Test " + to_string(i + 1);

        for (const auto& impl : impls) {
            vector<vector<int>> got = impl.run(tc);

            REQUIRE_ASSERT(assertEqVVIntAnyOrder(
                base + " [" + impl.name + "]",
                tc.expected,
                got));
        }
    }

    return true;
}

bool permutations_46_tests() {
    vector<PermutationsTestCase> tests = {
        {{1,2,3}, {{1,2,3},{1,3,2},{2,1,3},{2,3,1},{3,1,2},{3,2,1}}},
        {{0,1},   {{0,1},{1,0}}},
        {{1},     {{1}}},
        {{-1,2},  {{-1,2},{2,-1}}},
    };

    Permutations_46 sol;

    for (size_t i = 0; i < tests.size(); ++i) {
        auto in  = tests[i].nums;               // method takes non-const ref
        auto got = sol.permute(in);

        const string label = "Permutations 46 Test " + to_string(i + 1);
        REQUIRE_ASSERT(assertEqVVIntPermutations(label, tests[i].expected, got));
    }

    return true;
}

/* Backtracking with constraints and incremental choice building */

bool letterCombinations_17_tests() {
    vector<LetterCombinationsTestCase> tests = {
        {"23", {"ad","ae","af","bd","be","bf","cd","ce","cf"}},
        {"",   {}},
        {"2",  {"a","b","c"}},
        {"9",  {"w","x","y","z"}},
        {"79", {"pw","px","py","pz","qw","qx","qy","qz",
                "rw","rx","ry","rz","sw","sx","sy","sz"}}
    };

    LetterCombinations_17 sol;

    for (size_t i = 0; i < tests.size(); ++i) {
        auto got = sol.letterCombinations(tests[i].digits);

        const string label = "Letter Combinations 17 Test " + to_string(i + 1);
        REQUIRE_ASSERT(assertEqStringsAnyOrder(label, tests[i].expected, got));
    }

    return true;
}

bool generateParentheses_22_tests() {
    vector<GenerateParenthesesTestCase> tests = {
        {3, {"((()))","(()())","(())()","()(())","()()()"}},
        {1, {"()"}},
        {2, {"(())","()()"}},
        {4, {"(((())))","((()()))","((())())","((()))()",
            "(()(()))","(()()())","(()())()","(())(())","(())()()",
            "()((()))","()(()())","()(())()","()()(())","()()()()"}}
    };

    GenerateParentheses_22 sol;

    for (size_t i = 0; i < tests.size(); ++i) {
        auto got = sol.generateParenthesis(tests[i].n);

        const string label = "Generate Parentheses 22 Test " + to_string(i + 1);
        REQUIRE_ASSERT(assertEqStringsAnyOrder(label, tests[i].expected, got));
    }

    return true;
}

bool combinationSum_39_tests() {
    vector<CombinationSumTestCase> tests = {
        {{2,3,6,7}, 7, {{2,2,3},{7}}},
        {{2,3,5},   8, {{2,2,2,2},{2,3,3},{3,5}}},
        {{2},       1, {}},
        {{2},       2, {{2}}},
        {{2,4,6},   6, {{2,2,2},{2,4},{6}}},
        {{8,7,4,3},11, {{3,4,4},{3,8},{7,4}}}
    };

    CombinationSum_39 sol;

    for (size_t i = 0; i < tests.size(); ++i) {
        auto cand = tests[i].candidates;       // method takes non-const ref
        auto got  = sol.combinationSum(cand, tests[i].target);

        const string label = "Combination Sum 39 Test " + to_string(i + 1);
        REQUIRE_ASSERT(assertEqVVIntAnyOrder(label, tests[i].expected, got));
    }

    return true;
}

/* Constraint-based board backtracking */

bool sudokuSolver_37_tests() {
    vector<SudokuSolverTestCase> testCases = {
        // Example 1: classic LeetCode example
        {
            {
                {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
                {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
                {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
                {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
                {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
                {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
                {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
                {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
                {'.', '.', '.', '.', '8', '.', '.', '7', '9'}
            },
            {
                {'5', '3', '4', '6', '7', '8', '9', '1', '2'},
                {'6', '7', '2', '1', '9', '5', '3', '4', '8'},
                {'1', '9', '8', '3', '4', '2', '5', '6', '7'},
                {'8', '5', '9', '7', '6', '1', '4', '2', '3'},
                {'4', '2', '6', '8', '5', '3', '7', '9', '1'},
                {'7', '1', '3', '9', '2', '4', '8', '5', '6'},
                {'9', '6', '1', '5', '3', '7', '2', '8', '4'},
                {'2', '8', '7', '4', '1', '9', '6', '3', '5'},
                {'3', '4', '5', '2', '8', '6', '1', '7', '9'}
            }
        },

        // Example 2: already solved board
        {
            {
                {'5', '3', '4', '6', '7', '8', '9', '1', '2'},
                {'6', '7', '2', '1', '9', '5', '3', '4', '8'},
                {'1', '9', '8', '3', '4', '2', '5', '6', '7'},
                {'8', '5', '9', '7', '6', '1', '4', '2', '3'},
                {'4', '2', '6', '8', '5', '3', '7', '9', '1'},
                {'7', '1', '3', '9', '2', '4', '8', '5', '6'},
                {'9', '6', '1', '5', '3', '7', '2', '8', '4'},
                {'2', '8', '7', '4', '1', '9', '6', '3', '5'},
                {'3', '4', '5', '2', '8', '6', '1', '7', '9'}
            },
            {
                {'5', '3', '4', '6', '7', '8', '9', '1', '2'},
                {'6', '7', '2', '1', '9', '5', '3', '4', '8'},
                {'1', '9', '8', '3', '4', '2', '5', '6', '7'},
                {'8', '5', '9', '7', '6', '1', '4', '2', '3'},
                {'4', '2', '6', '8', '5', '3', '7', '9', '1'},
                {'7', '1', '3', '9', '2', '4', '8', '5', '6'},
                {'9', '6', '1', '5', '3', '7', '2', '8', '4'},
                {'2', '8', '7', '4', '1', '9', '6', '3', '5'},
                {'3', '4', '5', '2', '8', '6', '1', '7', '9'}
            }
        },

        // Example 3: one missing value
        {
            {
                {'5', '3', '4', '6', '7', '8', '9', '1', '.'},
                {'6', '7', '2', '1', '9', '5', '3', '4', '8'},
                {'1', '9', '8', '3', '4', '2', '5', '6', '7'},
                {'8', '5', '9', '7', '6', '1', '4', '2', '3'},
                {'4', '2', '6', '8', '5', '3', '7', '9', '1'},
                {'7', '1', '3', '9', '2', '4', '8', '5', '6'},
                {'9', '6', '1', '5', '3', '7', '2', '8', '4'},
                {'2', '8', '7', '4', '1', '9', '6', '3', '5'},
                {'3', '4', '5', '2', '8', '6', '1', '7', '9'}
            },
            {
                {'5', '3', '4', '6', '7', '8', '9', '1', '2'},
                {'6', '7', '2', '1', '9', '5', '3', '4', '8'},
                {'1', '9', '8', '3', '4', '2', '5', '6', '7'},
                {'8', '5', '9', '7', '6', '1', '4', '2', '3'},
                {'4', '2', '6', '8', '5', '3', '7', '9', '1'},
                {'7', '1', '3', '9', '2', '4', '8', '5', '6'},
                {'9', '6', '1', '5', '3', '7', '2', '8', '4'},
                {'2', '8', '7', '4', '1', '9', '6', '3', '5'},
                {'3', '4', '5', '2', '8', '6', '1', '7', '9'}
            }
        },

        // Sparse board with a unique solution.
        //
        // A previous version used a 17-clue Sudoku, which is close to the hardest
        // realistic input for plain backtracking. It was correct, but too slow in
        // Debug builds. This case stays sparse enough to exercise deeper recursion,
        // while keeping the test suite reasonably fast.
        {
            {
                {'.', '.', '.', '7', '.', '.', '.', '1', '.'},
                {'4', '.', '7', '.', '1', '.', '9', '.', '.'},
                {'.', '2', '.', '9', '.', '.', '.', '.', '.'},
                {'.', '.', '.', '.', '5', '.', '4', '.', '7'},
                {'.', '.', '8', '.', '.', '.', '3', '.', '.'},
                {'.', '.', '1', '.', '9', '.', '.', '2', '.'},
                {'3', '.', '.', '4', '.', '.', '2', '.', '.'},
                {'.', '5', '.', '1', '.', '.', '.', '.', '3'},
                {'.', '.', '.', '8', '.', '6', '.', '.', '.'}
            },
            {
                {'6', '9', '3', '7', '8', '4', '5', '1', '2'},
                {'4', '8', '7', '5', '1', '2', '9', '3', '6'},
                {'1', '2', '5', '9', '6', '3', '8', '7', '4'},
                {'9', '3', '2', '6', '5', '1', '4', '8', '7'},
                {'5', '6', '8', '2', '4', '7', '3', '9', '1'},
                {'7', '4', '1', '3', '9', '8', '6', '2', '5'},
                {'3', '1', '9', '4', '7', '5', '2', '6', '8'},
                {'8', '5', '6', '1', '2', '9', '7', '4', '3'},
                {'2', '7', '4', '8', '3', '6', '1', '5', '9'}
            }
        }
    };

    SudokuSolver_37 solver;

    for (size_t i = 0; i < testCases.size(); ++i) {
        const auto& tc = testCases[i];
        const string base = "Sudoku Solver 37 Test " + to_string(i + 1);

        auto plainBoard = tc.input;
        solver.solveSudoku_PlainBacktracking(plainBoard);
        REQUIRE_ASSERT(assertEqScalar(
            base + " [PlainBacktracking]",
            true,
            plainBoard == tc.expected));

        auto bitMasksBoard = tc.input;
        solver.solveSudoku_BitMasks(bitMasksBoard);
        REQUIRE_ASSERT(assertEqScalar(
            base + " [BitMasks]",
            true,
            bitMasksBoard == tc.expected));
    }

    return true;
}

/* Backtracking over a 2D search space with visited-state control */

bool wordSearch_79_tests() {
    vector<WordSearchTestCase> testCases = {
        // Example 1 from problem statement
        {{{'A', 'B', 'C', 'E'},
            {'S', 'F', 'C', 'S'},
            {'A', 'D', 'E', 'E'}},
            "ABCCED",
            true},

        // Example 2 from problem statement
        {{{'A', 'B', 'C', 'E'},
            {'S', 'F', 'C', 'S'},
            {'A', 'D', 'E', 'E'}},
            "SEE",
            true},

        // Example 3 from problem statement
        {{{'A', 'B', 'C', 'E'},
            {'S', 'F', 'C', 'S'},
            {'A', 'D', 'E', 'E'}},
            "ABCB",
            false},

        // Additional complex test case 1
        {{{'A', 'B', 'C', 'E', 'F', 'G'},
            {'H', 'I', 'J', 'K', 'L', 'M'},
            {'N', 'O', 'P', 'Q', 'R', 'S'},
            {'T', 'U', 'V', 'W', 'X', 'Y'},
            {'Z', 'A', 'B', 'C', 'D', 'E'}},
            "ABCEFGMLKJIHNT",
            true},

        // Additional complex test case 2
        {{{'A', 'B', 'C', 'E', 'F', 'G'},
            {'H', 'I', 'J', 'K', 'L', 'M'},
            {'N', 'O', 'P', 'Q', 'R', 'S'},
            {'T', 'U', 'V', 'W', 'X', 'Y'},
            {'Z', 'A', 'B', 'C', 'D', 'E'}},
            "ZYXWVUTSRQPONMLK",
            false}};

    WordSearch_79 solution;

    for (size_t i = 0; i < testCases.size(); ++i) {
        bool got = solution.exist(testCases[i].board, testCases[i].word);

        const string label = "Word Search Test " + to_string(i + 1);
        REQUIRE_ASSERT(assertEqScalar(label, testCases[i].expected, got));
    }

    return true;
}

} // namespace

namespace TestsBacktracking {

std::vector<TestRegistry::Entry> getTests() {
    return {
        // Basic subset/permutation generation
        TEST(78, "Subsets",       subsets_78_tests),
        TEST(46, "Permutations",  permutations_46_tests),
        TEST(77, "Combinations",  combinations_77_tests),

        // Backtracking over choice strings and constrained combinations
        TEST(17, "Letter Combinations",  letterCombinations_17_tests),
        TEST(39, "Combination Sum",      combinationSum_39_tests),
        TEST(22, "Generate Parentheses", generateParentheses_22_tests),

        // Backtracking on boards / grids
        TEST(79, "Word Search",   wordSearch_79_tests),
        TEST(37, "Sudoku Solver", sudokuSolver_37_tests),
    };
}

} // namespace TestsBacktracking
