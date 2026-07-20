#include "TestsLinkedLists.h"

#include <string>
#include <vector>

#include "TestCases.h"
#include "TestUtils.h"
#include "ListUtils.h"

#include "RemoveDuplicatesFromSortedList_83.h"
#include "InsertGreatestCommonDivisors_2807.h"

#include "ReverseLinkedList_206.h"
#include "MergeTwoSortedLists_21.h"

#include "LinkedListCycle_141.h"
#include "MiddleOfLinkedList_876.h"
#include "RemoveNthNodeFromEndOfList_19.h"

#include "CopyListWithRandomPointer_138.h"

#include "LRUCache_146.h"

using namespace std;
using namespace TestCases;
using namespace TestUtils;

namespace {

/* Basic traversal and local pointer updates in linked lists */

bool removeDuplicatesFromSortedList_83_tests() {
    using IntListNode = ListNode<int>;

    // Define test cases
    vector<RemoveDuplicatesFromSortedListTestCase> testCases = {
        // Provided examples
        {{1, 1, 2}, {1, 2}},
        {{1, 1, 2, 3, 3}, {1, 2, 3}},

        // Additional complex test cases
        {{1, 1, 1, 1, 1}, {1}},                         // Single value repeated many times
        {{1, 2, 2, 3, 3, 4, 4, 5, 5, 6}, {1, 2, 3, 4, 5, 6}}, // Alternating duplicates
        {{-10, -10, -5, 0, 0, 1, 1, 2, 2, 2, 100}, {-10, -5, 0, 1, 2, 100}}, // Mixed negative and positive numbers
    };

    RemoveDuplicatesFromSortedList_83 solution;

    for (size_t i = 0; i < testCases.size(); ++i) {
        auto list = ListUtils::makeUniqueList<int>(testCases[i].list);

        IntListNode* result = solution.deleteDuplicates(list.get());
        ListUtils::resetListHead(list, result);

        const string label =
            "Remove Duplicates from Sorted List 83 Test " + to_string(i + 1);
        REQUIRE_ASSERT(assertEqVIntExact(
            label,
            testCases[i].expected,
            ListUtils::toVector<int>(list.get())));
    }

    return true;
}

bool insertGreatestCommonDivisors_2807_tests() {
    using IntListNode = ListNode<int>;

    vector<InsertGreatestCommonDivisorsTestCase> testCases = {
        // Provided examples
        {{18, 6, 10, 3}, {18, 6, 6, 2, 10, 1, 3}},
        {{7}, {7}},

        // Additional cases
        {{2, 4, 6}, {2, 2, 4, 2, 6}},
        {{5, 7, 11}, {5, 1, 7, 1, 11}},      // all primes -> gcd = 1
        {{1000, 1000}, {1000, 1000, 1000}},  // identical adjacent values
        {{1, 1000}, {1, 1, 1000}},
        {{12, 15, 21, 28}, {12, 3, 15, 3, 21, 7, 28}},
    };

    InsertGreatestCommonDivisors_2807 solution;

    for (size_t i = 0; i < testCases.size(); ++i) {
        auto stdList = ListUtils::makeUniqueList<int>(testCases[i].list);
        IntListNode* stdHead = solution.insertGreatestCommonDivisors_stdGcd(stdList.get());
        ListUtils::resetListHead(stdList, stdHead);

        vector<int> gotStd = ListUtils::toVector<int>(stdList.get());

        auto euclidList = ListUtils::makeUniqueList<int>(testCases[i].list);
        IntListNode* euclidHead = solution.insertGreatestCommonDivisors_euclid(euclidList.get());
        ListUtils::resetListHead(euclidList, euclidHead);

        vector<int> gotEuclid = ListUtils::toVector<int>(euclidList.get());

        const string base = "Insert Greatest Common Divisors 2807 Test " + to_string(i + 1);
        REQUIRE_ASSERT(assertEqVIntExact(base + " [std::gcd]", testCases[i].expected, gotStd));
        REQUIRE_ASSERT(assertEqVIntExact(base + " [euclid]", testCases[i].expected, gotEuclid));
        REQUIRE_ASSERT(assertEqVIntExact(base + " [consistency]", gotStd, gotEuclid));
    }

    return true;
}

/* Core linked-list transformations by rewiring next pointers */

bool reverseLinkedList_206_tests() {
    using IntListNode = ListNode<int>;

    // Define test cases
    vector<ReverseLinkedListTestCase> testCases = {
        // Provided examples
        {{1, 2, 3, 4, 5}, {5, 4, 3, 2, 1}},
        {{1, 2}, {2, 1}},
        {{}, {}},

        // Additional complex test cases
        {{-5, -4, -3, -2, -1}, {-1, -2, -3, -4, -5}}, // Negative values
        {{10, 20, 30, 40, 50, 60}, {60, 50, 40, 30, 20, 10}} // Longer list
    };

    ReverseLinkedList_206 solution;

    for (size_t i = 0; i < testCases.size(); ++i) {
        auto list = ListUtils::makeUniqueList<int>(testCases[i].list);

        IntListNode* result = solution.reverseList(list.get());
        ListUtils::resetListHead(list, result);

        const string label = "Reverse Linked List 206 Test " + to_string(i + 1);
        REQUIRE_ASSERT(assertEqVIntExact(
            label,
            testCases[i].expected,
            ListUtils::toVector<int>(list.get())));
    }

    return true;
}

bool mergeTwoSortedLists_21_tests() {
    using IntListNode = ListNode<int>;

    vector<MergeTwoSortedListsTestCase> testCases = {
        // Provided examples
        {{1, 2, 4}, {1, 3, 4}, {1, 1, 2, 3, 4, 4}},
        {{}, {}, {}},
        {{}, {0}, {0}},

        // Additional complex test cases
        {{-10, -5, 0, 3}, {-8, -6, 2, 4}, {-10, -8, -6, -5, 0, 2, 3, 4}},
        {{1, 3, 5, 7}, {2, 4, 6, 8, 10}, {1, 2, 3, 4, 5, 6, 7, 8, 10}}
    };

    MergeTwoSortedLists_21 solution;

    struct Impl {
        string name;
        function<IntListNode*(IntListNode*, IntListNode*)> run;
    };

    const vector<Impl> impls = {
        {
            "DummyNode",
            [&](IntListNode* a, IntListNode* b) {
                return solution.mergeTwoLists_DummyNode(a, b);
            }
        },
        {
            "NoDummy",
            [&](IntListNode* a, IntListNode* b) {
                return solution.mergeTwoLists_NoDummy(a, b);
            }
        },
    };

    for (size_t i = 0; i < testCases.size(); ++i) {
        const auto& tc = testCases[i];

        for (const auto& impl : impls) {
            auto list1 = ListUtils::makeUniqueList<int>(tc.list1);
            auto list2 = ListUtils::makeUniqueList<int>(tc.list2);

            IntListNode* result = impl.run(list1.get(), list2.get());

            // mergeTwoLists re-links nodes from both inputs into one output list.
            // The result owner must be the only owner of the merged chain.
            list1.release();
            list2.release();
            ListUtils::UniqueList<int> resultList(result);

            const string label =
                "Merge Two Sorted Lists 21 Test " + to_string(i + 1) +
                " [" + impl.name + "]";
            REQUIRE_ASSERT(assertEqVIntExact(
                label,
                tc.expected,
                ListUtils::toVector<int>(resultList.get())));
        }
    }

    return true;
}

/* Fast/slow pointer techniques on linked lists */

bool hasCycle_141_tests() {
    vector<LinkedListCycleTestCase> testCases = {
        // Provided examples
        {{3, 2, 0, -4}, 1, true},
        {{1, 2}, 0, true},
        {{1}, -1, false},

        // Additional examples
        {{1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, 4, true},
        {{10, 20, 30, 40, 50, 60, 70, 80}, 2, true}
    };

    LinkedListCycle_141 solution;

    for (size_t i = 0; i < testCases.size(); ++i) {
        auto list = ListUtils::makeUniqueListWithCycle<int>(
            testCases[i].values,
            testCases[i].pos);

        bool got = solution.hasCycle(list.get());

        const string label = "Linked List Cycle 141 Test " + to_string(i + 1);
        REQUIRE_ASSERT(assertEqScalar(label, testCases[i].expected, got));
    }

    return true;
}

bool middleOfTheLinkedList_876_tests() {
    using IntListNode = ListNode<int>;

    vector<MiddleOfTheLinkedListTestCase> testCases = {
        // Provided examples
        {{1, 2, 3, 4, 5}, {3, 4, 5}},
        {{1, 2, 3, 4, 5, 6}, {4, 5, 6}},

        // Additional test cases
        {{}, {}},                         // Edge case: empty list
        {{1}, {1}},                       // Edge case: single element
        {{1, 2, 3, 4, 5, 6, 7}, {4, 5, 6, 7}} // Odd-length list
    };

    MiddleOfLinkedList_876 solution;

    for (size_t i = 0; i < testCases.size(); ++i) {
        auto list = ListUtils::makeUniqueList<int>(testCases[i].values);

        IntListNode* result = solution.middleNode(list.get());

        const string label = "Middle of the Linked List 876 Test " + to_string(i + 1);
        REQUIRE_ASSERT(assertEqVIntExact(
            label,
            testCases[i].expected,
            ListUtils::toVector<int>(result)));
    }

    return true;
}

bool removeNthNodeFromEndOfList_19_tests() {
    using IntListNode = ListNode<int>;

    vector<RemoveNthNodeFromEndOfListTestCase> testCases = {
        // Provided examples
        {{1, 2, 3, 4, 5}, 2, {1, 2, 3, 5}},
        {{1}, 1, {}},
        {{1, 2}, 1, {1}},

        // Additional test cases
        {{10, 20, 30, 40, 50, 60, 70}, 3, {10, 20, 30, 40, 60, 70}}, // Bigger list
        {{5, 10, 15, 20}, 4, {10, 15, 20}} // Removing the head
    };

    RemoveNthNodeFromEndOfList_19 solution;

    for (size_t i = 0; i < testCases.size(); ++i) {
        auto list = ListUtils::makeUniqueList<int>(testCases[i].values);

        IntListNode* result = solution.removeNthFromEnd(list.get(), testCases[i].n);
        ListUtils::resetListHead(list, result);

        const string label = "Remove Nth Node From End of List 19 Test " + to_string(i + 1);
        REQUIRE_ASSERT(assertEqVIntExact(
            label,
            testCases[i].expected,
            ListUtils::toVector<int>(list.get())));
    }

    return true;
}

/* More advanced linked structures with extra references */

bool copyRandomList_138_tests() {
    using IntListNode = ListNode<int>;

    vector<CopyRandomListTestCase> testCases = {
        // Provided test cases
        {{{7, nullopt}, {13, 0}, {11, 4}, {10, 2}, {1, 0}},
            {{7, nullopt}, {13, 0}, {11, 4}, {10, 2}, {1, 0}}},
        {{{1, 1}, {2, 1}}, {{1, 1}, {2, 1}}},
        {{{3, nullopt}, {3, 0}, {3, nullopt}},
            {{3, nullopt}, {3, 0}, {3, nullopt}}},

        // Additional complex test cases
        {{{1, nullopt}, {2, 0}, {3, 1}, {4, 3}, {5, 2}},
            {{1, nullopt}, {2, 0}, {3, 1}, {4, 3}, {5, 2}}},
        {{{10, 4}, {20, 3}, {30, 2}, {40, 1}, {50, nullopt}},
            {{10, 4}, {20, 3}, {30, 2}, {40, 1}, {50, nullopt}}}
    };

    CopyListWithRandomPointer_138 solution;

    for (size_t i = 0; i < testCases.size(); ++i) {
        auto input = ListUtils::makeUniqueListWithRandom<int>(testCases[i].nodes);
        auto expected = ListUtils::makeUniqueListWithRandom<int>(testCases[i].expected);

        ListUtils::UniqueList<int> result(solution.copyRandomList(input.get()));

        bool isCorrect = ListUtils::compareListsWithRandom<int>(
            result.get(),
            expected.get());

        const string label = "Copy List with Random Pointer 138 Test " + to_string(i + 1);
        REQUIRE_ASSERT(assertEqScalar(label, true, isCorrect));
    }

    return true;
}

/* Linked-list-based data structure design */

bool lruCache_146_tests() {
    vector<LRUCacheTestCase> testCases = {
        // From problem statement
        {
            {"LRUCache","put","put","get","put","get","put","get","get","get"},
            {{2},      {1,1}, {2,2}, {1},  {3,3}, {2},  {4,4}, {1},  {3},   {4}},
            { nullopt, nullopt, nullopt, 1,
                nullopt, -1,         nullopt, -1,
                3,            4 }
        },
        // Additional: overwrite existing key and capacity=1 edge
        {
            {"LRUCache","put","put","get","put","get","get"},
            {{1},      {1,10},{1,20},{1},  {2,30},{1},  {2}},
            { nullopt, nullopt, nullopt, 20,
                nullopt,  -1,           30 }
        },
        // Additional: complex sequence with capacity = 3 and multiple evictions
        {
            {"LRUCache","put","put","put","get","put","get","get","put","get","get"},
            {{3},      {1,1}, {2,2}, {3,3}, {1},  {4,4}, {2},  {3},  {5,5}, {1},  {4}},
            { nullopt, nullopt, nullopt, nullopt, 1,
                nullopt, -1,          3,          nullopt, -1,        4}
        },
    };

    for (size_t t = 0; t < testCases.size(); ++t) {
        const auto& tc = testCases[t];
        unique_ptr<LRUCache> cache;

        for (size_t i = 0; i < tc.operations.size(); ++i) {
            const string& op = tc.operations[i];

            if (op == "LRUCache") {
                cache = make_unique<LRUCache>(tc.arguments[i][0]);
            } else if (op == "put") {
                cache->put(tc.arguments[i][0], tc.arguments[i][1]);
            } else if (op == "get") {
                int key = tc.arguments[i][0];
                int got = cache->get(key);

                const string label = makeStepLabel("LRUCache_146", t, i, "get", to_string(key));
                REQUIRE_ASSERT(assertEqScalar(label, tc.expected[i].value(), got));
            }
        }
    }

    return true;
}

} // namespace

namespace TestsLinkedLists {

std::vector<TestRegistry::Entry> getTests() {
    return {
        // Basic traversal and local pointer updates in linked lists
        TEST(83,   "Remove Duplicates from Sorted List",             removeDuplicatesFromSortedList_83_tests),
        TEST(2807, "Insert Greatest Common Divisors in Linked List", insertGreatestCommonDivisors_2807_tests),

        // Core linked-list transformations by rewiring next pointers
        TEST(206,  "Reverse Linked List",                            reverseLinkedList_206_tests),
        TEST(21,   "Merge Two Sorted Lists",                         mergeTwoSortedLists_21_tests),

        // Fast/slow pointer techniques on linked lists
        TEST(141,  "Linked List Cycle",                              hasCycle_141_tests),
        TEST(876,  "Middle of the Linked List",                      middleOfTheLinkedList_876_tests),
        TEST(19,   "Remove Nth Node From End of List",               removeNthNodeFromEndOfList_19_tests),

        // More advanced linked structures with extra references
        TEST(138,  "Copy List With Random Pointer",                  copyRandomList_138_tests),

        // Linked-list-based data structure design
        TEST(146,  "LRU Cache",                                      lruCache_146_tests),
    };
}

} // namespace TestsLinkedLists
