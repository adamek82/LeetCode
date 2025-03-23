class KthSmallestElementInBST_230 {
    fun kthSmallest(root: TreeNode?, k: Int): Int {
        // We'll do an iterative inorder traversal
        val stack = ArrayDeque<TreeNode>()
        var current = root
        var count = 0

        while (true) {
            // 1) Push all the left children onto the stack
            while (current != null) {
                stack.addLast(current)
                current = current.left
            }

            // 2) Pop from stack, this is the next smallest node
            val node = stack.removeLast()
            count++
            if (count == k) {
                // The k-th node visited is our result
                return node.value
            }

            // 3) Move to the right subtree of the popped node
            current = node.right
        }
    }
}