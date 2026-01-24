#pragma once
#include <vector>

using namespace std;

class MergeSortedArray_88 {
public:
    // In-place back-to-front merge, O(m+n) time / O(1) extra space.
    void merge(vector<int>& nums1, int m,
               const vector<int>& nums2, int n);
};
