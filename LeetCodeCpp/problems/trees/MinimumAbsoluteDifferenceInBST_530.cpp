#include "MinimumAbsoluteDifferenceInBST_530.h"

#include <algorithm>
#include <limits>
#include <stack>

using namespace std;

int MinimumAbsoluteDifferenceInBST_530::getMinimumDifferenceRecursive(
    TreeNode<int>* root)
{
    const TreeNode<int>* previous = nullptr;
    int minDifference = numeric_limits<int>::max();

    inorder(root, previous, minDifference);
    return minDifference;
}

void MinimumAbsoluteDifferenceInBST_530::inorder(
    const TreeNode<int>* node, const TreeNode<int>*& previous, int& minDifference)
{
    if (node == nullptr) {
        return;
    }

    inorder(node->left, previous, minDifference);

    if (previous != nullptr) {
        minDifference = min(minDifference, node->val - previous->val);
    }

    previous = node;
    inorder(node->right, previous, minDifference);
}

int MinimumAbsoluteDifferenceInBST_530::getMinimumDifferenceIterative(
    TreeNode<int>* root)
{
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
