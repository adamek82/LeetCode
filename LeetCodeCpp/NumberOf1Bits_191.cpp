#include "NumberOf1Bits_191.h"
#include <array>

/*
 * 191. Number of 1 Bits — two implementations
 * -------------------------------------------
 * 1) Brian Kernighan trick (hammingWeightKernighan)
 *    ---------------------------------------------
 *    We repeatedly clear the least-significant set bit of n and count how many
 *    times we can do this before n becomes 0.
 *
 *    Key identity:
 *      For any n > 0, the expression (n - 1) flips all bits from the least-
 *      significant 1-bit to the right (including that 1-bit). Therefore:
 *
 *          n & (n - 1)
 *
 *      is equal to n with its least-significant 1-bit cleared.
 *
 *    Algorithm:
 *      - Initialize cnt = 0.
 *      - While n != 0:
 *          n = n & (n - 1)   // drop the lowest set bit
 *          ++cnt
 *      - When n reaches 0, the number of iterations equals the number of 1-bits.
 *
 *    Complexity:
 *      - Time:  O(k), where k is the number of set bits in n (≤ 32 for uint32_t).
 *      - Space: O(1).
 *
 * 2) Byte lookup table (hammingWeightLookup)
 *    ---------------------------------------
 *    If we need to call popcount many times, we can precompute the popcount
 *    for all 256 possible byte values and then, for each 32-bit number:
 *
 *      - Split it into 4 bytes.
 *      - Sum table[byte0] + table[byte1] + table[byte2] + table[byte3].
 *
 *    With a constexpr helper we can build this table at compile time using
 *    the Kernighan trick itself, so we don't have to write the 256 values
 *    manually.
 *
 *    Complexity:
 *      - Time:  O(1) per call with a very small constant.
 *      - Space: 256-byte lookup table.
 */

// 1) Brian Kernighan implementation
int NumberOf1Bits_191::hammingWeightKernighan(uint32_t n)
{
    int cnt = 0;
    while (n) {
        n &= (n - 1);   // drop least-significant set bit
        ++cnt;
    }
    return cnt;
}

// Helper: build a 256-entry popcount table at compile time.
static constexpr std::array<uint8_t, 256> makePopcountTable()
{
    std::array<uint8_t, 256> table{};

    for (int i = 0; i < 256; ++i) {
        uint32_t x = static_cast<uint32_t>(i);
        uint8_t count = 0;
        while (x) {
            x &= (x - 1);  // Brian Kernighan trick on a byte
            ++count;
        }
        table[i] = count;
    }

    return table;
}

static constexpr std::array<uint8_t, 256> POPCOUNT_TABLE = makePopcountTable();

// 2) Lookup-table implementation
int NumberOf1Bits_191::hammingWeightLookup(uint32_t n)
{
    // Extract 4 bytes and sum precomputed popcounts.
    return POPCOUNT_TABLE[n        & 0xFFu]
         + POPCOUNT_TABLE[(n >> 8) & 0xFFu]
         + POPCOUNT_TABLE[(n >> 16) & 0xFFu]
         + POPCOUNT_TABLE[(n >> 24) & 0xFFu];
}
