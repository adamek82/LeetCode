#pragma once

#include "common/TreeNode.h"

class MaximumDepthOfBinaryTree_104 {
public:
    int maxDepthRecursive(TreeNode<int>* root);
    int maxDepthDFSStack(TreeNode<int>* root);
    int maxDepthBFSQueue(TreeNode<int>* root);
};
