#include "RemoveDuplicatesFromSortedList_83.h"

/*
 * Remove Duplicates from Sorted List (LeetCode 83) — in-place one-pass
 *
 * Idea
 * ----
 * The list is sorted, so duplicates (if any) appear as consecutive nodes.
 * Walk the list with a pointer `current`. If `current->val == current->next->val`,
 * remove the next node by bypassing it: `current->next = current->next->next`,
 * then free the removed node. Otherwise, advance `current`.
 *
 * Key detail
 * ----------
 * After deleting a duplicate, do NOT advance `current` — there may be more nodes
 * with the same value right after it.
 *
 * Complexity
 * ----------
 * Time:  O(n)  (single pass)
 * Space: O(1)  (in-place)
 */
ListNode<int>* RemoveDuplicatesFromSortedList_83::deleteDuplicates(ListNode<int>* head)
{
    ListNode<int>* current = head;

    while (current != nullptr && current->next != nullptr) {
        ListNode<int>* next = current->next;

        if (current->val == next->val) {
            // unlink + free the duplicate node
            current->next = next->next;
            delete next;
        } else {
            current = next;
        }
    }

    return head;
}
