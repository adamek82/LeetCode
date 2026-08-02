#pragma once
#include <vector>
using namespace std;

class CombinationSum_39 {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target);

private:
    static void dfs(int start, int remain, const vector<int>& cand,
                    vector<int>& cur, vector<vector<int>>& out);
};
