#pragma once

#include <optional>
#include <string>
#include <utility>
#include <vector>

#include "tests/framework/TestCaseTypes.h"

namespace TestCases {

// 83. Remove Duplicates from Sorted List
struct RemoveDuplicatesFromSortedListTestCase { List list; List expected; };

// 2807. Insert Greatest Common Divisors in Linked List
struct InsertGreatestCommonDivisorsTestCase { List list; List expected; };

// 206. Reverse Linked List
struct ReverseLinkedListTestCase { List list; List expected; };

// 21. Merge Two Sorted Lists
struct MergeTwoSortedListsTestCase { List list1; List list2; List expected; };

// 141. Linked List Cycle
struct LinkedListCycleTestCase { List values; int pos; bool expected; };

// 876. Middle of the Linked List
struct MiddleOfTheLinkedListTestCase { List values; List expected; };

// 19. Remove Nth Node From End of List
struct RemoveNthNodeFromEndOfListTestCase { List values; int n; List expected; };

// 138. Copy List with Random Pointer
struct CopyRandomListTestCase {
    std::vector<std::pair<int, std::optional<int>>> nodes;
    std::vector<std::pair<int, std::optional<int>>> expected;
};

// 146. LRU Cache
struct LRUCacheTestCase {
    std::vector<std::string> operations;
    std::vector<std::vector<int>> arguments;
    std::vector<std::optional<int>> expected;
};

} // namespace TestCases
