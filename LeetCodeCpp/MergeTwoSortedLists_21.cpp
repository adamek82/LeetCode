#include "MergeTwoSortedLists_21.h"

/*
 * Merge Two Sorted Lists (LeetCode 21) — iterative merge with a dummy node
 *
 * Idea
 * ----
 * We merge the two already-sorted singly linked lists by repeatedly taking the
 * smaller head node and appending it to the result list. We do this in-place:
 * we only relink existing nodes, we do not allocate new ones.
 *
 * Dummy node (why it helps)
 * -------------------------
 * The "dummy" node is a temporary fake head placed on the stack. It is not part
 * of the final data, but it gives us a stable, always-valid node to append to.
 *
 * Without a dummy node:
 *   - you'd typically need special-case logic for the first chosen node
 *     ("initialize head if it's null"), and then different code paths for the
 *     remaining nodes.
 *
 * With a dummy node:
 *   - `current` always points to the last node of the merged list built so far,
 *   - appending is always the same operation: `current->next = chosen; current = current->next;`
 *   - the final head is simply `dummy.next`.
 *
 * Invariant
 * ---------
 * Before each loop iteration:
 *   - `dummy.next` is the head of the merged prefix built so far,
 *   - `current` points to the last node of that merged prefix,
 *   - `list1` and `list2` point to the first not-yet-merged nodes of their
 *     respective original lists,
 *   - the merged prefix is sorted and contains exactly the nodes that were
 *     removed from the fronts of `list1`/`list2`.
 *
 * Progress step
 * -------------
 * Compare `list1->val` and `list2->val`, append the smaller node to `current`,
 * advance the chosen list pointer, then advance `current`. This preserves the
 * invariant and grows the merged prefix by one node.
 *
 * Finish
 * ------
 * Once one list is exhausted, the other list is already sorted, so we can append
 * the entire remainder in O(1): `current->next = list1 ? list1 : list2;`
 *
 * Complexity
 * ----------
 * Time:  O(n + m)  (each node is appended exactly once)
 * Space: O(1)      (in-place relinking; dummy/current are constant extra memory)
 */
ListNode<int> *MergeTwoSortedLists_21::mergeTwoLists_DummyNode(ListNode<int> *list1, ListNode<int> *list2)
{
    // Initialize a dummy node on the stack
    ListNode<int> dummy;
    ListNode<int>* current = &dummy;

    // Merge lists by comparing values
    while (list1 && list2) {
        if (list1->val <= list2->val) {
            current->next = list1;
            list1 = list1->next;
        } else {
            current->next = list2;
            list2 = list2->next;
        }
        current = current->next;
    }

    // Append the remaining nodes
    current->next = list1 ? list1 : list2;

    // The merged list starts from dummy.next
    return dummy.next;
}

/*
 * Merge Two Sorted Lists (LeetCode 21) — iterative merge WITHOUT a dummy node
 *
 * Idea
 * ----
 * Both input lists are already sorted. We build the merged list by repeatedly
 * taking the smaller head node from (l1, l2) and appending it to the output tail.
 * This is done in-place by relinking existing nodes (no allocations).
 *
 * Why there is a special-case (no dummy node)
 * -------------------------------------------
 * Without a dummy node we don't have a ready "anchor" node to append to.
 * Therefore we must initialize the output head explicitly:
 *   - choose the first node (min of l1->val and l2->val),
 *   - set `head` and `tail` to that node,
 *   - advance the chosen list pointer once.
 * After that, appending becomes uniform (always attach to `tail->next`).
 *
 * Invariant
 * ---------
 * After initialization and before each loop iteration:
 *   - `head` is the head of the merged list built so far,
 *   - `tail` points to the last node of that merged list,
 *   - `l1` and `l2` point to the first not-yet-merged nodes of the original lists,
 *   - the merged list is sorted and contains exactly the nodes already taken
 *     from the fronts of l1/l2.
 *
 * Progress step
 * -------------
 * Compare current heads. Append the smaller node to `tail->next`, advance the
 * chosen list pointer, then advance `tail`. This preserves sorting and grows
 * the merged list by one node.
 *
 * Finish
 * ------
 * When one list becomes empty, the other list's remainder is already sorted,
 * so we can append it in O(1): `tail->next = l1 ? l1 : l2;`
 *
 * Complexity
 * ----------
 * Time:  O(n + m)
 * Space: O(1)
 */
ListNode<int>* MergeTwoSortedLists_21::mergeTwoLists_NoDummy(ListNode<int>* l1, ListNode<int>* l2)
{
    if (!l1) return l2;
    if (!l2) return l1;

    ListNode<int>* head = nullptr;
    if (l1->val <= l2->val) { head = l1; l1 = l1->next; }
    else                    { head = l2; l2 = l2->next; }

    ListNode<int>* tail = head;

    while (l1 && l2) {
        if (l1->val <= l2->val) { tail->next = l1; l1 = l1->next; }
        else                    { tail->next = l2; l2 = l2->next; }
        tail = tail->next;
    }

    tail->next = l1 ? l1 : l2;
    return head;
}
