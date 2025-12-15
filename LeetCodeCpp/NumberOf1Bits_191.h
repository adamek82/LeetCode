#pragma once
#include <cstdint>

using namespace std;      // brevity

class NumberOf1Bits_191 {
public:
    // Brian Kernighan trick: clear the lowest set bit each iteration.
    int hammingWeightKernighan(uint32_t n);   // O(k) where k = number of set bits

    // Lookup-table solution: sum popcounts of the 4 bytes of a 32-bit value.
    int hammingWeightLookup(uint32_t n);      // O(1) per call with tiny constant
};
