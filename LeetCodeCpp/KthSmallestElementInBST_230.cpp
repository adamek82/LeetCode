#include "KthSmallestElementInBST_230.h"

/*
 * Kth Smallest Element in a BST (LeetCode 230)
 * -------------------------------------------
 * In a Binary Search Tree the in-order traversal (left, node, right) visits
 * nodes in non-decreasing (sorted) order.
 *
 * Approach — in-order DFS with countdown:
 * - Store `k` in a member `count` and run an in-order traversal.
 * - Each time we "visit" a node (between left and right subtree), decrement `count`.
 * - When `count` reaches 0, the current node is the k-th smallest; store it in
 *   `result` and terminate early.
 *
 * Correctness:
 * - In-order traversal enumerates nodes in sorted order: the first visited node
 *   is the 1st smallest, the second is the 2nd smallest, etc.
 * - Decrementing `count` at each visit and stopping exactly when it reaches 0
 *   ensures we return the k-th node in this sorted sequence.
 *
 * Complexity:
 * - Time:  O(h + k) in the average/best case due to early termination; O(n) in
 *          the worst case when k is large or the tree is skewed.
 * - Space: O(h) for the recursion stack, where h is the height of the tree.
 */
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