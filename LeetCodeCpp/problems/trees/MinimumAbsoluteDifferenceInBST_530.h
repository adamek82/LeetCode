#pragma once

#include "common/TreeNode.h"

class MinimumAbsoluteDifferenceInBST_530 {
public:
    int getMinimumDifferenceRecursive(TreeNode<int>* root);
    int getMinimumDifferenceIterative(TreeNode<int>* root);

private:
    void inorder(
        const TreeNode<int>* node, const TreeNode<int>*& previous, int& minDifference);
};
