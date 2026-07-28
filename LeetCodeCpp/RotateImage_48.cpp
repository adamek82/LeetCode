#include "RotateImage_48.h"
#include <algorithm>

void RotateImage_48::rotateTransposeReverse(vector<vector<int>>& matrix)
{
    const size_t n = matrix.size();

    for (size_t row = 0; row < n; ++row) {
        for (size_t col = row + 1; col < n; ++col)
            swap(matrix[row][col], matrix[col][row]);
    }

    for (auto& row : matrix)
        reverse(row.begin(), row.end());
}

void RotateImage_48::rotateLayerSwap(vector<vector<int>>& matrix)
{
    const size_t n = matrix.size();

    for (size_t layer = 0; layer < n / 2; ++layer) {
        const size_t last = n - layer - 1;

        for (size_t col = layer; col < last; ++col) {
            const size_t offset = col - layer;
            const int top = matrix[layer][col];

            matrix[layer][col] = matrix[last - offset][layer];
            matrix[last - offset][layer] = matrix[last][last - offset];
            matrix[last][last - offset] = matrix[col][last];
            matrix[col][last] = top;
        }
    }
}
