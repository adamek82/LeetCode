class BinaryTreeLevelOrderTraversal_102 {
    fun levelOrder(root: TreeNode?): List<List<Int>> {
        val result = mutableListOf<List<Int>>()
        if (root == null) return result

        val queue: ArrayDeque<TreeNode> = ArrayDeque()
        queue.add(root)

        while (queue.isNotEmpty()) {
            val levelSize = queue.size
            val currentLevel = mutableListOf<Int>()

            repeat(levelSize) {
                val node = queue.removeFirst()
                currentLevel.add(node.value)

                node.left?.let { queue.add(it) }
                node.right?.let { queue.add(it) }
            }
            result.add(currentLevel)
        }

        return result
    }
}