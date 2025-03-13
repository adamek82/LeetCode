class InvertBinaryTree_226 {
    fun invertTree(root: TreeNode?): TreeNode? {
        if (root == null) return null

        // Swap left and right subtrees
        val temp = root.left
        root.left = invertTree(root.right)
        root.right = invertTree(temp)

        return root
    }
}