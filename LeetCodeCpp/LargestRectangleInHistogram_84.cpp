#include "LargestRectangleInHistogram_84.h"

int LargestRectangleInHistogram_84::largestRectangleArea(vector<int> &heights)
{
    stack<int> st; // Stack to store indices of histogram bars
    int maxArea = 0; // Variable to store the maximum area
    int n = heights.size();

    // Append a 0 height to handle remaining bars in the stack
    heights.push_back(0);

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