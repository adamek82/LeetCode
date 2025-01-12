#include "MergeKSortedLists_23.h"

ListNode<int> *MergeKSortedLists_23::mergeKLists(std::vector<ListNode<int> *> &lists)
{
    // Custom comparator for the priority queue
    auto compare = [](ListNode<int>* a, ListNode<int>* b) {
        return a->val > b->val;
    };

    // Min-heap to store the smallest elements of each list
    std::priority_queue<ListNode<int>*, std::vector<ListNode<int>*>, decltype(compare)> minHeap(compare);

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