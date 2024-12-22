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

    while (head != nullptr) {
        oss << head->val;
        if (head->next != nullptr) oss << " -> ";
        head = head->next;
    }

    return oss.str();
}

// Free the linked list memory
template <typename T>
void ListUtils::freeList(ListNode<T>* head) {
    while (head != nullptr) {
        ListNode<T>* temp = head;
        head = head->next;
        delete temp;
    }
}

// Explicit instantiation for int type
template ListNode<int>* ListUtils::createLinkedList<int>(const std::vector<int>&);
template std::vector<int> ListUtils::toVector<int>(ListNode<int>*);
template std::string ListUtils::toString<int>(ListNode<int>*);
template void ListUtils::freeList<int>(ListNode<int>*);