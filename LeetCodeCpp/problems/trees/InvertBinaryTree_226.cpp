#include "InvertBinaryTree_226.h"

#include <utility>

using namespace std;

TreeNode<int>* InvertBinaryTree_226::invertTree(TreeNode<int>* root) {
    if (root == nullptr) {
        return nullptr;
    }

    swap(root->left, root->right);

    invertTree(root->left);
    invertTree(root->right);

    return root;
}
