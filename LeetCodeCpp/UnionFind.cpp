#include "UnionFind.h"

// Constructor: Initialize n elements, each in its own set
UnionFind::UnionFind(int n) {
    parent.resize(n);
    for (int i = 0; i < n; ++i) {
        parent[i] = i; // Each element is its own parent
    }
}

// Find: Returns the representative (root) of the set containing n
int UnionFind::find(int n) {
    while (parent[n] != n) {
        n = parent[n]; // Follow parent pointers until root is reached
    }
    return n;
}

// Union with path compression performed during union
void UnionFind::unionSets(int src, int dst) {
    int srcParent = find(src); // Find root of src
    while (parent[dst] != dst) {
        int temp = parent[dst]; // Store the next parent
        parent[dst] = srcParent; // Compress the path to srcParent
        dst = temp; // Move to the next node
    }
    parent[dst] = srcParent; // Finally link the root of dst to srcParent
}

// Display parent array (for debugging)
void UnionFind::displayParents() {
    std::cout << "Parent Array: ";
    for (size_t i = 0; i < parent.size(); ++i) {
        std::cout << parent[i] << " ";
    }
    std::cout << "\n";
}