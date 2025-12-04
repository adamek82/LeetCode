#include "ValidPerfectSquare_367.h"

/*
 * 367. Valid Perfect Square — binary search idea
 * ---------------------------------------------
 * We want to decide whether `num` is a perfect square without using `sqrt`.
 *
 * High-level idea:
 *   - For num == 1 we can immediately return true.
 *   - For num >= 2, if there is an integer x such that x * x == num, then
 *     x must lie between 1 and num / 2 (inclusive). We can then run a
 *     standard binary search on this interval and compare mid * mid to num.
 *
 * Why is `hi = num / 2` a safe upper bound?
 *   - If num >= 4 is a perfect square, let x be its integer square root
 *     so that x * x == num.
 *   - For x >= 2 we have:
 *
 *         x^2 >= 2x   ⇔   x^2 / 2 >= x
 *
 *     i.e.  num / 2 >= x, because num = x^2.
 *   - So for any perfect square num >= 4, its square root x satisfies:
 *
 *         2 <= x <= num / 2
 *
 *   - For num = 2 or 3 there is no integer x with x^2 == num, but allowing
 *     hi = num / 2 still gives a correct search interval:
 *       - num = 2 → hi = 1 → we only check x = 1 and correctly return false.
 *       - num = 3 → hi = 1 → same reasoning.
 *   - The special-case check for num == 1 ensures we do not miss x = 1
 *     when num itself is 1.
 *
 * Binary search details:
 *   - We search in [1, num / 2] for some integer mid with mid * mid == num.
 *   - If mid^2 < num, the square root (if it exists) must be > mid,
 *     so we move the lower bound up: lo = mid + 1.
 *   - If mid^2 > num, the square root must be < mid,
 *     so we move the upper bound down: hi = mid - 1.
 *   - If mid^2 == num, we found an integer square root and return true.
 *   - If the loop finishes without a match, there is no integer x with
 *     x * x == num and we return false.
 *
 * Overflow avoidance:
 *   - `num` can be as large as 2^31 - 1.
 *   - The upper bound for mid is num / 2, which is at most ~10^9.
 *   - mid * mid can therefore be as large as ~10^18, which does not fit
 *     in a 32-bit int but safely fits in a signed 64-bit (long long).
 *
 * Complexity:
 *   - Time:  O(log num), because each step halves the search interval.
 *   - Space: O(1) extra space.
 */
bool ValidPerfectSquare_367::isPerfectSquare(int num)
{
    if (num == 1) return true;          // quick edge case
    long long lo = 1, hi = num / 2;     // num ≥ 2 here
    while (lo <= hi) {
        long long mid = lo + (hi - lo) / 2;
        long long sq = mid * mid;       // 64-bit to avoid overflow
        if (sq == num) return true;
        else if (sq < num)
            lo = mid + 1;
        else
            hi = mid - 1;
    }
    return false;
}