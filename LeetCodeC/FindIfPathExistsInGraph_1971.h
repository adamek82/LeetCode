#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

bool recursive_dfs(int node, int destination, int** graph, int* graphSizes, int* visited);
bool validPath(int n, int** edges, int edgesSize, int* edgesColSize, int source, int destination);