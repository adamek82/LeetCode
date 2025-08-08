#pragma once
#include <queue>
#include <stack>
#include "TreeNode.h"

using namespace std;

class SameTree_100 {
public:
    // 1. Classic recursive DFS
    bool isSameTreeRecursive(TreeNode<int>* p, TreeNode<int>* q);

    // 2. Iterative DFS with an explicit stack
    bool isSameTreeIterativeDFS(TreeNode<int>* p, TreeNode<int>* q);

    // 3. Iterative BFS level-order with a queue
    bool isSameTreeBFSQueue(TreeNode<int>* p, TreeNode<int>* q);
};
