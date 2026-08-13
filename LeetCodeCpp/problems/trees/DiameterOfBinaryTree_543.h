#pragma once

#include "common/TreeNode.h"

class DiameterOfBinaryTree_543 {
public:
    int diameterOfBinaryTree(TreeNode<int>* root);

private:
    int dfsHeight(TreeNode<int>* node, int& best);
};
