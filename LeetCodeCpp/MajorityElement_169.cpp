#include "MajorityElement_169.h"
#include <unordered_map>

/*
 * Boyer–Moore Majority Vote — Correctness Sketch
 *
 * Invariant (pair-cancellation):
 *   After scanning the first i elements, the multiset of those i elements
 *   can be reduced — by repeatedly deleting pairs of **different** values —
 *   to exactly ‘count’ copies of the current ‘candidate’.
 *
 * Why the invariant holds
 *   – If the next value == candidate  → we add an unmatched copy (count++).
 *   – Else                            → we delete a mismatching pair (count--).
 *   – If count hits 0                 → all copies of the old candidate have
 *                                       been paired away; the next element
 *                                       starts a new (count = 1) multiset.
 *
 * Consequence at the end of the scan
 *   • We finish with count > 0, so one value survived all pair deletions:
 *     the final ‘candidate’.
 *   • Let M be the true majority element (guaranteed to exist, k > n/2).
 *     Every time we delete a pair we remove at most one copy of M, but the
 *     minority elements are exhausted first, so ≥1 copy of M survives.
 *   • Only one value survives, hence candidate == M.
 *
 * Complexity
 *   – Time:  O(n)  (single pass)
 *   – Space: O(1)  (two integers)
 */
int MajorityElement_169::majorityElement(const vector<int> &nums)
{
    int candidate = nums[0];
    int count = 0;

    for (int num : nums) {
        if (count == 0) {
            candidate = num;  // Assign a new candidate
        }
        count += (candidate == num) ? 1 : -1;  // Adjust count based on the match
    }

    return candidate;  // Return the majority candidate
}

int MajorityElement_169::majorityElementWithHashmap(const vector<int>& nums) {
    unordered_map<int, size_t> frequency;
    const size_t threshold = nums.size() / 2;

    for (int num : nums) {
        // Count frequencies of each element
        const size_t cnt = ++frequency[num];

        // Check if the current number becomes the majority element
        if (cnt > threshold) return num;
    }
    return -1;
}

/*
 * Bit Counting / Bitwise Reconstruction — Correctness Sketch
 *
 * Idea (majority per bit):
 *   Reconstruct the majority element M bit-by-bit.
 *   For each bit position b in [0..31], count how many array values have
 *   that bit set (ones). If ones > floor(n/2), then the majority element’s
 *   bit b must be 1; otherwise it must be 0.
 *
 * Why this works
 *   Let M be the true majority element, appearing k times, with k > n/2.
 *   Fix any bit position b.
 *
 *   Case 1: bit b of M is 1
 *     Among the k occurrences of M, all contribute a 1 at bit b.
 *     Therefore ones >= k > n/2, so the algorithm sets bit b in ans.
 *
 *   Case 2: bit b of M is 0
 *     The only contributors of 1 at bit b are non-M elements (there are n-k of them).
 *     Therefore ones <= n-k < n/2, so the algorithm does NOT set bit b in ans.
 *
 *   Hence for every bit b, ans[b] == M[b]. So ans == M.
 *
 * Note on negatives (two’s complement)
 *   We count bits on the 32-bit representation (including the sign bit b=31)
 *   by casting to uint32_t. Reconstructing all 32 bits yields the exact same
 *   two’s-complement bit pattern of M. Casting back to int returns M (including
 *   negative values if applicable).
 *
 * Complexity
 *   – Time:  O(32 * n) = O(n)  (32 bit positions, full scan per bit)
 *   – Space: O(1)             (a few counters)
 */
int MajorityElement_169::majorityElementWithBitCounting(const vector<int> &nums)
{
    int n = (int)nums.size();
    uint32_t ans = 0;

    for (int b = 0; b < 32; ++b) {
        int ones = 0;
        uint32_t mask = 1u << b;

        for (int x : nums) {
            if ((uint32_t)x & mask) ++ones;
        }

        if (ones > n / 2) ans |= mask;
    }

    return (int)ans;
}
