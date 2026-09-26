#include "LongestIncreasingSubsequence_300.h"
#include <algorithm>
#include <iterator>

using namespace std;

int LongestIncreasingSubsequence_300::lengthOfLIS_tails(vector<int> &nums)
{
    vector<int> tails;
    tails.reserve(nums.size());

    for (int num : nums) {
        auto it = lower_bound(tails.begin(), tails.end(), num);
        if (it == tails.end()) {
            tails.push_back(num);
        } else {
            *it = num;
        }
    }
    return static_cast<int>(tails.size());
}

int LongestIncreasingSubsequence_300::lengthOfLIS_dp(const vector<int>& nums)
{
    const int n = static_cast<int>(nums.size());
    if (n == 0) return 0;

    vector<int> dp(n, 1);
    int best = 1;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (nums[j] < nums[i]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        best = max(best, dp[i]);
    }
    return best;
}

vector<int> LongestIncreasingSubsequence_300::getLIS_tails(const vector<int>& nums)
{
    const int n = static_cast<int>(nums.size());
    if (n == 0)
        return {};

    vector<int> tailIdx;
    tailIdx.reserve(n);

    vector<int> prev(n, -1);

    for (int i = 0; i < n; ++i) {
        auto it = lower_bound(
            tailIdx.begin(), tailIdx.end(), nums[i],
            [&](int idx, int value) {
                return nums[idx] < value;
            });

        int pos = static_cast<int>(it - tailIdx.begin());

        if (pos > 0)
            prev[i] = tailIdx[pos - 1];

        if (it == tailIdx.end())
            tailIdx.push_back(i);
        else
            *it = i;
    }

    vector<int> lis(tailIdx.size());

    int cur = tailIdx.back();
    for (int pos = static_cast<int>(lis.size()) - 1; pos >= 0; --pos) {
        lis[pos] = nums[cur];
        cur = prev[cur];
    }

    return lis;
}

vector<int> LongestIncreasingSubsequence_300::getLIS_dp(const vector<int>& nums)
{
    const int n = (int)nums.size();
    if (n == 0) return {};

    vector<int> dp(n, 1);
    vector<int> prev(n, -1);

    int bestLen = 1;
    int bestEnd = 0;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (nums[j] < nums[i] && dp[j] + 1 > dp[i]) {
                dp[i] = dp[j] + 1;
                prev[i] = j;
            }
        }
        if (dp[i] > bestLen) {
            bestLen = dp[i];
            bestEnd = i;
        }
    }

    vector<int> lis;
    for (int cur = bestEnd; cur != -1; cur = prev[cur]) {
        lis.push_back(nums[cur]);
    }
    reverse(lis.begin(), lis.end());
    return lis;
}
