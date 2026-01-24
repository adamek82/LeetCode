#pragma once
#include "TreeNode.h"

class SubtreeOfAnotherTree_572 {
public:
    bool isSubtree(TreeNode<int>* root, TreeNode<int>* subRoot);

private:
    // Returns true if the two trees have identical structure and node values.
    bool isSame(TreeNode<int>* a, TreeNode<int>* b);
};
