#pragma once
#include "TreeNode.h"

class PathSum_112 {
public:
    bool hasPathSum(TreeNode<int>* root, int targetSum);

private:
    // DFS helper: returns true if there is a root-to-leaf path in this subtree
    // whose values sum to remainingSum.
    bool dfs(TreeNode<int>* node, int remainingSum);
};
