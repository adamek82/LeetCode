#include "ClimbingStairs_70.h"

/*
 * 70. Climbing Stairs — Fibonacci-style DP with shifted base cases
 * ---------------------------------------------------------------
 * Let Ways(n) be the number of distinct ways to climb n stairs when we can
 * take 1 or 2 steps at a time. From the last move:
 *
 *   - If the last move was 1 step, we come from Ways(n-1).
 *   - If the last move was 2 steps, we come from Ways(n-2).
 *
 * So the recurrence is:
 *
 *     Ways(n) = Ways(n-1) + Ways(n-2),  for n >= 3
 *
 * with base cases:
 *
 *     Ways(1) = 1   (only "1")
 *     Ways(2) = 2   ("1+1", "2")
 *
 * This is exactly the Fibonacci recurrence, just with different starting
 * values. We compute it bottom-up, keeping only the last two values:
 *   a = Ways(1), b = Ways(2), then iterate up to n and return Ways(n) in O(n)
 * time and O(1) extra space.
 */
int ClimbingStairs_70::climbStairs(int n)
{
    if (n <= 2) return n;     // Ways(1)=1, Ways(2)=2
    int a = 1, b = 2;         // a=Ways(1), b=Ways(2)
    for (int i = 3; i <= n; ++i) {
        int c = a + b;        // c=Ways(i)
        a = b;
        b = c;
    }
    return b;                 // Ways(n)
}
