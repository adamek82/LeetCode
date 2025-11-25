#include "BalancedBinaryTree_110.h"
#include <algorithm> // for max
#include <cstdlib>   // for abs

using namespace std;

/*
 * Balanced Binary Tree (LeetCode 110)
 * -----------------------------------
 * A tree is height-balanced if for every node the heights of its left and
 * right subtrees differ by at most 1.
 *
 * Approach — bottom-up DFS:
 * - Recursively compute the height of each subtree.
 * - If a child subtree is already unbalanced, propagate a sentinel (-1).
 * - At each node, if |leftHeight - rightHeight| > 1, return -1 (unbalanced).
 * - Otherwise return 1 + max(leftHeight, rightHeight).
 *
 * Complexity:
 * - Time:  O(n), each node is visited once.
 * - Space: O(h) for the recursion stack, where h is the tree height
 *          (O(n) in the worst case, O(log n) for a balanced tree).
 */
bool BalancedBinaryTree_110::isBalanced(TreeNode<int>* root) {
    return heightOrUnbalanced(root) != -1;
}

int BalancedBinaryTree_110::heightOrUnbalanced(TreeNode<int>* node) {
    if (!node) return 0;

    int left  = heightOrUnbalanced(node->left);
    if (left == -1) return -1;

    int right = heightOrUnbalanced(node->right);
    if (right == -1) return -1;

    if (abs(left - right) > 1) return -1;

    return 1 + max(left, right);
}
