#include "HIndex_274.h"

/*
 * H-Index (LeetCode 274) — counting / bucket approach
 *
 * Observation
 * -----------
 * The h-index is at most n (number of papers). Citations above n do not change
 * the answer: for h = n, ">= h citations" already means ">= n citations", so
 * 500 and n are equivalent from the h-index perspective.
 *
 * Idea
 * ----
 * Instead of sorting, count how many papers have a given citation count.
 * Use buckets:
 *   counts[i] = number of papers with exactly i citations, for 0 <= i < n
 *   counts[n] = number of papers with at least n citations (all large values)
 *
 * After bucketing, we can test candidate h values from high to low, while
 * maintaining how many papers have >= h citations.
 *
 * Invariant / running total
 * -------------------------
 * Let totalPapers be the number of papers with at least the current h citations.
 * If we start from h = n, then:
 *   totalPapers = counts[n]   // papers with >= n citations
 *
 * When we decrease h by 1, we should include papers with exactly h citations
 * (because they now qualify as ">= h"):
 *   totalPapers += counts[h]
 *
 * We keep decreasing h until the defining condition holds:
 *   totalPapers >= h
 * At that point, there are at least h papers with at least h citations, so
 * h is a valid h-index. Because we scan from the largest possible h downward,
 * the first valid h we reach is the maximum one (the true h-index).
 *
 * Example
 * -------
 * citations = [3,0,6,1,5], n = 5
 * Buckets (cap at n):
 *   counts[0]=1, counts[1]=1, counts[3]=1, counts[5]=2  (6 goes into counts[5])
 *
 * Start h=5: totalPapers = counts[5] = 2  -> 2 < 5, not enough
 * h=4: totalPapers += counts = 2    -> 2 < 4
 * h=3: totalPapers += counts = 3    -> 3 >= 3  => answer is 3
 *
 * Complexity
 * ----------
 * Time:  O(n)   (one pass to bucket + one pass decreasing h)
 * Space: O(n)   (n+1 buckets)
 */
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