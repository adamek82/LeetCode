#include "SetMatrixZeroes_73.h"
#include <algorithm>
#include <cstddef>

using namespace std;

void SetMatrixZeroes_73::setZeroes(vector<vector<int>>& matrix)
{
    if (matrix.empty() || matrix[0].empty())
        return;

    const size_t rows = matrix.size();
    const size_t cols = matrix[0].size();
    bool zeroFirstCol = false;

    for (size_t row = 0; row < rows; ++row) {
        if (matrix[row][0] == 0)
            zeroFirstCol = true;

        for (size_t col = 1; col < cols; ++col) {
            if (matrix[row][col] == 0) {
                matrix[row][0] = 0;
                matrix[0][col] = 0;
            }
        }
    }

    for (size_t row = 1; row < rows; ++row) {
        for (size_t col = 1; col < cols; ++col) {
            if (matrix[row][0] == 0 || matrix[0][col] == 0)
                matrix[row][col] = 0;
        }
    }

    if (matrix[0][0] == 0)
        fill(matrix[0].begin(), matrix[0].end(), 0);

    if (zeroFirstCol) {
        for (auto& row : matrix)
            row[0] = 0;
    }
}
