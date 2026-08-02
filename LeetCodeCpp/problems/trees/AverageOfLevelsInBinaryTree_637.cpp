#include "AverageOfLevelsInBinaryTree_637.h"
#include <queue>

using namespace std;

/*
 * Average of Levels in Binary Tree (LeetCode 637)
 * ----------------------------------------------
 * We need the average value of nodes on each level.
 *
 * Approach — BFS (level-order traversal):
 * - Use a queue starting from `root`.
 * - For each level, take the current queue size as `levelSize`.
 * - Pop exactly `levelSize` nodes, accumulate their values in a 64-bit sum,
 *   and enqueue their non-null children.
 * - Push `sum / levelSize` into the result as a double.
 *
 * Using a 64-bit accumulator avoids overflow when summing many int values.
 *
 * Complexity:
 * - Time:  O(n), each node is enqueued and dequeued once.
 * - Space: O(w), where w is the maximum width of the tree (queue size).
 */
vector<double> AverageOfLevelsInBinaryTree_637::averageOfLevels(TreeNode<int>* root) {
    vector<double> result;
    if (!root) return result;

    queue<TreeNode<int>*> q;
    q.push(root);

    while (!q.empty()) {
        int levelSize = static_cast<int>(q.size());
        long long sum = 0;  // 64-bit to avoid overflow

        for (int i = 0; i < levelSize; ++i) {
            TreeNode<int>* node = q.front();
            q.pop();

            sum += node->val;
            if (node->left)  q.push(node->left);
            if (node->right) q.push(node->right);
        }

        result.push_back(static_cast<double>(sum) / levelSize);
    }

    return result;
}
