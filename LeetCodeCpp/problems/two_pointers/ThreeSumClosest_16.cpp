#include "ThreeSumClosest_16.h"
#include <algorithm>
#include <cstdlib>      // for llabs

/*
 * ThreeSum Closest (LeetCode 16)
 *
 * This algorithm finds a triplet whose sum is closest to a given
 * target using the classic sort + two–pointer O(n^2) approach.
 *
 * Idea:
 *   - Sort nums in non-decreasing order.
 *   - Fix the first element at index i, and then run a two-pointer
 *     search on the suffix [i+1, n-1] for the best pair completing
 *     nums[i].
 *   - For each configuration (i, l, r) we compute:
 *
 *         sum = nums[i] + nums[l] + nums[r]
 *
 *     and compare its distance to target with the best distance seen
 *     so far. If it is strictly better, we update the answer.
 *
 *   - Pointer moves:
 *       * If sum == target:
 *           - We are at distance 0 from target, which is optimal,
 *             so we can return immediately.
 *
 *       * If sum < target:
 *           - The sum is too small, so to get closer to target we
 *             need a larger sum -> move the left pointer (l++) to
 *             pick a larger value (array is sorted).
 *
 *       * If sum > target:
 *           - The sum is too large, so to get closer to target we
 *             need a smaller sum -> move the right pointer (r--) to
 *             pick a smaller value.
 *
 * Correctness sketch:
 *   - For a fixed i, the pair (l, r) starts at the widest window
 *     [i+1, n-1] and moves monotonically inward:
 *         - l only increases, r only decreases.
 *     This ensures each pair (l, r) is considered at most once.
 *
 *   - When we move l to l+1 (because sum < target), all pairs using
 *     the old l with any r' < r would produce sums even smaller than
 *     the current sum, hence strictly farther from target on the
 *     "too small" side. They cannot give a better (closer) result
 *     than the current configuration we have just checked.
 *
 *   - Symmetrically, when we move r to r-1 (because sum > target),
 *     all pairs using the old r with any l' > l would produce sums
 *     even larger than the current sum, thus strictly worse on the
 *     "too large" side.
 *
 *   - Therefore, skipping these states is safe: if any configuration
 *     were closer to target, it would be reached by the monotone
 *     pointer adjustments before being skipped.
 *
 *   - Across all choices of i, we track the globally best sum seen.
 *     When the loops finish, this best value is the sum of the
 *     triplet with minimal distance to target.
 *
 * Complexity:
 *   - Sorting: O(n log n).
 *   - Outer loop over i: O(n).
 *   - For each i, the two pointers l and r together move at most
 *     O(n) steps (each only moves inward).
 *   - Total time complexity: O(n^2).
 *   - Extra space complexity: O(1) beyond the input array, since
 *     sorting is done in-place.
 */
int ThreeSumClosest_16::threeSumClosest(vector<int>& nums, int target)
{
    sort(nums.begin(), nums.end());
    const int n = static_cast<int>(nums.size());

    // Initialize with the first possible triplet (n >= 3 by constraints).
    int best = nums[0] + nums[1] + nums[2];

    for (int i = 0; i < n - 2; ++i) {
        int l = i + 1;
        int r = n - 1;

        while (l < r) {
            const int sum = nums[i] + nums[l] + nums[r];

            // Cast one operand to long long so the subtraction is performed
            // in 64-bit arithmetic (the other int is promoted automatically),
            // avoiding potential overflow before taking the absolute value.
            long long curDiff = llabs(static_cast<long long>(sum)    - target);
            long long bestDiff = llabs(static_cast<long long>(best)  - target);

            if (curDiff < bestDiff) {
                best = sum;
            }

            if (sum == target) {
                // Perfect match; cannot get closer than distance 0.
                return target;
            } else if (sum < target) {
                ++l;        // need a larger sum
            } else {
                --r;        // need a smaller sum
            }
        }
    }

    return best;
}
