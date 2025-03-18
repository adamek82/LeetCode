#include "LowestCommonAncestorOfBST_235.h"

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
