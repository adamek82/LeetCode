#pragma once
#include <cstdint>

using namespace std;      // brevity

class NumberOf1Bits_191 {
public:
    // Returns the Hamming weight (count of set bits) of a 32-bit integer.
    int hammingWeight(uint32_t n);   // use unsigned to avoid sign issues
};