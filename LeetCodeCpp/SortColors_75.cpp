#include "SortColors_75.h"
#include <array>
#include <vector>

/*
 * Sort Colors (LeetCode 75) — 1-pass “overwrite with three tails”
 *
 * This is a variant of Dutch National Flag, but written as a *single forward pass*
 * that does NOT swap elements in place. Instead, we iterate through the array
 * as a stream and continuously overwrite the prefix with the correct multiset
 * of values seen so far.
 *
 * Indices meaning
 * --------------
 * We maintain three “tails” (rightmost positions) for blocks of 0s, 1s, and 2s:
 *
 *   [0 .. zero]      are all 0
 *   [zero+1 .. one]  are all 1
 *   [one+1 .. two]   are all 2
 *   [two+1 .. end]   not processed / irrelevant yet
 *
 * Initially: zero = one = two = -1, so all blocks are empty.
 *
 * Core invariant
 * --------------
 * After processing some prefix of the input (some number of elements from the
 * original array), the prefix nums[0..two] contains *exactly* the processed
 * elements, already sorted into 0s then 1s then 2s.
 *
 * How updates work (intuition)
 * ----------------------------
 * When you read the next number, you conceptually “append it to the end” of the
 * already processed multiset, and then restore the 0/1/2 block structure.
 *
 * The trick is: updating one block boundary may shift the later blocks, so we
 * rebuild the tail end in the correct order:
 *
 * - If we read a 2: it belongs at the end. So we extend the 2-block by one:
 *       ++two; nums[two] = 2;
 *
 * - If we read a 1: it should go after all 0s but before 2s.
 *   Extending the 1-block by one pushes the 2-block right by one position.
 *   We achieve that by:
 *       ++two; nums[two] = 2;   // reserve new end position for 2s
 *       ++one; nums[one] = 1;   // place the new 1 at the end of 1-block
 *   Effect: 2s are still contiguous at the end; 1s end moved by one.
 *
 * - If we read a 0: it should go at the end of the 0-block (frontmost block).
 *   Extending the 0-block pushes both the 1-block and the 2-block right by one.
 *   So we do it in “back-to-front” order:
 *       ++two;  nums[two]  = 2;
 *       ++one;  nums[one]  = 1;
 *       ++zero; nums[zero] = 0;
 *   This preserves contiguity of all three blocks.
 *
 * Why the order (2 then 1 then 0) matters
 * ---------------------------------------
 * Because `two` is the farthest right boundary. If we placed 0 first, we could
 * overwrite a 1/2 that still needs to stay at the end. Writing in descending
 * color order is like “making room at the back” before inserting earlier colors.
 *
 * Step-by-step examples
 * ---------------------
 * Example A: nums = [2,0,2,1,1,0]
 *
 * Start: zero=one=two=-1, processed prefix empty
 *
 * read 2:
 *   ++two=0: [2]
 *
 * read 0:
 *   ++two=1 -> write 2: [2,2]
 *   ++one=0 -> write 1: [1,2]
 *   ++zero=0-> write 0: [0,2]
 *   (now zero=0, one=0, two=1 => [0][ ][2])
 *
 * read 2:
 *   ++two=2 -> write 2: [0,2,2]
 *
 * read 1:
 *   ++two=3 -> write 2: [0,2,2,2]
 *   ++one=1 -> write 1: [0,1,2,2]
 *
 * read 1:
 *   ++two=4 -> write 2: [0,1,2,2,2]
 *   ++one=2 -> write 1: [0,1,1,2,2]
 *
 * read 0:
 *   ++two=5 -> write 2: [0,1,1,2,2,2]
 *   ++one=3 -> write 1: [0,1,1,1,2,2]
 *   ++zero=1-> write 0: [0,0,1,1,2,2]
 *
 * Done: sorted.
 *
 * Example B: nums = [1,0,1]
 *
 * read 1:
 *   ++two=0 write 2; ++one=0 write 1 => [1]
 *
 * read 0:
 *   ++two=1 write 2 => [1,2]
 *   ++one=1 write 1 => [1,1]
 *   ++zero=0 write 0 => [0,1]
 *
 * read 1:
 *   ++two=2 write 2 => [0,1,2]
 *   ++one=2 write 1 => [0,1,1]
 *
 * Complexity and tradeoffs
 * ------------------------
 * Time:  O(n) (1 pass, constant work per element)
 * Space: O(1)
 *
 * Note: This approach overwrites elements multiple times, but stays simple and
 * branch-light. It relies on the fact we only care about final sorted values,
 * not preserving original positions.
 */
void SortColors_75::sortColors_threeTails(vector<int> &nums)
{
    int zero = -1;
    int one  = -1;
    int two  = -1;

    for (const int num : nums) {
        if (num == 0) {
            nums[++two]  = 2;
            nums[++one]  = 1;
            nums[++zero] = 0;
        } else if (num == 1) {
            nums[++two] = 2;
            nums[++one] = 1;
        } else {
            nums[++two] = 2;
        }
    }
}

/*
 * Sort Colors (LeetCode 75) — counting (2 passes)
 *
 * Idea
 * ----
 * Since values are only {0,1,2}, we can count how many of each occur,
 * then overwrite the array with that many 0s, then 1s, then 2s.
 *
 * This does not do any swaps and performs exactly n writes in the fill phase,
 * at the cost of an extra pass to count.
 *
 * Complexity
 * ----------
 * Time:  O(n) (two linear passes)
 * Space: O(1) (3 counters)
 */
void SortColors_75::sortColors_counting(vector<int> &nums)
{
    enum Color : int { Red = 0, White = 1, Blue = 2, ColorCount = 3 };

    std::array<int, ColorCount> counts{0, 0, 0};

    for (int c : nums) {
        ++counts[c];
    }

    int idx = 0;
    for (int color = Red; color <= Blue; ++color) {
        for (int t = 0; t < counts[color]; ++t) {
            nums[idx++] = color;
        }
    }
}
