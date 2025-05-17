#include "RemoveDuplicatesFromSortedArrayII_80.h"

int RemoveDuplicatesFromSortedArrayII_80::removeDuplicates(vector<int> &nums)
{
    int k = 0; // Writer pointer

    for(int i = 0; i < (int)nums.size(); i++) {
        // If we have less than 2 elements, we always insert.
        // If the current element is different from the element
        // at position k-2, then we also insert.
        if(k < 2 || nums[i] != nums[k - 2]) {
            nums[k++] = nums[i];
        }
    }

    return k;
}