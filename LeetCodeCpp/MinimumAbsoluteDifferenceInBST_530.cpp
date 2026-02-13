#include "MinimumAbsoluteDifferenceInBST_530.h"
#include <limits>       // for std::numeric_limits
#include <algorithm>    // for min

using namespace std;

/*
 * Minimum Absolute Difference in BST (LeetCode 530)
 * -------------------------------------------------
 * In a Binary Search Tree, an in-order traversal (left, node, right) visits
 * nodes in non-decreasing (sorted) order.
 *
 * Approach — in-order DFS + running previous node:
 * - Traverse the tree in-order.
 * - Keep a pointer `prev` to the previously visited node.
 * - For each current node (when `prev` is not null) update `minDiff` with
 *   min(minDiff, node->val - prev->val).
 * - Set `prev = node` and continue.
 *
 * Correctness:
 * - Because in-order yields values in sorted order, the smallest absolute
 *   difference between any two node values must occur between some pair of
 *   adjacent values in this order.
 * - By checking only differences between consecutive in-order values, we do
 *   not miss the global minimum.
 *
 * Complexity:
 * - Time:  O(n), each node is visited exactly once.
 * - Space: O(h) for the recursion stack, where h is the tree height
 *          (O(n) in the worst case, O(log n) for a balanced tree).
 */
int MinimumAbsoluteDifferenceInBST_530::getMinimumDifference(TreeNode<int>* root) {
    minDiff = numeric_limits<int>::max();
    prev = nullptr;

    inOrder(root);
    return minDiff;
}

void MinimumAbsoluteDifferenceInBST_530::inOrder(TreeNode<int>* node) {
    if (!node) return;

    inOrder(node->left);

    if (prev != nullptr) {
        minDiff = min(minDiff, node->val - prev->val);
    }
    prev = node;

    inOrder(node->right);
}
