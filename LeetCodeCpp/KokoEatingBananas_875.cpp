#include "KokoEatingBananas_875.h"
#include <algorithm> // max_element

/*
 * 875. Koko Eating Bananas — binary search on the answer (k)
 * ----------------------------------------------------------
 * We need the smallest integer eating speed k such that Koko can finish
 * all piles within h hours.
 *
 * Observations:
 *   - If Koko eats at speed k bananas/hour, then the time needed for
 *     a single pile of size p is:
 *
 *         ceil(p / k) = (p + k - 1) / k
 *
 *     (integer arithmetic).
 *
 *   - Total time T(k) is the sum of these per-pile times. T(k) is
 *     monotonically non-increasing in k:
 *       k1 < k2  =>  T(k1) >= T(k2).
 *
 *   - We are looking for the smallest k such that T(k) <= h.
 *
 * Search space for k:
 *   - Minimum possible speed is 1 (slowest non-zero speed).
 *   - Maximum necessary speed is max(piles), because if Koko eats at
 *     speed >= max pile size, each pile is finished in at most 1 hour,
 *     and the total time is piles.size() <= h (from the constraints).
 *
 * Monotone predicate:
 *   - Define:
 *
 *       canFinish(k) = (T(k) <= h)
 *
 *     This is true for all sufficiently large k, and false for all
 *     sufficiently small k. Therefore we can binary-search the minimal
 *     k with canFinish(k) == true.
 *
 * Binary search scheme (closed interval, "min true" pattern):
 *   - left  = 1
 *   - right = max(piles)
 *
 *   while (left < right):
 *       mid = left + (right - left) / 2
 *       if canFinish(mid):
 *           right = mid;        // mid is feasible, try to find smaller
 *       else:
 *           left = mid + 1;     // mid is too slow, need a larger k
 *
 *   When the loop ends, left == right and is the smallest k such that
 *   canFinish(k) is true.
 *
 * Complexity:
 *   - Let n = piles.size(), Pmax = max(piles).
 *   - Each evaluation of canFinish(k) scans all piles => O(n).
 *   - Binary search over k uses O(log Pmax) iterations.
 *
 *   Total time:  O(n log Pmax)
 *   Extra space: O(1)
 */

bool KokoEatingBananas_875::canFinish(const vector<int>& piles, int h, int k)
{
    long long hours = 0; // use 64-bit to avoid overflow

    for (int p : piles) {
        // ceil(p / k) using integer arithmetic
        hours += (p + k - 1) / k;
        if (hours > h) {
            // Early exit: already too slow at this k.
            return false;
        }
    }
    return true;    // hours <= h
}

int KokoEatingBananas_875::minEatingSpeed(vector<int>& piles, int h)
{
    int maxPile = *max_element(piles.begin(), piles.end());

    int left  = 1;
    int right = maxPile;

    while (left < right) {
        int mid = left + (right - left) / 2;

        if (canFinish(piles, h, mid)) {
            right = mid;        // mid works, try smaller k
        } else {
            left = mid + 1;     // mid too slow
        }
    }

    return left; // == right: minimal feasible speed
}
