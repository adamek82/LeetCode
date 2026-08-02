#include "KthLargestElementInArray_215.h"
#include <queue>

/*
 * Max-heap approach:
 * 1) Insert all elements into a max-heap.
 * 2) Remove the largest element k-1 times.
 * 3) The heap top is then the k-th largest element.
 *
 * Time:  O(n log n)
 *        - n insertions into the heap, each O(log n)
 *        - k-1 removals, each O(log n)
 * Space: O(n)
 *        - the heap stores all n elements
 */
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

/*
 * Min-heap of size k approach:
 * 1) Iterate through the array and push each element into a min-heap.
 * 2) If the heap size exceeds k, remove the smallest element.
 * 3) The heap always keeps the k largest elements seen so far.
 * 4) The heap top is the smallest among those k elements,
 *    which is exactly the k-th largest element overall.
 *
 * Time:  O(n log k)
 *        - each push/pop is O(log k), and heap size never exceeds k
 * Space: O(k)
 *        - the heap stores at most k elements
 */
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
