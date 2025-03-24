class LowestCommonAncestorOfBinarySearchTree_235 {
    fun lowestCommonAncestor(root: TreeNode?, p: TreeNode?, q: TreeNode?): TreeNode? {
        if (p == null || q == null) return null
        
        var current = root
        
        while (current != null) {
            val value = current.value
            if (p.value < value && q.value < value) {
                // Both p and q lie in the left subtree
                current = current.left
            } else if (p.value > value && q.value > value) {
                // Both p and q lie in the right subtree
                current = current.right
            } else {
                // We've found a split or exact match -> current is the LCA
                return current
            }
        }
        
        return null
    }
}