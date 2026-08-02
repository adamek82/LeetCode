#include "AppleRedistributionIntoBoxes_3074.h"
#include <algorithm> // sort
#include <functional> // greater

/*
 * 3074. Apple Redistribution into Boxes
 * -------------------------------------
 * Algorithm:
 *   1) Compute the total number of apples:
 *
 *        totalApples = sum(apple[i]).
 *
 *   2) Sort the capacities in descending order, so we consider the largest
 *      boxes first.
 *
 *   3) Traverse the sorted capacities, keeping a running sum of how much
 *      capacity we have taken and counting how many boxes we used. As soon
 *      as the running capacity >= totalApples, we can stop; the count of
 *      boxes is the minimum possible.
 *
 * Why it works (intuitive justification):
 *   - We want to reach a fixed threshold (totalApples) with as few "items"
 *     (boxes) as possible.
 *   - If we ever chose a smaller box instead of a larger unused one, swapping
 *     them would not reduce the total capacity but could only keep or reduce
 *     the number of boxes needed. Thus taking boxes greedily from largest
 *     capacity to smallest is optimal.
 *
 * Complexity:
 *   - Let n = apple.size(), m = capacity.size().
 *   - Time:  O(n + m log m)   (sum apples + sort capacities).
 *   - Space: O(1) extra (ignoring the input vectors themselves).
 */
int AppleRedistributionIntoBoxes_3074::minimumBoxes(vector<int>& apple, vector<int>& capacity)
{
    int totalApples = 0;
    for (int x : apple) {
        totalApples += x;
    }

    // Use largest boxes first.
    sort(capacity.begin(), capacity.end(), greater<int>());

    int usedBoxes = 0;
    int currentCapacity = 0;

    for (int cap : capacity) {
        currentCapacity += cap;
        ++usedBoxes;
        if (currentCapacity >= totalApples) {
            break;
        }
    }

    // Problem guarantees it is always possible to redistribute.
    return usedBoxes;
}
