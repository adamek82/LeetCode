#include "LowestCommonAncestorOfBST_235.h"

/*
 * Lowest Common Ancestor of a BST (LeetCode 235)
 * ----------------------------------------------
 * Goal: given the root of a Binary Search Tree and two nodes p and q that
 * exist in the tree, find their lowest common ancestor (LCA).
 *
 * BST property:
 * - For every node x:
 *     all values in the left subtree  < x->val
 *     all values in the right subtree > x->val
 *
 * Approach — walk down using BST ordering:
 * - Start at the root and use the values of p and q to decide where the LCA
 *   must lie:
 *   1) If p->val and q->val are both < root->val:
 *        → both nodes lie strictly in the left subtree, so the LCA must also
 *          lie in that left subtree. Move root = root->left.
 *   2) If p->val and q->val are both > root->val:
 *        → both nodes lie strictly in the right subtree, so the LCA must lie
 *          in the right subtree. Move root = root->right.
 *   3) Otherwise:
 *        → p and q are on different sides of root, or one of them equals root.
 *          In either case, root is the first node where their paths from the
 *          original root diverge (or meet), so root is the LCA.
 *
 * Correctness (sketch):
 * - Case 1 (both < root->val):
 *   Since all values in the right subtree are > root->val, neither p nor q
 *   can be in the right subtree. Both are strictly in the left subtree, so
 *   any common ancestor of p and q must also lie in that left subtree.
 *   In particular, both paths root→p and root→q start with the edge to
 *   root->left, so they share at least one common node strictly below root
 *   (namely root->left). The *lowest* common ancestor therefore lies inside
 *   the left subtree, and cannot be root or any node above root. Thus moving
 *   root = root->left preserves all possible LCAs.
 *
 * - Case 2 (both > root->val):
 *   Symmetric: p and q are strictly in the right subtree, so any common
 *   ancestor must lie there. The LCA cannot be root or above it. Moving
 *   root = root->right keeps all candidates.
 *
 * - Case 3 (different sides or one equals root):
 *   Here p and q lie in different subtrees of root, or root is one of them.
 *   This means root is the first node on the path from the original root
 *   that has p and q in different directions (or coincides with one of them),
 *   so root is by definition their *lowest* common ancestor.
 *
 * Since on each step we either correctly restrict ourselves to the left or
 * right subtree (cases 1–2) or stop at the first divergence (case 3), the
 * algorithm returns the unique LCA of p and q.
 *
 * Complexity:
 * - Time:  O(h), where h is the height of the BST (O(log n) for a balanced
 *          tree, O(n) in the worst case of a skewed tree).
 * - Space: O(1) extra, the algorithm is iterative and uses only a few pointers.
 */
TreeNode<int> *LowestCommonAncestorOfBST_235::lowestCommonAncestor(TreeNode<int> *root, TreeNode<int> *p, TreeNode<int> *q)
{
    while (root) {
        // If both p and q are smaller than root, LCA lies in the left subtree.
        if (p->val < root->val && q->val < root->val) {
            root = root->left;
        }
        // If both p and q are greater than root, LCA lies in the right subtree.
        else if (p->val > root->val && q->val > root->val) {
            root = root->right;
        }
        // If p and q are on opposite sides or one of them equals root, root is the LCA.
        else {
            return root;
        }
    }
    return nullptr; // Should never reach here if p and q exist in the BST.}
}
