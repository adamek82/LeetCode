#include "NumberOfEmployeesWhoMetTarget_2798.h"

/*
 * 2798. Number of Employees Who Met the Target
 * --------------------------------------------
 * Count how many entries in `hours` are greater than or equal to `target`.
 * Single pass with a counter.
 *
 * Time:  O(n), where n = hours.size()
 * Space: O(1) extra
 */
int NumberOfEmployeesWhoMetTarget_2798::numberOfEmployeesWhoMetTarget(vector<int>& hours, int target)
{
    int count = 0;
    for (int h : hours) {
        if (h >= target) {
            ++count;
        }
    }
    return count;
}
