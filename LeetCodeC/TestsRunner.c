#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "FindIfPathExistsInGraph_1971.h"

// Define a structure for a test case
typedef struct {
    int n;
    int edgesSize;
    int **edges;
    int *edgesColSize;
    int source;
    int destination;
    bool expectedResult;
} PathTestCase;

// Helper function to allocate and initialize an edge (an array of 2 ints)
int* createEdge(int a, int b) {
    int* edge = (int*)malloc(2 * sizeof(int));
    edge[0] = a;
    edge[1] = b;
    return edge;
}

// Helper function to free the edges array for a test case
void freeEdges(int **edges, int edgesSize) {
    for (int i = 0; i < edgesSize; i++) {
        free(edges[i]);
    }
    free(edges);
}

// Test cases are statically allocated using C99 compound literals.
void runValidPathTests() {
    PathTestCase testCases[5] = {
        {
            .n = 3,
            .edgesSize = 3,
            .edges = (int*[]){
                (int[]){0, 1},
                (int[]){1, 2},
                (int[]){2, 0}
            },
            .edgesColSize = (int[]){2, 2, 2},
            .source = 0,
            .destination = 2,
            .expectedResult = true
        },
        {
            .n = 6,
            .edgesSize = 5,
            .edges = (int*[]){
                (int[]){0, 1},
                (int[]){0, 2},
                (int[]){3, 5},
                (int[]){5, 4},
                (int[]){4, 3}
            },
            .edgesColSize = (int[]){2, 2, 2, 2, 2},
            .source = 0,
            .destination = 5,
            .expectedResult = false
        },
        {
            .n = 4,
            .edgesSize = 3,
            .edges = (int*[]){
                (int[]){0, 1},
                (int[]){1, 2},
                (int[]){2, 3}
            },
            .edgesColSize = (int[]){2, 2, 2},
            .source = 0,
            .destination = 3,
            .expectedResult = true
        },
        {
            .n = 5,
            .edgesSize = 4,
            .edges = (int*[]){
                (int[]){0, 4},
                (int[]){4, 3},
                (int[]){3, 2},
                (int[]){2, 1}
            },
            .edgesColSize = (int[]){2, 2, 2, 2},
            .source = 0,
            .destination = 1,
            .expectedResult = true
        },
        {
            .n = 4,
            .edgesSize = 2,
            .edges = (int*[]){
                (int[]){0, 1},
                (int[]){1, 2}
            },
            .edgesColSize = (int[]){2, 2},
            .source = 0,
            .destination = 3,
            .expectedResult = false
        }
    };

    // Run each test case and print results for both solutions
    for (int i = 0; i < 5; i++) {
        bool resultOriginal = validPath(testCases[i].n,
                                        testCases[i].edges,
                                        testCases[i].edgesSize,
                                        testCases[i].edgesColSize,
                                        testCases[i].source,
                                        testCases[i].destination);
        bool resultOptimized = validPathOptimized(testCases[i].n,
                                                  testCases[i].edges,
                                                  testCases[i].edgesSize,
                                                  testCases[i].edgesColSize,
                                                  testCases[i].source,
                                                  testCases[i].destination);
        printf("Test %d: Original = %s, Optimized = %s\n", i + 1,
               (resultOriginal == testCases[i].expectedResult) ? "PASS" : "FAIL",
               (resultOptimized == testCases[i].expectedResult) ? "PASS" : "FAIL");
    }
}

int main(void)
{
	printf("Running LeetCodeC tests:\n");
	printf("Running FindIfPathExistsInGraph tests (both original and optimized):\n");
	runValidPathTests();
	return 0;
}