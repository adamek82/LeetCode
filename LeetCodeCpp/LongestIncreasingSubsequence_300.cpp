#include "LongestIncreasingSubsequence_300.h"
#include <algorithm>
#include <iterator>

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

/*
 * Longest Increasing Subsequence (LeetCode 300) — O(N^2) DP
 * --------------------------------------------------------
 * Goal:
 *   Find the length of the longest strictly increasing subsequence (LIS).
 *   Subsequence = you may skip elements, but the order must stay the same.
 *
 * Core DP idea (build the best subsequence that ends “here”):
 *   Don’t try to directly construct the global LIS in one go.
 *   Instead, for every position i ask a smaller, local question:
 *
 *     dp[i] = length of the longest increasing subsequence that
 *             MUST end at index i (i.e., uses nums[i] as the last element).
 *
 *   If we know the best increasing subsequence ending at every earlier position j,
 *   then we can extend one of them with nums[i] — but only if nums[j] < nums[i].
 *
 * Transition (the “who can be my predecessor?” rule):
 *   To end at i, the previous element must come from some j < i with nums[j] < nums[i].
 *   Among all such valid predecessors, we want the one that gives the longest chain:
 *
 *     dp[i] = 1 + max(dp[j]) over all j < i with nums[j] < nums[i]
 *
 *   If there is NO valid j, then nums[i] starts a new subsequence by itself:
 *
 *     dp[i] = 1
 *
 * Why this works (intuition you can remember):
 *   Picture every index i as a “node” you want to finish on.
 *   You can draw an arrow j -> i if j < i and nums[j] < nums[i] (increasing + order).
 *   Then dp[i] is simply the length of the longest path that ends at node i.
 *   We compute nodes left-to-right, so when we process i, all dp[j] for j<i are ready.
 *
 * What `best` is:
 *   The LIS may end anywhere, not necessarily at the last index.
 *   So the final answer is:
 *
 *     best = max(dp[i]) over all i
 *
 * Quick examples to burn it in:
 *
 *   Example A: [10, 9, 2, 5, 3, 7, 101, 18]
 *     dp starts as all 1s.
 *     - At 5 (value=7): predecessors smaller than 7 are 2,5,3
 *       best predecessor dp is 2 (from 2->5 or 2->3->?), so dp becomes 3 (2,5,7).
 *     - At 6 (value=101): almost everything can precede it, so dp[6] becomes 4
 *       (2,3,7,101) or (2,5,7,101).
 *     Answer = 4.
 *
 *   Example B: [0, 1, 0, 3, 2, 3]
 *     i=0 (0): dp=1
 *     i=1 (1): can extend 0 -> dp=2
 *     i=2 (0): cannot extend anything smaller -> dp=1 (new start)
 *     i=3 (3): can extend 0/1/0 -> best dp is 2 -> dp=3 (0,1,3)
 *     i=4 (2): can extend 0/1/0 -> best dp is 2 -> dp=3 (0,1,2)
 *     i=5 (3): can extend ... best dp is 3 -> dp=4 (0,1,2,3)
 *     Answer = 4.
 *
 * Complexity:
 *   Time:  O(N^2)  (for each i, we scan all j<i)
 *   Space: O(N)    (dp array)
 */

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

/*
 * Longest Increasing Subsequence — O(N log N) (reconstruct one LIS)
 * ---------------------------------------------------------------
 * Problem:
 *   Return an actual strictly increasing subsequence (not only its length).
 *
 * Why we cannot return `tails`:
 *   The classic O(N log N) "tails" array stores only minimal possible tail values
 *   for each length. These values can come from different indices, so `tails`
 *   is not guaranteed to be a subsequence of the input.
 *
 * Reconstruction idea (parent pointers + tails as indices):
 *   Maintain:
 *     - tailsIdx[len-1] = the index in `nums` of the smallest possible tail value
 *       among all increasing subsequences of length `len` seen so far.
 *     - prev[i] = the predecessor index of nums[i] in one chosen LIS ending at i.
 *
 * Update for each i (value x = nums[i]):
 *   1) Find position `pos` such that:
 *        pos is the first index where nums[tailsIdx[pos]] >= x   (lower_bound)
 *      (This is the same rule as in the length-only version.)
 *   2) Link predecessor:
 *        prev[i] = (pos > 0) ? tailsIdx[pos-1] : -1
 *   3) Write the best tail index for this length:
 *        tailsIdx[pos] = i   (or push_back if pos == tailsIdx.size())
 *
 * At the end:
 *   - LIS length = tailsIdx.size()
 *   - last index of one LIS = tailsIdx.back()
 *   - follow prev[] backwards to reconstruct the sequence, then reverse it.
 *
 * Complexity:
 *   Time:  O(N log N)  (one binary search per element)
 *   Space: O(N)        (prev + tailsIdx)
 *
 * Notes:
 *   - This returns one valid LIS (there may be multiple).
 *   - Strictly increasing version uses lower_bound (first >= x).
 *     For non-decreasing LIS you would use upper_bound-like logic (first > x).
 */
vector<int> LongestIncreasingSubsequence_300::getLIS_tails(const vector<int>& nums)
{
    const int n = (int)nums.size();
    if (n == 0) return {};

    vector<int> tailsIdx;     // tailsIdx[len-1] = index of tail for length len
    tailsIdx.reserve(n);

    vector<int> prev(n, -1);  // predecessor pointers for reconstruction

    for (int i = 0; i < n; ++i) {
        const int x = nums[i];

        // Find first pos where nums[tailsIdx[pos]] >= x
        auto it = lower_bound(
            tailsIdx.begin(), tailsIdx.end(), x,
            [&](int idx, int value) { return nums[idx] < value; }
        );
        const int pos = (int)distance(tailsIdx.begin(), it);

        // predecessor of i is the best tail index for length pos (i.e., pos elements before)
        prev[i] = (pos > 0) ? tailsIdx[pos - 1] : -1;

        if (it == tailsIdx.end()) tailsIdx.push_back(i);
        else *it = i;
    }

    // Reconstruct sequence from the last tail index
    vector<int> lis;
    for (int cur = tailsIdx.back(); cur != -1; cur = prev[cur]) {
        lis.push_back(nums[cur]);
    }
    reverse(lis.begin(), lis.end());
    return lis;
}

/*
 * Longest Increasing Subsequence — O(N^2) DP (reconstruct one LIS)
 * ---------------------------------------------------------------
 * Extend the classic dp[i] = best LIS length ending at i by also tracking:
 *   prev[i] = predecessor index for that best chain ending at i.
 *
 * When dp[i] improves via j (nums[j] < nums[i] and dp[j]+1 > dp[i]),
 * we set prev[i] = j. After filling DP, pick bestEnd = argmax dp[i]
 * and follow prev[] backwards to reconstruct one LIS.
 *
 * Time:  O(N^2)
 * Space: O(N)
 */
vector<int> LongestIncreasingSubsequence_300::getLIS_dp(const vector<int>& nums)
{
    const int n = (int)nums.size();
    if (n == 0) return {};

    vector<int> dp(n, 1);
    vector<int> prev(n, -1);

    int bestLen = 1;
    int bestEnd = 0;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (nums[j] < nums[i] && dp[j] + 1 > dp[i]) {
                dp[i] = dp[j] + 1;
                prev[i] = j;
            }
        }
        if (dp[i] > bestLen) {
            bestLen = dp[i];
            bestEnd = i;
        }
    }

    vector<int> lis;
    for (int cur = bestEnd; cur != -1; cur = prev[cur]) {
        lis.push_back(nums[cur]);
    }
    reverse(lis.begin(), lis.end());
    return lis;
}
