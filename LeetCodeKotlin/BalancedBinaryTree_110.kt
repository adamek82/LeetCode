class BalancedBinaryTree_110 {
    fun isBalanced(root: TreeNode?): Boolean {
        return checkHeight(root) != -1
    }

    private fun checkHeight(node: TreeNode?): Int {
        if (node == null) return 0

        val leftHeight = checkHeight(node.left)
        if (leftHeight == -1) return -1 // Left subtree not balanced

        val rightHeight = checkHeight(node.right)
        if (rightHeight == -1) return -1 // Right subtree not balanced

        if (kotlin.math.abs(leftHeight - rightHeight) > 1) {
            return -1 // Current node not balanced
        }

        return maxOf(leftHeight, rightHeight) + 1
    }
}