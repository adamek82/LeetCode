#include "Base7_504.h"
#include <algorithm> // reverse

/*
 * 504. Base 7 — repeated division with sign handling
 * --------------------------------------------------
 * If num is 0, the answer is "0".
 * Otherwise, we:
 *   - Remember the sign and work with the absolute value.
 *   - Repeatedly take n % 7 as the next least-significant digit and push it
 *     to a string.
 *   - Divide n by 7 each step until it becomes 0, then reverse the string
 *     to get the correct order and prepend '-' if the original num was negative.
 *
 * Why use long long for n?
 *   - We convert num to a positive value before the loop. Using long long
 *     makes this safe even if num is at the edge of 32-bit range (e.g. INT_MIN),
 *     where -num would overflow in 32-bit int. For this problem’s constraints
 *     (-1e7..1e7) int would be enough, but long long is a robust, zero-cost
 *     defensive choice.
 *
 * Time:  O(log_7 |num|)
 * Space: O(1) extra (ignoring the output string)
 */
string Base7_504::convertToBase7(int num)
{
    if (num == 0) {
        return "0";
    }

    bool negative = (num < 0);
    long long n = negative ? -(long long)num : (long long)num;

    string digits;
    while (n > 0) {
        int d = static_cast<int>(n % 7);
        digits.push_back(static_cast<char>('0' + d));
        n /= 7;
    }

    if (negative) {
        digits.push_back('-');
    }

    reverse(digits.begin(), digits.end());
    return digits;
}
