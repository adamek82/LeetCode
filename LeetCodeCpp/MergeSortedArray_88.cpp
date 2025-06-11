#include "MergeSortedArray_88.h"

/*
 * Merge Sorted Array — Back-Fill Two-Pointer  — Correctness Sketch
 *
 * Let i = m-1 (last real element of nums1), j = n-1 (last of nums2),
 * k = m+n-1 (last slot of the buffer in nums1).
 *
 * Loop invariant
 *   • Elements in positions 0..k of nums1 are *not yet* in final order.
 *   • Elements in positions k+1..m+n-1 are already the largest k′ elements
 *     of the union and are in non-decreasing order.
 *
 * Step
 *   – Compare nums1[i] and nums2[j]; place the larger at nums1[k].
 *   – Decrement the corresponding pointer (i or j) and k.
 *
 * Termination
 *   • When j < 0, all of nums2 is consumed ⇒ remainder of nums1 is already
 *     correct.  When i < 0, copy the remaining prefix of nums2 (if any)
 *     because nums1’s original portion is exhausted.
 *
 * Complexity
 *   – Time:  O(m + n)  — each element moved exactly once.
 *   – Space: O(1)      — constant counters only.
 */
void MergeSortedArray_88::merge(vector<int>& nums1, int m,
                                const vector<int>& nums2, int n)
{
    int i = m - 1, j = n - 1, k = m + n - 1;

    while (j >= 0) {                          // continue until nums2 done
        if (i >= 0 && nums1[i] > nums2[j]) {
            nums1[k--] = nums1[i--];          // take from nums1
        } else {
            nums1[k--] = nums2[j--];          // take from nums2
        }
    }
}