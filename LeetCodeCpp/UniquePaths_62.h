#pragma once
#include <algorithm>

using namespace std;

class UniquePaths_62 {
public:
    // O(1) extra space – combinatorial formula using binomial coefficient.
    int uniquePaths_Comb(int m, int n);

    // O(m * n) time, O(m * n) space – classic 2D DP table.
    int uniquePaths_DP2D(int m, int n);

    // O(m * n) time, O(n) space – DP with only 2 rows stored.
    int uniquePaths_DP2Rows(int m, int n);
};
