#pragma once

#include "common/TreeNode.h"

class SubtreeOfAnotherTree_572 {
public:
    bool isSubtree(TreeNode<int>* root, TreeNode<int>* subRoot);

private:
    bool isSame(TreeNode<int>* a, TreeNode<int>* b);
};
