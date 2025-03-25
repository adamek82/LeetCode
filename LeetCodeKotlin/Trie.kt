class Trie {

    // Each TrieNode holds 26 children pointers (for a-z) and a flag indicating if this node marks the end of a word
    class TrieNode {
        val children = Array<TrieNode?>(26) { null }
        var isEndOfWord: Boolean = false
    }

    private val root = TrieNode()

    fun insert(word: String) {
        var current = root
        for (ch in word) {
            val index = ch - 'a'
            if (current.children[index] == null) {
                current.children[index] = TrieNode()
            }
            current = current.children[index]!!
        }
        current.isEndOfWord = true
    }

    fun search(word: String): Boolean {
        val node = findNode(word)
        return node != null && node.isEndOfWord
    }

    fun startsWith(prefix: String): Boolean {
        return findNode(prefix) != null
    }

    // Helper function that traverses down the Trie according to the given string.
    // Returns the node corresponding to the last character if found, otherwise null.
    private fun findNode(str: String): TrieNode? {
        var current = root
        for (ch in str) {
            val index = ch - 'a'
            if (current.children[index] == null) {
                return null
            }
            current = current.children[index]!!
        }
        return current
    }
}