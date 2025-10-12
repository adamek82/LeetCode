#include "LongestIncreasingPathInMatrix_329.h"
#include <algorithm>
#include <vector>

/*
 * Algorithm (DFS + memoization = top-down DP on an implicit DAG)
 * --------------------------------------------------------------
 * View each cell (r,c) as a node. Draw a directed edge from (r,c) to any
 * 4-neighbor (nr,nc) with matrix[nr][nc] > matrix[r][c]. Because edges always
 * go to a strictly larger value, this directed graph is acyclic (strictly
 * increasing values cannot form a cycle). The answer is the length of the
 * longest path in this DAG.
 *
 * We compute:
 *   dp[r][c] = 1 + max_{(nr,nc) is a larger-valued neighbor of (r,c)} dp[nr][nc],
 * with base case dp[r][c] = 1 if no outgoing edge exists. We evaluate dp by
 * DFS with memoization; each cell is solved once and then reused.
 *
 * Correctness sketch
 * ------------------
 * 1) Acyclicity:
 *    Every edge increases the matrix value strictly; hence no cycle exists.
 *
 * 2) Optimal substructure:
 *    Any maximal increasing path starting at (r,c) must choose one of the
 *    strictly larger neighbors (if any) as the next step; what follows from
 *    that neighbor is again the longest increasing path starting there.
 *    Therefore the recurrence above exactly matches the problem’s structure.
 *
 * 3) Termination and memo soundness:
 *    Since the graph is a DAG, a DFS starting at any node eventually reaches
 *    sinks (cells with no larger neighbors). Memoizing dp[r][c] after first
 *    computation ensures future visits return the same value without recomputing,
 *    so each state is solved once.
 *
 * Complexity
 * ----------
 * Let m x n be the grid size.
 *  - Time:  O(m*n) states, each inspects up to 4 neighbors ⇒ O(m*n).
 *  - Space: O(m*n) for the memo table and recursion stack in the worst case.
 */

int LongestIncreasingPathInMatrix_329::dfs(
    int r, int c,
    const vector<vector<int>>& a,
    vector<vector<int>>& dp
) {
    if (dp[r][c] != 0) return dp[r][c];

    static const int dr[4] = {-1, 0, 1, 0};
    static const int dc[4] = { 0, 1, 0,-1};

    const int m = (int)a.size();
    const int n = (int)a[0].size();
    int best = 1; // at least the cell itself

    for (int k = 0; k < 4; ++k) {
        int nr = r + dr[k], nc = c + dc[k];
        if (nr < 0 || nr >= m || nc < 0 || nc >= n) continue;
        if (a[nr][nc] > a[r][c]) {
            best = max(best, 1 + dfs(nr, nc, a, dp));
        }
    }
    dp[r][c] = best;
    return best;
}

int LongestIncreasingPathInMatrix_329::longestIncreasingPath(vector<vector<int>>& matrix) {
    const int m = (int)matrix.size();
    if (m == 0) return 0;
    const int n = (int)matrix[0].size();

    vector<vector<int>> dp(m, vector<int>(n, 0));
    int ans = 0;
    for (int r = 0; r < m; ++r)
        for (int c = 0; c < n; ++c)
            ans = max(ans, dfs(r, c, matrix, dp));
    return ans;
}
