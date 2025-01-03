#include "CopyListWithRandomPointer_138.h"

ListNode<int> *CopyListWithRandomPointer_138::copyRandomList(ListNode<int> *head)
{
    if (head == nullptr) return nullptr;

    ListNode<int>* c = head;

    // Step 1: Duplicate each node and insert it right after the original node.
    // Original: 1 --> 2 --> 3 --> 4 (with random pointers)
    // After first while loop: 1 --> 1' --> 2 --> 2' --> 3 --> 3' --> 4 --> 4'
    // (with correct labels, no random pointers yet)
    while (c != nullptr) {
        ListNode<int>* next = c->next;
        c->next = new ListNode<int>(c->val);
        c->next->next = next;
        c = next;
    }

    c = head;
    // Step 2: Assign random pointers for the copied nodes.
    // After second while loop: Random pointers for 1', 2', 3', 4'
    // set based on the original list.
    while (c != nullptr) {
        if (c->random != nullptr) {
            c->next->random = c->random->next;
        }
        c = c->next->next;
    }

    c = head;
    ListNode<int>* copyHead = head->next;
    ListNode<int>* copy = copyHead;

    // Step 3: Separate the original and copied list.
    // After third while loop:
    // Original head: 1 --> 2 --> 3 --> 4 (with original random pointers)
    // Copied head: 1' --> 2' --> 3' --> 4' (with copied random pointers)
    while (copy != nullptr) {
        c->next = c->next->next;
        c = c->next;

        if (copy->next != nullptr) {
            copy->next = copy->next->next;
        }
        copy = copy->next;
    }

    return copyHead;
}