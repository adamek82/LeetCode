#pragma once

#include <vector>

using namespace std;

class Combinations_77 {
public:
    vector<vector<int>> combinePickNext(int n, int k);
    vector<vector<int>> combineTakeSkip(int n, int k);

private:
    static void generatePickNext(
        int n,
        int k,
        int start,
        vector<int>& current,
        vector<vector<int>>& result);

    static void generateTakeSkip(
        int value,
        int k,
        vector<int>& current,
        vector<vector<int>>& result);
};
