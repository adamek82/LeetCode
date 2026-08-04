#pragma once

#include <optional>
#include <string>
#include <vector>

namespace TestCases {

// 226. Invert Binary Tree
struct InvertBinaryTreeTestCase {
    std::vector<std::optional<int>> tree;
    std::vector<std::optional<int>> expected;
};
// 104. Maximum Depth of Binary Tree
struct MaximumDepthOfBinaryTreeTestCase {
    std::vector<std::optional<int>> tree;
    int expected;
};
// 100. Same Tree
struct SameTreeTestCase {
    std::vector<std::optional<int>> p;
    std::vector<std::optional<int>> q;
    bool expected;
};
// 101. Symmetric Tree
struct SymmetricTreeTestCase {
    std::vector<std::optional<int>> tree;
    bool expected;
};
// 112. Path Sum
struct PathSumTestCase {
    std::vector<std::optional<int>> tree;
    int target;
    bool expected;
};
// 110. Balanced Binary Tree
struct BalancedBinaryTreeTestCase {
    std::vector<std::optional<int>> tree;
    bool expected;
};
// 543. Diameter of Binary Tree
struct DiameterOfBinaryTreeTestCase {
    std::vector<std::optional<int>> tree;
    int expected;
};
// 572. Subtree of Another Tree
struct SubtreeOfAnotherTreeTestCase {
    std::vector<std::optional<int>> root;
    std::vector<std::optional<int>> subRoot;
    bool expected;
};

// 102. Binary Tree Level Order Traversal
struct BinaryTreeLevelOrderTraversalTestCase {
    std::vector<std::optional<int>> tree;
    std::vector<std::vector<int>> expected;
};

// 637. Average of Levels in Binary Tree
struct AverageOfLevelsInBinaryTreeTestCase {
    std::vector<std::optional<int>> tree;
    std::vector<double> expected;
};
// 230. Kth Smallest Element in a BST
struct KthSmallestElementInABSTTestCase {
    std::vector<std::optional<int>> tree;
    int k;
    int expected;
};
// 530. Minimum Absolute Difference in BST
struct MinimumAbsoluteDifferenceInBSTTestCase {
    std::vector<std::optional<int>> tree;
    int expected;
};
// 98. Validate Binary Search Tree
struct ValidateBinarySearchTreeTestCase {
    std::vector<std::optional<int>> tree;
    bool expected;
};
// 235. Lowest Common Ancestor of a BST
struct LowestCommonAncestorTestCase {
    std::vector<std::optional<int>> tree;
    int p;
    int q;
    int expected;
};
// 208. Implement Trie (Prefix Tree)
struct ImplementTrieTestCase {
    std::vector<std::string> operations;
    std::vector<std::optional<std::string>> arguments;
    std::vector<std::optional<bool>> expected;
};

} // namespace TestCases
