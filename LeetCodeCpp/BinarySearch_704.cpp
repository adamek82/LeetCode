#include "BinarySearch_704.h"

int BinarySearch_704::search(vector<int> &nums, int target)
{
    int left = 0, right = nums.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2; // Prevents overflow

        if (nums[mid] == target) {
            return mid; // Target found, return its index
        } else if (nums[mid] < target) {
            left = mid + 1; // Search in the right half
        } else {
            right = mid - 1; // Search in the left half
        }
    }

    return -1; // Target not found
}