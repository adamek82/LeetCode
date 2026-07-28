#include "SpiralMatrix_54.h"

vector<int> SpiralMatrix_54::spiralOrder(const vector<vector<int>>& matrix)
{
    if (matrix.empty() || matrix[0].empty())
        return {};

    int top = 0;
    int bottom = static_cast<int>(matrix.size()) - 1;
    int left = 0;
    int right = static_cast<int>(matrix[0].size()) - 1;

    vector<int> result;
    result.reserve(matrix.size() * matrix[0].size());

    while (top <= bottom && left <= right) {
        for (int col = left; col <= right; ++col)
            result.push_back(matrix[top][col]);

        ++top;

        for (int row = top; row <= bottom; ++row)
            result.push_back(matrix[row][right]);

        --right;

        if (top <= bottom) {
            for (int col = right; col >= left; --col)
                result.push_back(matrix[bottom][col]);

            --bottom;
        }

        if (left <= right) {
            for (int row = bottom; row >= top; --row)
                result.push_back(matrix[row][left]);

            ++left;
        }
    }

    return result;
}
