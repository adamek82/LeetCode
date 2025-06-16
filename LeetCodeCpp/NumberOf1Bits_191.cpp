#include "NumberOf1Bits_191.h"

/*
 * Number of 1 Bits — Brian Kernighan Trick  — Correctness Sketch
 *
 * Operation  n &= n-1  clears the **least-significant set bit** each time.
 * Loop until n==0, incrementing a counter.
 *
 * Complexity
 *   – Time:  O(k)   where k = number of set bits (≤32) — fast for sparse ints.
 *   – Space: O(1)
 *
 * Follow-up optimisation
 *   For many calls, pre-compute popcount of all 256 possible bytes and sum
 *   four table lookups per 32-bit word; reduces to O(1) with tiny constant.
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
