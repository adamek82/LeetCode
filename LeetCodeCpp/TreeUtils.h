#pragma once

#include <vector>
#include <queue>
#include <optional>
#include <string>
#include <iostream>
#include <sstream>
#include <cmath>
#include <iomanip>
#include "TreeNode.h"

class TreeUtils {
public:
    // Create a binary tree from a vector (level-by-level)
    template <typename T>
    static TreeNode<T>* vectorToTree(const std::vector<std::optional<T>>& values);

    // Convert the tree to a level-order string representation
    template <typename T>
    static std::string toLevelOrderString(TreeNode<T>* root);

    // Print the tree in a visually formatted style (similar to BTreePrinter)
    template <typename T>
    static void printTree(TreeNode<T>* root);

    // Free the binary tree memory
    template <typename T>
    static void freeTree(TreeNode<T>* root);

private:
    // Helper methods for tree printing
    template <typename T>
    static void printNodeInternal(const std::vector<TreeNode<T>*>& nodes, int level, int maxLevel);

    static void printWhitespaces(int count);

    template <typename T>
    static int maxLevel(TreeNode<T>* node);

    template <typename T>
    static bool isAllElementsNull(const std::vector<TreeNode<T>*>& nodes);
};
