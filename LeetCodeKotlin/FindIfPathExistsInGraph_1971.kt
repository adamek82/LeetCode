class FindIfPathExistsInGraph_1971 {
    private fun recursiveDfs(node: Int, destination: Int, graph: Array<MutableList<Int>>, visited: BooleanArray): Boolean {
        if (node == destination) return true
        
        for (neighbor in graph[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true
                if (recursiveDfs(neighbor, destination, graph, visited)) return true
            }
        }
        return false
    }

    fun validPath(n: Int, edges: Array<IntArray>, source: Int, destination: Int): Boolean {
        if (source == destination) return true
        
        val graph = Array(n) { mutableListOf<Int>() }
        for (edge in edges) {
            graph[edge[0]].add(edge[1])
            graph[edge[1]].add(edge[0])
        }
        
        val visited = BooleanArray(n)
        visited[source] = true
        
        return recursiveDfs(source, destination, graph, visited)
    }
}