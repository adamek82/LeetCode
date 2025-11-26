#include "BinaryTreeLevelOrderTraversal_102.h"
#include <queue>

using namespace std;

/*
 * Binary Tree Level Order Traversal (LeetCode 102)
 * ------------------------------------------------
 * We need to return node values level by level from left to right.
 *
 * Approach — BFS (level-order traversal):
 * - Use a queue starting from `root`.
 * - For each level, record the number of nodes currently in the queue.
 * - Pop exactly that many nodes, push their values into a single vector,
 *   and enqueue their non-null children.
 * - Append that vector to the result and continue until the queue is empty.
 *
 * Complexity:
 * - Time:  O(n), each node is enqueued and dequeued once.
 * - Space: O(w), where w is the maximum width of the tree (queue size).
 */
vector<vector<int>> BinaryTreeLevelOrderTraversal_102::levelOrder(TreeNode<int>* root) {
    vector<vector<int>> result;
    if (!root) return result;

    queue<TreeNode<int>*> q;
    q.push(root);

    while (!q.empty()) {
        int levelSize = static_cast<int>(q.size());
        vector<int> level;
        level.reserve(levelSize);

        while (levelSize--) {
            TreeNode<int>* node = q.front();
            q.pop();

            level.push_back(node->val);
            if (node->left)  q.push(node->left);
            if (node->right) q.push(node->right);
        }

        result.push_back(move(level));
    }

    return result;
}
