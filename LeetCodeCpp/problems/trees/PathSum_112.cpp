#include "PathSum_112.h"

using namespace std;

/*
 * Path Sum (LeetCode 112)
 * -----------------------
 * We need a root-to-LEAF path whose node values sum to targetSum.
 *
 * Approach — DFS with running remainder:
 * - At each node subtract node->val from the remaining sum.
 * - If we are at a leaf (no children), return true iff remainingSum == node->val.
 * - Otherwise recursively search left and/or right with updated remainingSum.
 *
 * Complexity:
 * - Time:  O(n), each node is visited at most once.
 * - Space: O(h) for the recursion stack, where h is the height of the tree
 *          (O(n) worst case, O(log n) for a balanced tree).
 */
bool PathSum_112::hasPathSum(TreeNode<int>* root, int targetSum) {
    return dfs(root, targetSum);
}

bool PathSum_112::dfs(TreeNode<int>* node, int remainingSum) {
    if (!node) return false;

    remainingSum -= node->val;

    // Check leaf
    if (!node->left && !node->right) {
        return remainingSum == 0;
    }

    return dfs(node->left, remainingSum) ||
           dfs(node->right, remainingSum);
}
