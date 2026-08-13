#include "MaximumDepthOfBinaryTree_104.h"

#include <algorithm>
#include <queue>
#include <stack>
#include <utility>

using namespace std;

int MaximumDepthOfBinaryTree_104::maxDepthRecursive(TreeNode<int>* root) {
    if (root == nullptr) {
        return 0;
    }

    return 1 + max(
        maxDepthRecursive(root->left),
        maxDepthRecursive(root->right));
}

int MaximumDepthOfBinaryTree_104::maxDepthDFSStack(TreeNode<int>* root) {
    if (root == nullptr) {
        return 0;
    }

    stack<pair<TreeNode<int>*, int>> nodes;
    nodes.emplace(root, 1);

    int maxDepth = 0;

    while (!nodes.empty()) {
        const auto [node, depth] = nodes.top();
        nodes.pop();

        maxDepth = max(maxDepth, depth);

        if (node->left != nullptr) {
            nodes.emplace(node->left, depth + 1);
        }
        if (node->right != nullptr) {
            nodes.emplace(node->right, depth + 1);
        }
    }

    return maxDepth;
}

int MaximumDepthOfBinaryTree_104::maxDepthBFSQueue(TreeNode<int>* root) {
    if (root == nullptr) {
        return 0;
    }

    queue<TreeNode<int>*> nodes;
    nodes.push(root);

    int depth = 0;

    while (!nodes.empty()) {
        const size_t levelSize = nodes.size();

        for (size_t i = 0; i < levelSize; ++i) {
            TreeNode<int>* const node = nodes.front();
            nodes.pop();

            if (node->left != nullptr) {
                nodes.push(node->left);
            }
            if (node->right != nullptr) {
                nodes.push(node->right);
            }
        }

        ++depth;
    }

    return depth;
}
