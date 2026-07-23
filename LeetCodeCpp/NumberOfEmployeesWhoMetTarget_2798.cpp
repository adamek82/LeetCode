#include "NumberOfEmployeesWhoMetTarget_2798.h"
#include <algorithm>

int NumberOfEmployeesWhoMetTarget_2798::
numberOfEmployeesWhoMetTarget_CountingLoop(const vector<int>& hours, int target)
{
    int count = 0;

    for (int h : hours) {
        if (h >= target)
            ++count;
    }

    return count;
}

int NumberOfEmployeesWhoMetTarget_2798::
numberOfEmployeesWhoMetTarget_CountIf(const vector<int>& hours, int target)
{
    return static_cast<int>(
        count_if(hours.begin(), hours.end(),
                 [target](int h) { return h >= target; }));
}
