#include "Subsets_78.h"

/*
 * Bitmask power set: for each mask, collect elements with set bits.
 */
vector<vector<int>> Subsets_78::subsets(vector<int>& nums) {
    const int n = (int)nums.size();
    const int total = 1 << n;

    vector<vector<int>> out;
    out.reserve(total);

    for (int mask = 0; mask < total; ++mask) {
        vector<int> cur;
        cur.reserve(n);
        for (int i = 0; i < n; ++i) {
            if (mask & (1 << i)) cur.push_back(nums[i]);
        }
        out.push_back(move(cur));
    }
    return out;
}
