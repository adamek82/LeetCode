#include "UniquePaths_62.h"
#include <vector>

/*
 * 62. Unique Paths  ―  LeetCode
 *
 * A path from the top-left to the bottom-right of an m×n grid is a
 * sequence of moves containing exactly:
 *     • (m − 1) moves Down
 *     • (n − 1) moves Right
 *
 * Total moves:  N = (m − 1) + (n − 1) = m + n − 2.
 *
 * Counting distinct paths is therefore counting how many ways we can
 * choose where those Down moves (or, equivalently, Right moves) go in
 * that sequence.  That number is the binomial coefficient
 *
 *         C(N, m − 1)  =  C(N, n − 1).
 *
 * -------------------------------------------------------------------
 * Implementation #1 – combinatorial formula (O(1) extra space)
 *
 * Naive factorials overflow quickly (e.g. C(100,50) uses 100!),
 * so we use the multiplicative identity
 *
 *     C(N, k) = Π_{i = 1..k}  (N − k + i) / i,   where  k = min(m−1,n−1).
 *
 * Here the loop does:
 *
 *     res_0 = 1
 *     res_i = res_{i-1} * (N − k + i) / i
 *
 * Invariant (proof that res stays integer):
 *     After i-th iteration:
 *         res_i = C(N − k + i, i)
 *     Base:  res_0 = 1 = C(N − k + 0, 0).
 *     Step:  assume res_{i-1} = C(N − k + i − 1, i − 1). Then
 *
 *         res_i
 *           = C(N − k + i − 1, i − 1) * (N − k + i) / i
 *           = C(N − k + i, i)   // standard identity:
 *                               // C(n, r) * (n+1)/(r+1) = C(n+1, r+1)
 *
 *     A binomial coefficient C(a, b) is always an integer, so each
 *     division by i is exact and res never becomes fractional.
 *
 * Example (m=3, n=7 ⇒ N=8, k=2):
 *   res = 1
 *   i = 1:  res = 1 * (8-2+1)=7 / 1  = 7    = C(7,1)
 *   i = 2:  res = 7 * (8-2+2)=8 / 2  = 28   = C(8,2)
 *
 * Complexity:
 *     Time  O(min(m,n))  ≤ 99 iterations.
 *     Space O(1).
 */
int UniquePaths_62::uniquePaths_Comb(int m, int n)
{
    long long N = m + n - 2;          // total moves
    long long k = min(m - 1, n - 1);  // choose smaller group

    long long res = 1;
    for (long long i = 1; i <= k; ++i) {
        // After (i-1) iterations, res = C(N, i-1).
        // Multiply by next numerator factor, divide by next i,
        // to obtain C(N, i) without overflow or loss of precision.
        res = res * (N - k + i) / i;
    }
    return static_cast<int>(res);     // fits in 32-bit
}

/*
 * Implementation #2 – 2D DP (O(m * n) space).
 *
 * Let dp[i][j] be the number of unique paths to cell (i, j).
 *
 * Transition:
 *   dp[i][j] = dp[i-1][j] + dp[i][j-1]
 * Because we can arrive at (i, j) either from above or from the left.
 *
 * Base:
 *   First row and first column are all 1, because from the start
 *   there is only one way to move purely right or purely down.
 *
 * Complexity:
 *   Time  O(m * n)
 *   Space O(m * n)
 */
int UniquePaths_62::uniquePaths_DP2D(int m, int n)
{
    vector<vector<int>> dp(m, vector<int>(n, 1));  // first row/col = 1

    for (int i = 1; i < m; ++i) {
        for (int j = 1; j < n; ++j) {
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        }
    }
    return dp[m - 1][n - 1];
}

/*
 * Implementation #3 – DP with only 2 rows (O(n) space).
 *
 * We observe that to compute row i, we only need:
 *   • current row i       (curr[0..n-1])
 *   • previous row i - 1  (prev[0..n-1])
 *
 * Recurrence for row i:
 *   curr[0]   = 1                        (only one way: all downs)
 *   curr[j]   = curr[j-1] + prev[j]      for j >= 1
 *
 * Complexity:
 *   Time  O(m * n)
 *   Space O(n)   (2 * n integers)
 */
int UniquePaths_62::uniquePaths_DP2Rows(int m, int n)
{
    vector<int> prev(n, 1);  // row 0: all ones
    vector<int> curr(n, 1);  // will be overwritten for each next row

    for (int i = 1; i < m; ++i) {
        for (int j = 1; j < n; ++j) {
            curr[j] = curr[j - 1] + prev[j];
        }
        prev.swap(curr);
    }
    return prev[n - 1];
}
