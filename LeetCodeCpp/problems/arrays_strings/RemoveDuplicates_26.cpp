#include "RemoveDuplicates_26.h"

int RemoveDuplicates_26::removeDuplicates(vector<int>& nums)
{
    if (nums.empty())
        return 0;

    size_t write = 1;

    for (size_t read = 1; read < nums.size(); ++read) {
        if (nums[read] != nums[write - 1])
            nums[write++] = nums[read];
    }

    return static_cast<int>(write);
}
