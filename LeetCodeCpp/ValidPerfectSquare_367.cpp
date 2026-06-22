#include "ValidPerfectSquare_367.h"

// Exact binary search over possible square roots.
// See Docs/Algorithms/Binary_Search.md for the value-space search pattern.
bool ValidPerfectSquare_367::isPerfectSquare(int num)
{
    if (num == 1) {
        return true;
    }

    long long lo = 1;
    long long hi = num / 2;

    while (lo <= hi) {
        long long mid = lo + (hi - lo) / 2;
        long long sq = mid * mid;   // 64-bit to avoid overflow.

        if (sq == num) {
            return true;
        }

        if (sq < num) {
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }

    return false;
}
