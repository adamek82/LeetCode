#include "MinimumAbsoluteDifferenceInBST_530.h"

#include <algorithm>
#include <limits>
#include <stack>

using namespace std;

int MinimumAbsoluteDifferenceInBST_530::getMinimumDifference(TreeNode<int>* root) {
    stack<TreeNode<int>*> nodes;
    TreeNode<int>* node = root;
    TreeNode<int>* previous = nullptr;

    int minDifference = numeric_limits<int>::max();

    while (node != nullptr || !nodes.empty()) {
        while (node != nullptr) {
            nodes.push(node);
            node = node->left;
        }

        node = nodes.top();
        nodes.pop();

        if (previous != nullptr) {
            minDifference = min(
                minDifference,
                node->val - previous->val);
        }

        previous = node;
        node = node->right;
    }

    return minDifference;
}
