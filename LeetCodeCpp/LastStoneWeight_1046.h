#pragma once
#include <vector>
using namespace std;

/*
 * Last Stone Weight (LeetCode 1046)
 *
 * Optimal algo: max-heap (priority_queue).
 * Repeatedly extract two heaviest stones y >= x; if y != x, push (y - x) back.
 * Time: O(n log n) overall; Space: O(n).
 */
class LastStoneWeight_1046 {
public:
    int lastStoneWeight(const vector<int>& stones);
};