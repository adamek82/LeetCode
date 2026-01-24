#pragma once
#include "TreeNode.h"

class SymmetricTree_101 {
public:
    bool isSymmetricRecursive(TreeNode<int>* root);
    bool isSymmetricIterative(TreeNode<int>* root);

private:
    bool isMirror(TreeNode<int>* left, TreeNode<int>* right);
};
