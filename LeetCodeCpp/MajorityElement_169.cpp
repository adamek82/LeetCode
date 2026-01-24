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
int MajorityElement_169::majorityElement(vector<int> &nums)
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
    unordered_map<int, int> frequency; // Hashmap to store frequencies
    int n = nums.size();

    // Count frequencies of each element
    for (int num : nums) {
        frequency[num]++;
        // Check if the current number becomes the majority element
        if (frequency[num] > n / 2) {
            return num;
        }
    }

    // This line will never be reached if the input guarantees a majority element
    return -1;
}
