#include "MinHeap.h"

// Constructor
MinHeap::MinHeap() {
    heap.push_back(-1); // Dummy element to make 1-based indexing easier
}

// Helper: Restore the heap property by moving an element upward
void MinHeap::upheap(int idx) {
    while (idx > 1 && heap[idx] < heap[idx / 2]) {
        std::swap(heap[idx], heap[idx / 2]);
        idx /= 2; // Move up
    }
}

// Helper: Restore the heap property by moving an element downward
void MinHeap::downheap(int idx) {
    int size = heap.size() - 1;
    while (idx * 2 <= size) { // While there's at least a left child
        int child = idx * 2; // Left child
        if (child + 1 <= size && heap[child + 1] < heap[child]) {
            child++; // Choose the smaller child
        }
        if (heap[idx] <= heap[child]) break; // Min-heap property satisfied
        std::swap(heap[idx], heap[child]);
        idx = child; // Move down
    }
}

// Insert an element into the heap
void MinHeap::insert(int val) {
    heap.push_back(val); // Add the element to the end
    upheap(heap.size() - 1); // Restore min-heap property
}

// Extract the minimum element
int MinHeap::extractMin() {
    if (heap.size() <= 1) throw std::runtime_error("Heap is empty");
    int minVal = heap[1];
    heap[1] = heap.back(); // Move the last element to the root
    heap.pop_back();       // Remove the last element
    downheap(1);           // Restore min-heap property
    return minVal;
}

// Update the value at a specific index
void MinHeap::update(int idx, int newVal) {
    if (idx <= 0 || idx >= heap.size()) throw std::runtime_error("Invalid index");
    int oldVal = heap[idx];
    heap[idx] = newVal;
    if (newVal < oldVal) {
        upheap(idx); // If priority decreased, move up
    } else {
        downheap(idx); // If priority increased, move down
    }
}

// Print the current state of the heap
void MinHeap::printHeap() {
    for (int i = 1; i < heap.size(); i++) {
        std::cout << heap[i] << " ";
    }
    std::cout << std::endl;
}