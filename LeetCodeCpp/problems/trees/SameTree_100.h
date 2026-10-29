#pragma once

#include "common/TreeNode.h"

class SameTree_100 {
public:
    bool isSameTreeRecursive(TreeNode<int>* p, TreeNode<int>* q);
    bool isSameTreeIterativeDFS(TreeNode<int>* p, TreeNode<int>* q);
    bool isSameTreeBFSQueue(TreeNode<int>* p, TreeNode<int>* q);
};
