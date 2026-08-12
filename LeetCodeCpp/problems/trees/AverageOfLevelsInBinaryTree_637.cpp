#include "AverageOfLevelsInBinaryTree_637.h"

#include <queue>

vector<double> AverageOfLevelsInBinaryTree_637::averageOfLevels(TreeNode<int>* root) {
    vector<double> result;

    if (root == nullptr) {
        return result;
    }

    queue<TreeNode<int>*> nodes;
    nodes.push(root);

    while (!nodes.empty()) {
        const size_t levelSize = nodes.size();
        long long sum = 0;

        for (size_t i = 0; i < levelSize; ++i) {
            TreeNode<int>* const node = nodes.front();
            nodes.pop();

            sum += node->val;

            if (node->left != nullptr) {
                nodes.push(node->left);
            }
            if (node->right != nullptr) {
                nodes.push(node->right);
            }
        }

        result.push_back(
            static_cast<double>(sum) / static_cast<double>(levelSize));
    }

    return result;
}
