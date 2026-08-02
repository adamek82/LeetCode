#include "ValidPerfectSquare_367.h"

bool ValidPerfectSquare_367::isPerfectSquare(int num) const
{
    int low = 1;
    int high = num;

    while (low <= high) {
        const int mid = low + (high - low) / 2;
        const long long square = static_cast<long long>(mid) * mid;

        if (square == num) {
            return true;
        }

        if (square < num) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return false;
}
