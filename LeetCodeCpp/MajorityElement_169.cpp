#include "MajorityElement_169.h"

/*
 * Theoretical Proof:
 *
 * Let the majority element be 'M' and let it appear k times in the array,
 * where k > n / 2. All other elements together appear at most n - k times.
 *
 * The algorithm works by maintaining a balance:
 * 1. Each occurrence of 'M' increases the count by 1.
 * 2. Each occurrence of a non-'M' element decreases the count by 1.
 *
 * At any point in the iteration:
 * - The net count is the difference between occurrences of 'M' and
 *   non-'M' elements processed so far.
 *
 * By the end of the array:
 * - Total contribution to the count from 'M' is +k.
 * - Total contribution to the count from other elements is at most -(n - k).
 *
 * Since k > n / 2:
 * - k - (n - k) = 2k - n > 0.
 * - Thus, the count is guaranteed to be positive at the end of the iteration.
 *
 * Therefore, the majority element 'M' remains the final candidate.
 */
int MajorityElement_169::majorityElement(vector<int> &nums)
{
    //
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