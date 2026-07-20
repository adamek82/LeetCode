#include "TestsOther.h"

#include <string>
#include <vector>

#include "TestCases.h"
#include "TestUtils.h"

#include "FindCelebrity_277.h"
#include "ValidNumber_65.h"

using namespace std;
using namespace TestCases;
using namespace TestUtils;

namespace {

/* Problems that do not fit cleanly into the main technique-based categories */

static bool findCelebrity_277_tests() {
    vector<FindCelebrityTestCase> testCases = {
        // 1 is the celebrity
        {{{0, 1}, {0, 0}}, 1},

        // Single person is trivially the celebrity
        {{{0}}, 0},

        // No celebrity: 0 and 1 know each other
        {{{0, 1}, {1, 0}}, -1},

        // 2 is the celebrity
        {
            {
                {0, 1, 1},
                {0, 0, 1},
                {0, 0, 0},
            },
            2,
        },

        // No celebrity: candidate 2 knows 0
        {
            {
                {0, 1, 1},
                {0, 0, 1},
                {1, 0, 0},
            },
            -1,
        },

        // 3 is the celebrity
        {
            {
                {0, 1, 1, 1},
                {0, 0, 1, 1},
                {0, 0, 0, 1},
                {0, 0, 0, 0},
            },
            3,
        },

        // Larger case: 6 is the celebrity
        {
            {
                {0, 1, 1, 1, 1, 1, 1},
                {0, 0, 1, 1, 1, 1, 1},
                {0, 0, 0, 1, 1, 1, 1},
                {0, 0, 0, 0, 1, 1, 1},
                {0, 0, 0, 0, 0, 1, 1},
                {0, 0, 0, 0, 0, 0, 1},
                {0, 0, 0, 0, 0, 0, 0},
            },
            6,
        },
    };

    for (size_t i = 0; i < testCases.size(); ++i) {
        const auto& tc = testCases[i];

        FindCelebrity_277 sol;
        sol.knowsMatrix = tc.matrix;

        int got = sol.findCelebrity(static_cast<int>(tc.matrix.size()));

        const string label = "Find Celebrity 277 Test " + to_string(i + 1);
        REQUIRE_ASSERT(assertEqScalar(label, tc.expected, got));
    }

    return true;
}

static bool validNumber_65_tests() {
    vector<ValidNumberTestCase> testCases = {
        // Valid integers / decimals
        {"0", true},
        {"2", true},
        {"0089", true},
        {"-0.1", true},
        {"+3.14", true},
        {"4.", true},
        {"-.9", true},

        // Valid exponent forms
        {"2e10", true},
        {"-90E3", true},
        {"3e+7", true},
        {"+6e-1", true},
        {"53.5e93", true},
        {"-123.456e789", true},

        // Invalid forms
        {"e", false},
        {".", false},
        {"abc", false},
        {"1a", false},
        {"99e2.5", false},
        {"1e", false},
        {"e3", false},
        {"--6", false},
        {"-+3", false},
        {"95a54e53", false},
        {"+.", false},
        {".e1", false},
        {"6e6.5", false},
    };

    ValidNumber_65 solver;

    for (size_t i = 0; i < testCases.size(); ++i) {
        const auto& tc = testCases[i];

        bool got = solver.isNumber(tc.input);

        const string label =
            "Valid Number 65 Test " + to_string(i + 1) +
            " [\"" + tc.input + "\"]";
        REQUIRE_ASSERT(assertEqScalar(label, tc.expected, got));
    }

    return true;
}

} // namespace

namespace TestsOther {

std::vector<TestRegistry::Entry> getTests() {
    return {
        // Problems that do not fit cleanly into the main technique-based categories
        TEST(277, "Find the Celebrity", findCelebrity_277_tests),
        TEST(65,  "Valid Number",       validNumber_65_tests),
    };
}

} // namespace TestsOther
