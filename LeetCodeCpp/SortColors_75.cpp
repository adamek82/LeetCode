#include "SortColors_75.h"

void SortColors_75::sortColors(std::vector<int> &nums)
{
    int zero = -1;  // The rightmost index where we've placed a 0
    int one = -1;   // The rightmost index where we've placed a 1
    int two = -1;   // The rightmost index where we've placed a 2

    for (const int num : nums) {
        if (num == 0) {         // Encountered a 0
            nums[++two] = 2;    // - first move 'two' forward and place a 2
            nums[++one] = 1;    // - then move 'one' forward and place a 1
            nums[++zero] = 0;   // - finally move 'zero' forward and place a 0
        } else if (num == 1) {  // Encountered a 1:
            nums[++two] = 2;    // - move 'two' forward and place a 2
            nums[++one] = 1;    // - move 'one' forward and place a 1
        } else {                // Encountered a 2:
            nums[++two] = 2;    // - only move 'two' forward and place a 2
        }
    }
}