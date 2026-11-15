#pragma once

#include "common/TreeNode.h"

class KthSmallestElementInBST_230 {
public:
    int kthSmallestRecursive(TreeNode<int>* root, int k);
    int kthSmallestIterative(TreeNode<int>* root, int k);

private:
    bool inorderTraversal(TreeNode<int>* node, int& k, int& answer);
};
