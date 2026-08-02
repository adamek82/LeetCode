#include "LargestRectangleInHistogram_84.h"
#include <stack>
#include <algorithm>

/*
 * Approach — monotonic nondecreasing stack (indices)
 * --------------------------------------------------
 * Let heights[i] be the bar height (each bar has width = 1).
 *
 * Goal: for each bar, find the furthest span [L+1 .. R-1] where that bar
 *       remains the *shortest* height; the rectangle is height * width.
 *
 * This implementation uses:
 *   - st           : stack<int> holding bar *indices* whose heights are in
 *                    nondecreasing order from bottom → top.
 *   - maxArea      : the running maximum rectangle area.
 *   - heights.push_back(0) : a sentinel bar at the end to flush the stack.
 *
 * Algorithm (i = 0 .. heights.size()-1 after appending sentinel 0):
 *   • While the current height heights[i] is *lower* than the height at the
 *     top index of the stack (heights[st.top()]):
 *       - h = heights[st.top()]           // the popped bar’s height
 *       - pop the index
 *       - width = st.empty() ? i : i - st.top() - 1
 *           Explanation:
 *             If the stack is empty after popping, there is no smaller bar
 *             to the left → the span starts at 0, so width = i - 0.
 *             Otherwise, st.top() is the index of the previous smaller bar,
 *             so the span starts at st.top() + 1.
 *       - maxArea = max(maxArea, h * width)
 *   • Push i onto the stack and continue.
 *
 * Correctness
 * -----------
 * An index leaves the stack exactly once (when we discover the first bar to
 * its right that is strictly lower). At that moment:
 *   - i is the first index to the right with a smaller height;
 *   - after popping, st.top() (if any) is the previous smaller height to the left.
 * The computed width therefore covers *all* positions where h is the minimum,
 * hence we evaluate that bar’s maximal rectangle exactly once.
 *
 * Tie-handling (equal heights)
 * ----------------------------
 * Because we only pop when heights[i] < heights[st.top()], equal heights stay
 * stacked. This assigns equal-height bars to the *rightmost* occurrence when
 * forming widths and avoids double counting; the overall maximum is unaffected.
 *
 * Complexity
 * ----------
 * Time  : O(n) — each index is pushed once and popped at most once.
 * Space : O(n) — the stack can hold up to n indices in the worst case.
 *
 * Note
 * ----
 * The sentinel 0 is appended to heights to flush remaining bars. If mutating
 * the input vector is undesirable, pop_back() the sentinel before returning,
 * or work on a copy,
 * or avoid mutation entirely by one of these patterns:
 *   (A) Do a final explicit flush after the main loop (no sentinel):
 *       for (int i = 0; i < n; ++i) { ... }           // no push_back(0)
 *       while (!st.empty()) {
 *           int h = heights[st.top()]; st.pop();
 *           int width = st.empty() ? n : n - st.top() - 1;
 *           maxArea = max(maxArea, h * width);
 *       }
 *   (B) Iterate to i <= n and use a synthetic height at i == n:
 *       for (int i = 0; i <= n; ++i) {
 *           int curH = (i == n ? 0 : heights[i]);     // sentinel without modifying input
 *           while (!st.empty() && curH < heights[st.top()]) { ... }
 *           st.push(i);
 *       }
 */
int LargestRectangleInHistogram_84::largestRectangleArea(vector<int> &heights)
{
    stack<int> st; // Stack to store indices of histogram bars
    int maxArea = 0; // Variable to store the maximum area

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