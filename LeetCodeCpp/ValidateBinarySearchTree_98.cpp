#include "ValidateBinarySearchTree_98.h"

using namespace std;

/*
 * Validate Binary Search Tree (LeetCode 98)
 * ----------------------------------------
 * Goal: determine whether a binary tree is a valid BST.
 *
 * BST property:
 * - For every node:
 *     all values in the left subtree  < node->val
 *     all values in the right subtree > node->val
 * - This must hold recursively for every subtree, not only for direct children.
 *
 * Approach — DFS with value ranges:
 * - Each recursive call carries the allowed open interval (minVal, maxVal)
 *   for the current node’s value.
 * - Initially, the root may take any value in (−∞, +∞), represented here as
 *   (numeric_limits<long>::min(), numeric_limits<long>::max()).
 * - At a node `x`:
 *     • If x->val is not strictly inside (minVal, maxVal), the BST property
 *       is violated → return false.
 *     • Recursively validate:
 *         left  subtree with range (minVal, x->val)
 *         right subtree with range (x->val, maxVal)
 *   This way, every descendant is constrained not only by its parent, but by
 *   all ancestors above it.
 *
 * Why strict inequalities?
 * - We use `node->val <= minVal` or `node->val >= maxVal` as violation,
 *   which enforces strict ordering (no duplicates allowed on either side),
 *   matching the usual LeetCode definition for a BST in this problem.
 *
 * Correctness (sketch):
 * - Soundness: If the function returns true, then for every node:
 *     • Its value lies inside the interval passed to it, which was derived by
 *       pushing ancestor values down (left uses upper bound = parent value,
 *       right uses lower bound = parent value).
 *     • Therefore, it is strictly greater than all values in its left-ancestor
 *       chain and strictly smaller than all values in its right-ancestor chain.
 *   Hence the global BST property holds for the whole tree.
 *
 * - Completeness: If the tree satisfies the BST property, then:
 *     • For the root, its value lies in (−∞, +∞).
 *     • For any node, all its ancestors have imposed consistent bounds, and
 *       its own value respects those bounds by the BST definition.
 *     • Therefore, no node will ever violate the (minVal, maxVal) check, and
 *       all recursive calls return true.
 *
 * Complexity:
 * - Time:  O(n), each node is visited exactly once.
 * - Space: O(h) for the recursion stack, where h is the tree height
 *          (O(n) in the worst case, O(log n) for a balanced BST).
 */
bool ValidateBinarySearchTree_98::isValidBST(TreeNode<int> *root)
{
    return validate(root, numeric_limits<long>::min(), numeric_limits<long>::max());
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
