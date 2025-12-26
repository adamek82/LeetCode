#include "KthLargestElementInArray_215.h"

int KthLargestElementInArray_215::findKthLargest_MaxHeap(vector<int> &nums, int k)
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

int KthLargestElementInArray_215::findKthLargest_MinHeap(vector<int> &nums, int k)
{
    // min-heap keeps the k largest elements; top() is the smallest among them
    priority_queue<int, vector<int>, greater<int>> pq;

    for (int x : nums) {
        pq.push(x);
        if (static_cast<int>(pq.size()) > k) pq.pop();
    }

    // Assumes 1 <= k <= nums.size()
    return pq.top();
}
