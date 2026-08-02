#include "SymmetricTree_101.h"
#include <queue>

using namespace std;

/*
 * Symmetric Tree (LeetCode 101)
 * -----------------------------
 * A tree is symmetric if the left and right subtree are mirror images:
 * - root values match, and
 * - left->left mirrors right->right, left->right mirrors right->left.
 *
 * 1) Recursive mirror check:
 *    - Compare node pairs (l, r):
 *        • both null      -> symmetric at this level,
 *        • one null       -> not symmetric,
 *        • values differ  -> not symmetric,
 *        • otherwise recursively check (l->left, r->right) and
 *          (l->right, r->left).
 *
 * 2) Iterative BFS with a queue of pairs:
 *    - Start from (root->left, root->right).
 *    - Pop (l, r) and apply the same mirror conditions as above.
 *    - Push children in mirrored order:
 *        (l->left,  r->right) and
 *        (l->right, r->left).
 *
 * Complexity:
 * - Time:  O(n) for both variants, each node participates in exactly one pair.
 * - Space: O(h) recursion stack for the recursive solution, O(w) queue for the
 *          iterative one, where h is tree height and w is maximum tree width.
 */

bool SymmetricTree_101::isSymmetricRecursive(TreeNode<int>* root) {
    if (!root) return true;
    return isMirror(root->left, root->right);
}

bool SymmetricTree_101::isMirror(TreeNode<int>* left, TreeNode<int>* right) {
    if (!left && !right) return true;
    if (!left || !right) return false;
    if (left->val != right->val) return false;

    return isMirror(left->left,  right->right) &&
           isMirror(left->right, right->left);
}

/*
 * Iterative mirror check (BFS with queue of node pairs):
 * - Maintains the same invariants as the recursive solution but uses an
 *   explicit queue instead of the call stack.
 */
bool SymmetricTree_101::isSymmetricIterative(TreeNode<int>* root) {
    if (!root) return true;

    queue<pair<TreeNode<int>*, TreeNode<int>*>> q;
    q.emplace(root->left, root->right);

    while (!q.empty()) {
        auto [l, r] = q.front();
        q.pop();

        if (!l && !r) continue;
        if (!l || !r) return false;
        if (l->val != r->val) return false;

        q.emplace(l->left,  r->right);
        q.emplace(l->right, r->left);
    }

    return true;
}
