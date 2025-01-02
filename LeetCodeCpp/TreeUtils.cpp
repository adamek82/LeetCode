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

// Print the tree
template <typename T>
void TreeUtils::printTree(TreeNode<T>* root) {
    if (!root) return;

    int maxLevel = TreeUtils::maxLevel(root);
    printNodeInternal(std::vector<TreeNode<T>*>({root}), 1, maxLevel);
}

// Helper: Print nodes recursively
template <typename T>
void TreeUtils::printNodeInternal(const std::vector<TreeNode<T>*>& nodes, int level, int maxLevel) {
    if (nodes.empty() || isAllElementsNull(nodes)) return;

    int floor = maxLevel - level;
    int edgeLines = static_cast<int>(std::pow(2, std::max(floor - 1, 0)));
    int firstSpaces = static_cast<int>(std::pow(2, floor)) - 1;
    int betweenSpaces = static_cast<int>(std::pow(2, floor + 1)) - 1;

    printWhitespaces(firstSpaces);

    std::vector<TreeNode<T>*> newNodes;
    for (TreeNode<T>* node : nodes) {
        if (node) {
            std::cout << node->val;
            newNodes.push_back(node->left);
            newNodes.push_back(node->right);
        } else {
            std::cout << " ";
            newNodes.push_back(nullptr);
            newNodes.push_back(nullptr);
        }
        printWhitespaces(betweenSpaces);
    }
    std::cout << std::endl;

    for (int i = 1; i <= edgeLines; i++) {
        for (size_t j = 0; j < nodes.size(); j++) {
            printWhitespaces(firstSpaces - i);
            if (nodes[j] == nullptr) {
                printWhitespaces(edgeLines + edgeLines + i + 1);
                continue;
            }

            if (nodes[j]->left != nullptr) {
                std::cout << "/";
            } else {
                printWhitespaces(1);
            }

            printWhitespaces(i + i - 1);

            if (nodes[j]->right != nullptr) {
                std::cout << "\\";
            } else {
                printWhitespaces(1);
            }

            printWhitespaces(edgeLines + edgeLines - i);
        }
        std::cout << std::endl;
    }

    printNodeInternal(newNodes, level + 1, maxLevel);
}

// Helper: Print whitespaces
void TreeUtils::printWhitespaces(int count) {
    for (int i = 0; i < count; i++) {
        std::cout << " ";
    }
}

// Helper: Find the maximum depth of the tree
template <typename T>
int TreeUtils::maxLevel(TreeNode<T>* node) {
    if (!node) return 0;
    return std::max(maxLevel(node->left), maxLevel(node->right)) + 1;
}

// Helper: Check if all elements in a vector are null
template <typename T>
bool TreeUtils::isAllElementsNull(const std::vector<TreeNode<T>*>& nodes) {
    for (TreeNode<T>* node : nodes) {
        if (node != nullptr) return false;
    }
    return true;
}

template <typename T>
TreeNode<T>* TreeUtils::findNode(TreeNode<T>* root, T value) {
    while (root) {
        if (root->val == value) {
            return root; // Node found
        } else if (value < root->val) {
            root = root->left; // Traverse left subtree
        } else {
            root = root->right; // Traverse right subtree
        }
    }
    return nullptr; // Node not found
}

template <typename T>
void TreeUtils::freeTree(TreeNode<T>* root) {
    if (!root) return;

    // Recursively free left and right subtrees
    freeTree(root->left);
    freeTree(root->right);

    // Delete the current node
    delete root;
}

// Explicit instantiation for int type
template TreeNode<int>* TreeUtils::vectorToTree(const std::vector<std::optional<int>>& values);
template std::string TreeUtils::toLevelOrderString(TreeNode<int>* root);
template void TreeUtils::printTree(TreeNode<int>* root);
template TreeNode<int>* TreeUtils::findNode(TreeNode<int>* root, int value);
template void TreeUtils::freeTree(TreeNode<int>* root);
