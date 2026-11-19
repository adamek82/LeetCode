#include "DeleteNodeInBST_450.h"

using namespace std;

TreeNode<int>* DeleteNodeInBST_450::deleteNode(TreeNode<int>* root, int key)
{
    if (root == nullptr) {
        return nullptr;
    }

    if (key < root->val) {
        root->left = deleteNode(root->left, key);
    } else if (key > root->val) {
        root->right = deleteNode(root->right, key);
    } else {
        // Node with 0 or 1 child
        if (root->left == nullptr) {
            TreeNode<int>* right = root->right;
            delete root;
            return right;
        }

        if (root->right == nullptr) {
            TreeNode<int>* left = root->left;
            delete root;
            return left;
        }

        // Node with 2 children
        TreeNode<int>* successor = root->right;

        while (successor->left != nullptr) {
            successor = successor->left;
        }

        root->val = successor->val;
        root->right = deleteNode(root->right, successor->val);
    }

    return root;
}
