# Recursive Backtracking — Quick Guide (LeetCode Set)

A compact refresher with C++ tips, pruning rules, and gotchas. Fits on ~3–4 pages.

---

## Quick Reference

Backtracking = depth-first search over decisions (**choose → explore → unchoose**). Keep the state minimal; prune aggressively; avoid copying.

```cpp
// Generic backtracking template (C++17+)
void dfs(State& st) {
    if (done(st)) { emit(st); return; }
    for (auto choice : choices(st)) {
        if (!feasible(st, choice)) continue;   // pruning
        apply(st, choice);                      // choose
        dfs(st);                                // explore
        undo(st, choice);                       // unchoose
    }
}
```

**C++ notes / micro-optimizations**

- Minimize parameters: pass **references**, mutate + `pop_back()` / **swap back**.
- Pre-size buffers: `vector.reserve(k)`, `string.reserve(n)` to cut reallocations.
- Monotone indices avoid duplicates: forward **`start` pointer** pattern.
- Sort when dedup/pruning helps; skip equal values via `i>start && a[i]==a[i-1]`.
- Upper bounds matter: `i ≤ n − need + 1` (combinations).
- In-place swaps for permutations; restore with a second `swap(...)`.
- Grid search: mark visited **in place** (e.g., `'#'`) and restore after recursion.
- Emit on entry for subsets (pre-order) to capture all prefixes efficiently.
- **Parentheses invariant:** remaining counts `(openLeft, closeLeft)`; only close if `closeLeft > openLeft`.

---

## Set Overview

| Problem | LC # | Difficulty | Score | Status |
|---|---:|:---:|:---:|:---:|
| Subsets | 78 | Medium | 6/10 | ✔ |
| Permutations | 46 | Medium | 6/10 | ✔ |
| Combinations | 77 | Medium | 6.5/10 | ✔ |
| Combination Sum | 39 | Medium | 7/10 | ✔ |
| Letter Combinations of a Phone Number | 17 | Medium | 7/10 | ✔ |
| Generate Parentheses | 22 | Medium | 8/10 | ✔ |
| Jump Game II | 45 | Medium | 8/10 | ✔ |
| Word Search | 79 | Medium | 9/10 | ✔ |

---

## Subsets (Power Set) — LC 78

Two idioms: (1) **Pre-order include/exclude** via forward `start`; (2) **Bitmask** `0..(1<<n)-1`.

```cpp
// (1) Recursive include/exclude via 'start'
void dfs(const vector<int>& a, int start, vector<int>& cur, vector<vector<int>>& out) {
    out.push_back(cur);                       // emit prefix
    for (int i = start; i < (int)a.size(); ++i) {
        cur.push_back(a[i]);
        dfs(a, i + 1, cur, out);
        cur.pop_back();                       // backtrack
    }
}

// (2) Bitmask enumeration
for (int mask = 0; mask < (1<<n); ++mask) {
    vector<int> s;
    for (int i = 0; i < n; ++i) if (mask & (1<<i)) s.push_back(a[i]);
    out.push_back(move(s));
}
```

---

## Permutations — LC 46

In-place **swap** the candidate into position `pos`, recurse, then **swap back**.

```cpp
void dfsPerm(int pos, vector<int>& nums, vector<vector<int>>& out) {
    if (pos == (int)nums.size()) { out.push_back(nums); return; }
    for (int i = pos; i < (int)nums.size(); ++i) {
        swap(nums[pos], nums[i]);      // choose
        dfsPerm(pos + 1, nums, out);   // explore
        swap(nums[pos], nums[i]);      // unchoose
    }
}
```

---

## Combinations — LC 77

Forward index + **size-aware loop bound**. Prune with `i ≤ n − need + 1`.

```cpp
void dfsCombine(int n, int k, int start, vector<int>& cur, vector<vector<int>>& out) {
    if ((int)cur.size() == k) { out.push_back(cur); return; }
    int need = k - (int)cur.size();
    for (int i = start; i <= n - need + 1; ++i) { // leave enough room
        cur.push_back(i);
        dfsCombine(n, k, i + 1, cur, out);
        cur.pop_back();
    }
}
```

---

## Combination Sum — LC 39

Sort first. **Reuse allowed** ⇒ recurse with the **same index**. Prune when `cand[i] > remain`.

```cpp
void dfs(int i, int remain, const vector<int>& a, vector<int>& cur, vector<vector<int>>& out) {
    if (remain == 0) { out.push_back(cur); return; }
    for (int j = i; j < (int)a.size(); ++j) {
        int v = a[j];
        if (v > remain) break;           // sorted pruning
        cur.push_back(v);
        dfs(j, remain - v, a, cur, out); // reuse allowed
        cur.pop_back();
    }
}
```

---

## Letter Combinations of a Phone Number — LC 17

Digit→letters mapping + **positional DFS**. Pre-reserve the path.

```cpp
// Keypad mapping indexed by digit - '0' (0/1 → empty).
// `inline` + `constexpr` keeps this a single definition across TUs (C++17+).
inline static constexpr array<string_view, 10> KEYS{
    "", "", "abc", "def", "ghi",
    "jkl", "mno", "pqrs", "tuv", "wxyz"
};

void dfs(const string& digits, int idx, string& path, vector<string>& out) {
    if (idx == (int)digits.size()) { out.push_back(path); return; }
    string_view letters = KEYS[digits[idx] - '0'];
    for (char ch : letters) { path.push_back(ch); dfs(digits, idx + 1, path, out); path.pop_back(); }
}
```

---

## Generate Parentheses — LC 22

**Backtracking with remaining counts** `(openLeft, closeLeft)`. Only close if `closeLeft > openLeft`.

```cpp
void dfs(int openLeft, int closeLeft, string& cur, vector<string>& out) {
    if (openLeft == 0 && closeLeft == 0) { out.push_back(cur); return; }
    if (openLeft > 0) { cur.push_back('('); dfs(openLeft - 1, closeLeft, cur, out); cur.pop_back(); }
    if (closeLeft > openLeft) { cur.push_back(')'); dfs(openLeft, closeLeft - 1, cur, out); cur.pop_back(); }
}
```

---

## Word Search — LC 79

DFS from each cell; mark **visited in place** (e.g., `'#'`) and **restore**. Prune on mismatch/out-of-bounds.

```cpp
bool dfs(vector<vector<char>>& b, const string& w, int r, int c, int k) {
    if (k == (int)w.size()) return true;
    if (r<0 || c<0 || r>= (int)b.size() || c>= (int)b[0].size() || b[r][c] != w[k]) return false;
    char tmp = b[r][c]; b[r][c] = '#';              // mark
    bool ok = dfs(b,w,r+1,c,k+1) || dfs(b,w,r-1,c,k+1) ||
              dfs(b,w,r,c+1,k+1) || dfs(b,w,r,c-1,k+1);
    b[r][c] = tmp;                                   // restore
    return ok;
}
```

---

## Jump Game II — LC 45 (Greedy “level expansion”)

BFS intuition without a queue: expand the current reachable range `[0..curEnd]`; track the farthest `nextEnd`; when `i` hits `curEnd`, `++jumps` and set `curEnd = nextEnd`.

```cpp
int jump(const vector<int>& a) {
    int jumps = 0, curEnd = 0, nextEnd = 0;
    for (int i = 0; i + 1 < (int)a.size(); ++i) {
        nextEnd = max(nextEnd, i + a[i]);
        if (i == curEnd) { ++jumps; curEnd = nextEnd; }
    }
    return jumps;
}
```

---

## Common Pitfalls

- Copying vectors/strings per recursion step — mutate in place + `pop_back()` / `swap`.
- **Combinations**: off-by-one in loop upper bound; ensure enough room with `i ≤ n − need + 1`.
- Dedup/pruning without sorting; forgetting to skip equals (`i>start && a[i]==a[i-1]`).
- **Grid backtracking**: mark but forget to **restore**.
- **Parentheses**: placing `')'` when `openLeft == closeLeft` ⇒ invalid prefix.
- **LC 17**: empty input should return an **empty vector**, not `{""}`.
- **Jump Game II**: DFS/backtracking is exponential ⇒ use greedy range expansion.

---

## Mini Drills (tiny answers below each)

**Q:** Why pass `start` forward for subsets/combinations?  
**A:** Prevents revisiting earlier indices ⇒ no duplicates.

**Q:** When may we break early in Combination Sum?  
**A:** After sorting, if `a[i] > remain` then later values are too big ⇒ break.

**Q:** How to bound the loop for combinations?  
**A:** `need = k - cur.size();` ensure `i ≤ n - need + 1`.

**Q:** Why swap-based permutations are O(1) extra space?  
**A:** In-place swapping; recursion stores only indices.

**Q:** Parentheses invariant?  
**A:** Never place `')'` unless `closeLeft > openLeft`; counts never negative.

**Q:** Word Search: why in-place mark `'#'`?  
**A:** Saves memory and improves locality; restore after recursion.

**Q:** Jump Game II: why stop at `n-2`?  
**A:** We don't need to expand from the last index; answer finalized earlier.

---

**Tip:** Pre-allocate: power set ⇒ `2^n` subsets; reserve buffers to reduce reallocations.
