#pragma once

#include <vector>

class LongestIncreasingPathInMatrix_329 {
public:
    int longestIncreasingPath(std::vector<std::vector<int>>& matrix);

private:
    int dfs(int r,
            int c,
            const std::vector<std::vector<int>>& matrix,
            std::vector<std::vector<int>>& dp);
};
