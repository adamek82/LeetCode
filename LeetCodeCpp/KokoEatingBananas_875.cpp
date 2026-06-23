#include "KokoEatingBananas_875.h"
#include <algorithm>

// Binary search on the answer: find the smallest feasible eating speed.
// See Docs/Algorithms/Binary_Search.md for the "first true" pattern.
bool KokoEatingBananas_875::canFinish(const vector<int>& piles, int h, int k)
{
    long long hours = 0;

    for (int p : piles) {
        hours += (p + k - 1) / k; // ceil(p / k)

        if (hours > h) {
            return false;
        }
    }

    return true;
}

int KokoEatingBananas_875::minEatingSpeed(vector<int>& piles, int h)
{
    int maxPile = *max_element(piles.begin(), piles.end());

    int left = 1;
    int right = maxPile;

    while (left < right) {
        int mid = left + (right - left) / 2;

        if (canFinish(piles, h, mid)) {
            right = mid; // mid can still be the minimum feasible speed.
        } else {
            left = mid + 1;
        }
    }

    return left;
}
