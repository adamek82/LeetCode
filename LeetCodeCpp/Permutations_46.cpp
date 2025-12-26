#include "Permutations_46.h"
#include <algorithm>

void Permutations_46::dfsPerm(int pos, vector<int>& nums, vector<vector<int>>& out) {
    const int n = static_cast<int>(nums.size());
    if (pos == n) {
        out.push_back(nums);   // record one full permutation
        return;
    }
    for (int i = pos; i < n; ++i) {
        swap(nums[pos], nums[i]);       // choose nums[i] for position 'pos'
        dfsPerm(pos + 1, nums, out);    // recurse
        swap(nums[pos], nums[i]);       // backtrack
    }
}

vector<vector<int>> Permutations_46::permute(vector<int>& nums) {
    vector<vector<int>> out;
    dfsPerm(0, nums, out);
    return out;
}
