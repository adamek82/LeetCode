#include "KthSmallestElementInBST_230.h"

int KthSmallestElementInBST_230::kthSmallest(TreeNode<int> *root, int k)
{
    count = k;    // Initialize countdown
    result = -1;  // Reset result
    inOrderTraversal(root);
    return result;
}

void KthSmallestElementInBST_230::inOrderTraversal(TreeNode<int> *node)
{
    if (!node) return;

    // Traverse the left subtree
    inOrderTraversal(node->left);

    // Visit the current node
    count--; // Decrement count
    if (count == 0) {
        result = node->val;
        return; // Early termination
    }

    // Traverse the right subtree
    inOrderTraversal(node->right);
}