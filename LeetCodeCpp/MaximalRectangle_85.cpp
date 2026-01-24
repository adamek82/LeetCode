#include "MaximalRectangle_85.h"
#include <stack>
#include <algorithm>

/******************************************************************************
 *  Maximal Rectangle - LeetCode 85
 *
 *  Approach
 *  --------
 *  •  Treat every matrix row as the *base* of a histogram:
 *       height[c] = number of consecutive '1's ending at current row in column c.
 *  •  After refreshing `height` for the current row, run the classic
 *     *Largest Rectangle in a Histogram* scan with a **monotonically increasing
 *     stack**:
 *        – While the current bar is lower than the bar indexed at the
 *          stack’s top, pop and compute the rectangle that bar can form.
 *        – A sentinel 0-height bar is appended so every pending bar is flushed.
 *  •  The maximum over all rows is the answer.
 *
 *  Complexity
 *  ----------
 *      Time :  O(rows × cols)
 *              (each cell is processed a constant number of times)
 *      Space:  O(cols)
 *              (histogram array + stack)
 *
 ******************************************************************************/
int MaximalRectangle_85::maximalRectangle(vector<vector<char>>& matrix)
{
    if (matrix.empty() || matrix[0].empty()) return 0;
    const int rows = matrix.size(), cols = matrix[0].size();

    // Append a 0 height to handle remaining bars in the stack
    vector<int> height(cols+1, 0);   // current histogram heights
    int maxArea = 0;

    for (int r = 0; r < rows; ++r) {
        // 1. Build/refresh the histogram for this row
        for (int c = 0; c < cols; ++c) {
            height[c] = (matrix[r][c] == '1') ? height[c] + 1 : 0;
        }

        // 2. Largest-rectangle-in-histogram on `height`
        maxArea = max(maxArea, largestRectangleArea(height));
    }

    return maxArea;
}

int MaximalRectangle_85::largestRectangleArea(const vector<int>& heights)
{
    stack<int> st; // Stack to store indices of histogram bars
    int maxArea = 0; // Variable to store the maximum area
    int n = heights.size();

    for (int i = 0; i < heights.size(); ++i) {
        // While the current height is less than the height of the bar at the stack's top
        while (!st.empty() && heights[i] < heights[st.top()]) {
            int h = heights[st.top()]; // Height of the bar at the top of the stack
            st.pop();
            int width = st.empty() ? i : i - st.top() - 1; // Width of the rectangle
            maxArea = max(maxArea, h * width); // Update maximum area
        }
        st.push(i); // Push the current index into the stack
    }

    return maxArea;
}
