#include "TreeUtils.h"

// Create a binary tree from a vector (level-by-level)
template <typename T>
TreeNode<T>* TreeUtils::vectorToTree(const std::vector<std::optional<T>>& values) {
    if (values.empty() || !values[0]) return nullptr;

    TreeNode<T>* root = new TreeNode<T>(values[0].value());
    std::queue<TreeNode<T>*> q;
    q.push(root);

    size_t i = 1;
    while (i < values.size()) {
        TreeNode<T>* current = q.front();
        q.pop();

        // Assign left child
        if (i < values.size() && values[i].has_value()) {
            current->left = new TreeNode<T>(values[i].value());
            q.push(current->left);
        }
        ++i;

        // Assign right child
        if (i < values.size() && values[i].has_value()) {
            current->right = new TreeNode<T>(values[i].value());
            q.push(current->right);
        }
        ++i;
    }

    return root;
}

// Convert the tree to a level-order string representation
template <typename T>
std::string TreeUtils::toLevelOrderString(TreeNode<T>* root) {
    if (!root) return "null";

    std::ostringstream oss;
    std::queue<TreeNode<T>*> q;
    q.push(root);

    while (!q.empty()) {
        TreeNode<T>* current = q.front();
        q.pop();

        if (current) {
            oss << current->val << " ";
            q.push(current->left);
            q.push(current->right);
        } else {
            oss << "null ";
        }
    }

    return oss.str();
}

// Explicit instantiation for int type
template TreeNode<int>* TreeUtils::vectorToTree(const std::vector<std::optional<int>>& values);
template std::string TreeUtils::toLevelOrderString(TreeNode<int>* root);
