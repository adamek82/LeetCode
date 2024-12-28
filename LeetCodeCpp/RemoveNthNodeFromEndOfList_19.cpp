#include "RemoveNthNodeFromEndOfList_19.h"

ListNode<int> *RemoveNthNodeFromEndOfList_19::removeNthFromEnd(ListNode<int> *head, int n)
{
    // Create a stack-allocated dummy node
    ListNode<int> dummy(0, head);
    ListNode<int>* first = &dummy;
    ListNode<int>* second = &dummy;

    // Move the first pointer so that there is a gap of 'n + 1' between first and second
    for (int i = 0; i <= n; ++i) {
        first = first->next;
    }

    // Move both pointers until the first reaches the end
    while (first != nullptr) {
        first = first->next;
        second = second->next;
    }

    // Remove the nth node from the end
    ListNode<int>* toDelete = second->next;
    second->next = second->next->next;
    delete toDelete; // Delete the removed node

    // Return the new head
    return dummy.next;
}