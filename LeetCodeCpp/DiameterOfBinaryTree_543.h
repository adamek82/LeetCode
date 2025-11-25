#pragma once

#include "TreeNode.h"

class DiameterOfBinaryTree_543 {
public:
    int diameterOfBinaryTree(TreeNode<int>* root);

private:
    // Returns subtree height (in edges) and updates best diameter.
    int dfsHeight(TreeNode<int>* node, int& best);
};
