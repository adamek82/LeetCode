#include "TestsDesign.h"

#include <initializer_list>
#include <string>
#include <vector>

#include "TestCases.h"
#include "TestUtils.h"

#include "AllOOneDataStructure_432.h"
#include "ExamRoom_855.h"
#include "ShuffleAnArray_384.h"

using namespace std;
using namespace TestCases;
using namespace TestUtils;

namespace {

bool allOOneDataStructure_432_tests() {
    auto expectMaxMin = [](const string& label,
                        AllOOneDataStructure_432& ds,
                        initializer_list<string> maxKeys,
                        initializer_list<string> minKeys) {
        return assertMaxMin(
            label,
            [&] { return ds.getMaxKey(); },
            [&] { return ds.getMinKey(); },
            maxKeys,
            minKeys);
    };

    // Basic case
    AllOOneDataStructure_432 ds1;
    ds1.inc("hello");
    ds1.inc("hello");

    REQUIRE_ASSERT(expectMaxMin(
        "AllOOne 432 Test 1 [hello twice]",
        ds1,
        {"hello"},
        {"hello"}));

    ds1.inc("leet");

    REQUIRE_ASSERT(expectMaxMin(
        "AllOOne 432 Test 1 [add leet]",
        ds1,
        {"hello"},
        {"leet"}));

    // Ties
    AllOOneDataStructure_432 ds2;
    ds2.inc("foo");
    ds2.inc("bar");
    ds2.inc("bar");

    REQUIRE_ASSERT(expectMaxMin(
        "AllOOne 432 Test 2 [bar ahead]",
        ds2,
        {"bar"},
        {"foo"}));

    ds2.inc("foo");

    REQUIRE_ASSERT(expectMaxMin(
        "AllOOne 432 Test 2 [tie at 2]",
        ds2,
        {"foo", "bar"},
        {"foo", "bar"}));

    // dec() and removal
    AllOOneDataStructure_432 ds3;
    ds3.inc("a");
    ds3.inc("a");
    ds3.inc("a");
    ds3.inc("b");
    ds3.inc("c");

    REQUIRE_ASSERT(expectMaxMin(
        "AllOOne 432 Test 3 [a=3, b=c=1]",
        ds3,
        {"a"},
        {"b", "c"}));

    ds3.dec("a");
    ds3.dec("a");
    ds3.dec("a");

    REQUIRE_ASSERT(expectMaxMin(
        "AllOOne 432 Test 3 [a removed]",
        ds3,
        {"b", "c"},
        {"b", "c"}));

    return true;
}

bool examRoom_855_tests() {
    auto init = [](int n) {
        return ExamRoomTestCase{
            {"ExamRoom"},
            {{n}},
            {nullopt},
        };
    };

    auto appendSeat = [](ExamRoomTestCase& tc, int expectedSeat) {
        tc.operations.push_back("seat");
        tc.arguments.push_back({});
        tc.expected.push_back(expectedSeat);
    };

    auto appendLeave = [](ExamRoomTestCase& tc, int seatNo) {
        tc.operations.push_back("leave");
        tc.arguments.push_back({seatNo});
        tc.expected.push_back(nullopt);
    };

    vector<ExamRoomTestCase> testCases;

    {
        // Exact sequence from the statement
        auto tc = init(10);

        appendSeat(tc, 0);
        appendSeat(tc, 9);
        appendSeat(tc, 4);
        appendSeat(tc, 2);
        appendLeave(tc, 4);
        appendSeat(tc, 5);

        testCases.push_back(move(tc));
    }

    {
        // Edges cleared and re-filled; checks tie-breaking and edges
        auto tc = init(8);

        appendSeat(tc, 0);
        appendSeat(tc, 7);
        appendSeat(tc, 3);
        appendLeave(tc, 0);
        appendLeave(tc, 7);
        appendSeat(tc, 7);
        appendSeat(tc, 0);
        appendSeat(tc, 5);

        testCases.push_back(move(tc));
    }

    {
        // Interleaved interior leaves and inserts; exercises mid-splits
        auto tc = init(10);

        appendSeat(tc, 0);
        appendSeat(tc, 9);
        appendSeat(tc, 4);
        appendSeat(tc, 2);
        appendLeave(tc, 4);
        appendSeat(tc, 5);
        appendLeave(tc, 2);
        appendSeat(tc, 2);
        appendSeat(tc, 7);
        appendLeave(tc, 5);
        appendSeat(tc, 4);

        testCases.push_back(move(tc));
    }

    for (size_t caseIdx = 0; caseIdx < testCases.size(); ++caseIdx) {
        const auto& tc = testCases[caseIdx];

        REQUIRE_ASSERT(assertEqScalar(
            "Exam Room 855 Test " + to_string(caseIdx + 1) + " [ops/args size]",
            tc.operations.size(),
            tc.arguments.size()));
        REQUIRE_ASSERT(assertEqScalar(
            "Exam Room 855 Test " + to_string(caseIdx + 1) + " [ops/expected size]",
            tc.operations.size(),
            tc.expected.size()));

        optional<ExamRoom_855> room;

        for (size_t stepIdx = 0; stepIdx < tc.operations.size(); ++stepIdx) {
            const string& op = tc.operations[stepIdx];
            const auto& args = tc.arguments[stepIdx];
            const auto& expected = tc.expected[stepIdx];

            const string label =
                makeStepLabel("Exam Room 855 Test", caseIdx, stepIdx, op, nullopt);

            if (op == "ExamRoom") {
                REQUIRE_ASSERT(assertEqScalar(label + " [expected void]", false, expected.has_value()));
                room.emplace(args[0]);
            } else if (op == "seat") {
                REQUIRE_ASSERT(assertEqScalar(label + " [has expected]", true, expected.has_value()));

                int got = room->seat();
                REQUIRE_ASSERT(assertEqScalar(label, expected.value(), got));
            } else if (op == "leave") {
                REQUIRE_ASSERT(assertEqScalar(label + " [expected void]", false, expected.has_value()));

                room->leave(args[0]);
            }
        }
    }

    return true;
}

/* Randomized object design */

bool shuffleAnArray_384_tests() {
    using Vec = vector<int>;

    auto assertChiSquare = [](const string& label,
                            double value,
                            double threshold,
                            bool expectBelow) {
        const bool pass = expectBelow ? value < threshold : value >= threshold;

        cout << label << ": " << (pass ? "PASS" : "FAIL")
            << " (X=" << value << ", threshold=" << threshold << ")\n";

        return pass;
    };

    {
        Vec nums = {1, 2, 3};
        ShuffleAnArray_384_FisherYates sol(nums, /*seed=*/123456789ULL);

        Vec shuffled1 = sol.shuffle();
        Vec reset = sol.reset();
        Vec shuffled2 = sol.shuffle();

        REQUIRE_ASSERT(assertEqScalar(
            "Shuffle 384 Ops Test [shuffle #1 is permutation]",
            true,
            isPermutationVecInt(nums, shuffled1)));
        REQUIRE_ASSERT(assertEqVIntExact(
            "Shuffle 384 Ops Test [reset]",
            nums,
            reset));
        REQUIRE_ASSERT(assertEqScalar(
            "Shuffle 384 Ops Test [shuffle #2 is permutation]",
            true,
            isPermutationVecInt(nums, shuffled2)));
    }

    {
        // Permutation-level uniformity for n=3. The wrong shuffle should be visibly biased.
        Vec base = {1, 2, 3};
        const int numPermutations = 6;
        const int samples = 60000;
        const double threshold = 24.0;

        static const vector<Vec> permutations = [] {
            vector<Vec> all;
            Vec current = {1, 2, 3};

            do {
                all.push_back(current);
            } while (next_permutation(current.begin(), current.end()));

            return all;
        }();

        auto permutationIndex = [&](const Vec& v) -> int {
            auto it = find(permutations.begin(), permutations.end(), v);
            if (it == permutations.end()) {
                return -1;
            }

            return static_cast<int>(distance(permutations.begin(), it));
        };

        ShuffleAnArray_384_FisherYates good(base, /*seed=*/987654321ULL);
        ShuffleAnArray_384_Wrong bad(base, /*seed=*/987654321ULL);

        vector<long long> goodCounts(numPermutations, 0);
        vector<long long> badCounts(numPermutations, 0);

        for (int i = 0; i < samples; ++i) {
            good.reset();
            bad.reset();

            const int goodIndex = permutationIndex(good.shuffle());
            const int badIndex = permutationIndex(bad.shuffle());

            if (goodIndex < 0 || badIndex < 0) {
                cout << "Shuffle 384 Chi-square Test A: FAIL"
                    << " (invalid permutation index"
                    << ", goodIndex=" << goodIndex
                    << ", badIndex=" << badIndex << ")\n";
                return false;
            }

            ++goodCounts[goodIndex];
            ++badCounts[badIndex];
        }

        const double expected = static_cast<double>(samples) / numPermutations;
        const double goodX = chiSquare(goodCounts, expected);
        const double badX = chiSquare(badCounts, expected);

        REQUIRE_ASSERT(assertChiSquare(
            "Shuffle 384 Chi-square Test A [Fisher-Yates]",
            goodX,
            threshold,
            /*expectBelow=*/true));
        REQUIRE_ASSERT(assertChiSquare(
            "Shuffle 384 Chi-square Test A [wrong shuffle]",
            badX,
            threshold,
            /*expectBelow=*/false));
    }

    {
        // Per-position uniformity for n=5. Each value should appear uniformly across positions.
        Vec base = {0, 1, 2, 3, 4};
        const int n = static_cast<int>(base.size());
        const int samples = 30000;
        const double threshold = 22.0;

        ShuffleAnArray_384_FisherYates good(base, /*seed=*/424242ULL);
        ShuffleAnArray_384_Wrong bad(base, /*seed=*/424242ULL);

        vector<vector<long long>> goodCounts(n, vector<long long>(n, 0));
        vector<vector<long long>> badCounts(n, vector<long long>(n, 0));

        for (int i = 0; i < samples; ++i) {
            good.reset();
            bad.reset();

            Vec goodShuffle = good.shuffle();
            Vec badShuffle = bad.shuffle();

            for (int pos = 0; pos < n; ++pos) {
                ++goodCounts[goodShuffle[pos]][pos];
                ++badCounts[badShuffle[pos]][pos];
            }
        }

        const double expected = static_cast<double>(samples) / n;
        bool goodUniform = true;
        bool badBiased = false;

        for (int value = 0; value < n; ++value) {
            const double goodX = chiSquare(goodCounts[value], expected);
            const double badX = chiSquare(badCounts[value], expected);

            if (goodX >= threshold) {
                goodUniform = false;
            }
            if (badX >= threshold) {
                badBiased = true;
            }
        }

        REQUIRE_ASSERT(assertEqScalar(
            "Shuffle 384 Chi-square Test B [Fisher-Yates per-position]",
            true,
            goodUniform));
        REQUIRE_ASSERT(assertEqScalar(
            "Shuffle 384 Chi-square Test B [wrong shuffle detected]",
            true,
            badBiased));
    }

    return true;
}

} // namespace

namespace TestsDesign {

std::vector<TestRegistry::Entry> getTests() {
    return {
        // Core custom data structures and API-oriented implementations
        TEST(432, "All O`one Data Structure", allOOneDataStructure_432_tests),
        TEST(855, "Exam Room",                examRoom_855_tests),

        // Randomized object design
        TEST(384, "Shuffle an Array",         shuffleAnArray_384_tests),
    };
}

} // namespace TestsDesign
