#include "RemoveDuplicatesFromSortedArrayII_80.h"

int RemoveDuplicatesFromSortedArrayII_80::removeDuplicates(vector<int>& nums)
{
    size_t write = 0;

    for (int num : nums) {
        if (write < 2 || num != nums[write - 2])
            nums[write++] = num;
    }

    return static_cast<int>(write);
}
