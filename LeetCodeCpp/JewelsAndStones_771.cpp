#include "JewelsAndStones_771.h"

/*
 * Jewels and Stones (LeetCode 771)
 *
 * Counts how many characters in `stones` are also present in `jewels`.
 *
 * Idea:
 *   - Use a boolean lookup table of size 128 (ASCII) where isJewel[c] tells
 *     whether character c is a jewel.
 *   - First, iterate over `jewels` and mark each character as true in the
 *     table. We cast to unsigned char to safely use the character value as
 *     an array index even if `char` is signed on this platform.
 *   - Then, iterate over `stones` and for each character check the table; if
 *     isJewel[c] is true, increment the counter.
 *   - Return the total count.
 *
 * Time complexity:
 *   - O(J + S), where J = jewels.length() and S = stones.length().
 *
 * Space complexity:
 *   - O(1) extra space: the lookup table size (128) is constant.
 */
int JewelsAndStones_771::numJewelsInStones(string jewels, string stones)
{
    bool isJewel[128] = {false};                 // ASCII lookup table
    for (char c : jewels)
        isJewel[static_cast<unsigned char>(c)] = true;

    int cnt = 0;
    for (char c : stones)
        if (isJewel[static_cast<unsigned char>(c)])
            ++cnt;

    return cnt;
}
