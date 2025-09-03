#include "CombinationSum_39.h"
#include <algorithm>

void CombinationSum_39::dfs(int start, int remain, const vector<int>& cand,
                            vector<int>& cur, vector<vector<int>>& out) {
    if (remain == 0) {
        out.push_back(cur);
        return;
    }
    const int n = (int)cand.size();
    for (int i = start; i < n; ++i) {
        int v = cand[i];
        if (v > remain) break;           // pruning thanks to sorting
        cur.push_back(v);                // choose v
        dfs(i, remain - v, cand, cur, out); // reuse allowed -> pass i (not i+1)
        cur.pop_back();                  // backtrack
    }
}

vector<vector<int>> CombinationSum_39::combinationSum(vector<int>& candidates, int target) {
    sort(candidates.begin(), candidates.end()); // required for pruning & order
    vector<vector<int>> out;
    vector<int> cur;
    dfs(0, target, candidates, cur, out);
    return out;
}
