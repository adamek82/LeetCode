#pragma once
#include <vector>
using namespace std;

/*
 * Find Closest Number to Zero (LeetCode 2239)
 *
 * Scan once keeping the current best value `best` and its absolute distance `bestd`.
 * For each x:
 *   - let d = |x| (use 64-bit to be safe);
 *   - if d < bestd -> update;
 *   - if d == bestd -> tie-break by larger value (prefer positive).
 *
 * Time:  O(n)
 * Space: O(1)
 */
class FindClosestNumberToZero_2239 {
public:
    int findClosestNumber(const vector<int>& nums);
};
