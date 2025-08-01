#include "ValidPerfectSquare_367.h"

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