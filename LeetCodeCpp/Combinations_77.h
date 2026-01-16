#pragma once
#include <vector>
using namespace std;

class Combinations_77 {
public:
    vector<vector<int>> combine(int n, int k);

private:
    static void dfsCombine(int n, int k, int start,
                           vector<int>& cur, vector<vector<int>>& out);
};
