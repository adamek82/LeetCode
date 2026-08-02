#include "FirstBadVersion_278.h"

// Boundary binary search: find the first version where isBadVersion(version) is true.
// See Docs/Algorithms/Binary_Search.md for the "first true" pattern.
int FirstBadVersion_278::firstBadVersion(int n)
{
    int left = 1;
    int right = n;

    while (left < right) {
        int mid = left + (right - left) / 2;

        if (isBadVersion(mid)) {
            right = mid; // mid can still be the first bad version.
        } else {
            left = mid + 1;
        }
    }

    return left;
}

bool FirstBadVersion_278::isBadVersion(int version) const
{
    return version >= firstBad;
}
