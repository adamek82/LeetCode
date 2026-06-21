#include "BinarySearch_704.h"

// Classic closed-interval binary search.
// See Docs/Algorithms/Binary_Search.md for invariants and correctness proof.
int BinarySearch_704::search(vector<int> &nums, int target)
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

    return -1;
}
