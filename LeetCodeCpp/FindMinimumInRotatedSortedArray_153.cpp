#include "FindMinimumInRotatedSortedArray_153.h"

int FindMinimumInRotatedSortedArray_153::findMin(std::vector<int> &nums)
{
    int left = 0, right = nums.size() - 1;
    
    // Binary search loop
    while (left < right) {
        int mid = left + (right - left) / 2;
        
        // If the mid element is greater than the rightmost element,
        // then the minimum is in the right half
        if (nums[mid] > nums[right]) {
            left = mid + 1;
        }
        // Else the minimum is in the left half (including mid)
        else {
            right = mid;
        }
    }
    
    // When the loop ends, left == right, pointing to the smallest element
    return nums[left];
}