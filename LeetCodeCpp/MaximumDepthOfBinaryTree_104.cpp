#include "MaximumDepthOfBinaryTree_104.h"

int MaximumDepthOfBinaryTree_104::maxDepthRecursive(TreeNode<int> *root)
{
    if (!root) return 0;
    return 1 + max(maxDepthRecursive(root->left),
                   maxDepthRecursive(root->right));
}

int MaximumDepthOfBinaryTree_104::maxDepthDFSStack(TreeNode<int> *root)
{
    if (!root) return 0;

    stack<pair<TreeNode<int>*, int>> st;
    st.emplace(root, 1);
    int result = 0;

    while (!st.empty()) {
        auto [node, depth] = st.top();
        st.pop();
        result = max(result, depth);

        if (node->left)  st.emplace(node->left,  depth + 1);
        if (node->right) st.emplace(node->right, depth + 1);
    }
    return result;
}

int MaximumDepthOfBinaryTree_104::maxDepthBFSQueue(TreeNode<int> *root)
{
    if (!root) return 0;

    queue<TreeNode<int>*> q;
    q.push(root);
    int depth = 0;

    while (!q.empty()) {
        int levelSize = static_cast<int>(q.size());
        while (levelSize--) {
            TreeNode<int>* node = q.front();
            q.pop();
            if (node->left)  q.push(node->left);
            if (node->right) q.push(node->right);
        }
        ++depth;  // finished processing one level
    }
    return depth;
}
