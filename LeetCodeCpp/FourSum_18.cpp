#include "FourSum_18.h"
#include <vector>
#include <algorithm>

/*
 * FourSum (LeetCode 18)
 *
 * This algorithm finds all unique quadruplets (i, j, l, r) such that
 * nums[i] + nums[j] + nums[l] + nums[r] == target. It generalizes the
 * 3Sum two–pointer idea to 4Sum in O(n^3) time.
 *
 * Idea:
 *   - Sort the array first. Sorting enables:
 *       (1) a deterministic order for the two-pointer scan,
 *       (2) easy skipping of duplicates to ensure uniqueness.
 *
 *   - Fix the first index i in [0, n-4], skipping duplicates of nums[i].
 *   - For each i, fix the second index j in [i+1, n-3], skipping duplicates
 *     of nums[j].
 *   - On the remaining suffix [j+1, n-1], run a classic two-pointer scan:
 *       l starts at j+1, r starts at n-1.
 *
 *   - At each step, compute:
 *
 *         sum = nums[i] + nums[j] + nums[l] + nums[r]   (in 64-bit)
 *
 *     and compare it with the 64-bit target:
 *       * If sum == target:
 *           - Record the quadruplet [nums[i], nums[j], nums[l], nums[r]].
 *           - Move l forward and r backward, skipping duplicates to avoid
 *             producing the same quadruplet multiple times.
 *       * If sum < target:
 *           - Increase the sum by moving l++ (towards larger values).
 *       * If sum > target:
 *           - Decrease the sum by moving r-- (towards smaller values).
 *
 * Duplicates and uniqueness:
 *   - After sorting, equal values are adjacent.
 *   - For i:
 *       if (i > 0 && nums[i] == nums[i - 1]) continue;
 *     guarantees that we never start from the same first value twice.
 *   - For j:
 *       if (j > i + 1 && nums[j] == nums[j - 1]) continue;
 *     ensures we never reuse the same second value with the same i.
 *   - For l and r:
 *       after pushing a quadruplet, we advance l and r past any equal
 *       neighbors before continuing.
 *   - As a result, each distinct quadruplet is generated exactly once.
 *
 * 64-bit arithmetic:
 *   - nums[i] can be as large as 1e9, so the quadruple sum can reach 4e9,
 *     which does not fit in a 32-bit signed int.
 *   - We compute the sum in long long and compare it against a long long
 *     copy of target to avoid overflow:
 *
 *         long long sum = (long long)nums[i] + nums[j] + nums[l] + nums[r];
 *         long long targetLL = target;
 *
 * Complexity:
 *   - Sorting: O(n log n).
 *   - Outer loop over i: O(n).
 *   - For each i, loop over j: O(n).
 *   - For each (i, j), a two-pointer scan (l, r) is O(n).
 *   - Total time complexity: O(n^3).
 *   - Extra space complexity: O(1) beyond the input array and the output
 *     container, ignoring the stack used internally by std::sort.
 */
vector<vector<int>> FourSum_18::fourSum(vector<int>& nums, int target)
{
    vector<vector<int>> res;
    sort(nums.begin(), nums.end());
    const int n = static_cast<int>(nums.size());
    const long long targetLL = static_cast<long long>(target);

    for (int i = 0; i < n - 3; ++i) {
        if (i > 0 && nums[i] == nums[i - 1]) continue; // skip duplicate first

        for (int j = i + 1; j < n - 2; ++j) {
            if (j > i + 1 && nums[j] == nums[j - 1]) continue; // skip duplicate second

            int l = j + 1;
            int r = n - 1;

            while (l < r) {
                long long sum =
                    static_cast<long long>(nums[i]) +
                    nums[j] +
                    nums[l] +
                    nums[r];

                if (sum == targetLL) {
                    res.push_back({nums[i], nums[j], nums[l], nums[r]});

                    // skip duplicates for l and r
                    while (l < r && nums[l] == nums[l + 1]) ++l;
                    while (l < r && nums[r] == nums[r - 1]) --r;
                    ++l;
                    --r;
                } else if (sum < targetLL) {
                    ++l;
                } else { // sum > targetLL
                    --r;
                }
            }
        }
    }

    return res;
}
