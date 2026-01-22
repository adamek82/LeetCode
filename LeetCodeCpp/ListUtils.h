#pragma once
#include "ListNode.h"
#include <vector>
#include <string>
#include <optional>

using namespace std;

class ListUtils {
public:
    // Create a linked list from a vector
    template <typename T>
    static ListNode<T>* createLinkedList(const vector<T>& values);

    // Convert a linked list to a vector
    template <typename T>
    static vector<T> toVector(ListNode<T>* head);

    // Convert a linked list to a string representation
    template <typename T>
    static string toString(ListNode<T>* head);

    // Free the linked list memory
    template <typename T>
    static void freeList(ListNode<T>* head);

    // Create a linked list from a vector and set up a cycle if pos >= 0
    template <typename T>
    static ListNode<T>* createLinkedListWithCycle(const vector<T>& values, int pos);

    // Creates a linked list with random pointers based on a vector of values and optional random indices
    template <typename T>
    static ListNode<T> *createLinkedListWithRandom(const vector<pair<T, optional<int>>> &nodes);

    // Compares two linked lists with random pointers for structural and value equality
    template <typename T>
    static bool compareListsWithRandom(ListNode<T> *list1, ListNode<T> *list2);
};