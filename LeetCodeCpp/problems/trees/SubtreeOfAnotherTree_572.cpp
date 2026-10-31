#include "SubtreeOfAnotherTree_572.h"

bool SubtreeOfAnotherTree_572::isSubtree(TreeNode<int>* root, TreeNode<int>* subRoot)
{
    if (!subRoot) {
        return true;
    }

    if (!root) {
        return false;
    }

    if (isSame(root, subRoot)) {
        return true;
    }

    return isSubtree(root->left, subRoot) ||
           isSubtree(root->right, subRoot);
}

bool SubtreeOfAnotherTree_572::isSame(TreeNode<int>* a, TreeNode<int>* b)
{
    if (!a && !b) {
        return true;
    }

    if (!a || !b) {
        return false;
    }

    if (a->val != b->val) {
        return false;
    }

    return isSame(a->left, b->left) &&
           isSame(a->right, b->right);
}
