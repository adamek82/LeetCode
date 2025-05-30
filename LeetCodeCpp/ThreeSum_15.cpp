#include "ThreeSum_15.h"

vector<vector<int>> ThreeSum_15::threeSum(vector<int> &nums)
{
    vector<vector<int>> res;
    sort(nums.begin(), nums.end());
    const int n = static_cast<int>(nums.size());

    for (int i = 0; i < n - 2; ++i) {
        if (i && nums[i] == nums[i - 1]) continue;          // skip duplicate first element
        int l = i + 1, r = n - 1;
        while (l < r) {
            long long sum = static_cast<long long>(nums[i]) +
                             nums[l] + nums[r];
            if (sum == 0) {
                res.push_back({nums[i], nums[l], nums[r]});
                while (l < r && nums[l] == nums[l + 1]) ++l; // skip duplicates
                while (l < r && nums[r] == nums[r - 1]) --r;
                ++l; --r;
            } else if (sum < 0) {
                ++l;
            } else {
                --r;
            }
        }
    }
    return res;
}