#include "ReverseLinkedList_206.h"

ListNode<int> *ReverseLinkedList_206::reverseList(ListNode<int> *head)
{
    ListNode<int>* prev = nullptr;
    ListNode<int>* current = head;

    while (current != nullptr) {
        // Store the next node
        ListNode<int>* nextNode = current->next;

        // Reverse the current node's pointer
        current->next = prev;

        // Move pointers one step forward
        prev = current;
        current = nextNode;
    }

    // The new head of the reversed list
    return prev;
}