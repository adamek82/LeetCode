#include "MiddleOfLinkedList_876.h"

ListNode<int> *MiddleOfLinkedList_876::middleNode(ListNode<int> *head)
{
    // Initialize two pointers
    ListNode<int> *slow = head;
    ListNode<int> *fast = head;

    // Move fast by 2 steps and slow by 1 step until fast reaches the end
    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // Slow pointer now points to the middle node
    return slow;
}