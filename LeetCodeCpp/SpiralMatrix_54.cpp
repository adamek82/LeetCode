#include "SpiralMatrix_54.h"

std::vector<int> SpiralMatrix_54::spiralOrder(std::vector<std::vector<int>> &matrix)
{
    int m = matrix.size();
    int n = matrix[0].size();
    std::vector<int> ans;
    
    const int Visited = std::numeric_limits<int>::max(); // Mark visited cells with MAX_INT
    
    int dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    int currDir = 0;
    int currRow = 0, currCol = 0;

    // Loop until all elements are collected
    while (ans.size() < m * n) {
        ans.push_back(matrix[currRow][currCol]);
        matrix[currRow][currCol] = Visited; // Mark the cell as visited
        
        int nextR = currRow + dir[currDir][0];
        int nextC = currCol + dir[currDir][1];

        // Change direction if the next cell is invalid or already visited
        if (nextR < 0 || nextR >= m || nextC < 0 || nextC >= n || matrix[nextR][nextC] == Visited) {
            currDir = (currDir + 1) % 4;
        }
        currRow += dir[currDir][0];
        currCol += dir[currDir][1];
    }
    return ans;
}