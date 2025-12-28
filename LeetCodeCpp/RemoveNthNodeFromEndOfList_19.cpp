#include "RemoveNthNodeFromEndOfList_19.h"
#include "ListNode.h"

/*
 * Remove Nth Node From End of List (LeetCode 19) — two pointers + dummy
 *
 * Goal
 * ----
 * Remove the n-th node counted from the end (1-based) in one pass, O(L) time and O(1) extra space.
 * We reuse existing nodes and only relink pointers.
 *
 * Core idea (gap technique)
 * ------------------------
 * Use a dummy sentinel node before `head` and two pointers starting at `dummy`:
 *   - `first` (fast)
 *   - `second` (slow)
 *
 * We advance `first` by (n + 1) steps, so that the distance between `first` and `second`
 * is exactly (n + 1) nodes.
 *
 * Why (n + 1), not n?
 * -------------------
 * We don't want `second` to land on the node to delete; we want it to land on the *previous*
 * node so we can relink:
 *
 *   second -> next  == node_to_delete
 *   second->next    = node_to_delete->next
 *
 * Advancing `first` by (n + 1) ensures that when `first` reaches nullptr (falls off the list),
 * `second` is exactly one node *before* the target:
 *
 * Example (n = 2):
 *   We want to delete the 2nd from end. If `first` starts (n+1)=3 steps ahead, then when
 *   `first` hits nullptr, `second` points to the predecessor of the node to delete.
 *
 * The dummy node matters because it makes "delete head" cases uniform:
 * if the removed node is the original head, `second` will end up at `dummy`, and relinking
 * `dummy.next` updates the head cleanly without special cases.
 *
 * Precondition
 * ------------
 * LeetCode guarantees: 1 <= n <= length(list).
 * The `delete` is correct only if list nodes were allocated with `new`.
 */
ListNode<int> *RemoveNthNodeFromEndOfList_19::removeNthFromEnd(ListNode<int> *head, int n)
{
    // Create a stack-allocated dummy node
    // Precondition (LeetCode): 1 <= n <= length of list.
    ListNode<int> dummy(0, head);
    ListNode<int>* first = &dummy;
    ListNode<int>* second = &dummy;

    // Keep a gap of n nodes between first and second (advance first by n+1).
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
    delete toDelete; // Delete the removed node - OK only if nodes are heap-allocated (new)

    // Return the new head
    return dummy.next;
}