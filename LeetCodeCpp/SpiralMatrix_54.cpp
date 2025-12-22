#include "SpiralMatrix_54.h"
#include <vector>
#include <limits>

/*
 * Spiral Matrix — walk in 4 directions, marking visited cells in-place
 *
 * Idea
 * ----
 * Simulate the spiral traversal starting at (0,0). Keep a current direction
 * among: right, down, left, up. At each step:
 *   1) output current cell,
 *   2) mark it as visited,
 *   3) try to move forward; if the next cell is out of bounds or already
 *      visited, rotate direction clockwise and then move.
 *
 * "Visited" trick (in-place marking)
 * ----------------------------------
 * Instead of maintaining a separate visited matrix or four shrinking borders,
 * we overwrite each visited cell with a sentinel value:
 *   Visited = numeric_limits<int>::max().
 * This makes the "can I move forward?" check uniform and keeps the code short.
 *
 * Important caveat:
 * ---------------
 * This works only because the function receives `matrix` by non-const reference
 * and is allowed to modify it (as on LeetCode). In general APIs you might get
 * `const vector<vector<int>>& matrix`, in which case you cannot do in-place
 * marking and must use borders or a separate visited structure.
 * Also, the sentinel must be a value that cannot appear as a legitimate matrix
 * element; otherwise you'd confuse real data with "visited".
 *
 * Complexity
 * ----------
 * Time:  O(m * n)  (each cell processed once)
 * Space: O(1) extra (besides the output vector)
 */
vector<int> SpiralMatrix_54::spiralOrder(vector<vector<int>> &matrix)
{
    int m = matrix.size();
    int n = matrix[0].size();
    vector<int> ans;

    const int Visited = numeric_limits<int>::max(); // Mark visited cells with MAX_INT

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