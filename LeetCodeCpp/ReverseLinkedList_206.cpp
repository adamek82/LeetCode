#include "ReverseLinkedList_206.h"
#include "ListNode.h"

/*
 * Reverse Linked List (LeetCode 206) — iterative in-place
 *
 * Idea
 * ----
 * Walk through the list once and reverse pointers as you go.
 * Maintain two pointers: `prev` (reversed part) and `current` (unprocessed part).
 * For each node, save `next`, redirect `current->next` to `prev`, then advance.
 *
 * Invariant
 * ---------
 * Before each loop iteration:
 *   - `prev` points to the already reversed prefix of the original list,
 *   - `current` points to the first node of the not-yet-processed suffix.
 * We take `current`, save `next`, reverse its link to `prev`, then advance both
 * pointers, growing the reversed prefix by one node.
 *
 * Complexity
 * ----------
 * Time:  O(n)
 * Space: O(1)
 */
ListNode<int>* ReverseLinkedList_206::reverseList(ListNode<int>* head)
{
    ListNode<int>* prev = nullptr;
    ListNode<int>* current = head;

    while (current != nullptr) {
        ListNode<int>* next = current->next;
        current->next = prev;

        prev = current;
        current = next;
    }

    return prev;
}
