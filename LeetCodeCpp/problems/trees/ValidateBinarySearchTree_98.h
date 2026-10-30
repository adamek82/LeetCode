#pragma once

#include "common/TreeNode.h"

class ValidateBinarySearchTree_98 {
public:
    bool isValidBST(TreeNode<int>* root);

private:
    bool validate(TreeNode<int>* node, long minVal, long maxVal);
};
