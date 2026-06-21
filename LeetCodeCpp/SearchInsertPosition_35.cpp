#include "SearchInsertPosition_35.h"

// Closed-interval binary search.
// If target is not found, left ends at the correct insertion position.
// See Docs/Algorithms/Binary_Search.md for invariants and correctness proof.
int SearchInsertPosition_35::searchInsert(vector<int> &nums, int target)
{
    int left = 0;
    int right = static_cast<int>(nums.size()) - 1; // Empty vector gives right == -1.

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (nums[mid] == target) {
            return mid;
        }

        if (nums[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return left;
}
