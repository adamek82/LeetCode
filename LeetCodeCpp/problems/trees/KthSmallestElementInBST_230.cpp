#include "KthSmallestElementInBST_230.h"

#include <stack>

using namespace std;

int KthSmallestElementInBST_230::kthSmallest(TreeNode<int>* root, int k) {
    stack<TreeNode<int>*> nodes;
    TreeNode<int>* node = root;

    while (node != nullptr || !nodes.empty()) {
        while (node != nullptr) {
            nodes.push(node);
            node = node->left;
        }

        node = nodes.top();
        nodes.pop();

        if (--k == 0) {
            return node->val;
        }

        node = node->right;
    }

    return -1;
}
