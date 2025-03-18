class DiameterOfBinaryTree_543 {
    fun diameterOfBinaryTree(root: TreeNode?): Int {
        var diameter = 0

        fun depth(node: TreeNode?): Int {
            if (node == null) return 0

            val leftDepth = depth(node.left)
            val rightDepth = depth(node.right)

            diameter = maxOf(diameter, leftDepth + rightDepth)

            return maxOf(leftDepth, rightDepth) + 1
        }

        depth(root)
        return diameter
    }
}