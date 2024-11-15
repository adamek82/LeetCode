class FindIfPathExistsInGraph_1971 {
    validPath(n, edges, source, destination) {
        if (source === destination) return true;

        // Create adjacency list
        const graph = Array.from({ length: n }, () => []);
        for (const [u, v] of edges) {
            graph[u].push(v);
            graph[v].push(u);
        }

        // Use an array to mark visited nodes
        const visited = Array(n).fill(false);
        visited[source] = true;

        return this.dfs(source, destination, graph, visited);
    }

    dfs(node, destination, graph, visited) {
        if (node === destination) return true;

        for (const neighbor of graph[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                if (this.dfs(neighbor, destination, graph, visited)) return true;
            }
        }

        return false;
    }
}

module.exports = FindIfPathExistsInGraph_1971;
