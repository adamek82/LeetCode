#include "MergeKSortedLists_23.h"
#include "ListNode.h"
#include <queue>
#include <vector>

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
 *  ------------------------------------------------------------------------- */
ListNode<int> *MergeKSortedLists_23::mergeKLists(vector<ListNode<int> *> &lists)
{
    /*
     * Custom comparator for the priority queue (min-heap)
     *
     * Note: std::priority_queue is a *max-heap* by default: top() returns the element
     * considered "largest" by the comparator. The comparator itself answers:
     *   "should `a` be ordered *after* `b`?" (i.e., does `a` have lower priority?)
     *
     * So `a->val > b->val` means: "if `a` has a bigger value than `b`, `a` should come later",
     * which makes smaller values rise to the top => min-heap behavior.
     */
    auto compare = [](ListNode<int>* a, ListNode<int>* b) {
        return a->val > b->val;
    };

    /*
     * Min-heap (std::priority_queue with a custom comparator)
     *
     * Here we use the (Compare, Container) constructor overload:
     *
     *   priority_queue(Compare comp, Container cont);
     *
     * - `compare` is our callable that defines the heap ordering.
     * - The second argument is the *underlying container* used to store elements.
     *   For priority_queue it is typically `std::vector<T>` (must support random-access
     *   iterators because heap algorithms rely on them).
     *
     * Why `vector<ListNode<int>*>{}`?
     * - This passes an *empty container instance* of the right type.
     * - With C++17 class template argument deduction (CTAD), the compiler can deduce:
     *     T         = ListNode<int>*
     *     Container = std::vector<ListNode<int>*>
     *   from this argument.
     *
     * Why not just write `priority_queue<ListNode<int>*, vector<ListNode<int>*>, ...>`?
     * - You can, but this form avoids repeating the element type and lets CTAD infer it
     *   from the comparator + container we provide.
     */
    priority_queue minHeap(
        compare,                      // Compare
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