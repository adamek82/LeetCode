#include "MaximumDepthOfBinaryTree_104.h"
#include <queue>
#include <stack>
#include <utility>

/*
 * Recursive DFS:
 * - Base case: a null node has depth 0.
 * - Otherwise the depth is 1 plus the maximum depth of the left and right subtree.
 * This directly mirrors the definition of the height of a binary tree.
 *
 * Complexity:
 * - Time:  O(n), each node is visited exactly once.
 * - Space: O(h) for the recursion stack, where h is the tree height
 *          (O(n) worst case for a skewed tree, O(log n) for a balanced tree).
 */
int MaximumDepthOfBinaryTree_104::maxDepthRecursive(TreeNode<int> *root)
{
    if (!root) return 0;
    return 1 + max(maxDepthRecursive(root->left),
                   maxDepthRecursive(root->right));
}

/*
 * Iterative DFS with an explicit stack:
 * - Store (node, depth) pairs on the stack, starting from (root, 1).
 * - Pop a node, update the best depth, then push its non-null children with depth + 1.
 * This simulates the recursive DFS but avoids using the call stack directly.
 *
 * Complexity:
 * - Time:  O(n), each node is pushed and popped at most once.
 * - Space: O(h) in the worst case, where h is the tree height
 *          (stack can hold up to all nodes on a root-to-leaf path).
 */
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

/*
 * BFS (level-order traversal):
 * - Use a queue and process the tree level by level.
 * - For each level, pop all nodes currently in the queue and push their children.
 * - The number of levels processed is exactly the maximum depth of the tree.
 *
 * Complexity:
 * - Time:  O(n), every node is enqueued and dequeued once.
 * - Space: O(w), where w is the maximum width of the tree
 *          (O(n) in the worst case when the last level is full).
 */
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
