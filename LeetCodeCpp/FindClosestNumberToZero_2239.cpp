#include "FindClosestNumberToZero_2239.h"
#include <cstdlib>   // llabs
#include <climits>

/*
 * Find Closest Number to Zero (LeetCode 2239) — Single Pass Selection
 * ------------------------------------------------------------------
 * Method:
 *   Scan the array once and keep the current best candidate.
 *   For each number x, compare its distance to zero |x| with the best distance.
 *
 * Selection rules:
 *   - Prefer the number with the smaller absolute value (closer to zero).
 *   - If distances tie (same |x|), prefer the larger value (e.g., +k over -k).
 *
 * Why long long + llabs:
 *   absstatic_cast<int>(can) overflow / be undefined for INT_MIN because |INT_MIN| cannot be
 *   represented as an int (two’s complement range is asymmetric).
 *   Casting to long long first and using llabs ensures the absolute value fits
 *   safely and the comparison is well-defined for all int inputs.
 */
int FindClosestNumberToZero_2239::findClosestNumber(const vector<int>& nums)
{
    int best = nums[0];
    long long bestd = llabs(static_cast<long long>(best));

    for (size_t i = 1; i < nums.size(); ++i) {
        int x = nums[i];
        long long d = llabs(static_cast<long long>(x));
        if (d < bestd || (d == bestd && x > best)) {
            bestd = d;
            best  = x;
        }
    }
    return best;
}
