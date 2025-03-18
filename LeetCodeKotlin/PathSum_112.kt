class PathSum_112 {
    fun hasPathSum(root: TreeNode?, targetSum: Int): Boolean {
        if (root == null) return false

        // Check if it's a leaf node and its value equals the remaining sum
        if (root.left == null && root.right == null)
            return root.value == targetSum

        // Recursively check left and right subtrees, reducing the targetSum by root value
        return hasPathSum(root.left, targetSum - root.value) ||
               hasPathSum(root.right, targetSum - root.value)
    }
}
