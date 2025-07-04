#include "UniquePaths_62.h"

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
 * Why *not* use factorials directly?
 *     C(100,50)  involves 100! which overflows 64-bit very quickly.
 *
 * Instead we use the **multiplicative** identity
 *
 *     C(N, k) = Π_{i = 1..k}  (N − k + i) / i,   where  k = min(m−1,n−1).
 *
 * Interpretation:
 *   • The numerator  (N − k + i) runs through the k largest factors of N!
 *   • The denominator  i  runs through 1,2,…,k (i.e. k!).
 *   • Multiplying first and *immediately* dividing keeps the result an
 *     integer at every step, so intermediate values never exceed the
 *     64-bit range guaranteed by the problem (answer ≤ 2 · 10⁹).
 *
 * Example (m=3,n=7 ⇒ N=8,k=2):
 *   res = 1
 *   i = 1:  res = 1 * (8-2+1)=7 / 1  = 7
 *   i = 2:  res = 7 * (8-2+2)=8 / 2  = 28   ← C(8,2)
 *
 * Complexity:
 *     Time  O(min(m,n))  ≤ 99 iterations.
 *     Space O(1).
 */
int UniquePaths_62::uniquePaths(int m, int n)
{
    long long N = m + n - 2;              // total moves
    long long k = std::min(m - 1, n - 1); // choose smaller group

    long long res = 1;
    for (long long i = 1; i <= k; ++i) {
        // After (i-1) iterations, res = C(N, i-1).
        // Multiply by next numerator factor, divide by next i,
        // to obtain C(N, i) without overflow or loss of precision.
        res = res * (N - k + i) / i;
    }
    return static_cast<int>(res);         // fits in 32-bit
}