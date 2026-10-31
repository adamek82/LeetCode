#pragma once

#include "common/TreeNode.h"

class PathSum_112 {
public:
    bool hasPathSum(TreeNode<int>* root, int targetSum);

private:
    bool dfs(TreeNode<int>* node, int remainingSum);
};
