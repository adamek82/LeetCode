#pragma once

#include <vector>

namespace TestCases {

// 1046. Last Stone Weight
struct LastStoneWeightTestCase { std::vector<int> stones; int expected; };

// 215. Kth Largest Element in an Array
struct KthLargestElementTestCase { std::vector<int> nums; int k; int expected; };

// 347. Top K Frequent Elements
struct TopKFrequentElementsTestCase { std::vector<int> nums; int k; std::vector<int> expected; };

// 973. K Closest Points to Origin
struct KClosestPointsToOriginTestCase {
    std::vector<std::vector<int>> points;
    int k;
    std::vector<std::vector<int>> expected;
};

// 23. Merge k Sorted Lists
struct MergeKListsTestCase { std::vector<std::vector<int>> lists; std::vector<int> expected; };

// 2812. Find Safest Path in Grid
struct FindTheSafestPathInGridTestCase { std::vector<std::vector<int>> grid; int expected; };

} // namespace TestCases
