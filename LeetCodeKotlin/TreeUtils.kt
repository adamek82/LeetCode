class TreeUtils {
    companion object {
        @JvmStatic
        fun isSameTree(p: TreeNode?, q: TreeNode?): Boolean {
            if (p == null && q == null) return true
            if (p == null || q == null || p.value != q.value) return false
            return isSameTree(p.left, q.left) && isSameTree(p.right, q.right)
        }
    }
}