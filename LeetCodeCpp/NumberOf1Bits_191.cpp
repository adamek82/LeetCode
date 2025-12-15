#include "NumberOf1Bits_191.h"

/*
 * 191. Number of 1 Bits — Brian Kernighan trick
 * ---------------------------------------------
 * We repeatedly clear the least-significant set bit of n and count how many
 * times we can do this before n becomes 0.
 *
 * Key identity:
 *   For any n > 0, the expression (n - 1) flips all bits from the least-
 *   significant 1-bit to the right (including that 1-bit). Therefore:
 *
 *       n & (n - 1)
 *
 *   is equal to n with its least-significant 1-bit cleared.
 *
 * Algorithm:
 *   - Initialize cnt = 0.
 *   - While n != 0:
 *       n = n & (n - 1)   // drop the lowest set bit
 *       ++cnt
 *   - When n reaches 0, we have performed exactly as many iterations as
 *     there were 1-bits in the original value; cnt is the popcount.
 *
 * Complexity:
 *   - Time:  O(k), where k is the number of set bits in n (≤ 32 for uint32_t),
 *            which is very fast especially when n is sparse.
 *   - Space: O(1).
 *
 * Follow-up (many calls):
 *   - Precompute popcount for all 256 possible byte values and sum four table
 *     lookups per 32-bit word to get O(1) per query with a tiny constant.
 */
int NumberOf1Bits_191::hammingWeight(uint32_t n)
{
    int cnt = 0;
    while (n) {
        n &= (n - 1);   // drop LS set bit
        ++cnt;
    }
    return cnt;
}
