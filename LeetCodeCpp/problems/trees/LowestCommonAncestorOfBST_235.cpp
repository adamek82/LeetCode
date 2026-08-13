#include "LowestCommonAncestorOfBST_235.h"

TreeNode<int>* LowestCommonAncestorOfBST_235::lowestCommonAncestor(
    TreeNode<int>* root,
    TreeNode<int>* p,
    TreeNode<int>* q) {
    while (root != nullptr) {
        if (p->val < root->val && q->val < root->val) {
            root = root->left;
        } else if (p->val > root->val && q->val > root->val) {
            root = root->right;
        } else {
            return root;
        }
    }

    return nullptr;
}
