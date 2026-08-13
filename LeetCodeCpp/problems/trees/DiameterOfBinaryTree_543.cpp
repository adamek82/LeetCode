#include "DiameterOfBinaryTree_543.h"

#include <algorithm>

using namespace std;

int DiameterOfBinaryTree_543::diameterOfBinaryTree(TreeNode<int>* root) {
    int best = 0;
    dfsHeight(root, best);
    return best;
}

int DiameterOfBinaryTree_543::dfsHeight(TreeNode<int>* node, int& best) {
    if (node == nullptr) {
        return 0;
    }

    const int leftHeight = dfsHeight(node->left, best);
    const int rightHeight = dfsHeight(node->right, best);

    best = max(best, leftHeight + rightHeight);

    return 1 + max(leftHeight, rightHeight);
}
