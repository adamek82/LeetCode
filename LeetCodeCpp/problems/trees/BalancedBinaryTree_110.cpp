#include "BalancedBinaryTree_110.h"

#include <algorithm>
#include <cstdlib>

using namespace std;

bool BalancedBinaryTree_110::isBalanced(TreeNode<int>* root) {
    return heightOrUnbalanced(root) != -1;
}

int BalancedBinaryTree_110::heightOrUnbalanced(TreeNode<int>* node) {
    if (node == nullptr) {
        return 0;
    }

    const int leftHeight = heightOrUnbalanced(node->left);
    if (leftHeight == -1) {
        return -1;
    }

    const int rightHeight = heightOrUnbalanced(node->right);
    if (rightHeight == -1) {
        return -1;
    }

    if (abs(leftHeight - rightHeight) > 1) {
        return -1;
    }

    return 1 + max(leftHeight, rightHeight);
}
