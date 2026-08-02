#include "CopyListWithRandomPointer_138.h"

ListNode<int> *CopyListWithRandomPointer_138::copyRandomList(ListNode<int> *head)
{
    if (head == nullptr) return nullptr;

    ListNode<int>* orig = head;

    /*
     * Step 1: Duplicate each node and insert it right after the original node.
     * Original: 1 --> 2 --> 3 --> 4 (with random pointers)
     * After weaving: 1 --> 1' --> 2 --> 2' --> 3 --> 3' --> 4 --> 4'
     * (with correct labels, no random pointers yet)
     *
     * Note: On LeetCode we ignore exception-safety / partial-allocation cleanup.
     * In production code, you'd want to handle allocation failures and roll back / free.
     */
    while (orig != nullptr) {
        ListNode<int>* nextOrig = orig->next;
        orig->next = new ListNode<int>(orig->val);
        orig->next->next = nextOrig;
        orig = nextOrig;
    }

    /*
     * Step 2: Assign random pointers for the copied nodes.
     * For an original node `orig`, its copy is `orig->next`.
     * If orig->random points to some node R, then the copy's random should point to R's copy,
     * which is R->next (because of weaving).
     */
    orig = head;

    while (orig != nullptr) {
        if (orig->random != nullptr) {
            orig->next->random = orig->random->next;
        }
        orig = orig->next->next;
    }

    /*
     * Step 3: Unweave (separate) the original and copied list.
     * After third while loop:
     * Original head: 1 --> 2 --> 3 --> 4 (with original random pointers)
     * Copied head: 1' --> 2' --> 3' --> 4' (with copied random pointers)
     */
    orig = head;
    ListNode<int>* copyHead = head->next;
    ListNode<int>* clone = copyHead;

     while (clone != nullptr) {
        // restore original list: skip over the interleaved clone (orig -> clone -> nextOrig)
        orig->next = orig->next->next;
        /*
         * Link clones:
         * after weaving, each clone points to the next *original* node (or nullptr for the last clone),
         * so the next clone is two hops ahead: clone -> (next original) -> (next clone).
         * Guard against the last clone where clone->next is nullptr.
         */
        clone->next = (clone->next != nullptr) ? clone->next->next : nullptr;

        orig = orig->next;
        clone = clone->next;
    }

    return copyHead;
}
