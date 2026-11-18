#include "KthSmallestElementInBST_230.h"

#include <stack>
#include <utility>

using namespace std;

int KthSmallestElementInBST_230::kthSmallestRecursive(TreeNode<int>* root, int k)
{
    int answer = -1;
    inorderTraversal(root, k, answer);
    return answer;
}

bool KthSmallestElementInBST_230::inorderTraversal(TreeNode<int>* node, int& k, int& answer)
{
    if (node == nullptr) {
        return false;
    }

    if (inorderTraversal(node->left, k, answer)) {
        return true;
    }

    if (--k == 0) {
        answer = node->val;
        return true;
    }

    return inorderTraversal(node->right, k, answer);
}

int KthSmallestElementInBST_230::kthSmallestIterative(TreeNode<int>* root, int k)
{
    stack<TreeNode<int>*> nodes;
    TreeNode<int>* node = root;

    while (node != nullptr || !nodes.empty()) {
        while (node != nullptr) {
            nodes.push(node);
            node = node->left;
        }

        node = nodes.top();
        nodes.pop();

        if (--k == 0) {
            return node->val;
        }

        node = node->right;
    }

    // The problem guarantees 1 <= k <= the number of nodes.
    unreachable();
}
