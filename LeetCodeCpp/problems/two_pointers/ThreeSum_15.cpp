#include "ThreeSum_15.h"
#include <algorithm>

/*
 * ThreeSum (LeetCode 15)
 *
 * This algorithm finds all unique triplets (i, l, r) such that
 * nums[i] + nums[l] + nums[r] == 0. It uses the optimal O(n^2)
 * approach based on sorting and the two–pointer technique.
 *
 * How it works:
 *   - First we sort the array. Sorting enables two key things:
 *       (1) efficient two-pointer scanning,
 *       (2) easy skipping of duplicates.
 *
 *   - We iterate i from 0 to n-3. The value nums[i] is the first
 *     element of the triplet. If nums[i] equals nums[i-1], we skip
 *     this i to avoid generating duplicate triplets.
 *
 *   - For each fixed i, we use two pointers:
 *       l = i + 1   (left pointer)
 *       r = n - 1   (right pointer)
 *     We compute: sum = nums[i] + nums[l] + nums[r].
 *
 *       * If sum == 0:
 *           - We add the triplet to the result.
 *           - We skip all duplicates of nums[l] and nums[r],
 *             because repeating them would generate identical triplets.
 *           - Then we move both pointers (l++, r--).
 *
 *       * If sum < 0:
 *           - The sum is too small, so we move l to the right to
 *             increase the total (the array is sorted).
 *
 *       * If sum > 0:
 *           - The sum is too large, so we move r to the left to
 *             decrease the total.
 *
 * Why this is optimal:
 *   - After sorting (O(n log n)), each i uses a linear two-pointer
 *     scan (O(n)). Summed over all i, this gives overall O(n^2).
 *   - There is no known solution that improves the worst-case
 *     complexity below O(n^2). In fact, 3SUM is a classic problem
 *     used to establish conditional lower bounds in computational
 *     complexity (many problems are known to be “3SUM-hard”).
 *   - Therefore this algorithm is considered optimal for general input.
 *
 * Implementation details:
 *   - sum is computed as long long to prevent overflow when nums
 *     contains large values.
 *   - Duplicate skipping is done both for nums[i] (outer loop)
 *     and for nums[l]/nums[r] (inner loop) to ensure unique output.
 */
vector<vector<int>> ThreeSum_15::threeSum(vector<int> &nums)
{
    vector<vector<int>> res;
    sort(nums.begin(), nums.end());
    const int n = static_cast<int>(nums.size());

    for (int i = 0; i < n - 2; ++i) {
        if (i && nums[i] == nums[i - 1]) continue;          // skip duplicate first element
        int l = i + 1, r = n - 1;
        while (l < r) {
            long long sum = static_cast<long long>(nums[i]) +
                             nums[l] + nums[r];
            if (sum == 0) {
                res.push_back({nums[i], nums[l], nums[r]});
                while (l < r && nums[l] == nums[l + 1]) ++l; // skip duplicates
                while (l < r && nums[r] == nums[r - 1]) --r;
                ++l; --r;
            } else if (sum < 0) {
                ++l;
            } else {
                --r;
            }
        }
    }
    return res;
}
