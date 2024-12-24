#include "MergeTwoSortedLists_21.h"

ListNode<int> *MergeTwoSortedLists_21::mergeTwoLists(ListNode<int> *list1, ListNode<int> *list2)
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
