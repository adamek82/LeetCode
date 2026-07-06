#include "LongestIncreasingPathInMatrix_329.h"

#include <algorithm>
#include <array>
#include <utility>
#include <vector>

using namespace std;

int LongestIncreasingPathInMatrix_329::longestIncreasingPath(vector<vector<int>>& matrix)
{
    if (matrix.empty() || matrix[0].empty()) {
        return 0;
    }

    const int m = static_cast<int>(matrix.size());
    const int n = static_cast<int>(matrix[0].size());

    vector<vector<int>> dp(m, vector<int>(n, 0));

    int ans = 0;
    for (int r = 0; r < m; ++r) {
        for (int c = 0; c < n; ++c) {
            ans = max(ans, dfs(r, c, matrix, dp));
        }
    }

    return ans;
}

int LongestIncreasingPathInMatrix_329::dfs(
    int r,
    int c,
    const vector<vector<int>>& matrix,
    vector<vector<int>>& dp)
{
    if (dp[r][c] != 0) {
        return dp[r][c];
    }

    static constexpr array<pair<int, int>, 4> directions{{
        {-1, 0}, {0, 1}, {1, 0}, {0, -1}
    }};

    const int m = static_cast<int>(matrix.size());
    const int n = static_cast<int>(matrix[0].size());

    int best = 1;

    for (const auto& [dr, dc] : directions) {
        const int nr = r + dr;
        const int nc = c + dc;

        if (nr >= 0 && nr < m
            && nc >= 0 && nc < n
            && matrix[nr][nc] > matrix[r][c]) {
            best = max(best, 1 + dfs(nr, nc, matrix, dp));
        }
    }

    dp[r][c] = best;
    return best;
}
