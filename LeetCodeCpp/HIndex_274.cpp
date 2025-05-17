#include "HIndex_274.h"

int HIndex_274::hIndex(vector<int> &citations)
{
    int n = citations.size();
    vector<int> counts(n + 1, 0);

    // Bucket each citation count into counts[min(c, n)].
    for (int c : citations) {
        counts[min(c, n)]++;
    }

    // Start with h at n, and totalPapers = counts[n].
    int h = n;
    int totalPapers = counts[n];

    // Decrease h until totalPapers >= h
    while (totalPapers < h) {
        --h;
        totalPapers += counts[h];
    }

    // Once totalPapers >= h, that's our h-index.
    return h;
}