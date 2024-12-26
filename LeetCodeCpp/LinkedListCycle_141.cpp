#include "LinkedListCycle_141.h"

bool LinkedListCycle_141::hasCycle(ListNode<int> *head)
{
    ListNode<int> *slow = head; // Slow pointer starts at head.
    ListNode<int> *fast = head; // Fast pointer starts at head.

    while (fast && fast->next) {
        slow = slow->next;          // Move slow pointer one step.
        fast = fast->next->next;    // Move fast pointer two steps.

        if (slow == fast) {
            return true; // Cycle detected.
        }
    }

    return false; // No cycle detected.
}