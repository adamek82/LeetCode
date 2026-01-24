#pragma once
#include "TreeNode.h"

using namespace std;

class MaximumDepthOfBinaryTree_104 {
public:
    // 1. Classic recursive DFS
    int maxDepthRecursive(TreeNode<int>* root);

    // 2. Iterative DFS using an explicit stack
    int maxDepthDFSStack(TreeNode<int>* root);

    // 3. Iterative BFS level-order using a queue
    int maxDepthBFSQueue(TreeNode<int>* root);
};
