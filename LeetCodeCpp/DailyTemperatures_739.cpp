#include "DailyTemperatures_739.h"

/*
 * Daily Temperatures (LeetCode 739) — Monotonic Stack (decreasing by temperature)
 *
 * Approach:
 *   Scan left → right while maintaining a stack of indices whose temperatures form a
 *   strictly decreasing sequence. For a new day i with temperature T[i], pop from the top
 *   while T[i] > T[top]. For each popped index j, day i is the first warmer day, so
 *   answer[j] = i - j. Then push i. Indices left on the stack at the end have no warmer
 *   future day → answer stays 0.
 *
 * Why it works (invariant sketch):
 *   The stack is always strictly decreasing by temperature. If j is popped by i, there is
 *   no k with j < k < i and T[k] > T[j]; otherwise j would have been popped earlier at k.
 *   Thus i is the first warmer day after j.
 *
 * Complexity:
 *   Time  : O(n)  — each index is pushed and popped at most once.
 *   Space : O(n)  — stack can hold up to n indices in a strictly decreasing run.
 *
 * Notes:
 *   Use strict '>' (equal temps don't count as warmer) and store indices (we need distances).
 */
vector<int> DailyTemperatures_739::dailyTemperatures(vector<int> &temperatures)
{
    const int n = static_cast<int>(temperatures.size());
    vector<int> ans(n, 0);

    // Monotonic stack of indices; temperatures[st[k]] are strictly decreasing.
    vector<int> st;
    st.reserve(n);

    for (int i = 0; i < n; ++i) {
        // If today is warmer than the day at the top of the stack,
        // we just found the next warmer day for that index.
        while (!st.empty() && temperatures[i] > temperatures[st.back()]) {
            int j = st.back(); st.pop_back();
            ans[j] = i - j;    // distance to the first warmer day
        }
        // Today still waits for a warmer future day → push its index.
        st.push_back(i);
    }

    // Any indices left on the stack have no warmer future day → remain 0.
    return ans;
}
