class MinimumAbsoluteDifferenceInBST_530 {
    private var prevValue: Int? = null
    private var minDiff = Int.MAX_VALUE

    fun getMinimumDifference(root: TreeNode?): Int {
        prevValue = null
        minDiff = Int.MAX_VALUE
        inorder(root)
        return minDiff
    }

    private fun inorder(node: TreeNode?) {
        if (node == null) return

        // Traverse left
        inorder(node.left)

        // "Visit" current node
        if (prevValue != null) {
            val currentDiff = node.value - prevValue!!
            if (currentDiff < minDiff) {
                minDiff = currentDiff
            }
        }
        prevValue = node.value

        // Traverse right
        inorder(node.right)
    }
}