#pragma once
#include <algorithm>
#include <vector>
#include <stack>

using namespace std;

class MaxAreaOfIsland_695 {
public:
    // Depth-first search that uses recursion (old implementation, just renamed)
    int maxAreaOfIslandRecursive(vector<vector<int>>& grid);

    // Iterative DFS using an explicit stack (new implementation)
    int maxAreaOfIslandIterative(vector<vector<int>>& grid);
private:
    // helper for the recursive variant (old implementation, just renamed)
    int dfsRecursive(vector<vector<int>>& grid, int i, int j);

    // helper for the iterative variant (new implementation)
    int floodFillIterative(vector<vector<int>>& grid, int r, int c);
};