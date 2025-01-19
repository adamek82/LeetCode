#include "SearchInsertPosition_35.h"

int SearchInsertPosition_35::searchInsert(std::vector<int> &nums, int target)
{
    int left = 0, right = nums.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2; // Prevents overflow

        if (nums[mid] == target) {
            return mid; // Target found, return its index
        } else if (nums[mid] < target) {
            left = mid + 1; // Narrow search to the right half
        } else {
            right = mid - 1; // Narrow search to the left half
        }
    }

    // If the loop ends, `left` is the insertion point
    return left;
}