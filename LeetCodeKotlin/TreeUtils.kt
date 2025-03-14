class TreeUtils {
    companion object {
        @JvmStatic
        fun isSameTree(p: TreeNode?, q: TreeNode?): Boolean {
            if (p == null && q == null) return true
            if (p == null || q == null || p.value != q.value) return false
            return isSameTree(p.left, q.left) && isSameTree(p.right, q.right)
        }

        @JvmStatic
        fun vectorToTree(values: List<Int?>): TreeNode? {
            // If the list is empty or the first element is null, no tree can be formed
            if (values.isEmpty() || values[0] == null) return null
        
            val root = TreeNode(values[0]!!)
            val queue = ArrayDeque<TreeNode>()
            queue.addLast(root)
        
            var i = 1
            while (i < values.size) {
                val current = queue.removeFirst()
        
                // Assign left child if not null
                if (i < values.size && values[i] != null) {
                    val leftNode = TreeNode(values[i]!!)
                    current.left = leftNode
                    queue.addLast(leftNode)
                }
                i++
        
                // Assign right child if not null
                if (i < values.size && values[i] != null) {
                    val rightNode = TreeNode(values[i]!!)
                    current.right = rightNode
                    queue.addLast(rightNode)
                }
                i++
            }
        
            return root
        }
    }
}