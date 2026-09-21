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
 * From the factorial definition:
 *
 *     C(N, k) = N! / (k! (N-k)!).
 *
 * Cancelling (N-k)! gives:
 *
 *     C(N, k) = ((N-k+1)(N-k+2)...N) / (1*2*...*k).
 *
 * Choose k = min(m - 1, n - 1): the symmetry C(N, k) = C(N, N-k)
 * lets us count the smaller group, minimizing the number of iterations.
 *
 * Starting with res = 1, the loop builds the product incrementally:
 *
 *     res = res * (N - k + i) / i.
 *
 * After iteration i:
 *
 *     res = ((N-k+1)(N-k+2)...(N-k+i)) / (1*2*...*i).
 *
 * Therefore, the loop invariant is:
 *
 *     res = C(N-k+i, i).
 *
 * Thus each division by i is exact: the result is a binomial
 * coefficient and hence an integer, provided no overflow occurs.
 * At i = k, res = C(N, k). For k = 0, the empty product is 1
 * and the loop is skipped (a single row or column has one path).
 *
 * This avoids computing large factorials, but the intermediate
 * multiplication res * (N - k + i) can still overflow the chosen
 * integer type in general. long long suffices under this problem's
 * constraints: m, n <= 100 and the final answer <= 2 * 10^9.
 *
 * Example (m=3, n=7 ⇒ N=8, k=2):
 *   res = 1
 *   i = 1:  res = 1 * (8-2+1) / 1 = 1 * 7 / 1 = 7  = C(7,1)
 *   i = 2:  res = 7 * (8-2+2) / 2 = 7 * 8 / 2 = 28 = C(8,2)
 *
 * Complexity:
 *     Time  O(min(m,n)); k iterations, at most 99 when m, n <= 100.
 *     Space O(1).
 */
int UniquePaths_62::uniquePaths_Comb(int m, int n)
{
    long long N = m + n - 2;          // total moves
    long long k = min(m - 1, n - 1);  // choose smaller group

    long long res = 1;
    for (long long i = 1; i <= k; ++i) {
        // Before iteration i, res = C(N - k + i - 1, i - 1).
        // Multiply by the next numerator factor and divide exactly by i
        // to obtain C(N - k + i, i), assuming no intermediate overflow.
        res = res * (N - k + i) / i;
    }
    return static_cast<int>(res);     // answer <= 2 * 10^9 by the problem's guarantee
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
    vector<int> curr(n, 1);  // curr[1..n-1] is overwritten each row; curr[0] stays 1

    for (int i = 1; i < m; ++i) {
        for (int j = 1; j < n; ++j) {
            curr[j] = curr[j - 1] + prev[j];
        }
        prev.swap(curr);
    }
    return prev[n - 1];
}
