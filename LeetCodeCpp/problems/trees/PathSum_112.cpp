#include "PathSum_112.h"

using namespace std;

bool PathSum_112::hasPathSum(TreeNode<int>* root, int targetSum)
{
    return dfs(root, targetSum);
}

bool PathSum_112::dfs(TreeNode<int>* node, int remainingSum)
{
    if (!node) {
        return false;
    }

    remainingSum -= node->val;

    if (!node->left && !node->right) {
        return remainingSum == 0;
    }

    return dfs(node->left, remainingSum) ||
           dfs(node->right, remainingSum);
}
