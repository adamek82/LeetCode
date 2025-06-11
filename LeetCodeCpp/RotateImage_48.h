#pragma once
#include <vector>

using namespace std;

class RotateImage_48 {
public:
    void rotateTransposeReverse(vector<vector<int>>& matrix); // transpose-reverse algo
    void rotateLayerSwap(vector<vector<int>>& matrix);        // “onion-layers” algo
};