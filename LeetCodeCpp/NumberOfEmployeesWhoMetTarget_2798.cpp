#include "NumberOfEmployeesWhoMetTarget_2798.h"
#include <vector>
#include <algorithm> // count_if

/*
 * 2798. Number of Employees Who Met the Target
 * --------------------------------------------
 * Count how many entries in `hours` are greater than or equal to `target`.
 *
 * Time:  O(n), where n = hours.size()
 * Space: O(1) extra
 */
int NumberOfEmployeesWhoMetTarget_2798::numberOfEmployeesWhoMetTarget_CountingLoop(vector<int>& hours, int target)
{
    int count = 0;
    for (int h : hours) {
        if (h >= target) {
            ++count;
        }
    }
    return count;
}

/*
 * STL variant: std::count_if
 * --------------------------
 * Counts elements that satisfy a predicate (here: h >= target).
 *
 * Note on return type:
 * - std::count_if returns an iterator "difference_type" (typically ptrdiff_t),
 *   not an int. Since this method returns int (LeetCode signature), we cast
 *   explicitly to avoid implicit narrowing and potential -Wconversion warnings.
 *
 * Time:  O(n)
 * Space: O(1) extra
 */
int NumberOfEmployeesWhoMetTarget_2798::numberOfEmployeesWhoMetTarget_CountIf(vector<int>& hours, int target)
{
    return static_cast<int>(count_if(hours.begin(), hours.end(),
                                     [target](int h) { return h >= target; }));
}
