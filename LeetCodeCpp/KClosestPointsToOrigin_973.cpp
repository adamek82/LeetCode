#include "KClosestPointsToOrigin_973.h"
#include <cstdlib>   // rand, srand
#include <ctime>     // time
#include <queue>     // priority_queue

/* ---------- Helpers ---------------------------------------------------- */
// Squared distance from the origin (safer in 64-bit).
long long KClosestPointsToOrigin_973::distSq(const Point& p) {
    return 1LL * p[0] * p[0] + 1LL * p[1] * p[1];
}

// Lomuto partition: rearrange [l, r] around pivotIdx, return final pivot index.
int KClosestPointsToOrigin_973::partition(vector<Point>& a, int l, int r, int pivotIdx)
{
    long long pivot = distSq(a[pivotIdx]);
    swap(a[pivotIdx], a[r]);           // Move pivot to the end.
    int store = l;

    for (int i = l; i < r; ++i)
        if (distSq(a[i]) <= pivot)
            swap(a[store++], a[i]);

    swap(a[store], a[r]);              // Place pivot in the gap.
    return store;                      // 0-based index of the pivot.
}

// In-place QuickSelect: after it returns, indices 0 … k-1 hold the k closest points.
void KClosestPointsToOrigin_973::quickSelect(vector<Point>& a, int k)
{
    if (k == 0) return;
    const int target = k - 1;          // We want pivot to land on k-1.
    int l = 0, r = static_cast<int>(a.size()) - 1;

    while (l < r) {
        int pivotIdx = l + rand() % (r - l + 1);
        int pos      = partition(a, l, r, pivotIdx);

        if (pos == target) return;         // Done!
        if (pos <  target) l = pos + 1;    // Look in the right part.
        else               r = pos - 1;    // Look in the left part.
    }
}

/* ---------- Public API: QuickSelect ----------------------------------- */
vector<KClosestPointsToOrigin_973::Point>
KClosestPointsToOrigin_973::kClosestQuickSelect(vector<Point>& points, int k)
{
    srand(static_cast<unsigned>(time(nullptr)));   // Seed RNG once per call.
    quickSelect(points, k);                        // Rearrange in-place
    return {points.begin(), points.begin() + k};   // Copy first k items.
}

/* ---------- Public API: max-heap / priority_queue --------------------- */
vector<KClosestPointsToOrigin_973::Point>
KClosestPointsToOrigin_973::kClosestHeap(vector<Point>& points, int k)
{
    using Item = pair<long long, Point>;          // (dist², point)
    priority_queue<Item> pq;                      // max-heap on distance

    /* seed with first k points */
    for (int i = 0; i < k; ++i)
        pq.emplace(distSq(points[i]), points[i]);

    /* scan rest */
    for (int i = k; i < (int)points.size(); ++i) {
        long long d = distSq(points[i]);
        if (d < pq.top().first) {
            pq.pop();
            pq.emplace(d, points[i]);
        }
    }

    /* extract */
    vector<Point> res;
    res.reserve(k);
    while (!pq.empty()) {
        res.push_back(pq.top().second);
        pq.pop();
    }
    return res;          // any order acceptable
}