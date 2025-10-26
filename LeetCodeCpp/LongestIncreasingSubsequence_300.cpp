#include "LongestIncreasingSubsequence_300.h"

/*
 * Longest Increasing Subsequence — O(N log N) (length only)
 * ---------------------------------------------------------
 * Concept:
 *   Maintain an array `tails`, where tails[len-1] is the smallest possible
 *   ending value (tail) of any strictly increasing subsequence (IS) of length `len`
 *   seen so far while scanning left→right.
 *
 *   Key property: `tails` is strictly increasing as a sequence of values and
 *   is pointwise minimal among all feasible tail arrays for the processed prefix.
 *
 * Intuition (why replacing by x helps):
 *   When a new element x arrives, two cases:
 *   1) x is larger than all current tails → we can extend the longest IS by x,
 *      so push_back(x).
 *   2) Otherwise, find the first tails[i] >= x and set tails[i] = x.
 *      This keeps the existence of a length-(i+1) IS but with a smaller tail,
 *      which makes it *easier* to extend later. We never reduce any achievable
 *      LIS length by doing this replacement.
 *
 * Invariants (maintained after each processed element):
 *   I1. For every k in [1..|tails|], there exists a strictly increasing subsequence
 *       of length k whose last element equals tails[k-1].
 *   I2. `tails` is strictly increasing: tails[0] < tails[1] < ... < tails[L-1].
 *   I3. Pointwise minimality: For any other feasible "tail array" T' produced from
 *       the same prefix (i.e., T'[k-1] is the tail of some IS of length k),
 *       we have tails[k-1] <= T'[k-1] for all k.
 *
 * Sketch proofs:
 *   - Base: After first element x, tails = [x]. I1 holds (length-1 IS = [x]),
 *     I2 holds trivially, I3 holds by definition (x is the minimal 1-tail seen).
 *
 *   - Maintenance (I1):
 *       Case A (extend): if x > tails.back(), appending x creates a new IS
 *       of length L+1 ending with x, so I1 holds for new length; prior lengths
 *       unchanged.
 *       Case B (replace): let i be the smallest index with tails[i] >= x.
 *       By choice of i, there exists an IS of length i (ending with tails[i-1])
 *       and at least one IS of length i+1 ending with tails[i]. Replacing tails[i]
 *       by x asserts the existence of an IS of length i+1 ending with x:
 *       take an IS of length i ending with tails[i-1] (< x, because i is the
 *       first position where tails[i] >= x ⇒ tails[i-1] < x) and append x,
 *       preserving strict increase. Thus I1 holds.
 *
 *   - Maintenance (I2):
 *       Case A: appending x where x > tails.back() keeps strict increase.
 *       Case B: replacing tails[i] with x where tails[i-1] < x <= tails[i]
 *       preserves tails[i-1] < x and x <= tails[i+1] (if i+1 exists), so
 *       strict increase remains valid.
 *
 *   - Maintenance (I3):
 *       Consider any other feasible T' after processing the same prefix.
 *       We prove by induction on k that tails[k-1] <= T'[k-1].
 *       For k=1, tails[0] is the minimum value seen so far that can end any
 *       length-1 IS, hence <= any other length-1 tail T'[0].
 *       Assume true up to k-1. For k, when we set/adjust tails[k-1], we use the
 *       smallest possible value x that can follow some length-(k-1) IS whose
 *       tail is tails[k-2] (minimal by IH), hence x <= any candidate that could
 *       follow T'[k-2] (which is >= tails[k-2]). Therefore tails[k-1] <= T'[k-1].
 *
 * Consequences:
 *   - The LIS length after processing all elements equals |tails|.
 *   - `tails` itself is NOT guaranteed to be a subsequence of the input; its entries
 *     can come from different indices. (Counterexample: nums = [3,10,2,1,20]
 *     → final tails = [1,10,20], which is not an in-order subsequence.)
 *
 * Implementation details:
 *   - For strictly increasing LIS, we use lower_bound (first >= x).
 *   - For non-decreasing LIS, use upper_bound (first > x).
 *   - Time complexity: O(N log N) due to one binary search per element.
 *   - Space: O(N) for the tails array (amortized ≤ LIS length).
 *
 * Worked examples (evolution of `tails`):
 *
 *   A) nums = [10, 9, 2, 5, 3, 7, 101, 18]
 *      10 → [10]
 *       9 → [ 9]
 *       2 → [ 2]
 *       5 → [ 2, 5]
 *       3 → [ 2, 3]
 *       7 → [ 2, 3, 7]
 *     101 → [ 2, 3, 7, 101]
 *      18 → [ 2, 3, 7, 18]   ⇒ answer = 4
 *
 *   B) nums = [0, 1, 0, 3, 2, 3]
 *       0 → [0]
 *       1 → [0, 1]
 *       0 → [0, 1]
 *       3 → [0, 1, 3]
 *       2 → [0, 1, 2]
 *       3 → [0, 1, 2, 3]     ⇒ answer = 4
 *
 *   C) nums = [7,7,7,7,7]
 *       7 → [7]
 *       7 → [7] (replace 7 with 7)
 *       ... stays [7]        ⇒ answer = 1
 *
 */
int LongestIncreasingSubsequence_300::lengthOfLIS_tails(vector<int> &nums)
{
    vector<int> tails;              // tails[i] = min tail of length i+1
    tails.reserve(nums.size());

    for (int num : nums) {
        // Find the first element in 'tails' that is >= num
        auto it = lower_bound(tails.begin(), tails.end(), num);
        if (it == tails.end()) {
            // Extend: if num is greater than all elements, append it
            tails.push_back(num);
        } else {
            // Improve: replace the first element >= num
            *it = num;
        }
    }
    return tails.size();
}

// O(N^2) dynamic programming: dp[i] = LIS length ending at i
int LongestIncreasingSubsequence_300::lengthOfLIS_dp(const vector<int>& nums)
{
    const int n = static_cast<int>(nums.size());
    if (n == 0) return 0;

    vector<int> dp(n, 1);
    int best = 1;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (nums[j] < nums[i]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        best = max(best, dp[i]);
    }
    return best;
}
