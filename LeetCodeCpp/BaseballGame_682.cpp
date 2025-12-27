#include "BaseballGame_682.h"
#include <vector>
#include <string>

int BaseballGame_682::calPoints(vector<string>& operations) {
    vector<int> st;
    int total = 0;

    for (const string& op : operations) {
        if (op == "C") {
            total -= st.back();
            st.pop_back();
        } else if (op == "D") {
            int v = 2 * st.back();
            st.push_back(v);
            total += v;
        } else if (op == "+") {
            int v = st.back() + st[st.size() - 2];
            st.push_back(v);
            total += v;
        } else {
            int v = stoi(op);
            st.push_back(v);
            total += v;
        }
    }
    return total;
}