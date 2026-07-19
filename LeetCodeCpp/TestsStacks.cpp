#include "TestsStacks.h"

#include <string>
#include <vector>

#include "TestCases.h"
#include "TestUtils.h"

#include "BaseballGame_682.h"
#include "ValidParentheses_20.h"
#include "EvaluateReversePolishNotation_150.h"

#include "DecodeString_GoogleOnsite.h"

#include "DailyTemperatures_739.h"
#include "LargestRectangleInHistogram_84.h"

#include "MinStack_155.h"

#include "MaximalRectangle_85.h"

using namespace std;
using namespace TestCases;
using namespace TestUtils;

namespace {

/* Basic stack simulation for push/pop-style processing */

static bool baseballGame_682_tests() {
    using namespace TestCases;
    vector<BaseballGameTestCase> testCases = {
        {{"5","2","C","D","+"}, 30},                      // Example 1
        {{"5","-2","4","C","D","9","+","+"}, 27},         // Example 2
        {{"1","C"}, 0},                                   // Example 3
        {{"10"}, 10},                                     // Simple single score
        {{"5","-2","C","C","10"}, 10},                    // Consecutive cancellations then a value
        {{"3","4","+","+"}, 25},                          // Multiple '+' in a row
        {{"-5","D","+"}, -30},                            // Negatives with D and +
        {{"1","C","2","C"}, 0},                           // Ends empty again
        {{"1","2","3","D","+","C","D","+"}, 42},          // Rich sequence with interleaved ops
        {{"-1","-2","+","D","C","C"}, -3},                // Many ops with cancels near the end
        {{"30000","30000","+","D","C"}, 120000},          // Large values near bounds to verify 32-bit-safe math
        {{"1","D","D","C","+"}, 6},                       // Alternating D and C
    };

    BaseballGame_682 sol;

    for (size_t i = 0; i < testCases.size(); ++i) {
        auto ops = testCases[i].operations; // calPoints takes non-const ref
        int got = sol.calPoints(ops);

        const string label = "Baseball Game 682 Test " + to_string(i + 1);
        REQUIRE_ASSERT(assertEqScalar(label, testCases[i].expected, got));
    }

    return true;
}

static bool validParentheses_20_tests() {
    vector<ValidParenthesesTestCase> testCases = {
        {"()", true},
        {"()[]{}", true},
        {"(]", false},
        {"([])", true},
        {"({[(){}[]]})", true} // Additional complex test case
    };

    ValidParentheses_20 solution;

    for (size_t i = 0; i < testCases.size(); ++i) {
        bool got = solution.isValid(testCases[i].input);

        const string label = "Valid Parentheses Test " + to_string(i + 1);
        REQUIRE_ASSERT(assertEqScalar(label, testCases[i].expected, got));
    }

    return true;
}

static bool evaluateReversePolishNotation_150_tests() {
    vector<EvaluateReversePolishNotationTestCase> testCases = {
        {{"2", "1", "+", "3", "*"}, 9},  // Example 1
        {{"4", "13", "5", "/", "+"}, 6}, // Example 2
        {{"10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"}, 22}, // Example 3
        // Additional test cases
        {{"3", "4", "+", "2", "*", "7", "/"}, 2}, // Complex case: (((3+4)*2)/7)
        {{"5", "-2", "4", "+", "*", "3", "+"}, 13} // Complex case: ((5*(-2+4))+3)
    };

    EvaluateReversePolishNotation_150 evaluator;

    for (size_t i = 0; i < testCases.size(); ++i) {
        int got = evaluator.evalRPN(testCases[i].input);

        const string label = "Evaluate RPN Test " + to_string(i + 1);
        REQUIRE_ASSERT(assertEqScalar(label, testCases[i].expected, got));
    }

    return true;
}

/* Stack-based parsing and nested expression decoding */

static bool decodeString_GoogleOnsite_tests() {
    vector<DecodeStringTestCase> testCases = {
        {"ab[cd]{2}",                   "abcdcd"},
        {"def[ab[cd]{2}]{3}ghi",        "defabcdcdabcdcdabcdcdghi"},
        {"x[y[z]{2}w]{3}",              "xyzzwyzzwyzzw"},
        {"[ab]{2}[cd]{2}",              "ababcdcd"},
        {"plain",                       "plain"},
        {"[a]{5}",                      "aaaaa"}
    };

    DecodeString_GoogleOnsite solver;

    for (size_t i = 0; i < testCases.size(); ++i) {
        string got = solver.decode(testCases[i].input);

        const string label = "Decode String (Google Onsite) Test " + to_string(i + 1);
        REQUIRE_ASSERT(assertEqScalar(label, testCases[i].expected, got));
    }

    return true;
}

/* Monotonic stack patterns for next greater / smaller reasoning */

static bool dailyTemperatures_739_tests() {
    vector<DailyTemperaturesTestCase> tests = {
        // Three examples from the problem statement
        {{73,74,75,71,69,72,76,73}, {1,1,4,2,1,1,0,0}},
        {{30,40,50,60},             {1,1,1,0}},
        {{30,60,90},                 {1,1,0}},

        // Three additional, more complex cases
        {{100,99,98,97},             {0,0,0,0}},            // strictly decreasing: no warmer future day
        {{70,70,71},                 {2,1,0}},              // plateau followed by a warmer day
        {{75,71,69,72,76,73,73,74,75},{4,2,1,1,0,2,1,1,0}}  // mixed drops, duplicates, multiple pops
    };

    DailyTemperatures_739 solver;

    for (size_t i = 0; i < tests.size(); ++i) {
        auto got = solver.dailyTemperatures(tests[i].temperatures);

        const string label = "Daily Temperatures 739 Test " + to_string(i + 1);
        REQUIRE_ASSERT(assertEqVIntExact(label, tests[i].expected, got));
    }

    return true;
}

static bool largestRectangleInHistogram_84_tests() {
    vector<LargestRectangleInHistogramTestCase> testCases = {
        // Example 1
        {{2, 1, 5, 6, 2, 3}, 10},
        // Example 2
        {{2, 4}, 4},
        // Additional Test 1: All bars of the same height
        {{1, 1, 1, 1, 1}, 5},
        // Additional Test 2: Decreasing heights
        {{5, 4, 3, 2, 1}, 9},
        // Additional Test 3: Complex case
        {{2, 1, 4, 5, 1, 3, 3}, 8},
        // Additional Test 4: Plateau with equal heights (ties).
        {{1, 2, 3, 3, 3, 1}, 9}
    };

    LargestRectangleInHistogram_84 solution;

    for (size_t i = 0; i < testCases.size(); ++i) {
        int got = solution.largestRectangleArea(testCases[i].heights);

        const string label = "Largest Rectangle Test " + to_string(i + 1);
        REQUIRE_ASSERT(assertEqScalar(label, testCases[i].expected, got));
    }

    return true;
}

/* Stack-backed data structure design */

static bool minStack_155_tests() {
    auto run = [](const vector<pair<string,int>>& ops) {
        MinStack_155 ms;
        vector<int> out;
        for (const auto& [op, val] : ops) {
            if (op == "push") {
                ms.push(val);
            } else if (op == "pop") {
                ms.pop();
            } else if (op == "top") {
                out.push_back(ms.top());
            } else if (op == "getMin") {
                out.push_back(ms.getMin());
            }
        }
        return out;
    };

    vector<MinStackTestCase> tests = {
        // Example from the prompt
        {
            {{"push",-2},{"push",0},{"push",-3},{"getMin",0},{"pop",0},{"top",0},{"getMin",0}},
            {-3, 0, -2}
        },
        // Monotonic decreasing pushes, verify min changes on pops
        {
            {{"push",5},{"push",3},{"push",1},{"getMin",0},{"pop",0},{"getMin",0},{"pop",0},{"getMin",0},{"top",0}},
            {1, 3, 5, 5}
        },
        // Duplicated minima; ensure min persists through equal values
        {
            {{"push",5},{"push",5},{"push",-1},{"push",-1},{"push",7},
            {"getMin",0},{"pop",0},{"getMin",0},{"pop",0},{"getMin",0},{"pop",0},{"getMin",0},{"top",0}},
            {-1, -1, -1, 5, 5}
        },
        // Interleaved stress: push/pop/top/getMin in mixed order
        {
            {{"push",2},{"push",0},{"push",3},{"push",0},{"getMin",0}, // min=0
            {"pop",0},{"getMin",0},                                   // min=0
            {"pop",0},{"getMin",0},                                   // min=0
            {"pop",0},{"getMin",0}},                                  // min=2
            {0, 0, 0, 2}
        },
        // Single element edge pattern
        {
            {{"push",42},{"getMin",0},{"top",0},{"pop",0}},
            {42, 42}
        }
    };

    for (size_t i = 0; i < tests.size(); ++i) {
        auto got = run(tests[i].operations);

        const string label = "Min Stack 155 Test " + to_string(i + 1);
        REQUIRE_ASSERT(assertEqVIntExact(label, tests[i].expected, got));
    }

    return true;
}

/* Matrix reduction to a histogram-based stack problem */

static bool maximalRectangle_85_tests() {
    vector<MaximalRectangleTestCase> testCases = {
        // ── three examples from the problem statement ──
        {{{'1','0','1','0','0'},
            {'1','0','1','1','1'},
            {'1','1','1','1','1'},
            {'1','0','0','1','0'}}, 6},
        {{{'0'}}, 0},
        {{{'1'}}, 1},

        // ── additional, larger & denser cases ──
        // 1) 8×8 block of 1 s → area 64
        {vector<vector<char>>(8, vector<char>(8, '1')), 64},

        // 2) 4×10 mixed grid (largest 5×4 block) → area 20
        {{{'1','1','1','1','1','0','0','0','1','1'},
            {'1','1','1','1','1','1','1','1','1','0'},
            {'1','1','1','1','1','1','1','1','0','0'},
            {'1','1','1','1','1','0','0','0','0','0'}}, 20}
    };

    MaximalRectangle_85 solver;

    for (size_t i = 0; i < testCases.size(); ++i) {
        int got = solver.maximalRectangle(testCases[i].matrix);

        const string label = "Maximal Rectangle 85 Test " + to_string(i + 1);
        REQUIRE_ASSERT(assertEqScalar(label, testCases[i].expected, got));
    }

    return true;
}

} // namespace

namespace TestsStacks {

std::vector<TestRegistry::Entry> getTests() {
    return {
        // Basic stack simulation for push/pop-style processing
        TEST(682,  "Baseball Game",                     baseballGame_682_tests),
        TEST(20,   "Valid Parentheses",                 validParentheses_20_tests),
        TEST(150,  "Evaluate Reverse Polish Notation",  evaluateReversePolishNotation_150_tests),

        // Stack-based parsing and nested expression decoding
        TEST(0,    "Decode String (Google Onsite)",     decodeString_GoogleOnsite_tests),

        // Monotonic stack patterns for next greater / smaller reasoning
        TEST(739,  "Daily Temperatures",                dailyTemperatures_739_tests),
        TEST(84,   "Largest Rectangle in Histogram",    largestRectangleInHistogram_84_tests),

        // Stack-backed data structure design
        TEST(155,  "Min Stack",                         minStack_155_tests),

        // Matrix reduction to a histogram-based stack problem
        TEST(85,   "Maximal Rectangle",                 maximalRectangle_85_tests),
    };
}

} // namespace TestsStacks
