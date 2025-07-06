#include "MergeKSortedLists_23.h"

/*  ============================================================================
 *  Merge K Sorted Lists — High-level Algorithm Overview
 *  ----------------------------------------------------------------------------
 *  Goal
 *  -----
 *  Given *k* singly-linked lists that are each already sorted in non-decreasing
 *  order, produce one new list that preserves the global sort order while
 *  re-using the existing nodes (no extra allocations).
 *
 *  Core Idea
 *  ---------
 *  Keep the “current” node of every list in a **min-heap** (priority-queue whose
 *  comparator returns `true` when the left node’s value is *greater* than the
 *  right node’s value, thus turning the C++ `priority_queue` into a min-heap).
 *  At every step the heap’s top holds the smallest key among all remaining
 *  nodes, so removing that node and pushing its successor maintains global
 *  ordering.
 *
 *  Step-by-step
 *  -----------
 *  1.  Push the head of every non-empty list into the heap.
 *  2.  Pop the smallest node, append it to the output list, and—if that node
 *      has a successor—push the successor back into the heap.
 *  3.  Repeat until the heap is empty; the output list is now fully merged.
 *
 *  Implementation Notes
 *  --------------------
 *  • A **dummy (sentinel) head** node lets us treat the first and subsequent
 *    insertions identically, eliminating special-case branches.
 *  • Time complexity is **O(N log k)**, where *N* is the total node count; the
 *    extra space is **O(k)** for the heap.
 *  • The algorithm mutates the `next` pointers of the original nodes but
 *    performs no new allocations or value copies.
 *
 *  Optimality Proof Sketch – why Ω(N log k) is a lower bound
 *  ---------------------------------------------------------
 *  Model:  comparison–based; the algorithm may only inspect elements via
 *          < or > (no hashing, counting sort, etc.).
 *
 *  1.  Reduction to sorting
 *      –  Put each of the N values into its own 1-element list.
 *      –  Now k = N and merging the k lists produces those N values in
 *        sorted order.
 *
 *  2.  Consequence
 *      –  If a k-way merge ran in T(N,k) comparisons, we could sort N
 *        arbitrary items in T(N,N) comparisons.
 *
 *  3.  Known lower bound
 *      –  Any comparison-based sorting of N items requires Ω(N log N)
 *        comparisons.
 *
 *  4.  Therefore
 *      T(N,N) ≥ c·N log N  ⇒  T(N,k) ≥ c·N log k  for all k ≤ N
 *        (monotonicity in k: merging becomes easier, never harder, as k
 *         decreases).
 *
 *  Conclusion:  Θ(N log k) algorithms (heap or tournament tree) are
 *  asymptotically optimal; no purely comparison-based method can be faster
 *  in the worst case.
 *  ------------------------------------------------------------------------- */
ListNode<int> *MergeKSortedLists_23::mergeKLists(vector<ListNode<int> *> &lists)
{
    // Custom comparator for the priority queue
    auto compare = [](ListNode<int>* a, ListNode<int>* b) {
        return a->val > b->val;
    };

    // Min-heap to store the smallest elements of each list
    priority_queue minHeap(
        compare,                           // Compare
        vector<ListNode<int>*>{}      // Container (deducts T = ListNode<int>*)
    );

    // Add the head of each non-empty list to the heap
    for (auto list : lists) {
        if (list != nullptr) {
            minHeap.push(list);
        }
    }

    // Dummy head to simplify handling of the merged list
    ListNode<int> dummy;
    ListNode<int>* current = &dummy;

    // Merge the lists
    while (!minHeap.empty()) {
        // Get the smallest node from the heap
        ListNode<int>* smallest = minHeap.top();
        minHeap.pop();

        // Append the smallest node to the merged list
        current->next = smallest;
        current = current->next;

        // If the smallest node has a next node, add it to the heap
        if (smallest->next != nullptr) {
            minHeap.push(smallest->next);
        }
    }

    // Get the head of the merged list
    return dummy.next;
}