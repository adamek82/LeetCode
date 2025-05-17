#pragma once
#include "TreeNode.h"

using namespace std;

class KthSmallestElementInBST_230 {
public:
    int kthSmallest(TreeNode<int>* root, int k);
private:
    int count;   // Countdown to track the remaining nodes to visit
    int result;  // To store the kth smallest element
    void inOrderTraversal(TreeNode<int>* node);
};
