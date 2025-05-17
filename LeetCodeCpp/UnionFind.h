#pragma once
#include <vector>
#include <iostream>

using namespace std;

class UnionFind {
private:
    vector<int> parent;

public:
    // Constructor: Initialize n elements, each in its own set
    UnionFind(int n);

    // Find: Returns the representative (root) of the set containing n
    int find(int n);

    // Union with path compression performed during union
    void unionSets(int src, int dst);

    // Display parent array (for debugging)
    void displayParents();
};
