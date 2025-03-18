class SymmetricTree_101 {
    fun isSymmetric(root: TreeNode?): Boolean {
        return isMirror(root?.left, root?.right)
    }

    private fun isMirror(left: TreeNode?, right: TreeNode?): Boolean {
        if (left == null && right == null) return true
        if (left == null || right == null) return false
        if (left.value != right.value) return false

        return isMirror(left.left, right.right) && isMirror(left.right, right.left)
    }
}