#include "SingleNumber_136.h"

/*
 * 136. Single Number — XOR trick
 * ------------------------------
 * In an array where every element appears exactly twice except for one,
 * we can find the unique element by XOR-ing all numbers together:
 *
 *   - x ^ x = 0  → pairs cancel out,
 *   - 0 ^ y = y  → the remaining value is the single number.
 *
 * So a single pass with an accumulator `result ^= x` returns the element that
 * appears exactly once.
 *
 * Time:  O(n)
 * Space: O(1)
 */
int SingleNumber_136::singleNumber(vector<int>& nums)
{
    int result = 0;
    for (int x : nums) {
        result ^= x;
    }
    return result;
}
