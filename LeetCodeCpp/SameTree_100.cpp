#include "SameTree_100.h"

/* 1. Recursive ---------------------------------------------------------------- */
bool SameTree_100::isSameTreeRecursive(TreeNode<int>* p, TreeNode<int>* q)
{
    if (!p && !q) return true;

    if (!p || !q) return false;

    return p->val == q->val &&
           isSameTreeRecursive(p->left,  q->left) &&
           isSameTreeRecursive(p->right, q->right);
}

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
