#include "FindMinimumInRotatedSortedArray_153.h"

// Boundary binary search over a rotated sorted array.
// See Docs/Algorithms/Binary_Search.md for the minimum-in-rotated-array pattern.
int FindMinimumInRotatedSortedArray_153::findMin(vector<int> &nums)
{
    int left = 0;
    int right = static_cast<int>(nums.size()) - 1;

    while (left < right) {
        int mid = left + (right - left) / 2;

        if (nums[mid] > nums[right]) {
            left = mid + 1;
        } else {
            right = mid; // mid can still be the minimum.
        }
    }

    return nums[left];
}
