#include "TopKFrequentElements_347.h"
#include <unordered_map>

vector<int> TopKFrequentElements_347::topKFrequent(const vector<int>& nums, int k)
{
    unordered_map<int,int> freq;
    freq.reserve(nums.size());          // reserve to reduce rehashing in typical implementations
    int maxf = 0;                       // track maximum frequency
    for (int x : nums) maxf = max(maxf, ++freq[x]);

    vector<vector<int>> buckets(maxf + 1); // allocate only up to maxf
    for (const auto& [val, f] : freq) buckets[f].push_back(val);

    vector<int> ans;
    ans.reserve(k);
    for (int f = maxf; f >= 1; --f) {
        for (int v : buckets[f]) {
            ans.push_back(v);
            if ((int)ans.size() == k) return ans; // early return once k elements are gathered
        }
    }
    return ans; // defensive: with valid inputs we should have returned earlier
}