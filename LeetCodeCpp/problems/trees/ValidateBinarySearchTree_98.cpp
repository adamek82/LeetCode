#include "ValidateBinarySearchTree_98.h"

#include <limits>

using namespace std;

bool ValidateBinarySearchTree_98::isValidBST(TreeNode<int>* root)
{
    return validate(root,
                    numeric_limits<long long>::min(),
                    numeric_limits<long long>::max());
}

bool ValidateBinarySearchTree_98::validate(
    TreeNode<int>* node, long long minVal, long long maxVal)
{
    if (!node) {
        return true;
    }

    if (node->val <= minVal || node->val >= maxVal) {
        return false;
    }

    return validate(node->left, minVal, node->val) &&
           validate(node->right, node->val, maxVal);
}
