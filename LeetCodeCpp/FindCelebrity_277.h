#pragma once
#include <vector>

class FindCelebrity_277 {
public:
    // The matrix should be set before calling findCelebrity
    std::vector<std::vector<int>> knowsMatrix;

    bool knows(int a, int b) {
        return knowsMatrix[a][b] == 1;
    }

    int findCelebrity(int n);
};
