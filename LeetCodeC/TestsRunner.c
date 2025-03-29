#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "FindIfPathExistsInGraph_1971.h"
#include "AllOOneDataStructure_432.h"

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

// Helper function to check if a string is among the candidate strings.
static bool inSet(const char* str, const char* candidates[], int candidateCount) {
    for (int i = 0; i < candidateCount; i++) {
        if (strcmp(str, candidates[i]) == 0)
            return true;
    }
    return false;
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

// AllOne tests, similar to our C++ tests.
void runAllOneTests() {
    // Test 1: Basic example from problem statement
    {
        AllOne* allOne = allOneCreate();
        allOneInc(allOne, "hello");
        allOneInc(allOne, "hello");
        // "hello" now has count 2
        char* mx = allOneGetMaxKey(allOne);  // expect "hello"
        char* mn = allOneGetMinKey(allOne);  // expect "hello"
        bool t1a = (strcmp(mx, "hello") == 0) && (strcmp(mn, "hello") == 0);

        allOneInc(allOne, "leet");
        // "hello"=2, "leet"=1
        mx = allOneGetMaxKey(allOne); // still "hello"
        mn = allOneGetMinKey(allOne); // now "leet"
        bool t1b = (strcmp(mx, "hello") == 0) && (strcmp(mn, "leet") == 0);

        bool pass = t1a && t1b;
        printf("AllOne Test 1: %s\n", pass ? "PASS" : "FAIL");
        allOneFree(allOne);
    }

    // Test 2: Multiple keys with same counts
    {
        AllOne* allOne = allOneCreate();
        allOneInc(allOne, "foo"); // foo=1
        allOneInc(allOne, "bar"); // bar=1
        allOneInc(allOne, "bar"); // bar=2
        // So bar=2, foo=1
        bool t2a = inSet(allOneGetMaxKey(allOne), (const char*[]){"bar"}, 1); // Only "bar" has count=2
        bool t2b = inSet(allOneGetMinKey(allOne), (const char*[]){"foo"}, 1); // Only "foo" has count=1

        // Now bring foo up to 2
        allOneInc(allOne, "foo"); // foo=2, bar=2
        // Both foo & bar have count=2, so min & max can be either
        bool t2c = inSet(allOneGetMaxKey(allOne), (const char*[]){"foo", "bar"}, 2);
        bool t2d = inSet(allOneGetMinKey(allOne), (const char*[]){"foo", "bar"}, 2);

        bool pass = t2a && t2b && t2c && t2d;
        printf("AllOne Test 2: %s\n", pass ? "PASS" : "FAIL");
        allOneFree(allOne);
    }

    // Test 3: Testing dec() and removal
    {
        AllOne* allOne = allOneCreate();
        // a=3, b=1, c=1
        allOneInc(allOne, "a");  allOneInc(allOne, "a");  allOneInc(allOne, "a");
        allOneInc(allOne, "b");
        allOneInc(allOne, "c");

        // Check max/min
        bool t3a = inSet(allOneGetMaxKey(allOne), (const char*[]){"a"}, 1);          // a=3 is max
        bool t3b = inSet(allOneGetMinKey(allOne), (const char*[]){"b", "c"}, 2);     // b=1, c=1

        // Decrement "a" 3 times => "a" removed from structure
        allOneDec(allOne, "a"); // now a=2
        allOneDec(allOne, "a"); // now a=1
        allOneDec(allOne, "a"); // now removed
        // left with b=1, c=1
        bool t3c = inSet(allOneGetMaxKey(allOne), (const char*[]){"b", "c"}, 2);
        bool t3d = inSet(allOneGetMinKey(allOne), (const char*[]){"b", "c"}, 2);

        bool pass = t3a && t3b && t3c && t3d;
        printf("AllOne Test 3: %s\n", pass ? "PASS" : "FAIL");
        allOneFree(allOne);
    }
}

int main(void)
{
	printf("Running LeetCodeC tests:\n");
	printf("Running FindIfPathExistsInGraph tests (both original and optimized):\n");
	runValidPathTests();
	printf("Running All O One Data Structure_432) tests:\n");
	runAllOneTests();
	return 0;
}