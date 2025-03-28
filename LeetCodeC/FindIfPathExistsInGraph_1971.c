#include "FindIfPathExistsInGraph_1971.h"

// Helper function for the recursive DFS
bool recursive_dfs(int node, int destination, int** graph, int* graphSizes, int* visited) {
    if (node == destination) return true;

    for (int i = 0; i < graphSizes[node]; i++) {
        int neighbor = graph[node][i];
        if (!visited[neighbor]) {
            visited[neighbor] = 1;
            if (recursive_dfs(neighbor, destination, graph, graphSizes, visited)) return true;
        }
    }
    return false;
}

bool validPath(int n, int** edges, int edgesSize, int* edgesColSize, int source, int destination) {
    if (source == destination) return true;

    // Create an adjacency list
    int** graph = (int**)malloc(n * sizeof(int*)); // Array of pointers for adjacency list
    int* graphSizes = (int*)calloc(n, sizeof(int)); // Track the size of each adjacency list

    // Allocate space for adjacency lists
    for (int i = 0; i < n; i++) {
        graph[i] = NULL;
    }

    // Build the adjacency list
    for (int i = 0; i < edgesSize; i++) {
        int u = edges[i][0];
        int v = edges[i][1];

        // Add v to u's list
        graph[u] = (int*)realloc(graph[u], (graphSizes[u] + 1) * sizeof(int));
        graph[u][graphSizes[u]++] = v;

        // Add u to v's list
        graph[v] = (int*)realloc(graph[v], (graphSizes[v] + 1) * sizeof(int));
        graph[v][graphSizes[v]++] = u;
    }

    // Initialize visited array
    int* visited = (int*)calloc(n, sizeof(int));
    visited[source] = 1;

    // Perform recursive DFS
    bool result = recursive_dfs(source, destination, graph, graphSizes, visited);

    // Free allocated memory
    for (int i = 0; i < n; i++) {
        free(graph[i]);
    }
    free(graph);
    free(graphSizes);
    free(visited);

    return result;
}