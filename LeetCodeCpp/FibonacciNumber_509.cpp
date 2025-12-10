#include "FibonacciNumber_509.h"

/*
 * Fibonacci Number – iterative O(1) DP
 *
 * Goal:
 *   Compute F(n), where:
 *     F(0) = 0
 *     F(1) = 1
 *     F(n) = F(n-1) + F(n-2) for n >= 2
 *
 * Conceptual roadmap (4 stages):
 *
 * 1) Naive recursive backtracking (exponential)
 *
 *      fib(n):
 *        if n <= 1: return n
 *        return fib(n-1) + fib(n-2)
 *
 *    - Recomputes the same subproblems many times.
 *    - Time: O(2^n), Space: O(n) recursion depth.
 *
 * 2) Top-down DP with memoization
 *
 *      memo = array[0..n] filled with "unknown"
 *
 *      fib(n):
 *        if memo[n] is known: return memo[n]
 *        if n <= 1: memo[n] = n
 *        else: memo[n] = fib(n-1) + fib(n-2)
 *        return memo[n]
 *
 *    - Caches each F(k) once, avoids recomputation.
 *    - Time: O(n), Space: O(n) for memo + recursion stack.
 *
 * 3) Bottom-up DP (tabulation)
 *
 *      dp[0] = 0
 *      dp[1] = 1
 *      for i from 2 to n:
 *        dp[i] = dp[i-1] + dp[i-2]
 *      return dp[n]
 *
 *    - Iterative, no recursion.
 *    - Time: O(n), Space: O(n) for the table.
 *
 * 4) Bottom-up DP with O(1) extra memory (this solution)
 *
 *      if n <= 1: return n
 *      a = 0   // F(0)
 *      b = 1   // F(1)
 *      for i from 2 to n:
 *        c = a + b   // current F(i)
 *        a = b       // shift window: a <- F(i-1)
 *        b = c       //               b <- F(i)
 *      return b      // F(n)
 *
 *    - We only ever need the last two values.
 *    - Time: O(n), Space: O(1).
 */
int FibonacciNumber_509::fib(int n)
{
    if (n <= 1) return n;     // F(0)=0, F(1)=1
    int a = 0, b = 1;         // a=F(0), b=F(1)
    for (int i = 2; i <= n; ++i) {
        int c = a + b;        // c=F(i)
        a = b;
        b = c;
    }
    return b;                 // F(n)
}