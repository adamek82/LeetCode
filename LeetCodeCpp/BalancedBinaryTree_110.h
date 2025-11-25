#pragma once

#include "TreeNode.h"

class BalancedBinaryTree_110 {
public:
    bool isBalanced(TreeNode<int>* root);

private:
    // Returns subtree height, or -1 if this subtree is already unbalanced.
    int heightOrUnbalanced(TreeNode<int>* node);
};
