#pragma once
#include <vector>

using namespace std;

class RotateImage_48 {
public:
    void rotateTransposeReverse(std::vector<std::vector<int>>& matrix); // transpose-reverse algo
    void rotateLayerSwap(std::vector<std::vector<int>>& matrix);        // “onion-layers” algo
};