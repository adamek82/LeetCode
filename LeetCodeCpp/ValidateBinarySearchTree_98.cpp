#include "ValidateBinarySearchTree_98.h"

bool ValidateBinarySearchTree_98::isValidBST(TreeNode<int> *root)
{
    return validate(root, std::numeric_limits<long>::min(), std::numeric_limits<long>::max());
}

bool ValidateBinarySearchTree_98::validate(TreeNode<int> *node, long minVal, long maxVal)
{
    if (!node) return true;

    // Check if the current node's value violates the BST property
    if (node->val <= minVal || node->val >= maxVal) {
        return false;
    }

    // Recursively validate the left and right subtrees
    return validate(node->left, minVal, node->val) &&
        validate(node->right, node->val, maxVal);
}
