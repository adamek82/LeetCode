#include "SingleNumber_136.h"

/*
 * 136. Single Number — XOR trick
 * ------------------------------
 * In an array where every element appears exactly twice except for one,
 * we can find the unique element by XOR-ing all numbers together.
 *
 * XOR properties used here:
 *   - x ^ x = 0        → equal pairs cancel out,
 *   - 0 ^ y = y        → neutral element,
 *   - XOR is associative and commutative, so elements can be reordered
 *     and grouped regardless of their positions in the array.
 *
 * As a result, all duplicated values vanish and the remaining value
 * is the element that appears exactly once.
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
