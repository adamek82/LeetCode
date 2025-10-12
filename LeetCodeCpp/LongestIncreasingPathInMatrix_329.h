#pragma once
#include <vector>
using namespace std;

/*
 * 329. Longest Increasing Path in a Matrix
 * ----------------------------------------
 */
class LongestIncreasingPathInMatrix_329 {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix);

private:
     // Returns the longest increasing path length starting at (r, c).
    int dfs(int r, int c, const vector<vector<int>>& a, vector<vector<int>>& dp);
};
