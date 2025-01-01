#pragma once

#include <vector>
#include <queue>
#include <optional>
#include <string>
#include <sstream>
#include "TreeNode.h"

class TreeUtils {
public:
    // Create a binary tree from a vector (level-by-level)
    template <typename T>
    static TreeNode<T>* vectorToTree(const std::vector<std::optional<T>>& values);

    // Convert the tree to a level-order string representation
    template <typename T>
    static std::string toLevelOrderString(TreeNode<T>* root);
};
