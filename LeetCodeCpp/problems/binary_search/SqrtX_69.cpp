#include "SqrtX_69.h"

// Binary search for the last value whose square does not exceed x.
// See Docs/Algorithms/Binary_Search.md for the "last true" pattern.
int SqrtX_69::mySqrt(int x)
{
    if (x < 2) {
        return x;
    }

    int left = 1;
    int right = x / 2;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (mid <= x / mid) { // mid * mid <= x, without overflow.
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return right;
}
