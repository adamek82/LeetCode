#include "RemoveElement_27.h"

int RemoveElement_27::removeElement(vector<int>& nums, int val)
{
    size_t write = 0;

    for (int num : nums) {
        if (num != val)
            nums[write++] = num;
    }

    return static_cast<int>(write);
}
