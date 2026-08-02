#pragma once

// Template definition for a binary tree node
template <typename T = int>
struct TreeNode {
    T val;            // Value stored in the node
    TreeNode* left;   // Pointer to the left child
    TreeNode* right;  // Pointer to the right child

    // Default constructor
    TreeNode() : val(T()), left(nullptr), right(nullptr) {}

    // Constructor with value
    TreeNode(T x) : val(x), left(nullptr), right(nullptr) {}

    // Constructor with value and left/right child pointers
    TreeNode(T x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};
