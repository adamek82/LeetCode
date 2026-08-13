#include "BinaryTreeLevelOrderTraversal_102.h"

#include <queue>

using namespace std;

vector<vector<int>> BinaryTreeLevelOrderTraversal_102::levelOrder(
    TreeNode<int>* root) {
    vector<vector<int>> result;

    if (root == nullptr) {
        return result;
    }

    queue<TreeNode<int>*> nodes;
    nodes.push(root);

    while (!nodes.empty()) {
        const size_t levelSize = nodes.size();

        vector<int> level;
        level.reserve(levelSize);

        for (size_t i = 0; i < levelSize; ++i) {
            TreeNode<int>* const node = nodes.front();
            nodes.pop();

            level.push_back(node->val);

            if (node->left != nullptr) {
                nodes.push(node->left);
            }
            if (node->right != nullptr) {
                nodes.push(node->right);
            }
        }

        result.push_back(move(level));
    }

    return result;
}
