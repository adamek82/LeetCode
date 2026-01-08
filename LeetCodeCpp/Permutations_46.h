#pragma once
#include <vector>
using namespace std;

class Permutations_46 {
public:
    vector<vector<int>> permute(vector<int>& nums);

private:
    // Backtracking driver: fixes prefix [0..pos-1], permutes suffix [pos..n-1].
    static void dfsPerm(int pos, vector<int>& nums, vector<vector<int>>& out);
};
