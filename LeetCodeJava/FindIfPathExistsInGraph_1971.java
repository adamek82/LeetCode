import java.util.ArrayList;
import java.util.List;

public class FindIfPathExistsInGraph_1971 {
    public boolean validPath(int n, int[][] edges, int source, int destination) {
        if (source == destination) return true;

        // Create an adjacency list using a list of lists
        List<List<Integer>> graph = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            graph.add(new ArrayList<>());
        }
        for (int[] edge : edges) {
            graph.get(edge[0]).add(edge[1]);
            graph.get(edge[1]).add(edge[0]);
        }

        // Use an array to mark visited nodes
        boolean[] visited = new boolean[n];
        visited[source] = true;

        return dfs(source, destination, graph, visited);
    }

    private boolean dfs(int node, int destination, List<List<Integer>> graph, boolean[] visited) {
        if (node == destination) return true;

        for (int neighbor : graph.get(node)) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                if (dfs(neighbor, destination, graph, visited)) return true;
            }
        }
        return false;
    }
}
