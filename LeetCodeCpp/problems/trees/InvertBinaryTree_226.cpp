#include "InvertBinaryTree_226.h"
#include <utility>  // for std::swap

using namespace std;

/*
 * Invert Binary Tree (LeetCode 226)
 * ---------------------------------
 * Approach — recursive DFS:
 * 1. If the current node is null, there is nothing to invert, so return null.
 * 2. Swap its left and right children.
 * 3. Recursively invert the (new) left and right subtrees.
 *
 * Correctness
 * -----------
 * We process every node exactly once. For each node we swap its two children.
 * Therefore, for every edge (parent → left) and (parent → right) in the original
 * tree, the roles are reversed in the resulting tree. This guarantees that the
 * whole tree becomes the mirror image with respect to its root.
 *
 * Complexity
 * ----------
 * Time  : O(n), where n is the number of nodes, because each node is visited once.
 * Space : O(h) for the recursion stack, where h is the height of the tree
 *         (O(n) in the worst case of a skewed tree, O(log n) for a balanced tree).
 */
TreeNode<int>* InvertBinaryTree_226::invertTree(TreeNode<int>* root) {
    if (!root) return nullptr;

    // Swap left and right children
    swap(root->left, root->right);

    // Recursively invert subtrees
    invertTree(root->left);
    invertTree(root->right);

    return root;
}
