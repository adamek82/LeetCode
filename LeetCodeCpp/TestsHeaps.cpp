#include "TestsHeaps.h"

#include <algorithm>
#include <numeric>
#include <string>
#include <vector>

#include "TestCases.h"
#include "TestUtils.h"
#include "ListUtils.h"

#include "LastStoneWeight_1046.h"
#include "KthLargestElementInArray_215.h"
#include "TopKFrequentElements_347.h"
#include "KClosestPointsToOrigin_973.h"
#include "MergeKSortedLists_23.h"
#include "MinHeap.h"
#include "FindSafestPathInGrid_2812.h"

using namespace std;
using namespace TestCases;
using namespace TestUtils;

namespace {

/* Basic max-heap / min-heap simulation */

bool lastStoneWeight_1046_tests() {
    vector<LastStoneWeightTestCase> tests = {
        // 2 from the statement
        {{2,7,4,1,8,1}, 1},
        {{1}, 1},

        // 4 additional / edge-ish
        {{10,10}, 0},                 // equal pair cancels
        {{9,3,2,10}, 0},              // multiple reductions to zero
        {{1,1,2,3,5,8,13}, 1},        // mixed, ends with 1
        {{7,6,7,6,9}, 3}              // nontrivial leftovers
    };

    LastStoneWeight_1046 sol;
    for (size_t i = 0; i < tests.size(); ++i) {
        int got = sol.lastStoneWeight(tests[i].stones);

        const string label = "Last Stone Weight 1046 Test " + to_string(i + 1);
        REQUIRE_ASSERT(assertEqScalar(label, tests[i].expected, got));
    }

    return true;
}

/* Heap-based selection for k-th / top-k queries */

bool kthLargestElementInArray_215_tests()
{
    vector<KthLargestElementTestCase> testCases = {
        // Problem statement examples
        {{3, 2, 1, 5, 6, 4}, 2, 5},
        {{3, 2, 3, 1, 2, 4, 5, 5, 6}, 4, 4},

        // Additional test cases
        {{1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, 1, 10}, // Largest element
        {{7, 10, 4, 3, 20, 15}, 3, 10},           // Mixed elements
        {{2, 2, 2, 2, 2}, 3, 2},                  // Repeated elements

        // Large ascending [1..10000], k=500 -> 9501 (filled below)
        {{}, 500, 9501}
    };

    // Fill the large ascending test (no extra scope)
    auto& bigCase = testCases.back();
    bigCase.nums.resize(10000);
    iota(bigCase.nums.begin(), bigCase.nums.end(), 1); // 1..10000

    KthLargestElementInArray_215 solution;

    for (size_t i = 0; i < testCases.size(); ++i)
    {
        // Use copies to be robust if implementations ever mutate input
        auto v1 = testCases[i].nums;
        auto v2 = testCases[i].nums;

        const int resMax = solution.findKthLargest_MaxHeap(v1, testCases[i].k);
        const int resMin = solution.findKthLargest_MinHeap(v2, testCases[i].k);

        const string label = "Kth Largest 215 Test " + to_string(i + 1);
        REQUIRE_ASSERT(assertEqScalar(label + " [MaxHeap]", testCases[i].expected, resMax));
        REQUIRE_ASSERT(assertEqScalar(label + " [MinHeap]", testCases[i].expected, resMin));
    }

    return true;
}

bool topKFrequent_347_tests() {
    auto bag = [](initializer_list<pair<int, int>> spec) {
        size_t total = 0;

        for (const auto& [value, count] : spec) {
            total += count;
        }

        vector<int> values;
        values.reserve(total);

        for (const auto& [value, count] : spec) {
            values.insert(values.end(), count, value);
        }

        return values;
    };

    auto stress = bag({{42, 100}, {-7, 80}});
    stress.resize(stress.size() + 1000);
    iota(stress.end() - 1000, stress.end(), 10001);

    vector<TopKFrequentElementsTestCase> tests = {
        {{1,1,1,2,2,3}, 2, {1,2}},
        {{1},           1, {1}},
        {{1,1,2,2,2,3}, 1, {2}},
        {{-1,-1,-1,0,0,2,2,2,2,3,3}, 2, {2,-1}},

        // 7x7, 8x6, 9x5, 10x4, 11x3 -> k=3 => {7,8,9}
        {bag({{7,7}, {8,6}, {9,5}, {10,4}, {11,3}}), 3, {7,8,9}},

        // 42x100, -7x80, plus 1000 uniques -> k=2 => {42,-7}
        {stress, 2, {42,-7}},
    };

    TopKFrequentElements_347 sol;

    for (size_t i = 0; i < tests.size(); ++i) {
        auto got = sol.topKFrequent(tests[i].nums, tests[i].k);
        auto expected = tests[i].expected;

        sort(got.begin(), got.end());
        sort(expected.begin(), expected.end());

        const string label =
            "Top K Frequent Elements 347 Test " + to_string(i + 1) +
            " (k=" + to_string(tests[i].k) + ")";
        REQUIRE_ASSERT(assertEqVIntExact(label, expected, got));
    }

    return true;
}

bool kClosestPointsToOrigin_973_tests() {
    vector<KClosestPointsToOriginTestCase> testCases = {
        // Official examples
        {{{1, 3}, {-2, 2}}, 1, {{-2, 2}}},
        {{{3, 3}, {5, -1}, {-2, 4}}, 2, {{3, 3}, {-2, 4}}},

        // Ties at the same distance; any 3 of these 4 are valid
        {{{0, 1}, {1, 0}, {-1, 0}, {0, -1}}, 3, {{0, 1}, {1, 0}, {-1, 0}}},

        // Points at extreme coordinates
        {{{10000, 10000}, {-10000, -10000}, {5000, 0}, {0, 5000}}, 2,
        {{5000, 0}, {0, 5000}}},

        // Mixed signs, k near n
        {{{2, 2}, {1, 1}, {3, 3}, {-2, -2}, {-1, -1}}, 4,
        {{-2, -2}, {-1, -1}, {1, 1}, {2, 2}}},
    };

    KClosestPointsToOrigin_973 solver;

    for (size_t i = 0; i < testCases.size(); ++i) {
        const auto& tc = testCases[i];
        const string base = "K Closest Points to Origin 973 Test " + to_string(i + 1);

        auto quickSelectInput = tc.points; // solver may mutate
        vector<vector<int>> quickSelectOutput =
            solver.kClosestQuickSelect(quickSelectInput, tc.k);

        auto heapInput = tc.points; // solver may mutate
        vector<vector<int>> heapOutput =
            solver.kClosestHeap(heapInput, tc.k);

        REQUIRE_ASSERT(assertEqScalar(
            base + " [QuickSelect valid]",
            true,
            isValidKClosestPoints(tc.points, tc.k, quickSelectOutput)));
        REQUIRE_ASSERT(assertEqScalar(
            base + " [Heap valid]",
            true,
            isValidKClosestPoints(tc.points, tc.k, heapOutput)));
    }

    return true;
}

/* Merging multiple sorted streams with a heap frontier */

bool mergeKSortedLists_23_tests() {
    using IntListNode = ListNode<int>;

    vector<MergeKListsTestCase> testCases = {
        // Example 1
        {{{1, 4, 5}, {1, 3, 4}, {2, 6}}, {1, 1, 2, 3, 4, 4, 5, 6}},
        // Example 2
        {{}, {}},
        // Example 3
        {{{}}, {}},
        // Additional Test 1: Single long list
        {{{1, 2, 3, 4, 5}}, {1, 2, 3, 4, 5}},
        // Additional Test 2: Large overlapping lists
        {{{1, 3, 5}, {2, 4, 6}, {0, 7, 8, 9}}, {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}}
    };

    MergeKSortedLists_23 solution;

    for (size_t i = 0; i < testCases.size(); ++i) {
        vector<ListUtils::UniqueList<int>> owners;
        vector<IntListNode*> lists;

        owners.reserve(testCases[i].lists.size());
        lists.reserve(testCases[i].lists.size());

        for (const auto& values : testCases[i].lists) {
            owners.push_back(ListUtils::makeUniqueList<int>(values));
            lists.push_back(owners.back().get());
        }

        IntListNode* merged = solution.mergeKLists(lists);

        for (auto& owner : owners) {
            owner.release();
        }

        ListUtils::UniqueList<int> mergedOwner(merged);

        const string label = "Merge K Sorted Lists 23 Test " + to_string(i + 1);
        REQUIRE_ASSERT(assertEqVIntExact(label, testCases[i].expected,
                                            ListUtils::toVector<int>(mergedOwner.get())));
    }

    return true;
}

/* Priority-queue traversal on a graph / grid state space */

bool findSafestPathInGrid_2812_tests() {
    vector<FindTheSafestPathInGridTestCase> testCases = {
        // three examples from the statement
        {{{1, 0, 0},
            {0, 0, 0},
            {0, 0, 1}},
            0},
        {{{0, 0, 1},
            {0, 0, 0},
            {0, 0, 0}},
            2},
        {{{0, 0, 0, 1},
            {0, 0, 0, 0},
            {0, 0, 0, 0},
            {1, 0, 0, 0}},
            2},

        // extra – single thief in the centre of a 5×5 grid (answer = 2)
        {{{0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0},
            {0, 0, 1, 0, 0},
            {0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0}},
            2},

        // extra – two thieves forcing a bottleneck of 1
        {{{0, 0, 1},
            {0, 0, 0},
            {1, 0, 0}},
            1}};

    FindSafestPathInGrid_2812 solver;

    for (size_t i = 0; i < testCases.size(); ++i) {
        const auto& tc = testCases[i];

        auto grid = tc.grid; // solver may mutate
        int got = solver.maximumSafenessFactor(grid);

        const string label = "Find Safest Path in Grid 2812 Test " + to_string(i + 1);
        REQUIRE_ASSERT(assertEqScalar(label, tc.expected, got));
    }

    return true;
}

/* Core custom data structures and API-oriented implementations */

vector<int> runMinHeapScenario(const vector<MinHeapOp>& ops) {
    MinHeap heap;
    vector<int> output;

    for (const auto& op : ops) {
        switch (op.kind) {
            case MinHeapOpKind::Insert:
                heap.insert(op.value);
                break;

            case MinHeapOpKind::ExtractMin:
                output.push_back(heap.extractMin());
                break;

            case MinHeapOpKind::Update:
                heap.update(op.value, op.newValue);
                break;
        }
    }

    return output;
}

bool minHeap_tests() {
    auto insert = [](int value) {
        return MinHeapOp{MinHeapOpKind::Insert, value};
    };

    auto extractMin = [] {
        return MinHeapOp{MinHeapOpKind::ExtractMin};
    };

    auto update = [](int index, int newValue) {
        return MinHeapOp{MinHeapOpKind::Update, index, newValue};
    };

    vector<MinHeapTestCase> testCases = {
        {
            {
                insert(5),
                insert(3),
                insert(8),
                insert(1),
                insert(2),
                extractMin(),
                extractMin(),
            },
            {1, 2},
        },
        {
            {
                insert(10),
                insert(20),
                insert(5),
                update(1, 1), // index 1: 5 -> 1
                extractMin(),
            },
            {1},
        },
        {
            {
                insert(100),
                insert(50),
                insert(25),
                extractMin(),
                extractMin(),
            },
            {25, 50},
        },
    };

    for (size_t i = 0; i < testCases.size(); ++i) {
        const auto& tc = testCases[i];

        vector<int> got = runMinHeapScenario(tc.operations);

        const string label = "MinHeap Test " + to_string(i + 1);
        REQUIRE_ASSERT(assertEqVIntExact(label, tc.expected, got));
    }

    return true;
}

} // namespace

namespace TestsHeaps {

std::vector<TestRegistry::Entry> getTests() {
    return {
        // Basic max-heap / min-heap simulation
        TEST(1046, "Last Stone Weight",              lastStoneWeight_1046_tests),

        // Heap-based selection for k-th / top-k queries
        TEST(215,  "Kth Largest Element in an Array", kthLargestElementInArray_215_tests),
        TEST(347,  "Top K Frequent Elements",         topKFrequent_347_tests),
        TEST(973,  "K Closest Points to Origin",      kClosestPointsToOrigin_973_tests),

        // Merging multiple sorted streams with a heap frontier
        TEST(23,   "Merge K Sorted Lists",            mergeKSortedLists_23_tests),

        // Custom heap implementation
        TEST(0,    "MinHeap",                         minHeap_tests),

        // Priority-queue traversal on a grid
        TEST(2812, "Find Safest Path in Grid",        findSafestPathInGrid_2812_tests),
    };
}

} // namespace TestsHeaps
