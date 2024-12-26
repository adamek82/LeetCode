#include "ListUtils.h"

// Create a linked list from a vector
template <typename T>
ListNode<T>* ListUtils::createLinkedList(const std::vector<T>& values) {
    if (values.empty()) return nullptr;

    ListNode<T>* head = new ListNode<T>(values[0]);
    ListNode<T>* current = head;

    for (size_t i = 1; i < values.size(); ++i) {
        current->next = new ListNode<T>(values[i]);
        current = current->next;
    }

    return head;
}

// Convert a linked list to a vector
template <typename T>
std::vector<T> ListUtils::toVector(ListNode<T>* head) {
    std::vector<T> result;

    while (head != nullptr) {
        result.push_back(head->val);
        head = head->next;
    }

    return result;
}

// Convert a linked list to a string representation
template <typename T>
std::string ListUtils::toString(ListNode<T>* head) {
    std::ostringstream oss;
    std::unordered_set<ListNode<T>*> visited;
    while (head) {
        if (visited.find(head) != visited.end()) {
            oss << head->val << "(cycle)";
            break;
        }
        visited.insert(head);
        oss << head->val << " -> ";
        head = head->next;
    }
    oss << "null";
    return oss.str();
}

// Free the linked list memory
template <typename T>
static void ListUtils::freeList(ListNode<T>* head) {
    ListNode<T>* current = head;
    std::unordered_set<ListNode<T>*> visited;

    while (current && visited.find(current) == visited.end()) {
        visited.insert(current);
        ListNode<T>* next = current->next;
        delete current;
        current = next;
    }
}

// Create a linked list from a vector and set up a cycle if pos >= 0
template <typename T>
static ListNode<T>* ListUtils::createLinkedListWithCycle(const std::vector<T>& values, int pos) {
    if (values.empty()) return nullptr;

    ListNode<T>* head = new ListNode<T>(values[0]);
    ListNode<T>* current = head;
    ListNode<T>* cycleNode = head;

    for (size_t i = 1; i < values.size(); ++i) {
        current->next = new ListNode<T>(values[i]);
        current = current->next;

        if (static_cast<int>(i) == pos) {
            cycleNode = current;
        }
    }

    if (pos >= 0) {
        current->next = cycleNode;
    }

    return head;
}

// Explicit instantiation for int type
template ListNode<int>* ListUtils::createLinkedList<int>(const std::vector<int>&);
template std::vector<int> ListUtils::toVector<int>(ListNode<int>*);
template std::string ListUtils::toString<int>(ListNode<int>*);
template void ListUtils::freeList<int>(ListNode<int>*);
template ListNode<int>* ListUtils::createLinkedListWithCycle(const std::vector<int>& values, int pos);