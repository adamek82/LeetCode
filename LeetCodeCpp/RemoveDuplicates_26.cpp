#include "RemoveDuplicates_26.h"

int RemoveDuplicates_26::removeDuplicates(vector<int>& nums) {
    const int n = (int)nums.size();
    if (n == 0) return 0;

    int k = 1; // write index for next unique
    for (int i = 1; i < n; ++i) {
        if (nums[i] != nums[k - 1]) {
            nums[k++] = nums[i];
        }
    }
    return k;
}
