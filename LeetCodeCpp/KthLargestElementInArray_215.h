#pragma once
#include <vector>
#include <queue>

using namespace std;

class KthLargestElementInArray_215 {
public:
     int findKthLargest_MaxHeap(vector<int>& nums, int k);
     int findKthLargest_MinHeap(vector<int>& nums, int k);
};
