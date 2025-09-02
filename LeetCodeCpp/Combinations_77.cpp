#include "Combinations_77.h"

void Combinations_77::dfsCombine(int n, int k, int start,
                                 vector<int>& cur, vector<vector<int>>& out) {
    if ((int)cur.size() == k) {
        out.push_back(cur);
        return;
    }
    // remaining slots to fill
    const int need = k - (int)cur.size();
    // iterate i so that even picking all remaining from i..n, we can reach size k
    for (int i = start; i <= n - need + 1; ++i) {
        cur.push_back(i);
        dfsCombine(n, k, i + 1, cur, out);
        cur.pop_back();
    }
}

vector<vector<int>> Combinations_77::combine(int n, int k) {
    vector<vector<int>> out;
    vector<int> cur;
    cur.reserve(k);
    dfsCombine(n, k, 1, cur, out);
    return out;
}
