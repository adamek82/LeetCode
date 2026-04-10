class AllOOneDataStructure_432 {

    private class Node(val count: Int) {
        val keys: MutableSet<String> = mutableSetOf()
        var prev: Node? = null
        var next: Node? = null
    }

    private val head = Node(Int.MIN_VALUE)
    private val tail = Node(Int.MAX_VALUE)
    private val keyToNode = mutableMapOf<String, Node>()

    init {
        head.next = tail
        tail.prev = head
    }

    fun inc(key: String) {
        if (key !in keyToNode) {
            var firstNode = head.next!!
            if (firstNode == tail || firstNode.count != 1) {
                firstNode = Node(1)
                insertNodeAfter(head, firstNode)
            }
            firstNode.keys.add(key)
            keyToNode[key] = firstNode
            return
        }

        val curNode = keyToNode[key]!!
        val newCount = curNode.count + 1
        curNode.keys.remove(key)

        var nextNode = curNode.next!!
        if (nextNode == tail || nextNode.count != newCount) {
            nextNode = Node(newCount)
            insertNodeAfter(curNode, nextNode)
        }

        nextNode.keys.add(key)
        keyToNode[key] = nextNode

        if (curNode.keys.isEmpty()) {
            removeNode(curNode)
        }
    }

    fun dec(key: String) {
        val curNode = keyToNode[key]!!
        val newCount = curNode.count - 1
        curNode.keys.remove(key)

        if (newCount == 0) {
            keyToNode.remove(key)
        } else {
            var prevNode = curNode.prev!!
            if (prevNode == head || prevNode.count != newCount) {
                val newNode = Node(newCount)
                insertNodeAfter(prevNode, newNode)
                prevNode = newNode
            }

            prevNode.keys.add(key)
            keyToNode[key] = prevNode
        }

        if (curNode.keys.isEmpty()) {
            removeNode(curNode)
        }
    }

    fun getMaxKey(): String {
        val maxNode = tail.prev!!
        return if (maxNode == head) "" else maxNode.keys.first()
    }

    fun getMinKey(): String {
        val minNode = head.next!!
        return if (minNode == tail) "" else minNode.keys.first()
    }

    private fun insertNodeAfter(prevNode: Node, newNode: Node) {
        newNode.prev = prevNode
        newNode.next = prevNode.next
        prevNode.next!!.prev = newNode
        prevNode.next = newNode
    }

    private fun removeNode(node: Node) {
        node.prev!!.next = node.next
        node.next!!.prev = node.prev
    }
}
