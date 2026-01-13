#include "TreeUtils.h"

// Create a binary tree from a vector (level-by-level)
template <typename T>
TreeNode<T>* TreeUtils::vectorToTree(const vector<optional<T>>& values) {
    if (values.empty() || !values[0]) return nullptr;

    TreeNode<T>* root = new TreeNode<T>(values[0].value());
    queue<TreeNode<T>*> q;
    q.push(root);

    size_t i = 1;
    while (i < values.size()) {
        // If we still have input values but no parent nodes to attach them to,
        // the encoding is invalid (or contains trailing/orphaned items).
        if (q.empty()) {
            std::cerr
                << "[ERROR] TreeUtils::vectorToTree: invalid level-order encoding: "
                << "orphaned value(s) starting at index " << i
                << " (no remaining parent nodes in queue). Returning nullptr.\n";
            TreeUtils::freeTree(root);
            return nullptr;
        }

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
string TreeUtils::toLevelOrderString(TreeNode<T>* root) {
    if (!root) return "null";

    ostringstream oss;
    queue<TreeNode<T>*> q;
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
    printNodeInternal(vector<TreeNode<T>*>({root}), 1, maxLevel);
}

// Helper: Print nodes recursively
template <typename T>
void TreeUtils::printNodeInternal(const vector<TreeNode<T>*>& nodes, int level, int maxLevel) {
    if (nodes.empty() || isAllElementsNull(nodes)) return;

    int floor = maxLevel - level;
    int edgeLines = static_cast<int>(pow(2, max(floor - 1, 0)));
    int firstSpaces = static_cast<int>(pow(2, floor)) - 1;
    int betweenSpaces = static_cast<int>(pow(2, floor + 1)) - 1;

    printWhitespaces(firstSpaces);

    vector<TreeNode<T>*> newNodes;
    for (TreeNode<T>* node : nodes) {
        if (node) {
            cout << node->val;
            newNodes.push_back(node->left);
            newNodes.push_back(node->right);
        } else {
            cout << " ";
            newNodes.push_back(nullptr);
            newNodes.push_back(nullptr);
        }
        printWhitespaces(betweenSpaces);
    }
    cout << endl;

    for (int i = 1; i <= edgeLines; i++) {
        for (size_t j = 0; j < nodes.size(); j++) {
            printWhitespaces(firstSpaces - i);
            if (nodes[j] == nullptr) {
                printWhitespaces(edgeLines + edgeLines + i + 1);
                continue;
            }

            if (nodes[j]->left != nullptr) {
                cout << "/";
            } else {
                printWhitespaces(1);
            }

            printWhitespaces(i + i - 1);

            if (nodes[j]->right != nullptr) {
                cout << "\\";
            } else {
                printWhitespaces(1);
            }

            printWhitespaces(edgeLines + edgeLines - i);
        }
        cout << endl;
    }

    printNodeInternal(newNodes, level + 1, maxLevel);
}

// Helper: Print whitespaces
void TreeUtils::printWhitespaces(int count) {
    for (int i = 0; i < count; i++) {
        cout << " ";
    }
}

// Helper: Find the maximum depth of the tree
template <typename T>
int TreeUtils::maxLevel(TreeNode<T>* node) {
    if (!node) return 0;
    return max(maxLevel(node->left), maxLevel(node->right)) + 1;
}

// Helper: Check if all elements in a vector are null
template <typename T>
bool TreeUtils::isAllElementsNull(const vector<TreeNode<T>*>& nodes) {
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
template TreeNode<int>* TreeUtils::vectorToTree(const vector<optional<int>>& values);
template string TreeUtils::toLevelOrderString(TreeNode<int>* root);
template void TreeUtils::printTree(TreeNode<int>* root);
template TreeNode<int>* TreeUtils::findNode(TreeNode<int>* root, int value);
template void TreeUtils::freeTree(TreeNode<int>* root);
