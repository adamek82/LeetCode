#include "SymmetricTree_101.h"

#include <queue>
#include <utility>

using namespace std;

bool SymmetricTree_101::isSymmetricRecursive(TreeNode<int>* root)
{
    if (!root) {
        return true;
    }

    return isMirror(root->left, root->right);
}

bool SymmetricTree_101::isMirror(TreeNode<int>* left, TreeNode<int>* right)
{
    if (!left && !right) {
        return true;
    }

    if (!left || !right) {
        return false;
    }

    if (left->val != right->val) {
        return false;
    }

    return isMirror(left->left, right->right) &&
           isMirror(left->right, right->left);
}

bool SymmetricTree_101::isSymmetricIterative(TreeNode<int>* root)
{
    if (!root) {
        return true;
    }

    queue<pair<TreeNode<int>*, TreeNode<int>*>> q;
    q.emplace(root->left, root->right);

    while (!q.empty()) {
        const auto [l, r] = q.front();
        q.pop();

        if (!l && !r) {
            continue;
        }

        if (!l || !r) {
            return false;
        }

        if (l->val != r->val) {
            return false;
        }

        q.emplace(l->left, r->right);
        q.emplace(l->right, r->left);
    }

    return true;
}
