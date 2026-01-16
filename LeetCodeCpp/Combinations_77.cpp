#include "Combinations_77.h"

 /*
  * LeetCode 77 — Combinations
  *
  * Recursive backtracking — pick-next (k-level decision tree)
  * -------------------------------------------------------------------
  * Idea:
  *   We build combinations of length k by picking numbers in increasing order.
  *   Each recursion level chooses the next element of the combination.
  *
  *   At each recursion frame we have:
  *     - 'start' : the smallest number we are allowed to pick next,
  *     - 'cur'   : the partial combination built so far (size <= k).
  *
  *   When cur.size() == k, we emit 'cur' (a leaf in the decision tree).
  *
  * Traversal example (n = 4, k = 2):
  *   We choose 2 numbers from [1,2,3,4]. The tree has k=2 levels of picks.
  *
  *   start=1, cur=[]
  *   ├─ pick 1 → start=2, cur=[1]
  *   │   ├─ pick 2 → cur=[1,2] → emit
  *   │   ├─ pick 3 → cur=[1,3] → emit
  *   │   └─ pick 4 → cur=[1,4] → emit
  *   ├─ pick 2 → start=3, cur=[2]
  *   │   ├─ pick 3 → cur=[2,3] → emit
  *   │   └─ pick 4 → cur=[2,4] → emit
  *   └─ pick 3 → start=4, cur=[3]
  *       └─ pick 4 → cur=[3,4] → emit
  *
  * Notes:
  *   - There's no explicit "don't pick" branch: skipping happens naturally because after
  *     picking i we recurse with start=i+1, so i can never appear again.
  *
  * Pruning intuition:
  *   - If we still need 'need = k - cur.size()' numbers, then starting at i only makes
  *     sense if there are at least 'need' numbers available in [i..n].
  *   - That is: (n - i + 1) >= need  ⇔  i <= n - need + 1.
  *
  * Mini example showing pruning (n = 4, k = 3):
  *
  *   start=1, cur=[]
  *   ├─ pick 1 → start=2, cur=[1]
  *   │   ├─ pick 2 → start=3, cur=[1,2]
  *   │   │   ├─ pick 3 → cur=[1,2,3] → emit
  *   │   │   └─ pick 4 → cur=[1,2,4] → emit
  *   │   └─ pick 3 → start=4, cur=[1,3]
  *   │       └─ pick 4 → cur=[1,3,4] → emit
  *   └─ pick 2 → start=3, cur=[2]
  *       └─ pick 3 → start=4, cur=[2,3]
  *           └─ pick 4 → cur=[2,3,4] → emit
  *
  *   Note how the root does NOT try "pick 3" (nor "pick 4"):
  *     need = 3 (cur is empty), so i <= n - need + 1 = 4 - 3 + 1 = 2.
  *     Starting with 3 would leave only {4} → impossible to reach length 3.
  *
  * Complexity
  * ----------
  * Time  : O(C(n,k) * k) — we emit C(n,k) combinations, each of length k.
  * Space : O(k) auxiliary — recursion depth equals combination length.
  */
void Combinations_77::dfsCombine(int n, int k, int start,
                                 vector<int>& cur, vector<vector<int>>& out) {
    if (static_cast<int>(cur.size()) == k) {
        out.push_back(cur);
        return;
    }
    // remaining slots to fill
    const int need = k - static_cast<int>(cur.size());
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
