#include "PerfectSquares_279.h"
#include <vector>
#include <climits>

/*
 * Problem: 279. Perfect Squares
 *
 * Goal:
 *   Given an integer n (1 ≤ n ≤ 10^4), return the least number of perfect
 *   squares that sum to n.
 *
 * Algorithm (Bottom-up Dynamic Programming):
 *   Let dp[k] denote the minimum number of perfect-square addends whose sum is k.
 *
 *   Initialization:
 *     - dp[0] = 0  (zero can be formed with zero squares)
 *     - dp[1..n] = +∞ sentinel (use INT_MAX/2 to avoid overflow on +1)
 *     - Precompute all perfect squares s = j*j with 1 ≤ j*j ≤ n once.
 *
 *   Transition:
 *     For k from 1 to n:
 *       For each perfect square s in squares (in increasing order):
 *         If s > k, break (no larger square can be used for this k).
 *         Otherwise, try taking one s and solve the remainder optimally:
 *           dp[k] = min(dp[k], dp[k - s] + 1).
 *
 *   Answer:
 *     Return dp[n].
 *
 * Correctness (Sketch by Induction on k):
 *   Base: k = 0. By definition, dp[0] = 0 is optimal.
 *   Step: Assume dp[t] is optimal for all t < k.
 *         The algorithm considers every admissible first square s ≤ k.
 *         For each s, the remainder k - s is solved optimally by the IH,
 *         contributing dp[k - s] + 1 squares. Taking the minimum over all s
 *         yields the true optimum for k. Hence dp[k] is optimal, and by
 *         induction dp[n] is optimal.
 *
 * Complexity:
 *   Let Q(k) be the number of squares ≤ k; Q(k) = ⌊√k⌋.
 *   Time:  Σ_{k=1..n} Q(k) = Θ(n√n).
 *   Space: O(n) for the dp array (plus O(√n) for the precomputed squares).
 *
 * Implementation Notes:
 *   - Using INT_MAX/2 prevents overflow in dp[k - s] + 1.
 *   - Precomputing squares and breaking when s > k improve constant factors.
 */

int PerfectSquares_279::numSquares(int n) {
    vector<int> dp(n + 1, INT_MAX / 2);  // avoid overflow
    dp[0] = 0;

    // Pre-compute all squares ≤ n once
    vector<int> squares;
    for (int j = 1; j * j <= n; ++j)
        squares.push_back(j * j);

    for (int k = 1; k <= n; ++k) {
        for (int s : squares) {
            if (s > k) break;
            dp[k] = min(dp[k], dp[k - s] + 1);
        }
    }
    return dp[n];
}