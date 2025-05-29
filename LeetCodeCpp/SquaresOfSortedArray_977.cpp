#include "SquaresOfSortedArray_977.h"

vector<int> SquaresOfSortedArray_977::sortedSquares(const vector<int> &nums)
{
    int n = static_cast<int>(nums.size());
    vector<int> res(n);            // result, to be filled from back → front
    int l = 0, r = n - 1;          // two pointers

    for (int pos = n - 1; pos >= 0; --pos) {
        int leftVal  = nums[l];
        int rightVal = nums[r];

        if (abs(leftVal) > abs(rightVal)) {     // left dominates
            res[pos] = leftVal * leftVal;
            ++l;
        } else {                                // right dominates (or ties)
            res[pos] = rightVal * rightVal;
            --r;
        }
    }
    return res;
}