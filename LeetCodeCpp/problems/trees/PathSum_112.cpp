#include "PathSum_112.h"

bool PathSum_112::hasPathSum(TreeNode<int>* root, int targetSum)
{
    if (root == nullptr) {
        return false;
    }

    targetSum -= root->val;

    if (root->left == nullptr && root->right == nullptr) {
        return targetSum == 0;
    }

    return hasPathSum(root->left, targetSum) ||
           hasPathSum(root->right, targetSum);
}
