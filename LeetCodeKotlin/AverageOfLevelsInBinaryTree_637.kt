class AverageOfLevelsInBinaryTree_637 {
    fun averageOfLevels(root: TreeNode?): DoubleArray {
        if (root == null) return DoubleArray(0)

        val result = mutableListOf<Double>()
        val queue = ArrayDeque<TreeNode>()
        queue.addLast(root)

        while (queue.isNotEmpty()) {
            val levelSize = queue.size
            var levelSum = 0L  // Use Long to avoid potential overflow when summing

            repeat(levelSize) {
                val currentNode = queue.removeFirst()
                levelSum += currentNode.value

                currentNode.left?.let { queue.addLast(it) }
                currentNode.right?.let { queue.addLast(it) }
            }

            result.add(levelSum.toDouble() / levelSize)
        }

        return result.toDoubleArray()
    }
}