#pragma once
#include "ListNode.h"
#include <memory>
#include <optional>
#include <string>
#include <vector>

using namespace std;

class ListUtils {
public:
    template <typename T>
    static ListNode<T>* createLinkedList(const vector<T>& values);

    template <typename T>
    static vector<T> toVector(ListNode<T>* head);

    template <typename T>
    static string toString(ListNode<T>* head);

    template <typename T>
    static void freeList(ListNode<T>* head);

    template <typename T>
    static ListNode<T>* createLinkedListWithCycle(const vector<T>& values, int pos);

    template <typename T>
    static ListNode<T> *createLinkedListWithRandom(const vector<pair<T, optional<int>>> &nodes);

    template <typename T>
    static bool compareListsWithRandom(ListNode<T> *list1, ListNode<T> *list2);

    template <typename T>
    struct ListDeleter {
        void operator()(ListNode<T>* node) const {
            freeList<T>(node);
        }
    };

    template <typename T>
    using UniqueList = unique_ptr<ListNode<T>, ListDeleter<T>>;

    template <typename T>
    static UniqueList<T> makeUniqueList(const vector<T>& values) {
        return UniqueList<T>(createLinkedList<T>(values));
    }

    template <typename T>
    static UniqueList<T> makeUniqueListWithCycle(const vector<T>& values, int pos) {
        return UniqueList<T>(createLinkedListWithCycle<T>(values, pos));
    }

    template <typename T>
    static UniqueList<T> makeUniqueListWithRandom(
        const vector<pair<T, optional<int>>>& nodes) {
        return UniqueList<T>(createLinkedListWithRandom<T>(nodes));
    }

    // Use after an in-place linked-list algorithm returns a possibly different head.
    // Ownership stays with the same unique_ptr, but its stored head pointer is updated.
    template <typename T>
    static void resetListHead(UniqueList<T>& owner, ListNode<T>* newHead) {
        owner.release();
        owner.reset(newHead);
    }
};
