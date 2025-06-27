#pragma once
#include <vector>

using namespace std;

/* 973. K Closest Points to Origin
 * QuickSelect (Lomuto) that stops when the pivot lands on index k-1.
 * Expected time  O(n),   extra space  O(1).
 */
class KClosestPointsToOrigin_973 {
    using Point = vector<int>;

    /* helper functions – defined in the .cpp file */
    static long long distSq(const Point& p);                        // squared distance
    static int  partition (vector<Point>& a, int l, int r, int pivotIdx);
    static void quickSelect(vector<Point>& a, int k);               // in-place select

public:
    /* main API, exactly the same signature you used before */
    vector<Point> kClosestQuickSelect(vector<Point>& points, int k);  // QuickSelect
    vector<Point> kClosestHeap       (vector<Point>& points, int k);  // max-heap
};