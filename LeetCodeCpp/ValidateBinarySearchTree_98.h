#pragma once
#include <limits>
#include "TreeNode.h"

class ValidateBinarySearchTree_98 {
public:
    bool isValidBST(TreeNode<int>* root);
private:
    // Helper function to validate the BST with range checks
    bool validate(TreeNode<int>* node, long minVal, long maxVal);
};