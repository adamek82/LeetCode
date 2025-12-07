# Binary Search — Interview Cheat Sheet (LeetCode Set)

A compact refresher with C++-style patterns, invariants, and gotchas. Aimed as a 4–5 page pre-interview recap.

---

## Set Overview

| Problem | LC # | Difficulty | Score | Status |
|---|---:|:---:|:---:|:---:|
| Binary Search | 704 | Easy | 3/10 | ✔ |
| Search Insert Position | 35 | Easy | 3.5/10 | ✔ |
| First Bad Version | 278 | Easy | 4/10 | ✔ |
| Valid Perfect Square | 367 | Easy | 4/10 | ✔ |
| Search a 2D Matrix | 74 | Medium | 5/10 | ✔ |
| Find Minimum in Rotated Sorted Array | 153 | Medium | 6/10 | ✔ |
| Search in Rotated Sorted Array | 33 | Medium | 7/10 | ✔ |
| Koko Eating Bananas | 875 | Medium | 7/10 | ✔ |

---

## Quick Reference

**Core idea.** Binary search works when the search space is “monotone” in some sense:

- Sorted array, or  
- Parameter `x` where predicate `ok(x)` goes `false, false, …, true, true, …`.

Two main loop shapes:

1. **Exact search (may fail)**  
   - Invariant: if the answer exists, it is in the **closed** interval `[left, right]`.  
   - Interval is allowed to become empty.  
   - Loop: `while (left <= right)`  
   - Typical exit:
     - Found: `return mid;`
     - Not found: `left > right` (interval empty).

2. **Boundary search (answer definitely exists)**  
   - We know at least one valid answer is inside `[left, right]`.  
   - Keep `[left, right]` **non-empty**; shrink until `left == right`.  
   - Loop: `while (left < right)`  
   - One branch **keeps** `mid` (e.g., `right = mid;`), the other **discards** `mid` (e.g., `left = mid + 1;`).  
   - Exit: `left == right` is the boundary.

**Always compute mid safely:**

```cpp
int mid = left + (right - left) / 2;
```

---

## Generic Templates

### 1. Exact search on indices — `while (left <= right)`

Used when the target may be **absent** (classic “find element or −1”).

```cpp
int binarySearch(const vector<int>& a, int target) {
    int left = 0, right = (int)a.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (a[mid] == target)
            return mid;           // found
        else if (a[mid] < target)
            left = mid + 1;       // drop [left..mid]
        else
            right = mid - 1;      // drop [mid..right]
    }
    return -1;                    // not found
}
```

**Key invariant.**

- All candidates are always inside `[left, right]`.  
- If `a[mid] < target`, then `mid` and everything left of it are too small ⇒ `left = mid + 1`.  
- If `a[mid] > target`, then `mid` and everything right of it are too big ⇒ `right = mid - 1`.  
- In both branches we **drop** `mid` because it cannot be the answer.

**When to use it:**

- LC 704 – Binary Search
- LC 74 – Search a 2D Matrix
- LC 33 – Search in Rotated Sorted Array (structural variant)
- LC 35 – Search Insert Position (with a twist)
- LC 367 – Valid Perfect Square (search in value space, but same pattern)

---

### 2. Boundary / “first True” search — `while (left < right)`

Used when we know an answer exists and want a **boundary**:

- First bad version  
- Minimal feasible speed / capacity  
- Minimum element in rotated array  

Generic pattern:

```cpp
int firstTrue(int left, int right) { // [left, right], answer exists
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (ok(mid))
            right = mid;           // mid can be the answer → keep it
        else
            left = mid + 1;        // mid cannot be the answer → discard it
    }
    return left;                   // == right
}
```

**Key mental hook:**

> Ask: “Can `mid` still be the answer?”
>
> - If **yes** → keep `mid` inside interval (e.g., `right = mid;`).  
> - If **no** → discard `mid` (e.g., `left = mid + 1;` or `right = mid - 1;`).

**When to use it:**

- LC 278 – First Bad Version
- LC 153 – Find Minimum in Rotated Sorted Array
- LC 875 – Koko Eating Bananas (binary search on the answer)

---

## Problem-by-Problem Patterns

### 704. Binary Search — exact hit or fail

Classic exact search, `while (left <= right)`.

- Search over indices `[0, n-1]`.  
- Return index if found, `-1` otherwise.  
- Direct use of the generic exact template.

---

### 74. Search a 2D Matrix — flatten to 1D

Matrix has rows sorted and each row strictly greater than previous row’s last element.  
Treat it as one sorted array of length `m * n`.

```cpp
bool searchMatrix(const vector<vector<int>>& mat, int target) {
    int m = mat.size(), n = mat[0].size();
    int left = 0, right = m * n - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        int row = mid / n;         // map 1D → 2D
        int col = mid % n;
        int val = mat[row][col];
        if (val == target) return true;
        else if (val < target) left = mid + 1;
        else right = mid - 1;
    }
    return false;
}
```

Same **exact-search** logic, just with index mapping.

---

### 367. Valid Perfect Square — search over values

Search over possible roots `x`:

- `left = 1`, `right = num`.  
- Compare `mid * mid` with `num`.  
- Use `long long` to avoid overflow.

```cpp
bool isPerfectSquare(int num) {
    long long left = 1, right = num;
    while (left <= right) {
        long long mid = left + (right - left) / 2;
        long long sq = mid * mid;
        if (sq == num) return true;
        if (sq < num) left = mid + 1;
        else right = mid - 1;
    }
    return false;
}
```

Still **exact search**, just on the number line instead of array indices.

---

### 35. Search Insert Position — exact search + insertion index

Same `while (left <= right)` template, but if not found we must return the **insertion index**.

```cpp
int searchInsert(const vector<int>& a, int target) {
    int left = 0, right = (int)a.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (a[mid] == target)
            return mid;
        else if (a[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return left;  // insertion position
}
```

**Why `left` is correct:**

At all times:

- All indices `< left` have `a[i] < target`.  
- All indices `> right` have `a[i] > target`.  

Loop ends when `left == right + 1`. Then:

- Every index `< left` has `a[i] < target`.  
- Every index `>= left` is `> right`, so `a[i] > target`.  

So `left` is exactly the first position where an element ≥ target could appear — the correct insertion position.

---

### 278. First Bad Version — first `true`

Versions: `1..n`. Predicate `isBad(v)` is monotone:

- `false, false, …, false, true, true, …, true`  
- We want the **first** bad version.

Use `while (left < right)` and **keep** `mid` when it’s bad:

```cpp
int firstBadVersion(int n) {
    int left = 1, right = n;
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (isBadVersion(mid))
            right = mid;       // mid is bad → F ∈ [left, mid]
        else
            left = mid + 1;    // mid is good → F ∈ (mid, right]
    }
    return left;               // first bad
}
```

- Here `ok(v) = isBadVersion(v)`.  
- When `ok(mid)` is true, `mid` might be the first bad, so we **keep** it (`right = mid`).

---

### 153. Find Minimum in Rotated Sorted Array — keep mid on the “good” side

Given strictly increasing array rotated once. We want the **minimum**.

Observation: compare `nums[mid]` with `nums[right]`.

- If `nums[mid] > nums[right]` → `mid` is in **left rotated part**, min is strictly to the **right** of `mid`.  
- Else (`nums[mid] <= nums[right]`) → `mid` is in **right (sorted) part** that contains the min; min is in `[left, mid]`.

```cpp
int findMin(const vector<int>& nums) {
    int left = 0, right = (int)nums.size() - 1;
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] > nums[right])
            left = mid + 1;    // min in (mid, right]
        else
            right = mid;       // min in [left, mid] → keep mid
    }
    return nums[left];         // left == right
}
```

Boundary search:

- `while (left < right)`  
- One branch discards `mid`, the other **keeps** it.

---

### 875. Koko Eating Bananas — binary search on the answer

We search for the **minimum speed `k`** so that Koko can eat all piles within `h` hours.

- Search space: `k ∈ [1, maxPile]`.  
- Predicate: `canFinish(k) = (total hours at speed k ≤ h)` — **monotone**.

```cpp
bool canFinish(const vector<int>& piles, int h, int k) {
    long long hours = 0;
    for (int p : piles) {
        hours += (p + k - 1) / k;  // ceil(p / k)
        if (hours > h) return false;
    }
    return true;
}

int minEatingSpeed(const vector<int>& piles, int h) {
    int left = 1, right = *max_element(piles.begin(), piles.end());
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (canFinish(piles, h, mid))
            right = mid;       // mid works → try smaller
        else
            left = mid + 1;    // mid too slow
    }
    return left;
}
```

**Pattern: binary search on the answer**

- Search not over indices, but over a **parameter** `k`.  
- `ok(k)` monotone in `k`.  
- We want `min k` with `ok(k) == true` → classic **first true** pattern.

---

### 33. Search in Rotated Sorted Array — structural exact search

Target may be absent, so we use `while (left <= right)`.

Idea: in each step, at least one half is a **normal sorted** range.

- If `nums[left] <= nums[mid]` → left half `[left..mid]` is sorted.  
- Else → right half `[mid..right]` is sorted.

Check if target lies in the sorted half; if yes, search there, otherwise search in the other half.

```cpp
int search(const vector<int>& nums, int target) {
    int left = 0, right = (int)nums.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] == target)
            return mid;

        if (nums[left] <= nums[mid]) {
            // left half sorted
            if (nums[left] <= target && target < nums[mid])
                right = mid - 1;     // target in [left, mid-1]
            else
                left = mid + 1;      // target in [mid+1, right]
        } else {
            // right half sorted
            if (nums[mid] < target && target <= nums[right])
                left = mid + 1;      // target in [mid+1, right]
            else
                right = mid - 1;     // target in [left, mid-1]
        }
    }
    return -1;
}
```

- Still **exact search**: discard `mid` with `±1` whenever it cannot be answer.  
- Rotated structure only affects how we decide which half can contain target.

---

## How to Choose the Pattern (the “while” decision)

**Q1. Can the answer be absent?**

- **Yes** (target might not exist) → use **`while (left <= right)`**.  
  - Target search, possibly returning −1 / false.  
  - Examples: 704, 74, 33, 35, 367.

- **No** (you know some answer exists in the interval) → use **`while (left < right)`**.  
  - Boundary / minimum / first bad / minimal feasible parameter.  
  - Examples: 278, 153, 875.

**Q2. Are you searching for a value, or for a boundary of a monotone predicate?**

- **Value** (“find this element, if it exists”).  
  - Pattern: exact search (`<=`), discard `mid` once it can’t be the answer.  

- **Boundary** (“first bad”, “smallest that works”, “minimum element”).  
  - Pattern: first-true (`<`), keep `mid` in the branch where predicate holds.  

**Q3. Is your search over indices or over parameter values?**

- **Over indices**: classic array/matrix search, rotated array min, etc.  
- **Over values/parameters**: banana speed, minimal capacity, smallest radius, …  
  - As long as `ok(x)` is monotone, you can binary-search on `x`.

---

## Common Gotchas & Invariants

- Always reason in terms of **invariants**:
  - Exact search: “If answer exists, it is in `[left, right]`.”  
  - First-true: “Interval `[left, right]` is non-empty and contains at least one valid answer.”

- **Overflow**: use `left + (right - left) / 2`.  
- **Keeping vs discarding `mid`**:
  - If `mid` **cannot** be the answer → discard it with `±1`.  
  - If `mid` **could** be the answer (boundary search) → keep it (`right = mid` or `left = mid`).

- **Off-by-one on loop condition**:
  - `left <= right` → you must adjust bounds with `±1` to ensure progress; interval may become empty.  
  - `left < right` → ensure each step shrinks interval; final answer at `left == right`.

- **Binary search on answer**:
  - Don’t forget to prove monotonicity of `ok(x)`.  
  - Typically: `false, false, …, false, true, true, …, true`.

---

## Mini Drills (with brief answers)

**Q1. Why use `left + (right - left) / 2` instead of `(left + right) / 2`?**  
A1. To avoid integer overflow when `left` and `right` are large.

**Q2. When should I think “`while (left <= right)`”?**  
A2. When the search may **fail** (element might not exist), and you’re fine with interval becoming empty. You discard `mid` with `±1` once it cannot be the answer.

**Q3. When should I think “`while (left < right)`”?**  
A3. When you know at least one valid answer is inside `[left, right]` and you want a **boundary** (first/last true, min element, minimal parameter). You keep `mid` on the side that still may contain the boundary.

**Q4. In first-bad-version style, why `right = mid` and not `right = mid - 1` on `isBad(mid)`?**  
A4. Because `mid` itself could be the **first** bad version. Dropping it (`mid - 1`) risks skipping the correct answer.

**Q5. How to quickly decide whether to include or exclude `mid`?**  
A5. Ask: “Can `mid` still be the answer?”  
- If **no** → exclude: `left = mid + 1` or `right = mid - 1`.  
- If **yes** → include: `right = mid` (or `left = mid` in symmetric variants).

**Q6. What is “binary search on the answer”?**  
A6. You search over a parameter (like speed `k` in Koko) instead of indices. If `ok(k)` is monotone, you can perform a first-true search on `k` to find the smallest/largest value with `ok(k)`.

**Q7. In Search Insert Position, why do we return `left` at the end?**  
A7. Loop invariant ensures all indices `< left` have values `< target`, and all indices `>= left` have values `> target`. Therefore `left` is exactly the index where `target` should be inserted to keep the array sorted.
