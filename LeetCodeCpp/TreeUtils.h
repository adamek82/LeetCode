#pragma once
#include "TreeNode.h"
#include <vector>
#include <optional>
#include <string>

using namespace std;

class TreeUtils {
public:
    // Create a binary tree from a vector (level-by-level)
    template <typename T>
    static TreeNode<T>* vectorToTree(const vector<optional<T>>& values);

    // Convert the tree to a level-order string representation
    template <typename T>
    static string toLevelOrderString(TreeNode<T>* root);

    // Print the tree in a visually formatted style (similar to BTreePrinter)
    template <typename T>
    static void printTree(TreeNode<T>* root);

    // Find a node in the tree by its value
    template <typename T>
    static TreeNode<T>* findNode(TreeNode<T>* root, T value);

    // Free the binary tree memory
    template <typename T>
    static void freeTree(TreeNode<T>* root);

private:
    // Helper methods for tree printing
    template <typename T>
    static void printNodeInternal(const vector<TreeNode<T>*>& nodes, int level, int maxLevel);

    static void printWhitespaces(int count);

    template <typename T>
    static int maxLevel(TreeNode<T>* node);

    template <typename T>
    static bool isAllElementsNull(const vector<TreeNode<T>*>& nodes);
};
