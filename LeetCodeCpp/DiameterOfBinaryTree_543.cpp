#include "DiameterOfBinaryTree_543.h"
#include <algorithm> // for max

using namespace std;

/*
 * Diameter of Binary Tree (LeetCode 543)
 * --------------------------------------
 * The diameter is the length (in edges) of the longest path between any
 * two nodes; this path may or may not pass through the root.
 *
 * Approach — DFS with height and running best:
 * - For each node, compute the height of its left and right subtrees.
 * - At that node, the longest path going through it has length
 *   leftHeight + rightHeight; keep the maximum over all nodes.
 * - Return 1 + max(leftHeight, rightHeight) as the height to the parent.
 *
 * Complexity:
 * - Time:  O(n), each node is processed exactly once.
 * - Space: O(h) for the recursion stack, where h is the tree height
 *          (O(n) worst case, O(log n) for a balanced tree).
 */
int DiameterOfBinaryTree_543::diameterOfBinaryTree(TreeNode<int>* root) {
    if (!root) return 0;
    int best = 0;
    dfsHeight(root, best);
    return best;
}

int DiameterOfBinaryTree_543::dfsHeight(TreeNode<int>* node, int& best) {
    if (!node) return 0;

    int left  = dfsHeight(node->left,  best);
    int right = dfsHeight(node->right, best);

    best = max(best, left + right);
    return 1 + max(left, right);
}
