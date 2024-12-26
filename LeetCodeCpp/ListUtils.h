#pragma once
#include "ListNode.h"
#include <vector>
#include <string>
#include <unordered_set>
#include <sstream>

class ListUtils {
public:
    // Create a linked list from a vector
    template <typename T>
    static ListNode<T>* createLinkedList(const std::vector<T>& values);

    // Convert a linked list to a vector
    template <typename T>
    static std::vector<T> toVector(ListNode<T>* head);

    // Convert a linked list to a string representation
    template <typename T>
    static std::string toString(ListNode<T>* head);

    // Free the linked list memory
    template <typename T>
    static void freeList(ListNode<T>* head);

    // Create a linked list from a vector and set up a cycle if pos >= 0
    template <typename T>
    static ListNode<T>* createLinkedListWithCycle(const std::vector<T>& values, int pos);
};