#include "TestsSlidingWindow.h"

#include <string>
#include <vector>

#include "TestCases.h"
#include "TestUtils.h"

#include "MaximumAverageSubarrayI_643.h"
#include "MaxConsecutiveOnesIII_1004.h"
#include "MinimumSizeSubarraySum_209.h"
#include "LongestSubstringWithoutRepeatingCharacters_3.h"
#include "LongestRepeatingCharacterReplacement_424.h"
#include "PermutationInString_567.h"

using namespace std;
using namespace TestCases;
using namespace TestUtils;

namespace {

/* Fixed-size windows with rolling updates */

static bool maximumAverageSubarrayI_643_tests() {
    vector<MaximumAverageSubarrayITestCase> testCases = {
        // problem examples
        {{1, 12, -5, -6, 50, 3}, 4, 12.75},
        {{5},                    1,  5.0},

        // additional complex tests
        {{1,2,3,4,5,6,7,8,9,10},   5,  8.0},          // increasing sequence
        {{-5,-10,-3,-4,-1,-2},     3, -2.3333333333}, // all negatives
        {{0,100,0,100,0,100},      2,  50.0}          // alternating highs/lows
    };

    MaximumAverageSubarrayI_643 sol;

    for (size_t i = 0; i < testCases.size(); ++i) {
        double got = sol.findMaxAverage(testCases[i].nums, testCases[i].k);

        const string label = "Max Avg Subarray I 643 Test " + to_string(i + 1);
        REQUIRE_ASSERT(assertApprox(label, testCases[i].expected, got));
    }

    return true;
}

/* Expanding and shrinking windows with a running constraint */

static bool maxConsecutiveOnesIII_1004_tests() {
    vector<MaxConsecutiveOnesIIITestCase> testCases = {
        // two examples from the problem statement:
        {{1,1,1,0,0,0,1,1,1,1,0},           2,  6},
        {{0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1}, 3, 10},

        // three more:
        {{1,0,1,0,1,0,1},                   1,  3},  // alternating
        {{1,1,0,0,1,1,1,0,1},               2,  7},  // mixed blocks
        {{0,0,0,0},                         0,  0}   // all zeros, no flips
    };

    MaxConsecutiveOnesIII_1004 sol;

    for (size_t i = 0; i < testCases.size(); ++i) {
        int got = sol.longestOnes(testCases[i].nums, testCases[i].k);

        const string label = "Max Consecutive Ones III 1004 Test " + to_string(i + 1);
        REQUIRE_ASSERT(assertEqScalar(label, testCases[i].expected, got));
    }

    return true;
}

static bool minimumSizeSubarraySum_209_tests() {
    vector<MinimumSizeSubarraySumTestCase> testCases = {
        // 3 examples from the problem statement
        {7,  {2, 3, 1, 2, 4, 3},             2},
        {4,  {1, 4, 4},                      1},
        {11, {1, 1, 1, 1, 1, 1, 1, 1},       0},

        // 2 additional, more demanding cases
        //  – overlapping windows, answer = 2  (10+7)
        {15, {5, 1, 3, 5, 10, 7, 4, 9, 2, 8}, 2},
        //  – strictly increasing array, answer = 3  (8+9+10)
        {25, {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, 3}
    };

    MinimumSizeSubarraySum_209 sol;

    for (size_t i = 0; i < testCases.size(); ++i) {
        int got = sol.minSubArrayLen(testCases[i].target, testCases[i].nums);

        const string label = "Minimum Size Subarray Sum 209 Test " + to_string(i + 1);
        REQUIRE_ASSERT(assertEqScalar(label, testCases[i].expected, got));
    }

    return true;
}

/* Variable-size windows for distinctness and replacement limits */

static bool longestSubstringWithoutRepeatingCharacters_3_tests() {
    vector<LongestSubstringWithoutRepeatingCharactersTestCase> testCases = {
        {"abcabcbb", 3},  // example 1
        {"bbbbb",    1},  // example 2
        {"pwwkew",   3},  // example 3
        // two more complex cases:
        {"dvdf",     3},  // "vdf"
        {"anviaj",   5}   // "nviaj"
    };

    LongestSubstringWithoutRepeatingCharacters_3 sol;

    for (size_t i = 0; i < testCases.size(); ++i) {
        int got = sol.lengthOfLongestSubstring(testCases[i].input);

        const string label = "Longest Substring 3 Test " + to_string(i + 1);
        REQUIRE_ASSERT(assertEqScalar(label, testCases[i].expected, got));
    }

    return true;
}

static bool longestRepeatingCharacterReplacement_424_tests() {
    vector<LongestRepeatingCharacterReplacementTestCase> testCases = {
        {"ABAB",      2, 4},  // Example 1
        {"AABABBA",   1, 4},  // Example 2
        {"BABABA",    3, 6},  // Transform 3 'A's into 'B's
        {"ABCDE",     2, 3},  // Best substring length 3 by 2 changes
        {"ABBBBAA",   2, 6},  // 6-length window after 2 changes
        {"AAACCCCAC", 1, 6},  // Example of sliding window where maxFreq lags; still yields best=6
    };

    LongestRepeatingCharacterReplacement_424 sol;

    for (size_t i = 0; i < testCases.size(); ++i) {
        int got = sol.characterReplacement(testCases[i].input, testCases[i].k);

        const string label = "Character Replacement 424 Test " + to_string(i + 1);
        REQUIRE_ASSERT(assertEqScalar(label, testCases[i].expected, got));
    }

    return true;
}

/* Window matching with character-frequency requirements */

static bool permutationInString_567_tests() {
    vector<PermutationInStringTestCase> testCases = {
        {"ab",   "eidbaooo",          true},
        {"ab",   "eidboaoo",          false},
        {"adc",  "dcda",              true},
        {"xyz",  "afdgzyxksldfm",     true},
        {"abcd", "abc",               false}
    };

    PermutationInString_567 sol;

    for (size_t i = 0; i < testCases.size(); ++i) {
        const bool gotFullCompare = sol.checkInclusion_fullCompare(testCases[i].s1, testCases[i].s2);
        const bool gotMatchesCounter = sol.checkInclusion_matchesCounter(testCases[i].s1, testCases[i].s2);

        const string base = "Permutation in String 567 Test " + to_string(i + 1);
        REQUIRE_ASSERT(assertEqScalar(base + " [fullCompare]", testCases[i].expected, gotFullCompare));
        REQUIRE_ASSERT(assertEqScalar(base + " [matchesCounter]", testCases[i].expected, gotMatchesCounter));
    }

    return true;
}

} // namespace

namespace TestsSlidingWindow {

std::vector<TestRegistry::Entry> getTests() {
    return {
        // Fixed-size windows with rolling updates
        TEST(643,  "Maximum Average Subarray I",
             maximumAverageSubarrayI_643_tests),

        // Expanding and shrinking windows with a running constraint
        TEST(1004, "Max Consecutive Ones III",
             maxConsecutiveOnesIII_1004_tests),
        TEST(209,  "Minimum Size Subarray Sum",
             minimumSizeSubarraySum_209_tests),

        // Variable-size windows for distinctness and replacement limits
        TEST(3,    "Longest Substring Without Repeating Characters",
             longestSubstringWithoutRepeatingCharacters_3_tests),
        TEST(424,  "Longest Repeating Character Replacement",
             longestRepeatingCharacterReplacement_424_tests),

        // Window matching with character-frequency requirements
        TEST(567,  "Permutation in String",
             permutationInString_567_tests),
    };
}

} // namespace TestsSlidingWindow
