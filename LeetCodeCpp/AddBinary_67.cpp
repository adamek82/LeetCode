#include "AddBinary_67.h"
#include <algorithm>      // for reverse

using namespace std;

/*
 * Add Binary (LeetCode 67) — Back-to-Front Addition — Correctness Sketch
 * ---------------------------------------------------------------------
 * Idea:
 *   Add two binary numbers exactly like “manual” addition, but starting from
 *   the least significant bits (the right ends of the strings) and carrying
 *   to the left.
 *
 * State:
 *   i points to the current bit of a (from right to left),
 *   j points to the current bit of b (from right to left),
 *   carry is the incoming carry into the current bit position (0 or 1).
 *
 * Loop invariant:
 *   After processing k rightmost positions, the algorithm has produced the
 *   correct k least-significant bits of the sum, and carry equals the carry-out
 *   that must be added into the next (more significant) position.
 *
 * Step:
 *   At each iteration, take the available bits at i and j (or treat them as 0
 *   if the pointer is already past the left end) plus carry. This total can be
 *   0..3:
 *     - the output bit for this position is total mod 2,
 *     - the next carry is total / 2.
 *   This matches the truth table of binary addition, so the produced bit and
 *   carry are correct for that position.
 *
 * Termination:
 *   The loop continues while any input bits remain or carry is non-zero.
 *   When it stops, all positions have been processed and any final carry has
 *   been accounted for, so the entire sum is correct.
 *
 * Output order:
 *   Bits are generated from least significant to most significant, so the
 *   accumulated result is reversed once at the end to return MSB→LSB order.
 *
 * Complexity:
 *   – Time:  O(max(|a|, |b|))  (each bit is processed once)
 *   – Space: O(max(|a|, |b|))  (result length is at most max+1)
 */
string AddBinary_67::addBinary(string a, string b)
{
    string res;
    int i = static_cast<int>(a.size()) - 1;
    int j = static_cast<int>(b.size()) - 1;
    int carry = 0;

    while (i >= 0 || j >= 0 || carry) {
        int sum = carry;
        if (i >= 0) sum += a[i--] - '0';
        if (j >= 0) sum += b[j--] - '0';
        res.push_back(char('0' + (sum & 1)));
        carry = sum >> 1;
    }
    reverse(res.begin(), res.end());
    return res;
}
