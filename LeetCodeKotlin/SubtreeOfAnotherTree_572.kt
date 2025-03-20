class SubtreeOfAnotherTree_572 {
        fun isSubtree(root: TreeNode?, subRoot: TreeNode?): Boolean {
        if (root == null) return false
        if (isSameTree(root, subRoot)) return true
        return isSubtree(root.left, subRoot) || isSubtree(root.right, subRoot)
    }

    private fun isSameTree(p: TreeNode?, q: TreeNode?): Boolean {
        if (p == null && q == null) return true
        if (p == null || q == null || p.value != q.value) return false
        return isSameTree(p.left, q.left) && isSameTree(p.right, q.right)
    }
}