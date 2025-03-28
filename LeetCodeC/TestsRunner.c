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

void runValidPathTests() {
    // We will create 5 test cases as in our C++ tests
    int numTests = 5;
    PathTestCase testCases[5];

    // Test case 1: 3 nodes; edges: {0,1}, {1,2}, {2,0}; source=0, destination=2; expected true.
    testCases[0].n = 3;
    testCases[0].edgesSize = 3;
    testCases[0].edges = (int**)malloc(3 * sizeof(int*));
    testCases[0].edges[0] = createEdge(0, 1);
    testCases[0].edges[1] = createEdge(1, 2);
    testCases[0].edges[2] = createEdge(2, 0);
    testCases[0].edgesColSize = (int*)malloc(3 * sizeof(int));
    for (int i = 0; i < 3; i++) {
        testCases[0].edgesColSize[i] = 2;
    }
    testCases[0].source = 0;
    testCases[0].destination = 2;
    testCases[0].expectedResult = true;

    // Test case 2: 6 nodes; edges: {0,1}, {0,2}, {3,5}, {5,4}, {4,3}; source=0, destination=5; expected false.
    testCases[1].n = 6;
    testCases[1].edgesSize = 5;
    testCases[1].edges = (int**)malloc(5 * sizeof(int*));
    testCases[1].edges[0] = createEdge(0, 1);
    testCases[1].edges[1] = createEdge(0, 2);
    testCases[1].edges[2] = createEdge(3, 5);
    testCases[1].edges[3] = createEdge(5, 4);
    testCases[1].edges[4] = createEdge(4, 3);
    testCases[1].edgesColSize = (int*)malloc(5 * sizeof(int));
    for (int i = 0; i < 5; i++) {
        testCases[1].edgesColSize[i] = 2;
    }
    testCases[1].source = 0;
    testCases[1].destination = 5;
    testCases[1].expectedResult = false;

    // Test case 3: 4 nodes; edges: {0,1}, {1,2}, {2,3}; source=0, destination=3; expected true.
    testCases[2].n = 4;
    testCases[2].edgesSize = 3;
    testCases[2].edges = (int**)malloc(3 * sizeof(int*));
    testCases[2].edges[0] = createEdge(0, 1);
    testCases[2].edges[1] = createEdge(1, 2);
    testCases[2].edges[2] = createEdge(2, 3);
    testCases[2].edgesColSize = (int*)malloc(3 * sizeof(int));
    for (int i = 0; i < 3; i++) {
        testCases[2].edgesColSize[i] = 2;
    }
    testCases[2].source = 0;
    testCases[2].destination = 3;
    testCases[2].expectedResult = true;

    // Test case 4: 5 nodes; edges: {0,4}, {4,3}, {3,2}, {2,1}; source=0, destination=1; expected true.
    testCases[3].n = 5;
    testCases[3].edgesSize = 4;
    testCases[3].edges = (int**)malloc(4 * sizeof(int*));
    testCases[3].edges[0] = createEdge(0, 4);
    testCases[3].edges[1] = createEdge(4, 3);
    testCases[3].edges[2] = createEdge(3, 2);
    testCases[3].edges[3] = createEdge(2, 1);
    testCases[3].edgesColSize = (int*)malloc(4 * sizeof(int));
    for (int i = 0; i < 4; i++) {
        testCases[3].edgesColSize[i] = 2;
    }
    testCases[3].source = 0;
    testCases[3].destination = 1;
    testCases[3].expectedResult = true;

    // Test case 5: 4 nodes; edges: {0,1}, {1,2}; source=0, destination=3; expected false.
    testCases[4].n = 4;
    testCases[4].edgesSize = 2;
    testCases[4].edges = (int**)malloc(2 * sizeof(int*));
    testCases[4].edges[0] = createEdge(0, 1);
    testCases[4].edges[1] = createEdge(1, 2);
    testCases[4].edgesColSize = (int*)malloc(2 * sizeof(int));
    for (int i = 0; i < 2; i++) {
        testCases[4].edgesColSize[i] = 2;
    }
    testCases[4].source = 0;
    testCases[4].destination = 3;
    testCases[4].expectedResult = false;

    // Run each test case and print the result
    for (int i = 0; i < numTests; i++) {
        bool result = validPath(testCases[i].n,
                                testCases[i].edges,
                                testCases[i].edgesSize,
                                testCases[i].edgesColSize,
                                testCases[i].source,
                                testCases[i].destination);
        printf("Test %d: %s\n", i + 1, (result == testCases[i].expectedResult) ? "PASS" : "FAIL");

        // Clean up allocated memory for this test case
        free(testCases[i].edgesColSize);
        freeEdges(testCases[i].edges, testCases[i].edgesSize);
    }
}

int main(void)
{
	printf("Running LeetCodeC tests:\n");
	printf("Running FindIfPathExistsInGraph_1971 tests:\n");
	runValidPathTests();
	return 0;
}