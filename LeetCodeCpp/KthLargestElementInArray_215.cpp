#include "KthLargestElementInArray_215.h"

int KthLargestElementInArray_215::findKthLargest(vector<int> &nums, int k)
{
    // Using a max-heap: O(n log n) time and O(n) space
    priority_queue<int> maxHeap;

    // Push all elements into the max-heap
    for (int num : nums) {
        maxHeap.push(num);
    }

    // Pop from the heap k-1 times
    for (int i = 0; i < k - 1; i++) {
        maxHeap.pop();
    }

    // The top of the heap is the k-th largest element
    return maxHeap.top();
}