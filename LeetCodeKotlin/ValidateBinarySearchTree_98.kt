class ValidateBinarySearchTree_98 {
    fun isValidBST(root: TreeNode?): Boolean {
        return validate(root, Long.MIN_VALUE, Long.MAX_VALUE)
    }

    private fun validate(node: TreeNode?, minVal: Long, maxVal: Long): Boolean {
        if (node == null) return true
        if (node.value <= minVal || node.value >= maxVal) return false

        // Recur for left and right subtrees, updating boundaries
        return validate(node.left, minVal, node.value.toLong()) &&
               validate(node.right, node.value.toLong(), maxVal)
    }
}