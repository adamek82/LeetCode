#include "RemoveDuplicatesFromSortedList_83.h"

ListNode<int> *RemoveDuplicatesFromSortedList_83::deleteDuplicates(ListNode<int> *head)
{
    ListNode<int>* current = head;

    while (current != nullptr && current->next != nullptr) {
        if (current->val == current->next->val) {
            // Node to be removed
            ListNode<int>* duplicateNode = current->next;

            // Skip the duplicate node
            current->next = current->next->next;

            // Free the duplicate node
            delete duplicateNode;
        } else {
            // Move to the next node
            current = current->next;
        }
    }

    return head;
}