#pragma once
#include <vector>

using namespace std;

class FindCelebrity_277 {
public:
    // The matrix should be set before calling findCelebrity
    vector<vector<int>> knowsMatrix;

    bool knows(int a, int b) {
        return knowsMatrix[a][b] == 1;
    }

    int findCelebrity(int n);
};
