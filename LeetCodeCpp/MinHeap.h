#pragma once
#include <vector>
#include <iostream>
#include <stdexcept>

class MinHeap {
private:
    std::vector<int> heap; // 1-based index

    void upheap(int idx);
    void downheap(int idx);

public:
    MinHeap(); // Constructor

    void insert(int val);        // Insert an element into the heap
    int extractMin();            // Extract the minimum element
    void update(int idx, int newVal); // Update the value at a specific index
    void printHeap();            // Print the current state of the heap
};