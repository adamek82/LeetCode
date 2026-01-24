#include "SameTree_100.h"
#include <queue>
#include <stack>
#include <utility>

/* Implementation notes (alternatives discussed)
 * ------------------------------------------------
 * • Iterative DFS:
 *     - Current code uses a single stack of pairs: stack<pair<TreeNode<int>*, TreeNode<int>*>>
 *     - An equivalent variant uses TWO stacks (one per tree). If you choose that,
 *       you must push children in the SAME order on both stacks (e.g., right then left)
 *       to avoid desynchronization.
 *
 * • Iterative BFS:
 *     - Current code uses TWO queues (one per tree).
 *     - An equivalent variant uses a single queue of pairs: queue<pair<TreeNode<int>*, TreeNode<int>*>>
 *       which is often a bit cleaner and removes any risk of the queues getting out of sync.
 * In all variants, time complexity is Θ(n). Space is Θ(h) for DFS and up to Θ(n) for BFS.
 */

/* 1. Recursive ---------------------------------------------------------------- */
bool SameTree_100::isSameTreeRecursive(TreeNode<int>* p, TreeNode<int>* q)
{
    if (!p && !q) return true;

    if (!p || !q) return false;

    return p->val == q->val &&
           isSameTreeRecursive(p->left,  q->left) &&
           isSameTreeRecursive(p->right, q->right);
}

/*
 * NOTE on iterative DFS variants:
 *
 * Besides the stack-of-pairs approach below, a two-stacks version (stack<TreeNode<int>*> sp, sq)
 * is equivalent. The critical invariant is to push corresponding children in IDENTICAL order
 * on both stacks (e.g., push right then left on both). If the order diverges, the stacks can
 * become misaligned, producing false mismatches.
 */

/* 2. Iterative DFS (stack) ---------------------------------------------------- */
bool SameTree_100::isSameTreeIterativeDFS(TreeNode<int>* p, TreeNode<int>* q)
{
    stack<pair<TreeNode<int>*, TreeNode<int>*>> st;
    st.emplace(p, q);

    while (!st.empty()) {
        auto [n1, n2] = st.top();
        st.pop();

        if (!n1 || !n2) {
            if (n1 != n2) return false;   // exactly one is null
            continue;                     // both null – nothing to compare
        }
        if (n1->val != n2->val) return false;

        st.emplace(n1->right, n2->right);
        st.emplace(n1->left,  n2->left);
    }
    return true;
}

/*
 * NOTE on iterative BFS variants:
 *
 * We currently keep TWO queues (one per tree). A single queue of pairs
 * (queue<pair<TreeNode<int>*, TreeNode<int>*>>) is an equivalent drop-in approach
 * that tends to be more compact and eliminates any chance of queue desynchronization.
 * Both forms have identical asymptotic complexity.
 */

/* 3. Iterative BFS (queue) ---------------------------------------------------- */
bool SameTree_100::isSameTreeBFSQueue(TreeNode<int>* p, TreeNode<int>* q)
{
    queue<TreeNode<int>*> qp, qq;
    qp.push(p);
    qq.push(q);

    while (!qp.empty()) {
        auto n1 = qp.front(); qp.pop();
        auto n2 = qq.front(); qq.pop();

        if (!n1 || !n2) {
            if (n1 != n2) return false;   // one null, one not
            continue;                     // both null
        }
        if (n1->val != n2->val) return false;

        qp.push(n1->left);   qq.push(n2->left);
        qp.push(n1->right);  qq.push(n2->right);
    }
    return true;
}
