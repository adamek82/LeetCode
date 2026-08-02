#pragma once
#include <vector>
using namespace std;

/*
 * Top K Frequent Elements (LeetCode 347)
 *
 * Idea:
 * 1) Count frequencies in an unordered_map while tracking the maximum frequency (maxf).
 * 2) Allocate buckets of size (maxf + 1), where buckets[f] holds all values that appear exactly f times.
 *    Using maxf avoids allocating n+1 buckets when the true maximum frequency is smaller.
 * 3) Scan buckets from maxf down to 1, collecting values until k elements are gathered.
 *
 * Complexity:
 * - Time:   Average O(n): O(n) to build the frequency map, O(n) to distribute into buckets,
 *           and up to O(n) to scan buckets with an early exit once k elements are collected.
 * - Space:  O(n) for the frequency map and buckets.
 */
class TopKFrequentElements_347 {
public:
    vector<int> topKFrequent(const vector<int>& nums, int k);
};
