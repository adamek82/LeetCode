#include "SubtreeOfAnotherTree_572.h"

using namespace std;

/*
 * Subtree of Another Tree (LeetCode 572)
 * --------------------------------------
 * We want to know whether `subRoot` appears as a subtree inside `root`.
 * A subtree is defined as a node together with all its descendants.
 *
 * Approach — DFS + subtree equality:
 * - Traverse every node in `root`.
 * - At each node, treat it as a candidate root and compare its subtree
 *   with `subRoot` using a tree-equality helper (`isSame`).
 * - If any candidate matches, return true; if we exhaust all candidates,
 *   there is no matching subtree.
 *
 * Complexity:
 * - Let n = |root| and m = |subRoot|.
 * - Time:  O(n * m) in the worst case, when many nodes share values and
 *          structure is similar so `isSame` walks most of `subRoot` often.
 * - Space: O(h1 + h2) for recursion, where h1 and h2 are the heights of
 *          `root` and `subRoot` (worst-case O(n + m), best-case O(log n + log m)).
 */
bool SubtreeOfAnotherTree_572::isSubtree(TreeNode<int>* root, TreeNode<int>* subRoot) {
    if (!subRoot) return true;   // empty tree is a subtree of any tree
    if (!root)    return false;  // non-empty subRoot cannot be in an empty root

    if (isSame(root, subRoot)) return true;

    return isSubtree(root->left, subRoot) ||
           isSubtree(root->right, subRoot);
}

bool SubtreeOfAnotherTree_572::isSame(TreeNode<int>* a, TreeNode<int>* b) {
    if (!a && !b) return true;
    if (!a || !b) return false;
    if (a->val != b->val) return false;

    return isSame(a->left,  b->left) &&
           isSame(a->right, b->right);
}
