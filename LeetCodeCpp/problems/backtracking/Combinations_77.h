#pragma once
#include <vector>
using namespace std;

class Combinations_77 {
public:
    // Version 1: "pick-next" (increasing order via start)
    vector<vector<int>> combinePickNext(int n, int k);

    // Version 2: "take/skip" (binary tree over x = n..1, with pruning)
    vector<vector<int>> combineTakeSkip(int n, int k);

private:
    static void dfsCombinePickNext(int n, int k, int start,
                                   vector<int>& cur, vector<vector<int>>& out);

    static void dfsCombineTakeSkip(int x, int k,
                                   vector<int>& cur, vector<vector<int>>& out);
};
