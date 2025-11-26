#pragma once

#include "TreeNode.h"

class MinimumAbsoluteDifferenceInBST_530 {
public:
    int getMinimumDifference(TreeNode<int>* root);

private:
    int minDiff;               // current best (minimum) difference
    TreeNode<int>* prev = nullptr; // previously visited node in in-order (nullptr if none yet)

    void inOrder(TreeNode<int>* node);
};
