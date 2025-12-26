#include "DailyTemperatures_739.h"

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