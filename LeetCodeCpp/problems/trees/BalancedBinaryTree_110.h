#pragma once

#include "common/TreeNode.h"

class BalancedBinaryTree_110 {
public:
    bool isBalanced(TreeNode<int>* root);

private:
    int heightOrUnbalanced(TreeNode<int>* node);
};
