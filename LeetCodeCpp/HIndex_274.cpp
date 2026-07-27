#include "HIndex_274.h"
#include <algorithm>

int HIndex_274::hIndex(const vector<int>& citations)
{
    const int n = static_cast<int>(citations.size());
    vector<int> counts(n + 1);

    for (int citation : citations)
        ++counts[min(citation, n)];

    int h = n;
    int papers = counts[n];

    while (papers < h) {
        --h;
        papers += counts[h];
    }

    return h;
}
